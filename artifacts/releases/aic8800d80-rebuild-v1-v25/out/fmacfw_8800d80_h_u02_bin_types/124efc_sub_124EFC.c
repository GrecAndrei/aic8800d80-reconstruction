// sub_124EFC @ 0x124efc, size 152 bytes
int  sub_124EFC(int a1, int a2)
{
  int v4; // r5

  switch ( a2 )
  {
    case 2:
      v4 = dword_124F98;
      *(uint32_t *)(dword_124F9C + 20 * a1 + 4) = 0;
      break;
    case 3:
      v4 = dword_124F98;
      sub_12AA90(*(unsigned __int8 *)(dword_124F98 + 1320 * a1 + 1225), dword_124FA8 + 38 * a1);
      break;
    case 1:
      v4 = dword_124F98;
      *(uint32_t *)(dword_124F9C + 20 * a1 + 4) = dword_124FA0 + 20 * a1;
      break;
    default:
      v4 = dword_124F98;
      if ( **(__int16 **)off_124F94 < 0 )
        sub_12F32C(dword_124FB0, dword_124FAC, 1214);
      break;
  }
  *(uint8_t *)(a1 + dword_124FA4 + 20) = 0;
  return sub_12AB58(*(unsigned __int8 *)(v4 + 1320 * a1 + 1225), a2);
}

