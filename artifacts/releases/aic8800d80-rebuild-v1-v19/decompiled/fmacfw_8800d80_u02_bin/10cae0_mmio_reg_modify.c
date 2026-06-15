// mmio_reg_modify @ 0x10cae0, size 182 bytes
// Doc: mmio_reg_modify [mmio]: Reads/modifies MMIO register via indirect pointer
// mmio_reg_modify [mmio]: Reads/modifies MMIO register via indirect pointer
int mmio_reg_modify()
{
  int v0; // r4
  int result; // r0
  _DWORD *v2; // r2
  _BYTE *v3; // r3
  _DWORD *v4; // r2
  _DWORD *v5; // r2
  _DWORD *v6; // r2

  v0 = *(_DWORD *)off_10CB98;
  if ( (*(_DWORD *)off_10CB98 & 0x20) != 0 )
  {
    v6 = off_10CBA0;
    *(_DWORD *)off_10CBB8 = 32;
    *v6 = 32;
    irq_nesting_or_d104(0x80000);
  }
  result = v0 << 27;
  if ( (v0 & 0x10) != 0 )
  {
    v5 = off_10CBA0;
    *(_DWORD *)off_10CBB8 = 16;
    *v5 = 16;
    result = irq_nesting_or_d104(0x100000);
  }
  if ( (v0 & 2) != 0 )
  {
    result = irq_nesting_or_d104(0x8000000);
    *(_DWORD *)off_10CBB8 = 2;
  }
  if ( (v0 & 0x40000000) != 0 )
  {
    result = rf_bus_reset_n_32e(1);
    *(_DWORD *)off_10CBA0 = 0x40000000;
  }
  if ( v0 < 0 )
  {
    v2 = off_10CBA0;
    *(_DWORD *)off_10CB9C = 0x80000000;
    *v2 = 0x80000000;
  }
  if ( (v0 & 0x20000000) == 0 )
  {
    v3 = off_10CBA4;
    if ( !*(_BYTE *)off_10CBA4 || !*(_DWORD *)off_10CBA8 )
      return result;
LABEL_16:
    v4 = off_10CBAC;
    v3[1] = 1;
    *v4 |= 1u;
    return result;
  }
  v3 = off_10CBA4;
  *(_DWORD *)off_10CBA0 = 0x20000000;
  if ( *v3 )
    goto LABEL_16;
  if ( (*(_DWORD *)off_10CBB0 & dword_10CBB4) == 0x10000 )
    return rf_fault_dump_n_1d4();
  return result;
}

