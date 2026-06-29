// sub_123BBC @ 0x123bbc, size 750 bytes
int sub_123BBC()
{
  int *v0; // r4
  int v1; // r11
  int v2; // r0
  int v3; // r0
  uint32_t *v4; // r5
  uint32_t *v5; // r6
  unsigned int v6; // r3
  int v7; // r4
  unsigned int v8; // r0
  unsigned int v9; // r1
  int v10; // r3
  uint32_t *v11; // r0
  int v12; // r2
  unsigned __int8 *v13; // r3
  unsigned int v15; // r3
  unsigned int v16; // r8
  unsigned int v17; // r10
  int v18; // r1
  unsigned int v19; // r12
  unsigned int v20; // lr
  int v21; // r7
  int v22; // r2
  int v23; // r8
  int v24; // r0
  unsigned int v25; // r1
  int v26; // r2
  char v27; // r9
  signed int v28; // r4
  int v29; // r9
  int v30; // r2
  uint32_t *v31; // r8
  int v32; // r1
  int v33; // r2
  int v34; // r4
  signed int v35; // r3
  unsigned int v36; // r0
  int v37; // [sp+Ch] [bp-10h]
  uint64_t v38; // [sp+10h] [bp-Ch] BYREF

  v0 = (int *)off_123EAC;
  if ( *(uint32_t *)off_123EAC <= 0x17u )
    *(uint32_t *)off_123EAC = 1000;
  sub_1019EC(&v38, 0);
  v1 = (unsigned __int8)v38;
  v2 = (unsigned __int8)v38;
  if ( (uint8_t)v38 )
    v2 = 1;
  v3 = sub_116580(v2, *v0);
  v4 = (uint32_t *)v3;
  if ( v3 )
  {
    v5 = *(uint32_t **)(v3 + 28);
    v6 = v5[20];
    v7 = *(uint32_t *)off_123EB4;
    v8 = *(uint32_t *)off_123EB0;
    v5[16] = *(uint32_t *)off_123EB0;
    v9 = v6 >> 19 << 19;
    v5[20] = v9;
    if ( v7 )
    {
      v10 = *(uint32_t *)off_123EB8;
      v11 = v5;
LABEL_8:
      v12 = *(uint32_t *)off_123EC0;
      v5[12] = *(uint32_t *)off_123EBC;
      v5[20] = v10 | v9;
      v5[13] = v12;
      sub_123A20((int)(v11 + 26));
      v13 = (unsigned __int8 *)off_123EC4;
      v4[11] = 0;
      v4[12] = 0;
      sub_1165B0((int)v4, *v13);
      return 0;
    }
    v15 = v8 & 0x7F;
    v16 = *((unsigned __int16 *)off_123EC8 + 20);
    v17 = (v8 >> 11) & 7;
    if ( v1 )
    {
      v18 = (v8 >> 11) & 6;
      if ( v18 )
      {
        if ( v17 >= 5 )
          v18 = 2;
        else
          v18 = 1;
        v19 = 4;
        v20 = 7;
      }
      else
      {
        v19 = 7;
        v20 = 11;
      }
      v21 = *(char *)(dword_123ECC + 12 * v18 + v15);
      if ( v15 <= v19 )
      {
        v37 = 0;
      }
      else
      {
        if ( v20 < v15 )
          v22 = 1;
        else
          v22 = 2;
        if ( v20 < v15 )
          v7 = 6;
        else
          v7 = 12;
        v37 = v22;
      }
      if ( v16 > 0x1666 )
      {
        v23 = 5;
      }
      else if ( v16 > 0x1616 )
      {
        v23 = 4;
      }
      else if ( v16 > 0x15C6 )
      {
        v23 = 3;
      }
      else if ( v16 > 0x1571 )
      {
        v23 = 2;
      }
      else
      {
        v23 = v16 > 0x1486;
      }
      v27 = *(uint8_t *)(v7 + *(uint32_t *)off_123EF8 + v23)
          + *((uint8_t *)off_123F00 + 1)
          + *(uint8_t *)(dword_123ED8 + v37 + 11);
      v28 = v27;
      if ( *((uint8_t *)off_123EDC + 396) )
        v21 = (char)(v21 + *(uint8_t *)(*(uint32_t *)off_123EFC + v23));
LABEL_45:
      if ( *(char *)off_123EE4 > 0 )
      {
        sub_11F504(dword_123EF0, v1, v17);
        v29 = v27 & 1;
        if ( v29 )
          v35 = v28 - 1 + ((unsigned int)(v28 - 1) >> 31);
        else
          v35 = v28 + ((unsigned int)v28 >> 31);
        sub_11F504(dword_123EF4, v21, v37, v23, v28, (v35 >> 1) + v21);
        --*(uint8_t *)off_123EE4;
        v30 = 1;
      }
      else
      {
        v29 = v27 & 1;
        v30 = 0;
      }
      if ( v17 > 4 )
      {
        v31 = off_123EB8;
        if ( (v5[16] & 0x600) == 0x400 )
          *(uint32_t *)off_123EB8 = *(uint32_t *)off_123EB8 & 0xFFFCFFFF | 0x20000;
      }
      else
      {
        v31 = off_123EB8;
      }
      v32 = *(char *)off_123EE8;
      if ( v32 < v21 )
      {
        v21 = *(char *)off_123EE8;
        if ( v30 )
        {
          if ( v29 )
            v33 = (v28 - 1) / 2;
          else
            v33 = v28 / 2;
          sub_11F504(dword_123EEC, v32, v33 + v32);
        }
      }
      if ( v29 )
        v34 = (v28 - 1) / 2;
      else
        v34 = v28 / 2;
      v9 = v5[20];
      v11 = (uint32_t *)v4[7];
      v10 = *v31 & 0x70000 | (v21 + v34) | ((v21 + v34) << 8);
      goto LABEL_8;
    }
    if ( ((v8 >> 11) & 6) != 0 )
    {
      v36 = dword_123ED0 + v15;
      if ( v17 <= 4 )
        v21 = *(char *)(v36 + 12);
      else
        v21 = *(char *)(v36 + 24);
      v25 = 2;
    }
    else
    {
      v24 = v8 & 0x7C | v17;
      if ( !v24 )
      {
        v37 = 0;
        v21 = *(char *)(dword_123ED0 + v15);
        goto LABEL_39;
      }
      v21 = *(char *)(dword_123ED0 + v15);
      v25 = 9;
    }
    if ( v15 > v25 )
      v26 = 1;
    else
      v26 = 2;
    if ( v15 > v25 )
      v24 = 3;
    else
      v24 = 6;
    v37 = v26;
LABEL_39:
    if ( v16 <= 0x97B )
    {
      v23 = 0;
    }
    else if ( v16 > 0x994 )
    {
      v23 = 2;
    }
    else
    {
      v23 = 1;
    }
    v27 = *(uint8_t *)(*(uint32_t *)off_123ED4 + v23 + v24) + *(uint8_t *)off_123F00 + *(uint8_t *)(dword_123ED8 + v37 + 8);
    v28 = v27;
    if ( *((uint8_t *)off_123EDC + 396) )
      v21 = (char)(v21 + *(uint8_t *)(*(uint32_t *)off_123EE0 + v23));
    goto LABEL_45;
  }
  return 1;
}

