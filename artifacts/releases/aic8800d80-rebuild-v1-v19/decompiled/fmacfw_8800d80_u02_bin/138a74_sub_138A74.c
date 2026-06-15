// sub_138A74 @ 0x138a74, size 46 bytes
// Doc: sub_1238A74 [util]: Helper that calls sub-function with arg 4 and returns result
// sub_1238A74 [util]: Helper that calls sub-function with arg 4 and returns result
_DWORD **__fastcall sub_138A74(_DWORD *a1)
{
  int v1; // r5

  v1 = dword_138AA4;
  sub_1389D0(0, 4, a1[5]);
  sub_12D2E8(v1, a1);
  list_push_tail(v1 - 8, a1);
  return sub_12F554((_DWORD **)(v1 - 32));
}

