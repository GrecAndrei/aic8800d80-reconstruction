// sub_114904 @ 0x114904, size 142 bytes
int  sub_114904(int a1, int a2, unsigned int a3)
{
  uint32_t *v6; // r4
  int v7; // r8
  int v9; // r1
  int v10; // [sp+0h] [bp-50h] BYREF
  int v11; // [sp+4h] [bp-4Ch]
  uint8_t v12[64]; // [sp+10h] [bp-40h] BYREF

  if ( !*(uint32_t *)off_114994 )
    lmac_state_get_n_e0();
  v6 = off_114998;
  v7 = dword_1149A0;
  MEMORY[0x1D8](*(uint32_t *)off_114998, 80, &v10);
  if ( v10 == v7 )
  {
    v11 |= a1;
    if ( (a1 & 1) == 0 )
      goto LABEL_5;
  }
  else
  {
    sub_100200(&v10, 0xFFu, 0x50u);
    v11 = a1;
    v10 = v7;
    if ( (a1 & 1) == 0 )
      goto LABEL_5;
  }
  sub_1282E8(v12, a2, 64);
  if ( a3 <= 0x3F )
    msg_parse(dword_11499C, v9);
LABEL_5:
  rf_event_handler_n258();
  sub_114298();
  return MEMORY[0x1E0](*v6, 80);
}

