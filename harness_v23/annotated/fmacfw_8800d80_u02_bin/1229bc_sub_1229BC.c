// v23 annotated: sub_1229BC @ 0x1229bc
// Original: 1229bc_sub_1229BC.c
// Primary struct: <unclustered>
//
// sub_1229BC @ 0x1229bc, size 148 bytes
int __fastcall sub_1229BC(int a1, int a2, int a3, int a4)
{
  int v4; // r9
  int v6; // r5
  int v9; // r8
  char v10; // r1
  int v11; // r2

  v4 = dword_122A60;
  v6 = *(unsigned __int8 *)(a2 + 5);
  if ( **(__int16 **)off_122A50 < 0 && *(_BYTE *)(dword_122A60 + 1320 * v6 + 106) )
    sub_12F46C(dword_122A5C, dword_122A58, 2660);
  v9 = v4 + 1320 * v6;
  v10 = *(_BYTE *)(a2 + 4);
  v11 = *(unsigned __int8 *)(v9 + 149);
  *(_DWORD *)(v9 + 1228) = *(_DWORD *)a2;
  *(_BYTE *)(v9 + 1227) = v10;
  if ( v11 == 1 )
  {
    timestamp_remove(1320 * v6 + 152 + v4);
    *(_BYTE *)(v9 + 149) = 0;
  }
  feature_guard_check(256, dword_122A54);
  sub_12CA10(98, a4, a3);
  return 0;
}

