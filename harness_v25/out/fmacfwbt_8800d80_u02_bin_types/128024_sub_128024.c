// sub_128024 @ 0x128024, size 138 bytes
int * sub_128024(int a1)
{
  __int16 **v1; // r8
  int v2; // r5
  int *v4; // r6
  int v5; // r7
  int v6; // r4
  int *result; // r0

  v1 = (__int16 **)off_1280C4;
  v2 = dword_1280B0;
  v4 = (int *)(dword_1280B0 + 28 * a1);
  if ( **(__int16 **)off_1280C4 < 0 )
  {
    v5 = 8 * a1;
    if ( *(unsigned __int8 *)(dword_1280B0 + 28 * a1 + 24) != 255
      || (sub_12F694(dword_1280C0, dword_1280B8, 3044), **v1 < 0) )
    {
      if ( *(uint8_t *)(v2 + 4 * (v5 - a1) + 25) )
        sub_12F694(dword_1280BC, dword_1280B8, 3046);
    }
  }
  else
  {
    v5 = 8 * a1;
  }
  sub_12D470(dword_1280B4);
  v6 = v2 + 4 * (v5 - a1);
  result = sub_100200(v4, 0, 0x1Cu);
  *(uint16_t *)(v6 + 14) = 255;
  *(uint8_t *)(v6 + 24) = -1;
  *(uint8_t *)(v6 + 27) = -1;
  return result;
}

