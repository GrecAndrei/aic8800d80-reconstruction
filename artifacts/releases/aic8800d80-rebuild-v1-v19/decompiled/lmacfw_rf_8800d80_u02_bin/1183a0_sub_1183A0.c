// sub_1183A0 @ 0x1183a0, size 134 bytes
int sub_1183A0()
{
  int result; // r0
  _DWORD *v1; // r1
  _WORD *v2; // r3
  unsigned int v3; // r2
  __int16 v4; // r2
  _DWORD *v5; // r1
  __int16 v6; // r2
  _DWORD *v7; // r1

  if ( (unsigned __int16)(*(_DWORD *)off_118428 >> 12) && (unsigned __int16)(*(_DWORD *)off_118428 >> 12) <= 0x96u )
    result = (unsigned __int16)(*(_DWORD *)off_118428 >> 12);
  else
    result = 150;
  v1 = off_11842C;
  v2 = off_118430;
  v3 = *(_DWORD *)off_11842C;
  *((_WORD *)off_118430 + 4) = result;
  if ( (unsigned __int16)(v3 >> 12) && (unsigned __int16)(*v1 >> 12) <= 0x96u )
    v4 = *v1 >> 12;
  else
    v4 = 150;
  v5 = off_118434;
  v2[5] = v4;
  if ( (unsigned __int16)(*v5 >> 12) && (unsigned __int16)(*v5 >> 12) <= 0x96u )
    v6 = *v5 >> 12;
  else
    v6 = 150;
  v7 = off_118438;
  v2[6] = v6;
  if ( (unsigned __int16)(*v7 >> 12) && (unsigned __int16)(*v7 >> 12) <= 0x96u )
    v2[7] = *v7 >> 12;
  else
    v2[7] = 150;
  return result;
}

