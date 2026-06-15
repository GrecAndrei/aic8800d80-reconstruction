// v23 annotated: sub_119D2C @ 0x119d2c
// Original: 119d2c_sub_119D2C.c
// Primary struct: <unclustered>
//
// sub_119D2C @ 0x119d2c, size 30 bytes
unsigned int __fastcall sub_119D2C(int a1, unsigned int a2)
{
  unsigned int v2; // r3

  v2 = (unsigned __int16)(((*(_WORD *)(a1 + 24) + 3) & 0xFFFC) + 4);
  if ( a2 <= v2 )
    return 0;
  else
    return ((unsigned int)(unsigned __int16)(a2 - v2) + 3) >> 2;
}

