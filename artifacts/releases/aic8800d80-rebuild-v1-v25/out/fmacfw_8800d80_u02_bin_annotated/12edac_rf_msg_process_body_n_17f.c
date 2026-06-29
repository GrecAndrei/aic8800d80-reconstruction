// fwstruct annotate: 12edac_rf_msg_process_body_n_17f.c
// rf_msg_process_body_n_17f @ 0x12edac, size 30 bytes
// Doc: rf_msg_process_body_n_17f [rf]: Initializes RF message header/body pointers in shared struct
// rf_msg_process_body_n_17f [rf]: Initializes RF message header/body pointers in shared struct
int __fastcall rf_msg_process_body_n_17f(int a1, int a2, __int16 a3, __int16 a4)
{
  _DWORD *v4; // r0

  v4 = (_DWORD *)sub_12C92C(1034, a4, a3, 0xCu);
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  sdio_buffer_prepare_n_4e8((int)v4);
  return 0;
}

