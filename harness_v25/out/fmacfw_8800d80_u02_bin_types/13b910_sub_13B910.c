// sub_13B910 @ 0x13b910, size 68 bytes
int  sub_13B910(int a1)
{
  int v1; // r3
  int v2; // r6
  int ( *v4)(int, int); // r2
  unsigned __int8 v5; // r0

  v1 = *(unsigned __int8 *)(a1 + 262) + a1;
  if ( *(uint8_t *)(v1 + 6) != 2 )
    return 0;
  LOBYTE(v2) = 0;
  do
  {
    *(uint8_t *)(v1 + 6) = 0;
    v4 = *(int ( **)(int, int))a1;
    *(uint16_t *)(a1 + 4) = (*(uint16_t *)(a1 + 4) + 1) & 0xFFF;
    v5 = v4(a1, 1);
    v1 = a1 + v5;
    *(uint8_t *)(a1 + 262) = v5;
    v2 = (char)(v2 + 1);
  }
  while ( *(uint8_t *)(v1 + 6) == 2 );
  return v2;
}

