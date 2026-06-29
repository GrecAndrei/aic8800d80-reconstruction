// fwstruct annotate: 1163a8_sub_1163A8.c
// sub_1163A8 @ 0x1163a8, size 132 bytes
int sub_1163A8()
{
  int **v0; // r5
  _DWORD *v1; // r6
  int *v2; // r0
  void *v3; // r8
  int v4; // r7
  unsigned __int16 v5; // r9
  int result; // r0

  v0 = (int **)off_116430;
  sub_12D468(dword_11642C);
  if ( **(__int16 **)off_116434 < 0 )
  {
    v2 = *v0;
    v1 = off_116438;
    if ( !*v0 || !*(_DWORD *)off_116438 )
    {
      sub_12F694(dword_11643C, dword_116440, 90);
      v2 = *v0;
    }
  }
  else
  {
    v1 = off_116438;
    v2 = *v0;
  }
  v3 = off_116444;
  v4 = dword_11642C;
  sub_100200(v2, 0, 88 * *(unsigned __int16 *)(*(_DWORD *)off_116444 + 8) + 88);
  v5 = 0;
  do
  {
    (*v0)[22 * v5 + 19] = *v1 + 80 * v5;
    result = sub_12D470(v4);
    ++v5;
  }
  while ( *(unsigned __int16 *)(*(_DWORD *)v3 + 8) >= (unsigned int)v5 );
  return result;
}

