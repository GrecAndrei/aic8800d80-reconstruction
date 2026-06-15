// v23 annotated: bt_subsystem_init_n_ef0 @ 0x118ef0
// Original: 118ef0_bt_subsystem_init_n_ef0.c
// Primary struct: <unclustered>
//
// bt_subsystem_init_n_ef0 @ 0x118ef0, size 228 bytes
// Doc: bt_subsystem_init_n_ef0 [bt]: Initialize Bluetooth subsystem tables and constants
// bt_subsystem_init_n_ef0 [bt]: Initialize Bluetooth subsystem tables and constants
int __fastcall bt_subsystem_init_n_ef0(int a1)
{
  int v2; // r4
  _DWORD *v3; // r6
  _DWORD *v4; // r5
  int v5; // r11
  int v6; // r10
  int v7; // r9
  int v8; // r8
  _DWORD *v9; // r6
  int v10; // r8
  int v11; // r0
  int *v12; // r5
  int v13; // r7
  int result; // r0

  v2 = dword_118FD8;
  v3 = (_DWORD *)dword_118FDC;
  v4 = (_DWORD *)dword_118FE0;
  v5 = dword_118FF0;
  v6 = dword_118FF4;
  v7 = dword_118FD4;
  bt_xtal_init_check(dword_118FD4);
  bt_xtal_init_check(v7 + 8);
  v8 = v2 + 400;
  do
  {
    if ( !a1 || !*(_BYTE *)(v2 + 97) )
    {
      memset_thunk((int *)v2, 0, 0x64u);
      *(_DWORD *)(v2 + 44) = v3 + 11;
      *(_DWORD *)(v2 + 72) = v3;
      *(_DWORD *)(v2 + 76) = v4;
      v4[13] = 0;
      v4[14] = 0;
      v3[24] = 0;
      v3[25] = 0;
      v4[3] = v5;
      v3[11] = v6;
      *(_BYTE *)(v2 + 96) = 0;
      v4[10] = 0;
      v4[15] = 0;
      v4[7] = v3 + 27;
      list_push_tail(v7);
    }
    v2 += 100;
    v3 += 155;
    v4 += 20;
  }
  while ( v2 != v8 );
  v9 = off_118FE4;
  v10 = dword_118FF4;
  *(_DWORD *)off_118FE4 = dword_118FF4;
  v9[13] = 0;
  v9[14] = 0;
  v9[15] = 0;
  v9[1] = sub_101954() << 14;
  v11 = sdio_buffer_prepare_n_32a();
  v12 = (int *)off_118FE8;
  v13 = dword_118FEC;
  v9[2] = v11;
  v9[4] = v13;
  v9[5] = 1024;
  v9[6] = 0;
  v9[7] = 0;
  v9[3] = 0;
  v9[8] = 0;
  *v12 = v10;
  v9[10] = 0;
  v9[11] = 0;
  v12[13] = 0;
  v12[14] = 0;
  v9[12] = 0;
  v12[15] = 0;
  v12[1] = sub_101954() << 14;
  result = sdio_buffer_prepare_n_32a();
  v12[2] = result;
  v12[3] = 0;
  v12[6] = 0;
  v12[7] = 0;
  v12[10] = 0;
  v12[11] = 0;
  v12[4] = v13;
  v12[8] = 0;
  v12[12] = 0;
  v12[5] = 4;
  return result;
}

