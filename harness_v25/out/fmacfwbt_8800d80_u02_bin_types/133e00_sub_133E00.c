// sub_133E00 @ 0x133e00, size 66 bytes
int  sub_133E00(int a1, unsigned __int8 *a2)
{
  int v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r4

  v2 = *a2;
  feature_guard_sdio(256, dword_133E44);
  result = msg_get_value(6u);
  if ( result )
    return 2;
  v4 = dword_133E48 + 1320 * v2;
  v5 = *(unsigned __int8 *)(v4 + 106);
  if ( !*(uint8_t *)(v4 + 106) )
  {
    result = *(unsigned __int8 *)(v4 + 108);
    if ( *(uint8_t *)(v4 + 108) )
    {
      sub_134FA8(v4, 1, *(unsigned __int8 *)(v4 + 106));
      return v5;
    }
  }
  return result;
}

