// v23 annotated: sub_131820 @ 0x131820
// Original: 131820_sub_131820.c
// Primary struct: bt_hci_cmd (cluster 4, 22 funcs)
// Fields: ogf=0x0, ocf=0x1
//
// sub_131820 @ 0x131820, size 118 bytes
int __fastcall sub_131820(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v4; // r0
  int v7; // r4
  int v8; // r1
  int v9; // r7
  _BYTE *v10; // r0

  v4 = *a2;
  if ( a2[1] )
  {
    v7 = dword_131898 + 696 * v4;
    v8 = *(unsigned __int8 *)(v7 + 34);
    v9 = *(unsigned __int8 *)(dword_13189C + 1320 * v8 + 106);
    *(_BYTE *)(v7 + 52) = 2;
    if ( !v9 && ((*((_DWORD *)off_1318A0 + 1) >> v8) & 1) != 0 )
    {
      v10 = (_BYTE *)rf_bus_setup_n3a8(5145, 5, 6, 2u);
      *v10 = 0;
      v10[1] = *(_BYTE *)(v7 + 34);
      sub_12CBB4((int)v10);
    }
  }
  else
  {
    *(_BYTE *)(dword_131898 + 696 * v4 + 52) = 1;
  }
  message_dispatch_n84(5125, a4, a3);
  return 0;
}

