// sub_11930C @ 0x11930c, size 34 bytes
// Doc: sub_121930C [rf]: Unknown RF helper routine
// sub_121930C [rf]: Unknown RF helper routine
int __fastcall sub_11930C(int a1, int a2, int a3, int a4)
{
  _BYTE *v5; // r4

  v5 = (_BYTE *)rf_setup_dispatch(11, a4, a3, 3);
  *v5 = rf_dispatch_handler_n8(a2, v5 + 1, v5 + 2);
  return 0;
}

