// call_hook_1 @ 0x114840, size 8 bytes
// Doc: rf_fault_dump_842 [rf]: Dump RF subsystem state on fault
// rf_fault_dump_842 [rf]: Dump RF subsystem state on fault
int call_hook_1()
{
  return MEMD(508)();
}

