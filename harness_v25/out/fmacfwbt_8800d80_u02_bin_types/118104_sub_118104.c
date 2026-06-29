// sub_118104 @ 0x118104, size 66 bytes
// Doc: sub_1218104 [util]: Memory/buffer offset utility: computes 4-byte aligned offsets using 0x3e8 stride
// sub_1218104 [util]: Memory/buffer offset utility: computes 4-byte aligned offsets using 0x3e8 stride
int  sub_118104(int a1)
{
  QWORD *v1; // r6
  QWORD *v2; // r7
  int v3; // r2
  uint32_t *v4; // r4
  int result; // r0
  int *v6; // r1
  int v7; // r3
  int v8; // t1
  uint64_t v9; // kr00_8
  uint64_t v10; // r2

  v1 = off_118148;
  v2 = off_11814C;
  v3 = a1 - 4;
  v4 = off_118148;
  result = a1 + 12;
  v6 = (int *)off_11814C;
  do
  {
    v8 = *(uint32_t *)(v3 + 4);
    v3 += 4;
    v7 = v8;
    if ( !v8 )
      v7 = *v6;
    *v4++ = 1000 * v7;
    ++v6;
  }
  while ( v3 != result );
  v9 = v2[2];
  LODWORD(v10) = 1000 * v9;
  HIDWORD(v10) = 1000 * HIDWORD(v9);
  v1[2] = v10;
  return result;
}

