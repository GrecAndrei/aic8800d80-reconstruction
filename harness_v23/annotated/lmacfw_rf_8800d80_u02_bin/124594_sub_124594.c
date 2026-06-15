// v23 annotated: sub_124594 @ 0x124594
// Original: 124594_sub_124594.c
// Primary struct: <unclustered>
//
// sub_124594 @ 0x124594, size 72 bytes
// Doc: sub_1224594 [unknown]: Check shared init flag byte and branch on ready state
// sub_1224594 [unknown]: Check shared init flag byte and branch on ready state
int sub_124594()
{
  _WORD *v0; // r4
  int result; // r0
  int v2; // r3
  _DWORD *v3; // r2
  int v4; // r0

  if ( *(_BYTE *)off_1245DC != 1 )
  {
    v0 = off_1245E0;
    result = rf_table_lookup(1u);
    v2 = (unsigned __int16)(*v0 + 1);
    *v0 = v2;
    if ( v2 == 1000 )
    {
      sub_12646C(3);
      v3 = off_1245EC;
      v4 = *(_DWORD *)off_1245E4 + 19968;
      *(_DWORD *)off_1245E8 = 0;
      *v0 = 0;
      *v3 = 0;
      return mmio_write_40320150(v4 + 32);
    }
  }
  return result;
}

