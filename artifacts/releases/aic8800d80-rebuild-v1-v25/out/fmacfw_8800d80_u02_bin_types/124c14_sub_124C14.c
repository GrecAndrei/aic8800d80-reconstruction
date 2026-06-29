// sub_124C14 @ 0x124c14, size 140 bytes
int  sub_124C14(unsigned __int8 *a1, void *a2)
{
  int v2; // r3
  unsigned int v3; // r2

  v2 = *a1;
  v3 = v2 << 28;
  if ( v2 << 28 )
  {
    v3 = (unsigned int)off_124CA0;
    a2 = (void *)(v2 & 1);
    *(uint8_t *)off_124CA0 = v2 & 1;
  }
  if ( (v2 & 0xF0) != 0 )
  {
    v3 = (unsigned int)off_124CA4;
    *((uint8_t *)off_124CA4 + 408) = v2 & 0x10;
  }
  if ( a1[1] )
  {
    a2 = off_124CA8;
    v3 = *(uint32_t *)off_124CA8 & 0xFFFFFF00;
    *(uint32_t *)off_124CA8 = a1[1] | v3;
  }
  if ( a1[2] )
  {
    a2 = off_124CAC;
    v3 = *(uint32_t *)off_124CAC & 0xFFFFFF00;
    *(uint32_t *)off_124CAC = a1[2] | v3;
  }
  if ( a1[3] )
  {
    a2 = off_124CA8;
    v3 = *(uint32_t *)off_124CA8 & 0xFFF00FFF;
    *(uint32_t *)off_124CA8 = v3 | (a1[3] << 12);
  }
  if ( a1[4] )
  {
    a2 = off_124CAC;
    v3 = *(uint32_t *)off_124CAC & 0xFFF00FFF;
    *(uint32_t *)off_124CAC = v3 | (a1[4] << 12);
  }
  msg_parse(dword_124CB0, a2, v3);
  return rf_mem_read_eb18(a1, 5, 1, 0);
}

