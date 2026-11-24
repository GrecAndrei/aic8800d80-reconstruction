// log_system_init_f6a4 @ 0x10f6a4, size 192 bytes
// Doc: log_system_init_f6a4 [util]: Initialize firmware logging subsystem
// log_system_init_f6a4 [util]: Initialize firmware logging subsystem
int log_system_init_f6a4()
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
  void *v9; // r2
  int (__fastcall **v10)(int); // r4
  int v11; // r0
  int v12; // r2
  int (__fastcall **v13)(int); // r5
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int (__fastcall **v17)(int); // r5
  int v18; // r0
  int inited; // r0
  int v20; // r0
  int v21; // r0

  v0 = (unsigned __int8 **)off_10F764;
  v1 = **(unsigned __int8 **)off_10F764;
  switch ( v1 )
  {
    case 1:
      v8 = off_10F768;
      v9 = off_10F780;
      *((_DWORD *)off_10F768 + 2) = off_10F77C;
      *(_DWORD *)(v8 + 0xc) = v9;
      break;
    case 2:
      v2 = off_10F768;
      v3 = dword_10F770;
      *((_DWORD *)off_10F768 + 6) = dword_10F76C;
      *(_DWORD *)(v2 + 0x1c) = v3;
      break;
    case 3:
      v6 = off_10F768;
      v7 = dword_10F778;
      *((_DWORD *)off_10F768 + 8) = dword_10F774;
      *(_DWORD *)(v6 + 0x24) = v7;
      break;
  }
  sub_10F5C8();
  v4 = sub_10F5FC();
  v5 = **v0;
  if ( v5 == 1 )
  {
    v17 = (int (__fastcall **)(int))off_10F768;
    *(_DWORD *)off_10F784 = dword_10F798;
    v18 = patch_apply_n422(v4, HIDWORD(v4));
    inited = rf_lmac_init_n114(v18);
    v20 = sub_11016C(inited);
    log_free_pool_dispatch2_n4ac(v20);
    v21 = *(_DWORD *)(v17 + 0x8)(dword_10F78C);
    LODWORD(v4) = *(_DWORD *)(v17 + 0xc)(v21);
    v5 = **v0;
  }
  if ( v5 == 2 )
  {
    v12 = dword_10F794;
    *(_DWORD *)off_10F784 = dword_10F790;
    v13 = (int (__fastcall **)(int))off_10F768;
    *(_WORD *)(v12 + 8244) = 0;
    v14 = sub_113280();
    sub_1130CC(v14);
    v15 = *(_DWORD *)(v13 + 0x18)(dword_10F78C);
    v16 = *(_DWORD *)(v13 + 0x1c)(v15);
    LODWORD(v4) = rf_chan_set_mask(v16);
    v5 = **v0;
  }
  if ( v5 == 3 )
  {
    v10 = (int (__fastcall **)(int))off_10F768;
    *(_DWORD *)off_10F784 = dword_10F788;
    sub_113760();
    v11 = *(_DWORD *)(v10 + 0x20)(dword_10F78C);
    LODWORD(v4) = *(_DWORD *)(v10 + 0x24)(v11);
  }
  return v4;
}

