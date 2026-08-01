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

extern uint32_t dword_12EFA4;
extern uint32_t off_12EFA8;

// cb_send_0x16ae04 @ 0x12ef78, size 42 bytes
// Doc: cb_send_0x16ae04 [ipc]: Dispatch KE message via IPC lookup table
// cb_send_0x16ae04 [ipc]: Dispatch KE message via IPC lookup table
int  cb_send_0x16ae04(int a1, uint32_t *a2, int16_t a3, int16_t a4)
{
  event_dispatch(dword_12EFA4, *a2);
  *((uint32_t *)off_12EFA8 + 1) = *a2;
  ke_msg_send_no_param(1031, a4, a3);
  return 0;
}

