// sub_11EB34 @ 0x11eb34, size 124 bytes
// Doc: sub_121EB34 [unknown]: Unidentified utility helper at 0x121EB34
// sub_121EB34 [unknown]: Unidentified utility helper at 0x121EB34
int  sub_11EB34(int result)
{
  int v1; // r4
  __int16 v2; // r2
  int v3; // r1

  v1 = result;
  if ( **(__int16 **)off_11EBB0 < 0 && *(uint32_t *)(result + 20) != dword_11EBB8 )
    result = sub_12F46C(dword_11EBC0, dword_11EBBC, 1811);
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
  v3 = dword_11EBB4;
  *(uint8_t *)(v1 + 16) = 2;
  *(uint8_t *)(v1 + 156) = 0;
  *(uint32_t *)(v1 + 12) = v1;
  *(uint32_t *)(v1 + 4) = v3;
  return result;
}

