// v23 annotated: rf_timer_abort2 @ 0x12ef94
// Original: 12ef94_rf_timer_abort2.c
// Primary struct: group_11 (cluster 11)
//
// rf_timer_abort2 @ 0x12ef94, size 22 bytes
// Doc: rf_timer_abort2 [rf]: Duplicate entry: abort RF timer and send 0x42d control message
// rf_timer_abort2 [rf]: Duplicate entry: abort RF timer and send 0x42d control message
void __noreturn rf_timer_abort2()
{
  msg_parse(dword_12EFAC);
  sub_12C5FC(1069, 1);
  sub_12EF88();
}

