// bt_hci_cmd_dispatch @ 0x1285f8, size 160 bytes
// Doc: bt_hci_cmd_dispatch [bt]: Dispatch HCI command from BT firmware host interface
// bt_hci_cmd_dispatch [bt]: Dispatch HCI command from BT firmware host interface
int  bt_hci_cmd_dispatch(int result)
{
  int v1; // r7
  int v2; // r5
  uint8_t *v3; // r6
  int v4; // r8
  int v5; // r0
  __int16 v6; // r5
  __int16 v7; // r4
  int v8; // r2

  v1 = *(uint32_t *)(result + 72);
  v2 = result;
  if ( **(__int16 **)off_128698 < 0 && !v1 )
    result = sub_12F694(dword_1286AC, dword_1286A8, 3591);
  v3 = off_12869C;
  if ( (*((uint8_t *)off_12869C + 88) & 0x20) == 0 && *((unsigned __int8 *)off_12869C + 90) > 1u )
  {
    v4 = *(unsigned __int8 *)(v2 + 116);
    v5 = rf_bus_setup_n3a8(70, *((uint8_t *)off_12869C + 88) & 0x20, *((uint8_t *)off_12869C + 88) & 0x20, 20);
    *(uint8_t *)v5 = 0;
    *(uint8_t *)(v5 + 1) = *(uint8_t *)(v2 + 107);
    *(uint8_t *)(v5 + 2) = *(uint8_t *)(v1 + 4);
    *(uint8_t *)(v5 + 3) = *(uint8_t *)(v1 + 5);
    v6 = *(uint16_t *)(v1 + 8);
    v7 = *(uint16_t *)(v1 + 10);
    v8 = dword_1286A0;
    *(uint16_t *)(v5 + 4) = *(uint16_t *)(v1 + 6);
    *(uint16_t *)(v5 + 6) = v6;
    *(uint16_t *)(v5 + 8) = v7;
    *(uint8_t *)(v5 + 16) = *(uint8_t *)(v1 + 12);
    *(uint32_t *)(v5 + 12) = (unsigned int)(((unsigned int)dword_1286A4
                                         * (unsigned uint64_t)(unsigned int)(*(uint32_t *)(v8 + 696 * v4 + 8) - 5000)) >> 32) >> 6;
    result = sub_12CBB4(v5);
    v3[88] |= 0x20u;
  }
  return result;
}

