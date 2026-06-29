// sub_112EF4 @ 0x112ef4, size 80 bytes
// Doc: rf_init_helper_n0c [util]: RF init helper, copies 18 bytes and checks config byte
// rf_init_helper_n0c [util]: RF init helper, copies 18 bytes and checks config byte
uint32_t * sub_112EF4(int a1)
{
  uint32_t *v2; // r4
  int v3; // r0
  unsigned int v4; // r0

  switch ( a1 )
  {
    case 1:
      v2 = off_112F4C;
      v3 = sub_1282E8(off_112F4C, dword_112F50, 18);
      if ( *((uint8_t *)off_112F54 + 370) && sub_113B30(v3) )
      {
        v4 = rf_helper_sub_n_3b78();
        v2[2] = ((HIWORD(v4) << 16) + 0x10000) | (unsigned __int16)v4;
        return v2;
      }
      else
      {
        return off_112F4C;
      }
    case 6:
      return (uint32_t *)dword_112F48;
    case 15:
      return (uint32_t *)dword_112F44;
    default:
      return nullptr;
  }
}

