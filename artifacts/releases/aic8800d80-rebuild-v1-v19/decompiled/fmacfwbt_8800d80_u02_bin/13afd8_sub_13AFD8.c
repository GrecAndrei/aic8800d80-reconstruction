// sub_13AFD8 @ 0x13afd8, size 64 bytes
int *__fastcall sub_13AFD8(int *result)
{
  int v1; // r5

  v1 = **(_DWORD **)(dword_13B018 + 696 * *((unsigned __int8 *)result + 29) + 188);
  if ( v1 )
  {
    if ( *(_BYTE *)(v1 + 96) == 1 )
      return bt_flag_check_init(
               (int)result,
               v1 + 80,
               result[18] - *((unsigned __int8 *)result + 52) + 172,
               *((unsigned __int8 *)result + 52) + *((unsigned __int16 *)result + 24));
  }
  return result;
}

