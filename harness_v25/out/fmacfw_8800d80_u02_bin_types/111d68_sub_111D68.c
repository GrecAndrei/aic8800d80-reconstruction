// sub_111D68 @ 0x111d68, size 36 bytes
// Doc: rf_bus_write2_n162 [rf]: Trivial RF bus write2 stub (return only)
// rf_bus_write2_n162 [rf]: Trivial RF bus write2 stub (return only)
int * sub_111D68(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rf_bus_write2_1c1c(a2, 0x200000, 0);
  }
  else if ( a2 <= 5 )
  {
    return rf_bus_write_1b64(a2, 0x200000, 0);
  }
  return result;
}

