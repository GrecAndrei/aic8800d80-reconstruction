// sub_10CF48 @ 0x10cf48, size 190 bytes
// Doc: sub_120CF48 [util]: Lookup entry in table at 0x180ac0 offset by halfword, call handler
// sub_120CF48 [util]: Lookup entry in table at 0x180ac0 offset by halfword, call handler
int __fastcall sub_10CF48(_WORD *a1)
{
  __int16 **v2; // r7
  int v3; // r0
  __int16 *v4; // r6
  int v5; // r4
  int v6; // r2
  unsigned int v7; // r7
  int *v8; // r3
  int *v9; // r2
  int v10; // r1
  int v11; // t1
  _DWORD *v12; // r1
  __int16 v13; // r3

  v2 = (__int16 **)off_10D008;
  v3 = sub_11DF94((unsigned __int16)a1[5] + 16);
  v4 = *v2;
  v5 = v3;
  if ( **v2 < 0 && !v3 )
  {
    rf_cmd_send_n264(dword_10D020, dword_10D018, 1358);
    v4 = *v2;
  }
  v6 = (unsigned __int16)a1[5];
  v7 = (unsigned __int16)a1[3];
  *(_WORD *)(v5 + 4) = a1[2];
  *(_WORD *)(v5 + 8) = 4;
  *(_WORD *)(v5 + 10) = v6;
  *(_WORD *)(v5 + 6) = v7;
  *(_DWORD *)v5 = 0;
  v8 = (int *)(a1 + 6);
  if ( v6 )
  {
    v9 = (int *)((char *)a1 + ((v6 - 1) & 0xFFFFFFFC) + 16);
    v10 = v5 + 8;
    do
    {
      v11 = *v8++;
      *(_DWORD *)(v10 + 4) = v11;
      v10 += 4;
    }
    while ( v8 != v9 );
  }
  if ( *v4 < 0 )
  {
    if ( v7 > 5 )
    {
      rf_cmd_send_n264(dword_10D028, dword_10D024, 183);
      rf_cmd_send_n264(dword_10D01C, dword_10D018, 1375);
    }
    else if ( v7 > 3 )
    {
      rf_cmd_send_n264(dword_10D01C, dword_10D018, 1375);
    }
  }
  if ( **(_BYTE **)off_10D00C == 3 )
  {
    v12 = off_10D014;
    v13 = *((unsigned __int8 *)off_10D010 + 20);
    *((_BYTE *)off_10D010 + 20) = v13 + 1;
    a1[4] = v13;
    *v12 = 4;
  }
  return sub_11DE50(v5 + 12);
}

