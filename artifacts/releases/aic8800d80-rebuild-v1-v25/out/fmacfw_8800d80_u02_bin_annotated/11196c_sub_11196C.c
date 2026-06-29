// fwstruct annotate: 11196c_sub_11196C.c
// sub_11196C @ 0x11196c, size 48 bytes
// Doc: rf_bus_write2_n_282 [rf]: Write value to RF bus register with delay
// rf_bus_write2_n_282 [rf]: Write value to RF bus register with delay
int *__fastcall sub_11196C(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int (__fastcall *v5)(_DWORD, _DWORD, int); // r3

  v2 = rf_bus_init_n_41c + 16 * (a1 - 1);
  v3 = *(unsigned __int8 *)(v2 + 8);
  result = memset_thunk((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    result = (int *)rf_bus_init_n_418;
    v5 = *(int (__fastcall **)(_DWORD, _DWORD, int))(rf_bus_init_n_418 + 4 * a1 + 32);
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

