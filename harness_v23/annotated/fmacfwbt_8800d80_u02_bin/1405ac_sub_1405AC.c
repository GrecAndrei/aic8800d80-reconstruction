// v23 annotated: sub_1405AC @ 0x1405ac
// Original: 1405ac_sub_1405AC.c
// Primary struct: <unclustered>
//
// sub_1405AC @ 0x1405ac, size 42 bytes
BOOL sub_1405AC()
{
  int v0; // r5

  v0 = dword_1405D8;
  if ( !*(_DWORD *)(dword_1405D8 + 6472) )
    return 1;
  if ( msg_get_value(0xBu) == 3 )
    return **(_DWORD **)(v0 + 6472) == 0;
  return 0;
}

