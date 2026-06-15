// msg_parse_top_nibble @ 0x141ed4, size 68 bytes
// Doc: sub_1241ED8 [util]: Generic helper; saves arg and tail-calls a function
// sub_1241ED8 [util]: Generic helper; saves arg and tail-calls a function
int __fastcall msg_parse_top_nibble(int a1)
{
  __int16 v1; // r3
  _BYTE *v3; // r1
  int result; // r0

  v1 = *(_WORD *)a1;
  if ( (*(_WORD *)a1 & 8) != 0 )
  {
    v3 = off_141F18;
    *(_WORD *)a1 = v1 | 0x40;
    if ( v3[1] )
    {
      if ( (v1 & 9) == 9 )
        fmac_init_handler_1e48(a1);
    }
  }
  result = timestamp_remove(a1 + 52);
  if ( !*(_BYTE *)(a1 + 4) )
  {
    result = *(unsigned __int8 *)(a1 + 47);
    *((_BYTE *)off_141F18 + 2) &= ~(1 << result);
  }
  return result;
}

