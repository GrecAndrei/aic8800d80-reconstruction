// v23 annotated: sub_12AEC8 @ 0x12aec8
// Original: 12aec8_sub_12AEC8.c
// Primary struct: <unclustered>
//
// sub_12AEC8 @ 0x12aec8, size 98 bytes
int sub_12AEC8()
{
  int v0; // r5
  int v1; // r4
  int v2; // r0
  int v3; // r2

  v0 = *(_DWORD *)off_12AF2C;
  v1 = *((unsigned __int8 *)off_12AF2C + 10);
  if ( sub_12CD48(2) != 2 )
  {
    v2 = sub_12CD48(2);
    sub_12E948(dword_12AF30, v2, v3);
  }
  if ( **(__int16 **)off_12AF34 < 0 && sub_12CD48(2) != 2 )
    sub_12F32C(dword_12AF3C, dword_12AF38, 163);
  if ( (*(_BYTE *)(v0 + 6 * v1 + 3) & 1) == 0 )
    sub_12B258();
  sub_12CBF4(2);
  return 0;
}

