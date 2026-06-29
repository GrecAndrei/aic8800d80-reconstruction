// fwstruct annotate: 13bf64_sub_13BF64.c
// sub_13BF64 @ 0x13bf64, size 108 bytes
int __fastcall sub_13BF64(int a1, int a2)
{
  int v3; // r7
  int v5; // r4

  if ( a2 == 255 )
    return 2;
  v3 = dword_13BFD0;
  v5 = *(unsigned __int8 *)(696 * (unsigned __int8)a1 + 12 * (unsigned __int8)a2 + dword_13BFD0 + 453);
  return v5 == 33
      || sub_12CD48((v5 << 8) | 8) != 1
      || *(unsigned __int16 *)(dword_13BFD4 + 32 * v5 + 20) > ((*(_WORD *)(v3 + 2 * (a2 + 348 * a1) + 316)
                                                              - *(_WORD *)(*(_DWORD *)(dword_13BFD4 + 32 * v5 + 28) + 4))
                                                             & 0xFFFu);
}

