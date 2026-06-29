// sub_1166FC @ 0x1166fc, size 88 bytes
int  sub_1166FC(int result)
{
  switch ( result )
  {
    case 0:
      *(uint32_t *)off_116754 = 2;
      break;
    case 1:
      *(uint32_t *)off_116754 = 4;
      break;
    case 2:
      *(uint32_t *)off_116754 = 8;
      break;
    case 3:
      *(uint32_t *)off_116754 = 16;
      break;
    case 4:
      *(uint32_t *)off_116754 = 1;
      break;
    case 5:
      *(uint32_t *)off_116754 = 32;
      break;
    default:
      if ( **(__int16 **)off_116758 < 0 )
        result = sub_12F694(dword_116760, dword_11675C, 944);
      break;
  }
  return result;
}

