// mmio_init_block_120DDA0 @ 0x10dda0, size 128 bytes
// Doc: mmio_init_block_120DDA0 [mmio]: Initialize MMIO block at 0x40100000/0x4010d000 with constant values
// mmio_init_block_120DDA0 [mmio]: Initialize MMIO block at 0x40100000/0x4010d000 with constant values
int mmio_init_block_120DDA0()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r3
  int v2; // r1
  int v3; // r2
  __int64 v4; // r0
  __int64 v5; // r0
  __int64 v6; // r0
  int v7; // r0

  v0 = off_10DE38;
  v1 = off_10DE3C;
  v2 = dword_10DE40;
  v3 = dword_10DE44;
  *(_DWORD *)off_10DE3C = 0;
  *(_DWORD *)(v0 + 0x38) = 296;
  *(_DWORD *)(v1 + 0x8) = *(_DWORD *)(v1 + 0x8) & 0xF000FFFF | 0x2000000;
  *(_DWORD *)(v1 + 0xc) = v2 & *(_DWORD *)(v1 + 0xc) | 0xA06A000;
  *(_DWORD *)(v1 + 0xc) = v3 & *(_DWORD *)(v1 + 0xc) | 0x100230;
  *(_DWORD *)(v1 + 0x4) = 1;
  while ( *(_DWORD *)(v1 + 0x1c) != 1 )
    ;
  *(_DWORD *)(v1 + 0x1c) = 1;
  v4 = sub_142A50(*(_DWORD *)(v1 + 0x10));
  v5 = sub_142B44(v4, HIDWORD(v4), dword_10DE20, dword_10DE24);
  v6 = sub_142D98(v5, HIDWORD(v5), dword_10DE28, dword_10DE2C);
  v7 = sub_1427D4(v6, HIDWORD(v6), dword_10DE30, dword_10DE34);
  return sub_143108(v7);
}

