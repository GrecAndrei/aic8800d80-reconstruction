// sub_11C350 @ 0x11c350, size 74 bytes
int  sub_11C350(int a1)
{
  uint8_t *v1; // r6
  int v2; // r7
  int v3; // r5
  int result; // r0
  uint32_t *v5; // r1
  uint32_t *v6; // r4
  unsigned int v7; // t1
  int v8; // r3

  v1 = off_11C39C;
  v2 = dword_11C3A0;
  v3 = *((uint32_t *)off_11C39C + 4);
  result = a1 - 4;
  v5 = off_11C39C;
  v6 = (uint32_t *)(v3 + 8);
  do
  {
    v7 = *(uint32_t *)(result + 4);
    result += 4;
    v8 = (v7 >> 4) & 0xFF0 | v7 & 0xF;
    v5[10] = v8;
    *((uint8_t *)v5 + 44) = BYTE2(v7);
    if ( v3 )
      v5[10] = v8 | *v6 & v2;
    ++v6;
    v5 += 7;
  }
  while ( (uint32_t *)(v3 + 24) != v6 );
  v1[160] = 1;
  return result;
}

