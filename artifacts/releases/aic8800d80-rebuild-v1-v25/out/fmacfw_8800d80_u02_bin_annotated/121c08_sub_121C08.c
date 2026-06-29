// fwstruct annotate: 121c08_sub_121C08.c
// sub_121C08 @ 0x121c08, size 148 bytes
int sub_121C08()
{
  int *v1; // r4
  int v2; // r3
  int v3; // r2

  if ( **(__int16 **)off_121C9C < 0 && (msg_get_value(0) == 3 || !msg_get_value(0)) )
    sub_12F46C(dword_121CB8, dword_121CB4, 1862);
  if ( msg_get_value(0) == 2 )
  {
    *(_DWORD *)off_121CA0 = 48;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_121CA4 = 1;
    }
    v1 = (int *)off_121CA8;
    ++*(_DWORD *)off_121CA8;
    clear_flags(0x2000000);
    if ( (*(_DWORD *)off_121CAC & 4) != 0 )
      *(_DWORD *)off_121CB0 = 4;
    if ( *v1 )
    {
      v2 = *v1 - 1;
      v3 = *(_DWORD *)off_121CA4;
      *v1 = v2;
      if ( !v2 )
      {
        if ( v3 )
          __enable_irq();
      }
    }
  }
  return sub_12CD34(0);
}

