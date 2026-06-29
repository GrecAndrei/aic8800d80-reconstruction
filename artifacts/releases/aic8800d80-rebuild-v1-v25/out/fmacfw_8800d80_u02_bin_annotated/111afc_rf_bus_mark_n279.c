// fwstruct annotate: 111afc_rf_bus_mark_n279.c
// rf_bus_mark_n279 @ 0x111afc, size 88 bytes
// Doc: rf_bus_write2_n_e8 [rf]: Writes 32-bit value to RF bus register and tail-calls helper
// rf_bus_write2_n_e8 [rf]: Writes 32-bit value to RF bus register and tail-calls helper
int __fastcall rf_bus_mark_n279(int result, int a2)
{
  int *v2; // r4
  int v3; // r5
  int v4; // r3
  char v5; // r2
  _DWORD *v6; // r2

  v2 = (int *)rf_bus_init_n_260;
  v3 = *(_DWORD *)off_111B54;
  v4 = *(_DWORD *)rf_bus_init_n_260;
  *((_WORD *)off_111B5C + 5) = a2;
  if ( a2 == 64 )
    v5 = -54;
  else
    v5 = -50;
  *(_DWORD *)v4 = -1073741824;
  *(_DWORD *)(v4 + 4) = v3;
  *(_BYTE *)(v4 + 3) = v5;
  *(_WORD *)v4 = a2;
  if ( result && a2 )
  {
    result = sub_143770(v3, result, a2);
    v4 = *v2;
  }
  v6 = rf_mem_read_n22c;
  *(_BYTE *)(v4 + 3) &= 0x3Fu;
  v6[578] = v6[578];
  v6[581] = v4;
  v6[576] |= 0x84000000;
  return result;
}

