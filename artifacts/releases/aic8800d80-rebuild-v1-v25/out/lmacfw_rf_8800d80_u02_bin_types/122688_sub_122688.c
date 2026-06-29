// sub_122688 @ 0x122688, size 134 bytes
int  sub_122688(int result, int a2)
{
  int v2; // r4
  unsigned __int8 v4[8]; // [sp+4h] [bp-8h] BYREF

  v2 = HIBYTE(*(uint32_t *)off_122710) & 2;
  if ( result )
  {
    if ( result == 1 )
    {
      if ( (unsigned int)(a2 - 1) > 6 )
      {
        msg_parse(dword_122724);
        return -12;
      }
      else if ( v2 )
      {
        return 0;
      }
      else
      {
        v4[0] = a2;
        *(uint16_t *)&v4[1] = 0;
        v4[3] = 0;
        rf_setup_param_n5ac((int)v4);
        msg_parse(dword_122718, a2);
        return a2;
      }
    }
    else
    {
      msg_parse(dword_122720);
      return -21;
    }
  }
  else if ( !v2 )
  {
    *(uint32_t *)v4 = 0;
    if ( sub_1145A0((int)v4) )
    {
      msg_parse(dword_12271C);
      return 0;
    }
    else
    {
      msg_parse(dword_122714, v4[0]);
      return v4[0];
    }
  }
  return result;
}

