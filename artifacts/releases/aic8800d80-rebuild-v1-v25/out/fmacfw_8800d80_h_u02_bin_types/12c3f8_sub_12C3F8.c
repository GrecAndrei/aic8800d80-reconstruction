// sub_12C3F8 @ 0x12c3f8, size 60 bytes
void  sub_12C3F8(int a1, int a2, unsigned __int8 *a3)
{
  int v3; // r4
  int v4; // r0

  if ( *((uint8_t *)off_12C434 + 197) )
  {
    v3 = *(uint32_t *)(*(uint32_t *)(a2 + 76) + 48);
    v4 = sub_101CAC((*(uint32_t *)(v3 + 20) >> 11) & 7, *(uint32_t *)(v3 + 20) & 0x7F, a3);
    *(uint32_t *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(__int16 **)off_12C438 < 0 )
  {
    sub_12F32C(dword_12C440, dword_12C43C, 109);
  }
}

