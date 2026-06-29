// rf_state_check @ 0x112030, size 66 bytes
// Doc: rf_bus_setup_n30c [rf]: Setup RF bus with branch-out to sub-init
// rf_bus_setup_n30c [rf]: Setup RF bus with branch-out to sub-init
int rf_state_check()
{
  uint8_t *v0; // r4
  int v1; // r0
  int ( *v3)(uint32_t); // r3

  v0 = patch_apply_n_224;
  v1 = *((unsigned __int16 *)patch_apply_n_224 + 7);
  *(uint16_t *)off_112078 = v1;
  if ( v1 )
  {
    v3 = *((int ( **)(uint32_t))off_112080 + 5);
    if ( v3 && v3((unsigned __int8)v1) )
    {
      *(uint8_t *)patch_apply_n24 = 4;
      *v0 = 7;
      if ( !rf_bus_setup_38e8() )
        sub_113FC4(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(uint8_t *)patch_apply_n24 = 3;
    return 1;
  }
}

