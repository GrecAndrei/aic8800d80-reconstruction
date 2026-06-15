// patch_apply_n_368 @ 0x115180, size 44 bytes
// Doc: rf_bus_reset2_n_312 [rf]: Resets RF bus using config pointers from data section
// rf_bus_reset2_n_312 [rf]: Resets RF bus using config pointers from data section
int __fastcall patch_apply_n_368(_BYTE *a1)
{
  __int16 v2; // r0

  v2 = MEMORY[0x1FC](15);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (_BYTE)v2 )
      return 1;
    else
      return 2;
  }
}

