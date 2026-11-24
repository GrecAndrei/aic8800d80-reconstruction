// fw_sub_1213824_load_struct_call @ 0x113824, size 24 bytes
int __fastcall fw_sub_1213824_load_struct_call(int a1)
{
  _DWORD *v1; // r2
  _WORD *v2; // r1

  v1 = off_11383C;
  v2 = off_113840;
  *((_DWORD *)off_11383C + 2) = a1;
  *(_DWORD *)(v1 + 0xc) = 0;
  *(_DWORD *)(v1 + 0x10) = 0;
  *(_DWORD *)(v1 + 0x14) = 0;
  *v1 = 0;
  *(_DWORD *)(v1 + 0x4) = 0;
  *(_DWORD *)(v2 + 0x18) = 0;
  return 1;
}

