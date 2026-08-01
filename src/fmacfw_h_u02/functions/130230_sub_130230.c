// fw_version_get @ 0x130230, size 4 bytes
// attributes: thunk
int fw_version_get()
{
  return hw_block_reset();
}

