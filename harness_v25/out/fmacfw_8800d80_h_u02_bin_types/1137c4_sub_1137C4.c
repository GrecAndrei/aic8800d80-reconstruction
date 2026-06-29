// sub_1137C4 @ 0x1137c4, size 156 bytes
void sub_1137C4()
{
  int *v0; // r4
  int v1; // r0
  uint8_t *v2; // r1
  int v3; // r0
  unsigned __int16 v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_113860 = 1;
  }
  v0 = (int *)off_113864;
  v1 = dword_113868;
  ++*(uint32_t *)off_113864;
  sub_12D108(v1);
  v2 = off_113870;
  v3 = *(unsigned __int8 *)off_113870;
  v4 = *(uint16_t *)off_11386C + 1;
  *(uint16_t *)off_11386C = v4;
  if ( v3 && *(unsigned __int8 *)off_113874 <= (unsigned int)v4 )
  {
    v7 = *(unsigned __int8 *)off_113878;
    *v2 = 0;
    if ( v7 )
      *((uint32_t *)off_11387C + 512) &= ~0x2000u;
    else
      *((uint32_t *)off_11387C + 713) &= ~1u;
    sub_111FBC(1);
    sub_12C5FC(1069, 1);
    sub_12EB90(512, dword_113880);
    if ( !*(uint8_t *)off_113884 )
      sub_113578();
  }
  if ( *v0 )
  {
    v5 = *v0 - 1;
    v6 = *(uint32_t *)off_113860;
    *v0 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
}

