// ipc_doorbell_handler_n_43a @ 0x12b080, size 124 bytes
// Doc: ipc_doorbell_handler_n_43a [ipc]: Handles doorbell interrupt from host/AP
// ipc_doorbell_handler_n_43a [ipc]: Handles doorbell interrupt from host/AP
int  ipc_doorbell_handler_n_43a(int a1, int a2, int a3, int a4)
{
  __int16 v4; // r6
  uint8_t *v6; // r4
  uint8_t *v7; // r2

  v4 = a4;
  v6 = (uint8_t *)sub_12C92C(2049, a4, a3, 1);
  msg_get_value(2);
  feature_guard_check(4, dword_12B100);
  if ( msg_get_value(2) )
  {
    *v6 = 8;
    sdio_buffer_prepare_n_4e8(v6);
    return 0;
  }
  else
  {
    if ( **(__int16 **)off_12B104 < 0 && !*(uint8_t *)(a2 + 367) )
      sub_12F46C(dword_12B110, dword_12B10C, 73);
    v7 = off_12B108;
    *v6 = 0;
    *(uint32_t *)v7 = a2;
    v7[10] = 0;
    *((uint16_t *)v7 + 4) = v4;
    sub_12B278(a2);
    sdio_buffer_prepare_n_4e8(v6);
    return 1;
  }
}

