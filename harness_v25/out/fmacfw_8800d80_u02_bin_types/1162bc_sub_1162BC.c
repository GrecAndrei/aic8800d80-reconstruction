// sub_1162BC @ 0x1162bc, size 88 bytes
// Doc: sub_12162BC [util]: Dispatch/route based on value comparison against 5
// sub_12162BC [util]: Dispatch/route based on value comparison against 5
int  sub_1162BC(int result)
{
  switch ( result )
  {
    case 0:
      *(uint32_t *)off_116314 = 2;
      break;
    case 1:
      *(uint32_t *)off_116314 = 4;
      break;
    case 2:
      *(uint32_t *)off_116314 = 8;
      break;
    case 3:
      *(uint32_t *)off_116314 = 16;
      break;
    case 4:
      *(uint32_t *)off_116314 = 1;
      break;
    case 5:
      *(uint32_t *)off_116314 = 32;
      break;
    default:
      if ( **(__int16 **)off_116318 < 0 )
        result = sub_12F46C(dword_116320, dword_11631C, 944);
      break;
  }
  return result;
}

