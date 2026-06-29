// fwstruct annotate: 111c1c_rf_bus_write2_1c1c.c
// rf_bus_write2_1c1c @ 0x111c1c, size 224 bytes
// Doc: rf_bus_write_n13e [rf]: RF bus write helper computing index shifted by 0xe
// rf_bus_write_n13e [rf]: RF bus write helper computing index shifted by 0xe
int __fastcall rf_bus_write2_1c1c(int a1, int a2, int a3)
{
  int v3; // r6
  _DWORD *v4; // r4
  int v5; // r5
  _DWORD *v6; // r3
  _DWORD *v7; // r2

  if ( a1 )
  {
    v3 = 32 * (a1 - 1);
    v4 = (_DWORD *)(rf_state_check_n_4d8 + v3);
    v5 = *(_DWORD *)(v3 + rf_state_check_n_4d8);
    if ( (v5 & 0x80008000) == 0 )
      return (int)rf_bus_write_9a4(a1);
    v6 = (_DWORD *)(rf_state_check_n_4d8 + v3 + 8);
    if ( (rf_bus_write2_ne4 & v5) == 0x20000 )
      goto rf_bus_reset2_n244;
    goto LABEL_15;
  }
  v4 = rf_bus_write2_ext;
  v5 = *(_DWORD *)rf_bus_write2_ext;
  if ( (*(_DWORD *)rf_bus_write2_ext & 0x80008000) != 0 )
  {
    v6 = (_DWORD *)rf_bus_reset2_n310;
    if ( (rf_bus_write2_ne4 & v5) == 0x20000 )
    {
rf_bus_reset2_n244:
      if ( a2 == 0x8000000 )
      {
        if ( !a3 )
          goto LABEL_11;
        *v6 = 64;
        *v4 |= 0x8008000u;
LABEL_27:
        *v4 &= ~a3;
rf_bus_reset2_n260:
        v7 = rf_bus_init_n_b4;
        *((_DWORD *)rf_bus_init_n_b4 + 4) = (a1 << 6) | 0x20;
        while ( (v7[4] & 0x20) != 0 )
          ;
        if ( (v5 & 0x8000) == 0 )
          *v4 &= ~0x8000u;
LABEL_11:
        if ( !a1 )
          return a1;
        return (int)rf_bus_write_9a4(a1);
      }
      *v6 = 64;
      *v4 |= a2 | 0x8008000;
LABEL_6:
      if ( !a3 )
        goto rf_bus_reset2_n260;
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
      goto rf_bus_reset2_n260;
    }
    goto LABEL_6;
  }
  return a1;
}

