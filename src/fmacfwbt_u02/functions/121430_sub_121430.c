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

extern uint32_t off_12157C;
extern uint32_t off_121580;
extern uint32_t off_121584;
extern uint32_t off_121588;
extern uint32_t off_12158C;
extern uint32_t off_121590;
extern uint32_t off_121594;
extern uint32_t dword_121598;

// irq_lock_save @ 0x121430, size 332 bytes
// Doc: sub_1221430 [unknown]: Unknown helper in fmacfwbt module
// sub_1221430 [unknown]: Unknown helper in fmacfwbt module
int irq_lock_save()
{
  int v0; // r4
  int *v1; // r5
  int updated; // r0
  int v3; // r1
  int v4; // r3
  int v5; // r2
  uint32_t *v6; // r5
  uint32_t **v7; // r6
  uint32_t *v8; // r7
  int v9; // r3
  uint32_t *v10; // r3
  uint32_t *v11; // r2
  unsigned int v12; // r8
  int v13; // r8
  int **i; // r3
  int v16; // r2
  int v17; // r1
  int v18; // r12
  int v19; // r2

  v0 = *((uint32_t *)off_12157C + 2);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_121580 = 1;
  }
  v1 = (int *)off_121584;
  ++*(uint32_t *)off_121584;
  mmio_set_bit(4);
  updated = conn_get(4);
  if ( *v1 )
  {
    v4 = *v1 - 1;
    v5 = *(uint32_t *)off_121580;
    *v1 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( v0 )
  {
    v6 = off_121588;
    v7 = (uint32_t **)off_12158C;
    v8 = off_121590;
    do
    {
      while ( 1 )
      {
        if ( *(uint8_t *)(v0 + 106) != 2 )
          goto LABEL_7;
        v9 = (uint8_t)(*(uint8_t *)(v0 + 225) - 1);
        *(uint8_t *)(v0 + 225) = v9;
        if ( v9 )
          goto LABEL_7;
        v10 = *v7;
        *(uint8_t *)(v0 + 225) = *(uint8_t *)(v0 + 224);
        if ( v10 )
          break;
LABEL_15:
        wlc_bmac_write_shm(v0);
        updated = bt_conn_event_process(v0, *(uint32_t *)(v0 + 36) + 3048);
        v3 = *(uint16_t *)(v0 + 222);
        v12 = 32 * *v6;
        if ( v12 <= 0xBE7 )
          v12 += v3 << 10;
        v13 = v12 + v8[4] - 3048;
        if ( *(uint32_t *)(v0 + 72) )
          updated = hci_command_handler(v0, *(uint32_t *)(v0 + 36), v13);
        if ( *(uint8_t *)(v0 + 1224) )
        {
          updated = ke_event_lock(v0 + 24, v13);
          goto LABEL_7;
        }
        if ( *((uint8_t *)off_121594 + 90) > 1u )
        {
          for ( i = *((int ***)off_121594 + 4); i; i = (int **)*i )
          {
            v3 = *((uint8_t *)i + 8);
            if ( v3 == *(uint8_t *)(v0 + 107) )
            {
              v16 = *(uint16_t *)(v0 + 222);
              v17 = *(uint32_t *)(v0 + 36);
              updated = (int)i[1];
              v18 = v17 + (v16 << 10);
              v19 = v16 << 10;
              if ( updated == v18 )
              {
                i[1] = (int *)v13;
                updated = v13;
                v19 = *(uint16_t *)(v0 + 222) << 10;
              }
              v3 = v17 + 2 * v19;
              if ( v3 == updated )
                i[1] = (int *)(v19 + v13);
            }
          }
        }
        *(uint32_t *)(v0 + 36) = v13;
        v0 = *(uint32_t *)v0;
        if ( !v0 )
          return rf_status_poll(updated);
      }
      v11 = (uint32_t *)(v0 + 48);
      while ( v10 != v11 )
      {
        v10 = (uint32_t *)*v10;
        if ( !v10 )
          goto LABEL_15;
      }
      updated = ke_event_schedule(dword_121598, v3, v11);
LABEL_7:
      v0 = *(uint32_t *)v0;
    }
    while ( v0 );
  }
  return rf_status_poll(updated);
}

