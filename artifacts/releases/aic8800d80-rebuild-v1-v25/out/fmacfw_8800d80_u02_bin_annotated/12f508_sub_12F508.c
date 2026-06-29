// fwstruct annotate: 12f508_sub_12F508.c
// sub_12F508 @ 0x12f508, size 26 bytes
// Doc: sub_122F508 [util]: Init/clear 16-byte table and link next node (sentinel setup)
// sub_122F508 [util]: Init/clear 16-byte table and link next node (sentinel setup)
int sub_12F508()
{
  int v0; // r4

  v0 = dword_12F524;
  memset_thunk((int *)dword_12F524, 0, 0x10u);
  sub_12D240((_DWORD *)(v0 + 8));
  return 0;
}

