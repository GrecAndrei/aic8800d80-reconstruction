// sub_13BF78 @ 0x13bf78, size 52 bytes
// Doc: sub_123BF78 [unknown]: Helper loading state struct pointer
// sub_123BF78 [unknown]: Helper loading state struct pointer
int sub_13BF78()
{
  uint32_t *v0; // r4
  int result; // r0
  unsigned int v2; // r0

  v0 = off_13BFAC;
  if ( !*((uint32_t *)off_13BFAC + 6)
    || (result = *((unsigned __int8 *)rf_bus_mark_n100_d2d0((int)off_13BFAC + 24) + 26), result == 33) )
  {
    if ( v0[8] )
      return 33;
    v2 = (unsigned __int8)sub_13BA78((int **)dword_13BFB0);
    if ( (unsigned __int8)v2 == 33 )
    {
      return 33;
    }
    else
    {
      sub_13BEF8(v2);
      return 33;
    }
  }
  return result;
}

