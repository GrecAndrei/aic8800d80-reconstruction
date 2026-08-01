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

extern uint32_t off_11A9A4;
extern uint32_t off_11A9A8;
extern uint32_t off_11A9AC;
extern uint32_t off_11A9B0;
extern uint32_t off_11A9B4;
extern uint32_t dword_11A9B8;

// mmio_select_port @ 0x11a8e4, size 192 bytes
// Doc: mmio_select_port [mmio]: Reads byte status field and MMIO register value from 0x403200e4
// mmio_select_port [mmio]: Reads byte status field and MMIO register value from 0x403200e4
int  mmio_select_port(uint8_t *a1)
{
  int v1; // r1
  int v3; // r3
  unsigned int *v4; // r0
  int v5; // r1
  unsigned int *v6; // r0
  unsigned int v7; // r1
  unsigned int *v8; // r0

  v1 = *a1;
  v3 = (uint8_t)*(uint32_t *)off_11A9A4;
  if ( *a1 )
  {
    v4 = (unsigned int *)off_11A9A8;
    *(uint32_t *)off_11A9A8 = *(uint32_t *)off_11A9A8 & 0xFFFFFF00 | v1;
    *v4 = *v4 & 0xFF0000FF | ((v3 * v1) << 8);
  }
  v5 = a1[1];
  if ( a1[1] )
  {
    v6 = (unsigned int *)off_11A9AC;
    *(uint32_t *)off_11A9AC = *(uint32_t *)off_11A9AC & 0xFFFFFF00 | v5;
    *v6 = *v6 & 0xFF0000FF | ((v3 * v5) << 8);
  }
  v7 = a1[2];
  if ( a1[2] )
  {
    v8 = (unsigned int *)off_11A9B0;
    *(uint32_t *)off_11A9B0 = *(uint32_t *)off_11A9B0 & 0xFFFFFF00 | v7;
    *v8 = *v8 & 0xFF0000FF | ((v3 * v7) << 8);
  }
  if ( a1[3] )
  {
    v7 = (unsigned int)off_11A9B4;
    *(uint32_t *)off_11A9B4 = *(uint32_t *)off_11A9B4 & 0xFFFFFF00 | a1[3];
  }
  if ( a1[4] )
  {
    v7 = (unsigned int)off_11A9B4;
    *(uint32_t *)off_11A9B4 = *(uint32_t *)off_11A9B4 & 0xFFFF00FF | (a1[4] << 8);
  }
  if ( a1[5] )
  {
    v7 = (unsigned int)off_11A9B4;
    *(uint32_t *)off_11A9B4 = *(uint32_t *)off_11A9B4 & 0xFF00FFFF | (a1[5] << 16);
  }
  dispatch_event_handler(dword_11A9B8, v7);
  return handle_ipc_request(a1, 6, 1, 0);
}

