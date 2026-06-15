// v23 annotated: sub_1288C0 @ 0x1288c0
// Original: 1288c0_sub_1288C0.c
// Primary struct: <unclustered>
//
// sub_1288C0 @ 0x1288c0, size 220 bytes
// Doc: sub_12288C0 [util]: Memory copy/fill routine with pld prefetch
// sub_12288C0 [util]: Memory copy/fill routine with pld prefetch
unsigned int __fastcall sub_1288C0(unsigned int a1)
{
  __int64 *v1; // r1
  int v3; // r4
  int v5; // r0
  int v15; // r5

  __pld((void *)a1);
  v1 = (__int64 *)(a1 & 0xFFFFFFF8);
  _R12 = -1;
  v3 = a1 & 7;
  __pld((void *)((a1 & 0xFFFFFFF8) + 32));
  if ( (a1 & 7) != 0 )
  {
    _R2 = *v1;
    v5 = -v3;
    __pld(v1 + 8);
    v15 = -1 << (8 * (v3 & 3));
    LODWORD(_R2) = _R2 | ~v15;
    if ( (v3 & 4) != 0 )
    {
      HIDWORD(_R2) |= ~v15;
      LODWORD(_R2) = -1;
    }
    _R4 = 0;
    goto LABEL_4;
  }
  _R4 = 0;
  v5 = -8;
  do
  {
    _R2 = *v1;
    __pld(v1 + 8);
    v5 += 8;
LABEL_4:
    __asm
    {
      UADD8.W         R2, R2, R12
      SEL.W           R2, R4, R12
      UADD8.W         R3, R3, R12
      SEL.W           R3, R2, R12
    }
    if ( HIDWORD(_R2) )
      break;
    _R2 = v1[1];
    __asm { UADD8.W         R2, R2, R12 }
    v5 += 8;
    __asm
    {
      SEL.W           R2, R4, R12
      UADD8.W         R3, R3, R12
      SEL.W           R3, R2, R12
    }
    if ( HIDWORD(_R2) )
      break;
    _R2 = v1[2];
    __asm { UADD8.W         R2, R2, R12 }
    v5 += 8;
    __asm
    {
      SEL.W           R2, R4, R12
      UADD8.W         R3, R3, R12
      SEL.W           R3, R2, R12
    }
    if ( HIDWORD(_R2) )
      break;
    _R2 = v1[3];
    v1 += 4;
    __asm { UADD8.W         R2, R2, R12 }
    v5 += 8;
    __asm
    {
      SEL.W           R2, R4, R12
      UADD8.W         R3, R3, R12
      SEL.W           R3, R2, R12
    }
  }
  while ( !HIDWORD(_R2) );
  if ( !(_DWORD)_R2 )
  {
    v5 += 4;
    LODWORD(_R2) = HIDWORD(_R2);
  }
  return v5 + (__clz(bswap32(_R2)) >> 3);
}

