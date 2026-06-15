// sub_103FBC @ 0x103fbc, size 48 bytes
int __fastcall sub_103FBC(int a1, int a2, _DWORD *a3)
{
  int v3; // r2
  unsigned int v4; // r0
  int v5; // r3

  v3 = a3[sub_103D60(a1, a2, a3)];
  v4 = (unsigned int)v3 >> 20;
  v5 = (unsigned __int16)v3 >> 4;
  if ( v3 < 0 )
    v4 -= 4096;
  if ( (((unsigned int)v3 >> 4) & 0x800) != 0 )
    v5 -= 4096;
  return v5 * v5 + v4 * v4;
}

