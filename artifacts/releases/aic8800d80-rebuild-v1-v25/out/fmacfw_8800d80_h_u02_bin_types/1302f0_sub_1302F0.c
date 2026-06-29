// sub_1302F0 @ 0x1302f0, size 110 bytes
int  sub_1302F0(int a1)
{
  signed int v1; // r0
  int v2; // r3
  int result; // r0

  if ( a1 > 29 )
    v1 = (unsigned int)(((unsigned int)dword_13036C * (unsigned uint64_t)(unsigned int)(a1 - 30)) >> 32) >> 3;
  else
    v1 = ((int)((unsigned uint64_t)(dword_130360 * (uint64_t)(a1 - 40)) >> 32) >> 2) - ((a1 - 40) >> 31);
  if ( v1 >= 8 )
    v1 = 8;
  if ( v1 < -7 )
    v1 = -7;
  v2 = *((unsigned __int8 *)off_130364 + 4)
     + (char)(*(uint8_t *)(dword_130368 + v1 + 7) - *(uint8_t *)(dword_130368 + *((char *)off_130364 + 2) + 7));
  if ( v2 >= 31 )
    v2 = 31;
  if ( v2 < 1 )
    LOBYTE(v2) = 1;
  *((uint8_t *)off_130364 + 5) = v2;
  sub_1301B8(v1);
  result = sub_12E91C(9u, 4u);
  if ( result )
    return sub_130260();
  return result;
}

