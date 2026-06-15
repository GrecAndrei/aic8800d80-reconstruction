// v23 annotated: sub_12E2A8 @ 0x12e2a8
// Original: 12e2a8_sub_12E2A8.c
// Primary struct: <unclustered>
//
// sub_12E2A8 @ 0x12e2a8, size 120 bytes
// Doc: sdio_buffer_prepare_2ba [mac]: Prepare SDIO scatter-gather buffer descriptor
// sdio_buffer_prepare_2ba [mac]: Prepare SDIO scatter-gather buffer descriptor
int __fastcall sub_12E2A8(unsigned int a1)
{
  int result; // r0

  if ( a1 > dword_12E320 )
  {
    if ( a1 == dword_12E324 )
    {
      return 1;
    }
    else if ( a1 == dword_12E324 + 2 )
    {
      return 2;
    }
    else if ( a1 == dword_12E324 - 3964929 )
    {
      return 4;
    }
    else
    {
      return 255;
    }
  }
  else if ( a1 <= dword_12E320 - 13 )
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

