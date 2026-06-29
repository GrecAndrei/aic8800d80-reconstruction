// sub_11BA4C @ 0x11ba4c, size 22 bytes
int  sub_11BA4C(int a1, int a2, int a3)
{
  int result; // r0

  rf_link_state_check(a1, a2, a3);
  result = sub_11B740();
  if ( !result )
    return sub_11B9E0();
  return result;
}

