// log_system_init @ 0x10f2b0, size 192 bytes
// Doc: log_system_init [util]: Initialize the firmware logging subsystem
// log_system_init [util]: Initialize the firmware logging subsystem
int log_system_init()
{
  unsigned __int8 **v0; // r4
  int v1; // r3
  _DWORD *v2; // r3
  int v3; // r2
  __int64 v4; // r0
  int v5; // r3
  _DWORD *v6; // r3
  int v7; // r2
  _DWORD *v8; // r3
  int v9; // r2
  int (__fastcall **v10)(int); // r4
  int v11; // r0
  int v12; // r2
  int (__fastcall **v13)(int); // r5
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int (__fastcall **v17)(int); // r5
  int v18; // r0
  int v19; // r0
  int v20; // r0
  int v21; // r0

  v0 = (unsigned __int8 **)off_10F370;
  v1 = **(unsigned __int8 **)off_10F370;
  switch ( v1 )
  {
    case 1:
      v8 = off_10F374;
      v9 = dword_10F38C;
      *((_DWORD *)off_10F374 + 2) = dword_10F388;
      v8[3] = v9;
      break;
    case 2:
      v2 = off_10F374;
      v3 = dword_10F37C;
      *((_DWORD *)off_10F374 + 6) = dword_10F378;
      v2[7] = v3;
      break;
    case 3:
      v6 = off_10F374;
      v7 = dword_10F384;
      *((_DWORD *)off_10F374 + 8) = dword_10F380;
      v6[9] = v7;
      break;
  }
  sub_10F1D4();
  v4 = sub_10F208();
  v5 = **v0;
  if ( v5 == 1 )
  {
    v17 = (int (__fastcall **)(int))off_10F374;
    *(_DWORD *)off_10F390 = dword_10F3A4;
    v18 = log_free_dispatch_n1dc(v4, HIDWORD(v4));
    v19 = sub_11007C(v18);
    v20 = log_free_dispatch_n274(v19);
    sub_10FFE4(v20);
    v21 = v17[2](dword_10F398);
    LODWORD(v4) = v17[3](v21);
    v5 = **v0;
  }
  if ( v5 == 2 )
  {
    v12 = dword_10F3A0;
    *(_DWORD *)off_10F390 = dword_10F39C;
    v13 = (int (__fastcall **)(int))off_10F374;
    *(_WORD *)(v12 + 8244) = 0;
    v14 = fw_sub_1213824_load_struct_call();
    sub_113670(v14);
    v15 = v13[6](dword_10F398);
    v16 = v13[7](v15);
    LODWORD(v4) = sub_113FC4(v16);
    v5 = **v0;
  }
  if ( v5 == 3 )
  {
    v10 = (int (__fastcall **)(int))off_10F374;
    *(_DWORD *)off_10F390 = dword_10F394;
    bt_fw_init_handler_0();
    v11 = v10[8](dword_10F398);
    LODWORD(v4) = v10[9](v11);
  }
  return v4;
}

