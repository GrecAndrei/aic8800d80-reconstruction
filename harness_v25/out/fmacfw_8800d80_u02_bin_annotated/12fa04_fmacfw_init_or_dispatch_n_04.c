// fwstruct annotate: 12fa04_fmacfw_init_or_dispatch_n_04.c
// fmacfw_init_or_dispatch_n_04 @ 0x12fa04, size 32 bytes
// Doc: fmacfw_init_or_dispatch_n_04 [util]: Initialize fmacfw global structure and dispatch
// fmacfw_init_or_dispatch_n_04 [util]: Initialize fmacfw global structure and dispatch
int fmacfw_init_or_dispatch_n_04()
{
  _DWORD *v0; // r4
  int v1; // r6
  int v2; // r5

  v0 = (_DWORD *)dword_12FA24;
  v1 = dword_12FA28;
  v2 = dword_12FA24 + 112;
  do
  {
    if ( v0[1] )
      sub_10DC24(v1, *v0);
    v0 += 4;
  }
  while ( v0 != (_DWORD *)v2 );
  return 0;
}

