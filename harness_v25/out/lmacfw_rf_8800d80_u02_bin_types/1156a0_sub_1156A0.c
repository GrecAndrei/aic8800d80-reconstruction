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

extern uint32_t dword_115744;
extern uint32_t dword_115740;
extern uint32_t off_11573C;
extern uint32_t dword_11574C;
extern uint32_t dword_115748;
extern uint32_t off_115750;

// sub_1156A0 @ 0x1156a0, size 154 bytes
int * sub_1156A0(int a1, int a2, int a3, int a4)
{
  int v4; // zf
  int *v6; // r5
  int v7; // r2
  int v8; // r3
  void *v11; // r8
  int *result; // r0

  v4 = a3 == 5;
  if ( a3 != 5 )
    a4 = 7 * a3;
  if ( a3 == 5 )
    v6 = (int *)dword_115744;
  else
    v6 = (int *)dword_115740;
  v7 = **(int16_t **)off_11573C;
  if ( !v4 )
    v6 += a4;
  v8 = *v6;
  if ( v7 < 0 && v8 == a1 )
    return (int *)sub_121960(dword_11574C, dword_115748, 1972, v8);
  if ( v8 )
  {
    v11 = off_115750;
    if ( *(uint8_t *)(*(uint32_t *)off_115750 + 1) || !v6[2] )
      *(uint32_t *)(v8 + 4) = a1;
    else
      *(uint32_t *)(v6[1] + 4) = a1;
    result = (int *)sub_11532C(a3);
  }
  else
  {
    result = sub_1153F4(a1, a3, v7, 0);
    v11 = off_115750;
  }
  if ( !*(uint8_t *)(*(uint32_t *)v11 + 1) )
  {
    if ( (*(uint32_t *)(a2 + 56) & 0x200000) != 0 )
    {
      v6[1] = a1;
      v6[2] = 1;
    }
    else
    {
      v6[1] = 0;
      v6[2] = 0;
    }
  }
  *(uint32_t *)(dword_115740 + 28 * a3) = a2;
  return result;
}

