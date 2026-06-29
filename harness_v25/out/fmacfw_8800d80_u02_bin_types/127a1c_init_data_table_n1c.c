// init_data_table_n1c @ 0x127a1c, size 140 bytes
// Doc: init_data_table_n1c [util]: Initialize internal data table
// init_data_table_n1c [util]: Initialize internal data table
int init_data_table_n1c()
{
  int *v0; // r7
  void *v1; // r6
  unsigned int v2; // r5
  int *i; // r4
  int result; // r0
  uint32_t *v5; // r3
  void *v6; // r1

  v0 = (int *)off_127AAC;
  v1 = off_127AA8;
  memset_thunk((int *)off_127AA8, 0, 0x60u);
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
  sub_12D240(dword_127AB0);
  sub_12D240(dword_127AB4);
  list_push_tail(dword_127AB0);
  list_push_tail(dword_127AB0);
  list_push_tail(dword_127AB0);
  result = list_push_tail(dword_127AB0);
  v5 = off_127AA8;
  v6 = off_127ACC;
  *((uint32_t *)off_127AA8 + 13) = off_127AC8;
  v5[17] = v6;
  v5[18] = 0;
  return result;
}

