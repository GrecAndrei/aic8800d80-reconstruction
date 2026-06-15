// v23 annotated: sub_1159CC @ 0x1159cc
// Original: 1159cc_sub_1159CC.c
// Primary struct: <unclustered>
//
// sub_1159CC @ 0x1159cc, size 72 bytes
// Doc: rf_bus_setup_n396_59ce [rf]: Pack and store RF bus register fields from descriptor bytes
// rf_bus_setup_n396_59ce [rf]: Pack and store RF bus register fields from descriptor bytes
void __fastcall __noreturn sub_1159CC(int a1)
{
  log_printf(dword_115A14);
  switch ( a1 )
  {
    case '0':
      log_printf(dword_115A24);
      break;
    case '@':
      log_printf(dword_115A2C);
      break;
    case ' ':
      log_printf(dword_115A28);
      break;
    default:
      log_printf(dword_115A18);
      break;
  }
  log_printf(dword_115A1C);
  patch_apply_n280();
  log_printf(dword_115A20);
  patch_apply_n4a8_5990();
}

