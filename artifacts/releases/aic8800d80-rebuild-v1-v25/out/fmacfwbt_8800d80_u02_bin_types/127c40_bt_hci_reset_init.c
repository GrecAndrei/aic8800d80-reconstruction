// bt_hci_reset_init @ 0x127c40, size 140 bytes
// Doc: bt_hci_reset_init [bt]: Initializes BT HCI control structures and buffers
// bt_hci_reset_init [bt]: Initializes BT HCI control structures and buffers
int bt_hci_reset_init()
{
  int *v0; // r7
  void *v1; // r6
  unsigned int v2; // r5
  int *i; // r4
  int result; // r0
  uint32_t *v5; // r3
  void *v6; // r1

  v0 = (int *)off_127CD0;
  v1 = off_127CCC;
  memset_thunk((int *)off_127CCC, 0, 0x60u);
  v2 = 0;
  for ( i = v0; ; i += 7 )
  {
    memset_thunk(i, 0, 0x1Cu);
    *((uint16_t *)i + 7) = 255;
    *((uint8_t *)i + 24) = -1;
    *((uint8_t *)i + 27) = -1;
    if ( v2 <= 2 )
    {
      list_push_tail(v1);
      goto LABEL_4;
    }
    if ( v2 != 3 )
      break;
    *((uint16_t *)v0 + 47) = 0;
    *((uint8_t *)v0 + 89) = 0;
LABEL_4:
    ++v2;
  }
  if ( v2 != 4 )
    goto LABEL_4;
  bt_xtal_init_check(dword_127CD4);
  bt_xtal_init_check(dword_127CD8);
  list_push_tail(dword_127CD4);
  list_push_tail(dword_127CD4);
  list_push_tail(dword_127CD4);
  result = list_push_tail(dword_127CD4);
  v5 = off_127CCC;
  v6 = off_127CF0;
  *((uint32_t *)off_127CCC + 13) = dword_127CEC;
  v5[17] = v6;
  v5[18] = 0;
  return result;
}

