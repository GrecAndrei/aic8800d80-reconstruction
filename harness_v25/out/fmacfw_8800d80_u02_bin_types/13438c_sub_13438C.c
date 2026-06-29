// sub_13438C @ 0x13438c, size 80 bytes
int sub_13438C()
{
  int *v0; // r4
  uint8_t *v1; // r2
  int v2; // r1
  int v3; // r3
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1343DC = 1;
  }
  v0 = (int *)off_1343E0;
  v1 = off_1343E4;
  v2 = *((unsigned __int8 *)off_1343E4 + 15);
  v3 = *(uint32_t *)off_1343E0 + 1;
  *(uint32_t *)off_1343E0 = v3;
  if ( v2 )
  {
    sub_134368();
    v3 = *v0;
  }
  else if ( v1[14] == 1 )
  {
    sub_1346E8();
    v3 = *v0;
  }
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(uint32_t *)off_1343DC;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  msg_parse(dword_1343E8);
  return 0;
}

