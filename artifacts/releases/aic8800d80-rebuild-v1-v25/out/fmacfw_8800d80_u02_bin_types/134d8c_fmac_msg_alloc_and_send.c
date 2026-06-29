// fmac_msg_alloc_and_send @ 0x134d8c, size 86 bytes
// Doc: fmac_msg_alloc_and_send [ipc]: Allocate FMAC message and dispatch to handler
// fmac_msg_alloc_and_send [ipc]: Allocate FMAC message and dispatch to handler
int  fmac_msg_alloc_and_send(int a1, int a2, int a3)
{
  uint32_t *v3; // r5

  v3 = off_134DE4;
  *((uint8_t *)off_134DE4 + 4) = a3;
  v3[2] = a1;
  *((uint16_t *)v3 + 6) = a2;
  sub_12CD34(6u, 10);
  feature_guard_check(
    256,
    dword_134DEC,
    *(unsigned __int8 *)(a1 + 107),
    a2,
    *(unsigned __int16 *)(dword_134DE8 + 696 * *(unsigned __int8 *)(a1 + 116) + 50),
    a3);
  if ( *((uint8_t *)v3 + 4) )
    return sub_134A90();
  else
    return sub_134914();
}

