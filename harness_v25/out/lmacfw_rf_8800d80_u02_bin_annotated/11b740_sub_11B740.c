// fwstruct annotate: 11b740_sub_11B740.c
// sub_11B740 @ 0x11b740, size 182 bytes
int sub_11B740()
{
  _DWORD *v0; // r6
  int v1; // r5
  int v2; // r7
  int *v3; // r4
  char v4; // r2
  int v5; // r8
  _BYTE *v6; // r10
  int v7; // r2
  int v8; // r0
  char v9; // r11
  int v10; // r4
  int v11; // r5
  int v12; // r4

  v0 = off_11B7F8;
  v1 = *((_DWORD *)off_11B7F8 + 10);
  v2 = *((unsigned __int8 *)off_11B7F8 + 89);
  if ( !v1 )
    return 0;
  v3 = *((int **)off_11B800 + 2);
  v4 = *((_BYTE *)off_11B7F8 + 89);
  *(_DWORD *)off_11B7FC |= 4u;
  if ( v3 )
  {
    v5 = dword_11B804;
    v6 = off_11B808;
    do
    {
      while ( 1 )
      {
        if ( v1 == v3[18] )
        {
          v7 = *((unsigned __int8 *)v3 + 94);
          if ( !*((_BYTE *)v3 + 94) )
          {
            if ( *((_BYTE *)v3 + 96) )
            {
              v8 = *((unsigned __int8 *)v3 + 102);
              if ( v8 != 255 )
                break;
            }
          }
        }
        v3 = (int *)*v3;
        if ( !v3 )
          goto LABEL_12;
      }
      v9 = *(_BYTE *)(v1 + 16);
      *(_BYTE *)(v1 + 16) = 6;
      if ( !rf_channel_set_n6838(v8, v5, v7) )
      {
        ++v2;
        *v6 = 1;
      }
      *(_BYTE *)(v1 + 16) = v9;
      v3 = (int *)*v3;
    }
    while ( v3 );
LABEL_12:
    v4 = v2;
  }
  v10 = *((unsigned __int8 *)v0 + 89);
  v11 = v0[11];
  *((_BYTE *)v0 + 89) = v4;
  v12 = v2 - v10;
  if ( !v11 )
  {
    mmio_init_clock_gate_n121();
    if ( v2 )
    {
      v12 = 0;
      --*((_BYTE *)v0 + 89);
      return v12;
    }
    return 0;
  }
  if ( !v12 )
    return v12;
  *(_BYTE *)(v11 + 16) = 3;
  mmio_init_clock_gate_n121();
  return v12;
}

