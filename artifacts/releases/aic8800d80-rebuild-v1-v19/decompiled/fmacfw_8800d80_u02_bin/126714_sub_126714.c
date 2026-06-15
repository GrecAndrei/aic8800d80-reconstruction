// sub_126714 @ 0x126714, size 166 bytes
int __fastcall sub_126714(int a1, int a2, int a3)
{
  int v6; // r0
  _DWORD *v7; // r4
  _DWORD *v8; // r5
  char *v9; // r0
  int v10; // r6
  int result; // r0
  int *v12; // r6
  int v13; // r1
  int v14; // r0
  int v15; // r3
  int v16; // r2
  int *v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r2

  v6 = rf_bus_mark_n100_d2d0(dword_1267BC);
  v7 = (_DWORD *)v6;
  if ( **(__int16 **)off_1267C0 < 0 && !v6 )
    sub_12F46C(dword_1267CC, dword_1267C8, 227);
  v8 = off_1267C4;
  v9 = (char *)off_1267C4 + 32;
  v10 = *((_DWORD *)off_1267C4 + 8);
  v7[3] = a3;
  v7[1] = a1;
  v7[2] = a2;
  result = list_push_tail(v9);
  if ( !v10 )
  {
    v8[18] = v7;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_1267D0 = 1;
    }
    v12 = (int *)off_1267D8;
    v13 = v7[1];
    v14 = *(_DWORD *)off_1267D8;
    v15 = v13 - *((_DWORD *)off_1267D4 + 4);
    v16 = *(_DWORD *)off_1267D8 + 1;
    *(_DWORD *)off_1267D8 = v16;
    if ( v15 - 64 >= 0 )
    {
      result = timestamp_update(dword_1267DC, v13);
      if ( *v12 )
      {
        v19 = *v12 - 1;
        v20 = *(_DWORD *)off_1267D0;
        *v12 = v19;
        if ( !v19 )
        {
          if ( v20 )
            __enable_irq();
        }
      }
    }
    else
    {
      if ( v16 )
      {
        v17 = (int *)off_1267D0;
        *v12 = v14;
        v18 = *v17;
        if ( !v14 )
        {
          if ( v18 )
            __enable_irq();
        }
      }
      return ((int (__fastcall *)(_DWORD *))v8[17])(v7);
    }
  }
  return result;
}

