// sub_126F08 @ 0x126f08, size 44 bytes
int sub_126F08()
{
  uint32_t *v0; // r3
  int v1; // r1
  int v2; // r2
  int result; // r0

  v0 = off_126F34;
  if ( (*((uint8_t *)off_126F34 + 88) & 8) != 0 )
  {
    v1 = dword_126F38;
    goto LABEL_6;
  }
  if ( (*((uint8_t *)off_126F34 + 88) & 4) != 0 )
  {
    v1 = dword_126F3C;
LABEL_6:
    v2 = *((uint32_t *)off_126F34 + 11);
    if ( v2 != v1 )
    {
      if ( v2 )
        *(uint8_t *)(v2 + 16) = 1;
      v0[11] = v1;
    }
    return sub_126CDC();
  }
  if ( *((uint32_t *)off_126F34 + 11) )
    return sub_126CDC();
  return result;
}

