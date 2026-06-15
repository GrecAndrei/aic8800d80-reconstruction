// sub_125CD8 @ 0x125cd8, size 22 bytes
char *__fastcall sub_125CD8(int a1, char a2)
{
  char *result; // r0

  if ( !*((_DWORD *)off_125CF0 + 1) )
    return (char *)sub_12503C(a1, a2);
  result = (char *)off_125CF0 + a1;
  result[20] = a2;
  return result;
}

