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
  v0[14] = 296;
  v1[2] = v1[2] & 0xF000FFFF | 0x2000000;
  v1[3] = v2 & v1[3] | 0xA06A000;
  v1[3] = v3 & v1[3] | 0x100230;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v4 = sub_142A50(v1[4]);
  v5 = sub_142B44(v4, HIDWORD(v4), dword_10DE20, dword_10DE24);
  v6 = sub_142D98(v5, HIDWORD(v5), dword_10DE28, dword_10DE2C);
  v7 = sub_1427D4(v6, HIDWORD(v6), dword_10DE30, dword_10DE34);
  return sub_143108(v7);
}

