// rf_fault_dump_4748 @ 0x114748, size 190 bytes
// Doc: rf_fault_dump_n9e [rf]: Dump RF fault state with bounded size cap of 0x100 entries
// rf_fault_dump_n9e [rf]: Dump RF fault state with bounded size cap of 0x100 entries
void __noreturn rf_fault_dump_4748()
{
  void *v0; // r5
  int v1; // r4
  unsigned int CPSR; // r1
  unsigned int v3; // r2
  unsigned int v4; // r5
  unsigned int v5; // r4
  int v6; // r1
  int v7; // r2
  int v8; // r1
  int v9; // r2
  int v10; // r1
  int v11; // r2
  int eb18; // r0
  unsigned int v13; // r4
  unsigned int v14; // r5
  int v15; // r1

  v0 = rf_fault_dump_nc0;
  v1 = *(uint32_t *)(*(uint32_t *)rf_fault_dump_nc0 + 16);
  msg_parse(rf_fault_dump_ncc, v1, *(uint32_t *)off_114810);
  if ( (v1 & 1) != 0 )
    *(uint32_t *)(*(uint32_t *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  v3 = __get_CPSR();
  v4 = __get_CPSR();
  v5 = __get_CPSR();
  __get_CPSR();
  msg_parse(dword_114818, CPSR, v3);
  if ( v4 )
  {
    msg_parse(dword_114834, v6, v7);
    if ( !v5 )
      goto rf_fault_dump_n4c;
  }
  else if ( !v5 )
  {
    goto rf_fault_dump_n4c;
  }
  v13 = v5 & 0xFFFFFFF0;
  v14 = (rf_fault_dump_nf0 - v13) >> 2;
  msg_parse(rf_fault_handler_nf4, v6, v7);
  v15 = v14;
  if ( v14 >= 0x100 )
    v15 = 256;
  rf_mem_read_eb18(v13, v15, 4, 0);
rf_fault_dump_n4c:
  msg_parse(dword_11481C, v6, v7);
  rf_mem_read_eb18(dword_114820, 8, 4, 0);
  msg_parse(rf_fault_dump_ndc, v8, v9);
  rf_mem_read_eb18(dword_114828, 8, 4, 0);
  msg_parse(rf_fault_dump_ne4, v10, v11);
  eb18 = rf_mem_read_eb18(dword_114830, 16, 4, 0);
  patch_apply_n4a8(eb18);
}

