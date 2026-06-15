// v23 annotated: sub_137170 @ 0x137170
// Original: 137170_sub_137170.c
// Primary struct: <unclustered>
//
// sub_137170 @ 0x137170, size 40 bytes
int sub_137170()
{
  int v0; // r0
  int value; // r0

  v0 = sub_12C92C(2051, 2, 4, 1u);
  sdio_buffer_prepare_n_4e8(v0);
  value = msg_get_value(4u);
  feature_guard_check(8, dword_137198, value);
  return 0;
}

