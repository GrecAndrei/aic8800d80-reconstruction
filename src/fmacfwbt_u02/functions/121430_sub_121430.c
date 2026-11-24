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


extern uint32_t dword_12157C;
extern uint32_t dword_121580;
extern uint32_t dword_121584;
extern uint32_t dword_121588;
extern uint32_t dword_12158C;
extern uint32_t dword_121594;

// irq_lock_save @ 0x121430, size 332 bytes
void irq_lock_save()
{
  int v0; // r4
  uint32_t *v1; // r5
  int v2; // r3
  int v3; // r2
  uint32_t *v4; // r5
  uint32_t **v5; // r6
  int v6; // r3
  uint32_t *v7; // r3
  unsigned int v8; // r8
  unsigned int v9; // r2
  int v10; // r8
  int **i; // r3
  int v12; // r2
  int v13; // r1
  int v14; // r0
  int v15; // r12
  int v16; // r2

  v0 = *(uint32_t *)(dword_12157C + 8);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)dword_121580 = 1;
  }
  v1 = (uint32_t *)dword_121584;
  ++*(uint32_t *)dword_121584;
  mmio_set_bit(4);
  conn_get(4u);
  if ( *v1 )
  {
    v2 = *v1 - 1;
    v3 = *(uint32_t *)dword_121580;
    *v1 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  if ( v0 )
  {
    v4 = (uint32_t *)dword_121588;
    v5 = (uint32_t **)dword_12158C;
    do
    {
      while ( 1 )
      {
        if ( *(uint8_t *)(v0 + 106) != 2 )
          goto LABEL_7;
        v6 = (uint8_t)(*(uint8_t *)(v0 + 225) - 1);
        *(uint8_t *)(v0 + 225) = v6;
        if ( v6 )
          goto LABEL_7;
        v7 = *v5;
        *(uint8_t *)(v0 + 225) = *(uint8_t *)(v0 + 224);
        if ( v7 )
          break;
LABEL_15:
        wlc_bmac_write_shm(v0);
        bt_conn_event_process(v0, *(uint32_t *)(v0 + 36) + 3048);
        v8 = 32 * *v4;
        if ( v8 <= 0xBE7 )
          v8 += *(uint16_t *)(v0 + 222) << 10;
        v9 = (*(volatile uint32_t *)0x40501010u) - 3048;
        v10 = v8 + v9;
        if ( *(uint32_t *)(v0 + 72) )
          hci_command_handler(v0, *(uint32_t *)(v0 + 36), v10);
        if ( *(uint8_t *)(v0 + 1224) )
        {
          ke_event_lock((uint32_t *)(v0 + 24), v10);
          goto LABEL_7;
        }
        if ( *(uint8_t *)(dword_121594 + 0x5A) > 1u )
        {
          for ( i = *(int ***)(dword_121594 + 0x10); i; i = (int **)*i )
          {
            if ( *((uint8_t *)i + 8) == *(uint8_t *)(v0 + 107) )
            {
              v12 = *(uint16_t *)(v0 + 222);
              v13 = *(uint32_t *)(v0 + 36);
              v14 = (int)i[1];
              v15 = v13 + (v12 << 10);
              v16 = v12 << 10;
              if ( v14 == v15 )
              {
                i[1] = (int *)v10;
                v14 = v10;
                v16 = *(uint16_t *)(v0 + 222) << 10;
              }
              if ( v13 + 2 * v16 == v14 )
                i[1] = (int *)(v16 + v10);
            }
          }
        }
        *(uint32_t *)(v0 + 36) = v10;
        v0 = *(uint32_t *)v0;
        if ( !v0 )
          goto LABEL_22;
      }
      while ( v7 != (uint32_t *)(v0 + 48) )
      {
        v7 = (uint32_t *)*v7;
        if ( !v7 )
          goto LABEL_15;
      }
      ke_event_schedule_1(aNextTbttTooClo);
LABEL_7:
      v0 = *(uint32_t *)v0;
    }
    while ( v0 );
  }
LABEL_22:
  rf_status_poll();
}
