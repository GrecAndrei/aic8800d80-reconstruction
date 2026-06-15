// v23 annotated: ipc_doorbell_handler_n_1a4 @ 0x1157d8
// Original: 1157d8_ipc_doorbell_handler_n_1a4.c
// Primary struct: <unclustered>
//
// ipc_doorbell_handler_n_1a4 @ 0x1157d8, size 346 bytes
// Doc: ipc_doorbell_handler_n_170 [ipc]: Handles IPC doorbell interrupts and clears status bits
// ipc_doorbell_handler_n_170 [ipc]: Handles IPC doorbell interrupts and clears status bits
void __fastcall ipc_doorbell_handler_n_1a4(int a1, int a2)
{
  int v2; // r3
  int v3; // r1
  int v4; // r0
  _DWORD *v5; // r3

  v2 = **(unsigned __int16 **)ipc_doorbell_handler_n_48;
  if ( (v2 & 1) != 0 )
    ((void (__fastcall *)(int, int, int))fmac_init_subsystems)(a1, a2, v2 << 31);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)ipc_doorbell_handler_938 = 1;
  }
  v3 = ipc_doorbell_handler_944;
  ++*(_DWORD *)ipc_doorbell_handler_n_40;
  feature_guard_check(1024, v3);
  v4 = clear_flags(0x80000000);
  mmio_reg_clear_bits_n3c(v4);
  v5 = ipc_doorbell_handler_n_33;
  *(_DWORD *)ipc_doorbell_handler_n_33 &= 0xFFFFFFu;
  *v5 |= 0x10u;
  while ( 1 )
    ;
}

