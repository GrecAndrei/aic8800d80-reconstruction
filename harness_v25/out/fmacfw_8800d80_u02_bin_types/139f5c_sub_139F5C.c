// sub_139F5C @ 0x139f5c, size 1160 bytes
int  sub_139F5C(unsigned int a1)
{
  unsigned int v1; // r7
  int v3; // r3
  uint8_t *v4; // r4
  int v5; // r6
  unsigned __int8 *v7; // r6
  __int16 v8; // r8
  unsigned __int16 v9; // r3
  int v10; // r11
  int v11; // r9
  char v12; // r3
  __int16 v13; // r3
  int v14; // r10
  int v15; // r3
  int v16; // r1
  int v17; // r12
  int v18; // r2
  int v19; // r1
  int v20; // r0
  __int16 v21; // r1
  uint8_t **v22; // r11
  int v23; // r1
  int v24; // r3
  uint16_t *v25; // r1
  unsigned __int8 *v26; // r9
  int v27; // r0
  __int16 v28; // r3
  char v29; // r0
  int v30; // r1
  int v31; // r0
  int v32; // r7
  unsigned uint64_t v33; // r0
  int v34; // r0
  int v35; // r2
  int v36; // r1
  uint16_t *v37; // r10
  BOOL v38; // r0
  int v39; // r0
  int v40; // [sp+0h] [bp-Ch]
  uint16_t *v41; // [sp+0h] [bp-Ch]
  int v42; // [sp+0h] [bp-Ch]
  int v43; // [sp+4h] [bp-8h]
  int v44; // [sp+4h] [bp-8h]
  int v45; // [sp+4h] [bp-8h]

  v1 = *(uint32_t *)(a1 + 84);
  if ( (v1 & 0x2000) == 0 )
  {
    v3 = *((unsigned __int8 *)off_13A238 + 16);
    if ( v3 != 255 )
    {
      v4 = off_13A23C;
LABEL_4:
      v4[10] = v3;
      sub_138D18(a1, 128);
      v5 = 1;
      goto LABEL_5;
    }
LABEL_35:
    v5 = 0;
    goto LABEL_5;
  }
  v4 = off_13A23C;
  v7 = *(unsigned __int8 **)(*(uint32_t *)(a1 + 28) + 8);
  v8 = *(uint16_t *)v7;
  *(uint16_t *)off_13A23C = *(uint16_t *)v7;
  *(uint32_t *)(a1 + 96) = 0;
  v4[9] = -1;
  v4[10] = -1;
  v9 = *((uint16_t *)v7 + 11);
  *((uint16_t *)v4 + 1) = v9;
  v4[48] = 0;
  *((uint16_t *)v4 + 2) = v9 >> 4;
  v4[6] = v9 & 0xF;
  if ( (v8 & 0x88) == 0x88 )
  {
    v10 = v8 & 0x300;
    if ( v10 == 768 )
      v28 = *((uint16_t *)v7 + 15);
    else
      v28 = *((uint16_t *)v7 + 12);
    v4[7] = v28 & 7;
  }
  else
  {
    v4[7] = 0;
    v10 = v8 & 0x300;
  }
  v11 = v8 & 0xFC;
  if ( v10 == 768 )
    v12 = 30;
  else
    v12 = 24;
  if ( v11 == 136 )
    v12 += 2;
  if ( v8 < 0 )
    v12 += 4;
  v4[8] = v12;
  if ( (v7[4] & 1) != 0 )
    v4[48] = 8;
  if ( (v8 & 0x100) != 0 )
  {
    *((uint16_t *)v4 + 18) = *((uint16_t *)v7 + 8);
    *((uint16_t *)v4 + 19) = *((uint16_t *)v7 + 9);
    *((uint16_t *)v4 + 20) = *((uint16_t *)v7 + 10);
    v13 = *(uint16_t *)v7;
    if ( (*(uint16_t *)v7 & 0x200) != 0 )
    {
LABEL_19:
      if ( (v13 & 0x100) != 0 )
      {
        *((uint16_t *)v4 + 21) = *((uint16_t *)v7 + 12);
        *((uint16_t *)v4 + 22) = *((uint16_t *)v7 + 13);
        *((uint16_t *)v4 + 23) = *((uint16_t *)v7 + 14);
      }
      else
      {
        *((uint16_t *)v4 + 21) = *((uint16_t *)v7 + 8);
        *((uint16_t *)v4 + 22) = *((uint16_t *)v7 + 9);
        *((uint16_t *)v4 + 23) = *((uint16_t *)v7 + 10);
      }
      if ( (v1 & 0x2000000) != 0 )
        goto LABEL_22;
LABEL_38:
      if ( v4[115]
        && (v1 & 0x200) == 0
        && *((unsigned __int16 *)v4 + 54) == *((unsigned __int16 *)v7 + 5)
        && *((unsigned __int16 *)v4 + 55) == *((unsigned __int16 *)v7 + 6)
        && *((unsigned __int16 *)v4 + 56) == *((unsigned __int16 *)v7 + 7) )
      {
        v4[114] = (*(uint16_t *)v7 & 0x1400) == 4096;
      }
      if ( (v8 & 0xC) != 0 )
        goto LABEL_56;
      v24 = *((unsigned __int16 *)v7 + 11);
      if ( (*(uint16_t *)v7 & 0x800) != 0 )
      {
        v25 = off_13A3E4;
        v26 = v7 + 10;
        if ( *((unsigned __int16 *)v4 + 51) == v24 )
        {
          v41 = off_13A3E4;
          if ( !sub_143710(v7 + 10, off_13A3E4, 6) )
            goto LABEL_34;
          v8 = *(uint16_t *)v4;
          LOWORD(v24) = *((uint16_t *)v7 + 11);
          v25 = v41;
        }
      }
      else
      {
        v25 = off_13A248;
        v26 = v7 + 10;
      }
      v27 = *(uint32_t *)v26;
      v25[2] = *((uint16_t *)v26 + 2);
      *((uint16_t *)v4 + 51) = v24;
      *((uint32_t *)v4 + 24) = v27;
      if ( (v8 & 0x4000) != 0 && ((v1 & 0x7C) != 4 || !sub_1387E8((int)v7, v1)) )
LABEL_56:
        v5 = fmac_state_check_nbf4(v7);
      else
        v5 = sub_139AB0(a1, 255);
      goto LABEL_57;
    }
  }
  else
  {
    *((uint16_t *)v4 + 18) = *((uint16_t *)v7 + 2);
    *((uint16_t *)v4 + 19) = *((uint16_t *)v7 + 3);
    *((uint16_t *)v4 + 20) = *((uint16_t *)v7 + 4);
    v13 = *(uint16_t *)v7;
    if ( (*(uint16_t *)v7 & 0x200) != 0 )
      goto LABEL_19;
  }
  *((uint16_t *)v4 + 21) = *((uint16_t *)v7 + 5);
  *((uint16_t *)v4 + 22) = *((uint16_t *)v7 + 6);
  *((uint16_t *)v4 + 23) = *((uint16_t *)v7 + 7);
  if ( (v1 & 0x2000000) == 0 )
    goto LABEL_38;
LABEL_22:
  v14 = dword_13A250;
  v15 = (unsigned __int8)((v1 >> 15) - 16);
  v16 = dword_13A250 + 696 * v15;
  if ( !*(uint8_t *)(v16 + 37) )
    goto LABEL_34;
  v17 = *(unsigned __int8 *)(v16 + 34);
  v18 = dword_13A244;
  v19 = *(uint32_t *)(v16 + 184);
  v4[9] = v15;
  *((uint32_t *)v4 + 6) = v1;
  v20 = *(unsigned __int8 *)(v18 + 1320 * v17 + 106);
  v4[10] = v17;
  v40 = v19;
  if ( v20 != 2 || (v4[36] & 1) != 0 )
  {
    v21 = v8;
  }
  else
  {
    v29 = mmio_block_write_3reg((int *)dword_13A24C);
    v21 = *(uint16_t *)v4;
    v15 = (unsigned __int8)((v1 >> 15) - 16);
    v18 = dword_13A244;
    v4[11] = v29;
  }
  if ( v10 == 768 )
    *(uint32_t *)(a1 + 96) |= 4u;
  if ( (v21 & 0x4000) != 0 )
  {
    v43 = v15;
    v34 = sub_1387E8((int)v7, *((uint32_t *)v4 + 6));
    v15 = v43;
    v18 = dword_13A3E8;
    if ( !v34 )
      goto LABEL_34;
  }
  v22 = (uint8_t **)off_13A254;
  if ( **(uint8_t **)off_13A254 == 1 && !*((uint8_t *)off_13A3EC + 412) )
  {
    v23 = v8 & 0xC;
    if ( v23 == 8 )
    {
      if ( !*(uint8_t *)(v18 + 1320 * (unsigned __int8)v4[10] + 106) )
      {
        v45 = v15;
        v39 = sub_139D94((char *)v7, v1, v15);
        v15 = v45;
        if ( !v39 )
          goto LABEL_34;
      }
      goto LABEL_83;
    }
LABEL_30:
    if ( *(unsigned __int8 *)(v14 + 696 * v15 + 669) > 1u
      || !v40
      || (unsigned int)*(unsigned __int8 *)(v40 + 96) - 1 > 1 )
    {
      goto LABEL_31;
    }
    goto LABEL_72;
  }
  v23 = v8 & 0xC;
  if ( v23 != 8 )
    goto LABEL_30;
LABEL_83:
  v44 = v15;
  scan_ie_parse_ef8((char *)v7, v1, *(unsigned __int16 *)(a1 + 48));
  v15 = v44;
  if ( *(unsigned __int8 *)(v14 + 696 * v44 + 669) > 1u || !v40 || (unsigned int)*(unsigned __int8 *)(v40 + 96) - 1 > 1 )
    goto LABEL_84;
  v23 = 8;
LABEL_72:
  if ( (v8 & 0x4000) != 0 && (v4[36] & 1) == 0 )
    *(uint8_t *)(v14 + 696 * v15 + 669) = 2;
LABEL_31:
  if ( v23 == 4 )
  {
    if ( v11 == 132 )
      tx_power_tbl_lookup(v15, (int)v7);
    goto LABEL_34;
  }
  if ( v23 != 8 )
  {
    if ( v23 )
      goto LABEL_34;
    if ( (v8 & 0x800) != 0 )
    {
      v30 = *((unsigned __int16 *)v4 + 1);
      if ( *(unsigned __int16 *)(v14 + 696 * v15 + 552) == v30 )
        goto LABEL_34;
    }
    else
    {
      LOWORD(v30) = *((uint16_t *)v4 + 1);
    }
    v31 = (unsigned __int8)v4[48] << 30;
    *(uint16_t *)(v14 + 696 * v15 + 552) = v30;
    if ( v31 < 0 )
    {
      v32 = *((uint32_t *)v4 + 8);
      v33 = *((QWORD *)v4 + 2);
      if ( *(QWORD *)(v32 + 64) >= v33 )
      {
        msg_parse(dword_13A3F0);
        goto LABEL_34;
      }
      *(QWORD *)(v32 + 64) = v33;
    }
    if ( **v22 == 1 && *v7 == 128 && !v7[1] )
    {
LABEL_34:
      v3 = *((unsigned __int8 *)off_13A238 + 16);
      if ( v3 != 255 )
        goto LABEL_4;
      goto LABEL_35;
    }
    v5 = sub_139AB0(a1, (unsigned __int8)v4[9]);
    goto LABEL_57;
  }
LABEL_84:
  if ( (v8 & 0x40) != 0 )
    goto LABEL_34;
  if ( (v8 & 0x80) != 0 )
  {
    v35 = 1;
    if ( (v4[48] & 8) == 0 )
    {
      v42 = v15;
      v38 = sub_121960(v15, (unsigned __int8)v4[7]);
      v15 = v42;
      v35 = 1;
      if ( v38 )
      {
        v5 = sub_139340(a1, v42);
        goto LABEL_57;
      }
    }
    v37 = (uint16_t *)(v14 + 2 * ((unsigned __int8)v4[7] + 277 + 348 * v15));
  }
  else
  {
    v35 = 0;
    v37 = (uint16_t *)(v14 + 696 * v15 + 552);
  }
  v36 = *((unsigned __int16 *)v4 + 1);
  if ( (v8 & 0x800) != 0 && (unsigned __int16)*v37 == v36 )
    goto LABEL_34;
  *v37 = v36;
  v5 = sub_138FE4(a1, v15, v35);
LABEL_57:
  v3 = *((unsigned __int8 *)off_13A238 + 16);
  if ( v3 != 255 && !v5 )
    goto LABEL_4;
LABEL_5:
  sub_12F554((uint32_t **)dword_13A240);
  return v5;
}

