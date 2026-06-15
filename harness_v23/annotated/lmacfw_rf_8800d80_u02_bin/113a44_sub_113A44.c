// v23 annotated: sub_113A44 @ 0x113a44
// Original: 113a44_sub_113A44.c
// Primary struct: <unclustered>
//
// sub_113A44 @ 0x113a44, size 130 bytes
int __fastcall sub_113A44(unsigned int a1)
{
  int v1; // r8
  _DWORD *v3; // r3
  unsigned int v4; // r6
  _DWORD *v5; // r5
  int v6; // r4
  unsigned int v7; // r2
  _DWORD *v8; // r3

  while ( !*(_DWORD *)off_113AC8 )
    ;
  if ( a1 <= 0x1F )
  {
    v3 = off_113ACC;
    v1 = 0;
    *((_DWORD *)off_113ACC + 16) = 1;
    v4 = a1 + 512;
    v5 = v3;
    v3[19] = 34816;
    v6 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v5[21] = (v6 << 12) | 0x27D;
        __dsb(0xFu);
        v7 = v5[v4];
        if ( v7 <= 0x29 )
          break;
        v1 |= 1 << v6;
LABEL_7:
        if ( ++v6 == 32 )
          goto LABEL_11;
      }
      if ( v7 <= 0x26 )
        goto LABEL_7;
      ++v6;
      uart_putc(101);
      if ( v6 == 32 )
      {
LABEL_11:
        v8 = off_113ACC;
        *((_DWORD *)off_113ACC + 16) = 0;
        v8[19] = 0;
        v8[21] &= ~4u;
        goto LABEL_4;
      }
    }
  }
  v1 = 0;
LABEL_4:
  *(_DWORD *)off_113AC8 = 1;
  return v1;
}

