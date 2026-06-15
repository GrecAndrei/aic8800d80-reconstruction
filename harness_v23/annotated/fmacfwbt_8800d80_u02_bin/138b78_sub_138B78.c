// v23 annotated: sub_138B78 @ 0x138b78
// Original: 138b78_sub_138B78.c
// Primary struct: <unclustered>
//
// sub_138B78 @ 0x138b78, size 46 bytes
_DWORD **__fastcall sub_138B78(_DWORD *a1)
{
  int v1; // r5

  v1 = dword_138BA8;
  sub_138AD4(0, 4, a1[5]);
  list_remove_node_d510(v1, a1);
  list_push_tail(v1 - 8, a1);
  return sub_12F770((_DWORD **)(v1 - 32));
}

