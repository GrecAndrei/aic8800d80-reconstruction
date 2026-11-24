// sub_124848 @ 0x124848, size 132 bytes
int __fastcall sub_124848(unsigned __int16 *a1)
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

  v1 = dword_1248D0;
  v2 = *(int **)off_1248CC;
  v4 = *a1;
  v5 = (int *)off_1248D4;
  v6 = (int *)off_1248D8;
  v7 = *(_DWORD *)(a1 + 0x8);
  *v2 = **(_DWORD **)off_1248CC & dword_1248D0 | (v4 << 12);
  *v5 = *v5 & v1 | (v4 << 12);
  v8 = *(_DWORD *)(a1 + 0x4);
  *(_DWORD *)(v2 + 0x4) = *(_DWORD *)(v2 + 0x4) & v1 | (v8 << 12);
  v9 = *(_DWORD *)(a1 + 0xc);
  *v6 = *v6 & v1 | (v8 << 12);
  *(_DWORD *)(v2 + 0x8) = *(_DWORD *)(v2 + 0x8) & v1 | (v7 << 12);
  v10 = (int *)off_1248DC;
  *(_DWORD *)(v6 + 0x4) = *(_DWORD *)(v6 + 0x4) & v1 | (v7 << 12);
  *(_DWORD *)(v2 + 0xc) = *(_DWORD *)(v2 + 0xc) & v1 | (v9 << 12);
  *v10 = v1 & *v10 | (v9 << 12);
  sub_120368();
  sub_12E948(dword_1248E0, *a1, *(_DWORD *)(a1 + 0x4));
  return 0;
}

