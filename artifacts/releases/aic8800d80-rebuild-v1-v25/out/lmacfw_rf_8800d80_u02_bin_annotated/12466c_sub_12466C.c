// fwstruct annotate: 12466c_sub_12466C.c
// sub_12466C @ 0x12466c, size 112 bytes
void sub_12466C()
{
  int v0; // r0

  v0 = sub_11E628(0x2000);
  if ( is_flag_set_n645c(v0) )
  {
    switch ( *(_BYTE *)off_1246DC )
    {
      case 1:
        sub_124520();
        break;
      case 2:
        sub_124594();
        break;
      case 3:
        sub_124638();
        break;
      case 4:
        if ( *(_BYTE *)off_1246EC != 1 )
          log_free_dispatch_n2f2();
        break;
      case 5:
        rf_init_or_reset_sub_12245f0();
        break;
      default:
        return;
    }
  }
  else if ( *(_DWORD *)off_1246E0 )
  {
    if ( !*(_BYTE *)off_1246E8 )
      rf_sub_3bbc();
  }
  else
  {
    *(_DWORD *)off_1246E4 = 0;
  }
}

