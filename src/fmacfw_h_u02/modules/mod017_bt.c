// ecc_point_mul @ 0x119368
unsigned int ecc_point_mul(int a1, int a2, int a3) {
  volatile int16_t **v3; // r10
  unsigned int v5; // r3
  int v8; // r4
  unsigned int v9; // r9
  int v10; // zf
  int v11; // r10
  unsigned int v12; // r8
  int v13; // s16
  int ( *v14)(int, uint32_t); // r3
  char v15; // r1
  int v16; // r4
  int v17; // r9
  int v18; // r6
  volatile unsigned int *v19; // r11
  int i; // r0
  unsigned int v21; // r0
  unsigned int v22; // r3
  int v23; // r9
  unsigned int v24; // r8
  int v25; // r11
  unsigned int v26; // r1
  int v27; // r0
  volatile uint8_t *v28; // r2
  unsigned int result; // r0
  char v30; // r3
  int v31; // r1
  unsigned int v32; // r2
  int v33; // r0
  int v34; // [sp+8h] [bp-1Ch]
  int v35; // [sp+8h] [bp-1Ch]
  int v36; // [sp+Ch] [bp-18h]
  unsigned int v37; // [sp+10h] [bp-14h] BYREF
  int v38; // [sp+14h] [bp-10h] BYREF
  int ( *v39)(int, uint32_t); // [sp+18h] [bp-Ch] BYREF
  int ( *v40[2])(int, int); // [sp+1Ch] [bp-8h] BYREF

  v3 = (volatile int16_t **)off_119598;
  v5 = *(volatile uint32_t *)(a1 + 4);
  v36 = *(volatile uint8_t *)(a1 + 12);
  v8 = (v5 >> 7) & 3;
  v9 = (v5 >> 11) & 7;
  if ( **(volatile int16_t **)off_119598 < 0 && ((v5 >> 11) & 6) == 0 )
    irq_disable_mmio_write(dword_119584, dword_119580, 397);
  v10 = v9 == 4;
  if ( v9 <= 4 )
  {
    v22 = *(volatile uint32_t *)(a1 + 4);
    v23 = *(volatile uint8_t *)(a1 + 12);
    v24 = v22 & 0x7F;
    v25 = (v22 >> 9) & 1;
    if ( v10 )
    {
      v31 = **v3;
      v32 = v24 >> 4;
      v33 = (v24 >> 4) + 1;
      v12 = v22 & 0xF;
      v38 = v33;
      if ( v31 < 0 )
      {
        if ( v32 <= 3 || (irq_disable_mmio_write(dword_119594, dword_119588, 340), **v3 < 0) )
        {
          if ( v12 > 9 )
            irq_disable_mmio_write(dword_119590, dword_119588, 341);
        }
      }
      v34 = dword_11956C;
      v37 = *(volatile uint32_t *)(dword_11956C + 696 * v23 + 16);
    }
    else
    {
      if ( **v3 < 0 && (v22 & 0x60) != 0 )
      {
        v35 = *(volatile uint32_t *)(a1 + 4);
        irq_disable_mmio_write(dword_11958C, dword_119588, 349);
        v22 = (v22 & ~0xFFu) | ((uint8_t)(v35) & 0xFFu);
      }
      v34 = dword_11956C;
      v26 = *(volatile uint16_t *)(dword_11956C + 696 * v23 + 20);
      v38 = ((v24 >> 3) & 3) + 1;
      v12 = v22 & 7;
      v37 = v26;
    }
    v14 = (int ( *)(int, uint32_t))dword_119570;
    v39 = (int ( *)(int, uint32_t))dword_119570;
    v11 = v25 | (8 * v12);
    v40[0] = (int ( *)(int, int))dword_119574;
    v12 = (v12 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
    goto LABEL_14;
  }
  v11 = phy_rate_to_index(a1, v9, (void *)(&v39), (void *)(v40), (void *)(&v37), &v38);
  v12 = (*(volatile uint8_t *)(a1 + 344) >> 5) & 1;
  if ( v9 != 7 )
  {
    v14 = v39;
    v34 = dword_11956C;
LABEL_14:
    v15 = v8;
    v13 = (uint8_t)v8;
    goto LABEL_5;
  }
  v13 = (uint8_t)v8;
  v14 = v39;
  v34 = dword_11956C;
  v15 = 0;
LABEL_5:
  v16 = 0;
  v17 = dword_11959C;
  *(volatile uint8_t *)(a3 + 34) = v15;
  v18 = a2 + 4;
  *(volatile uint8_t *)(a3 + 35) = 0;
  v19 = (volatile unsigned int *)(a3 + 12);
  for ( i = v14(v11, 0); ; i = v39(v11, (uint8_t)v16) )
  {
    v21 = (i * v38 * (unsigned int)*(volatile uint16_t *)(v17 + 2 * v18)) >> v12;
    if ( v21 >= v37 )
      v21 = v37;
    *v19++ = v21;
    if ( *(volatile uint8_t *)(a3 + 34) < ++v16 )
      break;
  }
  v27 = v40[0](v11, v13);
  v28 = (void *)(uintptr_t)(off_119578);
  result = v27 * v38 * *(volatile uint8_t *)(v34 + 696 * v36 + 28);
  *(volatile uint16_t *)(a3 + 28) = result >> v12;
  v30 = v28[381];
  if ( !v30 || *(volatile uint8_t *)off_11957C )
    v30 = *(volatile uint8_t *)(v34 + 696 * *(volatile uint8_t *)(a1 + 12) + 6 * *(volatile uint8_t *)(a1 + 13) + 354);
  *(volatile uint8_t *)(a3 + 32) = v30;
  return result;
}



// compare_device_state @ 0x1195a0
int compare_device_state(int a1, int a2, int a3) {
  unsigned int v3; // r7
  int result; // r0
  int v7; // r3
  int v8; // r6
  int v9; // nf
  int16_t v10; // r3
  int v11; // r1
  int v12; // r9
  int v13; // r7
  int v14; // r2
  int v15; // r8
  int v16; // r10
  int v17; // r0
  int v18; // r3
  int v19; // r2
  int v20; // r1
  int v21; // r1
  volatile uint32_t *v22; // r2
  int16_t v23; // r3
  int v24; // r2
  char v25; // r3

  if ( *(volatile uint8_t *)(a1 + 29) != *(volatile uint8_t *)(a2 + 29)
    || *(volatile uint8_t *)(a1 + 27) != *(volatile uint8_t *)(a2 + 27) )
  {
    return 0;
  }
  v7 = *(volatile uint32_t *)(a1 + 36);
  v8 = *(volatile uint32_t *)(a2 + 68);
  v9 = (v7 & 0x200000) != 0;
  if ( (v7 & 0x200000) != 0 )
    v7 = *(volatile uint32_t *)(a1 + 68);
  else
    v3 = *(volatile uint16_t *)(a1 + 80);
  if ( v9 )
    v3 = *(volatile uint16_t *)(v7 + 10);
  v10 = *(volatile uint16_t *)(v8 + 8);
  if ( (v10 & 6) == 4 )
    return 0;
  if ( v3 <= 0xE78 )
  {
    result = v10 & 2;
    if ( (v10 & 2) == 0 )
    {
      v11 = *(volatile uint32_t *)(v8 + 264);
      if ( v11 )
      {
        if ( *(volatile uint32_t *)(v11 + 16) != dword_119720 || (int)(v3 + *(volatile uint16_t *)(v8 + 10)) <= 3704 )
          return result;
        goto LABEL_16;
      }
      return 0;
    }
  }
LABEL_16:
  result = v10 & 1;
  if ( (v10 & 1) != 0 )
  {
    result = *(volatile uint16_t *)(*(volatile uint32_t *)(v8 + 324) + 82) & 1;
    if ( result )
    {
      *(volatile uint16_t *)(v8 + 8) = v10 | 6;
      return 1;
    }
  }
  else
  {
    v12 = dword_119730;
    v13 = dword_119730 + 84 * a3;
    v14 = *(volatile uint8_t *)(v13 + 77);
    if ( v14 != 1 )
    {
      v15 = *(volatile uint32_t *)(v13 + 52);
      if ( (*(volatile uint16_t *)(v15 + 82) & 1) != 0 )
      {
        if ( (*(volatile uint32_t *)off_119728 & 0x3F) > *(volatile uint8_t *)(*(volatile uint32_t *)off_119724 + 62)
                                            + *(volatile uint8_t *)(*(volatile uint32_t *)off_119724 + 63) )
        {
          v16 = *(volatile uint32_t *)(v15 + 76);
          *(volatile uint8_t *)(v16 + 1) = v14;
          v17 = *(volatile uint32_t *)(v13 + 48);
          *(volatile uint32_t *)(v15 + 36) |= 0x380000u;
          *(volatile uint32_t *)(v8 + 324) = v15;
          sta_rate_limit_check((void *)(uintptr_t)(v17));
          v18 = *(volatile uint8_t *)(*(volatile uint32_t *)off_11972C + 1);
          if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_11972C + 1) )
          {
            btm_acl_update(
              v8,
              *(volatile uint16_t *)(v15 + 34),
              *(volatile uint8_t *)(v8 + 12),
              *(volatile uint8_t *)(v8 + 13),
              *(volatile uint8_t *)(v13 + 78));
            *(volatile uint32_t *)(v16 + 20) = v8 + 84;
          }
          else
          {
            v19 = *(volatile uint32_t *)(a1 + 76);
            *(volatile uint32_t *)(v8 + 20) = v18;
            v20 = *(volatile uint32_t *)(v19 + 68) << 10;
            *(volatile uint32_t *)(v16 + 16) = v18;
            *(volatile uint32_t *)(v16 + 20) = v18;
            if ( v20 >= 0 )
            {
              v21 = v8 + 16;
              *(volatile uint32_t *)(v19 + 16) = v8 + 16;
            }
            else
            {
              v21 = v8 + 16;
              *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 68) + 20) = v8 + 16;
            }
            v22 = (volatile uint32_t *)(v12 + 84 * a3);
            *v22 = v16 + 12;
            v22[1] = v21;
            v22[2] = 1;
          }
          v23 = *(volatile uint16_t *)(v8 + 8);
          *(volatile uint32_t *)(v16 + 68) = *(volatile uint32_t *)(v15 + 36) | 0x100;
          if ( (v23 & 2) != 0 )
            *(volatile uint32_t *)(*(volatile uint32_t *)(v8 + 52) + 20) = *(volatile uint32_t *)(v8 + 4);
          *(volatile uint16_t *)(v8 + 8) = v23 | 0xF;
          wlan_ioctl_handler_1(v12 + 84 * a3 + 28, (volatile uint32_t *)v8);
          v24 = v12 + 84 * a3;
          v25 = *(volatile uint8_t *)(v24 + 80);
          *(volatile uint32_t *)(v24 + 44) = 0;
          *(volatile uint8_t *)(v24 + 80) = v25 + 1;
          return 1;
        }
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}


// btm_is_link_active @ 0x119734
int btm_is_link_active(int a1, volatile int *a2, unsigned int a3, unsigned int a4, uint8_t a5) {
  volatile int *v5; // r4
  int v6; // r5
  int v8; // r6
  int v9; // r8
  volatile uint16_t *v10; // lr
  int v11; // r9
  char v12; // r0
  int v13; // r0
  unsigned int v14; // r0
  unsigned int v15; // r7
  unsigned int v16; // r0
  unsigned int v17; // r3
  int16_t v18; // r10
  volatile int *v19; // r8
  unsigned int v20; // r7
  int16_t v21; // r12
  int v22; // r10
  int v23; // r8

  v5 = (volatile int *)*a2;
  if ( (*(volatile uint16_t *)(*a2 + 82) & 1) == 0 )
    return 0;
  v6 = *(volatile uint32_t *)(a1 + 68);
  if ( *(volatile uint8_t *)(v6 + 12) != *((volatile uint8_t *)v5 + 29)
    || *(volatile uint8_t *)(v6 + 13) != *((volatile uint8_t *)v5 + 27) )
  {
    return 0;
  }
  v8 = v5[19];
  v9 = *(volatile uint32_t *)(v6 + 324);
  v10 = *(volatile uint16_t **)(v8 + 28);
  v11 = *(volatile uint32_t *)(v9 + 76);
  if ( !v10 || (*v10 & 0x8000) != 0 )
  {
    v13 = *(volatile uint32_t *)(v8 + 36);
  }
  else
  {
    *v10 = ~((unsigned int)~((uint16_t)*v10 << 17) >> 17);
    v12 = *((volatile uint8_t *)v5 + 50) + 4;
    *((volatile uint8_t *)v5 + 51) += 4;
    *((volatile uint8_t *)v5 + 50) = v12;
    v13 = *(volatile uint32_t *)(v8 + 36) + 4;
    *(volatile uint32_t *)(v8 + 32) += 4;
    *(volatile uint32_t *)(v8 + 36) = v13;
  }
  v14 = (uint16_t)(((v13 + 3) & 0xFFFC) + 4);
  if ( a4 <= v14 )
  {
    v15 = 0;
  }
  else
  {
    v15 = ((unsigned int)(uint16_t)(a4 - v14) + 3) >> 2;
    v14 = (uint16_t)(v14 + 4 * v15);
  }
  v16 = v14 + *(volatile uint32_t *)(v6 + 40);
  if ( v16 > a3 )
    return 0;
  v17 = *(volatile uint32_t *)(v9 + 36) & 0xFFE7FFFF;
  v18 = *(volatile uint16_t *)(v6 + 10);
  --*(volatile uint8_t *)(dword_11987C + 84 * a5 + 80);
  *(volatile uint32_t *)(v9 + 36) = v17 | 0x300000;
  v19 = (volatile int *)off_119884;
  v20 = v5[9] & 0xFFE7FFFF | (v15 << 9);
  v21 = *((volatile uint16_t *)v5 + 40) + v18;
  v22 = *v5;
  *(volatile uint32_t *)(v11 + 68) = v17 | 0x300100;
  *(volatile uint32_t *)(v11 + 20) = v8 + 12;
  v23 = *v19;
  v5[9] = v20 | 0x780000;
  *(volatile uint32_t *)(v8 + 68) = v20 | 0x780100;
  *(volatile uint32_t *)(v8 + 16) = 0;
  *(volatile uint32_t *)(v8 + 48) = 0;
  *(volatile uint32_t *)(v6 + 40) = v16;
  v5[17] = v6;
  *(volatile uint32_t *)(v6 + 324) = (int)(uintptr_t)(v5);
  *(volatile uint16_t *)(v6 + 10) = v21;
  *a2 = v22;
  if ( !*(volatile uint8_t *)(v23 + 1) )
    *(volatile uint32_t *)(v6 + 20) = *(volatile uint8_t *)(v23 + 1);
  if ( v10 )
    *(volatile uint32_t *)(*(volatile uint32_t *)(v8 + 32) - 3) = *((volatile uint32_t *)off_119880 + 43);
  *(volatile uint8_t *)(v8 + 1) = *(volatile uint8_t *)(v11 + 1) + 1;
  return 1;
}



// btm_indirect_handler @ 0x119888
int btm_indirect_handler(int a1, volatile int *a2, unsigned int a3, unsigned int a4, uint8_t a5) {
  int v5; // r5
  int v7; // r4
  int v8; // s16
  int v9; // r6
  int v10; // r11
  void *v12; // r10
  int v13; // r3
  int v14; // r0
  int v15; // r7
  unsigned int v16; // r2
  char v17; // r7
  unsigned int v18; // r11
  unsigned int v19; // r3
  unsigned int v20; // r8
  int16_t v21; // r0
  int16_t v22; // r1
  int v23; // r3
  int v24; // r12
  unsigned int v25; // lr
  int v26; // r3
  int v27; // r2
  char v28; // lr
  int v29; // r1
  int v30; // r3
  int v31; // r3
  int v32; // r7
  int v33; // r3
  int v34; // zf
  int v35; // r3
  int v36; // r3
  int v37; // r3
  char v38; // r2
  int v39; // r1
  int v40; // r3
  int v42; // r2
  int v43; // r6
  unsigned int v44; // r3
  unsigned int v45; // r7
  int v47; // [sp+8h] [bp-1Ch]
  volatile uint32_t *v48; // [sp+Ch] [bp-18h]
  char v50; // [sp+18h] [bp-Ch]
  int v51; // [sp+1Ch] [bp-8h]

  v5 = *(volatile uint32_t *)(a1 + 68);
  v51 = *(volatile uint32_t *)(v5 + 324);
  v50 = *(volatile uint8_t *)(*(volatile uint32_t *)(v51 + 76) + 1);
  v7 = *a2;
  v8 = dword_119B88 + 84 * a5 + 28;
  v9 = *(volatile uint32_t *)(*a2 + 68);
  v10 = *(volatile uint32_t *)(*a2 + 76);
  list_pop(v8);
  if ( !compare_device_state(a1, v7, a5)
    || (v12 = (void *)(uintptr_t)(off_119BA4), *(volatile uint8_t *)(*(volatile uint32_t *)off_119BA4 + 62) > (*(volatile uint32_t *)off_119B8C & 0x3Fu)) )
  {
    wlan_ioctl_handler_2(v8, (volatile uint32_t *)v5);
    return 0;
  }
  v13 = *(volatile uint32_t *)(v51 + 36);
  v14 = *(volatile uint32_t *)(v51 + 76);
  v15 = *a2;
  v48 = (void *)(uintptr_t)(off_119B8C);
  *(volatile uint32_t *)(v14 + 20) = v10 + 12;
  *(volatile uint32_t *)(v51 + 36) = v13 & 0xFFC7FFFF | 0x300000;
  v47 = 0;
  v16 = *(volatile uint32_t *)(v7 + 36) & 0xFFC7FFFF | 0x300000;
  *(volatile uint32_t *)(v14 + 68) = v13 & 0xFFC7FEFF | 0x300100;
  *(volatile uint32_t *)(v7 + 36) = v16;
  *(volatile uint32_t *)(v10 + 68) = *(volatile uint32_t *)(v15 + 36) | 0x100;
  v17 = 0;
  v18 = 0;
  while ( 1 )
  {
    v24 = *(volatile uint32_t *)(v7 + 76);
    v19 = (uint16_t)(((*(volatile uint32_t *)(v24 + 36) + 3) & 0xFFFC) + 4);
    v25 = (uint16_t)(v19 + 4 * ((v16 >> 9) & 0x3FF));
    if ( v25 < a4 )
      break;
    v19 = (uint16_t)(v19 + 4 * ((v16 >> 9) & 0x3FF));
    v20 = v25 + *(volatile uint32_t *)(v5 + 40);
    if ( v20 > a3 )
      goto LABEL_17;
LABEL_7:
    if ( *(volatile uint8_t *)(*(volatile uint32_t *)v12 + 62) > (*v48 & 0x3Fu) )
      goto LABEL_17;
    if ( *(volatile uint32_t *)(v24 + 28) )
      *(volatile uint32_t *)(*(volatile uint32_t *)(v24 + 32) - 3) = *((volatile uint32_t *)off_119B90 + 43);
    v21 = *(volatile uint16_t *)(v7 + 80);
    v22 = *(volatile uint16_t *)(v5 + 10);
    *(volatile uint32_t *)(v7 + 68) = v5;
    *(volatile uint16_t *)(v5 + 10) = v22 + v21;
    *(volatile uint16_t *)(v9 + 10) -= v21;
    if ( v25 < a4 )
    {
      v16 = *(volatile uint32_t *)(v24 + 68) & 0xFFF801FF | (v18 << 9);
      *(volatile uint32_t *)(v7 + 36) = v16;
      v19 = v25;
      *(volatile uint32_t *)(v24 + 68) = v16 | 0x100;
    }
    *(volatile uint32_t *)(v5 + 40) = v20;
    *(volatile uint32_t *)(v9 + 40) -= v19;
    if ( (v16 & 0x380000) == 0x380000 )
    {
      v37 = dword_119B88 + 84 * a5;
      v38 = *(volatile uint8_t *)(v37 + 80);
      v39 = *(volatile uint32_t *)off_119B98;
      *(volatile uint32_t *)(v5 + 324) = v7;
      *(volatile uint8_t *)(v37 + 80) = v38 - 1;
      if ( !*(volatile uint8_t *)(v39 + 1) )
        *(volatile uint32_t *)(v5 + 20) = *(volatile uint32_t *)(v9 + 20);
      *(volatile uint8_t *)(v24 + 1) = v50 + v17;
      list_pop(v8);
      wlan_ioctl_handler_1(*(volatile uint32_t *)(v9 + 340), (volatile uint32_t *)v9);
      v40 = *(volatile uint32_t *)(v7 + 76);
      *a2 = *(volatile uint32_t *)v7;
      *(volatile uint32_t *)(v40 + 20) = 0;
      v32 = 1;
      goto LABEL_34;
    }
    v23 = *(volatile uint32_t *)v7;
    if ( **(volatile int16_t **)off_119B94 < 0 && !v23 )
    {
      irq_disable_mmio_write((int)aTxdescNNull, (int)aTxlAggHeTbCatA, 1713);
      v23 = 0;
    }
    v16 = *(volatile uint32_t *)(v23 + 36);
    v47 = v7;
    ++v17;
    v7 = v23;
  }
  if ( v19 >= a4 )
  {
    v18 = 0;
  }
  else
  {
    v18 = ((unsigned int)(uint16_t)(a4 - v19) + 3) >> 2;
    v19 = (uint16_t)(v19 + 4 * v18);
  }
  v20 = v19 + *(volatile uint32_t *)(v5 + 40);
  if ( v20 <= a3 )
    goto LABEL_7;
LABEL_17:
  if ( v47 )
  {
    v26 = dword_119B88 + 84 * a5;
    v27 = *(volatile uint32_t *)(v47 + 36);
    v28 = *(volatile uint8_t *)(v26 + 80);
    v29 = *(volatile uint32_t *)(v47 + 76);
    *(volatile uint32_t *)(v5 + 324) = v47;
    v27 |= 0x380000u;
    *(volatile uint32_t *)(v47 + 36) = v27;
    *(volatile uint32_t *)(v29 + 68) = v27 | 0x100;
    *(volatile uint32_t *)(v29 + 20) = 0;
    *(volatile uint8_t *)(v26 + 80) = v28 - 1;
    *(volatile uint8_t *)(v29 + 1) = v50 + v17;
    *(volatile uint8_t *)(*(volatile uint32_t *)(*(volatile uint32_t *)(v9 + 324) + 76) + 1) -= v17;
    v30 = *(volatile uint32_t *)(v7 + 36);
    v27 = (v27 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v9 + 8)) & 0xFFFFu);
    *(volatile uint32_t *)(v9 + 268) = v7;
    *(volatile uint16_t *)(v9 + 8) = v27 | 0x400;
    if ( (v30 & 0x380000) == 0x380000 )
      list_pop(v8);
    v31 = *(volatile uint32_t *)off_119B98;
    *a2 = v7;
    v32 = *(volatile uint8_t *)(v31 + 1);
    if ( *(volatile uint8_t *)(v31 + 1) )
    {
      v32 = 0;
    }
    else
    {
      v33 = *(volatile uint32_t *)(v7 + 36) & 0x380000;
      v34 = v33 == 3670016;
      if ( v33 == 3670016 )
        v35 = *(volatile uint32_t *)(v7 + 76);
      else
        v35 = *(volatile uint32_t *)(v7 + 68);
      if ( v34 )
        v36 = v35 + 12;
      else
        v36 = v35 + 16;
      *(volatile uint32_t *)(v5 + 20) = v36;
    }
LABEL_34:
    wlan_ioctl_handler_2(v8, (volatile uint32_t *)v5);
    return v32;
  }
  v42 = *(volatile uint32_t *)(v51 + 36);
  v43 = *(volatile uint32_t *)(v51 + 76);
  *(volatile uint32_t *)(v43 + 20) = 0;
  *(volatile uint32_t *)(v51 + 36) = v42 | 0x380000;
  v44 = *(volatile uint32_t *)(v7 + 36) & 0xFFC7FFFF | 0x280000;
  v45 = *(volatile uint32_t *)(v7 + 36) & 0xFFC7FEFF | 0x280100;
  *(volatile uint32_t *)(v43 + 68) = v42 | 0x380100;
  *(volatile uint32_t *)(v7 + 36) = v44;
  *(volatile uint32_t *)(v24 + 68) = v45;
  wlan_ioctl_handler_2(v8, (volatile uint32_t *)v5);
  v32 = 0;
  *a2 = v7;
  return v32;
}


// align_alloc_size @ 0x119bec
unsigned int align_alloc_size(int a1, unsigned int a2) {
  unsigned int v2; // r3

  v2 = (uint16_t)(((*(volatile uint16_t *)(a1 + 24) + 3) & 0xFFFC) + 4);
  if ( a2 <= v2 )
    return 0;
  else
    return ((unsigned int)(uint16_t)(a2 - v2) + 3) >> 2;
}



// compare_global_counters @ 0x119c0c
int compare_global_counters() {
  volatile int *v0; // r3
  uint64_t v1; // kr00_8
  uint64_t v2; // kr08_8
  volatile int **v3; // r5
  volatile int *v4; // r7
  int v5; // r8
  int v6; // r6
  volatile int **v7; // r9
  volatile int *v8; // t1
  int result; // r0
  int v10; // t1
  int v11; // r11
  int v12; // r10
  volatile int *v13; // r4
  int v14; // r0
  int v15; // r3

  v0 = (void *)(uintptr_t)(off_119D18);
if ( *(volatile uint32_t *)(uintptr_t)(off_119D18) != *(volatile uint32_t *)off_119D14 ) { v1 = *(volatile uint64_t *)((volatile char *)off_119D14 + 4);
    v2 = *(volatile uint64_t *)((volatile char *)off_119D14 + 12);
    *(volatile uint32_t *)(uintptr_t)(off_119D18) = *(volatile uint32_t *)off_119D14;
    v0[1] = v1;
    v0[2] = HIDWORD(v1);
    v0[3] = v2;
    v0[4] = HIDWORD(v2);
  }
  v3 = (volatile int **)off_119D18;
  v4 = (void *)(uintptr_t)(off_119D20);
  v5 = dword_119D30;
  v6 = dword_119D1C;
  memset((volatile int *)dword_119D1C, 0, 0x30u);
  v7 = v3 + 6;
  do
  {
    v8 = *v3++;
    result = (int)memset(v8, 0, 360 * *v4);
    v10 = *v4++;
    if ( v10 > 0 )
    {
      v11 = 0;
      v12 = 0;
      do
      {
        v13 = &(*(v3 - 1))[v11];
        v13[18] = dword_119D24;
        v13[43] = dword_119D28;
        *((volatile uint8_t *)v13 + 155) = 5;
        v13[30] = (int)(v13 + 43);
        v13[25] = (int)(v13 + 38);
        v13[26] = (int)v13 + 175;
        v13[27] = 24;
        v13[34] = 1536;
        v13[35] = 323;
        v13[14] = 0;
        v13[15] = 0;
        v13[23] = 0;
        v13[24] = 0;
        v13[31] = 0;
        v13[32] = 0;
        *((volatile uint8_t *)v13 + 152) = -124;
        *((volatile uint8_t *)v13 + 153) = 0;
        *((volatile uint8_t *)v13 + 154) = 0;
        v13[11] = 0;
        v13[16] = 0;
        v13[28] = 0;
        v13[33] = 0;
        v13[29] = 0;
        v13[85] = v6;
        v13[4] = v5;
        v13[21] = v5;
        v13[44] = get_rf_field_mid() << 14;
        v14 = get_clock_prescaler();
        v15 = dword_119D2C;
        v13[45] = v14;
        v13[46] = 0;
        v13[47] = v15;
        result = wlan_ioctl_handler_1(v6, (void *)(v13));
        ++v12;
        v11 += 90;
      }
      while ( v12 < *(v4 - 1) );
    }
    v6 += 8;
  }
  while ( v3 != v7 );
  return result;
}


// init_mac_global_0x1882c8 @ 0x119d34
volatile uint32_t *init_mac_global_0x1882c8() {
  volatile uint32_t *v0; // r4
  volatile int *v1; // r7
  volatile int *v2; // r6
  int v3; // r9
  volatile uint32_t *result; // r0
  int v5; // t1
  int v6; // r5
  int v7; // r8

  v0 = (volatile uint32_t *)dword_119D7C;
  v1 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_119D80)[0]);
  v2 = (void *)(uintptr_t)(off_119D84);
  v3 = dword_119D7C + 48;
  do
  {
    result = clear_stats_buf(v0);
    v5 = *v1++;
    if ( v5 > 0 )
    {
      v6 = 0;
      v7 = 0;
      do
      {
        result = (volatile uint32_t *)wlan_ioctl_handler_1((int)v0, (volatile uint32_t *)(*v2 + v6));
        ++v7;
        v6 += 360;
      }
      while ( v7 < *(v1 - 1) );
    }
    v0 += 2;
    ++v2;
  }
  while ( v0 != (volatile uint32_t *)v3 );
  return result;
}


// btm_get_conn_entry @ 0x119d88
int btm_get_conn_entry(int a1) {
  int v1; // r8
  int v2; // r3
  int v3; // r5
  int v4; // r6
  uint64_t v5; // kr00_8
  int v7; // r10
  int16_t v8; // r3
  volatile int *v9; // r2
  int v11; // r4
  char v12; // r3
  int v13; // r0
  void *v14; // r11
  int16_t v15; // r2
  int v16; // r7
  unsigned int v17; // r0
  volatile int *v18; // r3
  int v19; // r7
  int v20; // [sp+Ch] [bp-8h]

  v1 = dword_119F48;
  v2 = dword_119F48 + 84 * a1;
  v3 = *(volatile uint32_t *)(v2 + 52);
  v4 = *(volatile uint32_t *)(v2 + 44);
  v5 = *(volatile uint64_t *)(v3 + 72);
  v7 = HIDWORD(v5) + 12;
  if ( *(volatile uint8_t *)(v2 + 77) == 1 )
  {
    *(volatile uint32_t *)(v3 + 36) = 0;
    *(volatile uint32_t *)(HIDWORD(v5) + 20) = 0;
    *(volatile uint32_t *)(HIDWORD(v5) + 68) = 256;
    *(volatile uint32_t *)(v3 + 68) = 0;
    if ( (uint32_t)v5 )
      ((int (*)())tx_pending_check)(v3);
    v8 = *(volatile uint16_t *)(v4 + 8);
    if ( (v8 & 2) != 0 )
    {
      v9 = (volatile int *)off_119F40;
      *(volatile uint16_t *)(v3 + 82) |= 2u;
      if ( *((volatile uint8_t *)v9 + 197) )
      {
        v19 = *(volatile uint32_t *)(HIDWORD(v5) + 48);
        if ( v19 )
          *(volatile uint8_t *)(v19 + 36) = bt_packet_parser(
                                   (*(volatile uint32_t *)(v19 + 20) >> 11) & 7,
                                   *(volatile uint32_t *)(v19 + 20) & 0x7F,
                                   (volatile uint8_t *)(*(volatile uint32_t *)(dword_119F44
                                                                 + 1320 * *(volatile uint8_t *)(v3 + 28)
                                                                 + 72)
                                                     + 4));
      }
      phy_set_cfg(v7, v7, a1);
    }
    else if ( (v8 & 4) != 0 )
    {
      *(volatile uint16_t *)(v3 + 82) |= 2u;
    }
    else if ( (uint32_t)v5 )
    {
      *(volatile uint16_t *)(v3 + 82) |= 2u;
      ll_event_lookup(a1, v5);
    }
    wlan_ioctl_handler_1(*(volatile uint32_t *)(v4 + 340), (volatile uint32_t *)v4);
  }
  else
  {
    v13 = *(volatile uint32_t *)(v2 + 48);
    v20 = v2;
    *(volatile uint32_t *)(v3 + 36) |= 0x380000u;
    *(volatile uint32_t *)(v4 + 324) = v3;
    sta_rate_limit_check((void *)(uintptr_t)(v13));
    v14 = (void *)(uintptr_t)(off_119F4C);
    *(volatile uint8_t *)(HIDWORD(v5) + 1) = *(volatile uint8_t *)(v20 + 77);
    if ( *(volatile uint8_t *)(*(volatile uint32_t *)v14 + 1) )
    {
      btm_acl_update(
        v4,
        *(volatile uint16_t *)(v3 + 34),
        *(volatile uint8_t *)(v4 + 12),
        *(volatile uint8_t *)(v4 + 13),
        *(volatile uint8_t *)(v20 + 78));
      *(volatile uint32_t *)(HIDWORD(v5) + 20) = v4 + 84;
    }
    else
    {
      *(volatile uint32_t *)(v4 + 20) = *(volatile uint8_t *)(*(volatile uint32_t *)v14 + 1);
    }
    v15 = *(volatile uint16_t *)(v4 + 8);
    *(volatile uint32_t *)(HIDWORD(v5) + 68) = *(volatile uint32_t *)(v3 + 36) | 0x100;
    *(volatile uint16_t *)(v4 + 8) = v15 | 1;
    if ( (v15 & 2) != 0 )
    {
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)v14 + 1) )
        v7 = v4 + 84;
      v16 = *(volatile uint32_t *)(v4 + 52);
      v17 = *(volatile uint32_t *)(v4 + 4);
      v18 = (volatile int *)off_119F40;
      *(volatile uint32_t *)(v16 + 20) = v17;
      if ( *((volatile uint8_t *)v18 + 197) && v16 )
        *(volatile uint8_t *)(v16 + 36) = bt_packet_parser(
                                 (v17 >> 11) & 7,
                                 v17 & 0x7F,
                                 (volatile uint8_t *)(*(volatile uint32_t *)(dword_119F44 + 1320 * *(volatile uint8_t *)(v3 + 28) + 72)
                                                   + 4));
      phy_set_cfg(v4 + 16, v7, a1);
    }
    else if ( (uint32_t)v5 && (v15 & 4) == 0 )
    {
      *(volatile uint16_t *)(v4 + 8) = v15 | 5;
      ll_event_lookup(a1, v5);
    }
    wlan_ioctl_handler_1(v1 + 84 * a1 + 28, (volatile uint32_t *)v4);
  }
  v11 = v1 + 84 * a1;
  v12 = *(volatile uint8_t *)(v11 + 80);
  *(volatile uint32_t *)(v11 + 44) = 0;
  *(volatile uint8_t *)(v11 + 80) = v12 + 1;
  return 84;
}


// btm_init_conn_entry @ 0x119f50
int btm_init_conn_entry(int a1, int a2) {
  int v2; // r7
  int v3; // r8
  int v4; // r5
  int v5; // r2
  int v8; // r9
  int v9; // r3
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v12; // lr
  unsigned int v13; // r12
  unsigned int v14; // r10
  unsigned int v15; // r0
  unsigned int v16; // r11
  unsigned int v17; // r1
  int v18; // r0
  int v19; // r7
  unsigned int v20; // r5
  char v21; // r0
  unsigned int v22; // r3
  unsigned int v23; // r0
  int v25; // r0
  int v26; // r10
  volatile uint32_t *v27; // r5
  unsigned int v28; // r2
  unsigned int v29; // r0
  int v30; // r2
  int v31; // r1
  unsigned int v32; // r1
  int v33; // r3
  unsigned int v34; // r0
  int v35; // r6
  unsigned int v36; // r3
  int v37; // r12
  int v38; // r0
  int v39; // r3
  int v40; // [sp+0h] [bp-1Ch]
  int v41; // [sp+4h] [bp-18h]
  char v42; // [sp+8h] [bp-14h]
  char v43; // [sp+Ch] [bp-10h]
  int v44; // [sp+10h] [bp-Ch]
  int v45; // [sp+14h] [bp-8h]

  v2 = dword_11A188;
  v3 = *(volatile uint32_t *)(a1 + 76);
  v4 = dword_11A188 + 84 * a2;
  v5 = *(volatile uint32_t *)(v4 + 44);
  v42 = *(volatile uint8_t *)(a1 + 27);
  v43 = *(volatile uint8_t *)(a1 + 29);
  v8 = v3 + 12;
  if ( v5 )
  {
    while ( 1 )
    {
      v9 = *(volatile uint32_t *)(a1 + 36);
      if ( (v9 & 0x200000) != 0
        && (v9 & 0x380000) != 0x280000
        && *(volatile uint8_t *)(v5 + 12) == *(volatile uint8_t *)(a1 + 29)
        && *(volatile uint8_t *)(v5 + 13) == *(volatile uint8_t *)(a1 + 27) )
      {
        v10 = *(volatile uint16_t *)(v4 + 72);
        v11 = (uint16_t)(((*(volatile uint32_t *)(v3 + 36) + 3) & 0xFFFC) + 4);
        if ( v10 > v11 )
        {
          v37 = (uint16_t)(v10 - v11) + 3;
          v45 = v37 >> 2;
          v13 = (unsigned int)v37 >> 2;
          v12 = 4 * v45;
        }
        else
        {
          v12 = 0;
          v45 = 0;
          v13 = (v13 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
        }
        v41 = *(volatile uint32_t *)(v5 + 40);
        v40 = *(volatile uint32_t *)(v4 + 52);
        v14 = *(volatile uint8_t *)(v4 + 79);
        v15 = 21 * a2 + v14;
        v44 = *(volatile uint32_t *)(v40 + 76);
        v16 = *(volatile uint32_t *)(v2 + 4 * v15 + 56);
        *(volatile uint16_t *)(v4 + 74) = v13;
        v17 = v41 + v12 + v11;
        if ( v17 <= v16 )
          goto LABEL_15;
        if ( *(volatile uint8_t *)(v4 + 78) > v14 && *(volatile uint8_t *)(v4 + 77) != 1 && v17 <= *(volatile uint32_t *)(v2 + 4 * v15 + 60) )
          break;
      }
      btm_get_conn_entry(a2);
      v5 = *(volatile uint32_t *)(v4 + 44);
      if ( !v5 )
        goto LABEL_17;
    }
    v18 = v5 + 4 * v14;
    *(volatile uint32_t *)(v18 + 328) = v40;
    *(volatile uint32_t *)(v18 + 56) = v41;
    *(volatile uint8_t *)(v4 + 79) = v14 + 1;
LABEL_15:
    v19 = v2 + 84 * a2;
    v20 = *(volatile uint8_t *)(v19 + 76);
    v21 = *(volatile uint8_t *)(v19 + 77);
    *(volatile uint32_t *)(a1 + 68) = v5;
    v22 = (v9 | (v45 << 9)) & 0xFF87FFFF | 0x700000;
    *(volatile uint32_t *)(a1 + 36) = v22;
    v23 = (uint8_t)(v21 + 1);
    *(volatile uint32_t *)(v3 + 68) = v22;
    *(volatile uint32_t *)(v44 + 20) = v8;
    *(volatile uint32_t *)(v5 + 40) = v17;
    *(volatile uint32_t *)(v19 + 52) = a1;
    *(volatile uint8_t *)(v19 + 77) = v23;
    if ( v20 <= v23 )
      btm_get_conn_entry(a2);
  }
  else
  {
LABEL_17:
    if ( (*(volatile uint32_t *)(a1 + 36) & 0x200000) != 0 && ((*(volatile uint32_t *)(a1 + 40) >> 11) & 6) != 0 )
    {
      v25 = (int)(uintptr_t)(list_pop(dword_11A18C + 8 * a2));
      v26 = v2 + 84 * a2;
      v27 = (volatile uint32_t *)v25;
      *(volatile uint32_t *)(v26 + 44) = v25;
      if ( v25 )
      {
        *(volatile uint8_t *)(v25 + 12) = v43;
        *(volatile uint8_t *)(v25 + 13) = v42;
        *(volatile uint8_t *)(v25 + 14) = 1;
        v28 = *(volatile uint32_t *)(a1 + 40);
        *(volatile uint32_t *)(v25 + 268) = a1;
        *(volatile uint64_t *)(v25 + 4) = v28;
        *(volatile uint32_t *)(v25 + 264) = 0;
        *(volatile uint8_t *)(v25 + 344) = *(volatile uint8_t *)(a1 + 54);
        ecc_point_mul(v25, a2, v2 + 84 * a2 + 44);
        v29 = *(volatile uint16_t *)(v26 + 72);
        v30 = (uint16_t)(((*(volatile uint32_t *)(v3 + 36) + 3) & 0xFFFC) + 4);
        v27[10] = v30;
        v31 = *(volatile uint32_t *)(v3 + 36);
        v27[6] = v8;
        v32 = (uint16_t)(((v31 + 3) & 0xFFFC) + 4);
        v33 = 0;
        v27[14] = 0;
        v27[15] = 0;
        v27[19] = 0;
        v27[7] = 0;
        v27[16] = 0;
        *(volatile uint8_t *)(v26 + 77) = 1;
        if ( v29 > v32 )
        {
          v38 = (uint16_t)(v29 - v32) + 3;
          v39 = v38 >> 2;
          v30 += 4 * (v38 >> 2);
          v34 = (unsigned int)v38 >> 2;
          v33 = v39 << 9;
        }
        else
        {
          v34 = (v34 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
        }
        v35 = v2 + 84 * a2;
        v36 = (v33 | *(volatile uint32_t *)(a1 + 36)) & 0xFF87FFFF | 0x680000;
        *(volatile uint16_t *)(v35 + 74) = v34;
        v27[10] = v30;
        *(volatile uint32_t *)(v35 + 48) = a1;
        *(volatile uint32_t *)(v35 + 52) = a1;
        *(volatile uint32_t *)(a1 + 36) = v36;
        *(volatile uint32_t *)(a1 + 68) = (int)(uintptr_t)(v27);
        *(volatile uint32_t *)(v3 + 68) = v36;
      }
      else
      {
        *(volatile uint32_t *)(a1 + 36) = 0;
        ++*(volatile uint8_t *)(v26 + 80);
      }
    }
    else
    {
      ++*(volatile uint8_t *)(v2 + 84 * a2 + 80);
    }
  }
  return 0;
}



// decrement_refcount @ 0x11a190
int decrement_refcount(int result) {
  char v1; // r3

  v1 = *(volatile uint8_t *)(result + 14) - 1;
  *(volatile uint8_t *)(result + 14) = v1;
  if ( !v1 )
    return wlan_ioctl_handler_1(*(volatile uint32_t *)(result + 340), (volatile uint32_t *)result);
  return result;
}


