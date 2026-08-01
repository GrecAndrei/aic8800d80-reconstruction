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

extern uint32_t off_119470;
extern uint32_t off_11946C;
extern uint32_t off_119474;

// event_dispatch @ 0x119420, size 76 bytes
int  event_dispatch(int a1, int *a2, int a3, int a4)
{
  char *v7; // r7
  uint32_t *v8; // r3
  int v9; // r6
  int v10; // r4
  int v11; // r12
  int v12; // r5
  int v13; // r6

  if ( *(uint8_t *)a2 )
  {
    v7 = (char *)off_119470;
    if ( (*((uint8_t *)off_11946C + 1) & 1) == 0 || (*((uint32_t *)off_119470 + 98) & 1) != 0 )
    {
      v8 = off_119474;
      v9 = *a2;
      v10 = a2[2];
      v11 = a2[3];
      *((uint32_t *)off_119474 + 1) = a2[1];
      *(uint32_t *)(v7 + 266) = v9;
      v12 = a2[5];
      v13 = a2[4];
      v8[2] = v10;
      v8[6] = a2[6];
      v8[3] = v11;
      v8[4] = v13;
      v8[5] = v12;
    }
  }
  ke_evt_handler(122, a4, a3);
  return 0;
}

