// sub_12BEB0 @ 0x12beb0, size 402 bytes
int  sub_12BEB0(int result, int a2, int a3, int a4)
{
  int v4; // r1
  int v5; // r4
  int v6; // r3
  int v7; // r5

  v4 = *(uint32_t *)off_12C044;
  v5 = *(uint32_t *)off_12C048 & *(uint32_t *)off_12C044;
  v6 = dword_12C04C & v5;
  *((uint32_t *)off_12C044 + 1) = v5;
  if ( v6 )
    result = sub_12CFC4(0x1000000);
  if ( (dword_12C050 & v5) != 0 )
    result = sub_12CFC4(0x800000);
  if ( (v5 & 4) != 0 )
    result = sub_12B400();
  if ( (v5 & 8) != 0 )
    result = sub_12BD4C(result, v4);
  if ( (v5 & 0x10000000) != 0 )
  {
    v7 = *(uint32_t *)off_12C060;
    *((uint8_t *)off_12C064 + 30) |= *(uint8_t *)off_12C060 & 0x3F;
    result = sub_12CFC4(0x40000);
    *(uint32_t *)off_12C068 = v7;
  }
  if ( **(__int16 **)off_12C054 < 0 )
  {
    if ( (v5 & 0x400000) != 0 )
    {
      return sub_12F2C8(dword_12C06C, dword_12C058, 847, a4);
    }
    else if ( (v5 & 0x200000) != 0 )
    {
      return sub_12F2C8(dword_12C070, dword_12C058, 848, a4);
    }
    else if ( (v5 & 0x40) != 0 )
    {
      return sub_12F2C8(dword_12C074, dword_12C058, 849, a4);
    }
    else if ( (v5 & 0x100) != 0 )
    {
      return sub_12F2C8(dword_12C078, dword_12C058, 850, a4);
    }
    else if ( (v5 & 0x1000) != 0 )
    {
      return sub_12F2C8(dword_12C07C, dword_12C058, 851, a4);
    }
    else if ( (v5 & 0x2000) != 0 )
    {
      return sub_12F2C8(dword_12C080, dword_12C058, 852, a4);
    }
    else if ( (v5 & 0x4000) != 0 )
    {
      return sub_12F2C8(dword_12C084, dword_12C058, 853, a4);
    }
    else if ( (v5 & 0x8000) != 0 )
    {
      return sub_12F2C8(dword_12C088, dword_12C058, 854, a4);
    }
    else if ( (v5 & 0x10000) != 0 )
    {
      return sub_12F2C8(dword_12C08C, dword_12C058, 855, a4);
    }
    else if ( (v5 & 0x20000) != 0 )
    {
      return sub_12F2C8(dword_12C090, dword_12C058, 856, a4);
    }
    else
    {
      result = v5 << 7;
      if ( (v5 & 0x1000000) != 0 )
      {
        return sub_12F2C8(dword_12C094, dword_12C058, 857, a4);
      }
      else if ( (v5 & 0x2000000) != 0 )
      {
        return sub_12F2C8(dword_12C098, dword_12C058, 858, a4);
      }
      else if ( (v5 & 0x100000) != 0 )
      {
        return sub_12F2C8(dword_12C09C, dword_12C058, 859, a4);
      }
      else if ( (v5 & 0x8000000) != 0 )
      {
        return sub_12F2C8(dword_12C05C, dword_12C058, 860, a4);
      }
    }
  }
  return result;
}

