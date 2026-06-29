// fwstruct annotate: 1247a4_rf_state_load.c
// rf_state_load @ 0x1247a4, size 50 bytes
// Doc: rf_state_load [rf]: Load state pointer from context struct
// rf_state_load [rf]: Load state pointer from context struct
int __fastcall rf_state_load(unsigned __int8 **a1, unsigned __int8 *a2)
{
  unsigned __int8 *v2; // r3
  unsigned __int8 *v3; // t1

  v2 = *a1;
  if ( !*a1 )
    return 0;
  do
  {
    if ( *v2 == *a2 && v2[1] == a2[1] )
      return 1;
    v3 = a1[1];
    ++a1;
    v2 = v3;
  }
  while ( v3 );
  return 0;
}

