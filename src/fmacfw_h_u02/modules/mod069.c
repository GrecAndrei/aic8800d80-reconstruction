// l2c_state_check @ 0x1400c4
/* luna: Validates the connection index and updates the L2CAP link state from its control block, timeout, and RF conditions. */
int l2c_state_check(int result) {
  unsigned int v1; // r6
  int v2; // r4
  int v3; // r7
  int v4; // r5
  char v5; // r3
  char v6; // r3
  volatile uint32_t *v7; // r8
  int v8; // r1
  int16_t v9; // r2
  int v10; // nf
  unsigned int v11; // r6
  char v12; // r3
  char v13; // r3
  int v14; // r0
  char v15; // r3

  v1 = *(volatile uint8_t *)(result + 29);
  v2 = result;
  if ( v1 > 0x1F )
  {
    *(volatile uint8_t *)(result + 54) = 0;
  }
  else
  {
    v3 = dword_1401E4;
    v4 = *(volatile uint32_t *)(dword_1401E4 + 696 * v1 + 340);
    if ( **(volatile int16_t **)off_1401E0 < 0 && !v4 )
      irq_disable_mmio_write(dword_1401F0, dword_1401EC, 2758);
    v5 = *(volatile uint8_t *)(v4 + 166);
    if ( (*(volatile uint32_t *)(v2 + 36) & 0x200000) != 0 && (*(volatile uint8_t *)(v4 + 166) & 4) != 0 )
      v6 = v5 | 2;
    else
      v6 = v5 & 0xFD;
    v7 = (void *)(uintptr_t)(off_1401F4);
    *(volatile uint8_t *)(v4 + 166) = v6;
    if ( v7[4] - *(volatile uint32_t *)v4 > (unsigned int)dword_1401E8 )
    {
      v14 = l2c_ccb_prepare(v4, 0);
      v15 = (*(volatile uint8_t *)(v4 + 167) + 1) & 3;
      *(volatile uint8_t *)(v4 + 167) = v15;
      *(volatile uint8_t *)(v4 + 154) = 0;
      *(volatile uint8_t *)(v4 + 168) = 0;
      *(volatile uint32_t *)v4 = v7[4];
      *(volatile uint8_t *)(v2 + 54) = 4 * v15;
      if ( v14 )
      {
        if ( !mac_clear_flag_and_check(v4) )
          *(volatile uint32_t *)(v2 + 36) &= ~0x200000u;
        *(volatile uint8_t *)(v3 + 696 * v1 + 350) |= 0x11u;
      }
    }
    else
    {
      *(volatile uint8_t *)(v2 + 54) = *(volatile uint8_t *)(v4 + 168) | (4 * *(volatile uint8_t *)(v4 + 167));
    }
    result = rf_check_flag(v4);
    if ( result )
    {
      v8 = *(volatile uint32_t *)(v2 + 36);
      v9 = *(volatile uint16_t *)(v2 + 30);
      *(volatile uint8_t *)(v2 + 54) &= 0xFCu;
      v10 = (v8 & 0x200000) != 0;
      v11 = v3 + 696 * v1;
      v12 = *(volatile uint8_t *)(v11 + 350);
      *(volatile uint16_t *)(v2 + 30) = v9 | 0x2000;
      if ( (v8 & 0x200000) != 0 )
        v8 |= 0x280000u;
      v13 = v12 | 0x20;
      if ( v10 )
        *(volatile uint32_t *)(v2 + 36) = v8;
      *(volatile uint8_t *)(v11 + 350) = v13;
    }
  }
  return result;
}



// l2c_sig_hdr_parse @ 0x1401f8
/* luna: Updates L2C connection flags based on fields decoded from a header word and the supplied match and qualifier values. */
int l2c_sig_hdr_parse(int result, unsigned int a2, int a3, int a4, uint8_t a5, int a6, int a7, char a8) {
  unsigned int v8; // r2
  unsigned int v9; // r1
  unsigned int v10; // r1
  unsigned int v11; // r3
  unsigned int v12; // r3

  v8 = a2 >> 11;
  if ( ((a2 >> 11) & 6) == 0 )
  {
    v12 = *(volatile uint32_t *)(result + 60) & 0xFFFFFFEF;
    goto LABEL_11;
  }
  v9 = a2 & 0x7F;
  if ( (v8 & 7) == 4 )
    v10 = v9 >> 4;
  else
    v10 = (v9 >> 3) & 3;
  if ( a4 && v10 == a5 )
  {
    v11 = *(volatile uint32_t *)(result + 60) | 4;
    *(volatile uint32_t *)(result + 60) = v11;
    if ( !a8 )
      goto LABEL_10;
LABEL_7:
    *(volatile uint32_t *)(result + 60) = v11 | 0x10;
    return result;
  }
  v11 = *(volatile uint32_t *)(result + 60) & 0xFFFFFFFB;
  *(volatile uint32_t *)(result + 60) = v11;
  if ( a8 )
    goto LABEL_7;
LABEL_10:
  v12 = v11 & 0xFFFFFFEF;
LABEL_11:
  *(volatile uint32_t *)(result + 60) = v12;
  return result;
}



