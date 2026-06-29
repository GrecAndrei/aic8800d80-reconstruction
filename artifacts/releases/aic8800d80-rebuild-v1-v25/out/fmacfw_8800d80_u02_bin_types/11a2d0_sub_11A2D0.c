// sub_11A2D0 @ 0x11a2d0, size 22 bytes
// Doc: sub_121A2D0 [util]: Decrement reference counter at offset 0xe and deref handle at 0x154
// sub_121A2D0 [util]: Decrement reference counter at offset 0xe and deref handle at 0x154
int  sub_11A2D0(int result)
{
  char v1; // r3

  v1 = *(uint8_t *)(result + 14) - 1;
  *(uint8_t *)(result + 14) = v1;
  if ( !v1 )
    return list_push_tail(*(uint32_t *)(result + 340));
  return result;
}

