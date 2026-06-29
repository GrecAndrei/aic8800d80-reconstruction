// fwstruct annotate: 117cc4_sub_117CC4.c
// sub_117CC4 @ 0x117cc4, size 66 bytes
int __fastcall sub_117CC4(int a1)
{
  _QWORD *v1; // r6
  _QWORD *v2; // r7
  int v3; // r2
  _DWORD *v4; // r4
  int result; // r0
  int *v6; // r1
  int v7; // r3
  int v8; // t1
  __int64 v9; // kr00_8
  __int64 v10; // r2

  v1 = off_117D08;
  v2 = off_117D0C;
  v3 = a1 - 4;
  v4 = off_117D08;
  result = a1 + 12;
  v6 = (int *)off_117D0C;
  do
  {
    v8 = *(_DWORD *)(v3 + 4);
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

