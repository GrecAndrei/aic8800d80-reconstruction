// sub_11E270 @ 0x11e270, size 80 bytes
// Doc: sub_121E270 [unknown]: Unknown behavioral stub
// sub_121E270 [unknown]: Unknown behavioral stub
int __fastcall sub_11E270(int a1)
{
  _DWORD *v1; // r4
  int result; // r0
  unsigned int v3; // r3
  int v4; // r1
  int v5; // r2

  v1 = off_11E2C0;
  if ( *((_BYTE *)off_11E2C0 + 33) )
    *(_DWORD *)(*((_DWORD *)off_11E2C0 + 6) + 4) = a1;
  else
    *((_DWORD *)off_11E2C0 + 4) = a1;
  result = *((unsigned __int8 *)off_11E2C4 + 193);
  v3 = v1[7] + v1[3];
  v4 = v1[5] + v1[1];
  v5 = v1[2];
  v1[5] = v4;
  v1[7] = v3;
  *((_BYTE *)v1 + 33) = 1;
  v1[6] = v5;
  if ( v3 >= result << 9 )
  {
    result = sub_11101C(v1[4], v4, v5);
    v1[4] = 0;
    v1[5] = 0;
    v1[6] = 0;
    v1[7] = 0;
    *((_BYTE *)v1 + 33) = 0;
  }
  return result;
}

