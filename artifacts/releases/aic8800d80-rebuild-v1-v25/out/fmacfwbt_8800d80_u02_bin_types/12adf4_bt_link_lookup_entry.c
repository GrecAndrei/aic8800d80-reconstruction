// bt_link_lookup_entry @ 0x12adf4, size 188 bytes
// Doc: bt_link_lookup_entry [bt]: Look up a BT link entry by index from the link table
// bt_link_lookup_entry [bt]: Look up a BT link entry by index from the link table
int  bt_link_lookup_entry(int a1, int a2)
{
  int v2; // r6
  int v3; // r3
  char v4; // r2
  int v5; // r4
  uint32_t *v6; // r9
  uint32_t *v7; // r8
  int v8; // r3
  int v9; // r2
  __int16 v10; // r4
  int result; // r0

  v2 = dword_12AEB0;
  v3 = dword_12AEB0 + 140 * a1;
  v4 = *(uint8_t *)(v3 + 120);
  *(uint8_t *)(a2 + 9) = v4;
  v5 = *(unsigned __int8 *)(v3 + 115);
  *(uint8_t *)(v3 + 120) = v4 + 1;
  if ( v5 )
    *(uint8_t *)(a2 + 10) = v5 | 0x80;
  else
    *(uint8_t *)(a2 + 10) = 0;
  v6 = off_12AEB4;
  v7 = off_12AEB8;
  v8 = v2 + 140 * a1;
  v9 = a2 + 11;
  v10 = 0;
  do
  {
    if ( *(uint8_t *)(v8 + 16) && (!*(uint8_t *)(v2 + 140 * a1 + 135) || !*(uint8_t *)(v8 + 33) || *(uint8_t *)(v8 + 32) != 1) )
    {
      *(uint8_t *)v9 = *(uint8_t *)(v8 + 20);
      *(QWORD *)(v9 + 1) = *(QWORD *)(v8 + 24);
      v10 = (unsigned __int8)(v10 + 1);
      *(uint32_t *)(v9 + 9) = *v6 - v7[4] + *(uint32_t *)(v8 + 36);
    }
    v9 += 13;
    v8 += 48;
  }
  while ( v9 != a2 + 37 );
  result = v2 + 140 * a1;
  *(uint8_t *)(result + 136) = v10;
  *(uint8_t *)(a2 + 1) = 13 * v10 + 9;
  *(uint16_t *)(a2 + 7) = 13 * v10 + 2;
  return result;
}

