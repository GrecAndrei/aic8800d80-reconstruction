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


extern uint32_t dword_102D1C;
extern uint32_t dword_102D40;
extern uint32_t off_102D18;
extern uint32_t off_102D24;
extern uint32_t off_102D28;
extern uint32_t off_102D2C;
extern uint32_t off_102D30;
extern uint32_t off_102D34;
extern uint32_t off_102D38;
extern uint32_t off_102D3C;
extern uint32_t off_102D44;

// periph_wait_status @ 0x102bb0, size 358 bytes
int  periph_wait_status(int a1, uint16_t *a2)
{
  unsigned int v2; // r7
  unsigned int v4; // r11
  int v5; // r8
  unsigned int v6; // r4
  unsigned int *v7; // r6
  int v8; // r5
  unsigned int v9; // r4
  int v10; // t1
  unsigned int v11; // r4
  int v12; // r3
  int result; // r0
  uint64_t *v14; // r3
  char *v15; // r12
  int v16; // r6
  char *v17; // r7
  int v18; // r4
  int v19; // t1
  uint16_t *v20; // r1
  int v21; // r3
  int v22; // r5
  int *v23; // r1
  uint64_t v24; // r2
  int v25; // [sp+Ch] [bp-28h]
  uint64_t v27; // [sp+1Ch] [bp-18h] BYREF
  int *v28; // [sp+24h] [bp-10h]
  uint64_t v29; // [sp+28h] [bp-Ch]

  while ( !*(uint32_t *)off_102D18 )
    ;
  v4 = 0;
  gpio_set_pin(0);
  v5 = dword_102D40;
  v25 = 0;
  while ( ((1 << v4) & a1) == 0 )
  {
    v6 = (uint16_t)v4;
    if ( (uint16_t)v4 == 5 )
      goto LABEL_10;
LABEL_4:
    ++v4;
  }
  v7 = (unsigned int *)(dword_102D1C + (v4 << 9));
  v8 = 0;
  v2 = (unsigned int)(a2 - 1);
  do
  {
    v9 = *v7;
    check_interrupt_flag(0x2000, "before %d,%d: dcq/i=%4x\r\n", v4, v8, (uint16_t)(*v7 >> 11));
    v10 = *(uint16_t *)(v2 + 2);
    v2 += 2;
    v11 = v9 & v5 | (v10 << 11);
    *v7 = v11;
    v7 += 8;
    v12 = v8++;
    check_interrupt_flag(0x2000, "after  %d,%d: dcq/i=%4x\r\n", v4, v12, (uint16_t)(v11 >> 11));
  }
  while ( v8 != 16 );
  if ( v4 <= 1 )
    goto LABEL_4;
  v6 = (uint16_t)v4;
  v25 = 1;
  if ( (uint16_t)v4 != 5 )
    goto LABEL_4;
LABEL_10:
  result = gpio_clear_pin(0);
  *(uint32_t *)off_102D18 = 1;
  if ( v25 )
  {
    if ( (a1 & 0x80) != 0 )
      v2 = 3;
    else
      v6 = 3;
    if ( (a1 & 0x80) == 0 )
      v2 = 0;
    if ( (*(uint32_t *)off_102D24 & 0x8000000) == 0 || (*(uint32_t *)off_102D28 & 0x400) != 0 )
      v14 = (uint64_t *)off_102D44;
    else
      v14 = (uint64_t *)off_102D2C;
    v27 = *v14;
    v23 = *((int **)v14 + 2);
    v24 = *(uint64_t *)((char *)v14 + 12);
    v28 = v23;
    v29 = v24;
  }
  else
  {
    result = 0;
    v28 = (int *)off_102D34[0];
    v27 = __PAIR64__((unsigned int)off_102D30[0], (unsigned int)off_102D38[0]);
    v29 = (unsigned int)off_102D3C;
    if ( (a1 & 0x80) != 0 )
      v6 = 4;
    else
      v6 = 2;
    if ( (a1 & 0x80) != 0 )
      v2 = 2;
    else
      v2 = 0;
  }
  if ( v2 < v6 )
  {
    v15 = (char *)&v27 + 4 * v2 + 4 * (uint16_t)(v6 - 1 - v2) + 4;
    v16 = dword_102D40;
    v17 = (char *)&v27 + 4 * v2;
    do
    {
      v19 = *(uint32_t *)v17;
      v17 += 4;
      v18 = v19;
      v20 = a2;
      v21 = v19;
      v22 = v19 + 320;
      do
      {
        if ( v18 )
        {
          result = *v20;
          *(uint32_t *)(v21 + 16) = *(uint32_t *)(v21 + 16) & v16 | (result << 11);
        }
        v21 += 20;
        ++v20;
      }
      while ( v22 != v21 );
    }
    while ( v17 != v15 );
  }
  return result;
}
