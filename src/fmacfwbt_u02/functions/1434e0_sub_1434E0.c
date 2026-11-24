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

// sub_1434E0 @ 0x1434e0, size 702 bytes
uint64_t  sub_1434E0(uint64_t a1, uint64_t a2, uint64_t *a4)
{
  uint64_t v3; // r4
  unsigned int v4; // lr
  unsigned int v5; // r7
  unsigned int v6; // r2
  unsigned int v7; // r8
  int v8; // r12
  unsigned int v9; // r3
  unsigned int v10; // r0
  int v11; // cf
  unsigned int v12; // r3
  int v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r4
  unsigned int v17; // r3
  unsigned int v18; // lr
  int v19; // r8
  int v20; // r12
  unsigned int v21; // r3
  int v22; // r0
  unsigned int v23; // r8
  unsigned int v24; // r3
  uint64_t v25; // kr00_8
  unsigned int v26; // r12
  unsigned int v27; // r3
  unsigned int v28; // r3
  int v29; // r5
  unsigned int v30; // r5
  unsigned int v31; // r3
  unsigned int v32; // r7
  unsigned int v33; // lr
  unsigned int v34; // r5
  unsigned int v35; // r4
  int v36; // r9
  unsigned int v37; // r5
  unsigned int v38; // r10
  unsigned int v39; // r2
  unsigned int v40; // r3
  unsigned int v41; // r5
  int v42; // r0
  unsigned int v43; // r4
  unsigned int v44; // r8
  unsigned int v45; // r4
  uint64_t v46; // r8
  uint64_t v47; // kr08_8

  v3 = a1;
  v4 = HIDWORD(a1);
  if ( HIDWORD(a2) )
  {
    if ( HIDWORD(a2) <= HIDWORD(a1) )
    {
      HIDWORD(a1) = __clz(HIDWORD(a2));
      if ( HIDWORD(a1) )
      {
        v32 = ((unsigned int)a2 >> (32 - BYTE4(a1))) | (HIDWORD(a2) << SBYTE4(a1));
        HIDWORD(a2) = HIDWORD(v3) << SBYTE4(a1);
        v33 = HIWORD(v32);
        v34 = HIDWORD(v3) >> (32 - BYTE4(a1));
        v35 = ((unsigned int)a1 >> (32 - BYTE4(a1))) | HIDWORD(a2);
        v36 = v34 / HIWORD(v32);
        v37 = HIWORD(v35) | ((v34 % HIWORD(v32)) << 16);
        v38 = v36 * (uint16_t)v32;
        v39 = (uint32_t)a2 << SBYTE4(a1);
        v40 = (uint32_t)a1 << SBYTE4(a1);
        if ( v38 > v37 )
        {
          v11 = __CFADD__(v32, v37);
          v37 += v32;
          if ( v11 || v38 <= v37 )
          {
            --v36;
          }
          else
          {
            v36 -= 2;
            v37 += v32;
          }
        }
        v41 = v37 - v38;
        v42 = v41 / v33;
        v43 = (uint16_t)v35 | ((v41 % v33) << 16);
        v44 = v41 / v33 * (uint16_t)v32;
        if ( v44 > v43 )
        {
          v11 = __CFADD__(v32, v43);
          v43 += v32;
          if ( v11 || v44 <= v43 )
          {
            --v42;
          }
          else
          {
            v42 -= 2;
            v43 += v32;
          }
        }
        LODWORD(a1) = v42 | (v36 << 16);
        v45 = v43 - v44;
        v46 = (unsigned int)a1 * (uint64_t)v39;
        v47 = v46;
        if ( __PAIR64__(v45, v40) < v46 )
        {
          LODWORD(a1) = a1 - 1;
          v47 = v46 - __PAIR64__(v32, v39);
        }
        if ( a4 )
        {
          *(uint32_t *)a4 = ((__PAIR64__(v45, v40) - v47) >> 32 << (32 - BYTE4(a1)))
                        | ((v40 - (unsigned int)v47) >> SBYTE4(a1));
          *((uint32_t *)a4 + 1) = (unsigned int)((__PAIR64__(v45, v40) - v47) >> 32) >> SBYTE4(a1);
        }
        HIDWORD(a1) = 0;
      }
      else
      {
        if ( HIDWORD(a2) >= HIDWORD(v3) && (unsigned int)a2 > (unsigned int)a1 )
        {
          LODWORD(a1) = 0;
        }
        else
        {
          v25 = __PAIR64__(HIDWORD(v3), a1) - a2;
          v24 = (__PAIR64__(HIDWORD(v3), a1) - a2) >> 32;
          LODWORD(v3) = v25;
          LODWORD(a1) = 1;
          v4 = v24;
        }
        if ( a4 )
        {
          *(uint32_t *)a4 = v3;
          *((uint32_t *)a4 + 1) = v4;
        }
      }
    }
    else
    {
      HIDWORD(a1) = 0;
      if ( a4 )
      {
        *(uint32_t *)a4 = a1;
        *((uint32_t *)a4 + 1) = HIDWORD(v3);
      }
      LODWORD(a1) = 0;
    }
  }
  else
  {
    v5 = a2;
    if ( (unsigned int)a2 <= HIDWORD(a1) )
    {
      if ( !(uint32_t)a2 )
        __und(0xFFu);
      v6 = __clz(a2);
      if ( v6 )
      {
        v5 <<= v6;
        v18 = HIWORD(v5);
        v26 = HIDWORD(a1) >> (32 - v6);
        LODWORD(a1) = ((unsigned int)a1 >> (32 - v6)) | (HIDWORD(a1) << v6);
        HIDWORD(a1) = v26 / HIWORD(v5);
        v19 = (uint16_t)v5;
        HIDWORD(v3) = WORD1(a1) | ((v26 % HIWORD(v5)) << 16);
        v27 = HIDWORD(a1) * (uint16_t)v5;
        LODWORD(v3) = (uint32_t)v3 << v6;
        if ( v27 > HIDWORD(v3) )
        {
          v11 = __CFADD__(v5, HIDWORD(v3));
          HIDWORD(v3) += v5;
          if ( v11 || v27 <= HIDWORD(v3) )
          {
            --HIDWORD(a1);
          }
          else
          {
            HIDWORD(a1) -= 2;
            HIDWORD(v3) += v5;
          }
        }
        v28 = HIDWORD(v3) - v27;
        v29 = (uint16_t)a1;
        LODWORD(a1) = v28 / v18;
        v30 = v29 | ((v28 % v18) << 16);
        v31 = v28 / v18 * (uint16_t)v5;
        if ( v31 > v30 )
        {
          v11 = __CFADD__(v5, v30);
          v30 += v5;
          if ( v11 || v31 <= v30 )
          {
            LODWORD(a1) = a1 - 1;
          }
          else
          {
            LODWORD(a1) = a1 - 2;
            v30 += v5;
          }
        }
        v17 = v30 - v31;
        HIDWORD(a1) = a1 | (HIDWORD(a1) << 16);
      }
      else
      {
        v17 = HIDWORD(a1) - v5;
        v18 = HIWORD(v5);
        v19 = (uint16_t)v5;
        HIDWORD(a1) = 1;
      }
      v20 = v17 / v18;
      HIDWORD(v3) = WORD1(v3) | ((v17 % v18) << 16);
      v21 = v19 * (v17 / v18);
      if ( v21 > HIDWORD(v3) )
      {
        v11 = __CFADD__(v5, HIDWORD(v3));
        HIDWORD(v3) += v5;
        if ( v11 || v21 <= HIDWORD(v3) )
        {
          --v20;
        }
        else
        {
          v20 -= 2;
          HIDWORD(v3) += v5;
        }
      }
      HIDWORD(v3) -= v21;
      v22 = HIDWORD(v3) / v18;
      LODWORD(v3) = (uint16_t)v3 | ((HIDWORD(v3) % v18) << 16);
      v23 = v19 * (HIDWORD(v3) / v18);
      if ( v23 > (unsigned int)v3 )
      {
        v11 = __CFADD__(v5, (uint32_t)v3);
        LODWORD(v3) = v5 + v3;
        if ( v11 || v23 <= (unsigned int)v3 )
        {
          --v22;
        }
        else
        {
          v22 -= 2;
          LODWORD(v3) = v3 + v5;
        }
      }
      v16 = v3 - v23;
      LODWORD(a1) = v22 | (v20 << 16);
    }
    else
    {
      v6 = __clz(a2);
      if ( v6 )
      {
        v5 <<= v6;
        v4 = ((unsigned int)a1 >> (32 - v6)) | (HIDWORD(a1) << v6);
        LODWORD(v3) = (uint32_t)a1 << v6;
      }
      v7 = HIWORD(v5);
      v8 = v4 / HIWORD(v5);
      v9 = WORD1(v3) | ((v4 % HIWORD(v5)) << 16);
      v10 = v8 * (uint16_t)v5;
      if ( v10 > v9 )
      {
        v11 = __CFADD__(v5, v9);
        v9 += v5;
        if ( v11 || v10 <= v9 )
        {
          --v8;
        }
        else
        {
          v8 -= 2;
          v9 += v5;
        }
      }
      v12 = v9 - v10;
      v13 = v12 / v7;
      v14 = (uint16_t)v3 | ((v12 % v7) << 16);
      v15 = v12 / v7 * (uint16_t)v5;
      if ( v15 > v14 )
      {
        v11 = __CFADD__(v5, v14);
        v14 += v5;
        if ( v11 || v15 <= v14 )
        {
          --v13;
        }
        else
        {
          v13 -= 2;
          v14 += v5;
        }
      }
      v16 = v14 - v15;
      a1 = (unsigned int)v13 | (uint64_t)(unsigned int)(v8 << 16);
    }
    if ( a4 )
      *a4 = v16 >> v6;
  }
  return a1;
}
