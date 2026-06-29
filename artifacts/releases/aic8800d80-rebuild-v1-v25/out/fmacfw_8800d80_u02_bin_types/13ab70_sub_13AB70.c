// sub_13AB70 @ 0x13ab70, size 54 bytes
int  sub_13AB70(int a1, uint16_t *a2)
{
  unsigned int v2; // r2
  uint16_t *v4; // r1

  v2 = *(unsigned __int16 *)(a1 + 24);
  if ( (unsigned __int16)__rev16(v2) >= 0x600u )
  {
    *(a2 - 4) = -21846;
    a2 -= 4;
    a2[3] = v2;
    a2[1] = 3;
    a2[2] = 0;
  }
  v4 = sub_13A980(a1, a2, 1);
  return sub_13A704(a1, (int)v4);
}

