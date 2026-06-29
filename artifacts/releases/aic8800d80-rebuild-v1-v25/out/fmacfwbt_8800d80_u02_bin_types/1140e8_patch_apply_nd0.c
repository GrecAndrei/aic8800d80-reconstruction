// patch_apply_nd0 @ 0x1140e8, size 72 bytes
// Doc: patch_apply_nd0 [patch]: Apply 0xff-terminated patch entries to a register window
// patch_apply_nd0 [patch]: Apply 0xff-terminated patch entries to a register window
int patch_apply_nd0()
{
  int *v0; // r5
  uint32_t *v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_114130 = 1;
  }
  v0 = (int *)off_114134;
  v1 = off_114138;
  ++*(uint32_t *)off_114134;
  while ( !*v1 )
    ;
  result = list_push_tail(*(uint32_t *)off_11413C + 564);
  *v1 = 1;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_114130;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

