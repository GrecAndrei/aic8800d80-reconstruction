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

// strcmp @ 0x143aa8, size 724 bytes
int  strcmp(unsigned int a1, unsigned int *a2)
{
uint32_t _R12;
uint64_t _R2;
uint64_t _R3;
uint32_t _R4;
uint32_t _R5;

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
  _ZF = v3 == 1;
  if ( *(uint8_t *)a1 )
    _ZF = v3 == v4;
  if ( !_ZF )
    return v3 - v4;
  _R12 = -1;
  if ( !((a1 | (unsigned int)a2) << 29) )
    goto LABEL_9;
  if ( ((a1 ^ (unsigned int)a2) & 7) == 0 )
  {
    v7 = a1 & 7;
    v8 = (uint64_t *)(a1 & 0xFFFFFFF8);
    v9 = (uint64_t *)((unsigned int)a2 & 0xFFFFFFF8);
    v10 = *v8;
    a1 = (unsigned int)(v8 + 2);
    _R2 = v10;
    _ZF = (v7 & 4) == 0;
    v11 = *v9;
    a2 = (unsigned int *)(v9 + 2);
    v12 = -1 << (8 * (v7 & 3));
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(_R2 | ~v12) & 0xFFFFFFFFULL) << 0);
    v14 = v11 | (unsigned int)~v12;
    if ( !_ZF )
    {
      _R2 = _R2 | (((uint64_t)(~v12)) << 32);
      _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(-1) & 0xFFFFFFFFULL) << 0);
      v14 = v14 | (((uint64_t)(~v12)) << 32);
      v14 = (v14 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(-1) & 0xFFFFFFFFULL) << 0);
    }
    while ( 1 )
    {
      (void)0;

      _R4 = _R2 ^ v14;
      _R4 = (uint32_t)_R4 | __zmask32((uint32_t)_R2);

      if ( _R4 )
        break;
      (void)0;

      _R5 = HIDWORD(_R2) ^ HIDWORD(v14);
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)(_R2 >> 32));

      if ( _R5 )
        goto LABEL_14;
      _R2 = *(uint64_t *)(a1 - 8);
      v14 = *((uint64_t *)a2 - 1);
      (void)0;

      _R4 = _R2 ^ v14;
      _R4 = (uint32_t)_R4 | __zmask32((uint32_t)_R2);

      _R5 = HIDWORD(_R2) ^ HIDWORD(v14);
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)(_R2 >> 32));

      _R5 = _R5 | _R4;
      if ( _R5 )
      {
        if ( !_R4 )
        {
LABEL_14:
          v30 = __clz(bswap32(_R5)) & 0xF8;
          return (uint8_t)(HIDWORD(_R2) >> v30) - (uint8_t)(HIDWORD(v14) >> v30);
        }
        break;
      }
LABEL_9:
      v15 = *(uint64_t *)a1;
      a1 += 16;
      _R2 = v15;
      v16 = *(uint64_t *)a2;
      a2 += 4;
      v14 = v16;
    }
    v31 = __clz(bswap32(_R4)) & 0xF8;
    return (uint8_t)((unsigned int)_R2 >> v31) - (uint8_t)((unsigned int)v14 >> v31);
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
      _R2 = v44 | ~v48;
      v35 = v47 | ~v48;
      goto LABEL_19;
    }
    do
    {
      v34 = *(uint32_t *)a1;
      a1 += 8;
      _R2 = v34;
      v36 = *a2;
      a2 += 2;
      v35 = v36;
LABEL_19:
      (void)0;

      _R5 = _R2 ^ v35;
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)_R2);

      if ( _R5 )
        break;
      _R2 = *(uint32_t *)(a1 - 4);
      v35 = *(a2 - 1);
      (void)0;

      _R5 = _R2 ^ v35;
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)_R2);

    }
    while ( !_R5 );
    v42 = __clz(bswap32(_R5)) & 0xF8;
    return (uint8_t)(_R2 >> v42) - (uint8_t)(v35 >> v42);
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
  _R2 = v61;
  _CF = __CFSHL__(a2, 31);
  v63 = ((uint32_t)a2 << 31 != 0) & __CFSHL__(a2, 31);
  v64 = (uint32_t *)((unsigned int)a2 & 0xFFFFFFFC);
  v67 = *v64;
  v65 = (uint16_t *)(v64 + 1);
  v66 = v67;
  if ( v63 )
  {
    while ( 1 )
    {
      (void)0;

      _R5 = (uint8_t)_R2 ^ (uint8_t)(v66 >> 24);
      if ( (uint32_t)_R5 )
      {
        v66 >>= 24;
        goto LABEL_59;
      }
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)_R2);
      if ( _R5 )
        break;
      v81 = *(uint32_t *)v65;
      v65 += 2;
      v66 = v81;
      if ( ((uint8_t)_R2 ^ _R2) != v81 << 8 )
        goto LABEL_57;
      v82 = *v59++;
      _R2 = v82;
    }
    if ( !(uint8_t)_R5 )
    {
      v66 = *(uint32_t *)v65;
LABEL_57:
      _R2 >>= 8;
      v66 &= 0xFFFFFFu;
      goto LABEL_59;
    }
    return 0;
  }
  else if ( _CF )
  {
    while ( 1 )
    {
      (void)0;

      _R5 = (uint16_t)_R2 ^ HIWORD(v66);
      if ( (uint32_t)_R5 )
      {
        v66 >>= 16;
        goto LABEL_59;
      }
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)_R2);
      if ( _R5 )
        break;
      v76 = *(uint32_t *)v65;
      v65 += 2;
      v66 = v76;
      if ( ((uint16_t)_R2 ^ _R2) != v76 << 16 )
      {
        _R2 >>= 16;
        v66 = (uint16_t)v66;
        goto LABEL_59;
      }
      v77 = *v59++;
      _R2 = v77;
    }
    if ( (uint16_t)_R5 )
      return 0;
    v66 = *v65;
    _R2 >>= 16;
LABEL_59:
    _R2 = bswap32(_R2);
    v84 = bswap32(v66);
    (void)0;

    _R4 = _R2 ^ v84;
    _R5 = (uint32_t)_R4 | __zmask32((uint32_t)_R2);

    _R4 = ((unsigned)(_R4) & 0xFFFFFF00U) | (((unsigned)(__clz(_R5)) & 0xFFU) << 0);
    return ((uint32_t)_R2 << _R4 >> 24) - (v84 << _R4 >> 24);
  }
  else
  {
    while ( 1 )
    {
      (void)0;

      _R5 = _R2 & 0xFFFFFF ^ (v66 >> 8);
      if ( (uint32_t)_R5 )
      {
        v66 >>= 8;
        goto LABEL_59;
      }
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)_R2);
      if ( _R5 )
        break;
      v71 = *(uint32_t *)v65;
      v65 += 2;
      v66 = v71;
      if ( (_R2 & 0xFFFFFF ^ _R2) != v71 << 24 )
      {
        _R2 >>= 24;
        v66 = (uint8_t)v66;
        goto LABEL_59;
      }
      v72 = *v59++;
      _R2 = v72;
    }
    if ( (_R5 & 0xFFFFFF) != 0 )
      return 0;
    return -*(uint8_t *)v65;
  }
}
