// bt_rx_handler @ 0x12a540, size 34 bytes
// Doc: bt_rx_handler [bt]: Bluetooth RX path handler
// bt_rx_handler [bt]: Bluetooth RX path handler
unsigned __int8 *__fastcall bt_rx_handler(int a1)
{
  unsigned __int8 *v1; // r0

  v1 = (unsigned __int8 *)(dword_12A564 + 140 * *(unsigned __int8 *)(a1 + 1225));
  *(_DWORD *)(v1 + 0x218) = 0;
  return sub_129A28(v1);
}

