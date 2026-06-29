// sub_12373C @ 0x12373c, size 386 bytes
int sub_12373C()
{
  char *v0; // r5
  uint8_t *v1; // r8
  int *v2; // r7
  int v3; // r1
  unsigned int v4; // r4
  int result; // r0
  char v6; // r3
  int v7; // r6
  int v8; // r0
  int v9; // r3
  int v10; // r1
  int v11; // r1
  uint16_t *v12; // r3
  int v13; // r2
  int v14; // r6
  unsigned __int8 *v15; // r0
  int v16; // r2
  int v17; // [sp+0h] [bp-20h] BYREF
  __int16 v18; // [sp+4h] [bp-1Ch]
  int v19; // [sp+8h] [bp-18h] BYREF
  __int16 v20; // [sp+Ch] [bp-14h]
  unsigned __int16 v21; // [sp+10h] [bp-10h] BYREF
  __int16 v22; // [sp+12h] [bp-Eh]
  __int16 v23; // [sp+14h] [bp-Ch]
  uint16_t v24[4]; // [sp+18h] [bp-8h] BYREF

  v0 = (char *)off_1238C0;
  v1 = off_1238DC;
  v2 = (int *)dword_1238C4;
  while ( 1 )
  {
    v4 = sub_11798C();
    result = sub_11E628(0x4000);
    if ( !v4 )
      break;
    sub_1179C8(v4);
    v6 = *(uint8_t *)(v4 + 65);
    *v0 = v6;
    v0[1] = v6;
    v7 = *(uint32_t *)(v4 + 28);
    v8 = chip_rev_id_get();
    v9 = *v0;
    if ( v8 == 1 )
      v9 = (int)((v9 + v0[1] + ((unsigned int)(v9 + v0[1]) >> 31)) << 23) >> 24;
    *v1 = v9;
    if ( is_flag_set_n645c() || !*(uint8_t *)off_1238C8 )
    {
      v10 = v2[1];
      v17 = *v2;
      v18 = v10;
      v11 = *(uint32_t *)(dword_1238CC + 4);
      v19 = *(uint32_t *)dword_1238CC;
      v20 = v11;
      sub_1282E8(&v21, &v17, 6);
      sub_1282E8(v24, &v19, 6);
      v12 = *(uint16_t **)(v7 + 8);
      v13 = (unsigned __int16)v12[2];
      if ( (*v12 & 0x80) != 0 )
        v14 = 13;
      else
        v14 = 12;
      v15 = (unsigned __int8 *)&v12[v14];
      if ( v24[0] == v13 && v24[1] == (unsigned __int16)v12[3] && v24[2] == (unsigned __int16)v12[4] )
      {
        v3 = v21;
        if ( (unsigned __int16)v12[5] == v21 && v22 == v12[6] && v23 == v12[7] )
        {
          if ( *(uint8_t *)off_1238C8 == 1 )
          {
            v16 = *(unsigned __int8 *)off_1238D0;
            switch ( v16 )
            {
              case 2:
                if ( LOBYTE(v12[v14]) == 1 && v15[1] == *(unsigned __int8 *)off_1238D8 )
                  sub_123394((int)v15);
                break;
              case 4:
                rf_chan_band_parse(v15);
                break;
              case 1:
                sub_1234E4();
                break;
            }
          }
          goto LABEL_4;
        }
      }
      else
      {
        v3 = v21;
      }
      if ( v13 == v3 && v22 == v12[3] && v23 == v12[4] && !*(uint8_t *)off_1238C8 )
      {
        if ( *(uint8_t *)off_1238D0 )
        {
          if ( *(uint8_t *)off_1238D0 == 3 && LOBYTE(v12[v14]) == 129 )
            rf_event_check_n3cc(v15);
        }
        else if ( LOBYTE(v12[v14]) == 128 )
        {
          parse_subframe_header(v15);
        }
      }
    }
LABEL_4:
    rf_table_lookup_handler(v4);
  }
  *(uint32_t *)off_1238D4 |= 0x10000u;
  return result;
}

