// v23 annotated: fw_struct_init_helper @ 0x1107a0
// Original: 1107a0_fw_struct_init_helper.c
// Primary struct: <unclustered>
//
// fw_struct_init_helper @ 0x1107a0, size 52 bytes
// Doc: fw_struct_init_helper [util]: Initialize firmware control structure with zeros and arguments
// fw_struct_init_helper [util]: Initialize firmware control structure with zeros and arguments
int __fastcall fw_struct_init_helper(int a1)
{
  _DWORD *v1; // r2
  _DWORD *v2; // r1

  v1 = off_1107D4;
  v2 = off_1107D8;
  *(_DWORD *)off_1107D4 = 0;
  v1[1] = 0;
  v1[2] = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v2 = 0;
  v2[1] = 0;
  v2[4] = 0;
  v2[5] = 0;
  *((_WORD *)v2 + 6) = 0;
  v2[2] = 0;
  *((_BYTE *)v2 + 14) = 0;
  *((_WORD *)v2 + 14) = 0;
  v2[6] = 0;
  *((_BYTE *)v2 + 30) = 0;
  sub_11063C((int)v1, (int)v2);
  return 1;
}

