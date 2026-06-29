// fwstruct annotate: 13bc28_tx_msg_submit_n_bc28.c
// tx_msg_submit_n_bc28 @ 0x13bc28, size 168 bytes
// Doc: tx_msg_submit_n_bc28 [tx]: Build and submit TX message to LMAC queue
// tx_msg_submit_n_bc28 [tx]: Build and submit TX message to LMAC queue
_DWORD *__fastcall tx_msg_submit_n_bc28(unsigned int a1)
{
  int v1; // r5
  int v3; // r1
  unsigned __int8 *v4; // r3
  int v5; // r2
  int v6; // r0
  int v7; // r3
  _DWORD *v8; // r1
  _DWORD *v10; // [sp+4h] [bp-8h]

  v1 = (a1 << 8) | 8;
  event_queue_push(0x2000, v1);
  event_queue_push(8194, v1);
  v3 = dword_13BCD0;
  v4 = (unsigned __int8 *)(dword_13BCD0 + 32 * a1);
  v5 = v4[17];
  v6 = v4[16];
  v7 = v4[22];
  if ( v5 )
  {
    if ( v5 == 1 )
      *(_BYTE *)(696 * v6 + 12 * v7 + dword_13BCD4 + 453) = 33;
    v8 = (_DWORD *)(v3 + 32 * a1);
    v10 = v8;
    if ( a1 <= 0xF )
      goto LABEL_5;
LABEL_7:
    sub_12D2E8(dword_13BCE0, v8);
    list_push_tail(dword_13BCE4, v10);
    return sub_12CD34(v1, 0);
  }
  v8 = (_DWORD *)(dword_13BCD0 + 32 * a1);
  *(_BYTE *)(696 * v6 + 12 * v7 + dword_13BCD4 + 452) = 33;
  v10 = v8;
  if ( a1 > 0xF )
    goto LABEL_7;
LABEL_5:
  sub_12D2E8(dword_13BCD8, v8);
  list_push_tail(dword_13BCDC, v10);
  return sub_12CD34(v1, 0);
}

