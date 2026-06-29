// sub_1139C8 @ 0x1139c8, size 52 bytes
// Doc: rf_cmd_process_n480 [rf]: Allocate and queue RF command for processing
// rf_cmd_process_n480 [rf]: Allocate and queue RF command for processing
int sub_1139C8()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_1139FC;
  result = sub_12D240(rf_cmd_process_n4a8);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 4) )
  {
    v2 = rf_cmd_process_n4ac;
    v3 = rf_cmd_process_n4a8;
    v4 = 0;
    do
    {
      sub_10FB28(v2, 0x7Cu);
      result = list_push_tail(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(uint32_t *)v0 + 4) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

