// flash_cr_unlock @ 0x1027d8, size 102 bytes
// Doc: flash_cr_unlock [rf]: Writes 32-bit value to RF bus register pair
// flash_cr_unlock [rf]: Writes 32-bit value to RF bus register pair
void __noreturn flash_cr_unlock()
{
  llc_event_loop();
}

