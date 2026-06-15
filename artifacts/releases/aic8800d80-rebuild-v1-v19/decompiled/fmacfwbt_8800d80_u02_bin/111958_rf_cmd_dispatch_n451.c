// rf_cmd_dispatch_n451 @ 0x111958, size 88 bytes
// Doc: message_dispatch_n_4fe [ipc]: Dispatch incoming host message to handler
// message_dispatch_n_4fe [ipc]: Dispatch incoming host message to handler
int __fastcall rf_cmd_dispatch_n451(int result, int a2)
{
  int *v2; // r4
  int v3; // r5
  int v4; // r3
  char v5; // r2
  _DWORD *v6; // r2

  v2 = (int *)off_1119B4;
  v3 = *(_DWORD *)rf_bus_mark_n2d0;
  v4 = *(_DWORD *)off_1119B4;
  *((_WORD *)rf_bus_setup_n_3a0 + 5) = a2;
  if ( a2 == 64 )
    v5 = -54;
  else
    v5 = -50;
  *(_DWORD *)v4 = -1073741824;
  *(_DWORD *)(v4 + 4) = v3;
  *(_BYTE *)(v4 + 3) = v5;
  *(_WORD *)v4 = a2;
  if ( result && a2 )
  {
    result = sub_14380C(v3, result, a2);
    v4 = *v2;
  }
  v6 = rf_bus_mark_n2dc;
  *(_BYTE *)(v4 + 3) &= 0x3Fu;
  v6[578] = v6[578];
  v6[581] = v4;
  v6[576] |= 0x84000000;
  return result;
}

