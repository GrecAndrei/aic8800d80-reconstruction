// sub_131170 @ 0x131170, size 38 bytes
unsigned __int8 *__fastcall sub_131170(unsigned __int8 *a1, int a2, _BYTE *a3)
{
  unsigned __int8 *result; // r0
  unsigned int v5; // r3

  result = sub_12DE40(a1, a2);
  if ( result )
  {
    v5 = result[3];
    *a3 = v5 & 7;
    a3[1] = (v5 >> 3) & 7;
    return (unsigned __int8 *)1;
  }
  else
  {
    *a3 = 3;
    a3[1] = 5;
  }
  return result;
}

