// bt_msg_post @ 0x124bbc, size 132 bytes
// Doc: sub_1224BC2 [mmio]: Read/write MMIO control registers block
// sub_1224BC2 [mmio]: Read/write MMIO control registers block
int __fastcall bt_msg_post(unsigned __int16 *a1)
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

  v1 = dword_124C44;
  v2 = *(int **)off_124C40;
  v4 = *a1;
  v5 = (int *)off_124C48;
  v6 = (int *)off_124C4C;
  v7 = *(_DWORD *)(a1 + 0x8);
  *v2 = **(_DWORD **)off_124C40 & dword_124C44 | (v4 << 12);
  *v5 = *v5 & v1 | (v4 << 12);
  v8 = *(_DWORD *)(a1 + 0x4);
  *(_DWORD *)(v2 + 0x4) = *(_DWORD *)(v2 + 0x4) & v1 | (v8 << 12);
  v9 = *(_DWORD *)(a1 + 0xc);
  *v6 = *v6 & v1 | (v8 << 12);
  *(_DWORD *)(v2 + 0x8) = *(_DWORD *)(v2 + 0x8) & v1 | (v7 << 12);
  v10 = (int *)off_124C50;
  *(_DWORD *)(v6 + 0x4) = *(_DWORD *)(v6 + 0x4) & v1 | (v7 << 12);
  *(_DWORD *)(v2 + 0xc) = *(_DWORD *)(v2 + 0xc) & v1 | (v9 << 12);
  *v10 = v1 & *v10 | (v9 << 12);
  chip_version_read_12207E0();
  sub_12ECB0(dword_124C54, *a1, *(_DWORD *)(a1 + 0x4));
  return 0;
}

