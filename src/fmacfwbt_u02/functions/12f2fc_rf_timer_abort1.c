// send_hci_event_42d @ 0x12f2fc, size 22 bytes
// Doc: send_hci_event_42d [rf]: Abort an RF timer
// send_hci_event_42d [rf]: Abort an RF timer
void __noreturn send_hci_event_42d()
{
  ke_event_schedule(dword_12F314);
  irq_lock(1069, 1);
  task_poll_loop();
}

