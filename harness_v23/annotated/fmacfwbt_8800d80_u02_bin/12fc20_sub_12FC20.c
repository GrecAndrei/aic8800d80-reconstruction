// v23 annotated: sub_12FC20 @ 0x12fc20
// Original: 12fc20_sub_12FC20.c
// Primary struct: <unclustered>
//
// sub_12FC20 @ 0x12fc20, size 32 bytes
int sub_12FC20()
{
  _DWORD *v0; // r4
  int v1; // r6
  int v2; // r5

  v0 = (_DWORD *)dword_12FC40;
  v1 = dword_12FC44;
  v2 = dword_12FC40 + 112;
  do
  {
    if ( v0[1] )
      log_printf(v1, *v0);
    v0 += 4;
  }
  while ( v0 != (_DWORD *)v2 );
  return 0;
}

