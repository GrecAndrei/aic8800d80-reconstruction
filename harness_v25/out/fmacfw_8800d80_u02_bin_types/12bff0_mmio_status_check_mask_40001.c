// mmio_status_check_mask_40001 @ 0x12bff0, size 402 bytes
// Doc: mmio_status_check_mask_40001 [mmio]: Read MMIO and mask status bits against 0x40001
// mmio_status_check_mask_40001 [mmio]: Read MMIO and mask status bits against 0x40001
int  mmio_status_check_mask_40001(int result, int a2, int a3, int a4)
{
  int v4; // r1
  int v5; // r4
  int v6; // r3
  int v7; // r5

  v4 = *(uint32_t *)off_12C184;
  v5 = *(uint32_t *)off_12C188 & *(uint32_t *)off_12C184;
  v6 = dword_12C18C & v5;
  *((uint32_t *)off_12C184 + 1) = v5;
  if ( v6 )
    result = irq_nesting_or_d104(0x1000000);
  if ( (dword_12C190 & v5) != 0 )
    result = irq_nesting_or_d104(0x800000);
  if ( (v5 & 4) != 0 )
    result = sub_12B540();
  if ( (v5 & 8) != 0 )
    result = sub_12BE8C(result, v4);
  if ( (v5 & 0x10000000) != 0 )
  {
    v7 = *(uint32_t *)off_12C1A0;
    *((uint8_t *)off_12C1A4 + 30) |= *(uint8_t *)off_12C1A0 & 0x3F;
    result = irq_nesting_or_d104(0x40000);
    *(uint32_t *)off_12C1A8 = v7;
  }
  if ( **(__int16 **)off_12C194 < 0 )
  {
    if ( (v5 & 0x400000) != 0 )
    {
      return fmac_phy_op_handler(dword_12C1AC, dword_12C198, 847, a4);
    }
    else if ( (v5 & 0x200000) != 0 )
    {
      return fmac_phy_op_handler(dword_12C1B0, dword_12C198, 848, a4);
    }
    else if ( (v5 & 0x40) != 0 )
    {
      return fmac_phy_op_handler(dword_12C1B4, dword_12C198, 849, a4);
    }
    else if ( (v5 & 0x100) != 0 )
    {
      return fmac_phy_op_handler(dword_12C1B8, dword_12C198, 850, a4);
    }
    else if ( (v5 & 0x1000) != 0 )
    {
      return fmac_phy_op_handler(dword_12C1BC, dword_12C198, 851, a4);
    }
    else if ( (v5 & 0x2000) != 0 )
    {
      return fmac_phy_op_handler(dword_12C1C0, dword_12C198, 852, a4);
    }
    else if ( (v5 & 0x4000) != 0 )
    {
      return fmac_phy_op_handler(dword_12C1C4, dword_12C198, 853, a4);
    }
    else if ( (v5 & 0x8000) != 0 )
    {
      return fmac_phy_op_handler(dword_12C1C8, dword_12C198, 854, a4);
    }
    else if ( (v5 & 0x10000) != 0 )
    {
      return fmac_phy_op_handler(dword_12C1CC, dword_12C198, 855, a4);
    }
    else if ( (v5 & 0x20000) != 0 )
    {
      return fmac_phy_op_handler(dword_12C1D0, dword_12C198, 856, a4);
    }
    else
    {
      result = v5 << 7;
      if ( (v5 & 0x1000000) != 0 )
      {
        return fmac_phy_op_handler(dword_12C1D4, dword_12C198, 857, a4);
      }
      else if ( (v5 & 0x2000000) != 0 )
      {
        return fmac_phy_op_handler(dword_12C1D8, dword_12C198, 858, a4);
      }
      else if ( (v5 & 0x100000) != 0 )
      {
        return fmac_phy_op_handler(dword_12C1DC, dword_12C198, 859, a4);
      }
      else if ( (v5 & 0x8000000) != 0 )
      {
        return fmac_phy_op_handler(dword_12C19C, dword_12C198, 860, a4);
      }
    }
  }
  return result;
}

