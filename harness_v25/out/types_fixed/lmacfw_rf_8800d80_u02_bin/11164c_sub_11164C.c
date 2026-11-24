// sub_11164C @ 0x11164c, size 36 bytes
// Doc: rf_bus_mark_n4c8 [rf]: Marks RF bus state for n4c8 access pattern
// rf_bus_mark_n4c8 [rf]: Marks RF bus state for n4c8 access pattern
int *__fastcall sub_11164C(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)sub_111524(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return rf_bus_write_1(a2, 0x8000000, 0);
  }
  return result;
}

