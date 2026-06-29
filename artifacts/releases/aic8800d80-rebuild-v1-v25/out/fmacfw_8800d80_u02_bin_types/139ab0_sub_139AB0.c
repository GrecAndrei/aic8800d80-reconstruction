// sub_139AB0 @ 0x139ab0, size 550 bytes
// Doc: sub_1239AB0 [rx]: RX descriptor/MSDU processing handler in fmac
// sub_1239AB0 [rx]: RX descriptor/MSDU processing handler in fmac
int  sub_139AB0(int a1, int a2)
{
  int v2; // r7
  __int16 *v3; // r9
  int v4; // r6
  uint8_t *v7; // r8
  int v8; // r0
  int v10; // r10
  __int16 v11; // r0
  int v12; // r9
  int v13; // r11
  char v14; // r5
  __int16 v15; // r3^2
  unsigned __int16 *v16; // r0
  int *v17; // r3
  char v18; // r3
  int v19; // [sp+10h] [bp-24h]
  __int16 v20; // [sp+16h] [bp-1Eh]
  unsigned int v21; // [sp+1Ch] [bp-18h]
  unsigned __int8 v22; // [sp+24h] [bp-10h] BYREF
  char v23; // [sp+25h] [bp-Fh] BYREF
  __int16 v24; // [sp+26h] [bp-Eh] BYREF
  uint64_t v25; // [sp+28h] [bp-Ch] BYREF

  v2 = *(uint32_t *)(a1 + 28);
  v3 = *(__int16 **)(v2 + 8);
  v22 = 1;
  if ( (*v3 & 0x400) == 0 )
  {
    v4 = v3[11] & 0xF;
    if ( !v4 )
    {
      if ( a2 == 255 )
      {
        if ( (*(uint32_t *)(a1 + 84) & 0x600) != 0 )
        {
LABEL_31:
          v18 = -1;
        }
        else
        {
          v17 = *((int **)off_139CD8 + 2);
          if ( v17 )
          {
            while ( *((unsigned __int16 *)v17 + 50) != (unsigned __int16)v3[2]
                 || *((unsigned __int16 *)v17 + 51) != (unsigned __int16)v3[3]
                 || *((unsigned __int16 *)v17 + 52) != (unsigned __int16)v3[4] )
            {
              v17 = (int *)*v17;
              if ( !v17 )
                goto LABEL_31;
            }
            v18 = *((uint8_t *)v17 + 107);
          }
          else
          {
            v18 = -1;
          }
        }
        v7 = off_139CDC;
        *((uint8_t *)off_139CDC + 10) = v18;
      }
      else if ( *((unsigned __int8 *)off_139CD8 + 16) == 255 )
      {
        v7 = off_139CDC;
      }
      else
      {
        v7 = off_139CDC;
        if ( (v3[2] & 1) == 0 )
        {
          v16 = (unsigned __int16 *)(1320 * *((unsigned __int8 *)off_139CDC + 10) + 100 + dword_139CE8);
          if ( *v16 == (unsigned __int16)v3[2] && v16[1] == (unsigned __int16)v3[3] && v16[2] == (unsigned __int16)v3[4] )
            *((uint8_t *)off_139CDC + 10) = -1;
        }
      }
      if ( sub_13C518(off_139CDC, v3, *(unsigned __int16 *)(a1 + 48), &v22) )
      {
        v8 = v22;
      }
      else
      {
        v20 = *v3;
        v19 = (unsigned __int8)v7[8];
        v10 = *(unsigned __int16 *)(a1 + 48);
        v21 = *(uint32_t *)(v2 + 8);
        v11 = *v3;
        v23 = 0;
        v24 = 255;
        v8 = sub_139584(v11, v10, v19, a2, (uint8_t *)dword_139CE0, v21, &v24, &v23);
        if ( v24 != 255 )
        {
          v12 = sub_12C92C(10240, v24, 10, (unsigned __int16)(v10 + 12));
          get_cached_1828f8(&v25, 0);
          v13 = v10;
          if ( !v23 )
          {
            if ( **(__int16 **)off_139CE4 < 0 && v19 << 30 )
              sub_12F49C(dword_139CF0, dword_139CEC, 2608);
            v4 = v19;
            v13 = v10 - v19;
            v10 = (unsigned __int16)(v10 - v19);
          }
          *(uint16_t *)v12 = v10;
          sub_11E1D0(v2, v10, v4, v12 + 12);
          *(uint8_t *)(v12 + 8) = v7[10];
          *(uint8_t *)(v12 + 7) = a2;
          *(uint16_t *)(v12 + 2) = v20;
          v14 = *(uint8_t *)(a1 + 65);
          sub_101AEC();
          v15 = WORD1(v25);
          *(uint8_t *)(v12 + 6) = v25;
          *(uint8_t *)(v12 + 9) = v14;
          *(uint16_t *)(v12 + 4) = v15;
          sdio_buffer_prepare_n_4e8(v12);
          if ( v24 == 4 )
            sub_141730(
              v21,
              v13,
              *(uint32_t *)(a1 + 52),
              *(unsigned __int16 *)(v12 + 4),
              *(unsigned __int8 *)(v12 + 6),
              *(char *)(v12 + 9),
              *(unsigned __int8 *)(a1 + 61));
          return 0;
        }
        v22 = v8;
      }
      if ( v8 )
      {
        sub_138D18(a1, 3);
        return 1;
      }
    }
  }
  return 0;
}

