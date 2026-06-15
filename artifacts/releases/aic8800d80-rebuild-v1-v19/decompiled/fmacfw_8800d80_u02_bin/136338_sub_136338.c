// sub_136338 @ 0x136338, size 56 bytes
// Doc: sub_1236338 [util]: Check firmware ready flag from shared state
// sub_1236338 [util]: Check firmware ready flag from shared state
int sub_136338()
{
  if ( **(__int16 **)off_136370 >= 0 || msg_get_value(7u) == 2 )
  {
    ipc_msg_post_init(0);
    return 0;
  }
  else
  {
    sub_12F46C(dword_136378, dword_136374, 388);
    ipc_msg_post_init(0);
    return 0;
  }
}

