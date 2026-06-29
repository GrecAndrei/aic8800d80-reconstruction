// sub_1278F0 @ 0x1278f0, size 94 bytes
// Doc: sub_12278F0 [util]: State/field update helper, reads struct at offset 0x55 and calls downstream
// sub_12278F0 [util]: State/field update helper, reads struct at offset 0x55 and calls downstream
int  sub_1278F0(int a1)
{
  int result; // r0
  char v3; // r3
  int v4; // r3

  result = timestamp_update(a1 + 24, *(uint32_t *)(a1 + 36) + *(uint32_t *)(a1 + 88));
  v3 = *(uint8_t *)(a1 + 85);
  *(uint8_t *)(a1 + 85) = v3 & 0xDF;
  if ( (v3 & 1) != 0 )
  {
    v4 = *((uint32_t *)off_127950 + 9);
    if ( v4 && *(uint32_t *)(v4 + 12) == a1 + 76 )
    {
      bt_event_handler();
      sub_126584(a1, *(uint32_t *)(a1 + 36), 0);
      return sub_126824(a1, *((uint32_t *)off_127954 + 4), 0);
    }
    else
    {
      return sub_126584(a1, *(uint32_t *)(a1 + 36), 0);
    }
  }
  return result;
}

