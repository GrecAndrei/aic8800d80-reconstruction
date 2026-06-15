// sub_132AA0 @ 0x132aa0, size 22 bytes
int __fastcall sub_132AA0(int a1)
{
  unsigned int v1; // r3
  int v2; // r0

  v1 = *(_DWORD *)(a1 + 220);
  v2 = HIBYTE(v1) & 0x3F;
  if ( (v1 & 0x40000000) != 0 )
    return v2 | 0x300;
  else
    return v2 | 0x100;
}

