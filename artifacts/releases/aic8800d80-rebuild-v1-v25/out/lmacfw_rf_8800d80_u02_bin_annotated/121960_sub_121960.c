// fwstruct annotate: 121960_sub_121960.c
// sub_121960 @ 0x121960, size 82 bytes
int __fastcall sub_121960(int a1, int a2, int a3)
{
  int *v4; // r4
  int v5; // r0
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1219B4 = 1;
  }
  v4 = (int *)off_1219B8;
  v5 = dword_1219BC;
  ++*(_DWORD *)off_1219B8;
  result = msg_parse(v5, a1, a2, a3 & 0xFFFFF);
  if ( *(int *)off_1219C0 >= 0 )
  {
    sub_11D31C();
    result = irq_nesting_or(0x80000000);
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(_DWORD *)off_1219B4;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

