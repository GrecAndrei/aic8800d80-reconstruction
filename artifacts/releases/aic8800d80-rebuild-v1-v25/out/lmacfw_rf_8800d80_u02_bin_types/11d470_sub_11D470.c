// sub_11D470 @ 0x11d470, size 298 bytes
// Doc: sub_121D470 [mmio]: Copies MMIO register value 0x40328084 to 0x40328088
// sub_121D470 [mmio]: Copies MMIO register value 0x40328084 to 0x40328088
int sub_11D470()
{
  int v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r1
  int v4; // r0
  int v5; // r2
  char *v6; // r4
  int v7; // r1

  v0 = *(uint32_t *)off_11D59C;
  *(uint32_t *)off_11D5A0 = *(uint32_t *)off_11D59C;
  if ( (v0 & 0x400) != 0 )
    sub_126588();
  result = v0 << 23;
  if ( (v0 & 0x100) != 0 )
    result = sub_116C6C();
  if ( (v0 & 0x200) != 0 )
  {
    msg_parse(dword_11D5BC, v0 << 22);
    while ( 1 )
      ;
  }
  if ( (v0 & 0x800) == 0 )
  {
    if ( (v0 & 0x10) == 0 )
      goto LABEL_8;
LABEL_24:
    rf_event_handler_8a4(4);
    result = rf_chan_table_lookup(4);
    if ( (v0 & 0x2F) == 0 )
      goto LABEL_13;
    goto LABEL_9;
  }
  result = irq_nesting_or(0x2000);
  if ( (v0 & 0x10) != 0 )
    goto LABEL_24;
LABEL_8:
  if ( (v0 & 0x2F) == 0 )
    goto LABEL_13;
LABEL_9:
  if ( *(uint8_t *)off_11D5A4 )
  {
    v6 = (char *)off_11D5C0;
    sub_1029DC(*((uint8_t *)off_11D5C0 + 411));
    v7 = v6[411];
    *((uint8_t *)off_11D5C4 + 9) = v7;
    return msg_parse(dword_11D5C8, v7);
  }
  if ( *(uint8_t *)off_11D5A8 )
  {
    result = *(uint32_t *)off_11D5AC << 28;
    if ( result )
      *((uint8_t *)off_11D5A8 + 6) = 1;
  }
LABEL_13:
  v2 = **(__int16 **)off_11D5B0;
  if ( v2 >= 0 )
    return result;
  if ( (v0 & 1) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5D0;
    v5 = 760;
    return sub_121960(v4, v3, v5, v2);
  }
  if ( (v0 & 2) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5D4;
    v5 = 761;
    return sub_121960(v4, v3, v5, v2);
  }
  v2 = v0 << 29;
  if ( (v0 & 4) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5D8;
    v5 = 762;
    return sub_121960(v4, v3, v5, v2);
  }
  result = v0 << 28;
  if ( (v0 & 8) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5CC;
    v5 = 763;
    return sub_121960(v4, v3, v5, v2);
  }
  if ( (v0 & 0x80) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5E0;
    v5 = 765;
    return sub_121960(v4, v3, v5, v2);
  }
  if ( (v0 & 0x40) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5DC;
    v5 = 767;
    return sub_121960(v4, v3, v5, v2);
  }
  v2 = v0 << 26;
  if ( (v0 & 0x20) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5B8;
    v5 = 769;
    return sub_121960(v4, v3, v5, v2);
  }
  return result;
}

