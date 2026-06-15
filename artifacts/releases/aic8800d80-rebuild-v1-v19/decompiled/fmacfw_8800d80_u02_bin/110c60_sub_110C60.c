// sub_110C60 @ 0x110c60, size 218 bytes
int sub_110C60()
{
  _DWORD *v0; // r8
  int *v1; // r7
  int *v2; // r10
  char *v3; // r9
  int v4; // r3
  unsigned int v5; // r6
  int v6; // r11
  unsigned __int16 v7; // r4
  int v8; // r5
  int v9; // r2
  int v10; // r0
  int v11; // r2
  int v12; // r2
  int v13; // r3
  int result; // r0
  int v15; // r3
  int v16; // r2
  int v17; // [sp+4h] [bp-8h]

  v0 = off_110D44;
  v1 = (int *)off_110D3C;
  v2 = (int *)off_110D40;
  v3 = (char *)off_110D44 + 3080;
  while ( 1 )
  {
    v4 = v0[770];
    if ( !v4 )
      break;
    while ( 1 )
    {
      v5 = *(unsigned __int16 *)(v4 + 8);
      v6 = *(_DWORD *)(v4 + 4);
      if ( *(_WORD *)(v4 + 8) )
      {
        v7 = 0;
        v8 = 0;
        v9 = 0;
        do
        {
          while ( 1 )
          {
            v10 = v6;
            ++v7;
            v6 = *(_DWORD *)(v6 + 4);
            if ( v9 == v8 )
              break;
            log_free_dispatch_n2f4_0();
            v9 = v7;
            if ( v7 >= v5 )
              goto LABEL_8;
          }
          v17 = v10;
          sub_11D8EC();
          LOWORD(v8) = v8 + (*(_BYTE *)(v17 + 11) & 0x7F);
          log_free_dispatch_n2f4_0();
          v9 = v7;
          v8 = (unsigned __int16)v8;
        }
        while ( v7 < v5 );
      }
LABEL_8:
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v2 = 1;
      }
      ++*v1;
      rf_bus_mark_n100_d2d0(v3);
      v11 = *v1;
      --*((_BYTE *)v0 + 3074);
      if ( !v11 )
        break;
      v12 = v11 - 1;
      v13 = *v2;
      *v1 = v12;
      if ( v12 || !v13 )
        break;
      __enable_irq();
      v4 = v0[770];
      if ( !v4 )
        goto LABEL_14;
    }
  }
LABEL_14:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110D40 = 1;
  }
  ++*v1;
  result = clear_flags(128);
  if ( *v1 )
  {
    v15 = *v1 - 1;
    v16 = *(_DWORD *)off_110D40;
    *v1 = v15;
    if ( !v15 )
    {
      if ( v16 )
        __enable_irq();
    }
  }
  return result;
}

