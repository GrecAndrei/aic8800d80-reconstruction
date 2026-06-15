// v23 annotated: sub_121EE8 @ 0x121ee8
// Original: 121ee8_sub_121EE8.c
// Primary struct: <unclustered>
//
// sub_121EE8 @ 0x121ee8, size 32 bytes
// Doc: rf_cmd_dispatch_n_4b [rf]: Dispatches completed RF command response
// rf_cmd_dispatch_n_4b [rf]: Dispatches completed RF command response
int sub_121EE8()
{
  _DWORD *v0; // r4
  int v1; // r6
  int v2; // r5

  v0 = (_DWORD *)rf_mem_write_n_123;
  v1 = dword_121F0C;
  v2 = rf_mem_write_n_123 + 880;
  do
  {
    if ( v0[1] )
      sub_10DA6C(v1, *v0);
    v0 += 4;
  }
  while ( v0 != (_DWORD *)v2 );
  return 0;
}

