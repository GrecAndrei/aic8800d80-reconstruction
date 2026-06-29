// sub_11DA78 @ 0x11da78, size 64 bytes
int  sub_11DA78(int result, int a2)
{
  int v2; // r4
  int v3; // r0

  if ( *((uint8_t *)off_11DAB8 + 197) )
  {
    v2 = *(uint32_t *)(*(uint32_t *)(a2 + 32) + 44);
    v3 = sub_101C70((*(uint32_t *)(v2 + 20) >> 11) & 7, *(uint32_t *)(v2 + 20) & 0x7F, *(uint32_t *)(result + 72) + 4);
    result = v3 | (v3 << 8);
    *(uint32_t *)(v2 + 36) = result;
  }
  else if ( **(__int16 **)off_11DABC < 0 )
  {
    return rf_cmd_send_n264(dword_11DAC4, dword_11DAC0, 92);
  }
  return result;
}

