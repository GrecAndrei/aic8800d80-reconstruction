// sub_12C760 @ 0x12c760, size 60 bytes
void  sub_12C760(int a1, int a2, unsigned __int8 *a3)
{
  int v3; // r4
  int v4; // r0

  if ( *((uint8_t *)off_12C79C + 197) )
  {
    v3 = *(uint32_t *)(*(uint32_t *)(a2 + 76) + 48);
    v4 = sub_101BD4((*(uint32_t *)(v3 + 20) >> 11) & 7, *(uint32_t *)(v3 + 20) & 0x7F, a3);
    *(uint32_t *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(__int16 **)off_12C7A0 < 0 )
  {
    sub_12F694(dword_12C7A8, dword_12C7A4, 109);
  }
}

