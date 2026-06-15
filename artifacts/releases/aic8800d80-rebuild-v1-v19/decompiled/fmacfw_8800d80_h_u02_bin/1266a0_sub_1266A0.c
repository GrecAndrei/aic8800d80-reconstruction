// sub_1266A0 @ 0x1266a0, size 56 bytes
int sub_1266A0()
{
  int result; // r0
  _DWORD *v1; // r4
  char *v2; // r5
  char *v3; // r4

  result = sub_12D190(dword_1266D8);
  if ( result )
  {
    v1 = off_1266DC;
    sub_124CF4(dword_1266E0);
    v1[18] = 0;
    v2 = (char *)(v1 + 6);
    v3 = (char *)(v1 + 8);
    do
    {
      sub_12D108(v2);
      result = sub_12D190(v3);
    }
    while ( result );
  }
  return result;
}

