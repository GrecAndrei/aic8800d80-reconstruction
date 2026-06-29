// fwstruct annotate: 12a788_rf_table_lookup_n788.c
// rf_table_lookup_n788 @ 0x12a788, size 102 bytes
// Doc: rf_table_lookup_n788 [rf]: Looks up RF calibration entry from indexed table
// rf_table_lookup_n788 [rf]: Looks up RF calibration entry from indexed table
char *__fastcall rf_table_lookup_n788(int a1)
{
  int v1; // r7
  int v2; // r4
  unsigned __int8 *v3; // r6
  int v4; // r3
  int v5; // r4
  char v6; // r1

  v1 = dword_12A7F0;
  v2 = *(unsigned __int8 *)(a1 + 1225);
  v3 = (unsigned __int8 *)(dword_12A7F0 + 140 * v2);
  v4 = v3[114];
  v3[115] = 0;
  if ( v4 )
  {
    timestamp_remove_058(140 * v2 + 96 + v1);
    v3[114] = 0;
  }
  sub_129A28(v3);
  v5 = v1 + 140 * v2;
  if ( *(_BYTE *)(v5 + 121) )
    v6 = 3;
  else
    v6 = 2;
  return sub_125EFC(*(unsigned __int8 *)(v5 + 113), v6);
}

