// clear_queue_buffer @ 0x10d2c4, size 10 bytes
// Doc: clear_queue_buffer [mac]: Clear SDIO state with 0xac threshold check, wide register save
// clear_queue_buffer [mac]: Clear SDIO state with 0xac threshold check, wide register save
int *clear_queue_buffer()
{
  return sub_100200((int *)dword_10D2D0, 0, 0x38u);
}

