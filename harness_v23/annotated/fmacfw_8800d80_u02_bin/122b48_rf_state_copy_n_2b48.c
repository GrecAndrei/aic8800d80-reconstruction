// v23 annotated: rf_state_copy_n_2b48 @ 0x122b48
// Original: 122b48_rf_state_copy_n_2b48.c
// Primary struct: <unclustered>
//
// rf_state_copy_n_2b48 @ 0x122b48, size 28 bytes
// Doc: rf_state_copy_n_2b48 [util]: Copy 8-byte state (dword+hword) from arg struct to global at 0x173268
// rf_state_copy_n_2b48 [util]: Copy 8-byte state (dword+hword) from arg struct to global at 0x173268
int __fastcall rf_state_copy_n_2b48(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r0
  _DWORD *v5; // r5
  int v6; // r4
  int v7; // r1

  v4 = *a2;
  v5 = a2;
  v6 = dword_122B64;
  v7 = a2[1];
  LOWORD(v5) = *((_WORD *)v5 + 4);
  *(_DWORD *)dword_122B64 = v4;
  *(_DWORD *)(v6 + 4) = v7;
  *(_WORD *)(v6 + 8) = (_WORD)v5;
  sub_12CA10(138, a4, a3);
  return 0;
}

