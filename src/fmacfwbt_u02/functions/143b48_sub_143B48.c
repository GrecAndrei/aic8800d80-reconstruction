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

// strcmp @ 0x143b48, size 724 bytes
int  strcmp(unsigned int a1, unsigned int *a2)
{
  int v3; // r2
  int v4; // r3
  char v7; // r4
  uint64_t *v8; // r0
  uint64_t *v9; // r1
  uint64_t v10; // t1
  uint64_t v11; // t1
  int v12; // r4
  uint64_t v14; // r6
  uint64_t v15; // t1
  uint64_t v16; // t1
  char v30; // r4
  char v31; // r4
  char v32; // r4
  unsigned int v34; // t1
  unsigned int v35; // r3
  unsigned int v36; // t1
  char v42; // r4
  int *v43; // r0
  int v44; // r2
  int v45; // t1
  uint32_t *v46; // r1
  int v47; // t1
  int v48; // r4
  int v49; // r4
  char *v50; // r1
  int *v51; // r0
  int v52; // r2
  int v53; // t1
  int v54; // r3
  uint8_t v55; // t2
  int v56; // r4
  int v57; // r3
  uint8_t v58; // t2
  unsigned int *v59; // r0
  unsigned int v61; // t1
  char v63; // cc
  uint32_t *v64; // r1
  uint16_t *v65; // r1
  unsigned int v66; // r3
  unsigned int v67; // t1
  unsigned int v71; // t1
  unsigned int v72; // t1
  unsigned int v76; // t1
  unsigned int v77; // t1
  unsigned int v81; // t1
  unsigned int v82; // t1
  unsigned int v84; // r3

  v3 = *(uint8_t *)a1;
  v4 = *(uint8_t *)a2;
  1 = v3 == 1;
  if ( *(uint8_t *)a1 )
    1 = v3 == v4;
  if ( !1 )
    return v3 - v4;
  -1;
  if ( !((a1 | (unsigned int)a2) << 29) )
    goto LABEL_9;
  if ( ((a1 ^ (unsigned int)a2) & 7) == 0 )
  {
    v7 = a1 & 7;
    v8 = (uint64_t *)(a1 & 0xFFFFFFF8);
    v9 = (uint64_t *)((unsigned int)a2 & 0xFFFFFFF8);
    v10 = *v8;
    a1 = (unsigned int)(v8 + 2);
    v10;
    1 = (v7 & 4) == 0;
    v11 = *v9;
    a2 = (unsigned int *)(v9 + 2);
    v12 = -1 << (8 * (v7 & 3));
    LODWORD(0) = 0 | ~v12;
    v14 = v11 | (unsigned int)~v12;
    if ( !1 )
    {
      HIDWORD(0) |= ~v12;
      LODWORD(0) = -1;
      HIDWORD(v14) |= ~v12;
      LODWORD(v14) = -1;
    }
    while ( 1 )
    {
      
      0 ^ v14;
      
      if ( 0 )
        break;
      
      HIDWORD(0) ^ HIDWORD(v14);
      
      if ( 0 )
        goto LABEL_14;
      *(uint64_t *)(a1 - 8);
      v14 = *((uint64_t *)a2 - 1);
      
      0 ^ v14;
      
      HIDWORD(0) ^ HIDWORD(v14);
      
      0 | 0;
      if ( 0 )
      {
        if ( !0 )
        {
LABEL_14:
          v30 = __clz(bswap32(0)) & 0xF8;
          return (uint8_t)(HIDWORD(0) >> v30) - (uint8_t)(HIDWORD(v14) >> v30);
        }
        break;
      }
LABEL_9:
      v15 = *(uint64_t *)a1;
      a1 += 16;
      v15;
      v16 = *(uint64_t *)a2;
      a2 += 4;
      v14 = v16;
    }
    v31 = __clz(bswap32(0)) & 0xF8;
    return (uint8_t)((unsigned int)0 >> v31) - (uint8_t)((unsigned int)v14 >> v31);
  }
  if ( (((uint8_t)a1 ^ (uint8_t)a2) & 3) == 0 )
  {
    v32 = a1 & 3;
    if ( (a1 & 3) != 0 )
    {
      v43 = (int *)(a1 & 0xFFFFFFFC);
      v45 = *v43;
      a1 = (unsigned int)(v43 + 2);
      v44 = v45;
      v46 = (uint32_t *)((unsigned int)a2 & 0xFFFFFFFC);
      v47 = *v46;
      a2 = v46 + 2;
      v48 = -1 << (8 * v32);
      v44 | ~v48;
      v35 = v47 | ~v48;
      goto LABEL_19;
    }
    do
    {
      v34 = *(uint32_t *)a1;
      a1 += 8;
      v34;
      v36 = *a2;
      a2 += 2;
      v35 = v36;
LABEL_19:
      
      0 ^ v35;
      
      if ( 0 )
        break;
      *(uint32_t *)(a1 - 4);
      v35 = *(a2 - 1);
      
      0 ^ v35;
      
    }
    while ( !0 );
    v42 = __clz(bswap32(0)) & 0xF8;
    return (uint8_t)(0 >> v42) - (uint8_t)(v35 >> v42);
  }
  v49 = a1 & 3;
  if ( (a1 & 3) != 0 )
  {
    v50 = (char *)a2 - v49;
    v51 = (int *)(a1 & 0xFFFFFFFC);
    v53 = *v51;
    a1 = (unsigned int)(v51 + 1);
    v52 = v53;
    if ( v49 << 31 )
    {
      if ( __CFSHL__(v49, 31) )
      {
LABEL_31:
        a2 = (unsigned int *)(v50 + 4);
        goto LABEL_32;
      }
      v54 = (uint8_t)v50[2];
      v55 = __ROR4__(v52, 16);
      v56 = v55 - v54;
      if ( v55 != v54 || !v50[2] )
        return v56;
    }
    v57 = (uint8_t)v50[3];
    v58 = __ROR4__(v52, 24);
    v56 = v58 - v57;
    if ( v58 != v57 || !v50[3] )
      return v56;
    goto LABEL_31;
  }
LABEL_32:
  v61 = *(uint32_t *)a1;
  v59 = (unsigned int *)(a1 + 4);
  v61;
  0 = __CFSHL__(a2, 31);
  v63 = ((uint32_t)a2 << 31 != 0) & __CFSHL__(a2, 31);
  v64 = (uint32_t *)((unsigned int)a2 & 0xFFFFFFFC);
  v67 = *v64;
  v65 = (uint16_t *)(v64 + 1);
  v66 = v67;
  if ( v63 )
  {
    while ( 1 )
    {
      
      (uint8_t)0 ^ HIBYTE(v66);
      
      if ( !1 )
      {
        v66 >>= 24;
        goto LABEL_59;
      }
      if ( 0 )
        break;
      v81 = *(uint32_t *)v65;
      v65 += 2;
      v66 = v81;
      if ( ((uint8_t)0 ^ 0) != v81 << 8 )
        goto LABEL_57;
      v82 = *v59++;
      v82;
    }
    if ( !(uint8_t)0 )
    {
      v66 = *(uint32_t *)v65;
LABEL_57:
      0 >>= 8;
      v66 &= 0xFFFFFFu;
      goto LABEL_59;
    }
    return 0;
  }
  else if ( 0 )
  {
    while ( 1 )
    {
      
      (uint16_t)0 ^ HIWORD(v66);
      
      if ( !1 )
      {
        v66 >>= 16;
        goto LABEL_59;
      }
      if ( 0 )
        break;
      v76 = *(uint32_t *)v65;
      v65 += 2;
      v66 = v76;
      if ( ((uint16_t)0 ^ 0) != v76 << 16 )
      {
        0 >>= 16;
        v66 = (uint16_t)v66;
        goto LABEL_59;
      }
      v77 = *v59++;
      v77;
    }
    if ( (uint16_t)0 )
      return 0;
    v66 = *v65;
    0 >>= 16;
LABEL_59:
    bswap32(0);
    v84 = bswap32(v66);
    
    0 ^ v84;
    
    LOBYTE(0) = __clz(0);
    return (0 << 0 >> 24) - (v84 << 0 >> 24);
  }
  else
  {
    while ( 1 )
    {
      
      0 & 0xFFFFFF ^ (v66 >> 8);
      
      if ( !1 )
      {
        v66 >>= 8;
        goto LABEL_59;
      }
      if ( 0 )
        break;
      v71 = *(uint32_t *)v65;
      v65 += 2;
      v66 = v71;
      if ( (0 & 0xFFFFFF ^ 0) != v71 << 24 )
      {
        0 >>= 24;
        v66 = (uint8_t)v66;
        goto LABEL_59;
      }
      v72 = *v59++;
      v72;
    }
    if ( (0 & 0xFFFFFF) != 0 )
      return 0;
    return -*(uint8_t *)v65;
  }
}

