// fwstruct annotate: 102b64_sub_102B64.c
// sub_102B64 @ 0x102b64, size 106 bytes
int __fastcall sub_102B64(int result)
{
  int v1; // r4
  bool v2; // zf
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r3

  v2 = result == 0;
  if ( result )
    v3 = -5;
  else
    v3 = -65;
  v4 = *(_DWORD *)off_102BD0 & v3;
  if ( !result )
    result = 32;
  *(_DWORD *)off_102BD0 = v4;
  if ( v2 )
    v1 = -17;
  else
    result = 2;
  if ( v2 )
    v3 = 16;
  else
    v1 = -2;
  if ( !v2 )
    v3 = 1;
  LOBYTE(v5) = -56;
  do
    v5 = (unsigned __int8)(v5 - 1);
  while ( v5 );
  v6 = v4 & v1;
  *(_DWORD *)off_102BD0 = v6;
  LOBYTE(v7) = 50;
  do
    v7 = (unsigned __int8)(v7 - 1);
  while ( v7 );
  v8 = v6 | result;
  *(_DWORD *)off_102BD0 = v8;
  LOBYTE(v9) = 50;
  do
    v9 = (unsigned __int8)(v9 - 1);
  while ( v9 );
  *(_DWORD *)off_102BD0 = v8 | v3;
  return result;
}

