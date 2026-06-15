// sub_12DF40 @ 0x12df40, size 120 bytes
int __fastcall sub_12DF40(unsigned int a1)
{
  int result; // r0

  if ( a1 > dword_12DFB8 )
  {
    if ( a1 == dword_12DFBC )
    {
      return 1;
    }
    else if ( a1 == dword_12DFBC + 2 )
    {
      return 2;
    }
    else if ( a1 == dword_12DFBC - 3964929 )
    {
      return 4;
    }
    else
    {
      return 255;
    }
  }
  else if ( a1 <= dword_12DFB8 - 13 )
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

