// v23 annotated: sub_1420A0 @ 0x1420a0
// Original: 1420a0_sub_1420A0.c
// Primary struct: <unclustered>
//
// sub_1420A0 @ 0x1420a0, size 38 bytes
int *sub_1420A0()
{
  int *v0; // r4
  int *v1; // r5
  int *result; // r0

  v0 = (int *)dword_1420CC;
  memset_thunk((int *)dword_1420C8, 0, 3u);
  v1 = v0 + 144;
  do
  {
    result = memset_thunk(v0, 0, 0x48u);
    v0[15] = (int)v0;
    v0 += 18;
  }
  while ( v0 != v1 );
  return result;
}

