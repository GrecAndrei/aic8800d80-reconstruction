// sdio_cfg_write @ 0x132540, size 20 bytes
// Doc: sdio_cfg_write [ipc]: Allocate and initialize an IPC message envelope via sub_12cb54
// sdio_cfg_write [ipc]: Allocate and initialize an IPC message envelope via sub_12cb54
void sdio_cfg_write()
{
  bt_buf_alloc(12, 0, 5, 1u);
  JUMPOUT(0x132554);
}

