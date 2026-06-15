// v23 annotated: sub_115FF0 @ 0x115ff0
// Original: 115ff0_sub_115FF0.c
// Primary struct: <unclustered>
//
// sub_115FF0 @ 0x115ff0, size 34 bytes
int __fastcall sub_115FF0(int a1, int a2, int a3)
{
  int v3; // r3

  v3 = dword_116014;
  **(_DWORD **)(a1 + 32) = a2;
  list_push_tail(v3 + 8 * a3);
  return irq_nesting_or(*(_DWORD *)(dword_116018 + 4 * a3));
}

