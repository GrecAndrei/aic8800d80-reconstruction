// sub_11A7C0 @ 0x11a7c0, size 58 bytes
int __fastcall sub_11A7C0(int result)
{
  int v1; // r5
  int v2; // r1
  char v3; // r3
  int v4; // r4

  v1 = dword_11A7FC;
  v2 = *(_DWORD *)(dword_11A7FC + 84 * result + 40);
  if ( v2 )
  {
    v3 = *(_BYTE *)(v2 + 14) - 1;
    v4 = result;
    *(_BYTE *)(v2 + 14) = v3;
    if ( !v3 )
      sub_12D108(*(_DWORD *)(v2 + 340));
    *(_DWORD *)(v1 + 84 * v4 + 40) = 0;
    return 84;
  }
  return result;
}

