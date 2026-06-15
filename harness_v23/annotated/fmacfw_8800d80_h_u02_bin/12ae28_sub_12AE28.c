// v23 annotated: sub_12AE28 @ 0x12ae28
// Original: 12ae28_sub_12AE28.c
// Primary struct: <unclustered>
//
// sub_12AE28 @ 0x12ae28, size 138 bytes
int sub_12AE28()
{
  int v0; // r0
  int v1; // r2
  _BYTE *v2; // r4
  int v3; // r0
  unsigned int v4; // r2
  unsigned int v5; // r3
  int v6; // r1

  if ( sub_12CD48(2) != 3 )
  {
    v0 = sub_12CD48(2);
    sub_12E948(dword_12AEB4, v0, v1);
  }
  if ( **(__int16 **)off_12AEB8 < 0 && sub_12CD48(2) != 3 )
    sub_12F32C(dword_12AEC4, dword_12AEC0, 201);
  v2 = off_12AEBC;
  v3 = *(_DWORD *)off_12AEBC;
  v4 = *(unsigned __int8 *)(*(_DWORD *)off_12AEBC + 367);
  v5 = (unsigned __int8)(*((_BYTE *)off_12AEBC + 10) + 1);
  *((_BYTE *)off_12AEBC + 10) = v5;
  if ( v4 <= v5 || v2[11] )
  {
    sub_12C8F8(v3 - 12);
    v6 = *((unsigned __int16 *)v2 + 4);
    if ( v2[11] )
    {
      sub_12B3A4(0, v6);
      v2[11] = 0;
    }
    else
    {
      sub_12C8D0(2050, v6, 2);
    }
    sub_12CBF4(2);
    return 0;
  }
  else
  {
    sub_12B064();
    return 0;
  }
}

