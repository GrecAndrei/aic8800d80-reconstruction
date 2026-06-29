// fwstruct annotate: 1140f0_sub_1140F0.c
// sub_1140F0 @ 0x1140f0, size 76 bytes
int __fastcall sub_1140F0(int a1)
{
  unsigned __int8 v2; // r0
  char v3; // r1
  int v4; // r4
  int v6; // r5

  v2 = sub_113A44(0x10u);
  v3 = v2 & 0xF;
  if ( (v2 & 0xF) != 0 )
  {
    v4 = v2 >> 4;
    if ( v4 )
      return -1;
    v3 = 4;
  }
  else
  {
    v4 = 1;
  }
  if ( (unsigned int)(a1 + 7) > 0xF )
    return v4 + 1;
  if ( a1 <= 0 )
    v6 = -a1;
  else
    v6 = (a1 - 1) | 8;
  host_reg_wait_set(0x10u, v6 << v3);
  return v4;
}

