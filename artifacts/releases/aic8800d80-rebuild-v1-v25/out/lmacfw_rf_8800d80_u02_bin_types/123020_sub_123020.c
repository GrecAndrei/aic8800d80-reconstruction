// sub_123020 @ 0x123020, size 60 bytes
int  sub_123020(int a1)
{
  unsigned int v1; // r4
  unsigned int v3; // r4

  if ( a1 )
  {
    if ( a1 == 1 )
    {
      sub_1141EC();
      v1 = patch_apply_slot_36();
      msg_parse(dword_12305C, v1);
    }
    else
    {
      msg_parse(dword_123064);
      return -21;
    }
    return v1;
  }
  else
  {
    v3 = patch_apply_slot_36();
    msg_parse(dword_123060, v3);
    return v3;
  }
}

