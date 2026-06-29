// fwstruct annotate: 116df4_sub_116DF4.c
// sub_116DF4 @ 0x116df4, size 278 bytes
int __fastcall sub_116DF4(int result)
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

  v1 = *(_DWORD *)off_116F0C;
  v2 = 1 << result;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_116F10 = 1;
  }
  v3 = off_116F14;
  v4 = (int *)off_116F0C;
  v5 = *(_DWORD *)off_116F14;
  v6 = *(_DWORD *)off_116F14 + 1;
  *(_DWORD *)off_116F14 = v6;
  *v4 = v1 & ~v2;
  if ( v6 )
  {
    v7 = (int *)off_116F10;
    *v3 = v5;
    v8 = *v7;
    if ( !v5 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  *(_DWORD *)off_116F18 = v2;
  switch ( result )
  {
    case 0:
      v10 = off_116F20;
      *(_DWORD *)off_116F1C = 0x10000;
      while ( (*v10 & 0x30) != 0 )
        ;
      *(_DWORD *)off_116F24 = 0x10000;
      break;
    case 1:
      v11 = off_116F20;
      *(_DWORD *)off_116F1C = 0x20000;
      while ( (*v11 & 0x300) != 0 )
        ;
      *(_DWORD *)off_116F24 = 0x20000;
      break;
    case 2:
      v13 = off_116F20;
      *(_DWORD *)off_116F1C = 0x40000;
      while ( (*v13 & 0x3000) != 0 )
        ;
      *(_DWORD *)off_116F24 = 0x40000;
      break;
    case 3:
      v12 = off_116F20;
      *(_DWORD *)off_116F1C = 0x80000;
      while ( (*v12 & 0x30000) != 0 )
        ;
      *(_DWORD *)off_116F24 = 0x80000;
      break;
    case 4:
      v14 = off_116F20;
      *(_DWORD *)off_116F1C = 0x8000;
      while ( *v14 << 30 )
        ;
      *(_DWORD *)off_116F24 = 0x8000;
      break;
    case 5:
      v9 = off_116F20;
      *(_DWORD *)off_116F1C = 0x200000;
      while ( (*v9 & 0x3000000) != 0 )
        ;
      *(_DWORD *)off_116F24 = 0x200000;
      break;
    default:
      if ( **(__int16 **)off_116F28 < 0 )
        result = sub_12F32C(dword_116F30, dword_116F2C, 2338);
      break;
  }
  return result;
}

