// rf_table_lookup @ 0x1242f0, size 476 bytes
// Doc: rf_table_lookup [rf]: Lookup RF table entry by index (<=0x80)
// rf_table_lookup [rf]: Lookup RF table entry by index (<=0x80)
int  rf_table_lookup(unsigned int a1)
{
  int v2; // r7
  int v3; // r5
  int v4; // r0
  int result; // r0
  int v6; // r6
  int v7; // r5
  int v8; // r3
  int v9; // r2
  uint8_t *v10; // r3
  char v11; // r0
  char v12; // r1
  uint8_t *v13; // r1
  __int16 v14; // r3
  __int16 v15; // r2
  uint8_t *v16; // r7
  char v17; // r0
  __int16 *v18; // r8
  unsigned int v19; // r4
  __int16 v20; // r3
  uint8_t *v21; // r2
  char v22; // r1
  unsigned int v23; // r3
  char *v24; // r0
  __int16 v25; // r2
  bool v26; // cc
  char v27; // r3
  int v28; // r0
  uint64_t v29; // [sp+0h] [bp-8h] BYREF

  if ( a1 == 128 )
  {
    v3 = 100;
    v2 = 10240;
  }
  else if ( a1 == 129 )
  {
    v3 = 500;
    v2 = 10244;
  }
  else
  {
    v2 = 10249;
    if ( a1 == 1 )
    {
      v3 = 2000;
    }
    else
    {
      v3 = 200;
      v2 = 10240;
    }
  }
  get_cached_1828f8(&v29, 0);
  v4 = (unsigned __int8)v29;
  if ( (uint8_t)v29 )
    v4 = 1;
  result = rf_alloc_or_init(v4, v3);
  v6 = result;
  if ( result )
  {
    v7 = *(uint32_t *)(result + 28);
    v8 = *(uint32_t *)off_1244D0;
    *(uint32_t *)(v7 + 48) = *(uint32_t *)off_1244CC;
    v9 = dword_1244D4;
    *(uint32_t *)(v7 + 64) = v2;
    *(uint32_t *)(v7 + 80) = v9;
    *(uint32_t *)(v7 + 52) = v8;
    if ( a1 == 128 )
    {
      sub_123AB4(v7 + 104);
      v23 = *(unsigned __int8 *)off_1244EC;
      v24 = (char *)off_1244E0;
      v25 = *(uint16_t *)off_1244DC;
      *(uint8_t *)(v7 + 128) = 0x80;
      v23 -= 2;
      v26 = v23 > 1;
      if ( v23 <= 1 )
        v22 = -106;
      v27 = *v24;
      *(uint8_t *)(v7 + 134) = v25;
      if ( v26 )
        v22 = -105;
      *(uint8_t *)(v7 + 132) = v22;
      *(uint8_t *)(v7 + 133) = v27;
      *(uint8_t *)(v7 + 135) = HIBYTE(v25);
      *(uint8_t *)(v7 + 129) = -64;
      *(uint8_t *)(v7 + 130) = -75;
      *(uint8_t *)(v7 + 131) = 122;
      *(uint8_t *)(v7 + 136) = -1;
      goto LABEL_14;
    }
    if ( a1 > 0x80 )
    {
      if ( a1 == 129 )
      {
        sub_123AB4(v7 + 104);
        v13 = off_1244D8;
        v14 = *(uint16_t *)off_1244DC;
        v15 = *(uint16_t *)off_1244D8;
        v16 = off_1244E0;
        *(uint8_t *)(v7 + 130) = *(uint16_t *)off_1244DC;
        v17 = v13[5];
        *(uint8_t *)(v7 + 128) = -127;
        LOBYTE(v13) = *v16;
        *(uint8_t *)(v7 + 131) = HIBYTE(v14);
        *(uint16_t *)(v7 + 132) = v15;
        *(uint8_t *)(v7 + 134) = v17;
        *(uint8_t *)(v7 + 129) = (uint8_t)v13;
        *(uint8_t *)(v7 + 135) = -1;
        goto LABEL_14;
      }
    }
    else
    {
      if ( a1 == 1 )
      {
        v18 = (__int16 *)off_1244DC;
        v19 = *(uint32_t *)off_1244E8 - *(uint32_t *)off_1244E4;
        if ( v19 <= 0x4E1F )
        {
          v28 = dword_1244F4;
          v19 = (1000 - *(unsigned __int16 *)off_1244DC)
              * ((*(uint32_t *)off_1244E4 - *(uint32_t *)off_1244F0)
               / (unsigned int)*(unsigned __int16 *)off_1244DC)
              + 20000;
          *(uint32_t *)off_1244E8 = *(uint32_t *)off_1244E4 + v19;
          msg_parse(v28, v19);
        }
        rf_chan_config_set(v7 + 104);
        v20 = *v18;
        v21 = off_1244E0;
        *(uint8_t *)(v7 + 130) = *v18;
        LOBYTE(v21) = *v21;
        *(uint8_t *)(v7 + 131) = HIBYTE(v20);
        *(uint8_t *)(v7 + 132) = v19;
        *(uint8_t *)(v7 + 129) = (uint8_t)v21;
        *(uint8_t *)(v7 + 128) = 1;
        *(uint8_t *)(v7 + 133) = BYTE1(v19);
        *(uint8_t *)(v7 + 134) = BYTE2(v19);
        *(uint8_t *)(v7 + 135) = HIBYTE(v19);
        *(uint8_t *)(v7 + 136) = -1;
        goto LABEL_14;
      }
      if ( a1 == 2 )
      {
        rf_chan_config_set(v7 + 104);
        v10 = off_1244D8;
        *(uint8_t *)(v7 + 128) = 2;
        v11 = v10[3];
        v12 = v10[4];
        *(uint8_t *)(v7 + 130) = v10[2];
        *(uint8_t *)(v7 + 131) = v11;
        *(uint8_t *)(v7 + 132) = v12;
        *(uint8_t *)(v7 + 129) = 1;
        *(uint8_t *)(v7 + 133) = -1;
LABEL_14:
        *(uint32_t *)(v6 + 44) = 0;
        *(uint32_t *)(v6 + 48) = 0;
        return sub_1165B0(v6, 0);
      }
    }
    rf_chan_config_set(v7 + 104);
    *(uint8_t *)(v7 + 128) = 0;
    *(uint8_t *)(v7 + 129) = -1;
    goto LABEL_14;
  }
  return result;
}

