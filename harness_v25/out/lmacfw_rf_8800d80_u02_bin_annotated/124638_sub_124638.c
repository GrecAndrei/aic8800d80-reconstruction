// fwstruct annotate: 124638_sub_124638.c
// sub_124638 @ 0x124638, size 44 bytes
// Doc: sub_1224640 [util]: Periodic counter increment utility, resets at threshold 0x64
// sub_1224640 [util]: Periodic counter increment utility, resets at threshold 0x64
int sub_124638()
{
  _WORD *v0; // r4
  int result; // r0
  int v2; // r3

  if ( *(_BYTE *)off_124664 )
  {
    v0 = off_124668;
    result = rf_table_lookup(0x81u);
    v2 = (unsigned __int16)(*v0 + 1);
    *v0 = v2;
    if ( v2 == 100 )
    {
      result = sub_12646C(4);
      *v0 = 0;
    }
  }
  return result;
}

