// v23 annotated: sub_111ADC @ 0x111adc
// Original: 111adc_sub_111ADC.c
// Primary struct: <unclustered>
//
// sub_111ADC @ 0x111adc, size 224 bytes
int __fastcall sub_111ADC(int a1, int a2, int a3)
{
  int v3; // r6
  _DWORD *v4; // r4
  int v5; // r5
  _DWORD *v6; // r3
  _DWORD *v7; // r2

  if ( a1 )
  {
    v3 = 32 * (a1 - 1);
    v4 = (_DWORD *)(dword_111BBC + v3);
    v5 = *(_DWORD *)(v3 + dword_111BBC);
    if ( (v5 & 0x80008000) == 0 )
      return (int)sub_111864(a1);
    v6 = (_DWORD *)(dword_111BBC + v3 + 8);
    if ( (dword_111BC0 & v5) == 0x20000 )
      goto LABEL_4;
    goto LABEL_15;
  }
  v4 = off_111BC8;
  v5 = *(_DWORD *)off_111BC8;
  if ( (*(_DWORD *)off_111BC8 & 0x80008000) != 0 )
  {
    v6 = (_DWORD *)dword_111BCC;
    if ( (dword_111BC0 & v5) == 0x20000 )
    {
LABEL_4:
      if ( a2 == 0x8000000 )
      {
        if ( !a3 )
          goto LABEL_11;
        *v6 = 64;
        *v4 |= 0x8008000u;
LABEL_27:
        *v4 &= ~a3;
LABEL_7:
        v7 = off_111BC4;
        *((_DWORD *)off_111BC4 + 4) = (a1 << 6) | 0x20;
        while ( (v7[4] & 0x20) != 0 )
          ;
        if ( (v5 & 0x8000) == 0 )
          *v4 &= ~0x8000u;
LABEL_11:
        if ( !a1 )
          return a1;
        return (int)sub_111864(a1);
      }
      *v6 = 64;
      *v4 |= a2 | 0x8008000;
LABEL_6:
      if ( !a3 )
        goto LABEL_7;
      goto LABEL_27;
    }
LABEL_15:
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
    goto LABEL_6;
  }
  return a1;
}

