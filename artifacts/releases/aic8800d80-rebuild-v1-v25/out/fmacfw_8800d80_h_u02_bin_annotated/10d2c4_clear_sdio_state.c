// fwstruct annotate: 10d2c4_clear_sdio_state.c
// clear_sdio_state @ 0x10d2c4, size 10 bytes
// Doc: clear_sdio_state [mac]: Clear SDIO state with 0xac threshold check, wide register save
// clear_sdio_state [mac]: Clear SDIO state with 0xac threshold check, wide register save
int *clear_sdio_state()
{
  return sub_100200((int *)dword_10D2D0, 0, 0x38u);
}

