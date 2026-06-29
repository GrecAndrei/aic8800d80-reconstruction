// sub_111B6C @ 0x111b6c, size 42 bytes
// Doc: rf_bus_setup_n_1e2 [rf]: Configure RF bus, check a status bit and load base address 0x40200900
// rf_bus_setup_n_1e2 [rf]: Configure RF bus, check a status bit and load base address 0x40200900
int  sub_111B6C(int a1, int a2)
{
  uint32_t *v2; // r0
  int v4; // r0

  if ( a2 )
  {
    if ( a1 == 1 )
      v4 = dword_111B98;
    else
      v4 = dword_111B9C;
    return (*(uint32_t *)(v4 + 32 * a2) >> 21) & 1;
  }
  else
  {
    if ( a1 == 1 )
      v2 = (uint32_t *)dword_111B98;
    else
      v2 = (uint32_t *)dword_111B9C;
    return (*v2 >> 21) & 1;
  }
}

