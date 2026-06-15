// v23 annotated: sub_12DFD4 @ 0x12dfd4
// Original: 12dfd4_sub_12DFD4.c
// Primary struct: <unclustered>
//
// sub_12DFD4 @ 0x12dfd4, size 158 bytes
int __fastcall sub_12DFD4(unsigned int a1)
{
  int result; // r0

  if ( a1 > dword_12E074 )
  {
    if ( a1 == dword_12E078 )
    {
      return 19;
    }
    else if ( a1 <= dword_12E078 )
    {
      if ( a1 == dword_12E078 - 1 )
        return 18;
      else
        return 255;
    }
    else if ( a1 == dword_12E07C )
    {
      return 2;
    }
    else if ( a1 == dword_12E07C + 1 )
    {
      return 3;
    }
    else
    {
      return 255;
    }
  }
  else if ( a1 <= dword_12E074 - 18 )
  {
    return 255;
  }
  else
  {
    switch ( a1 )
    {
      case 0xFAC01u:
        return 2;
      case 0xFAC02u:
        result = 3;
        break;
      case 0xFAC03u:
        result = 4;
        break;
      case 0xFAC04u:
        result = 5;
        break;
      case 0xFAC05u:
        result = 6;
        break;
      case 0xFAC06u:
        result = 7;
        break;
      case 0xFAC07u:
        result = 8;
        break;
      case 0xFAC08u:
        result = 9;
        break;
      case 0xFAC09u:
        result = 10;
        break;
      case 0xFAC0Bu:
        result = 11;
        break;
      case 0xFAC0Cu:
        result = 12;
        break;
      case 0xFAC0Du:
        result = 13;
        break;
      case 0xFAC0Fu:
        result = 14;
        break;
      case 0xFAC10u:
        result = 15;
        break;
      case 0xFAC11u:
        result = 16;
        break;
      case 0xFAC12u:
        result = 17;
        break;
      default:
        return 255;
    }
  }
  return result;
}

