// fwstruct annotate: 123164_bt_hci_cmd_alloc_n_12c.c
// bt_hci_cmd_alloc_n_12c @ 0x123164, size 120 bytes
// Doc: bt_hci_cmd_alloc_n_12c [bt]: Allocate and initialize an HCI command buffer (tag 0x74)
// bt_hci_cmd_alloc_n_12c [bt]: Allocate and initialize an HCI command buffer (tag 0x74)
int __fastcall bt_hci_cmd_alloc_n_12c(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r4
  unsigned __int16 v5; // r3
  unsigned int v6; // r2
  int v7; // r0
  unsigned int v9; // [sp+0h] [bp-14h] BYREF
  unsigned int v10; // [sp+4h] [bp-10h] BYREF
  unsigned int v11[3]; // [sp+8h] [bp-Ch] BYREF

  v9 = 0;
  v10 = 0;
  v4 = (_BYTE *)rf_bus_setup_n3a8(116, a4, a3, 6);
  if ( (*(_DWORD *)off_1231DC & 0x2000000) != 0 )
  {
    sub_114F00(&v9, &v10);
    v6 = v9;
    v5 = v10;
  }
  else
  {
    memset(v11, 0, 6);
    patch_apply_n_40((int)v11);
    v5 = __rev16(LOWORD(v11[0]));
    v6 = bswap32(*(unsigned int *)((char *)v11 + 2));
    v9 = v6;
    v10 = v5;
  }
  v4[1] = v5;
  v4[5] = v6;
  *v4 = HIBYTE(v5);
  v4[3] = BYTE2(v6);
  v4[2] = HIBYTE(v6);
  v7 = dword_1231E0;
  v4[4] = BYTE1(v6);
  sub_12ECB0(v7, HIBYTE(v5), (unsigned __int8)v6);
  sub_12CBB4(v4);
  return 0;
}

