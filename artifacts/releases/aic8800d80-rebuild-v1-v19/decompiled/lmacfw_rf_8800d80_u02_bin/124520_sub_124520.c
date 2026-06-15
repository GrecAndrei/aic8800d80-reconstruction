// sub_124520 @ 0x124520, size 90 bytes
void sub_124520()
{
  _WORD *v0; // r4
  int v1; // r0
  int v2; // r3
  int v3; // r3

  if ( *(_BYTE *)off_12457C != 1 )
  {
    v0 = off_124580;
    v1 = rf_table_lookup(0);
    v2 = (unsigned __int16)(*v0 + 1);
    *v0 = v2;
    if ( v2 == 1000 )
    {
      if ( (unsigned int)*(unsigned __int8 *)off_124584 - 2 <= 1 )
      {
        *v0 = 0;
        rf_init_n_dc(v1);
      }
      else
      {
        sub_12646C(2);
        v3 = *(_DWORD *)off_124588;
        *(_DWORD *)off_12458C = *(_DWORD *)off_124588;
        *v0 = 0;
        *(_DWORD *)off_124590 = v3 + 1000000;
      }
    }
  }
}

