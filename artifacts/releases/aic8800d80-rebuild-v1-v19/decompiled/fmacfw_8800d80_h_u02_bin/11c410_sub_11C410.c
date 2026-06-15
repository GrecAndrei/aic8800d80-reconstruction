// sub_11C410 @ 0x11c410, size 46 bytes
unsigned int *__fastcall sub_11C410(unsigned int *result)
{
  int v1; // r2

  v1 = *(unsigned __int16 *)(dword_11C440 + 1320 * *((unsigned __int8 *)result + 28) + 1222);
  if ( v1 != 1023 && *((_BYTE *)off_11C444 + 361) != 2 )
    return sub_11AF90((unsigned int *)(result[17] + 4), *(_DWORD *)(result[17] + 40), v1);
  return result;
}

