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

// alloc_buffer_by_flag @ 0x104828, size 466 bytes
// Doc: alloc_buffer_by_flag [scan]: Initialize channel set with 0x500/0xa00 based on mode flag
// alloc_buffer_by_flag [scan]: Initialize channel set with 0x500/0xa00 based on mode flag
int  alloc_buffer_by_flag(int a1, int a2, uint32_t *a3)
{
  int v3; // r3
  int v6; // r10
  int v7; // r6
  int v8; // r9
  float v9; // s14
  int v10; // r11
  int v11; // r10
  int v12; // r5
  int v13; // r4
  int v14; // r4
  int v15; // r3
  float v16; // s13
  int *v17; // r11
  int v18; // r5
  int v19; // r6
  int v20; // r4
  int v21; // r0
  int v22; // r3
  float v23; // s13
  float *v24; // r1
  int v25; // r0
  int v26; // r4
  float v27; // s15
  int result; // r0
  int v29; // [sp+4h] [bp-A8h]
  int v30; // [sp+4h] [bp-A8h]
  int v31; // [sp+8h] [bp-A4h]
  int v32; // [sp+Ch] [bp-A0h]
  int v33; // [sp+10h] [bp-9Ch]
  int v34; // [sp+14h] [bp-98h]
  int v35; // [sp+1Ch] [bp-90h]
  int v36; // [sp+24h] [bp-88h]
  float v37; // [sp+28h] [bp-84h] BYREF
  float v38; // [sp+2Ch] [bp-80h]

  if ( a1 )
    v3 = 2560;
  else
    v3 = 1280;
  if ( a1 )
    v6 = 528;
  else
    v6 = 256;
  v32 = v3;
  if ( a1 )
    v7 = 2624;
  else
    v7 = 1344;
  if ( a1 )
    v8 = 32;
  else
    v8 = 16;
  memset((int *)&v37, 0, 0x80u);
  v9 = flt_1049FC;
  v29 = v6;
  v10 = 10;
  v11 = 0;
  do
  {
    v12 = v10;
    v10 += v8;
    v13 = lookup_rate_entry(v10, a2, a3);
    v14 = v13 - lookup_rate_entry(v12, a2, a3);
    if ( (float)v14 < v9 )
    {
      v9 = (float)v14;
      v11 = v12;
    }
  }
  while ( v10 < v7 );
  v35 = v11;
  v15 = v11 - v29;
  if ( v11 - v29 <= 0 )
  {
    v35 = v11 + v32;
    v15 = v11 + v32 - v29;
    v36 = 1;
  }
  else
  {
    v36 = 0;
  }
  v33 = v15 - 1;
  v16 = flt_1049FC;
  v34 = v15;
  v17 = (int *)&v37;
  do
  {
    v31 = 9;
    *(float *)v17++ = v16;
    v30 = v34;
    do
    {
      v18 = v30;
      v19 = 5;
      do
      {
        v20 = lookup_rate_entry(v18, a2, a3);
        v21 = lookup_rate_entry(v33 - v34 + v18, a2, a3);
        --v19;
        v18 += v8;
        *((float *)v17 - 1) = *((float *)v17 - 1) + (float)(v20 - v21);
      }
      while ( v19 );
      v30 += v32;
      --v31;
    }
    while ( v31 );
    ++v34;
    ++v33;
  }
  while ( v17 != (int *)(&v37 + v8) );
  v22 = 0;
  v23 = flt_1049FC;
  v24 = &v37;
  v25 = 0;
LABEL_32:
  if ( (float)((float)(v37 + v38) * 0.5) > v23 )
  {
    v23 = (float)(v37 + v38) * 0.5;
    v25 = v22;
  }
  do
  {
    ++v22;
    ++v24;
    if ( !v22 )
      goto LABEL_32;
    if ( v8 - 1 == v22 )
    {
      v26 = v8;
      v27 = (float)(*v24 + *(v24 - 1)) * 0.5;
    }
    else
    {
      v26 = v22 + 1;
      v27 = (float)((float)(*(v24 - 1) + *v24) + v24[1]) / 3.0;
    }
    if ( v27 > v23 )
    {
      v23 = v27;
      v25 = v22;
    }
  }
  while ( v26 < v8 );
  result = v35 + v25 + 1;
  if ( v36 )
    result -= v32;
  return result;
}

