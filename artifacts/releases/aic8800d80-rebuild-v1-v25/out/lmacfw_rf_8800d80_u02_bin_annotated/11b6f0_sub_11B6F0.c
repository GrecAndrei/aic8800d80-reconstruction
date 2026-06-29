// fwstruct annotate: 11b6f0_sub_11B6F0.c
// sub_11B6F0 @ 0x11b6f0, size 68 bytes
int sub_11B6F0()
{
  int *v0; // r4
  int v1; // r5
  int result; // r0

  v0 = *((int **)off_11B738 + 2);
  v1 = *((_DWORD *)off_11B73C + 10);
  for ( *(_DWORD *)off_11B734 &= ~4u; v0; v0 = (int *)*v0 )
  {
    while ( v0[18] != v1 || *((_BYTE *)v0 + 94) || !*((_BYTE *)v0 + 96) )
    {
      v0 = (int *)*v0;
      if ( !v0 )
        return result;
    }
    result = rf_channel_set_n6838(
               *((unsigned __int8 *)v0 + 102),
               *((unsigned __int8 *)v0 + 94),
               *((unsigned __int8 *)v0 + 94));
  }
  return result;
}

