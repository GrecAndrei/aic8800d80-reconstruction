// sub_127CC0 @ 0x127cc0, size 138 bytes
int * sub_127CC0(int a1)
{
  __int16 **v1; // r8
  int v2; // r5
  int *v4; // r6
  int v5; // r7
  int v6; // r4
  int *result; // r0

  v1 = (__int16 **)off_127D60;
  v2 = dword_127D4C;
  v4 = (int *)(dword_127D4C + 28 * a1);
  if ( **(__int16 **)off_127D60 < 0 )
  {
    v5 = 8 * a1;
    if ( *(unsigned __int8 *)(dword_127D4C + 28 * a1 + 24) != 255
      || (sub_12F32C(dword_127D5C, dword_127D54, 3044), **v1 < 0) )
    {
      if ( *(uint8_t *)(v2 + 4 * (v5 - a1) + 25) )
        sub_12F32C(dword_127D58, dword_127D54, 3046);
    }
  }
  else
  {
    v5 = 8 * a1;
  }
  sub_12D108(dword_127D50);
  v6 = v2 + 4 * (v5 - a1);
  result = sub_100200(v4, 0, 0x1Cu);
  *(uint16_t *)(v6 + 14) = 255;
  *(uint8_t *)(v6 + 24) = -1;
  *(uint8_t *)(v6 + 27) = -1;
  return result;
}

