// rf_bus_setup_n294 @ 0x132134, size 144 bytes
// Doc: rf_bus_setup_n294 [rf]: Configure RF bus control register bits for operation
// rf_bus_setup_n294 [rf]: Configure RF bus control register bits for operation
int __fastcall rf_bus_setup_n294(int a1, _BYTE *a2, unsigned int a3, __int16 a4)
{
  _WORD *v7; // r7
  bool *v9; // r0
  char v10; // r1
  int v11; // r3

  if ( msg_get_value(5u) == 1 )
    return 2;
  v7 = off_1321C4;
  if ( *(_DWORD *)off_1321C4 )
  {
    if ( *a2 )
    {
      *(_DWORD *)off_1321C4 |= 1 << a2[1];
      sub_12CA10(5144, a4, a3);
      return 0;
    }
  }
  else if ( !*a2 )
  {
    sub_12CA10(5144, a4, a3);
    return 0;
  }
  v9 = (bool *)sub_12C92C(34, 0, a3, 1u);
  v10 = a2[1];
  if ( *a2 )
    v11 = (1 << v10) | *(_DWORD *)v7;
  else
    v11 = *(_DWORD *)v7 & ~(1 << v10);
  *(_DWORD *)v7 = v11;
  v7[4] = a4;
  *v9 = v11 == 0;
  sdio_buffer_prepare_n_4e8((int)v9);
  sub_12CD34(a3, 1);
  return 0;
}

