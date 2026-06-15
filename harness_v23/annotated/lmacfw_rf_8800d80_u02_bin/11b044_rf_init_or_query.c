// v23 annotated: rf_init_or_query @ 0x11b044
// Original: 11b044_rf_init_or_query.c
// Primary struct: <unclustered>
//
// rf_init_or_query @ 0x11b044, size 56 bytes
// Doc: rf_init_or_query [rf]: RF subsystem init/query: calls helper and stores result on stack
// rf_init_or_query [rf]: RF subsystem init/query: calls helper and stores result on stack
int rf_init_or_query()
{
  int result; // r0
  _DWORD *v1; // r4
  char *v2; // r5
  char *v3; // r4

  result = sub_11E7AC(dword_11B07C);
  if ( result )
  {
    v1 = off_11B080;
    timestamp_remove(dword_11B084);
    v1[18] = 0;
    v2 = (char *)(v1 + 6);
    v3 = (char *)(v1 + 8);
    do
    {
      list_push_tail(v2);
      result = sub_11E7AC(v3);
    }
    while ( result );
  }
  return result;
}

