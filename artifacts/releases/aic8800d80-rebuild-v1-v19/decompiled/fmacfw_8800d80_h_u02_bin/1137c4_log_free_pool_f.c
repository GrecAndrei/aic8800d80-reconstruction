// log_free_pool_f @ 0x1137c4, size 156 bytes
// Doc: log_free_pool_f [util]: Return buffer to log free pool variant F
// log_free_pool_f [util]: Return buffer to log free pool variant F
void log_free_pool_f()
{
  int *v0; // r4
  int v1; // r0
  _BYTE *v2; // r1
  int v3; // r0
  unsigned __int16 v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_113860 = 1;
  }
  v0 = (int *)off_113864;
  v1 = dword_113868;
  ++*(_DWORD *)off_113864;
  sub_12D108(v1);
  v2 = off_113870;
  v3 = *(unsigned __int8 *)off_113870;
  v4 = *(_WORD *)off_11386C + 1;
  *(_WORD *)off_11386C = v4;
  if ( v3 && *(unsigned __int8 *)off_113874 <= (unsigned int)v4 )
  {
    v7 = *(unsigned __int8 *)off_113878;
    *v2 = 0;
    if ( v7 )
      *((_DWORD *)off_11387C + 512) &= ~0x2000u;
    else
      *((_DWORD *)off_11387C + 713) &= ~1u;
    timer_set_relative(1);
    sub_12C5FC(1069, 1);
    sub_12EB90(512, dword_113880);
    if ( !*(_BYTE *)off_113884 )
      sub_113578();
  }
  if ( *v0 )
  {
    v5 = *v0 - 1;
    v6 = *(_DWORD *)off_113860;
    *v0 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
}

