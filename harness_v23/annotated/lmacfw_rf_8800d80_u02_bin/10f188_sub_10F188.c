// v23 annotated: sub_10F188 @ 0x10f188
// Original: 10f188_sub_10F188.c
// Primary struct: mmio_clock_gate (cluster 1, 25 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_10F188 @ 0x10f188, size 82 bytes
int __fastcall sub_10F188(int a1)
{
  unsigned int v2; // r0
  unsigned int v3; // r1

  v2 = sub_10EFBC(dword_10F1DC, 1);
  v3 = (v2 >> 20) & 0xF;
  if ( a1 )
  {
    if ( ((v2 >> 20) & 0xE) != 0 )
    {
      v3 = ((v3 - 2) << 20) & 0xF00000;
    }
    else if ( v3 )
    {
      v3 = ((v3 - 1) << 20) & 0xF00000;
    }
  }
  else if ( v3 > 0xD )
  {
    v3 = 15728640;
  }
  else
  {
    v3 = ((v3 + 2) << 20) & 0xF00000;
  }
  return sub_10F064(dword_10F1DC, v3, 15728640, 1);
}

