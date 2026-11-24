// sub_142670 @ 0x142670, size 58 bytes
int __fastcall sub_142670(int a1, unsigned int a2)
{
  if ( **(__int16 **)off_1426AC < 0 && *(unsigned __int8 *)(a2 + 8) == 255 )
    sub_12F694(dword_1426B4, dword_1426B0, 50);
  if ( (*(_WORD *)(a2 + 2) & 0xFC) == 0xD0 )
    bt_hci_cmd_dispatch_n_dc(a2);
  return 0;
}

