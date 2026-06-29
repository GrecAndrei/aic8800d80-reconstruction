// sub_111C4C @ 0x111c4c, size 40 bytes
int * sub_111C4C(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)sub_111ADC(a2, 0x8000000, 0x200000);
  }
  else if ( a2 <= 5 )
  {
    return sub_111A24(a2, 0x8000000, 0x200000);
  }
  return result;
}

