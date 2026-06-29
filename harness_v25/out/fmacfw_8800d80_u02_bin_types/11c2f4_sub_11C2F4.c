// sub_11C2F4 @ 0x11c2f4, size 24 bytes
// Doc: sub_121C2F4 [util]: Sets a one-shot flag byte, calls helper, then clears the flag
// sub_121C2F4 [util]: Sets a one-shot flag byte, calls helper, then clears the flag
void  sub_11C2F4(int a1)
{
  uint8_t *v1; // r4

  v1 = off_11C30C;
  *(uint8_t *)off_11C30C = 1;
  sub_11EBFC(a1);
  *v1 = 0;
  sub_11B9D8();
}

