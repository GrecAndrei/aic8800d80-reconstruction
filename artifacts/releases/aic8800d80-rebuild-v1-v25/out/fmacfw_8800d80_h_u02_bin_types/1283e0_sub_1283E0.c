// sub_1283E0 @ 0x1283e0, size 34 bytes
BOOL  sub_1283E0(int a1)
{
  BOOL result; // r0

  result = sub_128390(a1);
  if ( result )
    return !*((uint32_t *)off_128404 + 11) || *(unsigned __int8 *)(*((uint32_t *)off_128404 + 10) + 16) == 6;
  return result;
}

