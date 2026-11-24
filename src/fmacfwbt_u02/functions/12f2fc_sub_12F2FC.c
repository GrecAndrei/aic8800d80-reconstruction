#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

// send_hci_event_42d @ 0x12f2fc, size 22 bytes
void  send_hci_event_42d()
{
  char *v0; // r0

  ke_event_schedule_1(aErrWlanFcTimeo);
  v0 = irq_lock((char *)0x42D, 1);
  task_poll_loop((int)v0);
}
