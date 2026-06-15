// rf_cmd_wait_n_7e @ 0x114868, size 44 bytes
// Doc: rf_fault_dump_n132 [rf]: RF fault dump handler (variant n132)
// rf_fault_dump_n132 [rf]: RF fault dump handler (variant n132)
int __fastcall rf_cmd_wait_n_7e(_BYTE *a1)
{
  __int16 v2; // r0

  v2 = MEMORY[0x1FC](6);
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

