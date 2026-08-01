// call_ptr_1b0 @ 0x10ed6c, size 8 bytes
// Doc: call_ptr_1b0 [rf]: Indirect call dispatcher jumping via function pointers at 0x1b0/0x1b4/0x1b8
// call_ptr_1b0 [rf]: Indirect call dispatcher jumping via function pointers at 0x1b0/0x1b4/0x1b8
int call_ptr_1b0()
{
  return MEMD(432)();
}

