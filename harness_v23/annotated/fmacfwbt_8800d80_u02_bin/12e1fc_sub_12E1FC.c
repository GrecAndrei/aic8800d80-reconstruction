// v23 annotated: sub_12E1FC @ 0x12e1fc
// Original: 12e1fc_sub_12E1FC.c
// Primary struct: <unclustered>
//
// sub_12E1FC @ 0x12e1fc, size 158 bytes
// Doc: sdio_buffer_prepare_20e [ipc]: Prepare SDIO DMA buffer for transfer
// sdio_buffer_prepare_20e [ipc]: Prepare SDIO DMA buffer for transfer
int __fastcall sub_12E1FC(unsigned int a1)
{
  int result; // r0

  if ( a1 > sdio_buffer_prepare_n_a8_e29c )
  {
    if ( a1 == dword_12E2A0 )
    {
      return 19;
    }
    else if ( a1 <= dword_12E2A0 )
    {
      if ( a1 == dword_12E2A0 - 1 )
        return 18;
      else
        return 255;
    }
    else if ( a1 == dword_12E2A4 )
    {
      return 2;
    }
    else if ( a1 == dword_12E2A4 + 1 )
    {
      return 3;
    }
    else
    {
      return 255;
    }
  }
  else if ( a1 <= sdio_buffer_prepare_n_a8_e29c - 18 )
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

