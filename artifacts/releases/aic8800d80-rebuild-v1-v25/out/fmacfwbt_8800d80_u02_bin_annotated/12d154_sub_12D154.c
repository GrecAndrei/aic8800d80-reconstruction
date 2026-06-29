// fwstruct annotate: 12d154_sub_12D154.c
// sub_12D154 @ 0x12d154, size 168 bytes
int __fastcall sub_12D154(int a1, unsigned int a2)
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

  v2 = (__int16 **)off_12D1FC;
  v4 = (unsigned __int8)a2;
  v5 = a2 >> 8;
  if ( **(__int16 **)off_12D1FC >= 0 )
    goto LABEL_2;
  if ( (unsigned __int8)a2 > 0xDu )
  {
    sub_12F694(dword_12D20C, dword_12D204, 267);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v6 = dword_12D200;
      v7 = 16 * v4;
      goto LABEL_3;
    }
    if ( v4 != 14 )
      sub_12F694(dword_12D214, dword_12D210, 183);
  }
  else if ( (unsigned __int8)a2 != 13 )
  {
    goto LABEL_10;
  }
  sub_12F694(dword_12D218, dword_12D204, 268);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_10:
  v6 = dword_12D200;
  v13 = dword_12D200 + 16 * v4;
  v7 = 16 * v4;
  if ( *(unsigned __int16 *)(v13 + 14) <= v5 )
    sub_12F694(dword_12D208, dword_12D204, 269);
LABEL_3:
  v8 = *(_DWORD *)(v6 + v7);
  v9 = v6 + v7;
  if ( !v8
    || (v10 = v8 + 8 * *(unsigned __int16 *)(*(_DWORD *)(v9 + 8) + 2 * v5),
        (result = sub_12CEFC(a1, (int *)v10, *(unsigned __int16 *)(v10 + 4))) == 0) )
  {
    v12 = *(_DWORD *)(v9 + 4);
    if ( v12 )
      return sub_12CEFC(a1, (int *)v12, *(unsigned __int16 *)(v12 + 4));
    else
      return 0;
  }
  return result;
}

