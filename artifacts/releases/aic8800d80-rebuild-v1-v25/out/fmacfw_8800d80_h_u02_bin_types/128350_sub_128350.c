// sub_128350 @ 0x128350, size 58 bytes
BOOL  sub_128350(int a1)
{
  int v1; // r3
  int v2; // r2

  v1 = *((uint32_t *)off_12838C + 10);
  if ( v1
    && (v2 = *(uint32_t *)(a1 + 72), *(unsigned __int16 *)(v1 + 4) == *(unsigned __int16 *)(v2 + 4))
    && *(unsigned __int8 *)(v1 + 13) == *(unsigned __int8 *)(v2 + 13)
    && *(unsigned __int16 *)(v1 + 6) == *(unsigned __int16 *)(v2 + 6)
    && *(unsigned __int16 *)(v1 + 8) == *(unsigned __int16 *)(v2 + 8) )
  {
    return *(unsigned __int16 *)(v1 + 10) == *(unsigned __int16 *)(v2 + 10);
  }
  else
  {
    return 0;
  }
}

