// v23 annotated: sub_113AD0 @ 0x113ad0
// Original: 113ad0_sub_113AD0.c
// Primary struct: <unclustered>
//
// sub_113AD0 @ 0x113ad0, size 88 bytes
int __fastcall sub_113AD0(unsigned int a1, int a2)
{
  _DWORD *v4; // r3

  sub_10F188(1);
  while ( !*(_DWORD *)off_113B28 )
    ;
  if ( a1 <= 0x1F )
  {
    v4 = off_113B2C;
    *((_DWORD *)off_113B2C + 16) = 1;
    v4[19] = 34816;
    v4[21] = 629;
    __dsb(0xFu);
    v4[a1 + 512] = a2;
    v4[16] = 0;
    v4[19] = 0;
    v4[21] &= ~4u;
  }
  *(_DWORD *)off_113B28 = 1;
  return sub_10F188(0);
}

