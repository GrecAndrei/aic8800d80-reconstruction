// v23 annotated: sub_13684C @ 0x13684c
// Original: 13684c_sub_13684C.c
// Primary struct: <unclustered>
//
// sub_13684C @ 0x13684c, size 58 bytes
_DWORD *sub_13684C()
{
  int v0; // r4
  int v1; // r0
  __int16 v2; // r1
  __int16 v3; // r2

  v0 = *(_DWORD *)off_136888;
  v1 = sub_12C7EC(63, 0, 7, 0xCu);
  v2 = *(_WORD *)(v0 + 36);
  v3 = *(_WORD *)(v0 + 38);
  *(_DWORD *)v1 = *(_DWORD *)(v0 + 32);
  *(_WORD *)(v1 + 4) = v2;
  *(_WORD *)(v1 + 6) = v3;
  *(_BYTE *)(v1 + 8) = *(_BYTE *)(v0 + 50);
  *(_BYTE *)(v1 + 9) = *(_BYTE *)(v0 + 51);
  sub_12C84C(v1);
  return sub_12CBF4(7u, 2);
}

