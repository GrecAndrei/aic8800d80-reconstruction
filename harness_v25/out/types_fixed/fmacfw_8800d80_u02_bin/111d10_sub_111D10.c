// sub_111D10 @ 0x111d10, size 42 bytes
// Doc: rf_state_check_1d26 [rf]: Check the current state bit of an RF sub-block by index
// rf_state_check_1d26 [rf]: Check the current state bit of an RF sub-block by index
int __fastcall sub_111D10(int a1, int a2)
{
  _DWORD *v2; // r0
  int v4; // r0

  if ( a2 )
  {
    if ( a1 == 1 )
      v4 = dword_111D3C;
    else
      v4 = rf_bus_mark_n4bc;
    return (*(_DWORD *)(v4 + 32 * a2) >> 21) & 1;
  }
  else
  {
    if ( a1 == 1 )
      v2 = (_DWORD *)dword_111D3C;
    else
      v2 = (_DWORD *)rf_bus_mark_n4bc;
    return (*v2 >> 21) & 1;
  }
}

