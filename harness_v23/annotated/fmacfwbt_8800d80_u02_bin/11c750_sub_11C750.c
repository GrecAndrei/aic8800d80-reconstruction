// v23 annotated: sub_11C750 @ 0x11c750
// Original: 11c750_sub_11C750.c
// Primary struct: <unclustered>
//
// sub_11C750 @ 0x11c750, size 52 bytes
int sub_11C750()
{
  int result; // r0
  int v1; // r4
  int *v2; // r2
  int v3; // r3

  result = sub_12072C();
  if ( (*(_DWORD *)off_11C784 & 0x8000) != 0 && (v1 = result, (result = chip_feature_check()) != 0) && v1 )
  {
    v2 = (int *)off_11C78C;
    v3 = *(_DWORD *)off_11C78C;
    *((_DWORD *)off_11C788 + 4) = v1;
    *v2 = v3 | 0x80;
  }
  else
  {
    *((_DWORD *)off_11C788 + 4) = 0;
  }
  return result;
}

