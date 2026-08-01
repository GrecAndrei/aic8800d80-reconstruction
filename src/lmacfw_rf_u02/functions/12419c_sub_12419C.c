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

extern uint32_t off_124240;
extern uint32_t dword_124228;
extern uint32_t off_12423C;
extern uint32_t dword_124230;
extern uint32_t dword_124234;
extern uint32_t off_12422C;
extern uint32_t off_124238;

// mac_tx_frame @ 0x12419c, size 140 bytes
int  mac_tx_frame(int a1, int a2, int a3, int a4, int a5)
{
  uint8_t *v5; // r9
  char v8; // r8
  int v10; // r3
  int *v11; // r3
  int v12; // r5
  int v13; // r6
  int v14; // r4
  int v15; // r5

  v5 = off_124240;
  v8 = a3;
  dispatch_event_handler(dword_124228, a1, a2, a3, a4, a5, *((uint8_t *)off_124240 + 36));
  if ( v5[36] )
  {
    if ( a1 == 2 )
    {
      v10 = *(uint32_t *)off_12423C;
    }
    else
    {
      if ( a1 == 1 )
        v11 = (int *)dword_124230;
      else
        v11 = (int *)dword_124234;
      v10 = *v11;
    }
  }
  else if ( a1 )
  {
    v10 = *(uint32_t *)off_12422C;
  }
  else
  {
    v10 = *(uint32_t *)off_124238;
  }
  v12 = v10 + 4 * a2;
  v13 = ~(a4 << v8);
  v14 = v12 + 12;
  v15 = v12 + 204;
  do
  {
    *(uint32_t *)(v14 - 12) = *(uint32_t *)(v14 - 12) & v13 | (a5 << v8);
    v14 += 12;
  }
  while ( v15 != v14 );
  return memcpy_advance(1, (16 * a1) & 0xF0, 0x10u, v10);
}

