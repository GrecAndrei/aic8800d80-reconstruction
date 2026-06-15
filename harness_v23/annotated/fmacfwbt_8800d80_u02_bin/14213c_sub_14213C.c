// v23 annotated: sub_14213C @ 0x14213c
// Original: 14213c_sub_14213C.c
// Primary struct: <unclustered>
//
// sub_14213C @ 0x14213c, size 38 bytes
// Doc: sub_124213C [util]: Initialize firmware data structure via memset and setup callback
// sub_124213C [util]: Initialize firmware data structure via memset and setup callback
int *sub_14213C()
{
  int *v0; // r4
  int *v1; // r5
  int *result; // r0

  v0 = (int *)dword_142168;
  memset_thunk((int *)dword_142164, 0, 3u);
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

