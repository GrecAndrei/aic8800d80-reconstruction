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

extern uint32_t off_1292C0;
extern uint32_t off_1292CC;
extern uint32_t off_1292C8;
extern uint32_t dword_1292D0;
extern uint32_t off_1292C4;

// wlc_bus_state @ 0x129208, size 184 bytes
void  wlc_bus_state(uint16_t *a1, int16_t a2, int a3)
{
  uint8_t *v3; // r5
  uint16_t v4; // r6
  int v6; // r3
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r1

  v3 = off_1292C0;
  if ( *(uint8_t *)off_1292C0 )
  {
    v4 = *a1;
    if ( (a1[2] & 1) != 0 )
    {
      if ( *((uint8_t *)off_1292C0 + 29) == 5 )
      {
        fault_handler((int)off_1292C0 + 12);
        v3[29] = 0;
      }
      if ( (v4 & 0x2000) == 0 || *(uint8_t *)(a3 + 114) )
      {
        *(uint32_t *)(a3 + 4) &= ~2u;
      }
      else
      {
        *(uint32_t *)(a3 + 4) |= 2u;
        if ( !v3[29] )
        {
          v9 = *((uint32_t *)off_1292CC + 4);
          v10 = *(uint16_t *)(*(uint32_t *)off_1292C8 + 56);
          *((uint32_t *)v3 + 5) = a3;
          v3[29] = 5;
          unknown_worker(dword_1292D0, v10 + v9);
        }
      }
    }
    else if ( *(uint8_t *)off_1292C4 )
    {
      llcp_is_control(a3, *a1, a1);
    }
    else if ( (a2 & 0x200) == 0 )
    {
      v6 = *((uint32_t *)off_1292CC + 4);
      v7 = *(uint16_t *)(*(uint32_t *)off_1292C8 + 54);
      *((uint32_t *)off_1292C0 + 5) = a3;
      v3[29] = 2;
      unknown_worker((int)(v3 + 12), v7 + v6);
      v8 = *(uint32_t *)(a3 + 4);
      if ( (v4 & 0x2000) != 0 )
      {
        if ( (v8 & 4) == 0 )
          *(uint32_t *)(a3 + 4) = v8 | 4;
        wlc_core_state();
      }
      else
      {
        *(uint32_t *)(a3 + 4) = v8 & 0xFFFFFFFB;
      }
    }
  }
}

