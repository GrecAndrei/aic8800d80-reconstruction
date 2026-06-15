// v23 annotated: mmio_set_clock_gate_bit @ 0x100aa8
// Original: 100aa8_mmio_set_clock_gate_bit.c
// Primary struct: <unclustered>
//
// mmio_set_clock_gate_bit @ 0x100aa8, size 90 bytes
// Doc: mmio_set_clock_gate_bit [mmio]: Set bit in MMIO clock gate register 0x4033b390
// mmio_set_clock_gate_bit [mmio]: Set bit in MMIO clock gate register 0x4033b390
int mmio_set_clock_gate_bit()
{
  _DWORD *v0; // r2
  int *v1; // r3
  int v2; // r4
  int result; // r0
  int v4; // r1
  _DWORD *v5; // r2
  _DWORD *v6; // r3

  v0 = off_100B04;
  *(_DWORD *)off_100B04 |= 0x1000u;
  v0[4896] |= 0x20000000u;
  v1 = (int *)dword_100B08;
  v2 = dword_100B08 + 2048;
  result = dword_100B0C - dword_100B08;
  do
  {
    v4 = *v1;
    v5 = (int *)((char *)v1++ + result);
    *v5 = v4;
  }
  while ( v1 != (int *)v2 );
  v6 = off_100B04;
  *(_DWORD *)off_100B04 |= 0x80000u;
  *v6 &= ~0x1000u;
  *(_DWORD *)off_100B10 &= ~0x20000000u;
  return result;
}

