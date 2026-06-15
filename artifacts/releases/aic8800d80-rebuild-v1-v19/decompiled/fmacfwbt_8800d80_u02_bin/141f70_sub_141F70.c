// sub_141F70 @ 0x141f70, size 68 bytes
// Doc: sub_1241F70 [unknown]: Unknown behavioral stub
// sub_1241F70 [unknown]: Unknown behavioral stub
int __fastcall sub_141F70(int a1)
{
  __int16 v1; // r3
  _BYTE *v3; // r1
  int result; // r0

  v1 = *(_WORD *)a1;
  if ( (*(_WORD *)a1 & 8) != 0 )
  {
    v3 = off_141FB4;
    *(_WORD *)a1 = v1 | 0x40;
    if ( v3[1] )
    {
      if ( (v1 & 9) == 9 )
        sub_141EE4(a1);
    }
  }
  result = timestamp_remove_058(a1 + 52);
  if ( !*(_BYTE *)(a1 + 4) )
  {
    result = *(unsigned __int8 *)(a1 + 47);
    *((_BYTE *)off_141FB4 + 2) &= ~(1 << result);
  }
  return result;
}

