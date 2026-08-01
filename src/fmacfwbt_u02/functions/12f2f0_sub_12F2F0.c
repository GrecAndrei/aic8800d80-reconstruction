// task_poll_loop @ 0x12f2f0, size 12 bytes
// Doc: task_poll_loop [bt]: BT init helper calling patch/bt functions and loading 0x16b00c
// task_poll_loop [bt]: BT init helper calling patch/bt functions and loading 0x16b00c
void __noreturn task_poll_loop()
{
  int v0; // r0
  int v1; // r1
  int v2; // r2

  v0 = rf_mode_switch();
  periph_trigger_write(v0, v1, v2);
  while ( 1 )
    ;
}

