// sub_131FF4 @ 0x131ff4, size 144 bytes
int  sub_131FF4(int a1, uint8_t *a2, unsigned int a3, __int16 a4)
{
  uint16_t *v7; // r7
  bool *v9; // r0
  char v10; // r1
  int v11; // r3

  if ( sub_12CD48(5u) == 1 )
    return 2;
  v7 = off_132084;
  if ( *(uint32_t *)off_132084 )
  {
    if ( *a2 )
    {
      *(uint32_t *)off_132084 |= 1 << a2[1];
      sub_12C8D0(5144, a4, a3);
      return 0;
    }
  }
  else if ( !*a2 )
  {
    sub_12C8D0(5144, a4, a3);
    return 0;
  }
  v9 = (bool *)sub_12C7EC(34, 0, a3, 1u);
  v10 = a2[1];
  if ( *a2 )
    v11 = (1 << v10) | *(uint32_t *)v7;
  else
    v11 = *(uint32_t *)v7 & ~(1 << v10);
  *(uint32_t *)v7 = v11;
  v7[4] = a4;
  *v9 = v11 == 0;
  sub_12C84C((int)v9);
  sub_12CBF4(a3, 1);
  return 0;
}

