// sub_1258C0 @ 0x1258c0, size 258 bytes
void sub_1258C0()
{
  int v0; // r4
  uint8_t *v1; // r6
  int v2; // r5
  uint32_t *v3; // r2
  int v4; // r7
  uint8_t *v5; // r8
  char v6; // r9
  int v7; // r10
  int status; // r0
  int v9; // r3

  v0 = *((uint32_t *)off_1259C8 + 2);
  v1 = off_1259CC;
  if ( **(__int16 **)off_1259C4 < 0 && *((uint32_t *)off_1259CC + 1) )
  {
    sub_12F46C(dword_1259D8, dword_1259D4, 1074);
    v2 = (unsigned __int8)v1[9];
    if ( v1[9] )
      goto LABEL_20;
  }
  else
  {
    v2 = *((unsigned __int8 *)off_1259CC + 9);
    if ( *((uint8_t *)off_1259CC + 9) )
    {
LABEL_20:
      v1[8] = 1;
      return;
    }
  }
  v3 = off_1259D0;
  v1[8] = v2;
  v4 = 32 * *v3;
  if ( v0 )
  {
    v5 = off_1259DC;
    v6 = v2;
    v7 = 1;
    while ( 1 )
    {
      if ( *(uint8_t *)(v0 + 106) != 2
        || !*(uint8_t *)(v0 + 226)
        || !*(uint8_t *)(v0 + 108)
        || *(unsigned __int8 *)(v0 + 225) != *(unsigned __int8 *)(v0 + 224) )
      {
        goto LABEL_6;
      }
      if ( scan_chan_lookup_n_5e8(v0) )
        ++*v5;
      if ( v7 && (unsigned int)(v4 - 50) > 0xBB6 )
      {
        sub_128490(v0);
LABEL_16:
        *v5 = v6;
        v0 = *(uint32_t *)v0;
        v7 = 0;
        v2 = 1;
        if ( !v0 )
          return;
      }
      else
      {
        if ( v2 )
          goto LABEL_16;
        v7 = sub_128490(v0);
        if ( v7 )
        {
          *(uint8_t *)(v0 + 144) = *(uint8_t *)(v0 + 107);
          *(uint8_t *)(v0 + 145) = -1;
          status = rf_param_get_status(v0 + 116, 4);
          v9 = *((uint32_t *)v1 + 1);
          if ( status )
            *((uint32_t *)v1 + 1) = ++v9;
          if ( v9 == 1 )
            sub_121C08();
          v7 = 0;
        }
        else
        {
          *v5 = 0;
        }
LABEL_6:
        v0 = *(uint32_t *)v0;
        if ( !v0 )
          return;
      }
    }
  }
}

