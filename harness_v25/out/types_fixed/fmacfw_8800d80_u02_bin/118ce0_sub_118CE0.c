// sub_118CE0 @ 0x118ce0, size 22 bytes
int sub_118CE0()
{
  list_push_tail(dword_118CF8);
  return irq_nesting_or_d104(0x20000);
}

