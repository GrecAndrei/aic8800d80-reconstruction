// v23 annotated: rf_fault_dump_n_27c @ 0x139cf4
// Original: 139cf4_rf_fault_dump_n_27c.c
// Primary struct: <unclustered>
//
// rf_fault_dump_n_27c @ 0x139cf4, size 118 bytes
// Doc: rf_fault_dump_n_27c [rf]: Dump RF fault state at counter 0x27c
// rf_fault_dump_n_27c [rf]: Dump RF fault state at counter 0x27c
int rf_fault_dump_n_27c()
{
  _DWORD *v0; // r6
  int v1; // r4
  int v2; // r5
  _DWORD *v3; // r1
  int v4; // r3
  int result; // r0
  int v6; // r1

  v0 = (_DWORD *)(dword_139D6C + 16);
  sub_12D240((_DWORD *)dword_139D6C);
  v1 = dword_139D70;
  sub_12D240(v0);
  v2 = v1 + 4672;
  do
  {
    v3 = (_DWORD *)v1;
    v1 += 292;
    list_push_tail((int)v0, v3);
  }
  while ( v1 != v2 );
  sub_12D240((_DWORD *)dword_139D74);
  sub_12D240((_DWORD *)dword_139D78);
  list_push_tail(dword_139D74, (_DWORD *)dword_139D7C);
  list_push_tail(dword_139D74, (_DWORD *)dword_139D80);
  list_push_tail(dword_139D74, (_DWORD *)dword_139D84);
  v4 = dword_139D8C;
  result = dword_139D90;
  *((_WORD *)off_139D88 + 51) = -1;
  v6 = v4 + 15360;
  do
  {
    *(_BYTE *)(v4 - 52) = 0;
    *(_WORD *)(v4 + 8) = 0;
    *(_DWORD *)(v4 - 64) = result;
    *(_DWORD *)(v4 - 60) = v4;
    *(_DWORD *)(v4 - 48) = v4;
    v4 += 80;
  }
  while ( v6 != v4 );
  return result;
}

