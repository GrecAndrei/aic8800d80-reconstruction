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

extern uint32_t off_12376C;
extern uint32_t dword_12377C;
extern uint32_t dword_123774;
extern uint32_t dword_123778;
extern uint32_t off_123770;

// sub_1236B4 @ 0x1236b4, size 184 bytes
int  sub_1236B4(int a1, uint8_t *a2, int a3, int a4)
{
  uint8_t *v5; // r0
  int16_t **v6; // r6
  uint8_t *v7; // r5
  int v8; // r3

  v5 = (uint8_t *)sub_12C7EC(37, a4, a3, 2);
  v6 = (int16_t **)off_12376C;
  *v5 = 1;
  v7 = v5;
  if ( **v6 < 0 )
  {
    if ( *a2 <= 5u || (sub_12F32C(dword_12377C, dword_123774, 1725), **v6 < 0) )
    {
      if ( a2[4] > 0x20u )
        sub_12F32C(dword_123778, dword_123774, 1726);
    }
  }
  switch ( a2[40] )
  {
    case 0u:
    case 1u:
    case 3u:
      v8 = (*(uint32_t *)off_123770 >> 6) & 1;
      goto LABEL_4;
    case 2u:
    case 5u:
    case 8u:
      v8 = (*(uint32_t *)off_123770 >> 7) & 1;
      goto LABEL_4;
    case 4u:
      v8 = (*(uint32_t *)off_123770 >> 13) & 1;
      goto LABEL_4;
    case 6u:
    case 7u:
      v8 = (*(uint32_t *)off_123770 >> 9) & 1;
LABEL_4:
      if ( v8 && a2[4] <= 0x20u && *a2 <= 5u )
      {
        v7[1] = sub_1212D8(a2);
        *v7 = 0;
      }
      break;
    default:
      break;
  }
  sub_12C84C(v7);
  return 0;
}

