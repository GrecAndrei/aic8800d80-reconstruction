// v23 annotated: sub_13BEF8 @ 0x13bef8
// Original: 13bef8_sub_13BEF8.c
// Primary struct: <unclustered>
//
// sub_13BEF8 @ 0x13bef8, size 104 bytes
// Doc: sub_123BEF8 [util]: Indexed table lookup/handler dispatch using 32-byte stride entries
// sub_123BEF8 [util]: Indexed table lookup/handler dispatch using 32-byte stride entries
int __fastcall sub_13BEF8(unsigned int a1)
{
  int v1; // r5
  int v2; // r6
  int v3; // r7
  int v5; // r8
  int v6; // r0
  int v7; // r4

  v1 = dword_13BF60;
  v2 = dword_13BF60 + 32 * a1;
  v3 = *(unsigned __int8 *)(v2 + 16);
  v5 = 32 * a1;
  if ( a1 <= 0xF )
  {
    sub_12D2E8(dword_13BF70, (_DWORD *)v2);
    list_push_tail(dword_13BF74, (_DWORD *)v2);
  }
  else
  {
    sub_12D2E8(dword_13BF64, (_DWORD *)v2);
    list_push_tail(dword_13BF68, (_DWORD *)v2);
  }
  v6 = (a1 << 8) & 0xFF00;
  v7 = dword_13BF6C;
  sub_12CD34(v6 | 8, 4);
  *(_BYTE *)(v1 + v5 + 25) = 0;
  return sub_13B698(v3, v2, 2, 0, 0, 39, v7);
}

