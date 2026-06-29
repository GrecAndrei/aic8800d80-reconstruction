// fmac_init_n_be4 @ 0x133be4, size 66 bytes
// Doc: fmac_init_n_be4 [mac]: Initializes FMAC subsystem with 0x100 size and dispatches event
// fmac_init_n_be4 [mac]: Initializes FMAC subsystem with 0x100 size and dispatches event
int  fmac_init_n_be4(int a1, unsigned __int8 *a2)
{
  int v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r4

  v2 = *a2;
  feature_guard_check(256, dword_133C28);
  result = msg_get_value(6u);
  if ( result )
    return 2;
  v4 = dword_133C2C + 1320 * v2;
  v5 = *(unsigned __int8 *)(v4 + 106);
  if ( !*(uint8_t *)(v4 + 106) )
  {
    result = *(unsigned __int8 *)(v4 + 108);
    if ( *(uint8_t *)(v4 + 108) )
    {
      fmac_msg_alloc_and_send(v4, 1, *(unsigned __int8 *)(v4 + 106));
      return v5;
    }
  }
  return result;
}

