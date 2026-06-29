// sub_12CF2C @ 0x12cf2c, size 168 bytes
int  sub_12CF2C(int a1, unsigned int a2)
{
  __int16 **v2; // r4
  int v4; // r7
  unsigned int v5; // r5
  int v6; // r4
  int v7; // r7
  int v8; // r1
  int v9; // r4
  int v10; // r1
  int result; // r0
  int v12; // r1
  int v13; // r3

  v2 = (__int16 **)off_12CFD4;
  v4 = (unsigned __int8)a2;
  v5 = a2 >> 8;
  if ( **(__int16 **)off_12CFD4 >= 0 )
    goto LABEL_2;
  if ( (unsigned __int8)a2 > 0xDu )
  {
    sub_12F46C(dword_12CFE4, dword_12CFDC, 267);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v6 = dword_12CFD8;
      v7 = 16 * v4;
      goto LABEL_3;
    }
    if ( v4 != 14 )
      sub_12F46C(dword_12CFEC, dword_12CFE8, 183);
  }
  else if ( (unsigned __int8)a2 != 13 )
  {
    goto LABEL_10;
  }
  sub_12F46C(dword_12CFF0, dword_12CFDC, 268);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_10:
  v6 = dword_12CFD8;
  v13 = dword_12CFD8 + 16 * v4;
  v7 = 16 * v4;
  if ( *(unsigned __int16 *)(v13 + 14) <= v5 )
    sub_12F46C(dword_12CFE0, dword_12CFDC, 269);
LABEL_3:
  v8 = *(uint32_t *)(v6 + v7);
  v9 = v6 + v7;
  if ( !v8
    || (v10 = v8 + 8 * *(unsigned __int16 *)(*(uint32_t *)(v9 + 8) + 2 * v5),
        (result = sub_12CCD4(a1, (int *)v10, *(unsigned __int16 *)(v10 + 4))) == 0) )
  {
    v12 = *(uint32_t *)(v9 + 4);
    if ( v12 )
      return sub_12CCD4(a1, (int *)v12, *(unsigned __int16 *)(v12 + 4));
    else
      return 0;
  }
  return result;
}

