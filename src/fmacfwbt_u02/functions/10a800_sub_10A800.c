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


extern uint32_t dword_10AB30;
extern uint32_t off_10AB00;
extern uint32_t off_10AB04;
extern uint32_t off_10AB08;
extern uint32_t off_10AB0C;
extern uint32_t off_10AB14;
extern uint32_t off_10AB18;
extern uint32_t off_10AB1C;
extern uint32_t off_10AB20;
extern uint32_t off_10AB24;
extern uint32_t off_10AB28;
extern uint32_t off_10AB2C;
extern uint32_t off_10AB34;
extern uint32_t off_10AB38;
extern uint32_t off_10AE54;
extern uint32_t off_10AE58;
extern uint32_t off_10AE5C;
extern uint32_t off_10AE60;

// chip_common_init @ 0x10a800, size 1610 bytes
int  chip_common_init(unsigned int a1, unsigned int a2, int a3, unsigned int a4, uint8_t a5, char a6)
{
  unsigned int v8; // s17
  int v9; // r3
  uint32_t *v10; // r2
  uint32_t *v11; // r5
  uint32_t *v12; // r7
  unsigned int *v13; // r3
  unsigned int *v14; // r1
  uint32_t *v15; // r6
  unsigned int *v16; // r11
  unsigned int *v17; // r0
  int v18; // s16
  unsigned int *v19; // r10
  unsigned int v20; // r8
  int v21; // r6
  int v22; // r5
  int v23; // r4
  int v24; // zf
  unsigned int v25; // r4
  int v26; // r1
  int v27; // r6
  unsigned int v28; // r7
  uint16_t v29; // r4
  uint16_t v30; // r0
  unsigned int v31; // r2
  uint8_t v32; // r1
  unsigned int i; // r3
  unsigned int v34; // r4
  unsigned int v35; // r9
  uint32_t *v36; // r1
  unsigned int *v37; // r3
  unsigned int *v38; // r1
  uint16_t v39; // r3
  uint32_t *v40; // r3
  unsigned int *v42; // r3
  int v43; // [sp+24h] [bp-7C0h]
  int v44; // [sp+28h] [bp-7BCh]
  int v45; // [sp+34h] [bp-7B0h]
  int v46; // [sp+38h] [bp-7ACh]
  unsigned int a1a; // [sp+44h] [bp-7A0h]
  int v49; // [sp+48h] [bp-79Ch]
  char a3a; // [sp+5Ah] [bp-78Ah] BYREF
  char v53; // [sp+5Bh] [bp-789h] BYREF
  char v54[4]; // [sp+5Ch] [bp-788h] BYREF
  int result; // [sp+60h] [bp-784h] BYREF
  unsigned int a2a; // [sp+64h] [bp-780h] BYREF
  uint16_t v57[6]; // [sp+68h] [bp-77Ch] BYREF
  uint16_t v58[952]; // [sp+74h] [bp-770h] BYREF

  state_check_feature(
    0x2000,
    "page %x,sdm %x,freq %x,lock %x,rfen %x\n",
    (*(uint32_t *)off_10AB34 >> 3) & 7,
    *(uint32_t *)off_10AB00,
    *(uint32_t *)off_10AB04,
    *(uint32_t *)off_10AB08,
    *(uint32_t *)off_10AB0C);
  v8 = ((a1 >> 1) & 1) + 3;
  if ( (a1 & 0xC) != 0 )
  {
    if ( ((a1 >> 2) & 3) == 1 )
      v9 = 5;
    else
      v9 = 10;
    a1a = v9;
  }
  else
  {
    a1a = 1;
  }
  v10 = off_10AB14;
  v11 = off_10AB18;
  v12 = off_10AB1C;
  v13 = (unsigned int *)off_10AB20;
  v14 = (unsigned int *)off_10AB24;
  v15 = off_10AB28;
  v16 = (unsigned int *)off_10AB38;
  *(uint32_t *)off_10AB14 &= ~4u;
  *v11 &= 0xFFFF0FFF;
  *v12 = 0;
  *v13 |= 0x80u;
  *v14 |= 0x80000000;
  *v10 |= 4u;
  *v15 = HIWORD(*v15) << 16;
  *(v12 - 6154) = *(v12 - 6154) & 0xCFFFFFFF | 0x10000000;
  v17 = (unsigned int *)off_10AB2C;
  *v10 &= ~4u;
  *v14 &= ~0x80000000;
  *v13 &= ~0x80u;
  *v10 |= 4u;
  v15[6223] |= 2u;
  *v13 = *v13 & 0xFFFF8FFF | 0x4000;
  *v13 = *v13 & 0xF8FFFFFF | 0x6000000;
  *v13 = *v13 & 0xFFFFF8FF | 0x100;
  *v13 &= ~4u;
  *v13 |= 1u;
  *v13 |= 8u;
  *v14 = a3 | *v14 & 0x80000000;
  *v17 |= 0x2000000u;
  *v17 |= 0x10000u;
  v43 = 0;
  v49 = ((v10[2069] >> 3) & 7) << 6;
  v18 = 0;
  v19 = v17;
  v46 = -1;
  do
  {
    v45 = 0;
    do
    {
      if ( a4 <= a5 )
      {
        v20 = a4;
        do
        {
          *v16 = dword_10AB30 & (((uint16_t)v49 | (4 * v20) | 1) << 8) | *v16 & 0xFFFE00FF;
          *v16 |= 0x20000u;
          *v16 |= 0x40000u;
          timer_set(1);
          if ( v43 )
          {
            if ( v45 )
            {
              v21 = (uint16_t)v20;
            }
            else
            {
              mac_cmd_dispatch(v18, v20, &a3a, (char *)&v58[6] + 3 * v20, (int *)&v58[8 * v20 + 54]);
              v21 = (uint16_t)v20;
              mac_cmd_dispatch(v18, v20, &v53, (char *)&v58[30] + 3 * v20, (int *)&v58[8 * v20 + 182]);
            }
            v22 = *((uint8_t *)&v58[6] + 3 * v20 + v46);
            v23 = *((uint8_t *)&v58[30] + 3 * v20 + v46);
            *v19 = *v19 & 0xFE01FFFF | (v22 << 17);
            *v19 = *v19 & 0xFFFF00FF | (v22 << 8);
            udelay_50(&result, &a2a);
            if ( v22 != v23 )
            {
              *v19 = *v19 & 0xFE01FFFF | (v23 << 17);
              *v19 = *v19 & 0xFFFF00FF | (v23 << 8);
              udelay_50(v54, &a2a);
            }
          }
          else
          {
            *v19 = *v19 & 0xFE01FFFF | 0x1000000;
            *v19 = *v19 & 0xFFFF00FF | 0x8000;
            udelay_50(&result, &a2a);
            v21 = (uint16_t)v20;
          }
          u64_set_or_add((uint8_t)v45, result, &v58[20 * v21 + 310]);
          u64_set_or_add((uint8_t)v45, a2a, &v58[20 * v20 + 630]);
          v20 = (uint8_t)(v20 + 1);
        }
        while ( a5 >= v20 );
      }
      v24 = a1a == ++v45;
    }
    while ( !v24 );
    if ( a4 <= a5 )
    {
      v25 = a4;
      do
      {
        while ( 1 )
        {
          v27 = v43 + 4 * v25;
          if ( a1a != 1 )
            break;
          *(uint32_t *)&v58[2 * v27 + 54] = *(uint32_t *)&v58[20 * v25 + 310];
          *(uint32_t *)&v58[2 * v27 + 182] = *(uint32_t *)&v58[20 * v25 + 630];
          v25 = (uint8_t)(v25 + 1);
          if ( a5 < v25 )
            goto LABEL_28;
        }
        if ( v25 >= 6 )
          v26 = 100;
        else
          v26 = 50;
        v44 = v26;
        *(uint32_t *)&v58[2 * v27 + 54] = strlen(a1a, v26, (int *)&v58[20 * v25 + 310]);
        *(uint32_t *)&v58[2 * v27 + 182] = strlen(a1a, v44, (int *)&v58[20 * v25 + 630]);
        v25 = (uint8_t)(v25 + 1);
      }
      while ( a5 >= v25 );
    }
LABEL_28:
    ++v46;
    v18 = (uint8_t)++v43;
  }
  while ( v8 > (uint8_t)v43 );
  if ( a4 > a5 )
  {
    memmove_1((a1 >> 5) & 1, v57);
    memmove_1((a1 >> 5) & 1, v58);
  }
  else
  {
    v28 = a4;
    do
    {
      v29 = tx_packet_dispatch(v8, v28, (uint8_t *)&v58[6] + 3 * v28, (int *)&v58[8 * v28 + 54]);
      v30 = tx_packet_dispatch(v8, v28, (uint8_t *)&v58[30] + 3 * v28, (int *)&v58[8 * v28 + 182]);
      v31 = v28 - 10;
      if ( v28 > 9 )
        v57[v31] = v29;
      else
        v31 = a2;
      if ( v28 <= 9 )
        *(uint16_t *)(v31 + 2 * (uint16_t)v28) = (uint8_t)v29 | (uint16_t)(v30 << 8);
      v32 = v28 + 1;
      if ( v28 > 9 )
        v58[v31] = v30;
      v28 = v32;
    }
    while ( a5 >= (unsigned int)v32 );
    memmove_1((a1 >> 5) & 1, v57);
    memmove_1((a1 >> 5) & 1, v58);
    for ( i = a4; ; i = (uint8_t)(i + 1) )
    {
      if ( i > 9 )
        *(uint16_t *)(a2 + 2 * (uint16_t)i) = LOBYTE(v57[i - 10]) | (uint16_t)(v58[i - 10] << 8);
      if ( a5 == i )
        break;
    }
    v34 = a4;
    do
    {
      v35 = *(uint16_t *)(a2 + 2 * v34);
      state_check_feature(
        0x2000,
        "fit-in-I %x %x: [%d,%d;%d,%d;%d,%d;%d,%d]\r\n",
        v34,
        (uint8_t)v35,
        128,
        *(uint32_t *)&v58[8 * v34 + 54],
        *((uint8_t *)&v58[6] + 3 * v34),
        *(uint32_t *)&v58[8 * v34 + 56],
        *((uint8_t *)&v58[6] + 3 * v34 + 1),
        *(uint32_t *)&v58[8 * v34 + 58],
        *((uint8_t *)&v58[7] + 3 * v34),
        *(uint32_t *)&v58[8 * v34 + 60]);
      state_check_feature(
        0x2000,
        "fit-in-Q %x %x: [%d,%d;%d,%d;%d,%d;%d,%d]\r\n",
        v34,
        v35 >> 8,
        128,
        *(uint32_t *)&v58[8 * v34 + 182],
        *((uint8_t *)&v58[30] + 3 * v34),
        *(uint32_t *)&v58[8 * v34 + 184],
        *((uint8_t *)&v58[30] + 3 * v34 + 1),
        *(uint32_t *)&v58[8 * v34 + 186],
        *((uint8_t *)&v58[31] + 3 * v34),
        *(uint32_t *)&v58[8 * v34 + 188]);
      v24 = a5 == v34;
      v34 = (uint8_t)(v34 + 1);
    }
    while ( !v24 );
  }
  v36 = off_10AE54;
  v37 = (unsigned int *)off_10AE58;
  *(uint32_t *)off_10AE54 &= ~2u;
  *v37 |= 4u;
  *v37 = *v37 & 0xFFFF8FFF | 0x3000;
  *v37 = *v37 & 0xFFFFF8FF | 0x600;
  *v37 &= ~8u;
  *v37 &= ~1u;
  *(v36 - 6224) &= 0xCFFFFFFF;
  if ( a6 )
  {
    v38 = (unsigned int *)off_10AE5C;
    v39 = *(uint16_t *)(a2 + 2 * a4);
    *(uint32_t *)off_10AE5C = *(uint32_t *)off_10AE5C & 0xFE01FFFF | ((uint8_t)v39 << 17);
    *v38 = v39 & 0xFF00 | *v38 & 0xFFFF00FF;
  }
  else
  {
    v42 = (unsigned int *)off_10AE5C;
    *(uint32_t *)off_10AE5C &= ~0x2000000u;
    *v42 &= ~0x10000u;
    *v42 = *v42 & 0xFE01FFFF | 0x1000000;
    *v42 = *v42 & 0xFFFF00FF | 0x8000;
  }
  v40 = off_10AE60;
  *(uint32_t *)off_10AE60 &= 0xFFFE00FF;
  *v40 &= ~0x20000u;
  *v40 |= 0x40000u;
  return state_check_feature(0x2000, aWfDccalibEnd);
}
