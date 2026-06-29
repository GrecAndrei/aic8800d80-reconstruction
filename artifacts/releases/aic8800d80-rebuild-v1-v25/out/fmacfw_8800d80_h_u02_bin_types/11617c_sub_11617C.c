// sub_11617C @ 0x11617c, size 88 bytes
int  sub_11617C(int result)
{
  switch ( result )
  {
    case 0:
      *(uint32_t *)off_1161D4 = 2;
      break;
    case 1:
      *(uint32_t *)off_1161D4 = 4;
      break;
    case 2:
      *(uint32_t *)off_1161D4 = 8;
      break;
    case 3:
      *(uint32_t *)off_1161D4 = 16;
      break;
    case 4:
      *(uint32_t *)off_1161D4 = 1;
      break;
    case 5:
      *(uint32_t *)off_1161D4 = 32;
      break;
    default:
      if ( **(__int16 **)off_1161D8 < 0 )
        result = sub_12F32C(dword_1161E0, dword_1161DC, 944);
      break;
  }
  return result;
}

