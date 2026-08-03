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

extern uint32_t off_102D18;
extern uint32_t dword_102D48;
extern uint32_t dword_102D40;
extern uint32_t dword_102D1C;
extern uint32_t dword_102D20;
extern uint32_t off_102D24;
extern uint32_t off_102D28;
extern uint32_t off_102D44;
extern uint32_t off_102D2C;
extern uint32_t dword_102D34;
extern uint32_t dword_102D30;
extern uint32_t dword_102D38;
extern uint32_t dword_102D3C;

// sub_102BB0 @ 0x102bb0, size 358 bytes
int  sub_102BB0(int a1, uint16_t *a2)
{
  unsigned int v2; // r7
  unsigned int v4; // r11
  int v5; // r9
  int v6; // r8
  unsigned int v7; // r4
  unsigned int *v8; // r6
  int v9; // r5
  unsigned int v10; // r4
  int v11; // t1
  int v12; // r1
  unsigned int v13; // r4
  int v14; // r3
  int result; // r0
  unsigned uint64_t *v16; // r3
  char *v17; // r12
  int v18; // r6
  char *v19; // r7
  int v20; // r4
  int v21; // t1
  uint16_t *v22; // r1
  int v23; // r3
  int v24; // r5
  int v25; // r1
  uint64_t v26; // r2
  int v27; // [sp+Ch] [bp-28h]
  unsigned uint64_t v29; // [sp+1Ch] [bp-18h] BYREF
  int v30; // [sp+24h] [bp-10h]
  uint64_t v31; // [sp+28h] [bp-Ch]

  while ( !*(uint32_t *)off_102D18 )
    ;
  v4 = 0;
  sub_102ADC(0);
  v5 = dword_102D48;
  v6 = dword_102D40;
  v27 = 0;
  while ( ((1 << v4) & a1) == 0 )
  {
    v7 = (uint16_t)v4;
    if ( (uint16_t)v4 == 5 )
      goto LABEL_10;
LABEL_4:
    ++v4;
  }
  v8 = (unsigned int *)(dword_102D1C + (v4 << 9));
  v9 = 0;
  v2 = (unsigned int)(a2 - 1);
  do
  {
    v10 = *v8;
    sub_11F74C(0x2000, v5, v4, v9, (uint16_t)(*v8 >> 11));
    v11 = *(uint16_t *)(v2 + 2);
    v2 += 2;
    v12 = dword_102D20;
    v13 = v10 & v6 | (v11 << 11);
    *v8 = v13;
    v8 += 8;
    v14 = v9++;
    sub_11F74C(0x2000, v12, v4, v14, (uint16_t)(v13 >> 11));
  }
  while ( v9 != 16 );
  if ( v4 <= 1 )
    goto LABEL_4;
  v7 = (uint16_t)v4;
  v27 = 1;
  if ( (uint16_t)v4 != 5 )
    goto LABEL_4;
LABEL_10:
  result = sub_102B40(0);
  *(uint32_t *)off_102D18 = 1;
  if ( v27 )
  {
    if ( (a1 & 0x80) != 0 )
      v2 = 3;
    else
      v7 = 3;
    if ( (a1 & 0x80) == 0 )
      v2 = 0;
    if ( (*(uint32_t *)off_102D24 & 0x8000000) == 0 || (*(uint32_t *)off_102D28 & 0x400) != 0 )
      v16 = (unsigned uint64_t *)off_102D44;
    else
      v16 = (unsigned uint64_t *)off_102D2C;
    v29 = *v16;
    v25 = *((uint32_t *)v16 + 2);
    v26 = *(unsigned uint64_t *)((char *)v16 + 12);
    v30 = v25;
    v31 = v26;
  }
  else
  {
    result = 0;
    v30 = dword_102D34;
    v29 = __PAIR64__(dword_102D30, dword_102D38);
    v31 = (unsigned int)dword_102D3C;
    if ( (a1 & 0x80) != 0 )
      v7 = 4;
    else
      v7 = 2;
    if ( (a1 & 0x80) != 0 )
      v2 = 2;
    else
      v2 = 0;
  }
  if ( v2 < v7 )
  {
    v17 = (char *)&v29 + 4 * v2 + 4 * (uint16_t)(v7 - 1 - v2) + 4;
    v18 = dword_102D40;
    v19 = (char *)&v29 + 4 * v2;
    do
    {
      v21 = *(uint32_t *)v19;
      v19 += 4;
      v20 = v21;
      v22 = a2;
      v23 = v21;
      v24 = v21 + 320;
      do
      {
        if ( v20 )
        {
          result = *v22;
          *(uint32_t *)(v23 + 16) = *(uint32_t *)(v23 + 16) & v18 | (result << 11);
        }
        v23 += 20;
        ++v22;
      }
      while ( v24 != v23 );
    }
    while ( v19 != v17 );
  }
  return result;
}

