// rf_setup_dispatch @ 0x11ddf0, size 82 bytes
// Doc: rf_setup_dispatch [rf]: RF init/dispatch calling helper and reading config ptr
// rf_setup_dispatch [rf]: RF init/dispatch calling helper and reading config ptr
int  rf_setup_dispatch(__int16 a1, __int16 a2, __int16 a3, unsigned int a4)
{
  int v8; // r0
  int v9; // r4

  v8 = sub_11DF94(a4 + 12);
  v9 = v8;
  if ( **(__int16 **)off_11DE44 < 0 && !v8 )
    rf_cmd_send_n264(dword_11DE4C, dword_11DE48, 145);
  *(uint16_t *)(v9 + 4) = a1;
  *(uint16_t *)(v9 + 6) = a2;
  *(uint16_t *)(v9 + 8) = a3;
  *(uint16_t *)(v9 + 10) = a4;
  *(uint32_t *)v9 = 0;
  sub_100200((int *)(v9 + 12), 0, a4);
  return v9 + 12;
}

