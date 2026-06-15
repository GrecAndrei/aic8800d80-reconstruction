// sub_11601C @ 0x11601c, size 186 bytes
int __fastcall sub_11601C(int a1)
{
  int v1; // r5
  int v2; // r6
  int v4; // r7
  int result; // r0
  int v6; // r10
  _BYTE *v7; // r6
  int *v8; // r11
  int *v9; // r9
  int v10; // r2
  int v11; // r3

  v1 = dword_1160E0;
  v2 = *(_DWORD *)(dword_1160DC + 4 * a1);
  v4 = dword_1160E0 + 8 * a1;
  if ( **(__int16 **)off_1160D8 < 0 && (v2 & *(_DWORD *)off_1160E8) == 0 )
    rf_cmd_send_n264(dword_1160F0, dword_1160EC, 612);
  result = sub_11E628(v2);
  v6 = *(_DWORD *)(v1 + 8 * a1);
  if ( v6 )
  {
    v7 = off_1160E4;
    v8 = (int *)off_1160F4;
    v9 = (int *)off_1160F8;
    do
    {
      if ( v7[144] == 1 )
      {
        v7[144] = 0;
        irq_nesting_or(4096);
      }
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v9 = 1;
      }
      ++*v8;
      sub_11E7AC(v4);
      v10 = *v8 - 1;
      if ( *v8 )
      {
        v11 = *v9;
        *v8 = v10;
        if ( !v10 )
        {
          if ( v11 )
            __enable_irq();
        }
      }
      result = rf_cmd_dispatch_n_454((unsigned __int8)a1, v6, v10);
      v6 = *(_DWORD *)(v1 + 8 * a1);
    }
    while ( v6 );
  }
  return result;
}

