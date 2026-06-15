// rx_queue_head_init @ 0x12c954, size 64 bytes
// Doc: rx_queue_head_init [rx]: Initialize RX queue head pointer from 0x1906a7 (word-aligned)
// rx_queue_head_init [rx]: Initialize RX queue head pointer from 0x1906a7 (word-aligned)
_DWORD *rx_queue_head_init()
{
  _DWORD *result; // r0
  _DWORD *v1; // r2
  int v2; // r1
  int v3; // r4
  unsigned int v4; // r3
  int *v5; // r3
  int v6; // r3

  result = (_DWORD *)(dword_12C994 & 0xFFFFFFFC);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12C998 = 1;
  }
  v1 = off_12C99C;
  v2 = *(_DWORD *)off_12C99C;
  v3 = *(_DWORD *)off_12C99C + 1;
  v4 = (*(_DWORD *)sub_12C9A0 & 0xFFFFFFFC) - (_DWORD)result;
  *(_DWORD *)off_12C99C = v3;
  *result = 0;
  result[1] = v4;
  if ( v3 )
  {
    v5 = (int *)off_12C998;
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

