// sub_116F34 @ 0x116f34, size 278 bytes
int __fastcall sub_116F34(int result)
{
  int v1; // r3
  int v2; // r6
  _DWORD *v3; // r2
  int *v4; // r5
  int v5; // r4
  int v6; // r1
  int *v7; // r3
  int v8; // r3
  _DWORD *v9; // r2
  _DWORD *v10; // r2
  _DWORD *v11; // r2
  _DWORD *v12; // r2
  _DWORD *v13; // r2
  _DWORD *v14; // r2

  v1 = *(_DWORD *)off_11704C;
  v2 = 1 << result;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_117050 = 1;
  }
  v3 = off_117054;
  v4 = (int *)off_11704C;
  v5 = *(_DWORD *)off_117054;
  v6 = *(_DWORD *)off_117054 + 1;
  *(_DWORD *)off_117054 = v6;
  *v4 = v1 & ~v2;
  if ( v6 )
  {
    v7 = (int *)off_117050;
    *v3 = v5;
    v8 = *v7;
    if ( !v5 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  *(_DWORD *)off_117058 = v2;
  switch ( result )
  {
    case 0:
      v10 = off_117060;
      *(_DWORD *)off_11705C = 0x10000;
      while ( (*v10 & 0x30) != 0 )
        ;
      *(_DWORD *)off_117064 = 0x10000;
      break;
    case 1:
      v11 = off_117060;
      *(_DWORD *)off_11705C = 0x20000;
      while ( (*v11 & 0x300) != 0 )
        ;
      *(_DWORD *)off_117064 = 0x20000;
      break;
    case 2:
      v13 = off_117060;
      *(_DWORD *)off_11705C = 0x40000;
      while ( (*v13 & 0x3000) != 0 )
        ;
      *(_DWORD *)off_117064 = 0x40000;
      break;
    case 3:
      v12 = off_117060;
      *(_DWORD *)off_11705C = 0x80000;
      while ( (*v12 & 0x30000) != 0 )
        ;
      *(_DWORD *)off_117064 = 0x80000;
      break;
    case 4:
      v14 = off_117060;
      *(_DWORD *)off_11705C = 0x8000;
      while ( *v14 << 30 )
        ;
      *(_DWORD *)off_117064 = 0x8000;
      break;
    case 5:
      v9 = off_117060;
      *(_DWORD *)off_11705C = 0x200000;
      while ( (*v9 & 0x3000000) != 0 )
        ;
      *(_DWORD *)off_117064 = 0x200000;
      break;
    default:
      if ( **(__int16 **)off_117068 < 0 )
        result = sub_12F46C(dword_117070, dword_11706C, 2338);
      break;
  }
  return result;
}

