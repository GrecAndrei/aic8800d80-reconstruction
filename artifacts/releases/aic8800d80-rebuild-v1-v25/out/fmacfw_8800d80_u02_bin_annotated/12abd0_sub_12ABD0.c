// fwstruct annotate: 12abd0_sub_12ABD0.c
// sub_12ABD0 @ 0x12abd0, size 188 bytes
int __fastcall sub_12ABD0(int a1, int a2)
{
  int v2; // r6
  int v3; // r3
  char v4; // r2
  int v5; // r4
  _DWORD *v6; // r9
  _DWORD *v7; // r8
  int v8; // r3
  int v9; // r2
  __int16 v10; // r4
  int result; // r0

  v2 = dword_12AC8C;
  v3 = dword_12AC8C + 140 * a1;
  v4 = *(_BYTE *)(v3 + 120);
  *(_BYTE *)(a2 + 9) = v4;
  v5 = *(unsigned __int8 *)(v3 + 115);
  *(_BYTE *)(v3 + 120) = v4 + 1;
  if ( v5 )
    *(_BYTE *)(a2 + 10) = v5 | 0x80;
  else
    *(_BYTE *)(a2 + 10) = 0;
  v6 = off_12AC90;
  v7 = off_12AC94;
  v8 = v2 + 140 * a1;
  v9 = a2 + 11;
  v10 = 0;
  do
  {
    if ( *(_BYTE *)(v8 + 16) && (!*(_BYTE *)(v2 + 140 * a1 + 135) || !*(_BYTE *)(v8 + 33) || *(_BYTE *)(v8 + 32) != 1) )
    {
      *(_BYTE *)v9 = *(_BYTE *)(v8 + 20);
      *(_QWORD *)(v9 + 1) = *(_QWORD *)(v8 + 24);
      v10 = (unsigned __int8)(v10 + 1);
      *(_DWORD *)(v9 + 9) = *v6 - v7[4] + *(_DWORD *)(v8 + 36);
    }
    v9 += 13;
    v8 += 48;
  }
  while ( v9 != a2 + 37 );
  result = v2 + 140 * a1;
  *(_BYTE *)(result + 136) = v10;
  *(_BYTE *)(a2 + 1) = 13 * v10 + 9;
  *(_WORD *)(a2 + 7) = 13 * v10 + 2;
  return result;
}

