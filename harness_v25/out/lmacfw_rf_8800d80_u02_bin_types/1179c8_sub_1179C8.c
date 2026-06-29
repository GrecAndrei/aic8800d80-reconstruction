// sub_1179C8 @ 0x1179c8, size 124 bytes
int  sub_1179C8(int result)
{
  int v1; // r4
  __int16 v2; // r2
  int v3; // r1

  v1 = result;
  if ( **(__int16 **)off_117A44 < 0 && *(uint32_t *)(result + 20) != dword_117A4C )
    result = rf_cmd_send_n264(dword_117A54, dword_117A50, 1811);
  v2 = *(uint16_t *)(v1 + 48);
  if ( v2 )
  {
    switch ( *(uint32_t *)(v1 + 84) & 0x7C )
    {
      case 4:
      case 8:
        *(uint16_t *)(v1 + 48) = v2 - 8;
        break;
      case 0xC:
        *(uint16_t *)(v1 + 48) = v2 - 12;
        break;
      case 0x10:
      case 0x14:
      case 0x18:
      case 0x1C:
        *(uint16_t *)(v1 + 48) = v2 - 20;
        break;
      default:
        *(uint16_t *)(v1 + 48) = v2 - 4;
        break;
    }
  }
  v3 = dword_117A48;
  *(uint8_t *)(v1 + 16) = 2;
  *(uint8_t *)(v1 + 152) = 0;
  *(uint32_t *)(v1 + 12) = v1;
  *(uint32_t *)(v1 + 4) = v3;
  return result;
}

