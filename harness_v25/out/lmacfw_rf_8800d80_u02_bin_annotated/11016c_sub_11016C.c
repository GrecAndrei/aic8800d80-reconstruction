// fwstruct annotate: 11016c_sub_11016C.c
// sub_11016C @ 0x11016c, size 52 bytes
// Doc: sub_121016C [unknown]: Initialize engine context and read state register
// sub_121016C [unknown]: Initialize engine context and read state register
int sub_11016C()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_1101A0;
  result = sub_11E71C(dword_1101A4);
  if ( *(_WORD *)(*(_DWORD *)v0 + 4) )
  {
    v2 = dword_1101A8;
    v3 = dword_1101A4;
    v4 = 0;
    do
    {
      log_pool_alloc2_a18(v2, 0x7Cu);
      result = list_push_tail(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v0 + 4) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

