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

extern uint32_t dword_117D54;
extern uint32_t dword_117D5C;
extern uint32_t dword_117D58;
extern uint32_t off_117D60;
extern uint32_t off_117D64;
extern uint32_t dword_117D68;

// rf_calibration_table_get @ 0x117cb4, size 160 bytes
// Doc: sub_1217CB4 [util]: Index/compute entry into table via stride*8 multiply
// sub_1217CB4 [util]: Index/compute entry into table via stride*8 multiply
int  rf_calibration_table_get(int a1)
{
  int v1; // r6
  int v3; // r5
  int v4; // r5
  uint32_t *v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r0
  int v9; // r7
  int *v11; // r0
  int v12; // r2
  int *v13; // r3

  v1 = dword_117D54;
  v3 = 19 * a1;
  check_interrupt_flag(256, dword_117D5C, dword_117D58, a1);
  v4 = v1 + 8 * v3;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_117D60 = 1;
  }
  v5 = off_117D64;
  v6 = v1 + 152 * a1;
  v7 = *(uint32_t *)off_117D64;
  v8 = *(uint32_t *)(v6 + 44);
  v9 = *(uint32_t *)off_117D64 + 1;
  *(uint32_t *)off_117D64 = v9;
  *(uint8_t *)(v6 + 35) = 0;
  if ( v8 )
  {
    *(uint8_t *)(v8 + 35) = 0;
    if ( !v9 )
    {
LABEL_5:
      mutex_acquire_if_ready(v8);
      check_kernel_state(dword_117D68);
      goto LABEL_6;
    }
    v11 = (int *)off_117D60;
    *v5 = v7;
    v12 = *v11;
    if ( v7 )
    {
      v8 = *(uint32_t *)(v6 + 44);
      goto LABEL_5;
    }
  }
  else
  {
    if ( !v9 )
      goto LABEL_6;
    v13 = (int *)off_117D60;
    *v5 = v7;
    v12 = *v13;
    if ( v7 )
      goto LABEL_6;
  }
  if ( v12 )
    __enable_irq();
  v8 = *(uint32_t *)(v1 + 152 * a1 + 44);
  if ( v8 )
    goto LABEL_5;
LABEL_6:
  mutex_acquire_if_ready(v4);
  return check_kernel_state(dword_117D68);
}

