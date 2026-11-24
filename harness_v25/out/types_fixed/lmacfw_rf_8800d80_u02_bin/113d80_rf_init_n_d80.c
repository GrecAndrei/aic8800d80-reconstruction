// rf_init_n_d80 @ 0x113d80, size 120 bytes
// Doc: rf_init_n_d80 [rf]: RF subsystem initialization with param 0xf
// rf_init_n_d80 [rf]: RF subsystem initialization with param 0xf
int __fastcall rf_init_n_d80(unsigned int a1, int a2)
{
  int v4; // r4
  unsigned int v5; // r4

  if ( (sub_113A44(0xFu) & 0x10000) != 0 )
    return -2;
  v4 = sub_113A44(0xCu);
  if ( (unsigned __int16)sub_113A44(0xDu) | v4 )
  {
    v5 = sub_113A44(0xDu);
    if ( (HIWORD(v5) << 16) | sub_113A44(0xEu) )
    {
      return -1;
    }
    else
    {
      host_reg_wait_set(0xDu, a1 << 16);
      host_reg_wait_set(0xEu, HIWORD(a1) | (a2 << 16));
      return 0;
    }
  }
  else
  {
    host_reg_wait_set(0xCu, a1);
    host_reg_wait_set(0xDu, a2);
    return 1;
  }
}

