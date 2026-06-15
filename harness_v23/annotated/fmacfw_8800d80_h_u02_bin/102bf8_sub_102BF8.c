// v23 annotated: sub_102BF8 @ 0x102bf8
// Original: 102bf8_sub_102BF8.c
// Primary struct: <unclustered>
//
// sub_102BF8 @ 0x102bf8, size 96 bytes
int *__fastcall sub_102BF8(int a1)
{
  int v1; // r4
  int v2; // r1
  bool v3; // zf
  int v4; // r2
  int v5; // r2
  int v6; // r3
  int *result; // r0
  int v8; // r2
  int v9; // r3

  v2 = (int)off_102C58;
  v3 = a1 == 0;
  if ( a1 )
    v4 = -2;
  else
    v4 = -17;
  v5 = v4 & *(_DWORD *)off_102C58;
  if ( !a1 )
    a1 = -33;
  *(_DWORD *)off_102C58 = v5;
  if ( v3 )
    v2 = 64;
  else
    a1 = -3;
  if ( v3 )
    v1 = 16;
  else
    v2 = 4;
  if ( !v3 )
    v1 = 1;
  LOBYTE(v6) = 50;
  do
    v6 = (unsigned __int8)(v6 - 1);
  while ( v6 );
  v9 = v5 & a1;
  result = (int *)off_102C58;
  v8 = v9 | v2;
  *(_DWORD *)off_102C58 = v9;
  LOBYTE(v9) = 50;
  *result = v8;
  do
    v9 = (unsigned __int8)(v9 - 1);
  while ( v9 );
  *(_DWORD *)off_102C58 = v8 | v1;
  return result;
}

