// fwstruct annotate: 1164e0_bt_table_lookup_n_64e.c
// bt_table_lookup_n_64e @ 0x1164e0, size 34 bytes
// Doc: bt_table_lookup_n_64e [bt]: Lookup entry in BT table by indexed offset
// bt_table_lookup_n_64e [bt]: Lookup entry in BT table by indexed offset
int __fastcall bt_table_lookup_n_64e(int a1, int a2)
{
  int v2; // r3
  int result; // r0
  int v4; // r2

  v2 = dword_116504;
  result = a1 + 22;
  v4 = dword_116504 + 8 * result;
  if ( *(_DWORD *)(v4 + 4) )
    v4 = *(_DWORD *)(v4 + 8);
  *(_DWORD *)(v4 + 4) = a2;
  *(_DWORD *)(v2 + 8 * result + 8) = a2;
  *(_DWORD *)(a2 + 4) = 0;
  return result;
}

