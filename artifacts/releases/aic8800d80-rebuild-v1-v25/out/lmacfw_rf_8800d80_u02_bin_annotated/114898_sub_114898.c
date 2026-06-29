// fwstruct annotate: 114898_sub_114898.c
// sub_114898 @ 0x114898, size 96 bytes
int __fastcall sub_114898(int a1, int a2, unsigned int a3)
{
  int v6; // r4
  _DWORD v8[4]; // [sp+0h] [bp-50h] BYREF
  _BYTE v9[64]; // [sp+10h] [bp-40h] BYREF

  if ( !*(_DWORD *)off_1148F8 )
    sub_1142E0();
  MEMORY[0x1D8](*(_DWORD *)off_1148FC, 80, v8);
  if ( v8[0] != dword_114900 )
    return -1;
  v6 = a1 & v8[1];
  if ( !v6 )
    return 1;
  if ( (v6 & 1) != 0 )
  {
    sub_1282E8(a2, v9, 64);
    if ( a3 <= 0x3F )
      return -2;
  }
  return 0;
}

