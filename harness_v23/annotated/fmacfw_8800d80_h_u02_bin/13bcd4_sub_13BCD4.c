// v23 annotated: sub_13BCD4 @ 0x13bcd4
// Original: 13bcd4_sub_13BCD4.c
// Primary struct: <unclustered>
//
// sub_13BCD4 @ 0x13bcd4, size 120 bytes
int __fastcall sub_13BCD4(int result)
{
  int v1; // r9
  int v2; // r6
  int v3; // r5
  int v4; // r7
  int v5; // r10
  int v6; // r8
  int i; // r4
  int v8; // t1

  v1 = dword_13BD58;
  v2 = dword_13BD4C;
  v3 = dword_13BD50;
  v4 = result;
  v5 = dword_13BD58 - 8;
  v6 = dword_13BD58 + 24;
  for ( i = 0; i != 32; ++i )
  {
    v8 = *(unsigned __int16 *)(v2 + 2);
    v2 += 2;
    if ( v8 && *(unsigned __int8 *)(v3 + 16) == v4 )
    {
      if ( i > 15 )
      {
        sub_12D1A8(v6, (_DWORD *)v3);
        sub_12D108(dword_13BD54, (_DWORD *)v3);
      }
      else
      {
        sub_12D1A8(v1, (_DWORD *)v3);
        sub_12D108(v5, (_DWORD *)v3);
      }
      sub_12CBF4((unsigned __int16)((_WORD)i << 8) | 8, 4);
      result = sub_13BC64(v4, (unsigned __int16)i);
    }
    v3 += 32;
  }
  return result;
}

