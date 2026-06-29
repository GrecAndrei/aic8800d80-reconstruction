// fwstruct annotate: 1320bc_sub_1320BC.c
// sub_1320BC @ 0x1320bc, size 66 bytes
char *__fastcall sub_1320BC(int a1, int a2)
{
  char *result; // r0
  char *v3; // r3
  char *v4; // r4
  int v5; // r2

  if ( a1 )
  {
    result = (char *)*((unsigned __int8 *)off_132100 + 371);
    v3 = (char *)off_132100 + 202;
  }
  else
  {
    result = (char *)*((unsigned __int8 *)off_132100 + 370);
    v3 = (char *)off_132100 + 118;
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

