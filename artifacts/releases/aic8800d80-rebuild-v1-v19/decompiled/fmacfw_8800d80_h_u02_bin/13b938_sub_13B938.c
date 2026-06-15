// sub_13B938 @ 0x13b938, size 72 bytes
int __fastcall sub_13B938(int **a1)
{
  int *v1; // r6
  int result; // r0
  unsigned int v3; // r4
  int **v4; // r3
  int *v5; // r1
  unsigned int v6; // r2
  int v7; // r3

  v1 = *a1;
  if ( !*a1 )
    return 33;
  result = 0;
  v3 = 0;
  v4 = (int **)v1;
  do
  {
    v5 = v4[2];
    v6 = *((_DWORD *)off_13B980 + 4) - (_DWORD)v5;
    if ( v6 > v3 )
      result = *((unsigned __int8 *)v4 + 26);
    v4 = (int **)*v4;
    if ( v6 > v3 )
      v3 = *((_DWORD *)off_13B980 + 4) - (_DWORD)v5;
  }
  while ( v4 );
  v7 = dword_13B984 + 32 * result;
  if ( v3 <= *(unsigned __int16 *)(v7 + 14) << 10 || *(_DWORD *)(v7 + 4) )
    return *((unsigned __int8 *)v1 + 26);
  else
    return (unsigned __int16)result;
}

