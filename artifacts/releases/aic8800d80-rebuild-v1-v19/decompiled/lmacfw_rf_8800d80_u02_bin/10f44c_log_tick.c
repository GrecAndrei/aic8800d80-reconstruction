// log_tick @ 0x10f44c, size 90 bytes
// Doc: log_tick [util]: Periodic logging tick handler
// log_tick [util]: Periodic logging tick handler
int log_tick()
{
  _BYTE *v0; // r6
  int v1; // r4
  int v2; // r0
  int result; // r0

  v0 = off_10F4AC;
  v1 = *((char *)off_10F4AC + 7) - (char)(*((_BYTE *)off_10F4AC + 5) + (*(_BYTE *)off_10F4A8 & 3));
  if ( v1 < -62 )
    LOBYTE(v1) = -62;
  sub_1029DC(v1);
  v2 = dword_10F4B0;
  v0[7] = v1;
  result = msg_parse(v2, (char)v1);
  if ( (char)v1 >= -61 )
    return sub_11AB18(v0 + 12, *((_DWORD *)off_10F4B4 + 4) + 30000 * *((unsigned __int16 *)v0 + 4));
  v0[11] = 0;
  return result;
}

