// sub_12D240 @ 0x12d240, size 8 bytes
// Doc: sub_122D240 [util]: Zero-initialize a structure and check a status flag
// sub_122D240 [util]: Zero-initialize a structure and check a status flag
_DWORD *__fastcall sub_12D240(_DWORD *result)
{
  *result = 0;
  result[1] = 0;
  return result;
}

