// sub_12057C @ 0x12057c, size 40 bytes
int  sub_12057C(int result)
{
  int v1; // r4

  if ( *(uint8_t *)off_1205A4 && (*((uint32_t *)off_1205A4 + 1) & 8) == 0 )
  {
    v1 = result;
    if ( !*(uint32_t *)(result + 4) )
    {
      timestamp_remove_058(result + 48);
      return sub_11F82C(v1);
    }
  }
  return result;
}

