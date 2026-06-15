// sub_129E84 @ 0x129e84, size 56 bytes
unsigned __int8 *__fastcall sub_129E84(unsigned __int8 *result)
{
  int v1; // r3
  unsigned __int8 *v2; // r4
  int v3; // r1

  v1 = result[114];
  v2 = result;
  if ( v1 == 1 )
  {
    result[114] = 0;
    return sub_129A28(result);
  }
  else if ( v1 == 2 )
  {
    v3 = *((_DWORD *)result + 29);
    result[114] = 1;
    timestamp_update_4f60((int)(result + 96), v3);
    return sub_129A28(v2);
  }
  return result;
}

