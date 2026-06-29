// sub_112B7C @ 0x112b7c, size 126 bytes
// Doc: rf_cmd_send_n2c0 [rf]: Send RF command 0xC0 and check status
// rf_cmd_send_n2c0 [rf]: Send RF command 0xC0 and check status
int  sub_112B7C(int a1)
{
  unsigned __int16 *v2; // r4
  int v3; // r1
  uint8_t *v4; // r1
  uint8_t *v5; // r2
  uint32_t *v6; // r7
  int v7; // r6
  int v8; // r1
  int v9; // r4

  if ( (*(uint32_t *)off_112BFC & 0x2000000) != 0 )
  {
    sub_100200((int *)off_112C00, 0xFFu, 4u);
  }
  else
  {
    v2 = (unsigned __int16 *)off_112C00;
    sub_100200((int *)off_112C00, 0xFFu, 4u);
    if ( sub_114850(v2) || v2[1] == 0xFFFF || (v3 = *v2, v3 == 0xFFFF) )
      msg_parse(dword_112C04, v3);
    else
      msg_parse(rf_cmd_dispatch_n459, v3);
  }
  v4 = off_112C0C;
  v5 = off_112C10;
  *(uint32_t *)off_112C08 = *(uint32_t *)a1;
  v6 = (uint32_t *)dword_112C14;
  v7 = dword_112C18;
  *v4 = 0;
  *v5 = 0;
  do
  {
    v8 = *(unsigned __int8 *)(a1 + 8);
    if ( *(uint8_t *)(a1 + 8) )
      v8 = 1;
    v9 = rf_bus_write_n274(v6, v8);
    msg_parse(v7, v9);
  }
  while ( v9 );
  return 0;
}

