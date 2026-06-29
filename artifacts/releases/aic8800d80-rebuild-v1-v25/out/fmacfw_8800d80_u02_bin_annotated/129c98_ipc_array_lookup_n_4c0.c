// fwstruct annotate: 129c98_ipc_array_lookup_n_4c0.c
// ipc_array_lookup_n_4c0 @ 0x129c98, size 182 bytes
// Doc: ipc_array_lookup_n_4c0 [ipc]: Look up element in 0x528-stride IPC array via mla index
// ipc_array_lookup_n_4c0 [ipc]: Look up element in 0x528-stride IPC array via mla index
unsigned int __fastcall ipc_array_lookup_n_4c0(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // r6
  int v6; // r7
  unsigned int v7; // r5
  unsigned int v8; // r3
  unsigned int v9; // r5
  __int16 **v10; // r3
  _DWORD *v11; // r2
  unsigned int v12; // r3
  unsigned int result; // r0
  _DWORD *v14; // r1

  v4 = a3;
  v6 = dword_129D50 + 1320 * a2;
  if ( a4 < a3 )
  {
    v9 = 0;
  }
  else
  {
    if ( *(_BYTE *)(a1 + 19) == 1 )
      return 0;
    v7 = *(_DWORD *)(a1 + 28);
    v8 = (a4 - a3) / v7;
    v4 = a3 + v7 + v8 * v7;
    v9 = v8 + 1;
  }
  v10 = (__int16 **)off_129D54;
  *(_DWORD *)(a1 + 44) = v4;
  if ( **v10 < 0 && *(_BYTE *)(v6 + 106) )
    sub_12F46C(dword_129D64, dword_129D60, 98);
  v11 = off_129D5C;
  v12 = *(unsigned __int8 *)(a1 + 19);
  result = *((_DWORD *)off_129D5C + 4) - *(_DWORD *)off_129D58 - *(_DWORD *)(v6 + 132) + v4;
  if ( v12 == 255 )
  {
    if ( (int)(result - *((_DWORD *)off_129D5C + 4)) < 0 )
      goto LABEL_10;
    return result;
  }
  if ( v12 > v9 )
    LOBYTE(v12) = v12 - v9;
  else
    LOBYTE(v12) = 0;
  v12 = (unsigned __int8)v12;
  *(_BYTE *)(a1 + 19) = v12;
  if ( (int)(result - v11[4]) < 0 )
  {
LABEL_10:
    v14 = off_129D5C;
    while ( v12 )
    {
      while ( 1 )
      {
        result += *(_DWORD *)(a1 + 28);
        if ( v12 != 255 )
          break;
        if ( (int)(result - v14[4]) >= 0 )
          return result;
      }
      v12 = (unsigned __int8)(v12 - 1);
      *(_BYTE *)(a1 + 19) = v12;
      if ( (int)(result - v14[4]) >= 0 )
        goto LABEL_14;
    }
    return 0;
  }
LABEL_14:
  if ( !v12 )
    return 0;
  return result;
}

