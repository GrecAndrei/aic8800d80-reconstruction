// fwstruct annotate: 1101e8_sub_1101E8.c
// sub_1101E8 @ 0x1101e8, size 62 bytes
// Doc: ipc_doorbell_handler_n44 [ipc]: Handle IPC doorbell interrupt, set MSB and check doorbell flag
// ipc_doorbell_handler_n44 [ipc]: Handle IPC doorbell interrupt, set MSB and check doorbell flag
int sub_1101E8()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)log_free_dispatch_228 = 1;
  }
  v0 = (int *)log_free_dispatch_n3cc;
  v1 = dword_110230;
  ++*(_DWORD *)log_free_dispatch_n3cc;
  result = list_push_tail(v1);
  v3 = *v0;
  ++*(_DWORD *)log_free_dispatch_n3d4;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(_DWORD *)log_free_dispatch_228;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

