// rf_init_handler @ 0x1156a0, size 154 bytes
// Doc: rf_init_handler [rf]: RF initialization handler
// rf_init_handler [rf]: RF initialization handler
int * rf_init_handler(int a1, int a2, int a3, int a4)
{
  bool v4; // zf
  int *v6; // r5
  int v7; // r2
  int v8; // r3
  void *v11; // r8
  int *result; // r0

  v4 = a3 == 5;
  if ( a3 != 5 )
    a4 = 7 * a3;
  if ( a3 == 5 )
    v6 = (int *)dword_115744;
  else
    v6 = (int *)dword_115740;
  v7 = **(__int16 **)off_11573C;
  if ( !v4 )
    v6 += a4;
  v8 = *v6;
  if ( v7 < 0 && v8 == a1 )
    return (int *)sub_121960(dword_11574C, dword_115748, 1972, v8);
  if ( v8 )
  {
    v11 = off_115750;
    if ( *(uint8_t *)(*(uint32_t *)off_115750 + 1) || !v6[2] )
      *(uint32_t *)(v8 + 4) = a1;
    else
      *(uint32_t *)(v6[1] + 4) = a1;
    result = (int *)rf_subcmd_dispatch(a3);
  }
  else
  {
    result = sub_1153F4(a1, a3, v7, 0);
    v11 = off_115750;
  }
  if ( !*(uint8_t *)(*(uint32_t *)v11 + 1) )
  {
    if ( (*(uint32_t *)(a2 + 56) & 0x200000) != 0 )
    {
      v6[1] = a1;
      v6[2] = 1;
    }
    else
    {
      v6[1] = 0;
      v6[2] = 0;
    }
  }
  *(uint32_t *)(dword_115740 + 28 * a3) = a2;
  return result;
}

