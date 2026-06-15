// v23 annotated: bt_ps_control @ 0x114e84
// Original: 114e84_bt_ps_control.c
// Primary struct: <unclustered>
//
// bt_ps_control @ 0x114e84, size 18 bytes
// Doc: bt_ps_control [bt]: Bluetooth power-save control handler
// bt_ps_control [bt]: Bluetooth power-save control handler
unsigned int bt_ps_control()
{
  return ((unsigned int)MEMORY[0x1FC](1) >> 9) & 1;
}

