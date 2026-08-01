// send_hci_event_42c @ 0x12f318, size 22 bytes
void __noreturn send_hci_event_42c()
{
  ke_event_schedule(dword_12F330);
  irq_lock(1068, 1);
  task_poll_loop();
}

