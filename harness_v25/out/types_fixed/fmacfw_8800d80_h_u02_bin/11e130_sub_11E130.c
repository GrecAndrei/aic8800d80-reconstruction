// sub_11E130 @ 0x11e130, size 80 bytes
int __fastcall sub_11E130(int a1)
{
  _DWORD *v1; // r4
  int result; // r0
  unsigned int v3; // r3
  int v4; // r1
  int v5; // r2

  v1 = off_11E180;
  if ( *((_BYTE *)off_11E180 + 33) )
    *(_DWORD *)(*((_DWORD *)off_11E180 + 6) + 4) = a1;
  else
    *((_DWORD *)off_11E180 + 4) = a1;
  result = *((unsigned __int8 *)off_11E184 + 193);
  v3 = *(_DWORD *)(v1 + 0x1c) + *(_DWORD *)(v1 + 0xc);
  v4 = *(_DWORD *)(v1 + 0x14) + *(_DWORD *)(v1 + 0x4);
  v5 = *(_DWORD *)(v1 + 0x8);
  *(_DWORD *)(v1 + 0x14) = v4;
  *(_DWORD *)(v1 + 0x1c) = v3;
  *((_BYTE *)v1 + 33) = 1;
  *(_DWORD *)(v1 + 0x18) = v5;
  if ( v3 >= result << 9 )
  {
    result = sub_110EDC(*(_DWORD *)(v1 + 0x10), v4, v5);
    *(_DWORD *)(v1 + 0x10) = 0;
    *(_DWORD *)(v1 + 0x14) = 0;
    *(_DWORD *)(v1 + 0x18) = 0;
    *(_DWORD *)(v1 + 0x1c) = 0;
    *((_BYTE *)v1 + 33) = 0;
  }
  return result;
}

