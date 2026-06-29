// fwstruct annotate: 1371d0_bt_cmd_dispatch_setup.c
// bt_cmd_dispatch_setup @ 0x1371d0, size 82 bytes
// Doc: bt_cmd_dispatch_setup [bt]: Initializes BT command slots/queue at f08/f0a offsets
// bt_cmd_dispatch_setup [bt]: Initializes BT command slots/queue at f08/f0a offsets
int __fastcall bt_cmd_dispatch_setup(int a1, int a2, int a3, int a4)
{
  _WORD *v4; // r2
  __int64 v6; // r0
  _BYTE *v8; // r0
  int v9; // r0

  v4 = off_137224;
  *((_WORD *)off_137224 + 1924) = a4;
  v4[1925] = 0;
  v6 = *(_QWORD *)(a2 + 352);
  *(_DWORD *)v4 = a2;
  *((_DWORD *)v4 + 963) = v6;
  v4[1928] = WORD2(v6);
  if ( a4 == 11 || a4 == 6 )
  {
    sub_13876C(v6);
    return 1;
  }
  else
  {
    v8 = (_BYTE *)rf_bus_setup_n3a8(4105, a4, 4, 2u);
    v8[1] = 1;
    *v8 = *(_BYTE *)(a2 + 366);
    v9 = sub_12CBB4((int)v8);
    sub_13876C(v9);
    return 1;
  }
}

