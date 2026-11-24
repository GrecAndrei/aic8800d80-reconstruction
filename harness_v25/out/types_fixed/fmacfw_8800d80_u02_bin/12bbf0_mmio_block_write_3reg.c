// mmio_block_write_3reg @ 0x12bbf0, size 48 bytes
// Doc: mmio_block_write_3reg [mmio]: Writes 3 MMIO registers at 0x403200bc/c0/c4 from a struct
// mmio_block_write_3reg [mmio]: Writes 3 MMIO registers at 0x403200bc/c0/c4 from a struct
int __fastcall mmio_block_write_3reg(int *a1)
{
  _DWORD *v1; // r2
  int *v2; // r3
  int v3; // r4
  int v4; // r0
  int v5; // r0

  v1 = off_12BC24;
  v2 = (int *)off_12BC28;
  v3 = *a1;
  v4 = *((unsigned __int16 *)a1 + 2);
  *(_DWORD *)off_12BC20 = v3;
  *v1 = v4;
  *v2 = 0x20000000;
  do
    v5 = *v2;
  while ( (*v2 & 0x20000000) != 0 );
  if ( (v5 & 0x10000000) != 0 )
    return 255;
  else
    return (unsigned __int8)(BYTE2(v5) - 16);
}

