// v23 annotated: sub_12BAB0 @ 0x12bab0
// Original: 12bab0_sub_12BAB0.c
// Primary struct: <unclustered>
//
// sub_12BAB0 @ 0x12bab0, size 48 bytes
int __fastcall sub_12BAB0(int *a1)
{
  _DWORD *v1; // r2
  int *v2; // r3
  int v3; // r4
  int v4; // r0
  int v5; // r0

  v1 = off_12BAE4;
  v2 = (int *)off_12BAE8;
  v3 = *a1;
  v4 = *((unsigned __int16 *)a1 + 2);
  *(_DWORD *)off_12BAE0 = v3;
  *v1 = v4;
  *v2 = 0x20000000;
  do
    v5 = *v2;
  while ( (*v2 & 0x20000000) != 0 );
  if ( (v5 & 0x10000000) != 0 )
    return 255;
  else
    return (unsigned __int8)(BYTE2(v5) - 16);
}

