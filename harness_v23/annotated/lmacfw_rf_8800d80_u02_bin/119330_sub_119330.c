// v23 annotated: sub_119330 @ 0x119330
// Original: 119330_sub_119330.c
// Primary struct: <unclustered>
//
// sub_119330 @ 0x119330, size 154 bytes
int __fastcall sub_119330(int a1, int *a2, int a3, int a4)
{
  int v4; // r6
  int v6; // r7
  int v9; // r8
  int v10; // r4
  char v11; // r1
  int v12; // r2
  int v13; // r3

  v4 = dword_1193D0;
  v6 = *((unsigned __int8 *)a2 + 5);
  if ( **(__int16 **)off_1193CC < 0 )
  {
    v9 = 8 * v6;
    if ( *(_BYTE *)(dword_1193D0 + 224 * v6 + 94) )
      rf_cmd_send_n264(dword_1193DC, dword_1193D8, 2660);
  }
  else
  {
    v9 = 8 * v6;
  }
  v10 = v4 + 32 * (v9 - v6);
  v11 = *((_BYTE *)a2 + 4);
  v12 = *(unsigned __int8 *)(v10 + 121);
  v13 = *a2;
  *(_DWORD *)(v10 + 144) = *a2;
  *(_BYTE *)(v10 + 140) = v11;
  if ( v12 == 1 )
  {
    timestamp_remove(v4 + 224 * v6 + 124);
    v13 = *(_DWORD *)(v10 + 144);
    *(_BYTE *)(v10 + 121) = 0;
  }
  sub_11F74C(256, dword_1193D4, *(unsigned __int8 *)(v4 + 32 * (v9 - v6) + 140), v13);
  sub_11DED8(98, a4, a3);
  return 0;
}

