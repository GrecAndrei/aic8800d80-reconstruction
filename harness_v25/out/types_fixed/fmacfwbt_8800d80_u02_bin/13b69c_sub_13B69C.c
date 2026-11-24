// sub_13B69C @ 0x13b69c, size 42 bytes
int __fastcall sub_13B69C(int a1, int a2, unsigned int a3)
{
  int v4; // r0

  if ( msg_get_value(a3) == 1 )
  {
    if ( a3 < 0x1000 )
      v4 = dword_13B6D0;
    else
      v4 = dword_13B6CC;
    list_push_tail(v4, (_DWORD *)(dword_13B6C8 + 32 * (a3 >> 8)));
  }
  return 0;
}

