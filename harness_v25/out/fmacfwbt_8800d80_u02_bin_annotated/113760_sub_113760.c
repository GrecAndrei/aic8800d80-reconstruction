// fwstruct annotate: 113760_sub_113760.c
// sub_113760 @ 0x113760, size 156 bytes
void sub_113760()
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
    *(_DWORD *)off_1137FC = 1;
  }
  v0 = (int *)off_113800;
  v1 = dword_113804;
  ++*(_DWORD *)off_113800;
  list_push_tail(v1);
  v2 = off_11380C;
  v3 = *(unsigned __int8 *)off_11380C;
  v4 = *(_WORD *)off_113808 + 1;
  *(_WORD *)off_113808 = v4;
  if ( v3 && *(unsigned __int8 *)off_113810 <= (unsigned int)v4 )
  {
    v7 = *(unsigned __int8 *)off_113814;
    *v2 = 0;
    if ( v7 )
      *((_DWORD *)off_113818 + 512) &= ~0x2000u;
    else
      *((_DWORD *)off_113818 + 713) &= ~1u;
    hw_event_flag_1f58(1);
    sub_12C964(1069, 1);
    feature_guard_sdio(512, dword_11381C);
    if ( !*(_BYTE *)off_113820 )
      log_flush();
  }
  if ( *v0 )
  {
    v5 = *v0 - 1;
    v6 = *(_DWORD *)off_1137FC;
    *v0 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
}

