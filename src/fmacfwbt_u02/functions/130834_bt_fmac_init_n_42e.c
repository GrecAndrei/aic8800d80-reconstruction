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

extern uint32_t off_130858;

// rf_afe_disable @ 0x130834, size 36 bytes
// Doc: rf_afe_disable [bt]: Triggers BT-related FMAC initialization for opcode 0x42e
// rf_afe_disable [bt]: Triggers BT-related FMAC initialization for opcode 0x42e
int rf_afe_disable()
{
  int result; // r0

  *((uint8_t *)off_130858 + 1) = 0;
  result = find_hci_conn_by_handle(1070, 1);
  if ( result )
    return irq_lock(1070, 1);
  return result;
}

