// sub_120368 @ 0x120368, size 138 bytes
int sub_120368()
{
  int result; // r0
  _DWORD *v1; // r1
  _WORD *v2; // r3
  unsigned int v3; // r2
  __int16 v4; // r2
  _DWORD *v5; // r1
  __int16 v6; // r2
  _DWORD *v7; // r1
  __int16 v8; // r2

  if ( (unsigned __int16)(*(_DWORD *)off_1203F4 >> 12) && (unsigned __int16)(*(_DWORD *)off_1203F4 >> 12) <= 0x96u )
    result = (unsigned __int16)(*(_DWORD *)off_1203F4 >> 12);
  else
    result = 150;
  v1 = off_1203F8;
  v2 = off_1203FC;
  v3 = *(_DWORD *)off_1203F8;
  *((_WORD *)off_1203FC + 4) = result;
  if ( (unsigned __int16)(v3 >> 12) && (unsigned __int16)(*v1 >> 12) <= 0x96u )
    v4 = *v1 >> 12;
  else
    v4 = 150;
  v5 = off_120400;
  v2[5] = v4;
  if ( (unsigned __int16)(*v5 >> 12) && (unsigned __int16)(*v5 >> 12) <= 0x96u )
    v6 = *v5 >> 12;
  else
    v6 = 150;
  v7 = off_120404;
  v2[6] = v6;
  if ( (unsigned __int16)(*v7 >> 12) && (unsigned __int16)(*v7 >> 12) <= 0x96u )
  {
    v8 = *v7 >> 12;
    v2[7] = v8;
    v2[8] = v8;
  }
  else
  {
    v2[7] = 150;
    v2[8] = 150;
  }
  return result;
}

