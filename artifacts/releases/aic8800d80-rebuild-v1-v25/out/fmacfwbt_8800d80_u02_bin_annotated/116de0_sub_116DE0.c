// fwstruct annotate: 116de0_sub_116DE0.c
// sub_116DE0 @ 0x116de0, size 248 bytes
int __fastcall sub_116DE0(int result, int a2, int a3)
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
    v6 = (int *)dword_116EEC;
  else
    v6 = (int *)(dword_116ED8 + 84 * a3);
  v7 = *v6;
  v8 = **(__int16 **)off_116EDC;
  if ( v8 < 0 && v7 == result )
    return sub_12F630(dword_116EE8, dword_116EE4, 1972, v8);
  if ( v7 )
  {
    v9 = off_116EF0;
    v10 = *(unsigned __int8 *)(*(_DWORD *)off_116EF0 + 1);
    if ( *(_BYTE *)(*(_DWORD *)off_116EF0 + 1) || !v6[2] )
      *(_DWORD *)(v7 + 4) = result;
    else
      *(_DWORD *)(v6[1] + 4) = result;
    if ( a3 == 5
      || !*((_BYTE *)off_116EE0 + 28 * a3 + 46)
      && ((v11 = *((_DWORD *)off_116EE0 + 52), result = v11 << 31, (v11 & 1) == 0)
       || *((unsigned __int8 *)off_116EE0 + 190) != a3) )
    {
      result = sub_1166FC(a3);
      v10 = *(unsigned __int8 *)(*(_DWORD *)v9 + 1);
    }
  }
  else if ( a3 != 5
         && ((v8 = (int)off_116EE0, v7 = 8 * a3, *((_BYTE *)off_116EE0 + 28 * a3 + 46))
          || (result = *((unsigned __int8 *)off_116EE0 + 190), (*((_DWORD *)off_116EE0 + 52) & 1) != 0) && a3 == result) )
  {
    v12 = *(_DWORD *)off_116EF0;
    *((_DWORD *)off_116EE0 + 7 * a3 + 9) = v4;
    v10 = *(unsigned __int8 *)(v12 + 1);
  }
  else
  {
    result = bt_chan_dispatch_n_6f0(v4, a3, v7, v8);
    v10 = *(unsigned __int8 *)(*(_DWORD *)off_116EF0 + 1);
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
  *(_DWORD *)(dword_116ED8 + 84 * a3) = a2;
  return result;
}

