// v23 annotated: sub_13BEB0 @ 0x13beb0
// Original: 13beb0_sub_13BEB0.c
// Primary struct: <unclustered>
//
// sub_13BEB0 @ 0x13beb0, size 120 bytes
// Doc: sub_123BEB0 [util]: Large utility function iterating over descriptor tables from base pointers
// sub_123BEB0 [util]: Large utility function iterating over descriptor tables from base pointers
int __fastcall sub_13BEB0(int result)
{
  int v1; // r9
  int v2; // r6
  int v3; // r5
  int v4; // r7
  int v5; // r10
  int v6; // r8
  int i; // r4
  int v8; // t1

  v1 = dword_13BF34;
  v2 = dword_13BF28;
  v3 = dword_13BF2C;
  v4 = result;
  v5 = dword_13BF34 - 8;
  v6 = dword_13BF34 + 24;
  for ( i = 0; i != 32; ++i )
  {
    v8 = *(unsigned __int16 *)(v2 + 2);
    v2 += 2;
    if ( v8 && *(unsigned __int8 *)(v3 + 16) == v4 )
    {
      if ( i > 15 )
      {
        list_remove_node_d510(v6, (_DWORD *)v3);
        list_push_tail(dword_13BF30, (_DWORD *)v3);
      }
      else
      {
        list_remove_node_d510(v1, (_DWORD *)v3);
        list_push_tail(v5, (_DWORD *)v3);
      }
      rf_bus_mark_n_3b7((unsigned __int16)((_WORD)i << 8) | 8, 4);
      result = sub_13BE40(v4, (unsigned __int16)i);
    }
    v3 += 32;
  }
  return result;
}

