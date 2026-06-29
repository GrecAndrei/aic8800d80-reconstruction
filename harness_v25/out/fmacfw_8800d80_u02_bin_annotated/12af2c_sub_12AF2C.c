// fwstruct annotate: 12af2c_sub_12AF2C.c
// sub_12AF2C @ 0x12af2c, size 48 bytes
// Doc: sub_122AF2C [util]: Initialization helper calling sub_122CE88 with table pointers
// sub_122AF2C [util]: Initialization helper calling sub_122CE88 with table pointers
int __fastcall sub_12AF2C(int a1, int a2, int a3, int a4)
{
  int value; // r4

  value = msg_get_value(2);
  feature_guard_check(4, dword_12AF60);
  if ( value )
    *((_BYTE *)off_12AF64 + 11) = 1;
  else
    ipc_msg_alloc_n0(1, a4);
  return 0;
}

