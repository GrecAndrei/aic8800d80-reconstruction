// sub_111BC4 @ 0x111bc4, size 36 bytes
// Doc: rf_state_check_n_44c [rf]: Check RF state, conditional return based on flags
// rf_state_check_n_44c [rf]: Check RF state, conditional return based on flags
int *__fastcall sub_111BC4(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rf_bus_write2_1a78(a2, 0x200000, 0);
  }
  else if ( a2 <= 5 )
  {
    return sub_1119C0(a2, 0x200000, 0);
  }
  return result;
}

