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

extern uint32_t off_124BFC;
extern uint32_t off_124C00;
extern uint32_t off_124C04;
extern uint32_t off_124C08;
extern uint32_t off_124C0C;
extern uint32_t dword_124C10;

// rf_rssi_read @ 0x124b3c, size 192 bytes
// Doc: sub_1224B3C [util]: Helper reading a byte from a global and indexing input pointer
// sub_1224B3C [util]: Helper reading a byte from a global and indexing input pointer
int  rf_rssi_read(uint8_t *a1)
{
  int v1; // r1
  int v3; // r3
  unsigned int *v4; // r0
  int v5; // r1
  unsigned int *v6; // r0
  unsigned int v7; // r1
  unsigned int *v8; // r0
  int v9; // r2

  v1 = *a1;
  v3 = (uint8_t)*(uint32_t *)off_124BFC;
  if ( *a1 )
  {
    v4 = (unsigned int *)off_124C00;
    *(uint32_t *)off_124C00 = *(uint32_t *)off_124C00 & 0xFFFFFF00 | v1;
    *v4 = *v4 & 0xFF0000FF | ((v3 * v1) << 8);
  }
  v5 = a1[1];
  if ( a1[1] )
  {
    v6 = (unsigned int *)off_124C04;
    *(uint32_t *)off_124C04 = *(uint32_t *)off_124C04 & 0xFFFFFF00 | v5;
    *v6 = *v6 & 0xFF0000FF | ((v3 * v5) << 8);
  }
  v7 = a1[2];
  if ( a1[2] )
  {
    v8 = (unsigned int *)off_124C08;
    *(uint32_t *)off_124C08 = *(uint32_t *)off_124C08 & 0xFFFFFF00 | v7;
    *v8 = *v8 & 0xFF0000FF | ((v3 * v7) << 8);
  }
  if ( a1[3] )
  {
    v7 = (unsigned int)off_124C0C;
    *(uint32_t *)off_124C0C = *(uint32_t *)off_124C0C & 0xFFFFFF00 | a1[3];
  }
  if ( a1[4] )
  {
    v7 = (unsigned int)off_124C0C;
    *(uint32_t *)off_124C0C = *(uint32_t *)off_124C0C & 0xFFFF00FF | (a1[4] << 8);
  }
  v9 = a1[5];
  if ( a1[5] )
  {
    v7 = (unsigned int)off_124C0C;
    *(uint32_t *)off_124C0C = *(uint32_t *)off_124C0C & 0xFF00FFFF | (v9 << 16);
  }
  event_dispatch(dword_124C10, v7, v9);
  return send_msg(a1, 6, 1, 0);
}

