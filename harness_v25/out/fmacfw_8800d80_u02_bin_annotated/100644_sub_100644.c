// fwstruct annotate: 100644_sub_100644.c
// sub_100644 @ 0x100644, size 40 bytes
int __fastcall sub_100644(int a1)
{
  int result; // r0
  int v3; // [sp+4h] [bp-8h]

  result = a1 + *((_DWORD *)off_10066C + 4);
  do
  {
    v3 = 32;
    while ( v3-- )
      ;
  }
  while ( *((_DWORD *)off_10066C + 4) - result < 0 );
  return result;
}

