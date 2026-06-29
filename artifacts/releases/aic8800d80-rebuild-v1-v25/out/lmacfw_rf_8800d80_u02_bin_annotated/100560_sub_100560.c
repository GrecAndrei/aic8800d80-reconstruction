// fwstruct annotate: 100560_sub_100560.c
// sub_100560 @ 0x100560, size 40 bytes
int __fastcall sub_100560(int a1)
{
  int result; // r0
  int v3; // [sp+4h] [bp-8h]

  result = a1 + *((_DWORD *)off_100588 + 4);
  do
  {
    v3 = 32;
    while ( v3-- )
      ;
  }
  while ( *((_DWORD *)off_100588 + 4) - result < 0 );
  return result;
}

