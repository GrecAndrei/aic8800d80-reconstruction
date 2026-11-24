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
    *(_DWORD *)(v4 + 0x4c) = 34816;
    *(_DWORD *)(v4 + 0x54) = 629;
    __dsb(0xFu);
    v4[a1 + 512] = a2;
    *(_DWORD *)(v4 + 0x40) = 0;
    *(_DWORD *)(v4 + 0x4c) = 0;
    *(_DWORD *)(v4 + 0x54) &= ~4u;
  }
  *(_DWORD *)off_113B28 = 1;
  return sub_10F188(0);
}

