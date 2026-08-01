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

// uint64_divmod @ 0x143304, size 702 bytes
int  uint64_divmod(unsigned int a1, unsigned int a2, uint64_t a3, unsigned int *a4)
{
  unsigned int v5; // r4
  unsigned int v6; // lr
  unsigned int v7; // r7
  unsigned int v8; // r2
  unsigned int v9; // r8
  int v10; // r12
  unsigned int v11; // r3
  unsigned int v12; // r0
  int v13; // cf
  unsigned int v14; // r3
  int v15; // r0
  unsigned int v16; // r4
  unsigned int v17; // r1
  unsigned int v18; // r4
  int result; // r0
  unsigned int v20; // r3
  unsigned int v21; // lr
  int v22; // r8
  int v23; // r12
  unsigned int v24; // r5
  unsigned int v25; // r3
  unsigned int v26; // r5
  int v27; // r0
  unsigned int v28; // r4
  unsigned int v29; // r8
  unsigned int v30; // r1
  unsigned int v31; // r12
  unsigned int v32; // r0
  unsigned int v33; // r5
  unsigned int v34; // r3
  unsigned int v35; // r3
  unsigned int v36; // r5
  unsigned int v37; // r3
  unsigned int v38; // r7
  unsigned int v39; // lr
  unsigned int v40; // r5
  unsigned int v41; // r4
  int v42; // r9
  unsigned int v43; // r5
  unsigned int v44; // r10
  unsigned int v45; // r2
  unsigned int v46; // r3
  unsigned int v47; // r5
  int v48; // r0
  unsigned int v49; // r4
  unsigned int v50; // r8
  unsigned int v51; // r4
  unsigned uint64_t v52; // r8
  unsigned uint64_t v53; // kr08_8

  v5 = a1;
  v6 = a2;
  if ( HIDWORD(a3) )
  {
    if ( HIDWORD(a3) <= a2 )
    {
      v30 = __clz(HIDWORD(a3));
      if ( v30 )
      {
        v38 = ((unsigned int)a3 >> (32 - v30)) | (HIDWORD(a3) << v30);
        HIDWORD(a3) = a2 << v30;
        v39 = HIWORD(v38);
        v40 = a2 >> (32 - v30);
        v41 = (a1 >> (32 - v30)) | HIDWORD(a3);
        v42 = v40 / HIWORD(v38);
        v43 = HIWORD(v41) | ((v40 % HIWORD(v38)) << 16);
        v44 = v42 * (uint16_t)v38;
        v45 = (uint32_t)a3 << v30;
        v46 = a1 << v30;
        if ( v44 > v43 )
        {
          v13 = __CFADD__(v38, v43);
          v43 += v38;
          if ( v13 || v44 <= v43 )
          {
            --v42;
          }
          else
          {
            v42 -= 2;
            v43 += v38;
          }
        }
        v47 = v43 - v44;
        v48 = v47 / v39;
        v49 = (uint16_t)v41 | ((v47 % v39) << 16);
        v50 = v47 / v39 * (uint16_t)v38;
        if ( v50 > v49 )
        {
          v13 = __CFADD__(v38, v49);
          v49 += v38;
          if ( v13 || v50 <= v49 )
          {
            --v48;
          }
          else
          {
            v48 -= 2;
            v49 += v38;
          }
        }
        result = v48 | (v42 << 16);
        v51 = v49 - v50;
        v52 = (unsigned int)result * (unsigned uint64_t)v45;
        v53 = v52;
        if ( __PAIR64__(v51, v46) < v52 )
        {
          --result;
          v53 = v52 - __PAIR64__(v38, v45);
        }
        if ( a4 )
        {
          *a4 = ((__PAIR64__(v51, v46) - v53) >> 32 << (32 - (uint8_t)v30)) | ((v46 - (unsigned int)v53) >> v30);
          a4[1] = (unsigned int)((__PAIR64__(v51, v46) - v53) >> 32) >> v30;
        }
      }
      else
      {
        if ( HIDWORD(a3) >= a2 && (unsigned int)a3 > a1 )
        {
          result = 0;
        }
        else
        {
          HIDWORD(a3) = (__PAIR64__(a2, a1) - a3) >> 32;
          v5 = a1 - a3;
          result = 1;
          v6 = HIDWORD(a3);
        }
        if ( a4 )
        {
          *a4 = v5;
          a4[1] = v6;
        }
      }
    }
    else
    {
      if ( a4 )
      {
        *a4 = a1;
        a4[1] = a2;
      }
      return 0;
    }
  }
  else
  {
    v7 = a3;
    if ( (unsigned int)a3 <= a2 )
    {
      if ( !(uint32_t)a3 )
        __und(0xFFu);
      v8 = __clz(a3);
      if ( v8 )
      {
        v7 <<= v8;
        v21 = HIWORD(v7);
        v31 = a2 >> (32 - v8);
        v32 = (a1 >> (32 - v8)) | (a2 << v8);
        v22 = (uint16_t)v7;
        v33 = HIWORD(v32) | ((v31 % HIWORD(v7)) << 16);
        v34 = v31 / HIWORD(v7) * (uint16_t)v7;
        v5 <<= v8;
        if ( v34 > v33 )
        {
          v13 = __CFADD__(v7, v33);
          v33 += v7;
          if ( !v13 && v34 > v33 )
            v33 += v7;
        }
        v35 = v33 - v34;
        v36 = (uint16_t)v32 | ((v35 % v21) << 16);
        v37 = v35 / v21 * (uint16_t)v7;
        if ( v37 > v36 )
        {
          v13 = __CFADD__(v7, v36);
          v36 += v7;
          if ( !v13 && v37 > v36 )
            v36 += v7;
        }
        v20 = v36 - v37;
      }
      else
      {
        v20 = a2 - v7;
        v21 = HIWORD(v7);
        v22 = (uint16_t)v7;
      }
      v23 = v20 / v21;
      v24 = HIWORD(v5) | ((v20 % v21) << 16);
      v25 = v22 * (v20 / v21);
      if ( v25 > v24 )
      {
        v13 = __CFADD__(v7, v24);
        v24 += v7;
        if ( v13 || v25 <= v24 )
        {
          --v23;
        }
        else
        {
          v23 -= 2;
          v24 += v7;
        }
      }
      v26 = v24 - v25;
      v27 = v26 / v21;
      v28 = (uint16_t)v5 | ((v26 % v21) << 16);
      v29 = v22 * (v26 / v21);
      if ( v29 > v28 )
      {
        v13 = __CFADD__(v7, v28);
        v28 += v7;
        if ( v13 || v29 <= v28 )
        {
          --v27;
        }
        else
        {
          v27 -= 2;
          v28 += v7;
        }
      }
      v18 = v28 - v29;
      result = v27 | (v23 << 16);
    }
    else
    {
      v8 = __clz(a3);
      if ( v8 )
      {
        v7 <<= v8;
        v6 = (a1 >> (32 - v8)) | (a2 << v8);
        v5 = a1 << v8;
      }
      v9 = HIWORD(v7);
      v10 = v6 / HIWORD(v7);
      v11 = HIWORD(v5) | ((v6 % HIWORD(v7)) << 16);
      v12 = v10 * (uint16_t)v7;
      if ( v12 > v11 )
      {
        v13 = __CFADD__(v7, v11);
        v11 += v7;
        if ( v13 || v12 <= v11 )
        {
          --v10;
        }
        else
        {
          v10 -= 2;
          v11 += v7;
        }
      }
      v14 = v11 - v12;
      v15 = v14 / v9;
      v16 = (uint16_t)v5 | ((v14 % v9) << 16);
      v17 = v14 / v9 * (uint16_t)v7;
      if ( v17 > v16 )
      {
        v13 = __CFADD__(v7, v16);
        v16 += v7;
        if ( v13 || v17 <= v16 )
        {
          --v15;
        }
        else
        {
          v15 -= 2;
          v16 += v7;
        }
      }
      v18 = v16 - v17;
      result = v15 | (v10 << 16);
    }
    if ( a4 )
    {
      *a4 = v18 >> v8;
      a4[1] = 0;
    }
  }
  return result;
}

