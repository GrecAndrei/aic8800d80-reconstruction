// sub_11E34C @ 0x11e34c, size 142 bytes
int  sub_11E34C(unsigned int a1)
{
  __int16 **v1; // r6
  unsigned int v2; // r7
  unsigned int v3; // r5
  int v4; // r4
  int v5; // r5
  char v7; // r4
  int v8; // r3

  v1 = (__int16 **)off_11E3DC;
  v2 = a1 >> 8;
  v3 = (unsigned __int8)a1;
  if ( **(__int16 **)off_11E3DC >= 0 )
    goto LABEL_2;
  v7 = a1;
  if ( (unsigned __int8)a1 <= 4u )
    goto LABEL_5;
  rf_cmd_send_n264(dword_11E3EC, dword_11E3E4, 210);
  if ( **v1 >= 0 )
  {
LABEL_2:
    v4 = dword_11E3E0;
    v5 = 16 * v3;
    return *(unsigned __int16 *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
  }
  if ( v3 <= 5 )
  {
LABEL_5:
    if ( (v7 & 0xFC) == 0 )
      goto LABEL_6;
  }
  else
  {
    rf_cmd_send_n264(dword_11E3F4, dword_11E3F0, 183);
    if ( (v7 & 0xFC) == 0 )
      goto LABEL_12;
  }
  rf_cmd_send_n264(dword_11E3F8, dword_11E3E4, 211);
LABEL_12:
  if ( **v1 >= 0 )
    goto LABEL_2;
LABEL_6:
  v4 = dword_11E3E0;
  v8 = dword_11E3E0 + 16 * v3;
  v5 = 16 * v3;
  if ( *(unsigned __int16 *)(v8 + 14) > v2 )
    return *(unsigned __int16 *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
  rf_cmd_send_n264(dword_11E3E8, dword_11E3E4, 212);
  return *(unsigned __int16 *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
}

