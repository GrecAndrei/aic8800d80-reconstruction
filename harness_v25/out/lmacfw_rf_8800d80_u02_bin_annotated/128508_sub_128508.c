// fwstruct annotate: 128508_sub_128508.c
// sub_128508 @ 0x128508, size 724 bytes
int __fastcall sub_128508(unsigned int a1, unsigned int *a2)
{
  int v3; // r2
  int v4; // r3
  char v7; // r4
  __int64 *v8; // r0
  _QWORD *v9; // r1
  __int64 v10; // t1
  __int64 v11; // t1
  int v12; // r4
  __int64 v14; // r6
  __int64 v15; // t1
  __int64 v16; // t1
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
  _DWORD *v46; // r1
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
  _DWORD *v64; // r1
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
  _ZF = v3 == 1;
  if ( *(_BYTE *)a1 )
    _ZF = v3 == v4;
  if ( !_ZF )
    return v3 - v4;
  _R12 = -1;
  if ( !((a1 | (unsigned int)a2) << 29) )
    goto LABEL_9;
  if ( ((a1 ^ (unsigned int)a2) & 7) == 0 )
  {
    v7 = a1 & 7;
    v8 = (__int64 *)(a1 & 0xFFFFFFF8);
    v9 = (_QWORD *)((unsigned int)a2 & 0xFFFFFFF8);
    v10 = *v8;
    a1 = (unsigned int)(v8 + 2);
    _R2 = v10;
    _ZF = (v7 & 4) == 0;
    v11 = *v9;
    a2 = (unsigned int *)(v9 + 2);
    v12 = -1 << (8 * (v7 & 3));
    LODWORD(_R2) = _R2 | ~v12;
    v14 = v11 | (unsigned int)~v12;
    if ( !_ZF )
    {
      HIDWORD(_R2) |= ~v12;
      LODWORD(_R2) = -1;
      HIDWORD(v14) |= ~v12;
      LODWORD(v14) = -1;
    }
    while ( 1 )
    {
      __asm { UADD8.W         R5, R2, R12 }
      _R4 = _R2 ^ v14;
      __asm { SEL.W           R4, R4, R12 }
      if ( _R4 )
        break;
      __asm { UADD8.W         R5, R3, R12 }
      _R5 = HIDWORD(_R2) ^ HIDWORD(v14);
      __asm { SEL.W           R5, R5, R12 }
      if ( _R5 )
        goto LABEL_14;
      _R2 = *(_QWORD *)(a1 - 8);
      v14 = *((_QWORD *)a2 - 1);
      __asm { UADD8.W         R5, R2, R12 }
      _R4 = _R2 ^ v14;
      __asm
      {
        SEL.W           R4, R4, R12
        UADD8.W         R5, R3, R12
      }
      _R5 = HIDWORD(_R2) ^ HIDWORD(v14);
      __asm { SEL.W           R5, R5, R12 }
      _R5 = _R5 | _R4;
      if ( _R5 )
      {
        if ( !_R4 )
        {
LABEL_14:
          v30 = __clz(bswap32(_R5)) & 0xF8;
          return (unsigned __int8)(HIDWORD(_R2) >> v30) - (unsigned __int8)(HIDWORD(v14) >> v30);
        }
        break;
      }
LABEL_9:
      v15 = *(_QWORD *)a1;
      a1 += 16;
      _R2 = v15;
      v16 = *(_QWORD *)a2;
      a2 += 4;
      v14 = v16;
    }
    v31 = __clz(bswap32(_R4)) & 0xF8;
    return (unsigned __int8)((unsigned int)_R2 >> v31) - (unsigned __int8)((unsigned int)v14 >> v31);
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
      v46 = (_DWORD *)((unsigned int)a2 & 0xFFFFFFFC);
      v47 = *v46;
      a2 = v46 + 2;
      v48 = -1 << (8 * v32);
      _R2 = v44 | ~v48;
      v35 = v47 | ~v48;
      goto LABEL_19;
    }
    do
    {
      v34 = *(_DWORD *)a1;
      a1 += 8;
      _R2 = v34;
      v36 = *a2;
      a2 += 2;
      v35 = v36;
LABEL_19:
      __asm { UADD8.W         R5, R2, R12 }
      _R5 = _R2 ^ v35;
      __asm { SEL.W           R5, R5, R12 }
      if ( _R5 )
        break;
      _R2 = *(_DWORD *)(a1 - 4);
      v35 = *(a2 - 1);
      __asm { UADD8.W         R5, R2, R12 }
      _R5 = _R2 ^ v35;
      __asm { SEL.W           R5, R5, R12 }
    }
    while ( !_R5 );
    v42 = __clz(bswap32(_R5)) & 0xF8;
    return (unsigned __int8)(_R2 >> v42) - (unsigned __int8)(v35 >> v42);
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
  v61 = *(_DWORD *)a1;
  v59 = (unsigned int *)(a1 + 4);
  _R2 = v61;
  _CF = __CFSHL__(a2, 31);
  v63 = ((_DWORD)a2 << 31 != 0) & __CFSHL__(a2, 31);
  v64 = (_DWORD *)((unsigned int)a2 & 0xFFFFFFFC);
  v67 = *v64;
  v65 = (unsigned __int16 *)(v64 + 1);
  v66 = v67;
  if ( v63 )
  {
    while ( 1 )
    {
      __asm { UADD8.W         R5, R2, R12 }
      _R5 = (unsigned __int8)_R2 ^ HIBYTE(v66);
      __asm { SEL.W           R5, R5, R12 }
      if ( !_ZF )
      {
        v66 >>= 24;
        goto LABEL_59;
      }
      if ( _R5 )
        break;
      v81 = *(_DWORD *)v65;
      v65 += 2;
      v66 = v81;
      if ( ((unsigned __int8)_R2 ^ _R2) != v81 << 8 )
        goto LABEL_57;
      v82 = *v59++;
      _R2 = v82;
    }
    if ( !(_BYTE)_R5 )
    {
      v66 = *(_DWORD *)v65;
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
      __asm { UADD8.W         R5, R2, R12 }
      _R5 = (unsigned __int16)_R2 ^ HIWORD(v66);
      __asm { SEL.W           R5, R5, R12 }
      if ( !_ZF )
      {
        v66 >>= 16;
        goto LABEL_59;
      }
      if ( _R5 )
        break;
      v76 = *(_DWORD *)v65;
      v65 += 2;
      v66 = v76;
      if ( ((unsigned __int16)_R2 ^ _R2) != v76 << 16 )
      {
        _R2 >>= 16;
        v66 = (unsigned __int16)v66;
        goto LABEL_59;
      }
      v77 = *v59++;
      _R2 = v77;
    }
    if ( (_WORD)_R5 )
      return 0;
    v66 = *v65;
    _R2 >>= 16;
LABEL_59:
    _R2 = bswap32(_R2);
    v84 = bswap32(v66);
    __asm { UADD8.W         R4, R2, R12 }
    _R4 = _R2 ^ v84;
    __asm { SEL.W           R5, R4, R12 }
    LOBYTE(_R4) = __clz(_R5);
    return (_R2 << _R4 >> 24) - (v84 << _R4 >> 24);
  }
  else
  {
    while ( 1 )
    {
      __asm { UADD8.W         R5, R2, R12 }
      _R5 = _R2 & 0xFFFFFF ^ (v66 >> 8);
      __asm { SEL.W           R5, R5, R12 }
      if ( !_ZF )
      {
        v66 >>= 8;
        goto LABEL_59;
      }
      if ( _R5 )
        break;
      v71 = *(_DWORD *)v65;
      v65 += 2;
      v66 = v71;
      if ( (_R2 & 0xFFFFFF ^ _R2) != v71 << 24 )
      {
        _R2 >>= 24;
        v66 = (unsigned __int8)v66;
        goto LABEL_59;
      }
      v72 = *v59++;
      _R2 = v72;
    }
    if ( (_R5 & 0xFFFFFF) != 0 )
      return 0;
    return -*(unsigned __int8 *)v65;
  }
}

