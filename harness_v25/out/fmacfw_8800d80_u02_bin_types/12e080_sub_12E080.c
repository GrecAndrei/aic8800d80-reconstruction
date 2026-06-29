// sub_12E080 @ 0x12e080, size 120 bytes
// Doc: sdio_buffer_prepare_n_8a [mac]: SDIO buffer preparation routine
// sdio_buffer_prepare_n_8a [mac]: SDIO buffer preparation routine
int  sub_12E080(unsigned int a1)
{
  int result; // r0

  if ( a1 > dword_12E0F8 )
  {
    if ( a1 == dword_12E0FC )
    {
      return 1;
    }
    else if ( a1 == dword_12E0FC + 2 )
    {
      return 2;
    }
    else if ( a1 == dword_12E0FC - 3964929 )
    {
      return 4;
    }
    else
    {
      return 255;
    }
  }
  else if ( a1 <= dword_12E0F8 - 13 )
  {
    return 255;
  }
  else
  {
    switch ( a1 )
    {
      case 0xFAC01u:
        result = 0;
        break;
      case 0xFAC02u:
        return 1;
      case 0xFAC04u:
        return 2;
      case 0xFAC05u:
        result = 3;
        break;
      case 0xFAC06u:
        result = 5;
        break;
      case 0xFAC08u:
        result = 6;
        break;
      case 0xFAC09u:
        result = 7;
        break;
      case 0xFAC0Au:
        result = 8;
        break;
      case 0xFAC0Bu:
        result = 9;
        break;
      case 0xFAC0Cu:
        result = 10;
        break;
      case 0xFAC0Du:
        result = 11;
        break;
      default:
        return 255;
    }
  }
  return result;
}

