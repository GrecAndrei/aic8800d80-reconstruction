// rf_status_poll @ 0x113c98, size 104 bytes
// Doc: rf_status_poll [rf]: Poll and update RF status register state
// rf_status_poll [rf]: Poll and update RF status register state
int __fastcall rf_status_poll(unsigned int a1, int a2)
{
  int v4; // r4
  unsigned int v5; // r4

  v4 = sub_113A44(7u);
  if ( (unsigned __int16)sub_113A44(8u) | v4 )
  {
    v5 = sub_113A44(8u);
    if ( (HIWORD(v5) << 16) | sub_113A44(9u) )
    {
      return -1;
    }
    else
    {
      host_reg_wait_set(8u, a1 << 16);
      host_reg_wait_set(9u, HIWORD(a1) | (a2 << 16));
      return 0;
    }
  }
  else
  {
    host_reg_wait_set(7u, a1);
    host_reg_wait_set(8u, a2);
    return 1;
  }
}

