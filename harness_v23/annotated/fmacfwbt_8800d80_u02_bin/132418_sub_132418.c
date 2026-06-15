// v23 annotated: sub_132418 @ 0x132418
// Original: 132418_sub_132418.c
// Primary struct: <unclustered>
//
// sub_132418 @ 0x132418, size 66 bytes
char *__fastcall sub_132418(int a1, int a2)
{
  char *result; // r0
  char *v3; // r3
  char *v4; // r4
  int v5; // r2

  if ( a1 )
  {
    result = (char *)*((unsigned __int8 *)off_13245C + 371);
    v3 = (char *)off_13245C + 202;
  }
  else
  {
    result = (char *)*((unsigned __int8 *)off_13245C + 370);
    v3 = (char *)off_13245C + 118;
  }
  if ( result )
  {
    v4 = &v3[6 * (_DWORD)result];
    while ( 1 )
    {
      v5 = *(unsigned __int16 *)v3;
      result = v3;
      v3 += 6;
      if ( v5 == a2 )
        break;
      if ( v3 == v4 )
        return nullptr;
    }
  }
  return result;
}

