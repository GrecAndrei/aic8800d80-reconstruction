// v23 annotated: sub_12F538 @ 0x12f538
// Original: 12f538_sub_12F538.c
// Primary struct: <unclustered>
//
// sub_12F538 @ 0x12f538, size 18 bytes
int sub_12F538()
{
  int result; // r0

  if ( **(_BYTE **)off_12F54C != 3 )
    return 1;
  result = *(_DWORD *)(*(_DWORD *)off_10CBD8 + 612);
  *(_DWORD *)off_10CBDC = 32;
  if ( result )
    return 1;
  *(_DWORD *)off_10CBE0 = 32;
  return result;
}

