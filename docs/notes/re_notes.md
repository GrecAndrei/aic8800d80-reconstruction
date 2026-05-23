# AIC8800D80 Firmware RE Notes - Session 2026-05-20

## Binary Info
- **File**: fmacfw_8800d80_h_u02.bin
- **Size**: 0x5350C (341260 bytes)
- **MD5**: e9c5cf5f3488aa8ad4e4da87daf95c47
- **Arch**: ARM32 Thumb-2, Little Endian
- **Base**: 0x100000 (ROM)
- **Loader**: OBJ (should be BIN - known MCP issue)
- **Functions**: 1313 identified
- **Strings**: 726 identified

## Memory Map
| Region | Start | End | Size | Purpose |
|--------|-------|-----|------|---------|
| ROM | 0x100000 | 0x17350C | 0x5350C | Firmware code/data |
| SRAM | 0x20000000 | 0x2007FFFF | 0x80000 | Runtime RAM |

## Vector Table (0x100000)
- 64 entries, Cortex-M style
- SP = 0x001A0000
- Reset_Handler = 0x1201A8 (6 bytes, branches to 0x12016A)
- Active IRQ handlers: IRQ1(0x134410), IRQ2(0x14BEB0), IRQ3(0x137788), IRQ4(0x1377E4), IRQ5(0x13EA84), IRQ6(0x14C0A0), IRQ8(0x121888), IRQ9(0x1218A8), IRQ23(0x12DB00)
- Shared handlers: SVC/DebugMon/PendSV/SysTick all at 0x134D44

## Key MMIO Addresses
| Address | Purpose |
|---------|---------|
| 0x40010000 | WiFi MAC |
| 0x40020000 | BT Base |
| 0x4024001C | Status register |
| 0x40240100 | Control register |
| 0x40240120 | Control register |
| 0x40240124 | Control register |
| 0x40320038 | IPC doorbell |
| 0x40320064 | IPC register |
| 0x40580010 | Peripheral control |

## Key Global Variables
| Address | Purpose |
|---------|---------|
| 0x182B60 | Hardware capability register |
| 0x18274C | Feature mask |
| 0x182750 | Feature mask length |
| 0x182B64 | Feature flag |
| 0x1822C4 | State flag |
| 0x17348C | IPC completion flag |

## Hot Functions (by xref count)
| Address | Name | Xrefs | Description |
|---------|------|-------|-------------|
| 0x12F32C | sub_12F32C | 338 | IPC send: disable_irq, write MMIO 0x40320038, call parser, wait |
| 0x12E948 | sub_12E948 | 331 | Message/command parser - byte stream with feature mask checks |
| 0x12EB90 | sub_12EB90 | 316 | Feature flag guard - checks cap register, calls sub_10D6C8 |
| 0x12D108 | sub_12D108 | 143 | Unknown hot function |
| 0x10DAE4 | sub_10DAE4 | 141 | Unknown hot function |
| 0x12C7EC | sub_12C7EC | 137 | Unknown hot function |
| 0x12C84C | sub_12C84C | 134 | Unknown hot function |
| 0x12CD48 | sub_12CD48 | 124 | Unknown hot function |
| 0x12D190 | sub_12D190 | 98 | Unknown hot function |
| 0x143630 | sub_143630 | 80 | Unknown hot function |

## Key Orphan Functions (no callers - likely entry points)
| Address | Size | Description |
|---------|------|-------------|
| 0x111250 | 428 insns | Largest orphan - MMIO-heavy, 38 branches, 73 calls. Likely main init |
| 0x10CD7C | 274 insns | Significant orphan |
| 0x10F410 | 255 insns | Significant orphan |
| 0x106DD2 | 213 insns | Significant orphan |
| 0x112BAC | 208 insns | Significant orphan |
| 0x104718 | 166 insns | Significant orphan |
| 0x106000 | 151 insns | Significant orphan |

## String Analysis
Key strings found:
- `stk_start=%x, ptr_bss=%x` - Stack/BSS init
- `emacsh=%x, lmacsh=%x, ptr_macsh=%x` - EMAC/LMAC shared memory
- `hosttype=%d, asic_ver=0x%x` - ASIC version detection
- `phy_hw_set_channel`, `phy_get_rf_gain_idx`, `phy_get_txpwr_level` - PHY layer
- `cal_ipa_5g`, `cal_ipa_24g` - RF calibration (5GHz/2.4GHz)
- `intc_spurious` - Interrupt controller
- `wifimain!` - WiFi main entry indicator
- `postponed_arrays_allocating` - Memory allocation
- `crm_clk_conf` - Clock configuration
- `ke_state_get(TASK_APM) == APM_STOPPING` - WiFi state machine (APM task)
- `sm_assoc_req_send` - Association request (802.11)
- `invalid chan, band=%d, freq=%d` - Channel validation
- `rate:%d` - Rate control

## Architecture Inferences
1. **FullMAC WiFi firmware** - Contains complete MAC/PHY stack
2. **Dual-band** - 2.4GHz and 5GHz support (cal_ipa_24g/cal_ipa_5g)
3. **Host-firmware IPC** - Message-based communication via MMIO doorbell
4. **State machine driven** - APM (Access Point Manager) task states
5. **802.11 association** - sm_assoc_req_send indicates STA mode support
6. **RF calibration** - IPA (Internal Power Amplifier) calibration per band

## IPC Architecture (CONFIRMED)

## Queue Data Structure (CONFIRMED)
Queue layout: `[head_ptr, tail_ptr]` - singly-linked list
- sub_12D108 = queue_push (143 xrefs) - adds to tail
- sub_12D190 = queue_pop (98 xrefs) - removes from head  
- sub_12D1A8 = queue_remove (23 xrefs) - removes arbitrary element
- sub_12D240 = queue_insert_sorted (63 xrefs) - inserts by comparator callback

### Queue Instances
| Queue Addr | Purpose |
|------------|---------|
| 0x18FB00 (1637120) | TX buffer queue |
| 0x1843B8 | TX pending list |
| 0x1922A4 | Flag accumulator |
| 0x182BA0 | State machine state (check == 3) |

## MMIO Regions (EXPANDED)
| Range | Purpose |
|-------|---------|
| 0x40032xxx | SDIO controller config |
| 0x40035xxx | Hardware queue status |
| 0x40240xxx | TX/RX buffer control |
| 0x40320xxx | IPC doorbell/mailbox |
| 0x40500xxx | Clock/power config |
| 0x40501xxx | Timer/counter |
| 0x40505000 | Interrupt mask register |
| 0x40580xxx | Peripheral control |
| 0xE000E100 | NVIC SETENA0 (Cortex-M) |
| 0xE000ED08 | NVIC VTOR (Cortex-M) |

## SDIO Controller Init (CONFIRMED)
sub_10D508 = sdio_init (141 xrefs)
- Configures SDIO controller at 0x40032xxx
- Sets up interrupt via NVIC (0xE000E100, 0xE000ED08)
- Calculates timing parameters from MEMORY[0x1731B8]
- Enables SDIO interrupt (0x8000 bit)

## Interrupt Control (CONFIRMED)
MMIO 0x40505000 = Interrupt mask register
- sub_10DBC0 = irq_enable(bit) - sets bit in mask
- sub_10DBD4 = irq_disable(bit) - clears bit in mask
- Called from: sub_10DCC8, sub_10DCE0, sub_10DCF8, sub_10DD54

## Message Dispatch (CONFIRMED)
sub_12C84C = message_dispatch (134 xrefs) - central message router
```
void message_dispatch(msg *msg) {
    uint16_t msg_type = msg->type;  // at msg-6
    if (hw_cap < 0 || msg_type <= 0xE) {
        if (msg_type <= 0xC) {
            queue_push(0x191F88, msg-12);  // queue for type <= 0xC
            set_flag(0x4000000);
            return;
        }
    } else {
        ipc_send(1465988, 1482960, 183);  // error path
        msg_type = msg->type;
    }
    parse_message(1482900, msg->field1, msg->field2, msg_type);
    if (MEMORY[0x182749]) {
        sub_12CA88(msg-12);  // buffer management
    } else {
        sub_12F3EC();  // thunk to sub_10CC94
    }
}
```

sub_12CA88 = buffer_pool_manage (16 xrefs) - manages linked list of buffers
- Called from sub_12C84C, sub_12C5FC, sub_12C6B8, sub_12C798, sub_12C8F8
- Checks buffer address against MEMORY[0x1922C0] (pool limit)
- Traverses linked list looking for matching buffer

sub_12C8F8 = thunk to sub_12CA88 (137 xrefs)
TX buffer struct (from sub_124BFC analysis):
```
struct tx_buffer {
    tx_buffer *next;    // +0
    ???         field1; // +4
    ???         field2; // +8
    uint32_t    timestamp; // +12 (used with MMIO 0x40501010)
};
```
- sub_124BFC = tx_submit (63 xrefs) - submits TX buffer with timestamp check
- sub_11101C = tx_process (2 callers) - processes TX queue, writes to MMIO 0x40240148/0x40240168
- sub_11017C = tx_dequeue (5 callers) - dequeues TX buffer with IRQ safety
- MMIO 0x40501030 = TX timer register (set from buffer+12)
- MMIO 0x40501008 = TX control (4=active, 1024=idle)

### Message Processing Pipeline
```
Host → [MMIO Doorbell 0x40320038] → IRQ Handler (sub_10CD7C)
  → queue_pop (sub_11017C → sub_12D190)
  → Message dispatch (sub_11101C, sub_11017C)
  → sub_10D6C8 (core processor, 320 lines)
    → sub_12DFDC (buffer formatter)
    → sub_10D508 (init)
```

### TX/RX Path
```
sub_12F32C (IPC send, 338 xrefs)
  → __disable_irq()
  → MEMORY[0x40320038] = 0 (doorbell)
  → sub_12E948 (message parser, 331 xrefs)
    → sub_10D6C8 (core processor)
  → spin on MEMORY[0x17348C] (completion flag)

sub_10DAE4 (variadic wrapper, 141 xrefs)
  → sub_10D6C8 (core processor)

sub_10CD7C (IRQ handler, orphan, 274 insns)
  → queue_push (sub_12D108)
  → sub_113374 (message type check)
  → sub_11017C (queue_pop)
  → sub_11101C (TX buffer management)
  → sub_12C8F8 (response handler)
```

### IRQ Safety Pattern
All IPC functions use nested IRQ save/restore:
```
CPSR = __get_CPSR()
if (!(CPSR & 1)) { __disable_irq(); MEMORY[0x187F8C] = 1; }
++MEMORY[0x182560];  // nesting counter
// ... critical section ...
--MEMORY[0x182560];
if (nesting == 1 && MEMORY[0x187F8C]) __enable_irq();
```

### Key MMIO Regions
| Range | Purpose |
|-------|---------|
| 0x40240xxx | TX/RX buffer control |
| 0x40320xxx | IPC doorbell/mailbox |
| 0x40501xxx | Timer/counter |
| 0x40580xxx | Peripheral control |
| 0x40035xxx | Hardware queue status |

### Key Globals
| Address | Purpose |
|---------|---------|
| 0x187F8C | IRQ enable flag |
| 0x182560 | IRQ nesting counter |
| 0x1843B8 | TX buffer list head |
| 0x1843C4 | TX buffer flags |
| 0x182B9C | State flag |
| 0x1822C6 | State flag |
| 0x173282 | State flag |
| 0x17327D | State flag |
| 0x173282 | State flag |

## Crypto/Security
- AES S-Box at 0x14CBE0 (ROM, no xrefs yet)
- CRC32 table at 0x14A5EC (ROM, little endian, no xrefs yet)
- No crypto_symmetric functions classified
- Risk level: LOW (firmware, no dangerous libc)

## Protocol Stack (CONFIRMED)
**SDIO FullMAC WiFi Firmware** with:
- SDIO interface: `sdio_func1_h2d_free_queue1_head_get`
- IPC: `ipc_emb_hostrxbuf_get`
- MAC Management: `mm_timer_set`, `mm_set_ps_options_req_handler`
- PHY Layer: `phy_get_channel`, `phy_hw_set_channel`, `phy_get_rf_gain_idx`, `phy_get_txpwr_level`
- Kernel Environment: `ke_task_local`, `ke_state_get(TASK_APM)`
- BSS Config: `co_list_is_empty(&sm_env.bss_config)`
- TX/RX: `txl_he_tb_transmit_cancelled`
- Power Save: `mm_set_ps_options_req_handler`
- RF Calibration: `cal_ipa_5g`, `cal_ipa_24g`
- 802.11: `sm_assoc_req_send`, `APM_STOPPING`, `APM_IDLE`

## Key Subsystems Identified
1. **IPC Layer**: Queue-based host-firmware communication via SDIO
2. **TX Path**: sub_11101C manages TX buffer linked list
3. **RX Path**: sub_10CD7C (IRQ handler) processes incoming messages
4. **Message Parser**: sub_12E948 parses byte-stream commands
5. **Core Processor**: sub_10D6C8 handles message dispatch
6. **Queue System**: sub_12D108 (push), sub_12D190 (pop)
7. **Feature Flags**: sub_12EB90 guards operations by hardware capability
8. **PHY Control**: Channel, gain, TX power management
9. **RF Calibration**: IPA calibration for 2.4GHz and 5GHz bands
10. **State Machine**: APM (Access Point Manager) task states

## Firmware Init Chain (CONFIRMED)
sub_100478 = firmware_init (noreturn, 1 caller from entry point)
```
void __noreturn firmware_init() {
    // Set up global table pointers
    MEMORY[0x182B5C] = 0x17300C;  // global_table
    MEMORY[0x182BA0] = 0x173058;  // state_ptr
    MEMORY[0x182B54] = 0x173018;  // ?
    MEMORY[0x182B58] = 0x1730B4;  // ?
    MEMORY[0x182B34] = 0x1730C4;  // ?
    MEMORY[0x182B60] = 0x1730DE;  // hw_cap_ptr
    MEMORY[0x182B9C] = 0x1730DC;  // ?

    sub_1002A0(...);  // subsystem_init

    if (*state_ptr == 1) {
        MEMORY[0x40500058] &= ~1;
        MEMORY[0x40241050] |= 1;
        MEMORY[0x40241050] &= ~2;
    }

    MEMORY[0x182B66] = (MEMORY[0x40580048] & 0xF) == 10;

    sub_12FE58(...);  // sdio_init + queue_setup
    sub_10D068(...);  // ?
    sub_10F0C4(...);  // ?
    sub_115674(...);  // ?

    if (MEMORY[0x173277]) {
        sub_1303B8(...);
        sub_130474(...);
    }

    sub_12E948(0x163E88, MEMORY[0x173158], MEMORY[0x18255C], 0x1824FC);  // msg_parse
    sub_10FFC0(...);  // ?
    sub_10F318(...);  // ?

    if (MEMORY[0x182B66]) {
        sub_114428(...);
        MEMORY[0x40580010] &= ~8;
        MEMORY[0x40580048] &= 0xFFFFFFF0;
        sub_12EB90(2, 0x163EA8, 0x40580048, ...);
    } else {
        sub_12EB90(2, 0x163EB4, ...);
    }

    if (*state_ptr == 3)
        MEMORY[0x40035100] = 1;

    sub_115C20(...);  // main_loop (never returns)
}
```

## Feature Guard / Conditional SDIO (CONFIRMED)
sub_12EB90 = feature_guard_sdio (many callers)
- Checks if `(result & *hw_cap) != 0`
- If true: calls sub_10D6C8 (sdio_transfer)
- Used to conditionally execute SDIO transfers based on hardware capabilities

sub_10DAE4 = sdio_transfer_varargs (many callers)
- Variadic wrapper for sub_10D6C8
- `return sub_10D6C8(a1, varg_r1);`

## SDIO Data Transfer (CONFIRMED)
sub_10D6C8 = sdio_transfer (3 callers)
- Complex function (~320 lines, 78 calls, 30 branches, 28 loops)
- Calls sub_12DFDC (buffer prepare)
- Checks MEMORY[0x18221C] (SDIO initialized flag)
- If not initialized: calls sub_10D508 (sdio_init)
- Waits for MEMORY[0x40035040] (SDIO status register)
- Handles SDIO command/response transfer
- Uses queue operations: sub_12D22C (queue_len), sub_12D190 (queue_pop), sub_12D108 (queue_push)
- Calls sub_111130 (sdio_cmd_send?)
- Calls sub_1435D0 (sdio_data_read?)

## Init Chain Functions (CONFIRMED)
sub_115674 = system_init_chain (1 caller from firmware_init)
```
int system_init_chain() {
    MEMORY[0x182569] = 0;
    sub_12F3A8();  // feature_flags_init
    sub_132088();  // subsystems_init
    sub_1205E0();  // mac_phy_init
    sub_12D0D0();  // rx_queue_init
    sub_12F3C8();  // tx_queue_init
}
```

sub_12F3A8 = feature_flags_init (1 caller)
- Clears 8 bytes at 0x18274C
- Sets MEMORY[0x18274C] = 0x2FFFFFFFF (feature mask)

sub_132088 = subsystems_init (2 callers)
- Clears 0x17C bytes at 0x1922F8
- Calls: sub_12CBF4(5, 0) → sub_137490 → sub_1365C0 → sub_1342F4 → sub_13B82C → sub_140C5C

sub_1205E0 = mac_phy_init (2 callers)
- If !MEMORY[0x182B66]: sub_12B77C()
- Calls: sub_120408 → sub_11F5E4 → sub_11ECB0 → sub_12AD00 → sub_128DB8 → sub_129E04 → sub_116D3C
- If MEMORY[0x182B66]: nullsub_5() else sub_11D6BC()
- Then: sub_124BF0 → sub_12B030 → sub_1278DC → sub_12C1FC → sub_1255F4 → sub_10F11C → sub_12047C

sub_12D0D0 = rx_queue_init (1 caller)
- MEMORY[0x1922C0] = sub_12C954() (rx_queue_head)
- Clears rx counters: 0x1922B0-0x1922BC
- Sets MEMORY[0x1922C8] = 0x14E005 (rx handler ptr?)
- Calls sub_12D00C(-1)

sub_12F3C8 = tx_queue_init (1 caller)
- Clears 0x10 bytes at 0x1922D4
- Initializes queue at 0x18F00C via loc_12D100

## SDIO Init (CONFIRMED)
sub_10D508 = sdio_init (2 callers)
- Configures SDIO controller at 0x40032xxx
- Sets up NVIC interrupt at 0xE000E100 (0x8000 = IRQ 15)
- Configures clock divisor from MEMORY[0x171894] (calculated by clock_calc)
- Sets up SDIO command/response registers

sub_12FE58 = sdio_queue_setup (1 caller from firmware_init)
- Calls sub_10D634 (sdio_init wrapper)
- Initializes 4 queues at:
  - 0x182764 (queue head 1)
  - 0x1827A8 (queue head 2)
  - 0x1827EC (queue head 3)
  - 0x182830 (queue head 4)
- All pushed to queue 0x18F00C via sub_12D108 (queue_push)
- Uses IRQ save/restore pattern

## Subsystem Init Details (CONFIRMED)
sub_12CBF4 = msg_register_handler (5 callers)
- Registers message handler by type (a1 >> 8 = type, a1 & 0xFF = subtype)
- Looks up handler table at 0x16A230 + 16*type
- Validates against max count at table+14
- Calls sub_12E948 (msg_parse), sub_12D108 (queue_push), sub_12CFC4 (set_flag)
- Error handling via sub_12F32C

sub_100688 = hw_config_init (1 caller from subsystems_init)
- Calls sub_1005B0(HIBYTE(MEMORY[0x40330000]) & 3) (chip variant detection)
- Clears 8 bytes at 0x182198
- Reads config from table at 0x163F30 + 16*variant
- Sets MMIO 0x4034006C = config_word0
- Sets MEMORY[0x182199] = config_word1
- Sets MEMORY[0x182198] = -1

sub_102B4C = nvic_irq_setup (1 caller from subsystems_init)
- Sets up NVIC interrupt vectors at 0xE000ED08 (VTOR)
- IRQ2_Handler, IRQ4_Handler, IRQ6_Handler, IRQ7_Handler
- IRQ36_Handler, IRQ37_Handler
- Enables interrupts: 0xE000E100 = 8, then 512, then 0x800000
- 0xE000E104 = 64
- __enable_irq()
- String: "h_handler: reason code =%d\r\n"

## Memory Operations (CONFIRMED)
sub_100200 = memset_wrapper (many callers)
- Thunk to sub_100202
- `return sub_100202(result, a2, a3);`

sub_100202 = memset_impl (1 caller)
- ARM32 Thumb memset implementation
- Optimized with STRD.W for 8-byte stores
- Handles alignment, 16-byte blocks, and tail bytes
- Standard memset: fills memory with byte value

## Queue/Buffer Helpers (CONFIRMED)
sub_12A32C = queue_pending_check (1 caller)
- Checks if queue at 0x18E618 has pending items
- Walks linked list checking offset+106 == 2 AND offset+1224 != 0
- Returns check result from table at 0x190505

sub_10F24C = queue_init_helper (no callers, orphan)
- Sets up queue structure
- Calls loc_12D100 (queue_push)
- JUMPOUT to 0x12D102

## Subsystem Init Details (CONFIRMED)
sub_10D2C4 = clear_sdio_state (2 callers)
- Clears 0x38 bytes at 0x182AAC (SDIO state structure)

sub_10C7B8 = sdio_dma_init (1 caller from subsystems_init)
- Clears 0x28 bytes at 0x182A84 (DMA state)
- Clears 0x1E6C bytes at 0x174040 (DMA buffer, ~8KB)
- Checks MMIO 0x40035080 (DMA control)
- If bit 3 set: waits for bit 4
- Else: sets bit 3, calls memset if (v0 & 3) == 0, sets bit 4
- Sets *(ptr+644) = MEMORY[0x173320]
- Calls sub_10C700()

sub_10C700 = sdio_dma_config (1 caller)
- Configures SDIO DMA at MMIO 0x40035114, 0x40035118, 0x4003510C
- Sets up DMA channels (bits 2,3,8,9,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31)
- 0x4003510C = 0xF0000033 (DMA control register)
- Returns 0x4003510C

sub_1073D8 = crypto_hw_clear_regs (5 callers)
- Clears bits at 0x403420CC, 0x403420D0, 0x403420D4 (crypto control)
- Returns 0x403420D4

sub_10788C = crypto_power_calc (4 callers)
- Calculates power level from a1[0..3] values
- Uses FP: vcvts_n_f32_u32(v3, 0xF) * 10.0
- Clamps result to [-30, -2]
- Calls sub_12D5A0 (fp_convert), sub_12D5C8 (fp_convert), sub_107620 (state_dump)

sub_12D5A0 = fp_convert_uint (5 callers)
- Calls sub_12D464 → sub_1428B8 → sub_142968 → sub_142F2C
- String: "2ZGU" (FP constant?)

sub_12D5C8 = fp_convert_int (2 callers)
- Thunk to sub_142570

sub_1076E4 = crypto_power_apply (1 caller)
- Similar to sub_10788C but with different FP shift (0xE)
- Clamps power, calls sub_12D5A0, sub_12D5C8, sub_107620

sub_10779C = crypto_freq_set (1 caller)
- Calls sub_1073D8 (clear_regs)
- Sets 0x4034227C with freq value from a1+8 (QWORD)
- delay_us(40), toggles 0x403420D4 bit 26
- Calls sub_1076E4 (power_apply)
- Clears regs

sub_107B08 = crypto_rx_calibrate (2 callers from crypto_mac_core)
- Similar to sub_10794C but different constants (0xC00, 0x400, 1536, 3584, 512, 2560)
- Reads 0x40342214 & 0x7FFF multiple times
- Calls sub_107620, sub_1073D8, sub_10788C

sub_107F40 = crypto_channel_calc (1 caller from crypto_mac_core)
- 3 params: a1 (config struct), a2 (freq?), a3 (channel table)
- Checks a1[0] < a3[1]-1 && a1[3] <= 49
- Calls sub_10779C (freq_set)
- Divides values by 3, calculates channel mapping
- Strings: "VUUU"

sub_10C220 = tx_phy_config (1 caller)
- 129 lines, 36 calls, 8 branches, 5 loops
- Configures TX PHY from result[0] (rate/chan info)
- Writes -32640 (0x8080) to buffer at a2+2..a2+32
- Waits for MEMORY[0x40035248] (SDIO ready)
- Calculates rate from 0x4050900C/0x40509010
- Uses FP ops: sub_142894, sub_142968, sub_142BBC, sub_1424DC, sub_142EEC
- Calls sub_103A54 (crypto_hw?)
- Strings: "HR" (high rate?)

## Crypto HW Functions (CONFIRMED)
sub_103AFC = crypto_hw_reset (2 callers)
- Clears bits at 0x40342030, 0x4034202C, 0x40340010, 0x40344088
- delay_us(10) → feature_guard_sdio

sub_103B8C = crypto_hw_mode_select (1 caller from crypto_mac_core)
- 13-case switch on mode (a1): 1,2,3,10,14,30,31,34,35,36,37,38,39
- Sets MMIO 0x40330800 = 0x10000002
- Configures 0x4034202C based on mode
- Calls delay_us, msg_parse

sub_103E14 = crypto_hw_exec (1 caller from crypto_mac_core)
- Sets 0x40342004 = 777, waits for 0x40342228 >= 0
- Calls msg_parse with results
- Sets 0x40342000 = 65945, 0x40342180 &= ~0xFF0000

sub_107084 = crypto_hw_config (1 caller from crypto_mac_core)
- Configures 0x40342xxx registers (crypto engine)
- Sets up 0x403420E0-0x403420E8 with constants (0x351D, 0x375C, 0x35BB)
- delay_us(10)

sub_1058D0 = crypto_key_schedule (2 callers)
- Parses key bits from a1 (bitmask), stores in a2[10..27]
- a2[14]=count, a2[15]=15, a2[16]=8
- Iterates bits 20-27, extracts key schedule values

sub_107620 = crypto_state_dump (5 callers)
- Copies 24 words from 0x165D68-0x165DA4 to stack
- Reads from a1+8, a1+12
- Calls feature_guard_sdio

sub_10794C = crypto_hw_sequence (2 callers from crypto_mac_core)
- Calls sub_107620 (state_dump)
- Toggles 0x403420D4 bits, 0x403420C8 bits
- Reads 0x40342214 & 0x7FFF (crypto result)
- Multiple delay_us(20) calls
- Calls sub_1073D8, sub_10788C

## Crypto Functions (CONFIRMED)
sub_103B54 = crypto_hw_toggle (3 callers)
- Toggles MMIO 0x40344088 bits 21, 22 (crypto engine control)
- Calls sub_100644(2) (delay function)
- Pattern: clear bit → delay → set bit → delay → set bit

sub_100644 = delay_us (many callers)
- Busy-wait delay: waits for MEMORY[0x40501010] (timer) to reach target
- Inner loop: 32 iterations (fine-tune delay)
- Returns target time

sub_102A00 = msg_parse_thunk (no callers, orphan)
- Thunk to sub_12E948 (msg_parse)

sub_12CD48 = msg_get_value (5 callers)
- Gets value from message handler table by type (a1 >> 8) and subtype (a1 & 0xFF)
- Looks up table at 0x16A230 + 16*type
- Validates against max count at table+14
- Returns *(table_base + 2*subtype) as u16
- Error handling via sub_12F32C

sub_103A54 = crypto_hw_power_up (3 callers)
- Sets 0x40344084 |= 1
- Waits for 0x403440A8 & 0x10 (delay loop 50)
- Sets 0x40344088 |= 0x80000 | 0x100000
- Waits for 0x403440A8 & 8 (delay loop 50)
- Sets 0x4034202C |= 0x20000, 0x40340010 |= 0x1000000 | 0x8000000
- Sets 0x40342030 |= 0x524
- Calls feature_guard_sdio(0x2000, 0x163EBC, 0x40340010, 0x40342030)
- Strings: ", 4@", "0 4@|C"

## TODO: Big Functions (skip for now)
- sub_109FF8 (401 lines, 75 calls, 16 branches, 6 loops) - 10 params, heavy FP, caller sub_10B2F0
- sub_108140 (4140 bytes, 593 lines) - crypto_mac_core
- sub_10B29A (282 lines) - crypto_mac_dispatch
- sub_105A88 (302 lines, 39 params!) - crypto heavy config, caller sub_109FF8
- sub_1059A4 (78 lines) - key/bitmask parser, callers sub_109FF8/sub_10B2F0
- sub_109EB0 (111 insns) - table copy from 0x182A04/0x182904/0x182984, caller sub_109FF8
- sub_1064E0 (303 lines, 51 calls, 13 branches, 13 loops) - large crypto config, caller sub_10B2F0
- sub_106DD2 (149 lines, 56 params) - large crypto sequence, calls sub_1064E0/104FA8/102BF8/102C5C
- sub_101A54 (152 lines) - large policy/config builder, calls sub_1320BC/sub_12F35C
- sub_10D6C8 (320 lines, 78 calls) - big logging/IO path (called by msg_parse)
- sub_12DFDC (decompile failed) - TODO
- sub_12DFDC (switch 89 cases) - format parser? used by sub_10D6C8

sub_1009DC = crypto_key_load (2 callers)
- Sets 0x4034224C |= 0x100, 0x403422C4 &= ~0x30000
- Copies key data from 0x40344000 area to crypto HW in 4 chunks (128 words each)
- Updates 0x403422C4 with chunk index << 16
- Calls sub_103FF4 (crypto_hw_write) 24 times (12 pairs)
- Clears 0x4034224C &= ~0x100, sets 0x403420C8 &= ~2

sub_103F14 = crypto_table_init (1 caller from crypto heavy config)
- If !a3: initializes table at a1+16*(3*a2) with constants (0x0C040480, 0x18060880, etc.)
- Copies table data to crypto HW at 0x40344000 in 3 chunks
- Uses 0x4034224C |= 0x100, 0x403422C4 for chunk tracking

sub_104080 = crypto_hw_reset_seq (2 callers)
- Clears 0x4034224C &= ~0x200
- Sets 0x4034206C = 0x333000, 0x40342034 = 8
- Enables crypto: 0x40340010 |= 0x1000000, 0x40342008 |= 0x2000000
- Configures 0x4034202C, 0x403420D4, 0x403420C8, 0x4034226C, 0x40342024, 0x40342078, 0x40342274
- Sets 0x40342030 = 112615, 0x40342004 |= 0x1000000
- Returns 0x40342048

sub_1043C8 = crypto_calibrate (1 caller from crypto heavy config)
- Saves/restores 0x40330800
- Sets 0x40342000 = 16188432, configures 0x4034206C
- delay_us(10), sets 0x40342004 = 16777473
- delay_us(125), sets 0x40342004 = 16777481
- Waits for 0x40342228 >= 0
- Calls msg_parse with results
- Calls sub_1042BC()
- Strings: "l 4@", "(\"4@", "t 4@"

sub_1042BC = crypto_iq_calculate (1 caller from crypto_calibrate)
- Reads table from IRQ47_Handler+1 area (0x44000 offset)
- Calculates min/max/sum of I/Q values (bits 20-31, bits 4-15)
- Checks bounds: >2040 or <-2040 → error
- Calls feature_guard_sdio with sums
- Normalizes I/Q values: subtracts average, re-encodes
- Strings: "HE", "pE"

sub_103FF4 = crypto_hw_write32
- Thin wrapper: sub_104000(a1, a2, 0x40340010, 0x40342274)

sub_100644 = delay_us
- Busy-loop delay using 0x40501010

sub_102A00 = msg_parse_thunk2
- Thin wrapper: sub_12E948(result, a2, a3, a4)

sub_104000 = crypto_hw_write32_core
- Writes control bits in 0x40340010 and 0x40342274
- Loads data into *v6 and sets addr/flags in 0x40342274 (a1<<16)
- Toggles 0x40342274 bits 0x8000/0x200000/0x400000 around the write

sub_1062DC = crypto_rate_ctrl
- If a4+132 <= a2: calls sub_105118 with table entry
- Builds control word (a1|a2<<8, optional a3 and a5 handling)
- Writes 0x40342270 and logs via msg_parse

sub_1063A4 = crypto_table_copy_165D00
- Copies 0x165D00..0x165D6C into stack locals, then writes into a1 table
- Calls msg_parse with 0x165D70 pointer

sub_106450 = crypto_table_adjust
- Uses math helpers sub_142894/sub_142BBC/sub_142F2C and sub_12D5A0
- Adjusts a1[a3+35] using derived delta (v10 * 20.0)
- Logs bounds errors, then calls sub_1063A4

sub_105118 = crypto_gain_clamp
- Computes gain from a1/20.0 and a2 via math helpers
- Clamps gain to [32..232] into a3+104, otherwise logs via sub_12E948
- Calls msg_parse with (a1*100, a2)

sub_104FA8 = crypto_adc_capture
- Clears 0x40342024 bit 0x20000000
- Sets 0x4034206C low 12 bits, toggles 0x40342034 0->8 with delays
- Sets 0x40342024 bit 0x40000000
- Reads HIWORD(0x40342218)&0x3FFF into table a2
- Logs and errors if value > 0x3E80

sub_103B54 = crypto_hw_clk_toggle
- Clears/sets bits 0x400000/0x200000 in 0x40344088 with delay_us(2)

sub_102BF8 = crypto_hw_enable (used in tx_rate_config)
- Programs 0x40344094 bits based on a1 (enable modes)
- Short delay loops around register writes

sub_102C5C = crypto_hw_disable (used in tx_rate_config)
- Programs 0x40344094 bits based on a1 (disable modes)
- Short delay loops around register writes

sub_12EB90 = msg_parse_guard
- If (result & *0x182B60) != 0 → sub_10D6C8(a2)

sub_12E948 = msg_parse
- Uses 0x182750/0x18274C/0x182B60 to filter messages
- Walks bytes of format pointer, may call sub_12F32C or sub_10D6C8

sub_1018A8 = irq47_status_handler
- Copies 0x4033B41C -> 0x4033B420
- If bit 0x1000 clear: msg_parse(0x4033B41C, <<19)
- Else clears 0x4033B414 bit 0x1000 and calls sub_12CFC4(16)

sub_1018F0 = get_cached_1828F8
- If a2 != 0, msg_parse and returns *out = 0x1828F8
- Else just stores 0x1828F8 into *out

sub_101924 = debug_if_40320038
- If 0x40320038 << 28 nonzero: msg_parse

sub_12CFC4 = irq_nesting_or
- Disables IRQs if CPSR bit0 clear, sets 0x187F8C
- ORs a1 into 0x1922A4 with nesting count in 0x182560
- Re-enables IRQs if needed

sub_12F32C = msg_parse_blocking
- Disables IRQs, clears 0x40320038, calls msg_parse(1487032)
- Waits while 0x17348C

sub_12F35C = msg_parse_short
- Thin wrapper: msg_parse(1487056, a1, a2, a3 & 0xFFFFF)

sub_111130 = log_enqueue
- Allocates buf via sub_10FE7C(4), enqueues to queue from sub_11017C
- Fills header and payload via sub_143630, then sub_11101C

sub_10D508 = log_hw_init
- Programs 0x400320xx and NVIC (0xE000ED08/0xE000E100)
- Uses 0x1731B8 and clock-related globals for divisor

sub_12D22C = list_count
- Counts nodes in a singly-linked list head pointer

sub_10D634 = log_hw_init_if
- If 0x18221C == 0 → sub_10D508

sub_10DAE4 = log_printf
- varargs wrapper for sub_10D6C8

sub_10FE7C = log_alloc
- Alloc from sub_110340 or sub_10F9E8
- Marks header byte and validates via sub_10FDF4

sub_110340 = log_pool_alloc
- IRQ-protected alloc via sub_12D190(1605216)

sub_10F9E8 = log_pool_alloc2 (large)
- Searches pool entries for size >= a2
- IRQ-protected allocation, logs errors on failure

sub_10FDF4 = log_ptr_in_range
- Checks pointer against [0x182260..0x182260+0x182264] or [0x18227C..0x18227C+0x182280]

sub_143630 = memcpy_like
- Optimized aligned copy (64-byte blocks), then tail bytes

sub_12D190 = list_pop
- Pops head from list at a1, updates tail if needed

sub_11017C = log_queue_alloc
- IRQ-protected alloc via sub_12D190(1605176)

sub_11101C = log_queue_push
- IRQ-protected enqueue, uses 0x40240148/0x40240168/0x4024016C
- Handles 0x182B9C/0x1822C6/0x17327D gating

sub_10FEC8 = log_free_dispatch
- Uses log_ptr_in_range then dispatches to pool-specific frees
- Calls sub_110380/sub_110250/sub_1102F0/sub_113908

sub_110250 = log_free_pool_A
- IRQ-protected free via sub_12D108(1605168), increments 0x1822BC

sub_1102F0 = log_free_pool_B
- IRQ-protected free via sub_12D108(1605224), increments 0x1822C0

sub_110380 = log_free_pool_C
- IRQ-protected free via sub_12D108(1605216)

sub_113908 = log_free_pool_D
- IRQ-protected free via sub_12D108(1605316)

sub_12D108 = list_push_tail
- Pushes node to list tail at a1
- Warns via msg_parse_blocking if a2 is null and log level <0

sub_10FBA0 = log_free_pool_dispatch2 (large)
- Validates pointer range, uses header byte a2-4 for pool id
- IRQ-protected; logs errors on invalid input

sub_11414C = log_free_pool_E
- Waits on 0x4003504C then frees via sub_12D108(0x17350C+628)

sub_1137C4 = log_free_pool_F
- Frees via sub_12D108(1605332) and updates counters
- May toggle 0x40200800/0x40200B24 and call sub_111FBC/sub_12C5FC

sub_111FBC = hw_event_flag
- Writes to 0x4020??? (base 0x40200000 + 0xB00) based on a1

sub_12C5FC = event_queue_push
- IRQ-protected enqueue into 0x1922B8 structure
- May allocate via sub_12C8FC and timestamp via sub_124BFC

sub_113578 = log_flush?
- Uses 0x187EBC/0x187ED1/0x182547/0x182548 state
- Calls sub_113210/sub_1132B0 and may sub_10DAE4 on error

sub_1103C4 = log_queue_refill (large)
- Allocates entries from sub_1102A0 and sub_11017C
- Programs 0x402401B8/0x402401?? with IRQ protection

sub_1102A0 = log_pool_alloc_B
- IRQ-protected alloc via sub_12D190(1605224), decrements 0x1822C0

sub_12C8FC = list_find_remove
- Walks list and removes first node where predicate a2(node, a3) is true

sub_12CA88 = list_insert_block (large)
- Inserts block into ordered list with IRQ protection
- Calls msg_parse_blocking on errors

sub_124BFC = timestamp_update (large)
- IRQ-protected, updates 0x40501008/0x40501030
- Uses sub_12D190/sub_12D1A8/sub_12D240 and msg_parse on errors

sub_12D1A8 = list_remove_node
- Removes node a2 from list at a1
- Logs via msg_parse_blocking if a1 invalid

sub_12D240 = list_insert_sorted
- Inserts node a2 into list at a1 using comparator a3

sub_10F058 = log_tick
- Computes v1 from 0x182B0D + (0x4032011C&3), clamps to -62
- Calls sub_102AD0 and msg_parse, updates 0x182B0F
- If v1 >= -61: timestamp_update(0x182B14) else clears 0x182B13

sub_110EDC = log_queue_push2
- IRQ-protected enqueue using 0x40240170/0x40240174
- Handles 0x182B9C/0x1822C6/0x17327D gating

sub_102AD0 = rf_power_set
- Writes a1 to 0x4033B3AC/0x4033B3D4 low byte
- Writes (a1-3) to bits 12..19 then calls sub_102B00

sub_124CF4 = timestamp_remove
- Removes a1 from 0x18FB00 list and updates 0x40501008/0x40501030

sub_124E3C = timestamp_list_contains
- Returns 1 if a1 is in list 0x18FB00

sub_10DBC0 = irq_mask_set
- Sets bit (1<<a1) in 0x40505000

sub_10DBD4 = irq_mask_clear
- Clears bit (1<<a1) in 0x40505000

sub_10DCC8 = irq_mask_set_if_flag
- If 0x17327D: set bit 2 else clear bit 2

sub_10DCE0 = irq_mask_set_if_flag2
- If 0x17327D: set bit 1 else clear bit 1

sub_10DCF8 = irq_event_handler
- Logs with sub_10DAE4, uses sub_10DBEC/sub_10D26C and mask helpers

sub_10DBEC = irq_mask_test
- Returns (0x40505000 & (1<<a1)) != 0

sub_10D26C = irq_event_set
- Writes 0x40035000 = 0x40000 or 0x80000 based on a1
- Sets 0x40506004 bit 0x400000

sub_12D3E0 = math_fastpath
- Uses lookup tables at 0x16A46C and 0x16A4EC and math helpers
- Returns transformed value (likely float/int conversion)

sub_1428B8 = math_helper
- Performs bit/shift checks and jumpouts; used by sub_12D3E0

sub_142968 = math_helper_big (large)
- Complex FP-ish math (exponent/mantissa handling)

sub_1425FC = math_helper_big2 (large)
- Complex FP-ish math (XOR-heavy)

sub_142E9C = math_helper_int
- Converts mantissa/exponent to int with saturation

sub_1424DC = math_round
- Rounds float-like value; handles NaN/inf via sub_1425FC

sub_11004C = log_pool_init_B
- Pre-allocates N items via sub_10F9E8(1581692, 0x63C) into list 1605224
- Increments 0x1822C0

sub_1100A4 = log_pool_init_queue
- Pre-allocates N items via sub_10F9E8(1581664, 0x0C) into list 1605176

sub_1100E4 = log_pool_init_A
- Pre-allocates N items via sub_10F9E8(1581692, 0x6B8) into list 1605168
- Increments 0x1822BC

sub_11013C = log_pool_init_C
- Pre-allocates N items via sub_10F9E8(1581692, 0x7C) into list 1605216

sub_10F24C = log_pool_config
- Writes config bytes at offsets +1622/+2432/+2434, then jumps to 0x12D102

sub_10F230 = log_free_wrapper
- Calls log_free_dispatch and returns 1

sub_10F270 = log_global_init
- Initializes 0x1843B4/0x1837A4/0x1843B8/0x1843C4/0x1837A8
- Clears buffers, seeds list at 1592264 via list_push_tail

sub_10F318 = log_system_init
- Switch on *0x182BA0 selects handlers into 0x185070/0x185074
- Calls log_global_init and pool init functions, then start hooks

sub_10F23C = log_pool_default_config
- Sets 0x1856F4 = 80 and calls log_pool_config(1595128, len=80, tag=81)

sub_10F382 = log_system_init_mode2
- Sets 0x18505C, calls sub_113888/sub_1136D4 and handler funcs
- If **v10 == 3, switches 0x18505C and calls sub_1140F4

sub_100200 = memset_thunk
- Wrapper to sub_100202

sub_100478 = fw_main_init
- Initializes log globals and runs init chain (sub_12FE58, sub_10D068, sub_10F0C4, sub_115674, sub_10F318)
- Configures 0x40241050/0x40580048/0x40035100 based on *0x182BA0

sub_1002A0 = fw_config_apply (large)
- Reads config table at *0x182BA0, sets 0x173364..0x173374 and 0x18257x
- Calls log_printf and validates bounds (msg_parse_blocking on error)

sub_12FE58 = log_list_init
- Calls log_hw_init_if, sets up list 1647340 with nodes 0x182764..0x182830

sub_10D068 = log_hw_regs_init
- Clears bits in 0x40035018 and writes 0x40035008/0x4003500C = 0x8000000

sub_10F0C4 = fw_config_copy
- Copies config fields from 0x182B54 into 0x182B38..0x182B4C
- Calls sub_1033F8/sub_100688/sub_102B4C and optional sub_10C7B8

sub_1033F8 (large)
- RF/PHY init sequence; writes 0x405060xx/0x40580010, waits on 0x40506030

sub_100688 = rf_variant_apply
- Reads variant from 0x40330000, loads table at 0x163F30
- Writes 0x4034006C and 0x182198/0x182199

sub_102B4C = irq_vector_init
- Writes IRQ handlers in vector table (IRQ2/4/6/7/36/37)
- Enables interrupts via 0xE000E100/0xE000E104

sub_10D2C4 = memset_182AAC
- Clears 0x182AAC (size 0x38)

sub_1005B0 = rf_variant_select
- Reads 0x40330000 and helper flags (sub_10194C/sub_101950)
- Returns variant index 0..11 based on a1 and config bits

sub_10F022 = rf_power_reset
- Calls rf_power_set(0xC2), sets 0x182B0F = -62

sub_103180 = rf_power_enable
- If a1: rf_power_set(0xB5), set bit 2 in 0x40035094
- Else rf_power_set(0xC2), clear bit 2

sub_10DD54 = irq_mask_init
- Calls sub_10DB64/10DBAC and sets mask bits via set/clear helpers
- Initializes 0x182AF8/0x182AE8

sub_10194C = rf_flag_const1
- Returns 1

sub_101950 = rf_flag_bit21
- Returns (0x40330000 >> 21) & 1

sub_10DB64 = irq_prio_set
- Clears low 4 bits at 0x40504080+4*a1 and sets 0x40505004 bit

sub_10DBAC = irq_prio_set2
- Sets 0x40505008 bit (1<<a1)

sub_10DC04 = irq_config
- Configures 0x405050xx masks for IRQ line and sets handler in 0x182220+4*irq
- Ensures IRQ23_Handler installed and enabled

sub_10D4E8 = irq23_enable
- Writes IRQ23 vector and enables 0xE000E100 bit 0x200000

sub_10D494 = timer_init
- Initializes 0x40501000/0x40501004/0x40501010/0x40501014
- Enables IRQ23 vector (same as sub_10D4E8)

sub_10D0E4 = hw_reg_set_40035000
- Writes 0x40035000 = 0x2000000

sub_10EE10 = rf_init_blockA (large)
- Repeated sub_10ECEC register programming; extra branch when *0x182BA0 == 1

sub_10E420 = rf_init_blockB (large)
- Configures 0x4010D0xx, uses math helpers, logs values

sub_10E160 = rf_init_blockC (large)
- Configures 0x4010D0xx, uses math helpers, logs values

sub_10ECEC = rf_reg_write_guard
- IRQ-protected wrapper for sub_10ED00

sub_10EC98 = rf_reg_write_wait
- IRQ-protected, waits on 0x4003505C when a3!=0, calls sub_10EC34

sub_10EC2C = rf_reg_read_cb
- Calls function pointer at 0x1B0

sub_10EC3C = rf_reg_write_cb
- Calls function pointer at 0x1B8

sub_10ED00 = rf_reg_write_core
- Calls rf_reg_write_cb and handles IRQ nesting

sub_10EC34 = rf_reg_ack_cb
- Calls function pointer at 0x1B4

sub_10ED40 (disasm)
- Logs via msg_parse, then writes 0x7000000C/0x70000000/0x70001400/0x70001408 via rf_reg_* helpers

sub_10ED98 (disasm)
- Writes 0x7000000C/0x70000020/0x70000000 via rf_reg_* helpers

sub_12FA08 = rf_mem_write
- Parses op size (1/2/4), writes to target address via rf_reg_ack_cb
- Logs via msg_parse, loops count

sub_12E9D8 = rf_mem_read (large)
- Reads via rf_reg_read_cb, logs, handles 1/2/4 widths

sub_10D674 = uart_puts
- Writes bytes to 0x40032000 while 0x40032020 busy

sub_10D65C = uart_putc
- Writes byte to 0x40032000 while 0x40032020 busy

sub_12F8EC = parse_width_suffix
- Parses trailing ".b"/".h" to width 1/2, else 4

sub_12F818 = parse_int
- Parses ASCII integer with base autodetect (0, 8, 10, 16)

sub_112B24 = rf_cmd_start
- If 0x1731BE bit 0x4000: uart_puts("...") else msg_parse
- Sets 0x182522 = 1

sub_112B68 = rf_cmd_stop
- Similar to rf_cmd_start, clears 0x182522 and 0x40200E00 bit 0

sub_112E30 = rf_cmd_wait
- If 0x182522 set: sets 0x40200804 bit 0 and loops

sub_12F920 = rf_cmd_dispatch
- Parses args and calls rf_mem_read/rf_mem_write or read+log

sub_112BAC (large)
- Handles RF command interrupts, sets up 0x40200900/0x40200B00
- Calls rf_cmd_start/rf_cmd_stop and other handlers

sub_112ED0 = rf_cmd_send
- Checks state, writes command struct at 0x186?? and 0x40200900 flags

sub_113418 = rf_cmd_process
- Processes queued commands, uses rf_mem_read/rf_mem_write

sub_114608 = rf_fault_dump
- Logs CPSR/state and dumps memory via rf_mem_read

- sub_1120E8 (decompile failed) - TODO
- sub_1120E8 (disasm) - large RF bus handler using 0x182464/0x187EAC and 0x40200000+0xB14

sub_1128A8 = rf_bus_reset (large)
- Resets bus state at 0x40200E00/0x40200804, loops over 0x40200B00/0x40200900
- Uses sub_11189C/sub_111744 and memset

sub_111A24 = rf_bus_write
- Writes control bits to 0x40200B00/0x40200900 and waits on 0x40200014
- Calls sub_11182C

sub_113374 = rf_cmd_queue_next
- Uses list_count(1592272) and sets 0x18252A/0x187EB4
- Calls rf_cmd_send

sub_11189C = rf_bus_scan
- Loops i=1..5: calls sub_11182C and sub_111864

sub_111744 = rf_bus_mark
- Sets status bits in 0x187E8C/0x187EA4/0x187E90/0x187E94/0x187E98/0x187E9C
- Updates 0x40200B14 and 0x40200914

sub_11182C = rf_bus_clear
- Clears 16-byte entry at 0x182280+16*(a1-1)
- Calls optional callback at 0x1822E8+4*a1

sub_111864 = rf_bus_clear2
- Clears 16-byte entry at 0x1822F0+16*(a1-1)
- Calls optional callback at 0x1822C8+4*(a1+13)

sub_111C04/sub_111C28/sub_111C4C = rf_bus_write_wrappers
- Gate on a2<=5 then call rf_bus_write or rf_bus_write2 with flags

sub_111ADC = rf_bus_write2
- Similar to rf_bus_write, operates on 0x40200900/0x40200920

sub_111C74 = rf_bus_write_wrapper
- Thunk to rf_bus_write

sub_111DBC = rf_bus_setup
- Programs 0x40200900 with timing/size parameters

sub_111C78 = rf_bus_init
- Validates config, copies to 0x1822C8, sets IRQs and starts bus

sub_11316C = rf_bus_start
- Clears 0x187EB8, logs, loops until rf_bus_init succeeds

sub_113210 = rf_stream_start
- Checks flags 0x18252B/0x182529, calls sub_111F08
- Uses rf_bus_write_wrapper on failure

sub_1132B0 = rf_stream_start2
- Similar to rf_stream_start, uses sub_111FDC and sets 0x40200B24/0x40200800

sub_113578 = rf_stream_loop
- Chooses rf_stream_start or rf_stream_start2, retries, handles queue/free on failure

sub_113FD4 = rf_stream_start_once
- Allocates entry via 0x187F00+16, starts stream, frees on error

sub_1137C4 = rf_stream_release
- Enqueues entry back to pool, updates counters, may stop stream and log

sub_113FC4 = rf_stream_kick
- If not running, invokes rf_stream_loop

sub_114028 = rf_stream_start_from_event
- Logs event then calls rf_stream_start_once

sub_112094 = rf_state_check
- If 0x182472 and callback 0x1822DC succeeds, sets state/flags and may start stream

sub_112FC4 = rf_msg_handler
- Parses header, validates length, dispatches to rf_stream_kick and helpers
- Large; TODO: finish mapping message types and offsets

sub_113B08 = rf_msg_process_body
- Validates fields, checks tables, allocates work item via sub_115EC8, copies 0x1C bytes
- Large; TODO: finish mapping fields and queue interactions

sub_11394C = rf_state_is_ready
- Returns (0x17331C == 1)

sub_114088 = rf_msg_log_rate
- Logs message class vs 0x173304/0x173308, optional rate-limit via sub_12C4A4

sub_115EC8 = rf_work_alloc
- List pop from 1582472, warning if empty

sub_12C4A4 = timer_set_relative
- Schedules/updates timer entry keyed by (id, subid) with expiry = now + delta

sub_12C5FC = timer_cancel
- Cancels timer entry keyed by (id, subid) if present

sub_143630 = memcpy_fast
- Optimized memcpy used across log/crypto paths

sub_12EBB8 = rf_timer_stop
- Logs, cancels timer (1071,1), clears 0x40241050 bit 1

sub_12EF20 = rf_timer_toggle
- Cancels timer (1070,1) and alternates between two periods

sub_12EF94 = rf_timer_abort1
- Logs, cancels timer (1069,1), tailcalls sub_12EF88

sub_12EFB0 = rf_timer_abort2
- Logs, cancels timer (1068,1), tailcalls sub_12EF88

sub_12EF88 = rf_timer_abort_common
- Calls sub_114EE0 then sub_10ED40, spins forever

sub_130230 = rf_timer_toggle_start
- Thunk to sub_10DEB0

sub_130370 = rf_timer_toggle_update
- Reads value via sub_10DF08, logs, adjusts 0x1828BB, calls sub_1302F0/sub_130184

sub_1302F0 = rf_level_compute
- Maps input to bounded index, updates 0x1828BD, triggers sub_1301B8/12E91C

sub_130184 = rf_level_step
- Steps 0x1828BE toward 0x1828BD, calls sub_10EDF8 + log

sub_10DEB0 = rf_hw_timer_init
- Programs 0x4010D0xx registers, starts timer

sub_10DF08 = rf_hw_timer_read
- Waits for 0x4010D01C, reads 0x4010D010, applies FP math pipeline

sub_1301B8 = rf_level_apply
- Computes deltas vs table at 0x16B5xx, writes 0x1828C0..0x1828C5, calls sub_102A24

sub_12E91C = rf_feature_check
- Tests bit in 0x18274C and compares 0x182750 threshold

sub_130260 = rf_level_dump
- Logs 0x1828B8..0x1828BE and timer info via sub_12C774

sub_10EDF8 = rf_reg_write_masked
- Wrapper to sub_10ECEC with mask 0xF800

sub_113888 = log_pool_init_D
- Pre-allocates N items into list 1605316 (size 0x7C)

sub_1136D4 = log_pool_init_E
- Pre-allocates N items into list 1605332 (size 0x17323A)

sub_111ADC = rf_bus_write2
- Writes via 0x40200900/0x40200920 with flags and waits

sub_1118BC = rf_bus_reset2
- Programs 0x4020000C/0x40200010 and clears 0x40200800 flags
- Initializes 0x40200B08/0x40200908 tables and logs via msg_parse

sub_111864 = rf_bus_clear2
- Clears entry at 0x1822F0+16*(a1-1) and optional callback

sub_10ED00 = rf_reg_write_core
- Increments a counter, calls rf_reg_write_cb (with optional wait)
- Decrements counter and re-enables IRQs when it hits 0

sub_10EC34 = rf_reg_ack_cb
- Calls function pointer at 0x1B4

- sub_10ED40 (decompile failed) - TODO
- sub_10ED98 (decompile failed) - TODO

## Crypto HW Control (CONFIRMED)
sub_102BF8 = crypto_hw_enable (5 callers)
- Manipulates 0x40344094 (crypto control register)
- If a1==0: clears bits -17, sets 64, 16
- If a1!=0: clears bits -2, sets 4, 1
- Two delay loops: 50 iterations, 50 iterations
- Returns 0x40344094

sub_102C5C = crypto_hw_disable (5 callers)
- Similar to sub_102BF8 but different bit patterns
- If result==0: clears bits -65, sets -17, 16
- If result!=0: clears bits -5, sets 2, 1
- Delay loops: 200 iterations, 50 iterations, 50 iterations
- Returns result

sub_102970 = msg_handler_tx (5 callers)
- If a2: calls msg_parse(0x163E54, 0x163FB4, a2, a4)
- Else: checks cached values at 0x1828F8-0x1828FE against a1[0..3]
- If changed: calls sub_101EC0 (tx_init)
- Checks sub_12CD48(7)==1 || sub_12CD48(6)==3
- Else: calls sub_102A00()

sub_102CCC = tx_rate_config (1 caller from tx_phy_dispatch)
- 98 lines, 18 calls, 6 branches, 7 loops
- Waits for MEMORY[0x40035248] (SDIO ready)
- Calls sub_102BF8(0) (crypto_hw_enable)
- Iterates bits of a1 (rate bitmask), up to 5
- Writes to table at 0x40035200 + (v4 << 9): *v6 = (*v6 & 0xF80007FF) | (rate << 11)
- 16 iterations per rate
- Calls sub_102C5C(0) (crypto_hw_disable)
- Strings: "HR", "xB"

## TX/PHY Functions (CONFIRMED)
sub_10C4AC = tx_phy_dispatch (5 callers)
- Thunk: calls sub_101EC0(a1, a2, a2, 0)

sub_101EC0 = tx_init (4 callers)
- Calls msg_parse(0x163E8C, 0x163F70, a1, a2)
- If state != 3: feature_guard_sdio(4, 0x163F00, a3, state)
- Calls sub_100670 (variant_update), sub_100BE0 (panic_loop)

sub_100670 = variant_update_cache (1 caller)
- Calls sub_1005B0 (chip_variant_detect)
- Caches result at MEMORY[0x182198] if changed

sub_100BE0 = panic_entry (1 caller)
- Thunk to sub_1006D8

sub_1006D8 = panic_loop (2 callers)
- Sets 0x40340018 = 17
- Infinite spin loop with 32-iteration delay
- Strings: "gfff", " \b3@", "$\b3@"

sub_1006CC = get_variant_cached (2 callers)
- Returns MEMORY[0x182199] (cached variant config)

sub_10C220 = tx_phy_config (1 caller)
- 129 lines, 36 calls, 8 branches, 5 loops
- Configures TX PHY from result[0] (rate/chan info)
- Writes -32640 (0x8080) to buffer at a2+2..a2+32
- Waits for MEMORY[0x40035248] (SDIO ready)
- Calculates rate from 0x4050900C/0x40509010
- Uses FP ops: sub_142894, sub_142968, sub_142BBC, sub_1424DC, sub_142EEC
- Calls sub_103A54 (crypto_hw?)
- Strings: "HR" (high rate?)

## Crypto Identification (CONFIRMED)
- AES S-Box at 0x14CBE0 (ROM, const)
- CRC32 table at 0x14A5EC (ROM, little-endian)
- Algorithms: AES, CRC32

sub_10B29A = crypto_mac_dispatch (no callers, orphan)
- Large function: ~282 lines, 46 calls, 21 branches, 12 loops
- 13 parameters (complex crypto operation)
- Calls sub_108140 (crypto_mac_core)
- Calls: sub_12EB90, sub_12E948, sub_102BF8, sub_102C5C, sub_102970, sub_100644
- Strings: "$@4@", "TV" (crypto constants)
- Likely dispatches MAC/crypto operations to core function

## Binary Statistics
- Total functions: 1313 (25 named, 1288 unnamed, 1.9% named)
- Average function size: 188.2 bytes
- Total code in functions: 247,094 bytes
- Largest function: sub_108140 (4140 bytes at 0x108140)
- Smallest function: sub_100200 (2 bytes at 0x100200)
- Total strings: 1128
- No imports (statically linked)
- Single segment: 341,260 bytes code

## Largest Function Analysis
sub_108140 = crypto_mac_core (4140 bytes, 1 caller)
- Massive function: ~593 lines, 125 calls, 9 branches, 20 loops
- Uses memset for buffer initialization
- Calls: sub_103B54, sub_12EB90, sub_103FF4, sub_107084, sub_1058D0, sub_107620, sub_10794C
- Strings contain patterns like "@4@", "DL" (likely crypto constants)
- Likely implements MAC (Message Authentication Code) or crypto operation
- Called from sub_10B29A

## Chip Variant Detection (CONFIRMED)
sub_1005B0 = chip_variant_detect (2 callers)
- Reads MMIO 0x40330000 (chip ID register)
- Extracts: bits 8-11 = variant ID, bit 27 = flag
- Calls sub_10194C() (always returns 1), sub_101950() (bit 21 of chip ID)
- Returns chip type index (0-11) based on variant + features
- Used to select correct config tables

sub_10194C = feature_always_on (2 callers)
- Always returns 1 (hardcoded feature flag)

sub_101950 = chip_feature_check (5 callers)
- Returns bit 21 of MMIO 0x40330000 (chip feature flag)

## PHY/RF Init (CONFIRMED)
sub_1033F8 = phy_rf_init (1 caller from subsystems_init)
- Large function (~290 lines, 87 calls, 24 branches, 12 loops)
- Configures MMIO 0x40500100, 0x40506000-0x4050605C (RF/PHY registers)
- Waits for 0x40506030 & 0x22 == 2
- Sets 0x40580010 = 6
- Uses memset for buffer initialization
- Calls: sub_10DD54, sub_10D4E8, sub_10D0E4, sub_10EE10, sub_10E420, sub_10E160, sub_10D494

## RX Queue Init Details (CONFIRMED)
sub_12C954 = rx_queue_head_init (1 caller)
- Returns 0x18FB04 (rx_queue_head address)
- Sets MEMORY[0x1906A4] = 0
- Sets MEMORY[0x1906A8] = (IRQ36_Handler & ~3) - 0x18FB04
- Uses IRQ save/restore pattern

sub_12D00C = clear_flags (5 callers)
- Clears flags in MEMORY[0x1922A4]: `flags &= ~a1`
- Uses IRQ save/restore pattern
- Called with -1 (0xFFFFFFFF) to clear all flags in rx_queue_init

## SDIO Buffer Prepare (CONFIRMED)
sub_12DFDC = sdio_buffer_prepare (1 caller from sdio_transfer)
- Large function with 89-case switch statement (TBH jump table)
- Parses SDIO command parameters
- Handles different SDIO command types (cases 32-120)
- Prepares buffer for SDIO transfer
- Uses registers R4-R11, LR (heavy stack usage)

## Main Loop Sub-functions (CONFIRMED)
sub_1159A4 = idle_processing (1 caller from main_loop)
- Complex idle processing with multiple state checks
- Calls: sub_128DDC (queue_check), sub_12BC00 (tx_timeout_check), sub_12EB90 (feature_guard)
- Calls: sub_12E8D0 (sdio_wait), sub_1111B4 (state_check), sub_10D1C4 (sdio_status_check)
- Calls: sub_11583C (ipc_doorbell_handler)

sub_128DDC = queue_check (1 caller)
- Checks if queue at 0x18E618 is empty or has pending items
- Returns 0 if !MEMORY[0x190454] && !sub_12A32C()
- Returns 0 if MEMORY[0x190458]
- Walks linked list checking v0[1] field

sub_12BC00 = tx_timeout_check (1 caller)
- Checks TX timeout conditions
- Reads MMIO 0x4032004C (IPC status), 0x40501010 (timer)
- Checks TX queue at 0x18FB00
- If timeout: calls sub_12F32C (error_handler)
- Sets MMIO 0x40501030 = timeout_value, 0x40501008 = 4

sub_12E8D0 = sdio_wait_busy (5 callers)
- Spins while `(MEMORY[0x40032020] & 0x40000) == 0`
- Waits for SDIO busy bit to clear

sub_1111B4 = state_flag_check (5 callers)
- Returns MEMORY[0x1822C4] if set, else MEMORY[0x1822C5]
- Simple state flag getter

sub_10D1C4 = sdio_status_check (3 callers)
- Checks MMIO 0x4050012C (SDIO interrupt mask)
- Checks MMIO 0x40035084 (SDIO status)
- If bit 3 set: checks bit 1, triggers SDIO reset
- Sets MEMORY[0x40035000] = 0x200000, waits for completion
- Calls sub_12EB90 (feature_guard_sdio)

sub_11583C = ipc_doorbell_handler (2 callers)
- Reads IPC doorbell at MMIO 0x40320038
- Sets MEMORY[0x182568] = doorbell & 0xF
- If bit 31 set: clears doorbell, waits for 0x4032806C & 4
- Sets MEMORY[0x182569] = 1, writes doorbell = 32
- If state == 3: sets MMIO 0x40035084 |= 1, 0x40035100 = 512
- If state == 1: calls sub_12E8D0, enables TX/RX interrupts

## Message Processing Pipeline (CONFIRMED)
### sub_12C84C = msg_dispatch (5 callers, hot function)
- Entry point for all message processing
- Reads message type from `a1-6` (offset -6 from message header)
- If type <= 0xC: calls `sub_12D108` (queue_push) + `sub_12CFC4` (set_flag)
- If type > 0xE: calls `sub_12F32C` (error_handler)
- Otherwise: calls `sub_12E948` (msg_parse) + `sub_12CA88` (buffer_pool_get) or `sub_12F3EC`

### sub_12D108 = queue_push (many callers)
- Pushes item to linked list queue
- `*(_DWORD *)queue = item; *(queue+4) = item; *item = 0;`

### sub_12D190 = queue_pop (5 callers)
- Pops item from linked list queue
- `item = *queue; if (tail == item) tail = 0; *queue = *item;`

### sub_12CFC4 = set_flag (many callers)
- Sets flag in `MEMORY[0x1922A4]` (flag register)
- Uses IRQ save/restore pattern with `MEMORY[0x182560]` (IRQ nesting counter)
- `flags |= a1;`

### sub_12CA88 = buffer_pool_get (5 callers)
- Gets buffer from pool at `0x182000` (RAM vector table area)
- Validates buffer integrity
- Uses IRQ save/restore

### sub_12F32C = error_handler (many callers)
- Calls `sub_12E948` (msg_parse) with error codes
- Writes to MMIO `0x40320038` (doorbell?) = 0
- Waits for `MEMORY[0x17348C]` to clear

### sub_12F3EC = fallback_handler (1 caller)
- Thunk to `sub_10CC94`

### sub_10CC94 = state_check (1 caller)
- Checks `*state_ptr != 3`, jumps to `0x10CED8`

### sub_10CD7C = tx_submit (no callers, orphan)
- Submits TX buffer to hardware
- Calls `sub_12D108` (queue_push), `sub_113374` (tx_prepare)
- Calls `sub_11017C` (tx_alloc), `sub_11101C` (tx_setup)
- Calls `sub_12C8F8` (buffer_pool_get)

### sub_113374 = tx_prepare (5 callers)
- Prepares TX buffer for transmission
- Calls `sub_12D22C` (queue_len), `sub_112ED0` (tx_start)
- Returns error codes: -99, -98

### sub_12D22C = queue_len (many callers)
- Counts items in linked list queue
- `while (ptr) { ptr = *ptr; count++; }`

### sub_112ED0 = tx_start (1 caller)
- Starts TX on hardware
- Checks `MEMORY[0x18231F] == 4` (state check)
- Writes to MMIO `0x40200900 + 32*a1` (TX control register)
- Sets bit 0x80000000 (TX enable)

### sub_112E30 = tx_wait (1 caller)
- Waits for TX to complete
- Checks `MEMORY[0x182522]` (TX busy flag)
- If busy: sets `MEMORY[0x40200804] |= 1` and spins forever
- Uses IRQ save/restore

## Main Loop (CONFIRMED)
sub_115C20 = main_loop (noreturn, 1 caller from firmware_init)
```
void __noreturn main_loop() {
    sub_12E948(1472080, 1498584, 1498548, a4);  // init message parser
    if (MEMORY[0x182558]) {
        sub_10EDD4(...);  // IRQ handler setup
        if (*(WORD*)(global_table + 8))
            sub_10ED98(...);  // configure IRQ
    }
    if (*state_ptr == 2) {
        *(BYTE*)(global_table + 6) = 2;
        *(BYTE*)(global_table + 3) = 1;
    }
    v6 = sub_1144FC(*(WORD*)(global_table + 4));
    if (!*(BYTE*)(global_table + 3))
        v6 = sub_114588(v6);
    __enable_irq();
    __dsb(0xF);
    __isb(0xF);

    while (1) {
        if (*(BYTE*)(global_table + 3))
            v6 = sub_114578(v6);
        if (!MEMORY[0x182B64])
            v6 = sub_12D050(v6);
        v6 = sub_130030(v6);

        // Check flags
        flags = MEMORY[0x1922A4];
        counter++;
        if (!flags) {
            v6 = sub_1159A4(v6);  // idle processing
            ...
        }
    }
}
```
- Infinite loop with nested state machine
- Processes flags from MEMORY[0x1922A4]
- Calls: sub_114578, sub_12D050, sub_130030, sub_1159A4, sub_115470
- Uses IRQ save/restore pattern

## Patch Table Loader (CONFIRMED)
sub_114D6C = patch_apply (1 caller from entry point)
- Checks magic at 0x174000: "PTCH" LE (0x48435450)
- Checks magic at 0x174008: "PTCH" BE (0x50544348) - dual-endian validation
- Loads patch table from 0x174004
- Processes patch entries at 0x174010-0x174020 (3 entries)
- Each patch entry: [target_addr, patch_data, size, count]
- Applies patches by copying data to target addresses
- This is how firmware patches are applied at boot!

## Clock/PLL Init (CONFIRMED)
sub_1031D8 = clock_calc (2 callers)
- Reads MMIO 0x40500010 (clock config)
- If bit 1 set: base clock = 320MHz (or 480MHz if bit 2 clear)
- If bit 0 of divisor negative: double clock, mask to 7 bits
- Calculates: MEMORY[0x171898] = clock / MMIO[0x40500020]
- Calculates: MEMORY[0x171894] = MEMORY[0x171898] / MMIO[0x40100024]
- Returns 0x40100000 (base address?)

## Firmware Init Chain (CONFIRMED)
```
sub_114DE8 (TRUE ENTRY POINT, orphan, no callers)
  → Zero BSS: 0x182B58 to 0x198DF4 (clear ~96KB)
  → Copy vector table: 0x120000-0x120198 → 0x182000 (RAM)
  → NVIC: SCB_CPACR |= 0xF00000 (enable FPU)
  → NVIC: VTOR = 0x182000 (relocate vectors to RAM)
  → Clear 86 bytes at 0xDFFFFFFF+768 (unknown peripheral)
  → Check CPUID (0xE000ED00 == 49729 = Cortex-M4)
  → Read chip config from MMIO 0x40500000-0x40500003
  → If bit 26 set: clock = 26MHz
  → sub_1031D8() → sub_114D6C() (hw init)
  → sub_100478() (firmware_init)
    → Set up global pointers
    → sub_1002A0 (subsystem init)
    → sub_12FE58 (SDIO init + queue setup)
    → sub_10D068 → sub_10F0C4 → sub_115674 (init chain)
    → sub_12E948 (parse message)
    → sub_10FFC0 → sub_10F318 (process)
    → sub_12EB90 (feature flag guard)
    → sub_115C20 (enter main loop)
```

## Next Steps
1. Analyze sub_111250 (largest orphan, 428 insns) - main firmware entry
2. Map message type dispatch table
3. Find AES usage functions (WPA/WPA2)
4. Analyze SDIO queue mechanism
5. Map PHY register interface
6. Find firmware patch/update mechanism
7. Analyze power save state machine
