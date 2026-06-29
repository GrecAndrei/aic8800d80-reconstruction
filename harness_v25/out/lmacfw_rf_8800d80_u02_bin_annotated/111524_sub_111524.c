// fwstruct annotate: 111524_sub_111524.c
// sub_111524 @ 0x111524, size 224 bytes
// Doc: rf_bus_mark_n45e [rf]: Clear/mark RF bus register bits via mask
// rf_bus_mark_n45e [rf]: Clear/mark RF bus register bits via mask
int __fastcall sub_111524(int a1, int a2, int a3)
{
  int v3; // r6
  _DWORD *v4; // r4
  int v5; // r5
  _DWORD *v6; // r3
  _DWORD *v7; // r2

  if ( a1 )
  {
    v3 = 32 * (a1 - 1);
    v4 = (_DWORD *)(dword_111604 + v3);
    v5 = *(_DWORD *)(v3 + dword_111604);
    if ( (v5 & 0x80008000) == 0 )
      return (int)sub_1112AC(a1);
    v6 = (_DWORD *)(dword_111604 + v3 + 8);
    if ( (rf_bus_mark_n47c & v5) == 0x20000 )
      goto rf_bus_write_ndc;
    goto rf_bus_write_n_2e3;
  }
  v4 = off_111610;
  v5 = *(_DWORD *)off_111610;
  if ( (*(_DWORD *)off_111610 & 0x80008000) != 0 )
  {
    v6 = (_DWORD *)dword_111614;
    if ( (rf_bus_mark_n47c & v5) == 0x20000 )
    {
rf_bus_write_ndc:
      if ( a2 == 0x8000000 )
      {
        if ( !a3 )
          goto LABEL_11;
        *v6 = 64;
        *v4 |= 0x8008000u;
LABEL_27:
        *v4 &= ~a3;
LABEL_7:
        v7 = rf_bus_write_n1a0;
        *((_DWORD *)rf_bus_write_n1a0 + 4) = (a1 << 6) | 0x20;
        while ( (v7[4] & 0x20) != 0 )
          ;
        if ( (v5 & 0x8000) == 0 )
          *v4 &= ~0x8000u;
LABEL_11:
        if ( !a1 )
          return a1;
        return (int)sub_1112AC(a1);
      }
      *v6 = 64;
      *v4 |= a2 | 0x8008000;
rf_bus_mark_cmp:
      if ( !a3 )
        goto LABEL_7;
      goto LABEL_27;
    }
rf_bus_write_n_2e3:
    *v6 = 64;
    *v4 |= a2 | 0x8008000;
    if ( v5 < 0 )
    {
      if ( (v5 & 0x20000) == 0 )
      {
        while ( (*v6 & 0x40) == 0 )
          ;
        *v6 = 64;
      }
      if ( a3 )
        *v4 &= ~a3;
      *v6 = 2;
      *v4 |= 0x40000000u;
      while ( (*v6 & 2) == 0 )
        ;
      goto LABEL_7;
    }
    goto rf_bus_mark_cmp;
  }
  return a1;
}

