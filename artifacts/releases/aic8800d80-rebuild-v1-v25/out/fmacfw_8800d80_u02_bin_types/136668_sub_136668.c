// sub_136668 @ 0x136668, size 52 bytes
// Doc: sub_1236668 [util]: Returns boolean indicating firmware state flag status
// sub_1236668 [util]: Returns boolean indicating firmware state flag status
uint32_t *sub_136668()
{
  if ( **(__int16 **)off_13669C >= 0 || !*((uint32_t *)off_1366A4 + 1) )
    return sub_12D240((uint32_t *)dword_1366A0);
  sub_12F46C(dword_1366A8, dword_1366AC, 46);
  return sub_12D240((uint32_t *)dword_1366A0);
}

