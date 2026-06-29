// fwstruct annotate: 11768c_counter_increment_n1f8.c
// counter_increment_n1f8 @ 0x11768c, size 14 bytes
// Doc: counter_increment_n1f8 [util]: Increment 32-bit counter at offset 0x1f8
// counter_increment_n1f8 [util]: Increment 32-bit counter at offset 0x1f8
void counter_increment_n1f8()
{
  ++*((_DWORD *)off_11769C + 126);
}

