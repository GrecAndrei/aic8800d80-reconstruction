// v23 annotated: log_tick @ 0x10eff0
// Original: 10eff0_log_tick.c
// Primary struct: <unclustered>
//
// log_tick @ 0x10eff0, size 90 bytes
// Doc: log_tick [util]: Periodic log/tick handler updating counters and status
// log_tick [util]: Periodic log/tick handler updating counters and status
int log_tick()
{
  _BYTE *v0; // r6
  int v1; // r5
  int v2; // r4
  int v3; // r0
  int result; // r0

  v0 = off_10F050;
  v1 = (char)(*((_BYTE *)off_10F050 + 5) + (*(_BYTE *)off_10F04C & 3));
  v2 = *((char *)off_10F050 + 7) - v1;
  if ( v2 < -62 )
    LOBYTE(v2) = -62;
  rf_power_set(v2);
  v3 = dword_10F054;
  v0[7] = v2;
  result = sub_12ECB0(v3, (char)v2, v1);
  if ( (char)v2 >= -61 )
    return timestamp_update_4f60(v0 + 12, *((_DWORD *)off_10F058 + 4) + 30000 * *((unsigned __int16 *)v0 + 4));
  v0[11] = 0;
  return result;
}

