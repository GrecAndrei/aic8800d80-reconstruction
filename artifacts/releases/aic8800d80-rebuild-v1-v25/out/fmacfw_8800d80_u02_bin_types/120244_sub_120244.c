// sub_120244 @ 0x120244, size 40 bytes
// Doc: obj_release_n252 [util]: Release/destroy wrapper object and free memory
// obj_release_n252 [util]: Release/destroy wrapper object and free memory
int  sub_120244(int result)
{
  int v1; // r4

  if ( *(uint8_t *)off_12026C && (*((uint32_t *)off_12026C + 1) & 8) == 0 )
  {
    v1 = result;
    if ( !*(uint32_t *)(result + 4) )
    {
      timestamp_remove(result + 48);
      return rf_cmd_dispatch_n_125(v1);
    }
  }
  return result;
}

