// sub_117538 @ 0x117538, size 80 bytes
int  sub_117538(int a1)
{
  uint32_t *v1; // r4
  int result; // r0
  unsigned int v3; // r3
  int v4; // r1
  int v5; // r2

  v1 = off_117588;
  if ( *((uint8_t *)off_117588 + 33) )
    *(uint32_t *)(*((uint32_t *)off_117588 + 6) + 4) = a1;
  else
    *((uint32_t *)off_117588 + 4) = a1;
  result = *((unsigned __int8 *)off_11758C + 193);
  v3 = v1[7] + v1[3];
  v4 = v1[5] + v1[1];
  v5 = v1[2];
  v1[5] = v4;
  v1[7] = v3;
  *((uint8_t *)v1 + 33) = 1;
  v1[6] = v5;
  if ( v3 >= result << 9 )
  {
    result = sub_110AB8(v1[4], v4, v5);
    v1[4] = 0;
    v1[5] = 0;
    v1[6] = 0;
    v1[7] = 0;
    *((uint8_t *)v1 + 33) = 0;
  }
  return result;
}

