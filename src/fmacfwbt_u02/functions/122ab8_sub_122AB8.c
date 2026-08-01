#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t off_122B08;
extern uint32_t off_122B04;
extern uint32_t dword_122B18;
extern uint32_t dword_122B14;
extern uint32_t off_122B0C;
extern uint32_t off_122B10;

// get_chip_status @ 0x122ab8, size 76 bytes
// Doc: ipc_msg_status_check [ipc]: Inspect IPC message field mask 0x1800000 and branch on r3
// ipc_msg_status_check [ipc]: Inspect IPC message field mask 0x1800000 and branch on r3
char *get_chip_status()
{
  int v0; // r4

  v0 = *(uint32_t *)off_122B08 & 0x1800000;
  if ( **(int16_t **)off_122B04 < 0 && v0 == 25165824 )
    mmio_irq_clear(dword_122B18, dword_122B14, 1308);
  set_system_flag_2(v0);
  if ( *((uint8_t *)off_122B0C + 18) )
    return (char *)irq_lock_save();
  else
    return bt_state_flags_check(*((char **)off_122B10 + 8));
}

