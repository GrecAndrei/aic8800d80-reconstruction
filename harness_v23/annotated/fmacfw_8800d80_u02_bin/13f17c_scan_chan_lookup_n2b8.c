// v23 annotated: scan_chan_lookup_n2b8 @ 0x13f17c
// Original: 13f17c_scan_chan_lookup_n2b8.c
// Primary struct: <unclustered>
//
// scan_chan_lookup_n2b8 @ 0x13f17c, size 174 bytes
// Doc: scan_chan_lookup_n2b8 [scan]: Lookup channel entry from 0x2b8-stride table
// scan_chan_lookup_n2b8 [scan]: Lookup channel entry from 0x2b8-stride table
int __fastcall scan_chan_lookup_n2b8(int a1, unsigned int a2, unsigned int a3)
{
  __int16 **v3; // r8
  int v4; // r3
  int result; // r0
  _BYTE *v7; // r4
  __int16 *v10; // r3

  v3 = (__int16 **)off_13F240;
  v4 = dword_13F22C + 696 * a1;
  result = **(__int16 **)off_13F240;
  v7 = *(_BYTE **)(v4 + 340);
  if ( result < 0 && !v7 )
    result = sub_12F46C(dword_13F234, dword_13F230, 3326);
  if ( (unsigned __int8)v7[179] != a2 || (unsigned __int8)v7[180] != a3 )
  {
    v10 = *v3;
    v7[179] = a2;
    if ( *v10 < 0 && a2 > 3 )
    {
      result = sub_12F46C(dword_13F23C, dword_13F230, 3332);
      v10 = *v3;
    }
    v7[180] = a3;
    if ( *v10 < 0 && a3 > 7 )
      result = sub_12F46C(dword_13F238, dword_13F230, 3334);
    if ( (v7[166] & 0x20) != 0 )
      v7[166] |= 0x80u;
    else
      return mac_table_lookup(a1);
  }
  return result;
}

