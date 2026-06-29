// sub_12AB58 @ 0x12ab58, size 94 bytes
int  sub_12AB58(int result, int a2)
{
  switch ( a2 )
  {
    case 2:
      result = dword_12ABBC + 140 * result;
      *(uint8_t *)(result + 132) = 0;
      break;
    case 3:
      result = dword_12ABBC + 140 * result;
      if ( !*(uint8_t *)(result + 132) )
        return (int)sub_125B98(*(unsigned __int8 *)(result + 113), 1);
      break;
    case 1:
      result = dword_12ABBC + 140 * result;
      *(uint8_t *)(result + 132) = 1;
      break;
    default:
      if ( **(__int16 **)off_12ABB8 < 0 )
        return sub_12F32C(dword_12ABC4, dword_12ABC0, 1898);
      break;
  }
  return result;
}

