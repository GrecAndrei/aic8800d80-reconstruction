// sub_114194 @ 0x114194, size 54 bytes
int  sub_114194(int a1)
{
  __int16 v2; // r0
  char v3; // r1
  int v4; // r5

  v2 = sub_113A44(0xFu);
  v3 = v2;
  if ( !(uint8_t)v2 )
  {
    v4 = 1;
LABEL_3:
    host_reg_wait_set(0xFu, a1 << v3);
    return v4;
  }
  v4 = HIBYTE(v2);
  if ( (v2 & 0xFF00) == 0 )
  {
    v3 = 8;
    goto LABEL_3;
  }
  return -1;
}

