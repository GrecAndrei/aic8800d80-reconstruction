// call_indirect_table @ 0x10efa4, size 8 bytes
// Doc: call_indirect_table [rf]: RF register read callback dispatch table (0x1b0/0x1b4/0x1b8)
// call_indirect_table [rf]: RF register read callback dispatch table (0x1b0/0x1b4/0x1b8)
int call_indirect_table()
{
  return MEMD(432)();
}

