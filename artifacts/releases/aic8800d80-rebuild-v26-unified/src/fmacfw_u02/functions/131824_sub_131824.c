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

extern uint32_t dword_131914;
extern uint32_t off_131918;
extern uint32_t off_13191C;

// sub_131824 @ 0x131824, size 238 bytes
int  sub_131824(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int v5; // r0
  int v6; // r2
  int v7; // r6
  int v8; // r5
  int16_t v9; // r0
  int16_t v10; // r1
  int16_t v11; // r2
  uint16_t v12; // r4
  int v13; // r0
  unsigned int v14; // r2
  int v15; // r1
  int v16; // r2
  int *v17; // r4
  int v18; // r3
  int v19; // r0
  int v20; // r3
  int v21; // r3
  int v22; // r2

  v5 = sub_12C92C(5135, a4, a3, 0xC8u);
  v6 = *a2;
  v7 = v5;
  v8 = *(uint32_t *)(dword_131914 + 696 * v6 + 340);
  *(uint8_t *)v5 = v6;
  if ( v8 )
  {
    v9 = *(uint16_t *)(v8 + 184);
    v10 = *(uint16_t *)(v8 + 144);
    v11 = *(uint16_t *)(v8 + 146);
    *(uint32_t *)(v7 + 8) = *(uint32_t *)(v8 + 148);
    *(uint16_t *)(v7 + 2) = v9;
    *(uint16_t *)(v7 + 4) = v10;
    *(uint16_t *)(v7 + 6) = v11;
    *(uint8_t *)(v7 + 12) = *(uint8_t *)(v8 + 168);
    *(uint8_t *)(v7 + 13) = *(uint16_t *)(v8 + 152);
    sub_143770(v7 + 14, v8 + 136, 8);
    sub_143770(v7 + 22, v8 + 4, 120);
    if ( *(uint16_t *)(v8 + 184) )
    {
      v12 = 0;
      do
      {
        v13 = sub_13F4B0(v8, (uint8_t)v12, 0);
        v14 = *(uint16_t *)(v8 + 184);
        *(uint32_t *)(v7 + 4 * v12++ + 156) = v13;
      }
      while ( v14 > v12 );
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_131918 = 1;
    }
    v15 = *(uint32_t *)(v8 + 128);
    v16 = *(uint32_t *)(v8 + 132);
    v17 = (int *)off_13191C;
    *(uint32_t *)(v7 + 142) = *(uint32_t *)(v8 + 124);
    v18 = *v17;
    *(uint32_t *)(v7 + 146) = v15;
    *(uint32_t *)(v7 + 150) = v16;
    *v17 = v18 + 1;
    v19 = sub_13F4B0(v8, 10, 0);
    v20 = *v17;
    *(uint32_t *)(v7 + 196) = v19;
    if ( v20 )
    {
      v21 = v20 - 1;
      v22 = *(uint32_t *)off_131918;
      *v17 = v21;
      if ( !v21 )
      {
        if ( v22 )
          __enable_irq();
      }
    }
    sdio_buffer_prepare_n_4e8(v7);
    return 0;
  }
  else
  {
    *(uint16_t *)(v5 + 2) = 0;
    sdio_buffer_prepare_n_4e8(v5);
    return 0;
  }
}

