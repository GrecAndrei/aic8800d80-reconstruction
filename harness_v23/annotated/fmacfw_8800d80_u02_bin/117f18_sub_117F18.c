// v23 annotated: sub_117F18 @ 0x117f18
// Original: 117f18_sub_117F18.c
// Primary struct: <unclustered>
//
// sub_117F18 @ 0x117f18, size 44 bytes
// Doc: sub_1217F18 [unknown]: Lookup 8-byte table entry by index and invoke callback
// sub_1217F18 [unknown]: Lookup 8-byte table entry by index and invoke callback
int __fastcall sub_117F18(int a1, int a2, int a3)
{
  int v3; // r3
  int v5; // r0
  int result; // r0

  v3 = *(_DWORD *)(a1 + 76);
  v5 = dword_117F44;
  *(_DWORD *)(v3 + 4) = a2;
  result = list_push_tail(v5 + 8 * a3);
  if ( (*(_DWORD *)(a1 + 36) & 0x200000) == 0 )
    return irq_nesting_or_d104(*(_DWORD *)(dword_117F48 + 4 * a3));
  return result;
}

