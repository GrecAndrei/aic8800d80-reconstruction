// fwstruct annotate: 101de8_sub_101DE8.c
// sub_101DE8 @ 0x101de8, size 2412 bytes
void __fastcall __noreturn sub_101DE8(int a1, int a2, int a3, int a4)
{
  sub_12ECB0(dword_102134, dword_102130, a1);
  if ( **(_BYTE **)off_102138 != 3 )
    feature_guard_sdio(4, dword_10213C);
  variant_update_cache(a4);
  rf_calib_init_handler();
}

