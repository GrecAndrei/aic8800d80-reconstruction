// sub_1357B4 @ 0x1357b4, size 186 bytes
uint32_t * sub_1357B4(char *a1)
{
  int v2; // r8
  unsigned int v3; // r1
  int v4; // r6
  int v5; // r3
  int v6; // r1
  char *v7; // r4
  int v8; // r12
  char *v9; // r3
  char v10; // t1
  int v12; // r1

  v2 = *((uint32_t *)off_135870 + 5);
  sub_12C964(6154, 6);
  v3 = *(unsigned __int16 *)a1;
  v4 = *((unsigned __int16 *)a1 + 7);
  if ( v3 <= 5 )
  {
    v12 = dword_135878;
    *(uint16_t *)(v2 + 16) = 0;
    feature_guard_sdio(256, v12, v4);
    if ( !v4 )
      return rf_msg_process_body_n_102(*((uint16_t *)a1 + 8) & 0x3FFF);
  }
  else
  {
    v5 = *(unsigned __int16 *)(v2 + 14);
    v6 = (unsigned __int16)(v3 - 6);
    v7 = a1 + 18;
    if ( v6 + v5 > 800 )
    {
      if ( **(__int16 **)off_135874 < 0 )
      {
        sub_12F6C4(dword_135880, dword_13587C, 1236);
        v5 = *(unsigned __int16 *)(v2 + 14);
      }
      v6 = (unsigned __int16)(800 - v5);
    }
    v8 = v2 + 20 + v5;
    if ( v6 )
    {
      do
      {
        v9 = v7 - 18;
        v10 = *v7++;
        *(uint8_t *)(v9 - a1 + v8) = v10;
      }
      while ( v7 != &a1[v6 + 18] );
    }
    *(uint16_t *)(v2 + 16) = v6;
    feature_guard_sdio(256, dword_135878, v4);
    if ( !v4 )
      return rf_msg_process_body_n_102(*((uint16_t *)a1 + 8) & 0x3FFF);
  }
  return (uint32_t *)sub_135020(v4);
}

