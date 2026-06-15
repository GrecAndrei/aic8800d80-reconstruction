// sub_117EF8 @ 0x117ef8, size 222 bytes
int sub_117EF8()
{
  int *v0; // r7
  _BYTE *v1; // r5
  _DWORD *v2; // r8
  _DWORD *v3; // r11
  int v4; // r10
  int *v5; // r9
  _DWORD *v6; // r6
  int i; // r4
  int v8; // r0
  int v9; // r2
  int v10; // r1
  int v11; // r3
  int *v12; // r3
  int v13; // r3
  int v14; // r3
  int v15; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_117FD8 = 1;
  }
  v0 = (int *)off_117FDC;
  v1 = off_117FE0;
  v2 = off_117FEC;
  v3 = off_117FF0;
  v4 = dword_117FF4;
  v5 = (int *)off_117FF8;
  ++*(_DWORD *)off_117FDC;
  v1[511] = 0;
  v6 = v2;
  for ( i = 4; i != -1; --i )
  {
    v8 = (unsigned __int8)i;
    if ( !*((_BYTE *)v6 + 158) && ((v2[52] & 1) == 0 || *((unsigned __int8 *)v2 + 190) != (unsigned __int8)i) )
    {
      if ( *((_DWORD *)v1 + 84) )
      {
        sub_1166FC((unsigned __int8)i);
        *(_DWORD *)(dword_117FE4 + 4 * i) = *v3 + *(_DWORD *)(v4 + 4 * i);
        *(_DWORD *)off_117FE8 = 1 << i;
        v8 = (unsigned __int8)i;
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(_DWORD *)off_117FD8 = 1;
        }
        v9 = *v0;
        v10 = *v0 + 1;
        v11 = (1 << i) | *v5;
        *v0 = v10;
        *v5 = v11;
        if ( v10 )
        {
          v12 = (int *)off_117FD8;
          *v0 = v9;
          v13 = *v12;
          if ( !v9 )
          {
            if ( v13 )
              __enable_irq();
          }
        }
      }
      sub_11AC28(v8);
    }
    v6 -= 7;
    v1 -= 84;
  }
  if ( *v0 )
  {
    v14 = *v0 - 1;
    v15 = *(_DWORD *)off_117FD8;
    *v0 = v14;
    if ( !v14 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  return irq_nesting_or(512);
}

