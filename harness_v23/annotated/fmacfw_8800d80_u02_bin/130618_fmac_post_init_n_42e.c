// v23 annotated: fmac_post_init_n_42e @ 0x130618
// Original: 130618_fmac_post_init_n_42e.c
// Primary struct: <unclustered>
//
// fmac_post_init_n_42e @ 0x130618, size 36 bytes
// Doc: fmac_post_init_n_42e [util]: FMAC post-init/config write to MMIO 0x42e
// fmac_post_init_n_42e [util]: FMAC post-init/config write to MMIO 0x42e
int fmac_post_init_n_42e()
{
  int result; // r0

  *((_BYTE *)off_13063C + 1) = 0;
  result = message_dispatch_c8b4(1070, 1);
  if ( result )
    return event_queue_push(1070, 1);
  return result;
}

