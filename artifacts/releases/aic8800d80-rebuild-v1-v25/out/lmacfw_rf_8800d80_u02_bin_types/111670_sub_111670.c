// sub_111670 @ 0x111670, size 36 bytes
// Doc: unknown_func_0 [unknown]: firmware function (unlabeled)
// unknown_func_0 [unknown]: firmware function (unlabeled)
int * sub_111670(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)sub_111524(a2, 0x200000, 0);
  }
  else if ( a2 <= 5 )
  {
    return rf_bus_write_1(a2, 0x200000, 0);
  }
  return result;
}

