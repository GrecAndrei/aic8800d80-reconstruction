# AIC8800D80 KE Kernel Extraction

Extracted from `fmacfw_8800d80_h_u02.bin` — the FullMAC WiFi firmware for the AIC8800D80 wireless chip.

## Binary Slices Extracted

| File | Offset Range | Size | Description |
|------|-------------|------|-------------|
| `fmacfw_full.bin` | 0x00000 - 0x5350C | 341,260 | Complete firmware |
| `vectors_and_startup.bin` | 0x00000 - 0x01000 | 4,096 | Cortex-M vector table + Reset_Handler + early init |
| `kernel_core.bin` | 0x01000 - 0x10000 | 61,440 | Kernel bootstrap, scheduler, message passing, timers, memory |
| `kernel_function_table.bin` | 0x4A000 - 0x4A600 | 1,536 | Exported function name strings + task descriptors |
| `task_descriptors.bin` | 0x4A200 - 0x4A300 | 256 | TASK_DESC array (task registration table) |

## Architecture

The KE (Kernel Environment) is the RivieraWaves RTOS microkernel for ARM Cortex-M. It provides:
- Cooperative multi-tasking with 8 task slots
- Inter-task message passing (ke_msg_alloc/free)
- State machine framework per task
- Event dispatching (ke_evt_schedule)
- Timer services (ke_timer_set/clear)
- Memory allocation (ke_malloc/free) with static pools
- Intrusive doubly-linked lists (co_list_*)

## Kernel API Surface

### Task Management
- `ke_task_local` — Check if a task ID is local (on this core)
- `ke_task_schedule` — Schedule a task to run
- `ke_task_handler_get` — Get the message handler for a task state

### State Machine
- `ke_state_set` — Set current state of a task
- `ke_state_get` — Get current state of a task
- `ke_stateid_ptr` — Get pointer to state ID variable
- `ke_handler_search` — Search for message handler in state table

### Message Passing
- `ke_msg_alloc` — Allocate a kernel message buffer
- `ke_malloc` — Allocate from kernel heap
- `ke_free` — Free kernel heap allocation

### Events
- `ke_evt_schedule` — Schedule an event for processing
- `ke_evt_get` — Read current event flags
- `ke_evt_hdlr` — Event handler dispatch table

### Timers
- `ke_timer_set` — Set a kernel timer
- `ke_timer_clear` — Cancel a kernel timer

### List Utilities (co_)
- `co_list_push_back` — Append to linked list
- `co_list_push_front` — Prepend to linked list
- `co_list_extract` — Remove element from list
- `co_list_remove` — Delete element from list
- `co_list_is_empty` — Check if list is empty
- `co_list_pick` — Get first element without removing

## Registered Tasks

| Task | State Handler | Message Table | Max Instances | States |
|------|--------------|---------------|---------------|--------|
| MM (MAC Manager) | 0x169114 | 0x168F4C | 5 | MM_IDLE, MM_NO_IDLE, MM_HOST_BYPASSED |
| SM (Station Manager) | 0x1699B4 | 0x190678 | 4 | SM_IDLE, SM_SCANNING, SM_JOINING, SM_BSS_PARAM_SETTING, SM_STA_ADDING, SM_DISCONNECTING, SM_FT_OVER_AIR |
| SCAN | — | — | — | SCAN_WAIT_BEACON_PROBE_RSP, SCAN_WAIT_CHANNEL |
| ME (Management Entity) | — | — | — | ME_BUSY |
| APM (AP Manager) | — | — | — | APM_IDLE, APM_STOPPING, APM_BSS_PARAM_SETTING, APM_BCN_SETTING |
| BAM (Block Ack Manager) | — | — | — | BAM_INVALID_TASK_IDX, BAM_DELETE |

Maximum task types: TASK_MAX = 8

## Key Constants
- `KE_TIMER_DELAY_MAX` — Maximum timer delay value
- `KE_EVT_MAX` — Maximum event types
- `KE_BUILD_ID(type, idx)` — Macro to build task instance ID

## Data Structures (Inferred)

### TASK_DESC
```c
struct task_desc {
    void *state_handler;   // State handler table
    void *msg_table;       // Message dispatch table
    uint32_t field_8;      // Unknown (varies per task)
    uint16_t idx_max;      // Max instances of this task type
    uint16_t flags;        // Task flags
};
```

### State Handler
```c
struct state_handler {
    const struct msg_handler *msg_table;  // Array of {msg_id, func_ptr} pairs
    // ... state-specific data follows
};
```

### Kernel Message
```c
struct ke_msg {
    uint16_t id;           // Message ID
    uint16_t dest_id;      // Destination task ID
    uint16_t src_id;       // Source task ID
    uint16_t param_len;    // Parameter length
    uint32_t param[];      // Variable-length parameters
};
```

## Memory Map (Runtime)
- ROM (firmware): `0x00000000 - 0x0005350C`
- SRAM: `0x20000000 - 0x2007FFFF`
- WiFi MAC registers: `0x40010000`
- Bluetooth base: `0x40020000`
- Initial stack pointer: `0x001A0000`

## Notes
- All code is ARM Thumb-2, Cortex-M target
- The function name table at 0x4A000+ is used by assertion macros for debug strings
- The actual function bodies for ke_* and co_* functions are scattered throughout the binary
- 64 vector table entries, 13 active handlers
- No dynamic loading — all code is statically linked
