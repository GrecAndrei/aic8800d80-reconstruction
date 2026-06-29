// sub_11C310 @ 0x11c310, size 52 bytes
int sub_11C310()
{
  int result; // r0
  int v1; // r4
  int *v2; // r2
  int v3; // r3

  result = sub_1203F4();
  if ( (*(uint32_t *)off_11C344 & 0x8000) != 0 && (v1 = result, (result = sub_1019FC()) != 0) && v1 )
  {
    v2 = (int *)off_11C34C;
    v3 = *(uint32_t *)off_11C34C;
    *((uint32_t *)off_11C348 + 4) = v1;
    *v2 = v3 | 0x80;
  }
  else
  {
    *((uint32_t *)off_11C348 + 4) = 0;
  }
  return result;
}

