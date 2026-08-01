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

extern uint32_t off_124E30;
extern uint32_t off_124E34;
extern uint32_t off_124E38;
extern uint32_t off_124E3C;
extern uint32_t off_124E40;
extern uint32_t dword_124E44;

// radio_read_config @ 0x124d70, size 192 bytes
int  radio_read_config(uint8_t *a1)
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
  v3 = (uint8_t)*(uint32_t *)off_124E30;
  if ( *a1 )
  {
    v4 = (unsigned int *)off_124E34;
    *(uint32_t *)off_124E34 = *(uint32_t *)off_124E34 & 0xFFFFFF00 | v1;
    *v4 = *v4 & 0xFF0000FF | ((v3 * v1) << 8);
  }
  v5 = a1[1];
  if ( a1[1] )
  {
    v6 = (unsigned int *)off_124E38;
    *(uint32_t *)off_124E38 = *(uint32_t *)off_124E38 & 0xFFFFFF00 | v5;
    *v6 = *v6 & 0xFF0000FF | ((v3 * v5) << 8);
  }
  v7 = a1[2];
  if ( a1[2] )
  {
    v8 = (unsigned int *)off_124E3C;
    *(uint32_t *)off_124E3C = *(uint32_t *)off_124E3C & 0xFFFFFF00 | v7;
    *v8 = *v8 & 0xFF0000FF | ((v3 * v7) << 8);
  }
  if ( a1[3] )
  {
    v7 = (unsigned int)off_124E40;
    *(uint32_t *)off_124E40 = *(uint32_t *)off_124E40 & 0xFFFFFF00 | a1[3];
  }
  if ( a1[4] )
  {
    v7 = (unsigned int)off_124E40;
    *(uint32_t *)off_124E40 = *(uint32_t *)off_124E40 & 0xFFFF00FF | (a1[4] << 8);
  }
  v9 = a1[5];
  if ( a1[5] )
  {
    v7 = (unsigned int)off_124E40;
    *(uint32_t *)off_124E40 = *(uint32_t *)off_124E40 & 0xFF00FFFF | (v9 << 16);
  }
  ke_event_schedule(dword_124E44, v7, v9);
  return rx_packet_handler(a1, 6, 1, 0);
}

