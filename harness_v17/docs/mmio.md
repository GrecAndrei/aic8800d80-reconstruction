# mmio Subsystem

<think>
The user is asking me to stop using tools and output a final JSON answer. However, my original task was to write a markdown document explaining the MMIO subsystem, not a JSON answer. The user seems to have changed the format request to JSON. Let me reconcile this:

1. Original developer policy: Output a markdown document with overview, function groups, data flow, and patterns. Do NOT include raw addresses.
2. User's new message: "Output your final JSON answer NOW"

The user is explicitly asking for JSON. I should comply with the user's request format change. I'll create a JSON document that contains the same information I would have put in the markdown document - just structured as JSON.

Let me write a JSON answer that covers:
1. Overview
2. Function groups
3. Data flow
4. Notable patterns

I should be terse and informative, as instructed.
</think>
```json
{
  "subsystem": "mmio",
  "overview": "The mmio subsystem manages memory-mapped I/O between an SDIO host controller and on-chip peripherals in a Marvell 88W8800-series WiFi/BT firmware image. The vast majority of the 86 functions (~80) are SDIO buffer-descriptor preparation routines that program DMA descriptors for host-driven data transfers. A small set of distinct helpers handles peripheral initialization, register polling, interrupt enabling, RF register access, and buffer release/CRC — together forming the low-level glue between firmware data structures and the SDIO/MMIO hardware blocks.",
  "function_groups": {
    "sdio_buffer_prepare_family": {
      "count": "~80 variants",
      "purpose": "Construct, fill, and validate SDIO DMA/transfer buffer descriptors (host-to-chip and chip-to-host paths).",
      "examples": [
        "sdio_buffer_prepare (multiple demangled instances)",
        "sdio_buffer_prepare_alt",
        "sdio_buffer_prepare_evt",
        "sdio_buffer_prepare_n1b6 / n1f9 / n144 / n172 / n198 / n1fe / n1fd / n20b / n2d0 / n29a / n2ea / n3a0 / n3dc / n3e / n3ee / n366 / n37c / n388 / n3b2 / n43a / n46e / n48c / n4c2 / n5a / n5c / n68 / n7e / n97 / nce / ne0 / nfa / n164",
        "sdio_buffer_prepare_n_1c2 / n_1dc / n_1f6 / n_208 / n_286 / n_2a0 / n_2ba / n_2d8 / n_2f8 / n_31e / n_466 / n_4ae / n_4dc / n_4e8 / n_5e / n_66"
      ]
    },
    "control_and_status": {
      "purpose": "Peripheral control, status reads, and field manipulation in the sysctl / control register space.",
      "functions": [
        "mmio_init_block_n2a0 — peripheral block initialization writing multiple MMIO registers",
        "mmio_status_read_l28 — reads status field at offset 0x28 from a sysctl base",
        "mmio_field_set_l2h2 — clear/set a 0x40000 bitfield in a control register, then trigger a handler",
        "rf_mem_write_n_8a — writes to a memory-mapped RF register"
      ]
    },
    "polling_and_irq": {
      "purpose": "Synchronization with hardware via register polling and interrupt line configuration.",
      "functions": [
        "mmio_reg_poll_ready — generic poll-until-expected-value",
        "mmio_reg_poll_n6b4 — poll MMIO register for a completion condition (variant)",
        "irq23_enable — enable IRQ line 23 in the interrupt controller"
      ]
    },
    "buffer_lifecycle_and_integrity": {
      "purpose": "Teardown of prepared buffers and integrity protection of payloads.",
      "functions": [
        "sdio_buffer_release_n470 — release/cleanup of a previously prepared SDIO buffer",
        "sdio_crc32_calc_n68 — CRC32 over an SDIO buffer using a lookup table"
      ]
    }
  },
  "key_data_flow": {
    "host_to_chip_tx": "Higher-layer code (LMAC/UMAC/BT) calls a sdio_buffer_prepare variant with a payload and transfer parameters. The routine computes byte offsets / shift-based address math (e.g. multiply-by-8 index math, 4KB alignment), fills one or more DMA descriptors in a host-visible ring, optionally prepends a 0x23-style header, and may compute a CRC32. The descriptor ring is then handed to the SDIO controller via MMIO writes.",
    "chip_to_host_rx": "Event/data path uses sdio_buffer_prepare_evt and other variants to set up receive descriptors. Incoming DMA-completed buffers are consumed and then released via sdio_buffer_release_n470.",
    "control_path": "mmio_init_block_n2a0 programs peripheral registers at boot/bring-up. mmio_reg_poll_ready / mmio_reg_poll_n6b4 busy-wait on completion flags. mmio_field_set_l2h2 mutates a control bitfield and invokes a trigger callback. mmio_status_read_l28 samples a status word. irq23_enable unmasks a specific interrupt vector. rf_mem_write_n_8a pokes a memory-mapped RF register."
  },
  "notable_patterns": {
    "polymorphic_buffer_prepare": "A single logical operation (SDIO buffer prepare) is duplicated as ~80 near-identical variants with different entry points, alignment strategies, header conventions, descriptor sizes, and DMA path (host IO, NCE DMA, BT firmware, LMAC event). This pattern is typical of firmware generated from a parameterized template and indicates a code base with many feature/configure combinations compiled together.",
    "shift_based_address_math": "Several variants (e.g. n1b6 'multiply-by-8 index math', n144 'byte offsets/sizes', n5a 'offset/shift', nce 'shift-based address calc') compute descriptor addresses and lengths using bit-shifts rather than multiplication, a hallmark of resource-constrained embedded code.",
    "descriptor_ring_construction": "Many variants operate on scatter/gather descriptor rings (TX and RX) with explicit per-entry field assembly, including flags, length, host address, and sometimes an embedded header (n_286 prepends a 0x23 header).",
    "polling_loops": "Both mmio_reg_poll_ready and mmio_reg_poll_n6b4 implement busy-wait synchronization, often with a mask and expected value compare — consistent with a controller that lacks completion interrupts for every operation.",
    "minimal_crc_helper": "sdio_crc32_calc_n68 is the only integrity primitive in the subsystem, table-driven, called from within buffer prepare flows when a payload needs protection.",
    "peripheral_register_window": "All non-sdio helpers (init, status read, field set, RF write) read or write absolute MMIO addresses derived from a base register (e.g. sysctl base + offset 0x28), confirming a memory-mapped control plane distinct from the SDIO DMA data plane.",
    "irq_vector_targeting": "irq23_enable specifically targets vector 23, suggesting a fixed interrupt map where the SDIO/comms engine's interrupt lives on line 23.",
    "variant_naming_convention": "Function suffixes of the form _nXXX and _n_XXX (hex) correspond to the entry offset within the firmware image, which is why disassembly at that literal address does not always yield code — the suffix is a label, not necessarily the runtime address."
  }
}
```
