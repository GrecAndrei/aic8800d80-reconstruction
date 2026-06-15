// fw_event_dispatch_nfb4 @ 0x13bfb4, size 222 bytes
// Doc: fw_event_dispatch_nfb4 [ipc]: Dispatch FW event by opcode (table lookup)
// fw_event_dispatch_nfb4 [ipc]: Dispatch FW event by opcode (table lookup)
int __fastcall fw_event_dispatch_nfb4(int a1, int a2, __int16 a3)
{
  int v6; // r0
  char v7; // r11
  _DWORD *v8; // r8
  int v9; // r4
  __int16 v10; // r6
  char v11; // r0
  __int16 v12; // r12
  int v13; // r2
  bool v14; // zf
  __int16 v15; // r0
  int v16; // r7
  int v17; // r2
  unsigned __int16 v18; // r6

  v6 = sub_13BF78();
  v7 = v6;
  if ( (unsigned __int8)v6 == 33 )
    return 3;
  v8 = off_13C0A0;
  v9 = dword_13C094 + 32 * (unsigned __int8)v6;
  v10 = v6;
  *(_BYTE *)(v9 + 22) = a2;
  *(_BYTE *)(v9 + 16) = a1;
  v11 = random_mix_64(v6);
  v13 = dword_13C098;
  *(_BYTE *)(v9 + 23) = v11;
  v14 = (*(_DWORD *)(v13 + 696 * a1 + 4) & 0x20) == 0;
  v15 = *(_WORD *)(*(_DWORD *)off_13C09C + 2);
  *(_BYTE *)(v9 + 18) = 1;
  *(_BYTE *)(v9 + 17) = 1;
  *(_DWORD *)(v9 + 4) = 0;
  v16 = v13 + 696 * a1 + 12 * a2;
  if ( !v14 )
    v12 = 256;
  v17 = v8[4];
  if ( v14 )
    v12 = 64;
  *(_WORD *)(v9 + 20) = v12;
  *(_WORD *)(v9 + 14) = v15;
  *(_DWORD *)(v9 + 8) = v17;
  *(_WORD *)(v9 + 12) = a3;
  *(_BYTE *)(v16 + 453) = v7;
  sub_13B698(a1, v9, 2, 0, 0, 39, 0);
  v18 = (v10 << 8) | 8;
  sub_13B698(a1, v9, 0, 0, 0, 0, 0);
  *(_DWORD *)(v16 + 444) = v8[4];
  timer_set_relative(0x2000, v18, 0x7D000u);
  sub_12CD34(v18, 2);
  return 0;
}

