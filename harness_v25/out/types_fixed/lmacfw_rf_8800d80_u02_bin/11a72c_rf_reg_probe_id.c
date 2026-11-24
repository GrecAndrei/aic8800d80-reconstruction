// rf_reg_probe_id @ 0x11a72c, size 132 bytes
// Doc: rf_reg_probe_id [rf]: Probes RF register 0x40320200 and reads header
// rf_reg_probe_id [rf]: Probes RF register 0x40320200 and reads header
int __fastcall rf_reg_probe_id(unsigned __int16 *a1)
{
  int v1; // r3
  int *v2; // r2
  int v4; // r0
  int *v5; // r5
  int *v6; // r7
  int v7; // r6
  int v8; // r1
  int v9; // r5
  int *v10; // r0

  v1 = dword_11A7B4;
  v2 = *(int **)off_11A7B0;
  v4 = *a1;
  v5 = (int *)off_11A7B8;
  v6 = (int *)off_11A7BC;
  v7 = *(_DWORD *)(a1 + 0x8);
  *v2 = **(_DWORD **)off_11A7B0 & dword_11A7B4 | (v4 << 12);
  *v5 = *v5 & v1 | (v4 << 12);
  v8 = *(_DWORD *)(a1 + 0x4);
  *(_DWORD *)(v2 + 0x4) = *(_DWORD *)(v2 + 0x4) & v1 | (v8 << 12);
  v9 = *(_DWORD *)(a1 + 0xc);
  *v6 = *v6 & v1 | (v8 << 12);
  *(_DWORD *)(v2 + 0x8) = *(_DWORD *)(v2 + 0x8) & v1 | (v7 << 12);
  v10 = (int *)off_11A7C0;
  *(_DWORD *)(v6 + 0x4) = *(_DWORD *)(v6 + 0x4) & v1 | (v7 << 12);
  *(_DWORD *)(v2 + 0xc) = *(_DWORD *)(v2 + 0xc) & v1 | (v9 << 12);
  *v10 = v1 & *v10 | (v9 << 12);
  sub_1183A0();
  msg_parse(dword_11A7C4, *a1);
  return 0;
}

