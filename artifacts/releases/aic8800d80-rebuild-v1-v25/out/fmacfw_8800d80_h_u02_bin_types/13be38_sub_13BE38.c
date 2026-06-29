// sub_13BE38 @ 0x13be38, size 52 bytes
int sub_13BE38()
{
  uint32_t *v0; // r4
  int result; // r0
  unsigned int v2; // r0

  v0 = off_13BE6C;
  if ( !*((uint32_t *)off_13BE6C + 6)
    || (result = *((unsigned __int8 *)sub_12D190((int)off_13BE6C + 24) + 26), result == 33) )
  {
    if ( v0[8] )
      return 33;
    v2 = (unsigned __int8)sub_13B938((int **)dword_13BE70);
    if ( (unsigned __int8)v2 == 33 )
    {
      return 33;
    }
    else
    {
      sub_13BDB8(v2);
      return 33;
    }
  }
  return result;
}

