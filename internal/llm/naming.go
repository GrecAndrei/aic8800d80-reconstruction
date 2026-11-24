package llm

import (
	"context"
	"encoding/json"
	"fmt"
	"strings"
	"time"
)

// StructProposalInput is the input to NameStruct.
type StructProposalInput struct {
	ClusterID    int
	Image        string
	PrimaryArg   string
	Fields       []FieldInput   // ordered by offset
	FieldStats   map[string]int // field_name -> total read_count
	SampleFuncs  []string       // sample function names touching the struct
	SampleCode   string         // 1-2 representative code snippets
}

// FieldInput is one field of a struct.
type FieldInput struct {
	Name      string // "field_0_0x0"
	Offset    int
	Size      int
	ReaderHint string  // optional: top caller names
	WriterHint string
}

// NameStruct asks the LLM to propose a name + field names for a struct.
//
// Uses a 2-turn strategy: Turn 1 asks for a one-line name, Turn 2 asks for
// the full JSON. The 2-turn approach avoids the model getting stuck in
// thinking before producing the answer.
// structNamingSystemPrompt is a byte-identical static prefix (>1,200 tokens)
// shared across every cluster and both Turn 1 and Turn 2 so providers with
// >=1,024-token prefix caching (e.g. Alibaba Token Plan deepseek-v4.1-flash-1017)
// hit cache on every subsequent request and on Turn 2 continuation.
const structNamingSystemPrompt = `You are a senior embedded WiFi/Bluetooth firmware reverse engineer specializing in ARM Cortex-M4 Thumb-2 wireless SoC firmware, specifically the AIC8800D80 (Marvell 88W8800 / RivieraWaves RW-NX MAC + LMAC/FMAC split) wireless chipset.

=== TARGET PLATFORM & FIRMWARE ARCHITECTURE ===
1. CPU & ABI:
   - ARM Cortex-M4F (ARMv7E-M, Thumb-2 instruction set, little-endian, 32-bit pointers, VFPv4-SP).
   - AAPCS calling convention: a1..a4 map to r0..r3; struct pointers are typically passed in a1 (r0) for object methods or a2 (r1) for event/message handlers.
   - Four firmware images exist in this repository:
     * fmacfw_8800d80_h_u02_bin: FullMAC WiFi host-interface variant (SDIO/USB high-throughput host offload, ~340 KB).
     * fmacfw_8800d80_u02_bin: FullMAC WiFi standard variant (802.11a/b/g/n/ac/ax MAC, SME/MLME, STA/AP/P2P, ~340 KB).
     * fmacfwbt_8800d80_u02_bin: FullMAC WiFi + Bluetooth/BLE coexistence firmware (adds BT/BLE controller, HCI, PTA coex, ~340 KB).
     * lmacfw_rf_8800d80_u02_bin: LowerMAC + RF test/calibration firmware (PHY/RF front-end, TX/RX calibration, DPD/IQ/LO/DCOC, ~220 KB).
   - Hardware load base is 0x120000; static analysis / decompiled symbols use analysis-space base 0x100000 (file_offset + 0x100000).
   - Peripheral MMIO occupies 0x40000000..0x60000000 (sysctrl, clock/PLL, RF/MDM/PHY, MAC-HW 0x40300000+, IPC/DMA, SDIO/USB, UART/console 0x40032000, timers/WDT 0x40501000+, crypto/AES/CCMP/GCMP/TKIP, BT/BLE baseband & PTA).

2. CORE FIRMWARE SUBSYSTEMS & TYPICAL STRUCT FAMILIES:
   - Kernel / Event Loop (ke_* / co_*):
     * co_list_hdr (next pointer at offset 0x0, size 4), co_list (first @ 0x0, last @ 0x4).
     * ke_msg (hdr @ 0x0, id @ 0x4, dest_id @ 0x6, src_id @ 0x8, param_len @ 0xa, param[] @ 0xc).
     * ke_timer (next @ 0x0, id @ 0x4, task @ 0x6, time @ 0x8).
     * ke_task_desc / ke_state_handler / ke_msg_handler (msg_id, func ptr).
     * Dynamic heap / block allocator descriptors (free_list, pool_head, block_size, alloc_cnt, free_cnt).
   - MAC Management & Interface State (vif_* / sta_* / mm_* / me_* / sm_* / apm_*):
     * vif_info_tag (virtual interface: index, type STA/AP/IBSS/MONITOR, active, mac_addr[6], bssid[6], chan_ctxt, txq, bcn_int, dtim_period, key_info, ps_state, twt, uapsd).
     * sta_info_tag (station entry: staid, inst_nbr, valid, mac_addr[6], aid, ctrl_port_state, ba_info, pol_tbl, rate_info, rssi, ps_state, txq_list, ht_cap/vht_cap/he_cap).
     * chan_ctxt_tag / chan_tbtt_tag (channel context: band, type/bw, prim20_freq, center1_freq, center2_freq, tx_power, vif_index, status, linked list).
     * mm_env_tag / mm_bcn_env_tag / mm_timer_tag (MAC management state, beacon template, TIM/DTIM, TSF offset, power save).
     * scan_env_tag / scanu_env_tag (active/passive scan state, chan_idx, ssid_list, ie_addr, probe_req_desc, scan_result).
     * sm_connect_req / sm_env_tag (STA connection state machine: bssid, ssid, auth_type, flags, vif_idx, assoc_ie, status).
     * apm_env_tag / apm_start_req (AP mode state: bcn_addr, bcn_len, tim_oft, tim_len, bcn_int, flags, vif_idx).
   - TX / RX Data Path & DMA Descriptors (txl_* / rxl_* / txd_* / rxd_* / dma_* / ipc_*):
     * txdesc / tx_hw_desc / tx_hd (upatterntx, nextfrmexseq_ptr, nextmpdudesc_ptr, first_pbd_ptr, datastartptr, dataendptr, frmlen, frmlifetime, phyctrlinfo, policyentryaddr, macctrlinfo1, macctrlinfo2, statinfo).
     * tx_pbd (upatterntx, next, datastartptr, dataendptr, bufctrlinfo).
     * tx_cfm_tag (pn[4], sn, timestamp, credits, ampdu_size, status).
     * rx_hd / rx_dmadesc / rx_swdesc / rx_pbd (upatternrx, next, first_pbd_ptr, swdesc, datastartptr, dataendptr, headerctrlinfo, frmlen, ampdu_stat_info, tsflo, tsfhi, recvec1a..1d, recvec2a..2b, statinfo).
     * dma_desc (src, dest, length, ctrl, next).
     * ipc_emb_env_tag / ipc_shared_env_tag (txdesc_idx, rxbuf_idx, msg_idx, dbg_idx, host/emb ring buffers, SDIO/USB aggregation queues).
     * bam_env_tag / rc_sta_stats (Block Ack session: ba_policy, tid, ssn, win_size, timeout; Rate Control: retry_chain, tp, prob, mcs, bw, gi).
   - PHY / RF Front-End & Calibration (phy_* / rf_* / mdm_* / cal_* / tpc_*):
     * phy_cfg_tag / phy_channel_info (band, bw, freq, path_mask, tx_pwr_tbl, rssi_offset).
     * rf_cal_ctx / rf_dpd_tbl / rf_iq_cal / rf_dcoc_cal / rf_lo_cal (gain_idx, i_coeff, q_coeff, dc_i, dc_q, lut_ptr, temp_comp, status).
     * tpc_cfg / pwr_tbl (per-rate TX power limits for 11b/11g/11n/11ac/11ax, channel edge backoff, regulatory domain).
   - Security / Crypto (sec_* / key_* / mfp_*):
     * key_info_tag (key[4] uint32, tx_pn, rx_pn[16], key_idx, cipher_suite WEP/TKIP/CCMP/GCMP/BIP, hw_key_idx, valid).
   - Bluetooth / BLE & Coexistence (bt_* / hci_* / lmp_* / ll_* / pta_*):
     * hci_cmd_desc / hci_acl_desc / bt_conn_ctx / ble_adv_ctx / pta_coex_cfg (opcode, param_len, handle, bd_addr[6], priority, slot_time, mask).
   - Host Interface, Logging & Utility (sdio_* / usb_* / uart_* / log_* / ring_buf_*):
     * ring_buf (base, size, head, tail, count, mask).
     * log_ctx / dbg_env (level, mask, uart_base, fmt_buf, timestamp).

=== STRUCT NAMING METHODOLOGY ===
When analyzing a recovered struct cluster:
1. Inspect the field offset map and field sizes (1=uint8/flags/idx, 2=uint16/len/id/port, 4=uint32/ptr/reg/mask, 6=MAC/BD addr, 8=uint64/TSF/PN).
2. Inspect the sample caller function names and code snippet for domain clues (subsystem prefix, register accesses, list links at offset 0x0, state fields, counters, flags, pointers).
3. Choose a concise, idiomatic C snake_case struct name (NO leading "struct_" and NO trailing "_t" unless already a standard short tag; e.g., "vif_state", "tx_hw_desc", "rf_cal_ctx", "ke_timer_node", "sdio_rx_ring", "scan_chan_cfg"). Never emit generic placeholder names like "struct_shape_*" or "unknown_struct".
4. Choose concise semantic snake_case field names (e.g., "next", "state", "flags", "len", "mac_addr", "chan", "tx_pwr", "status", "cb", "ctx"). Never embed raw hex offsets like "field_0x10" in field names.

=== TWO-TURN INTERACTION PROTOCOL ===
- Turn 1 (Brief): You receive the full struct cluster layout, field offsets/sizes, reader/writer hints, sample caller functions, and code snippet. Respond with ONE concise plain-text line describing what this struct represents (no markdown, no code fences, no "struct" prefix).
- Turn 2 (JSON): In the next turn of the same conversation, you will be asked to emit ONLY a single valid JSON object with NO prose, NO markdown fences, and NO commentary, using this exact schema:
  {"struct_name":"<snake_case>","fields":[{"name":"<snake_case>","comment":"<one-line semantic>"}]}
  Emit one entry in "fields" for each input field, in the exact same offset order.`

// NameStruct asks the LLM to propose a name + field names for a struct.
//
// Uses a 2-turn append-only conversation sharing the >1,200-token static
// system prompt so both cross-cluster requests and Turn 2 hit the prompt cache.
func NameStruct(ctx context.Context, c *Client, in StructProposalInput) (*StructProposal, error) {
	t1User := buildFullStructPrompt(in)
	t1Msgs := []Message{
		{Role: "system", Content: structNamingSystemPrompt},
		{Role: "user", Content: t1User},
	}
	brief, err := c.CallMessages(ctx, t1Msgs, false)
	if err != nil {
		return nil, fmt.Errorf("turn1: %w", err)
	}
	brief = cleanBrief(brief)

	t2Msgs := []Message{
		{Role: "system", Content: structNamingSystemPrompt},
		{Role: "user", Content: t1User},
		{Role: "assistant", Content: brief},
		{Role: "user", Content: fmt.Sprintf(
			"Now output ONLY the JSON object matching the schema for this %d-field struct in exact offset order. "+
				"Use concise semantic snake_case names (no hex offsets, no 'struct_' prefix). No prose or markdown.",
			len(in.Fields),
		)},
	}
	resp, err := c.CallMessages(ctx, t2Msgs, true)
	if err != nil {
		return nil, fmt.Errorf("turn2: %w", err)
	}
	prop, err := parseProposal(resp, in)
	if err != nil {
		return nil, err
	}
	prop.Brief = brief
	return prop, nil
}

// StructProposal is the LLM's output.
type StructProposal struct {
	StructName string             `json:"struct_name"`
	Brief      string             `json:"brief"`
	Fields     []StructFieldName  `json:"fields"`
}

type StructFieldName struct {
	Name    string `json:"name"`
	Comment string `json:"comment"`
}

func buildFullStructPrompt(in StructProposalInput) string {
	var b strings.Builder
	b.WriteString(fmt.Sprintf("Image: %s, cluster %d, primary arg: %s\n", in.Image, in.ClusterID, in.PrimaryArg))
	b.WriteString(fmt.Sprintf("Fields (%d), in offset order:\n", len(in.Fields)))
	for _, f := range in.Fields {
		hint := ""
		if f.ReaderHint != "" {
			hint += " [readers: " + f.ReaderHint + "]"
		}
		if f.WriterHint != "" {
			hint += " [writers: " + f.WriterHint + "]"
		}
		b.WriteString(fmt.Sprintf("  %s @ offset=0x%x size=%d%s\n", f.Name, f.Offset, f.Size, hint))
	}
	b.WriteString("\nSample caller funcs (top 5):\n")
	for i, fn := range in.SampleFuncs {
		if i >= 5 {
			break
		}
		b.WriteString("  " + fn + "\n")
	}
	if in.SampleCode != "" {
		b.WriteString("\nCode sample (truncated):\n")
		if len(in.SampleCode) > 1500 {
			b.WriteString(in.SampleCode[:1500] + "...\n")
		} else {
			b.WriteString(in.SampleCode + "\n")
		}
	}
	b.WriteString("\nTurn 1: In one short line, what is this struct likely to be?")
	return b.String()
}

func cleanBrief(s string) string {
	s = strings.TrimSpace(s)
	// Strip code fences
	for _, prefix := range []string{"```", "Brief:", "Answer:", "Output:"} {
		s = strings.TrimPrefix(s, prefix)
	}
	// First line
	if i := strings.Index(s, "\n"); i >= 0 {
		s = s[:i]
	}
	return strings.TrimSpace(s)
}

// parseProposal uses a stack-based tolerant JSON parser since the LLM
// often emits non-strict JSON (hex literals, negative numbers, etc).
func parseProposal(s string, in StructProposalInput) (*StructProposal, error) {
	// Find the first '{' and last '}'
	start := strings.Index(s, "{")
	end := strings.LastIndex(s, "}")
	if start < 0 || end < 0 || end <= start {
		return nil, fmt.Errorf("no JSON object in response: %q", s[:min(100, len(s))])
	}
	body := s[start : end+1]
	// Try strict parse first
	var p StructProposal
	if err := json.Unmarshal([]byte(body), &p); err == nil && p.StructName != "" {
		return &p, nil
	}
	// Tolerant parse: extract struct_name and fields
	return tolerantParse(body, in)
}

func tolerantParse(s string, in StructProposalInput) (*StructProposal, error) {
	p := &StructProposal{}
	// Extract struct_name: "struct_name"\s*:\s*"<name>"
	if m := extractQuoted(s, "struct_name"); m != "" {
		p.StructName = sanitizeName(m)
	}
	// Extract fields array
	if arrStart := strings.Index(s, "\"fields\""); arrStart >= 0 {
		if lb := strings.Index(s[arrStart:], "["); lb >= 0 {
			arrStart += lb
			rb := findMatching(s, arrStart, '[', ']')
			if rb > arrStart {
				arr := s[arrStart+1 : rb]
				p.Fields = parseFieldArray(arr)
			}
		}
	}
	if p.StructName == "" {
		return nil, fmt.Errorf("could not extract struct_name from: %q", s[:min(200, len(s))])
	}
	return p, nil
}

func parseFieldArray(s string) []StructFieldName {
	var out []StructFieldName
	// Split on top-level objects
	depth := 0
	start := -1
	for i := 0; i < len(s); i++ {
		switch s[i] {
		case '{':
			if depth == 0 {
				start = i
			}
			depth++
		case '}':
			depth--
			if depth == 0 && start >= 0 {
				obj := s[start : i+1]
				f := StructFieldName{}
				if n := extractQuoted(obj, "name"); n != "" {
					f.Name = sanitizeName(n)
				}
				if c := extractQuoted(obj, "comment"); c != "" {
					f.Comment = c
				}
				if f.Name != "" {
					out = append(out, f)
				}
				start = -1
			}
		}
	}
	return out
}

func extractQuoted(s, key string) string {
	kp := "\"" + key + "\""
	idx := strings.Index(s, kp)
	if idx < 0 {
		return ""
	}
	rest := s[idx+len(kp):]
	// Find colon
	ci := strings.Index(rest, ":")
	if ci < 0 {
		return ""
	}
	rest = rest[ci+1:]
	// Skip whitespace
	rest = strings.TrimLeft(rest, " \t\n")
	if len(rest) == 0 || rest[0] != '"' {
		return ""
	}
	// Find matching close quote
	for i := 1; i < len(rest); i++ {
		if rest[i] == '\\' && i+1 < len(rest) {
			i++
			continue
		}
		if rest[i] == '"' {
			return rest[1:i]
		}
	}
	return ""
}

func sanitizeName(s string) string {
	s = strings.TrimSpace(s)
	var b strings.Builder
	for i, r := range s {
		if i == 0 && (r >= '0' && r <= '9') {
			b.WriteRune('_')
			continue
		}
		switch {
		case r >= 'a' && r <= 'z':
			b.WriteRune(r)
		case r >= 'A' && r <= 'Z':
			b.WriteRune(r)
		case r >= '0' && r <= '9':
			b.WriteRune(r)
		case r == '_':
			b.WriteRune(r)
		default:
			b.WriteRune('_')
		}
	}
	out := b.String()
	if out == "" {
		return "unnamed"
	}
	return out
}

func findMatching(s string, start int, open, close byte) int {
	depth := 0
	for i := start; i < len(s); i++ {
		if s[i] == open {
			depth++
		} else if s[i] == close {
			depth--
			if depth == 0 {
				return i
			}
		}
	}
	return -1
}

// Wait a bit between calls to be polite to the API.
var DefaultDelay = 200 * time.Millisecond
