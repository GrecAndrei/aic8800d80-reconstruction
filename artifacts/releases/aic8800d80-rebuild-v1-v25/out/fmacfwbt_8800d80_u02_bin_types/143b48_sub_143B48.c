// sub_143B48 @ 0x143b48, size 724 bytes
int  sub_143B48(unsigned int a1, unsigned int *a2)
{
  int v3; // r2
  int v4; // r3
  char v7; // r4
  uint64_t *v8; // r0
  QWORD *v9; // r1
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
  unsigned __int8 v55; // t2
  int v56; // r4
  int v57; // r3
  unsigned __int8 v58; // t2
  unsigned int *v59; // r0
  unsigned int v61; // t1
  char v63; // cc
  uint32_t *v64; // r1
  unsigned __int16 *v65; // r1
  unsigned int v66; // r3
  unsigned int v67; // t1
  unsigned int v71; // t1
  unsigned int v72; // t1
  unsigned int v76; // t1
  unsigned int v77; // t1
  unsigned int v81; // t1
  unsigned int v82; // t1
  unsigned int v84; // r3

  v3 = *(unsigned __int8 *)a1;
  v4 = *(unsigned __int8 *)a2;
  ZF = v3 == 1;
  if ( *(uint8_t *)a1 )
    ZF = v3 == v4;
  if ( !ZF )
    return v3 - v4;
  R12 = -1;
  if ( !((a1 | (unsigned int)a2) << 29) )
    goto LABEL_9;
  if ( ((a1 ^ (unsigned int)a2) & 7) == 0 )
  {
    v7 = a1 & 7;
    v8 = (uint64_t *)(a1 & 0xFFFFFFF8);
    v9 = (QWORD *)((unsigned int)a2 & 0xFFFFFFF8);
    v10 = *v8;
    a1 = (unsigned int)(v8 + 2);
    R2 = v10;
    ZF = (v7 & 4) == 0;
    v11 = *v9;
    a2 = (unsigned int *)(v9 + 2);
    v12 = -1 << (8 * (v7 & 3));
    LODWORD(R2) = R2 | ~v12;
    v14 = v11 | (unsigned int)~v12;
    if ( !ZF )
    {
      HIDWORD(R2) |= ~v12;
      LODWORD(R2) = -1;
      HIDWORD(v14) |= ~v12;
      LODWORD(v14) = -1;
    }
    while ( 1 )
    {
      __asm { UADD8.W         R5, R2, R12 }
      R4 = R2 ^ v14;
      __asm { SEL.W           R4, R4, R12 }
      if ( R4 )
        break;
      __asm { UADD8.W         R5, R3, R12 }
      R5 = HIDWORD(R2) ^ HIDWORD(v14);
      __asm { SEL.W           R5, R5, R12 }
      if ( R5 )
        goto LABEL_14;
      R2 = *(QWORD *)(a1 - 8);
      v14 = *((QWORD *)a2 - 1);
      __asm { UADD8.W         R5, R2, R12 }
      R4 = R2 ^ v14;
      __asm
      {
        SEL.W           R4, R4, R12
        UADD8.W         R5, R3, R12
      }
      R5 = HIDWORD(R2) ^ HIDWORD(v14);
      __asm { SEL.W           R5, R5, R12 }
      R5 = R5 | R4;
      if ( R5 )
      {
        if ( !R4 )
        {
LABEL_14:
          v30 = __clz(bswap32(R5)) & 0xF8;
          return (unsigned __int8)(HIDWORD(R2) >> v30) - (unsigned __int8)(HIDWORD(v14) >> v30);
        }
        break;
      }
LABEL_9:
      v15 = *(QWORD *)a1;
      a1 += 16;
      R2 = v15;
      v16 = *(QWORD *)a2;
      a2 += 4;
      v14 = v16;
    }
    v31 = __clz(bswap32(R4)) & 0xF8;
    return (unsigned __int8)((unsigned int)R2 >> v31) - (unsigned __int8)((unsigned int)v14 >> v31);
  }
  if ( (((unsigned __int8)a1 ^ (unsigned __int8)a2) & 3) == 0 )
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
      R2 = v44 | ~v48;
      v35 = v47 | ~v48;
      goto LABEL_19;
    }
    do
    {
      v34 = *(uint32_t *)a1;
      a1 += 8;
      R2 = v34;
      v36 = *a2;
      a2 += 2;
      v35 = v36;
LABEL_19:
      __asm { UADD8.W         R5, R2, R12 }
      R5 = R2 ^ v35;
      __asm { SEL.W           R5, R5, R12 }
      if ( R5 )
        break;
      R2 = *(uint32_t *)(a1 - 4);
      v35 = *(a2 - 1);
      __asm { UADD8.W         R5, R2, R12 }
      R5 = R2 ^ v35;
      __asm { SEL.W           R5, R5, R12 }
    }
    while ( !R5 );
    v42 = __clz(bswap32(R5)) & 0xF8;
    return (unsigned __int8)(R2 >> v42) - (unsigned __int8)(v35 >> v42);
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
      v54 = (unsigned __int8)v50[2];
      v55 = __ROR4__(v52, 16);
      v56 = v55 - v54;
      if ( v55 != v54 || !v50[2] )
        return v56;
    }
    v57 = (unsigned __int8)v50[3];
    v58 = __ROR4__(v52, 24);
    v56 = v58 - v57;
    if ( v58 != v57 || !v50[3] )
      return v56;
    goto LABEL_31;
  }
LABEL_32:
  v61 = *(uint32_t *)a1;
  v59 = (unsigned int *)(a1 + 4);
  R2 = v61;
  CF = __CFSHL__(a2, 31);
  v63 = ((uint32_t)a2 << 31 != 0) & __CFSHL__(a2, 31);
  v64 = (uint32_t *)((unsigned int)a2 & 0xFFFFFFFC);
  v67 = *v64;
  v65 = (unsigned __int16 *)(v64 + 1);
  v66 = v67;
  if ( v63 )
  {
    while ( 1 )
    {
      __asm { UADD8.W         R5, R2, R12 }
      R5 = (unsigned __int8)R2 ^ HIBYTE(v66);
      __asm { SEL.W           R5, R5, R12 }
      if ( !ZF )
      {
        v66 >>= 24;
        goto LABEL_59;
      }
      if ( R5 )
        break;
      v81 = *(uint32_t *)v65;
      v65 += 2;
      v66 = v81;
      if ( ((unsigned __int8)R2 ^ R2) != v81 << 8 )
        goto LABEL_57;
      v82 = *v59++;
      R2 = v82;
    }
    if ( !(uint8_t)R5 )
    {
      v66 = *(uint32_t *)v65;
LABEL_57:
      R2 >>= 8;
      v66 &= 0xFFFFFFu;
      goto LABEL_59;
    }
    return 0;
  }
  else if ( CF )
  {
    while ( 1 )
    {
      __asm { UADD8.W         R5, R2, R12 }
      R5 = (unsigned __int16)R2 ^ HIWORD(v66);
      __asm { SEL.W           R5, R5, R12 }
      if ( !ZF )
      {
        v66 >>= 16;
        goto LABEL_59;
      }
      if ( R5 )
        break;
      v76 = *(uint32_t *)v65;
      v65 += 2;
      v66 = v76;
      if ( ((unsigned __int16)R2 ^ R2) != v76 << 16 )
      {
        R2 >>= 16;
        v66 = (unsigned __int16)v66;
        goto LABEL_59;
      }
      v77 = *v59++;
      R2 = v77;
    }
    if ( (uint16_t)R5 )
      return 0;
    v66 = *v65;
    R2 >>= 16;
LABEL_59:
    R2 = bswap32(R2);
    v84 = bswap32(v66);
    __asm { UADD8.W         R4, R2, R12 }
    R4 = R2 ^ v84;
    __asm { SEL.W           R5, R4, R12 }
    LOBYTE(R4) = __clz(R5);
    return (R2 << R4 >> 24) - (v84 << R4 >> 24);
  }
  else
  {
    while ( 1 )
    {
      __asm { UADD8.W         R5, R2, R12 }
      R5 = R2 & 0xFFFFFF ^ (v66 >> 8);
      __asm { SEL.W           R5, R5, R12 }
      if ( !ZF )
      {
        v66 >>= 8;
        goto LABEL_59;
      }
      if ( R5 )
        break;
      v71 = *(uint32_t *)v65;
      v65 += 2;
      v66 = v71;
      if ( (R2 & 0xFFFFFF ^ R2) != v71 << 24 )
      {
        R2 >>= 24;
        v66 = (unsigned __int8)v66;
        goto LABEL_59;
      }
      v72 = *v59++;
      R2 = v72;
    }
    if ( (R5 & 0xFFFFFF) != 0 )
      return 0;
    return -*(unsigned __int8 *)v65;
  }
}

