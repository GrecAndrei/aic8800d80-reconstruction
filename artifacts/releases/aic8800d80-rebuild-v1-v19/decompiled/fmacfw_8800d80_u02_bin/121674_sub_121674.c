// sub_121674 @ 0x121674, size 198 bytes
_DWORD *__fastcall sub_121674(int a1)
{
  int v2; // r1
  _DWORD *v3; // r5
  _DWORD *v4; // r2
  int *v5; // r1
  _DWORD *v6; // r5
  _DWORD *result; // r0
  int v8; // r5
  int v9; // r6
  _DWORD *v10; // r2

  if ( (unsigned int)a1 > HIBYTE(*(_DWORD *)off_12173C) )
    return (_DWORD *)sub_12018C(
                       dword_121744 + 1320 * ((a1 - (HIBYTE(*(_DWORD *)off_12173C) + 1)) / 2),
                       (((_BYTE)a1 - 1 - HIBYTE(*(_DWORD *)off_12173C)) & 1) + 4);
  if ( (unsigned int)a1 > 0xF )
  {
    v8 = dword_121760 + 696 * (unsigned __int8)(a1 - 16);
    v9 = *(unsigned __int8 *)(v8 + 34);
    result = (_DWORD *)ipc_msg_init_struct(v8);
    if ( *(_BYTE *)(dword_121744 + 1320 * v9 + 106) == 2 )
      return result;
    v10 = off_121748;
    *(_DWORD *)off_121740 = *(unsigned __int16 *)(v8 + 38) | (*(unsigned __int16 *)(v8 + 40) << 16);
    *v10 = *(unsigned __int16 *)(v8 + 42);
  }
  else
  {
    v2 = dword_121744;
    v3 = off_121748;
    *(_DWORD *)off_121740 = -1;
    *v3 = -1;
    sub_12018C(v2 + 1320 * (a1 >> 2), a1 & 3);
  }
  v4 = off_12174C;
  v5 = (int *)off_121750;
  v6 = off_121758;
  result = off_12175C;
  *(_DWORD *)off_121754 = 0;
  *v6 = 0;
  *v4 = 0;
  *result = 0;
  *v5 = (a1 << 16) | 0x40000000;
  while ( (*v5 & 0x40000000) != 0 )
    ;
  return result;
}

