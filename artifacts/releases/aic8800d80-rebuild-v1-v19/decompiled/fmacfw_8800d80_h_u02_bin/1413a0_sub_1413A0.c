// sub_1413A0 @ 0x1413a0, size 244 bytes
void sub_1413A0()
{
  __int16 **v0; // r6
  int v1; // r3
  int v2; // r5
  unsigned int v3; // r3
  int v4; // r4
  int v5; // r6
  _DWORD *v6; // r1
  int v7; // r4
  unsigned int v8; // r3
  unsigned int v9; // r3

  v0 = (__int16 **)off_141498;
  v1 = 136 * *(_DWORD *)(dword_141494 + 6480);
  v2 = v1 + 6336 + dword_141494;
  if ( **(__int16 **)off_141498 >= 0 )
  {
    v3 = *(unsigned __int8 *)(v1 + dword_141494 + 6339);
    if ( v3 > 1 )
    {
      if ( v3 != 2 )
        return;
      goto LABEL_4;
    }
LABEL_12:
    sub_140AAC(v2, 1);
    return;
  }
  v7 = dword_141494 + v1;
  if ( *(_BYTE *)(dword_141494 + v1 + 6338) == 5 )
  {
    v9 = *(unsigned __int8 *)(v7 + 6339);
    if ( v9 <= 1 )
      goto LABEL_12;
    if ( v9 != 2 )
    {
LABEL_18:
      sub_12F32C(dword_1414A8, dword_1414A0, 1726);
      return;
    }
  }
  else
  {
    sub_12F32C(dword_1414A4, dword_1414A0, 1714);
    v8 = *(unsigned __int8 *)(v7 + 6339);
    if ( v8 <= 1 )
      goto LABEL_12;
    if ( v8 != 2 )
    {
      if ( **v0 >= 0 )
        return;
      goto LABEL_18;
    }
  }
LABEL_4:
  v4 = dword_141494;
  sub_12CBF4(0xBu, 2);
  v5 = v4 + 6336;
  sub_12D100((_DWORD *)dword_14149C);
  do
  {
    while ( *(_WORD *)(v4 + 4) != 1 || !sub_140A38((unsigned __int16 *)(v4 + 6), v4 + 28, v2) )
    {
      v4 += 528;
      if ( v4 == v5 )
        goto LABEL_9;
    }
    v6 = (_DWORD *)v4;
    *(_WORD *)(v4 + 24) = 0;
    *(_BYTE *)(v4 + 22) = 0;
    *(_WORD *)(v4 + 4) = 2;
    v4 += 528;
    sub_12D108(v5 + 136, v6);
  }
  while ( v4 != v5 );
LABEL_9:
  sub_1409A4(v2, 0);
}

