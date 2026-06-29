// fwstruct annotate: 111a78_rf_bus_write2_1a78.c
// rf_bus_write2_1a78 @ 0x111a78, size 224 bytes
// Doc: rf_bus_reset2_aaa [rf]: RF bus secondary reset
// rf_bus_reset2_aaa [rf]: RF bus secondary reset
int __fastcall rf_bus_write2_1a78(int a1, int a2, int a3)
{
  int v3; // r6
  _DWORD *v4; // r4
  int v5; // r5
  _DWORD *v6; // r3
  _DWORD *v7; // r2

  if ( a1 )
  {
    v3 = 32 * (a1 - 1);
    v4 = (_DWORD *)(rf_bus_write_n198 + v3);
    v5 = *(_DWORD *)(v3 + rf_bus_write_n198);
    if ( (v5 & 0x80008000) == 0 )
      return (int)rf_bus_write_n_1c0(a1);
    v6 = (_DWORD *)(rf_bus_write_n198 + v3 + 8);
    if ( (dword_111B5C & v5) == 0x20000 )
      goto LABEL_4;
    goto rf_bus_write2_n78;
  }
  v4 = rf_bus_mark_n484;
  v5 = *(_DWORD *)rf_bus_mark_n484;
  if ( (*(_DWORD *)rf_bus_mark_n484 & 0x80008000) != 0 )
  {
    v6 = (_DWORD *)rf_bus_write2_nf0;
    if ( (dword_111B5C & v5) == 0x20000 )
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
rf_bus_setup_n_2a0:
        v7 = rf_bus_write_n1a0_1b60;
        *((_DWORD *)rf_bus_write_n1a0_1b60 + 4) = (a1 << 6) | 0x20;
        while ( (v7[4] & 0x20) != 0 )
          ;
        if ( (v5 & 0x8000) == 0 )
          *v4 &= ~0x8000u;
LABEL_11:
        if ( !a1 )
          return a1;
        return (int)rf_bus_write_n_1c0(a1);
      }
      *v6 = 64;
      *v4 |= a2 | 0x8008000;
rf_bus_write2_n3c:
      if ( !a3 )
        goto rf_bus_setup_n_2a0;
      goto LABEL_27;
    }
rf_bus_write2_n78:
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
      goto rf_bus_setup_n_2a0;
    }
    goto rf_bus_write2_n3c;
  }
  return a1;
}

