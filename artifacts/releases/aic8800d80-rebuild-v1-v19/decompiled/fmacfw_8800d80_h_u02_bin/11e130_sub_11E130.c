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
  v3 = v1[7] + v1[3];
  v4 = v1[5] + v1[1];
  v5 = v1[2];
  v1[5] = v4;
  v1[7] = v3;
  *((_BYTE *)v1 + 33) = 1;
  v1[6] = v5;
  if ( v3 >= result << 9 )
  {
    result = sub_110EDC(v1[4], v4, v5);
    v1[4] = 0;
    v1[5] = 0;
    v1[6] = 0;
    v1[7] = 0;
    *((_BYTE *)v1 + 33) = 0;
  }
  return result;
}

