// sub_12CD48 @ 0x12cd48, size 130 bytes
int  sub_12CD48(unsigned int a1)
{
  __int16 **v1; // r5
  unsigned int v2; // r6
  int v3; // r4
  int v4; // r5
  int v5; // r4
  int v7; // r3

  v1 = (__int16 **)off_12CDCC;
  v2 = a1 >> 8;
  v3 = (unsigned __int8)a1;
  if ( **(__int16 **)off_12CDCC >= 0 )
    goto LABEL_2;
  if ( (unsigned __int8)a1 > 0xDu )
  {
    sub_12F32C(dword_12CDDC, dword_12CDD4, 210);
    if ( **v1 >= 0 )
    {
LABEL_2:
      v4 = dword_12CDD0;
      v5 = 16 * v3;
      return *(unsigned __int16 *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
    }
    if ( v3 != 14 )
      sub_12F32C(dword_12CDE4, dword_12CDE0, 183);
  }
  else if ( (unsigned __int8)a1 != 13 )
  {
    goto LABEL_6;
  }
  sub_12F32C(dword_12CDE8, dword_12CDD4, 211);
  if ( **v1 >= 0 )
    goto LABEL_2;
LABEL_6:
  v4 = dword_12CDD0;
  v7 = dword_12CDD0 + 16 * v3;
  v5 = 16 * v3;
  if ( *(unsigned __int16 *)(v7 + 14) > v2 )
    return *(unsigned __int16 *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
  sub_12F32C(dword_12CDD8, dword_12CDD4, 212);
  return *(unsigned __int16 *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
}

