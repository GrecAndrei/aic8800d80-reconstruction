// sub_122034 @ 0x122034, size 36 bytes
// Doc: fw_state_get_1222036 [util]: FW state getter, reads from 0x16899c control block
// fw_state_get_1222036 [util]: FW state getter, reads from 0x16899c control block
int  sub_122034(int result, int a2)
{
  int v2; // r4

  v2 = result;
  if ( (a2 & 0x800000) != 0 )
  {
    *(uint8_t *)(result + 128) = 0;
  }
  else
  {
    feature_guard_check(1024, dword_122058);
    return send_msg_to_host_c43(v2);
  }
  return result;
}

