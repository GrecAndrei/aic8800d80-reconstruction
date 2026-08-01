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

extern uint32_t off_10CD0C;
extern uint32_t dword_10CD10;
extern uint32_t dword_10CD14;
extern uint32_t off_10CD18;
extern uint32_t off_10CD1C;
extern uint32_t off_10CD20;

// clear_buffer_180a0c @ 0x10cc98, size 114 bytes
int *clear_buffer_180a0c()
{
  int v0; // r4
  int v1; // zf
  uint8_t v2; // r1
  int **v3; // r4

  v0 = *((uint32_t *)off_10CD0C + 23);
  sub_100200((int *)dword_10CD10, 0, 0x28u);
  sub_100200((int *)dword_10CD14, 0, 0x17C4u);
  if ( (*(uint32_t *)off_10CD18 & 8) != 0 )
  {
    while ( (*(uint32_t *)off_10CD18 & 0x10) == 0 )
      ;
    v3 = (int **)off_10CD1C;
  }
  else
  {
    v2 = v0 & 3;
    v1 = (v0 & 3) == 0;
    v3 = (int **)off_10CD1C;
    *(uint32_t *)off_10CD18 |= 8u;
    if ( v1 )
      sub_100200(*v3, v2, 0x258u);
    *(uint32_t *)off_10CD18 |= 0x10u;
  }
  (*v3)[149] = *(uint32_t *)off_10CD20;
  return config_uart_control();
}

