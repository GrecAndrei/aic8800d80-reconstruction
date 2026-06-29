// sub_111C28 @ 0x111c28, size 36 bytes
int * sub_111C28(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)sub_111ADC(a2, 0x200000, 0);
  }
  else if ( a2 <= 5 )
  {
    return sub_111A24(a2, 0x200000, 0);
  }
  return result;
}

