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

extern uint32_t off_12D074;
extern uint32_t dword_12D09C;
extern uint32_t dword_12D090;
extern uint32_t dword_12D078;
extern uint32_t dword_12D0A4;
extern uint32_t dword_12D0A0;
extern uint32_t dword_12D0A8;
extern uint32_t dword_12D098;
extern uint32_t dword_12D094;
extern uint32_t dword_12D07C;
extern uint32_t dword_12D0AC;
extern uint32_t dword_12D080;
extern uint32_t off_12D084;
extern uint32_t off_12D088;
extern uint32_t dword_12D08C;

// sub_12CF5C @ 0x12cf5c, size 278 bytes
uint32_t * sub_12CF5C(unsigned int a1, int a2)
{
  int16_t **v2; // r7
  unsigned int v5; // r9
  int v6; // r6
  uint16_t *v7; // r9
  uint32_t *result; // r0
  int ( *v9)(uint32_t *, int); // r8
  int v10; // r7
  int *v11; // r6
  int *v12; // r5
  int v13; // r0
  int v14; // r3
  int v15; // r2
  int v16; // r6

  v2 = (int16_t **)off_12D074;
  v5 = a1 >> 8;
  v6 = (uint8_t)a1;
  if ( **(int16_t **)off_12D074 >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 > 0xDu )
  {
    sub_12F694(dword_12D09C, dword_12D090, 173);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v7 = (uint16_t *)(*(uint32_t *)(dword_12D078 + 16 * v6 + 8) + 2 * v5);
      goto LABEL_3;
    }
    if ( v6 != 14 )
      sub_12F694(dword_12D0A4, dword_12D0A0, 183);
  }
  else if ( (uint8_t)a1 != 13 )
  {
    goto LABEL_16;
  }
  sub_12F694(dword_12D0A8, dword_12D090, 174);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_16:
  v16 = dword_12D078 + 16 * v6;
  if ( *(uint16_t *)(v16 + 14) > v5 )
  {
    v7 = (uint16_t *)(*(uint32_t *)(v16 + 8) + 2 * v5);
    if ( v7 )
      goto LABEL_3;
    goto LABEL_18;
  }
  sub_12F694(dword_12D098, dword_12D090, 175);
  v7 = (uint16_t *)(*(uint32_t *)(v16 + 8) + 2 * v5);
  if ( **v2 < 0 && !v7 )
LABEL_18:
    sub_12F694(dword_12D094, dword_12D090, 180);
LABEL_3:
  result = (uint32_t *)sub_12ECB0(dword_12D07C, a1, a2);
  if ( (uint16_t)*v7 != a2 )
  {
    v9 = (int ( *)(uint32_t *, int))dword_12D0AC;
    v10 = dword_12D080;
    v11 = (int *)off_12D084;
    *v7 = a2;
    while ( 1 )
    {
      result = sub_12CC64(v10, v9, a1);
      if ( !result )
        break;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v11 = 1;
      }
      v12 = (int *)off_12D088;
      v13 = dword_12D08C;
      ++*(uint32_t *)off_12D088;
      sub_12D470(v13);
      v14 = *v12 - 1;
      if ( *v12 )
      {
        v15 = *v11;
        *v12 = v14;
        if ( !v14 )
        {
          if ( v15 )
            __enable_irq();
        }
      }
      sub_12D32C(0x4000000);
    }
  }
  return result;
}

