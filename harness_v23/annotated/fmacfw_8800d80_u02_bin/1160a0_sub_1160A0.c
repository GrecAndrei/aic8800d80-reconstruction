// v23 annotated: sub_1160A0 @ 0x1160a0
// Original: 1160a0_sub_1160A0.c
// Primary struct: <unclustered>
//
// sub_1160A0 @ 0x1160a0, size 34 bytes
// Doc: sub_12160A0 [unknown]: Lookup 3*index entry in table at 0x187f98 and load field
// sub_12160A0 [unknown]: Lookup 3*index entry in table at 0x187f98 and load field
int __fastcall sub_1160A0(int a1, int a2)
{
  int v2; // r3
  int result; // r0
  int v4; // r2

  v2 = dword_1160C4;
  result = a1 + 22;
  v4 = dword_1160C4 + 8 * result;
  if ( *(_DWORD *)(v4 + 4) )
    v4 = *(_DWORD *)(v4 + 8);
  *(_DWORD *)(v4 + 4) = a2;
  *(_DWORD *)(v2 + 8 * result + 8) = a2;
  *(_DWORD *)(a2 + 4) = 0;
  return result;
}

