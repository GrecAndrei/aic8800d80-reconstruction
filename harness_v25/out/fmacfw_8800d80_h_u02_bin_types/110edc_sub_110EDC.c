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

extern uint32_t off_110FCC;
extern uint32_t off_110FF8;
extern uint32_t off_110FD0;
extern uint32_t off_110FE8;
extern uint32_t off_110FEC;
extern uint32_t dword_110FF0;
extern uint32_t off_110FF4;
extern uint32_t off_110FD4;
extern uint32_t off_110FD8;
extern uint32_t off_110FDC;
extern uint32_t off_110FE0;
extern uint32_t off_110FE4;

// sub_110EDC @ 0x110edc, size 238 bytes
int  sub_110EDC(int a1, int a2, int a3)
{
  int *v6; // r9
  uint8_t *v7; // r3
  int v8; // r5
  int result; // r0
  uint32_t *v10; // r4
  uint32_t *v11; // r3
  uint32_t *v12; // r1
  int v13; // r5
  int v14; // r3
  uint32_t *v15; // r2
  uint8_t *v16; // r4
  uint8_t *v17; // r5
  int v18; // r3
  uint8_t *v19; // r10
  int v20; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110FCC = 1;
  }
  v6 = (int *)off_110FF8;
  v7 = *(uint8_t **)off_110FD0;
  v8 = *(uint32_t *)off_110FF8 + 1;
  *(uint32_t *)off_110FF8 = v8;
  result = *v7;
  if ( result == 1 )
  {
    v16 = off_110FE8;
    if ( *(uint8_t *)off_110FE8 )
    {
      v19 = off_110FEC;
      v20 = *((uint8_t *)off_110FEC + 374);
      if ( v20 != 1 )
        goto LABEL_4;
      result = sub_124E3C(dword_110FF0);
      if ( result )
        goto LABEL_18;
      if ( v19[369] )
        sub_10DBD4(v20);
      else
        sub_10DBC0(v20);
    }
    else
    {
      v17 = (uint8_t *)off_110FEC;
      if ( *((uint8_t *)off_110FEC + 369) )
        result = sub_10DBD4(1);
      else
        result = sub_10DBC0(1);
      v18 = v17[374];
      *v16 = 1;
      if ( v18 != 1 )
        goto LABEL_18;
    }
    result = sub_124BFC(dword_110FF0, *((uint32_t *)off_110FF4 + 4) + 10000);
LABEL_18:
    v8 = *v6;
  }
LABEL_4:
  v10 = off_110FD4;
  *(uint32_t *)off_110FD4 = 256;
  while ( (*v10 & 0x200) != 0 )
    ;
  if ( *(uint32_t *)off_110FD8 )
  {
    v11 = off_110FDC;
    v12 = off_110FE0;
    *(uint32_t *)(*((uint32_t *)off_110FDC + 769) + 4) = a1;
    *v12 += a2;
  }
  else
  {
    v15 = off_110FE0;
    *(uint32_t *)off_110FD8 = a1;
    v11 = off_110FDC;
    *v15 += a2;
  }
  *(uint32_t *)off_110FE4 = 256;
  v11[769] = a3;
  if ( v8 )
  {
    v13 = v8 - 1;
    v14 = *(uint32_t *)off_110FCC;
    *v6 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}

