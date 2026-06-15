// v23 annotated: sub_117954 @ 0x117954
// Original: 117954_sub_117954.c
// Primary struct: <unclustered>
//
// sub_117954 @ 0x117954, size 50 bytes
int __fastcall sub_117954(int a1)
{
  void *v2; // r0

  sub_11739C(a1, *(_DWORD *)(a1 + 28));
  v2 = off_117988;
  if ( !*(_DWORD *)off_117988 )
    return sub_1174EC(a1);
  *(_BYTE *)(a1 + 16) |= 1u;
  *(_DWORD *)(a1 + 4) = 0;
  return sub_11E724(v2);
}

