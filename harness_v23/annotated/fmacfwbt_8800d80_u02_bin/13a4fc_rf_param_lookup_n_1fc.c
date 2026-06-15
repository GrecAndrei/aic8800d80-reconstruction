// v23 annotated: rf_param_lookup_n_1fc @ 0x13a4fc
// Original: 13a4fc_rf_param_lookup_n_1fc.c
// Primary struct: rf_param_tbl (cluster 14, 4 funcs)
// Fields: field1=0x26, field2=0x2c, field3=0x4c
//
// rf_param_lookup_n_1fc @ 0x13a4fc, size 64 bytes
// Doc: rf_param_lookup_n_1fc [rf]: Look up indexed RF parameter table entry
// rf_param_lookup_n_1fc [rf]: Look up indexed RF parameter table entry
int __fastcall rf_param_lookup_n_1fc(int a1, int a2)
{
  int v2; // r4
  _DWORD *v3; // r5
  int result; // r0

  v2 = a1 + 4 * a2;
  v3 = *(_DWORD **)(v2 + 408);
  if ( **(__int16 **)off_13A53C < 0 && !v3 )
    sub_12F694(dword_13A548, dword_13A544, 3320);
  timestamp_remove_058((int)(v3 + 68));
  result = list_push_tail(dword_13A540, v3);
  *(_DWORD *)(v2 + 408) = 0;
  return result;
}

