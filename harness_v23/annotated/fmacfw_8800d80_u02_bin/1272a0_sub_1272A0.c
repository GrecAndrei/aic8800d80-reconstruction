// v23 annotated: sub_1272A0 @ 0x1272a0
// Original: 1272a0_sub_1272A0.c
// Primary struct: <unclustered>
//
// sub_1272A0 @ 0x1272a0, size 134 bytes
int sub_1272A0()
{
  _BYTE *v0; // r4
  int v1; // r3
  int result; // r0

  v0 = off_127328;
  v1 = *((unsigned __int8 *)off_127328 + 88);
  result = v1 << 31;
  if ( (v1 & 1) != 0 )
  {
    if ( **(__int16 **)off_12732C < 0 && (v1 & 4) != 0 )
    {
      sub_12F46C(dword_12733C, dword_127338, 1720);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xFA | 4;
    return sub_127170(dword_127330);
  }
  else if ( (v1 & 6) == 2 )
  {
    if ( **(__int16 **)off_12732C < 0 && (v1 & 8) != 0 )
    {
      sub_12F46C(dword_127340, dword_127338, 1731);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xF5 | 8;
    return sub_127170(dword_127334);
  }
  return result;
}

