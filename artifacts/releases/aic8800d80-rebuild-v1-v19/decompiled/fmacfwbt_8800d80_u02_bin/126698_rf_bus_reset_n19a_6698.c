// rf_bus_reset_n19a_6698 @ 0x126698, size 258 bytes
// Doc: rf_bus_reset_n19a_6698 [rf]: Reset RF bus and check controller state
// rf_bus_reset_n19a_6698 [rf]: Reset RF bus and check controller state
BOOL __fastcall rf_bus_reset_n19a_6698(int a1, int a2, int a3)
{
  int v6; // r5
  int v7; // r3
  int v8; // r9
  unsigned int v9; // r8
  int v10; // r6
  int v11; // r6
  int v12; // r0
  int v13; // r3
  int v14; // r0
  int v16; // r3
  int v17; // r5
  int v18; // r3

  if ( a1 )
  {
    v6 = a1;
  }
  else
  {
    v16 = dword_1267A0;
    while ( 1 )
    {
      if ( *(unsigned __int8 *)(v16 + 24) != 255 )
      {
        v17 = *(unsigned __int8 *)(v16 + 27);
        if ( v17 != 255 )
          break;
      }
      v16 += 28;
      if ( dword_1267A0 + 84 == v16 )
        return 0;
    }
    v6 = dword_12679C + 1320 * v17;
  }
  if ( !a3 || *(unsigned __int8 *)(a3 + 10) == 255 )
  {
    v14 = sub_10186C() + 14000;
  }
  else
  {
    v7 = dword_12679C + 1320 * *(unsigned __int8 *)(a3 + 8);
    if ( *(_BYTE *)(v7 + 106) )
    {
      if ( *(_BYTE *)(v7 + 106) == 2 )
      {
        v18 = *(unsigned __int16 *)(v7 + 222);
        v9 = v18 << 10;
        v8 = v18 << 9;
      }
      else
      {
        v8 = 51200;
        v9 = 102400;
      }
    }
    else
    {
      v9 = *(_DWORD *)(dword_1267A4 + 696 * *(unsigned __int8 *)(v7 + 116) + 8);
      v8 = v9 >> 1;
    }
    v10 = *(_DWORD *)(a3 + 4);
    v11 = v10 + 10000 + sub_10186C();
    v12 = sub_12A3BC(a1, *(unsigned __int8 *)(a3 + 11));
    v13 = v12 - a2;
    if ( v12 - a2 + v8 < 0 )
    {
      do
        v12 += v9;
      while ( v8 - a2 + v12 < 0 );
      v13 = v12 - a2;
    }
    if ( v13 < 0 )
      a2 = v12 - 1;
    if ( v11 + 9000 - a2 < 0 )
      v14 = 5000;
    else
      v14 = v11 + 4000 - a2;
  }
  return sub_12A818(v6, 1, 0, 1, 0, v14, a2) != 255;
}

