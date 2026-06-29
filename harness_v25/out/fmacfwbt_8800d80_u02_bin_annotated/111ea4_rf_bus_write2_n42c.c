// fwstruct annotate: 111ea4_rf_bus_write2_n42c.c
// rf_bus_write2_n42c @ 0x111ea4, size 158 bytes
// Doc: rf_bus_write2_n43c [rf]: Writes a value onto the RF control bus
// rf_bus_write2_n43c [rf]: Writes a value onto the RF control bus
int __fastcall rf_bus_write2_n42c(int a1, int a2, unsigned int a3)
{
  int v3; // r4
  int v4; // r12
  int v5; // r3
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r7
  int v9; // r4
  char v10; // r6

  if ( *(_BYTE *)off_111F44 != 4 )
    return 1;
  v3 = a1 - 1;
  if ( (unsigned __int8)(a1 - 1) > 5u )
    return 2;
  if ( a2 << 30 )
  {
    log_printf(rf_state_check_f54);
    return 3;
  }
  else
  {
    v4 = dword_111F48 + 16 * v3;
    if ( *(_DWORD *)v4 )
    {
      return 4;
    }
    else
    {
      v5 = 32 * a1 + 1075838976;
      if ( (*((_DWORD *)&REG_4020_0b00 + 8 * a1) & 0x8000) != 0 )
      {
        v6 = dword_111F4C;
        *(_DWORD *)(dword_111F48 + 16 * v3) = a2;
        v7 = *(_DWORD *)(v6 + 4 * v3);
        v8 = dword_111F50;
        *(_BYTE *)(v4 + 8) = 1;
        v9 = 32 * v3 + 1075838976;
        v10 = *(_BYTE *)(v7 + 3) & 0x31;
        if ( a3 >= v8 )
          a3 = v8;
        *(_DWORD *)(v4 + 4) = a3;
        *(_WORD *)v7 = a3;
        *(_DWORD *)(v7 + 4) = a2;
        *(_BYTE *)(v7 + 3) = v10 | 0xE;
        *(_DWORD *)(v9 + 2868) = v7;
        *(_DWORD *)(v5 + 2816) |= 0x84000000;
        return 0;
      }
      else
      {
        return 5;
      }
    }
  }
}

