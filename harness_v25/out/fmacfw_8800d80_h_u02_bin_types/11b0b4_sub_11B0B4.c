// sub_11B0B4 @ 0x11b0b4, size 68 bytes
BOOL  sub_11B0B4(BOOL result)
{
  int v1; // r3
  uint32_t *v2; // r2
  int v3; // r4

  v1 = *(unsigned __int8 *)(result + 37);
  if ( *(uint8_t *)(result + 37) )
  {
    v3 = result;
    sub_124BFC(off_11B0F8, *((uint32_t *)off_11B0FC + 4) + 5000);
    return sub_118F74(*(unsigned __int8 *)(v3 + 35), 0, 2500, 37, 5u, 2u, 0, 0);
  }
  else
  {
    v2 = off_11B0F8;
    *((uint32_t *)off_11B0F8 + 1) = v1;
    v2[2] = v1;
  }
  return result;
}

