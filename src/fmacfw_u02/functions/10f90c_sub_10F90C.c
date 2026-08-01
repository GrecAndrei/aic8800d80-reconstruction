// sys_command_40d @ 0x10f90c, size 24 bytes
int sys_command_40d()
{
  int v0; // r0

  v0 = ke_msg_alloc(1037, 1, 13, 8);
  return ke_msg_send(v0);
}

