// fwstruct annotate: 113824_fw_sub_1213824_load_struct_call.c
// fw_sub_1213824_load_struct_call @ 0x113824, size 24 bytes
int __fastcall fw_sub_1213824_load_struct_call(int a1)
{
  _DWORD *v1; // r2
  _WORD *v2; // r1

  v1 = off_11383C;
  v2 = off_113840;
  *((_DWORD *)off_11383C + 2) = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v1 = 0;
  v1[1] = 0;
  v2[6] = 0;
  return 1;
}

