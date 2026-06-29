// sub_12CDEC @ 0x12cdec, size 168 bytes
int  sub_12CDEC(int a1, unsigned int a2)
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

  v2 = (__int16 **)off_12CE94;
  v4 = (unsigned __int8)a2;
  v5 = a2 >> 8;
  if ( **(__int16 **)off_12CE94 >= 0 )
    goto LABEL_2;
  if ( (unsigned __int8)a2 > 0xDu )
  {
    sub_12F32C(dword_12CEA4, dword_12CE9C, 267);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v6 = dword_12CE98;
      v7 = 16 * v4;
      goto LABEL_3;
    }
    if ( v4 != 14 )
      sub_12F32C(dword_12CEAC, dword_12CEA8, 183);
  }
  else if ( (unsigned __int8)a2 != 13 )
  {
    goto LABEL_10;
  }
  sub_12F32C(dword_12CEB0, dword_12CE9C, 268);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_10:
  v6 = dword_12CE98;
  v13 = dword_12CE98 + 16 * v4;
  v7 = 16 * v4;
  if ( *(unsigned __int16 *)(v13 + 14) <= v5 )
    sub_12F32C(dword_12CEA0, dword_12CE9C, 269);
LABEL_3:
  v8 = *(uint32_t *)(v6 + v7);
  v9 = v6 + v7;
  if ( !v8
    || (v10 = v8 + 8 * *(unsigned __int16 *)(*(uint32_t *)(v9 + 8) + 2 * v5),
        (result = sub_12CB94(a1, (int *)v10, *(unsigned __int16 *)(v10 + 4))) == 0) )
  {
    v12 = *(uint32_t *)(v9 + 4);
    if ( v12 )
      return sub_12CB94(a1, (int *)v12, *(unsigned __int16 *)(v12 + 4));
    else
      return 0;
  }
  return result;
}

