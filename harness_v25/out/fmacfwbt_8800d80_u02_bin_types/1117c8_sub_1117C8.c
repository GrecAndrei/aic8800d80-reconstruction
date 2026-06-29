// sub_1117C8 @ 0x1117c8, size 48 bytes
// Doc: rf_bus_mark_nfa_17da [rf]: Mark RF bus state via helper call
// rf_bus_mark_nfa_17da [rf]: Mark RF bus state via helper call
int * sub_1117C8(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int ( *v5)(uint32_t, uint32_t, int); // r3

  v2 = rf_bus_write_n_1c8 + 16 * (a1 - 1);
  v3 = *(unsigned __int8 *)(v2 + 8);
  result = memset_thunk((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    result = (int *)dword_1117FC;
    v5 = *(int ( **)(uint32_t, uint32_t, int))(dword_1117FC + 4 * a1 + 32);
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

