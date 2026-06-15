// v23 annotated: sub_11B044 @ 0x11b044
// Original: 11b044_sub_11B044.c
// Primary struct: <unclustered>
//
// sub_11B044 @ 0x11b044, size 56 bytes
int sub_11B044()
{
  int result; // r0
  _DWORD *v1; // r4
  char *v2; // r5
  char *v3; // r4

  result = sub_11E7AC(dword_11B07C);
  if ( result )
  {
    v1 = off_11B080;
    sub_11AC10(dword_11B084);
    v1[18] = 0;
    v2 = (char *)(v1 + 6);
    v3 = (char *)(v1 + 8);
    do
    {
      sub_11E724(v2);
      result = sub_11E7AC(v3);
    }
    while ( result );
  }
  return result;
}

