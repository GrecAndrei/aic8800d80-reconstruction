// sub_130474 @ 0x130474, size 88 bytes
int sub_130474()
{
  _BYTE *v0; // r4
  int result; // r0
  int v2; // r0
  int v3; // r2
  int v4; // r0

  v0 = off_1304CC;
  *((_BYTE *)off_1304CC + 1) = 1;
  result = sub_12C774(1070, 1);
  if ( !result )
  {
    sub_10DEB0();
    *(_DWORD *)(v0 + 0x18) = sub_10EDE4();
    sub_130370();
    v2 = (unsigned __int8)*(_DWORD *)(v0 + 0x14);
    if ( (unsigned __int8)*(_DWORD *)(v0 + 0x18) != v2 )
    {
      sub_10EDF8(v2);
      v3 = (unsigned __int8)*(_DWORD *)(v0 + 0x14);
      v4 = dword_1304D4;
      *(_DWORD *)(v0 + 0x18) = v3;
      sub_12E948(v4, v3);
    }
    return sub_12C4A4(1070, 1, 1000 * *((_DWORD *)off_1304D0 + 91));
  }
  return result;
}

