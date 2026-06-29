// fmac_init_or_handler @ 0x12d190, size 104 bytes
// Doc: fmac_init_or_handler [unknown]: Generic fmacfw helper (likely init/IRQ dispatch)
// fmac_init_or_handler [unknown]: Generic fmacfw helper (likely init/IRQ dispatch)
void fmac_init_or_handler()
{
  unsigned int *v0; // r6
  unsigned int v1; // r4
  __int16 **v2; // r8
  int v3; // r5
  void *v4; // r7
  int v5; // r10
  int v6; // r9
  int v7; // r4
  void ( *v8)(uint32_t); // r3

  v0 = (unsigned int *)off_12D1F8;
  v1 = *(uint32_t *)off_12D1F8;
  if ( *(uint32_t *)off_12D1F8 )
  {
    v2 = (__int16 **)off_12D204;
    v3 = dword_12D1FC;
    v4 = off_12D200;
    v5 = dword_12D208;
    v6 = dword_12D20C;
    while ( 1 )
    {
      v7 = __clz(v1);
      if ( **v2 < 0 )
      {
        if ( v7 <= 27 )
        {
          v8 = *(void ( **)(uint32_t))(v3 + 8 * v7);
          if ( v8 )
            goto LABEL_5;
        }
        sub_12F46C(v6, v5, 230);
      }
      v8 = *(void ( **)(uint32_t))(v3 + 8 * v7);
LABEL_5:
      v8(*(uint32_t *)(v3 + 8 * v7 + 4));
      v1 = *v0;
      if ( *(uint8_t *)(*(uint32_t *)v4 + 3) )
      {
        rf_flag_clear_n_90();
        if ( !v1 )
          return;
      }
      else if ( !v1 )
      {
        return;
      }
    }
  }
}

