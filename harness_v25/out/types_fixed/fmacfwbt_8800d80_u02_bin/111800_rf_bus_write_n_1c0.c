// rf_bus_write_n_1c0 @ 0x111800, size 48 bytes
// Doc: rf_bus_reset2_1812 [rf]: Helper tail-call into bus reset primitive
// rf_bus_reset2_1812 [rf]: Helper tail-call into bus reset primitive
int *__fastcall rf_bus_write_n_1c0(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int (__fastcall *v5)(_DWORD, _DWORD, int); // r3

  v2 = rf_bus_write2_1830 + 16 * (a1 - 1);
  v3 = *(unsigned __int8 *)(v2 + 11);
  result = memset_thunk((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    v5 = *(int (__fastcall **)(_DWORD, _DWORD, int))(rf_bus_write_n_18c + 4 * (a1 + 13));
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

