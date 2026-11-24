// sub_10C1B4 @ 0x10c1b4, size 56 bytes
void __fastcall __noreturn sub_10C1B4(int a1, int a2, int *a3, unsigned __int16 *a4)
{
  int v7; // r0

  sub_101E18(a1, a2, a2, 0);
  tx_phy_config(a3, (unsigned int)a4, 1, 0);
  if ( a1 == 1 )
    v7 = 132;
  else
    v7 = 129;
  sub_102BB0(v7, a4);
}
