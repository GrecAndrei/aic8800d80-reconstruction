// fwstruct annotate: 111274_rf_bus_mark_ne8.c
// rf_bus_mark_ne8 @ 0x111274, size 48 bytes
// Doc: rf_bus_mark_n102 [rf]: Mark/flag RF bus slot for pending operation
// rf_bus_mark_n102 [rf]: Mark/flag RF bus slot for pending operation
int *__fastcall rf_bus_mark_ne8(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int (__fastcall *v5)(_DWORD, _DWORD, int); // r3

  v2 = rf_bus_reset2_n_60 + 16 * (a1 - 1);
  v3 = *(unsigned __int8 *)(v2 + 8);
  result = sub_100200((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    result = (int *)rf_bus_write_n_1c4;
    v5 = *(int (__fastcall **)(_DWORD, _DWORD, int))(rf_bus_write_n_1c4 + 4 * a1 + 32);
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

