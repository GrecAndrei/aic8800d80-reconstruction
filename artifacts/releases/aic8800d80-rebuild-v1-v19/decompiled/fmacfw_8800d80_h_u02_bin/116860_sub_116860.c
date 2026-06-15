// sub_116860 @ 0x116860, size 248 bytes
int __fastcall sub_116860(int result, int a2, int a3)
{
  int v4; // r6
  int *v6; // r5
  int v7; // r2
  int v8; // r3
  void *v9; // r8
  int v10; // r3
  int v11; // r2
  int v12; // r2

  v4 = result;
  if ( a3 == 5 )
    v6 = (int *)dword_11696C;
  else
    v6 = (int *)(dword_116958 + 84 * a3);
  v7 = *v6;
  v8 = **(__int16 **)off_11695C;
  if ( v8 < 0 && v7 == result )
    return sub_12F2C8(dword_116968, dword_116964, 1972, v8);
  if ( v7 )
  {
    v9 = off_116970;
    v10 = *(unsigned __int8 *)(*(_DWORD *)off_116970 + 1);
    if ( *(_BYTE *)(*(_DWORD *)off_116970 + 1) || !v6[2] )
      *(_DWORD *)(v7 + 4) = result;
    else
      *(_DWORD *)(v6[1] + 4) = result;
    if ( a3 == 5
      || !*((_BYTE *)off_116960 + 28 * a3 + 46)
      && ((v11 = *((_DWORD *)off_116960 + 52), result = v11 << 31, (v11 & 1) == 0)
       || *((unsigned __int8 *)off_116960 + 190) != a3) )
    {
      result = sub_11617C(a3);
      v10 = *(unsigned __int8 *)(*(_DWORD *)v9 + 1);
    }
  }
  else if ( a3 != 5
         && ((v8 = (int)off_116960, v7 = 8 * a3, *((_BYTE *)off_116960 + 28 * a3 + 46))
          || (result = *((unsigned __int8 *)off_116960 + 190), (*((_DWORD *)off_116960 + 52) & 1) != 0) && a3 == result) )
  {
    v12 = *(_DWORD *)off_116970;
    *((_DWORD *)off_116960 + 7 * a3 + 9) = v4;
    v10 = *(unsigned __int8 *)(v12 + 1);
  }
  else
  {
    result = sub_116574(v4, a3, v7, v8);
    v10 = *(unsigned __int8 *)(*(_DWORD *)off_116970 + 1);
  }
  if ( !v10 )
  {
    if ( (*(_DWORD *)(a2 + 56) & 0x200000) != 0 )
    {
      v6[1] = v4;
      v6[2] = 1;
    }
    else
    {
      v6[1] = 0;
      v6[2] = 0;
    }
  }
  *(_DWORD *)(dword_116958 + 84 * a3) = a2;
  return result;
}

