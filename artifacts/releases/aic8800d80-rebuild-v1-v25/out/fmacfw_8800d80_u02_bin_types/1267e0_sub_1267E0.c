// sub_1267E0 @ 0x1267e0, size 56 bytes
int sub_1267E0()
{
  int result; // r0
  uint32_t *v1; // r4
  char *v2; // r5
  char *v3; // r4

  result = sub_12D2D0(dword_126818);
  if ( result )
  {
    v1 = off_12681C;
    sub_124E34(dword_126820);
    v1[18] = 0;
    v2 = (char *)(v1 + 6);
    v3 = (char *)(v1 + 8);
    do
    {
      sub_12D248(v2);
      result = sub_12D2D0(v3);
    }
    while ( result );
  }
  return result;
}

