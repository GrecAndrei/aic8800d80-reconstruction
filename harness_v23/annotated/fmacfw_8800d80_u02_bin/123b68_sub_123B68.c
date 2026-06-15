// v23 annotated: sub_123B68 @ 0x123b68
// Original: 123b68_sub_123B68.c
// Primary struct: <unclustered>
//
// sub_123B68 @ 0x123b68, size 118 bytes
// Doc: sub_1223B68 [util]: Helper: reads flag from 0x182B60, dispatches to handler with r0/r1/r2 args
// sub_1223B68 [util]: Helper: reads flag from 0x182B60, dispatches to handler with r0/r1/r2 args
int __fastcall sub_123B68(int a1, void (__fastcall **a2)(int), int a3)
{
  __int16 **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (__int16 **)off_123BE0;
  if ( **(__int16 **)off_123BE0 < 0 && msg_get_value(a3) == 4 )
    sub_12F46C(dword_123BE8, dword_123BE4, 1587);
  result = msg_get_value(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      sub_12B804(result);
      sub_12CD34(a3);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(_DWORD *)off_123BEC << 28 )
      sub_12F46C(dword_123BF0, dword_123BE4, 1594);
    v7 = sub_12CD34(a3);
    (*a2)(v7);
    return 0;
  }
  return result;
}

