// v23 annotated: sub_128EF8 @ 0x128ef8
// Original: 128ef8_sub_128EF8.c
// Primary struct: <unclustered>
//
// sub_128EF8 @ 0x128ef8, size 28 bytes
int sub_128EF8()
{
  _DWORD *v0; // r4
  int *v1; // r0
  int result; // r0

  v0 = off_128F14;
  v1 = sub_100200((int *)off_128F14, 0, 0x28u);
  result = sub_1420A0(v1);
  v0[4] = off_128F18;
  *((_BYTE *)v0 + 28) = 1;
  return result;
}

