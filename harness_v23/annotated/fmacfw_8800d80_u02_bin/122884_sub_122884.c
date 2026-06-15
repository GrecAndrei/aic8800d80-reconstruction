// v23 annotated: sub_122884 @ 0x122884
// Original: 122884_sub_122884.c
// Primary struct: phy_reg_param (cluster 13, 6 funcs)
// Fields: addr=0x0, status=0x6a
//
// sub_122884 @ 0x122884, size 76 bytes
// Doc: sub_122288E [unknown]: Unknown helper in fmacfw
// sub_122288E [unknown]: Unknown helper in fmacfw
char *sub_122884()
{
  int v0; // r4

  v0 = *(_DWORD *)off_1228D4 & 0x1800000;
  if ( **(__int16 **)off_1228D0 < 0 && v0 == 25165824 )
    sub_12F46C(dword_1228E4, dword_1228E0, 1308);
  clear_flags(v0);
  if ( *((_BYTE *)off_1228D8 + 18) )
    return (char *)sub_1210F8();
  else
    return sub_122794(*((char **)off_1228DC + 8));
}

