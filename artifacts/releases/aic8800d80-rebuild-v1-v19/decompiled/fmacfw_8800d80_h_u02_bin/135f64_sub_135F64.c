// sub_135F64 @ 0x135f64, size 148 bytes
int __fastcall sub_135F64(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  __int16 v6; // r2
  int v7; // r0
  int v9; // r0
  _DWORD *v10; // r1
  _DWORD *v11; // r4
  int v12; // r6
  int v13; // r0
  unsigned int v14; // r3
  int *v15; // r3
  int v16; // r3

  sub_12E948(dword_135FFC, dword_135FF8);
  v6 = a3;
  v7 = dword_136000 + 1320 * *a2;
  if ( *(_BYTE *)(v7 + 106) == 2 && !*(_BYTE *)(v7 + 108) )
  {
    v9 = sub_12CD48(7u);
    v6 = a3;
    if ( !v9 )
    {
      sub_12847C(*a2);
      *(_BYTE *)off_136004 = 0;
      v6 = a3;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_136008 = 1;
      }
      v10 = off_13600C;
      v11 = off_136010;
      v12 = *(_DWORD *)off_13600C;
      v13 = *(_DWORD *)off_13600C + 1;
      v14 = *((_DWORD *)off_136010 + 1) & 0xFFFFFFEF;
      *(_DWORD *)off_13600C = v13;
      v11[1] = v14;
      if ( v13 )
      {
        v15 = (int *)off_136008;
        *v10 = v12;
        v16 = *v15;
        if ( !v12 )
        {
          if ( v16 )
            __enable_irq();
        }
      }
    }
  }
  sub_12C8D0(7175, a4, v6);
  return 0;
}

