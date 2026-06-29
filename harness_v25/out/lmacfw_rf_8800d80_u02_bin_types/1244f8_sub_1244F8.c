// sub_1244F8 @ 0x1244f8, size 36 bytes
int sub_1244F8()
{
  int result; // r0
  int v1; // r3

  result = sub_1242F0(2u);
  v1 = (unsigned __int16)(*(uint16_t *)off_12451C + 1);
  if ( v1 == 10 )
  {
    *(uint16_t *)off_12451C = 0;
    return sub_12632C(result);
  }
  else
  {
    *(uint16_t *)off_12451C = v1;
  }
  return result;
}

