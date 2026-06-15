// v23 annotated: sub_12D0D0 @ 0x12d0d0
// Original: 12d0d0_sub_12D0D0.c
// Primary struct: <unclustered>
//
// sub_12D0D0 @ 0x12d0d0, size 40 bytes
int sub_12D0D0()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r3
  void *v2; // r1

  v0 = sub_12C954();
  v1 = off_12D0F8;
  v2 = off_12D0FC;
  *((_DWORD *)off_12D0F8 + 7) = v0;
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = v2;
  return sub_12D00C(-1);
}

