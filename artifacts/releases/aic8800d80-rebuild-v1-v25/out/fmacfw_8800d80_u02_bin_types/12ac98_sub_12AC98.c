// sub_12AC98 @ 0x12ac98, size 94 bytes
int  sub_12AC98(int result, int a2)
{
  switch ( a2 )
  {
    case 2:
      result = dword_12ACFC + 140 * result;
      *(uint8_t *)(result + 132) = 0;
      break;
    case 3:
      result = dword_12ACFC + 140 * result;
      if ( !*(uint8_t *)(result + 132) )
        return (int)sub_125CD8(*(unsigned __int8 *)(result + 113), 1);
      break;
    case 1:
      result = dword_12ACFC + 140 * result;
      *(uint8_t *)(result + 132) = 1;
      break;
    default:
      if ( **(__int16 **)off_12ACF8 < 0 )
        return sub_12F46C(dword_12AD04, dword_12AD00, 1898);
      break;
  }
  return result;
}

