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

extern uint32_t off_130634;
extern uint32_t dword_130638;
extern uint32_t dword_13063C;
extern uint32_t dword_130640;
extern uint32_t off_130644;
extern uint32_t dword_130648;

// log_mac_state @ 0x1305bc, size 118 bytes
// Doc: log_mac_state [rf]: Dump signed RF level readings (signed bytes) to log
// log_mac_state [rf]: Dump signed RF level readings (signed bytes) to log
int log_mac_state()
{
  uint8_t *v0; // r4
  int v1; // r4
  int v2; // r0
  int v4; // [sp+14h] [bp-4h]

  v0 = (uint8_t *)off_130634;
  ke_event_schedule(
    dword_130638,
    *(char *)off_130634,
    *((char *)off_130634 + 1),
    *((char *)off_130634 + 2),
    *((char *)off_130634 + 3));
  ke_event_schedule(dword_13063C, v0[4], v0[5], v0[6]);
  ke_event_schedule(dword_130640, (char)v0[8], (char)v0[9], (char)v0[10], (char)v0[11], (char)v0[12], (char)v0[13]);
  v1 = *((uint8_t *)off_130644 + 363);
  v4 = *((uint32_t *)off_130644 + 91);
  v2 = find_hci_conn_by_handle(1070, 1);
  return ke_event_schedule(dword_130648, v1, v4, v2);
}

