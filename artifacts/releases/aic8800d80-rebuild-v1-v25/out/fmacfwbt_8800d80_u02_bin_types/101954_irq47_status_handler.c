// irq47_status_handler @ 0x101954, size 14 bytes
int irq47_status_handler()
{
  return (unsigned __int8)(((unsigned __int8)*(uint32_t *)off_101964 >> 4) - 1);
}

