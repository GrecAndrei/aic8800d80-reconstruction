// sub_1134E0 @ 0x1134e0, size 106 bytes
uint32_t * sub_1134E0(int a1)
{
  uint32_t *result; // r0
  uint32_t *v2; // r4
  int v3; // r0
  unsigned int v4; // r0

  switch ( a1 )
  {
    case 1:
      v2 = off_113554;
      v3 = sub_143630(off_113554, dword_113558, 18);
      if ( *((uint8_t *)off_11355C + 370) && sub_114708(v3) )
      {
        v4 = sub_11471C();
        v2[2] = ((HIWORD(v4) << 16) + 0x10000) | (unsigned __int16)v4;
        return v2;
      }
      else if ( *(unsigned __int16 *)off_113560 == 0xFFFF || *((unsigned __int16 *)off_113560 + 1) == 0xFFFF )
      {
        return off_113554;
      }
      else
      {
        result = off_113554;
        v2[2] = *(uint32_t *)off_113560;
      }
      break;
    case 6:
      return (uint32_t *)dword_113550;
    case 15:
      return (uint32_t *)dword_11354C;
    default:
      return nullptr;
  }
  return result;
}

