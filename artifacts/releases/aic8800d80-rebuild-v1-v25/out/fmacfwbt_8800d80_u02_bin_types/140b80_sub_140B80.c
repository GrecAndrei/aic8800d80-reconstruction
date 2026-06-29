// sub_140B80 @ 0x140b80, size 130 bytes
int  sub_140B80(int result, int a2)
{
  int v2; // r6
  unsigned int v3; // r4
  int v4; // r7
  int v5; // r3
  int v7; // r0
  int v8; // r4

  v2 = dword_140C04;
  v3 = *(unsigned __int8 *)(dword_140C04 + 6489);
  if ( v3 <= 3 && *(unsigned __int8 *)(dword_140C04 + 6488) <= 0x1Fu )
  {
    v4 = result;
    v5 = *(uint32_t *)(dword_140C08 + 1320 * v3 + 72);
    v7 = v5 ? *(unsigned __int8 *)(v5 + 4) : *((unsigned __int8 *)off_140C10 + 36);
    result = sub_119084(v7 != 0, 512);
    v8 = result;
    if ( result )
    {
      *(uint8_t *)(result + 28) = *(uint8_t *)(v2 + 6489);
      *(uint8_t *)(result + 29) = *(uint8_t *)(v2 + 6488);
      *(uint8_t *)(result + 51) = 0;
      *(uint8_t *)(result + 53) = 0;
      if ( !a2 )
      {
        *(uint32_t *)(result + 88) = dword_140C0C;
        *(uint32_t *)(result + 92) = result;
      }
      sub_1405DC(result, 1, a2, v4);
      return sub_1190B4(v8, 3);
    }
  }
  return result;
}

