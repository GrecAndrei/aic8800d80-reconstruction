// fwstruct annotate: 13b638_sub_13B638.c
// sub_13B638 @ 0x13b638, size 50 bytes
// Doc: sub_123B638 [unknown]: Unknown utility/helper function at 0x13b638
// sub_123B638 [unknown]: Unknown utility/helper function at 0x13b638
int __fastcall sub_13B638(int a1, int a2, unsigned int a3)
{
  if ( msg_get_value(a3) == 2 )
  {
    sub_13BA24(a3 >> 8);
    list_push_tail(dword_13B670, (_DWORD *)(dword_13B66C + 32 * (a3 >> 8)));
    sub_12CD34(a3, 0);
  }
  return 0;
}

