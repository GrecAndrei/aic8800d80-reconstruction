// sub_11AD40 @ 0x11ad40, size 58 bytes
int  sub_11AD40(int result)
{
  int v1; // r5
  int v2; // r1
  char v3; // r3
  int v4; // r4

  v1 = dword_11AD7C;
  v2 = *(uint32_t *)(dword_11AD7C + 84 * result + 40);
  if ( v2 )
  {
    v3 = *(uint8_t *)(v2 + 14) - 1;
    v4 = result;
    *(uint8_t *)(v2 + 14) = v3;
    if ( !v3 )
      list_push_tail(*(uint32_t *)(v2 + 340));
    *(uint32_t *)(v1 + 84 * v4 + 40) = 0;
    return 84;
  }
  return result;
}

