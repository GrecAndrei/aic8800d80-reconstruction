// v23 annotated: rx_agc_init_n_4e0 @ 0x1414e0
// Original: 1414e0_rx_agc_init_n_4e0.c
// Primary struct: <unclustered>
//
// rx_agc_init_n_4e0 @ 0x1414e0, size 244 bytes
// Doc: rx_agc_init_n_4e0 [rx]: Initialize RX AGC table from ROM data
// rx_agc_init_n_4e0 [rx]: Initialize RX AGC table from ROM data
void rx_agc_init_n_4e0()
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

  v0 = (__int16 **)off_1415D8;
  v1 = 136 * *(_DWORD *)(dword_1415D4 + 6480);
  v2 = v1 + 6336 + dword_1415D4;
  if ( **(__int16 **)off_1415D8 >= 0 )
  {
    v3 = *(unsigned __int8 *)(v1 + dword_1415D4 + 6339);
    if ( v3 > 1 )
    {
      if ( v3 != 2 )
        return;
      goto LABEL_4;
    }
LABEL_12:
    sub_140BEC(v2, 1);
    return;
  }
  v7 = dword_1415D4 + v1;
  if ( *(_BYTE *)(dword_1415D4 + v1 + 6338) == 5 )
  {
    v9 = *(unsigned __int8 *)(v7 + 6339);
    if ( v9 <= 1 )
      goto LABEL_12;
    if ( v9 != 2 )
    {
LABEL_18:
      sub_12F46C(dword_1415E8, dword_1415E0, 1726);
      return;
    }
  }
  else
  {
    sub_12F46C(dword_1415E4, dword_1415E0, 1714);
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
  v4 = dword_1415D4;
  sub_12CD34(0xBu, 2);
  v5 = v4 + 6336;
  sub_12D240((_DWORD *)dword_1415DC);
  do
  {
    while ( *(_WORD *)(v4 + 4) != 1 || !sub_140B78((unsigned __int16 *)(v4 + 6), v4 + 28, v2) )
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
    list_push_tail(v5 + 136, v6);
  }
  while ( v4 != v5 );
LABEL_9:
  sub_140AE4(v2, 0);
}

