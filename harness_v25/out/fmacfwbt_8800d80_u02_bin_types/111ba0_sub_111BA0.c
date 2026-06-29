// sub_111BA0 @ 0x111ba0, size 36 bytes
// Doc: rf_bus_write2_n12e [rf]: RF bus write variant dispatch on parameter
// rf_bus_write2_n12e [rf]: RF bus write variant dispatch on parameter
int * sub_111BA0(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rf_bus_write2_1a78(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return sub_1119C0(a2, 0x8000000, 0);
  }
  return result;
}

