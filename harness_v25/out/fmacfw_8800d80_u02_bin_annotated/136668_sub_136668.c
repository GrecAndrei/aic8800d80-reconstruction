// fwstruct annotate: 136668_sub_136668.c
// sub_136668 @ 0x136668, size 52 bytes
// Doc: sub_1236668 [util]: Returns boolean indicating firmware state flag status
// sub_1236668 [util]: Returns boolean indicating firmware state flag status
_DWORD *sub_136668()
{
  if ( **(__int16 **)off_13669C >= 0 || !*((_DWORD *)off_1366A4 + 1) )
    return sub_12D240((_DWORD *)dword_1366A0);
  sub_12F46C(dword_1366A8, dword_1366AC, 46);
  return sub_12D240((_DWORD *)dword_1366A0);
}

