// v23 annotated: sub_115E28 @ 0x115e28
// Original: 115e28_sub_115E28.c
// Primary struct: <unclustered>
//
// sub_115E28 @ 0x115e28, size 132 bytes
int sub_115E28()
{
  int **v0; // r5
  _DWORD *v1; // r6
  int *v2; // r0
  void *v3; // r8
  int v4; // r7
  unsigned __int16 v5; // r9
  int result; // r0

  v0 = (int **)off_115EB0;
  sub_12D100(dword_115EAC);
  if ( **(__int16 **)off_115EB4 < 0 )
  {
    v2 = *v0;
    v1 = off_115EB8;
    if ( !*v0 || !*(_DWORD *)off_115EB8 )
    {
      sub_12F32C(dword_115EBC, dword_115EC0, 90);
      v2 = *v0;
    }
  }
  else
  {
    v1 = off_115EB8;
    v2 = *v0;
  }
  v3 = off_115EC4;
  v4 = dword_115EAC;
  sub_100200(v2, 0, 88 * *(unsigned __int16 *)(*(_DWORD *)off_115EC4 + 8) + 88);
  v5 = 0;
  do
  {
    (*v0)[22 * v5 + 19] = *v1 + 80 * v5;
    result = sub_12D108(v4);
    ++v5;
  }
  while ( *(unsigned __int16 *)(*(_DWORD *)v3 + 8) >= (unsigned int)v5 );
  return result;
}

