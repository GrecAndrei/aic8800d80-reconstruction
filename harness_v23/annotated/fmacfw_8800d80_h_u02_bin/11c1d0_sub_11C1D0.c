// v23 annotated: sub_11C1D0 @ 0x11c1d0
// Original: 11c1d0_sub_11C1D0.c
// Primary struct: <unclustered>
//
// sub_11C1D0 @ 0x11c1d0, size 52 bytes
int sub_11C1D0()
{
  int result; // r0
  int v1; // r4
  int *v2; // r2
  int v3; // r3

  result = sub_1202B4();
  if ( (*(_DWORD *)off_11C204 & 0x8000) != 0 && (v1 = result, (result = sub_101950()) != 0) && v1 )
  {
    v2 = (int *)off_11C20C;
    v3 = *(_DWORD *)off_11C20C;
    *((_DWORD *)off_11C208 + 4) = v1;
    *v2 = v3 | 0x80;
  }
  else
  {
    *((_DWORD *)off_11C208 + 4) = 0;
  }
  return result;
}

