// fwstruct annotate: 11f120_rf_phy_field_clear_n_23c.c
// rf_phy_field_clear_n_23c @ 0x11f120, size 76 bytes
// Doc: rf_phy_field_clear_n_23c [rf]: Clears/resets a 32-bit PHY field at struct offset 0x23c
// rf_phy_field_clear_n_23c [rf]: Clears/resets a 32-bit PHY field at struct offset 0x23c
int *__fastcall rf_phy_field_clear_n_23c(int a1)
{
  int v2; // r5
  int v3; // r0
  int *result; // r0
  int v5; // r3

  v2 = a1 + 572;
  while ( *(_DWORD *)(a1 + 572) )
  {
    v3 = sub_12D4F8(v2);
    sub_11913C(v3, 1);
  }
  result = memset_thunk((int *)a1, 0, 0x2B8u);
  v5 = a1;
  do
  {
    *(_BYTE *)(v5 + 452) = 33;
    *(_BYTE *)(v5 + 453) = 33;
    v5 += 12;
  }
  while ( v5 != a1 + 108 );
  *(_BYTE *)(a1 + 34) = -1;
  return result;
}

