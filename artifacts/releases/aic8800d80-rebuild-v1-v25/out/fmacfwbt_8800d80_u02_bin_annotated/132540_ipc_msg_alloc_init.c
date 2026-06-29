// fwstruct annotate: 132540_ipc_msg_alloc_init.c
// ipc_msg_alloc_init @ 0x132540, size 20 bytes
// Doc: ipc_msg_alloc_init [ipc]: Allocate and initialize an IPC message envelope via sub_12cb54
// ipc_msg_alloc_init [ipc]: Allocate and initialize an IPC message envelope via sub_12cb54
void ipc_msg_alloc_init()
{
  rf_bus_setup_n3a8(12, 0, 5, 1u);
  JUMPOUT(0x132554);
}

