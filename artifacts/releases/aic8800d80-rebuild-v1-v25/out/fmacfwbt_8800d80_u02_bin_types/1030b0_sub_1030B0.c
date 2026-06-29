// sub_1030B0 @ 0x1030b0, size 112 bytes
uint32_t *sub_1030B0()
{
  int v0; // r1
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r3
  uint8_t *v4; // r2
  int v5; // r1
  unsigned int v6; // r2
  unsigned int v7; // r3
  uint32_t *result; // r0
  unsigned int *v9; // r1
  unsigned int v10; // r3
  int v11; // [sp+0h] [bp-14h]
  int v12; // [sp+4h] [bp-10h]
  int v13; // [sp+8h] [bp-Ch]
  int v14; // [sp+Ch] [bp-8h]
  uint8_t v15[4]; // [sp+10h] [bp-4h] BYREF

  v0 = *(uint32_t *)(dword_103120 + 4);
  v1 = *(uint32_t *)(dword_103120 + 8);
  v2 = *(uint32_t *)(dword_103120 + 12);
  v11 = *(uint32_t *)dword_103120;
  v12 = v0;
  v13 = v1;
  v14 = v2;
  if ( (*((uint32_t *)off_103124 + 4) & 2) != 0 )
  {
    v3 = dword_10312C;
    v4 = &v15[*((uint32_t *)off_103124 + 9) & 0xF];
    v5 = (char)*(v4 - 16);
    v6 = (unsigned __int8)*(v4 - 16);
    if ( (*((uint32_t *)off_103124 + 4) & 4) == 0 )
      v3 = dword_103128;
    if ( v5 < 0 )
    {
      v3 *= 2;
      v6 &= 0x7Fu;
    }
    v7 = v3 / v6;
  }
  else
  {
    v7 = 2 * *(uint32_t *)off_10313C;
  }
  result = off_103134;
  v9 = (unsigned int *)off_103138;
  v10 = v7 / (unsigned __int8)*((uint32_t *)off_103124 + 8);
  *(uint32_t *)off_103130 = v10;
  *v9 = v10 / (unsigned __int8)result[9];
  return result;
}

