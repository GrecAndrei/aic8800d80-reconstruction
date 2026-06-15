// v23 annotated: sub_11BD44 @ 0x11bd44
// Original: 11bd44_sub_11BD44.c
// Primary struct: <unclustered>
//
// sub_11BD44 @ 0x11bd44, size 54 bytes
// Doc: sub_121BD44 [util]: LMAC RF helper: load constant and tail-call helper
// sub_121BD44 [util]: LMAC RF helper: load constant and tail-call helper
int __fastcall sub_11BD44(int a1, _BYTE *a2)
{
  int v4; // r0
  char v5; // r2
  int v6; // r1

  v4 = sub_11E7AC(dword_11BD7C);
  if ( !v4 )
    return 1;
  v5 = dword_11BD84 * ((v4 - dword_11BD80) >> 2);
  *(_BYTE *)(v4 + 24) = v5;
  *a2 = v5;
  v6 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(v4 + 4) = *(_DWORD *)a1;
  *(_DWORD *)(v4 + 8) = v6;
  *(_WORD *)(v4 + 12) = *(_WORD *)(a1 + 8);
  return 0;
}

