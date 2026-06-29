// sub_11007C @ 0x11007c, size 72 bytes
int sub_11007C()
{
  void *v0; // r8
  int result; // r0
  uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = off_1100D0;
  result = sub_11E71C(dword_1100C4);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 6) )
  {
    v2 = off_1100C8;
    v3 = dword_1100CC;
    v4 = dword_1100C4;
    v5 = 0;
    do
    {
      sub_10FA18(v3, 0x63Cu);
      result = sub_11E724(v4);
      v6 = *(unsigned __int16 *)(*(uint32_t *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v6 > (unsigned __int16)v5 );
  }
  return result;
}

