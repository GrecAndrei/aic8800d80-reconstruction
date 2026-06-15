// v23 annotated: sub_124150 @ 0x124150
// Original: 124150_sub_124150.c
// Primary struct: <unclustered>
//
// sub_124150 @ 0x124150, size 30 bytes
// Doc: sub_1224150 [util]: Packs a value into a global word using shifts and ORs
// sub_1224150 [util]: Packs a value into a global word using shifts and ORs
int __fastcall sub_124150(int a1)
{
  int v1; // r1
  int v2; // r0

  v1 = (HIWORD(*(_DWORD *)off_124170) << 16) | (a1 << 8) | a1;
  v2 = dword_124174;
  *(_DWORD *)off_124170 = v1;
  msg_parse(v2);
  return 0;
}

