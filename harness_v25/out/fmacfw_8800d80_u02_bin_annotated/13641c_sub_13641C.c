// fwstruct annotate: 13641c_sub_13641C.c
// sub_13641C @ 0x13641c, size 84 bytes
int __fastcall sub_13641C(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v7; // r4

  feature_guard_check(256, dword_136470);
  v7 = dword_136474 + 1320 * *a2;
  if ( *(_BYTE *)(v7 + 106) == 2 && *(_BYTE *)(v7 + 108) )
  {
    if ( msg_get_value(7u) )
    {
      return 2;
    }
    else
    {
      sub_1369CC(v7);
      return 0;
    }
  }
  else
  {
    sub_12CA10(7171, a4, a3);
    return 0;
  }
}

