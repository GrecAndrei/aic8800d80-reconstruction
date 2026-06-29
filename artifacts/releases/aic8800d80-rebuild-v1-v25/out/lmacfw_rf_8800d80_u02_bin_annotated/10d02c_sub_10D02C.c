// fwstruct annotate: 10d02c_sub_10D02C.c
// sub_10D02C @ 0x10d02c, size 48 bytes
// Doc: sub_120D02C [mmio]: Reads MMIO register 0x40035104 and processes bit flags
// sub_120D02C [mmio]: Reads MMIO register 0x40035104 and processes bit flags
int sub_10D02C()
{
  _DWORD *v0; // r4
  int *v1; // r7
  _DWORD *v2; // r6
  int v3; // r0
  int result; // r0

  v0 = off_10D05C;
  if ( (*(_DWORD *)off_10D05C & 2) != 0 )
  {
    v1 = (int *)off_10D060;
    v2 = off_10D064;
    do
    {
      v3 = *v1;
      *v2 = 2;
      sub_10CF48((_WORD *)(v3 + 4));
    }
    while ( (*v0 & 2) != 0 );
  }
  result = sub_11E628(0x8000000);
  *(_DWORD *)off_10D068 = 2;
  return result;
}

