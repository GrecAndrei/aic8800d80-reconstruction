// fwstruct annotate: 1258c0_sub_1258C0.c
// sub_1258C0 @ 0x1258c0, size 258 bytes
void sub_1258C0()
{
  int v0; // r4
  _BYTE *v1; // r6
  int v2; // r5
  _DWORD *v3; // r2
  int v4; // r7
  _BYTE *v5; // r8
  char v6; // r9
  int v7; // r10
  int status; // r0
  int v9; // r3

  v0 = *((_DWORD *)off_1259C8 + 2);
  v1 = off_1259CC;
  if ( **(__int16 **)off_1259C4 < 0 && *((_DWORD *)off_1259CC + 1) )
  {
    sub_12F46C(dword_1259D8, dword_1259D4, 1074);
    v2 = (unsigned __int8)v1[9];
    if ( v1[9] )
      goto LABEL_20;
  }
  else
  {
    v2 = *((unsigned __int8 *)off_1259CC + 9);
    if ( *((_BYTE *)off_1259CC + 9) )
    {
LABEL_20:
      v1[8] = 1;
      return;
    }
  }
  v3 = off_1259D0;
  v1[8] = v2;
  v4 = 32 * *v3;
  if ( v0 )
  {
    v5 = off_1259DC;
    v6 = v2;
    v7 = 1;
    while ( 1 )
    {
      if ( *(_BYTE *)(v0 + 106) != 2
        || !*(_BYTE *)(v0 + 226)
        || !*(_BYTE *)(v0 + 108)
        || *(unsigned __int8 *)(v0 + 225) != *(unsigned __int8 *)(v0 + 224) )
      {
        goto LABEL_6;
      }
      if ( scan_chan_lookup_n_5e8(v0) )
        ++*v5;
      if ( v7 && (unsigned int)(v4 - 50) > 0xBB6 )
      {
        sub_128490(v0);
LABEL_16:
        *v5 = v6;
        v0 = *(_DWORD *)v0;
        v7 = 0;
        v2 = 1;
        if ( !v0 )
          return;
      }
      else
      {
        if ( v2 )
          goto LABEL_16;
        v7 = sub_128490(v0);
        if ( v7 )
        {
          *(_BYTE *)(v0 + 144) = *(_BYTE *)(v0 + 107);
          *(_BYTE *)(v0 + 145) = -1;
          status = rf_param_get_status(v0 + 116, 4);
          v9 = *((_DWORD *)v1 + 1);
          if ( status )
            *((_DWORD *)v1 + 1) = ++v9;
          if ( v9 == 1 )
            sub_121C08();
          v7 = 0;
        }
        else
        {
          *v5 = 0;
        }
LABEL_6:
        v0 = *(_DWORD *)v0;
        if ( !v0 )
          return;
      }
    }
  }
}

