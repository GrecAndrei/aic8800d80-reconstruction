// crypto_rate_ctrl @ 0x1063f4, size 188 bytes
// Doc: crypto_rate_ctrl [ke]: Configures crypto/encryption rate control parameters
// crypto_rate_ctrl [ke]: Configures crypto/encryption rate control parameters
int  crypto_rate_ctrl(int a1, int a2, int a3, int a4, int a5)
{
  int v9; // r4
  unsigned int v10; // r4
  int v11; // r8
  int v12; // r1

  if ( *(uint32_t *)(a4 + 132) <= a2 )
  {
    rf_bus_write_n_3dc(*(float *)(a4 + 4 * a2 + 148), (unsigned __int8)a1, a4);
    v9 = *(unsigned __int8 *)(a4 + 104);
  }
  else
  {
    v9 = (unsigned __int8)a1;
  }
  v10 = v9 | a1 & 0xFFFFF000 | (a2 << 8);
  if ( a3 )
  {
    if ( a2 == 7 )
    {
      v11 = 83886080;
      goto LABEL_8;
    }
    goto LABEL_11;
  }
  if ( a2 != 4 )
  {
    if ( a2 == 7 )
      goto LABEL_6;
LABEL_11:
    if ( (unsigned int)(a2 - 4) > 0xB )
      goto LABEL_9;
    if ( a2 > 6 )
    {
      if ( a3 )
      {
        v11 = (15 - a2) << 24;
        goto LABEL_8;
      }
    }
    else if ( a3 )
    {
      goto LABEL_14;
    }
    a3 = 15 - a2;
    goto LABEL_6;
  }
  a3 = 1;
LABEL_6:
  if ( (a5 & 0xFFFFFFFD) == 0 )
  {
LABEL_14:
    v10 |= 0xC08000u;
    feature_guard_check(1, dword_1064B8);
    goto LABEL_9;
  }
  v11 = a3 << 24;
LABEL_8:
  v10 = v10 & 0xFF3F7FFF | v11;
LABEL_9:
  v12 = dword_1064B4;
  *(uint32_t *)off_1064B0 = v10;
  return feature_guard_check(1, v12);
}

