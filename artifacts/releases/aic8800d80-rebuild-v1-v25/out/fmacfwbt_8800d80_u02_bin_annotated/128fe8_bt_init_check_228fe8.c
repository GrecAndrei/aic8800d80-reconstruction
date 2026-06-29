// fwstruct annotate: 128fe8_bt_init_check_228fe8.c
// bt_init_check_228fe8 @ 0x128fe8, size 186 bytes
// Doc: bt_init_check_228fe8 [bt]: Bluetooth init/state check loading config pointers
// bt_init_check_228fe8 [bt]: Bluetooth init/state check loading config pointers
void __fastcall bt_init_check_228fe8(int a1)
{
  _BYTE *v1; // r5
  __int64 v3; // r2
  BOOL v4; // r0
  _DWORD *v5; // r3
  int v6; // r2
  int v7; // r1
  int v8; // r0

  v1 = off_1290A8;
  LODWORD(v3) = *((_DWORD *)off_1290AC + 126);
  HIDWORD(v3) = *((_DWORD *)off_1290A8 + 1) & 0x20;
  if ( **(_BYTE **)off_1290A4 == 1 )
  {
    if ( v3 )
      v4 = 0;
    else
      v4 = state_flag_check() != 0;
  }
  else
  {
    v4 = v3 == 0;
  }
  if ( *(_BYTE *)(a1 + 149) )
  {
    if ( !**(_BYTE **)off_1290B0 || !*(_BYTE *)(a1 + 108) )
    {
LABEL_6:
      v1[29] = 0;
      *(_DWORD *)(a1 + 4) = 0;
      return;
    }
LABEL_18:
    v5 = off_1290BC;
    v6 = *(_DWORD *)off_1290B8;
    *((_DWORD *)v1 + 5) = a1;
    v7 = *(unsigned __int16 *)(v6 + 54);
    v8 = dword_1290C0;
    v1[29] = 1;
    timestamp_update_4f60(v8, v7 + v5[4]);
    return;
  }
  if ( !**(_BYTE **)off_1290B0 || !*(_BYTE *)(a1 + 108) )
    goto LABEL_6;
  if ( !v4 || (*(_DWORD *)off_1290B4 & 0x2000000) == 0 && !v1[36] )
    goto LABEL_18;
  if ( v1[29] == 5 )
  {
    *(_DWORD *)(a1 + 4) &= ~2u;
    v1[29] = 0;
  }
  if ( v1[28] )
    sub_128F88();
  else
    v1[29] = 0;
}

