// fwstruct annotate: 11af78_rf_xosc_setup.c
// rf_xosc_setup @ 0x11af78, size 166 bytes
// Doc: rf_xosc_setup [rf]: Configure RF crystal oscillator parameters
// rf_xosc_setup [rf]: Configure RF crystal oscillator parameters
int __fastcall rf_xosc_setup(int a1, int a2, int a3)
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

  v6 = sub_11E7AC(dword_11B020);
  v7 = (_DWORD *)v6;
  if ( **(__int16 **)off_11B024 < 0 && !v6 )
    rf_cmd_send_n264(dword_11B030, dword_11B02C, 227);
  v8 = off_11B028;
  v9 = (char *)off_11B028 + 32;
  v10 = *((_DWORD *)off_11B028 + 8);
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
      *(_DWORD *)off_11B034 = 1;
    }
    v12 = (int *)off_11B03C;
    v13 = v7[1];
    v14 = *(_DWORD *)off_11B03C;
    v15 = v13 - *((_DWORD *)off_11B038 + 4);
    v16 = *(_DWORD *)off_11B03C + 1;
    *(_DWORD *)off_11B03C = v16;
    if ( v15 - 64 >= 0 )
    {
      result = sub_11AB18(dword_11B040, v13);
      if ( *v12 )
      {
        v19 = *v12 - 1;
        v20 = *(_DWORD *)off_11B034;
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
        v17 = (int *)off_11B034;
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

