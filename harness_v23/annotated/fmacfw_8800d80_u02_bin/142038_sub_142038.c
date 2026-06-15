// v23 annotated: sub_142038 @ 0x142038
// Original: 142038_sub_142038.c
// Primary struct: <unclustered>
//
// sub_142038 @ 0x142038, size 30 bytes
int __fastcall sub_142038(int a1)
{
  int result; // r0
  _BYTE *v3; // r2
  char v4; // r3

  result = msg_parse_top_nibble(a1);
  v3 = off_142058;
  *(_WORD *)a1 &= ~1u;
  v4 = *v3 - 1;
  *(_BYTE *)(a1 + 2) = 0;
  *v3 = v4;
  return result;
}

