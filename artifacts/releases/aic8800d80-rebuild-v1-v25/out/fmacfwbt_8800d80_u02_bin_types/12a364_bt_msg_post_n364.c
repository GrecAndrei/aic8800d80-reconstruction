// bt_msg_post_n364 @ 0x12a364, size 72 bytes
// Doc: bt_msg_post_n364 [bt]: Posts a message; loads shared flag, branches on it then dispatches.
// bt_msg_post_n364 [bt]: Posts a message; loads shared flag, branches on it then dispatches.
unsigned int  bt_msg_post_n364(int a1, uint32_t *a2, uint32_t *a3)
{
  int v6; // r3
  int v7; // r0

  if ( **(__int16 **)off_12A3AC < 0 && !*(uint8_t *)(a1 + 1224) )
    sub_12F694(dword_12A3B8, dword_12A3B4, 1311);
  v6 = dword_12A3B0 + 140 * *(unsigned __int8 *)(a1 + 1225);
  *a2 = *(uint32_t *)(v6 + 128);
  v7 = *(uint32_t *)(v6 + 124);
  *a3 = v7;
  return (unsigned int)(v7 - *a2) >> 31;
}

