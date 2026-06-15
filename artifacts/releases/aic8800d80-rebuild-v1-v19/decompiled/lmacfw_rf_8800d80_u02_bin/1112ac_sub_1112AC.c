// sub_1112AC @ 0x1112ac, size 48 bytes
// Doc: rf_cmd_dispatch_n1b4 [rf]: Dispatches RF command requests from MAC scheduler
// rf_cmd_dispatch_n1b4 [rf]: Dispatches RF command requests from MAC scheduler
int *__fastcall sub_1112AC(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int (__fastcall *v5)(_DWORD, _DWORD, int); // r3

  v2 = dword_1112DC + 16 * (a1 - 1);
  v3 = *(unsigned __int8 *)(v2 + 11);
  result = sub_100200((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    v5 = *(int (__fastcall **)(_DWORD, _DWORD, int))(rf_bus_write2_n_244 + 4 * (a1 + 13));
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

