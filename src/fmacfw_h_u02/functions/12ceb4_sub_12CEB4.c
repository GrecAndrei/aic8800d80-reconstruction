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


extern uint32_t dword_12CF9C;
extern uint32_t dword_12CFB0;
extern uint32_t off_12CF94;
extern uint32_t off_12CF98;
extern uint32_t off_12CFA4;
extern uint32_t off_12CFA8;
extern uint32_t off_12CFB8;

// irq_disable_global @ 0x12ceb4, size 222 bytes
uint32_t *irq_disable_global()
{
  int *v0; // r5
  int v1; // r0
  uint32_t *result; // r0
  char *v3; // r4
  int v4; // r3
  int v5; // r2
  int ( *v6)(uint32_t, char *, uint32_t, uint32_t); // r6
  int v7; // r2
  int v8; // r3
  int v9; // r3
  int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12CF94 = 1;
  }
  v0 = (int *)off_12CF98;
  v1 = dword_12CF9C;
  ++*(uint32_t *)off_12CF98;
  result = list_pop(v1);
  v3 = (char *)result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(uint32_t *)off_12CF94;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (int ( *)(uint32_t, char *, uint32_t, uint32_t))hci_event_handler(
                                                               *((uint16_t *)result + 2),
                                                               *((uint16_t *)result + 3));
    alloc_tx_event(
      "\x9D\x80Dispatching msg:%x from tsk:%x to tsk:%x\n",
      *((uint16_t *)v3 + 2),
      *((uint16_t *)v3 + 4),
      *((uint16_t *)v3 + 3));
    if ( v6 )
    {
      result = (uint32_t *)v6(
                           *((uint16_t *)v3 + 2),
                           v3 + 12,
                           *((uint16_t *)v3 + 3),
                           *((uint16_t *)v3 + 4));
      if ( result == (uint32_t *)1 )
        goto LABEL_12;
      if ( result == (uint32_t *)2 )
      {
        result = (uint32_t *)wlan_ioctl_handler_1(dword_12CFB0, v3);
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(uint16_t **)off_12CFA4 < 0 )
          result = (uint32_t *)irq_disable_mmio_write(off_12CFB8, (int)aKeTaskSchedule, 360);
        goto LABEL_12;
      }
    }
    else
    {
      alloc_tx_event(
        "\x9A\x80No handler found for msg:%x from tsk:%x to tsk:%x\n",
        *((uint16_t *)v3 + 2),
        *((uint16_t *)v3 + 4),
        *((uint16_t *)v3 + 3));
    }
    result = tx_process_jump(v3);
  }
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12CF94 = 1;
  }
  v7 = *((uint32_t *)off_12CFA8 + 1);
  v8 = *v0 + 1;
  *v0 = v8;
  if ( !v7 )
  {
    result = (uint32_t *)irq_disable_global_3(0x4000000);
    v8 = *v0;
  }
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = *(uint32_t *)off_12CF94;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}
