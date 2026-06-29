// sub_114898 @ 0x114898, size 96 bytes
int  sub_114898(int a1, int a2, unsigned int a3)
{
  int v6; // r4
  uint32_t v8[4]; // [sp+0h] [bp-50h] BYREF
  uint8_t v9[64]; // [sp+10h] [bp-40h] BYREF

  if ( !*(uint32_t *)off_1148F8 )
    sub_1142E0();
  MEMORY[0x1D8](*(uint32_t *)off_1148FC, 80, v8);
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

