// sub_125B98 @ 0x125b98, size 22 bytes
char * sub_125B98(int a1, char a2)
{
  char *result; // r0

  if ( !*((uint32_t *)off_125BB0 + 1) )
    return (char *)sub_124EFC(a1, a2);
  result = (char *)off_125BB0 + a1;
  result[20] = a2;
  return result;
}

