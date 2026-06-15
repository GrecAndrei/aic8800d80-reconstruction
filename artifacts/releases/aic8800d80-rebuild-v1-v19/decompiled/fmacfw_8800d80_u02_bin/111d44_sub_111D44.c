// sub_111D44 @ 0x111d44, size 36 bytes
// Doc: rf_bus_reset2_n35f [rf]: Stub returning immediately (bx lr) for RF bus reset variant
// rf_bus_reset2_n35f [rf]: Stub returning immediately (bx lr) for RF bus reset variant
int *__fastcall sub_111D44(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rf_bus_write2_1c1c(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return rf_bus_write_1b64(a2, 0x8000000, 0);
  }
  return result;
}

