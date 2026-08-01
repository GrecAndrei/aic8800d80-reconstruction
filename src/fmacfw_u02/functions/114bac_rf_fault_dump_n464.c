// call_hook_27 @ 0x114bac, size 10 bytes
// Doc: call_hook_27 [rf]: Dump RF fault state via vectored call
// call_hook_27 [rf]: Dump RF fault state via vectored call
int call_hook_27()
{
  return MEMD(508)(27);
}

