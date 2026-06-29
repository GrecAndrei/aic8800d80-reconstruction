// fwstruct annotate: 11df44_rx_queue_head_init.c
// rx_queue_head_init @ 0x11df44, size 64 bytes
// Doc: rx_queue_head_init [rx]: Initialize RX queue head pointer from descriptor base
// rx_queue_head_init [rx]: Initialize RX queue head pointer from descriptor base
_DWORD *rx_queue_head_init()
{
  _DWORD *result; // r0
  _DWORD *v1; // r2
  int v2; // r1
  int v3; // r4
  unsigned int v4; // r3
  int *v5; // r3
  int v6; // r3

  result = (_DWORD *)(dword_11DF84 & 0xFFFFFFFC);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11DF88 = 1;
  }
  v1 = off_11DF8C;
  v2 = *(_DWORD *)off_11DF8C;
  v3 = *(_DWORD *)off_11DF8C + 1;
  v4 = (dword_11DF90 & 0xFFFFFFFC) - (_DWORD)result;
  *(_DWORD *)off_11DF8C = v3;
  *result = 0;
  result[1] = v4;
  if ( v3 )
  {
    v5 = (int *)off_11DF88;
    *v1 = v2;
    v6 = *v5;
    if ( !v2 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

