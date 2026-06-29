// message_dispatch_n_3dc @ 0x12c5b0, size 18 bytes
// Doc: message_dispatch_n_3da [ipc]: Check message index within dispatch table bound
// message_dispatch_n_3da [ipc]: Check message index within dispatch table bound
BOOL  message_dispatch_n_3dc(int a1, int a2)
{
  return *(uint32_t *)(a1 + 8) - *(uint32_t *)(a2 + 8) > (unsigned int)message_dispatch_n_3c8;
}

