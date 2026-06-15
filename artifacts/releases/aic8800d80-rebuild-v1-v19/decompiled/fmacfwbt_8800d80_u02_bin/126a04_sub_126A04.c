// sub_126A04 @ 0x126a04, size 56 bytes
int sub_126A04()
{
  int result; // r0
  _DWORD *v1; // r4
  char *v2; // r5
  char *v3; // r4

  result = sub_12D4F8(dword_126A3C);
  if ( result )
  {
    v1 = off_126A40;
    sub_125058(dword_126A44);
    v1[18] = 0;
    v2 = (char *)(v1 + 6);
    v3 = (char *)(v1 + 8);
    do
    {
      sub_12D470(v2);
      result = sub_12D4F8(v3);
    }
    while ( result );
  }
  return result;
}

