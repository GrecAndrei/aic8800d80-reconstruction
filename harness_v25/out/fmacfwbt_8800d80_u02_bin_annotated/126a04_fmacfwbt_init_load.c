// fwstruct annotate: 126a04_fmacfwbt_init_load.c
// fmacfwbt_init_load @ 0x126a04, size 56 bytes
// Doc: fmacfwbt_init_load [util]: Initialize FMAC+BT firmware image from 0x190c50 table
// fmacfwbt_init_load [util]: Initialize FMAC+BT firmware image from 0x190c50 table
int fmacfwbt_init_load()
{
  int result; // r0
  _DWORD *v1; // r4
  char *v2; // r5
  char *v3; // r4

  result = sub_12D4F8(dword_126A3C);
  if ( result )
  {
    v1 = off_126A40;
    timestamp_remove_058(dword_126A44);
    v1[18] = 0;
    v2 = (char *)(v1 + 6);
    v3 = (char *)(v1 + 8);
    do
    {
      list_push_tail(v2);
      result = sub_12D4F8(v3);
    }
    while ( result );
  }
  return result;
}

