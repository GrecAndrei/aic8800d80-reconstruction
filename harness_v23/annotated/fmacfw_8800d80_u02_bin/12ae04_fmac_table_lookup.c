// v23 annotated: fmac_table_lookup @ 0x12ae04
// Original: 12ae04_fmac_table_lookup.c
// Primary struct: <unclustered>
//
// fmac_table_lookup @ 0x12ae04, size 52 bytes
// Doc: fmac_table_lookup [ke]: Indexed table lookup by id (entry size 32 bytes)
// fmac_table_lookup [ke]: Indexed table lookup by id (entry size 32 bytes)
int *__fastcall fmac_table_lookup(int a1)
{
  int v1; // r4
  int v2; // r6
  char v3; // r5
  int v4; // r7
  int *result; // r0
  int v6; // r3
  int v7; // r1

  v1 = dword_12AE38;
  v2 = dword_12AE38 + 32 * a1;
  v3 = a1;
  v4 = 32 * a1;
  if ( *(_BYTE *)(v2 + 30) )
    timestamp_remove(dword_12AE38 + 32 * a1);
  result = memset_thunk((int *)v2, 0, 0x20u);
  v6 = v1 + v4;
  v7 = dword_12AE3C;
  *(_DWORD *)(v6 + 8) = v2;
  *(_BYTE *)(v6 + 28) = v3;
  *(_DWORD *)(v6 + 4) = v7;
  *(_DWORD *)(v6 + 24) = 3;
  return result;
}

