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

extern uint32_t dword_124C44;
extern uint32_t off_124C40;
extern uint32_t off_124C48;
extern uint32_t off_124C4C;
extern uint32_t off_124C50;
extern uint32_t dword_124C54;

// radio_reg_init @ 0x124bbc, size 132 bytes
int  radio_reg_init(uint16_t *a1)
{
  int v1; // r3
  int *v2; // r2
  int v4; // r0
  int *v5; // r5
  int *v6; // r7
  int v7; // r6
  int v8; // r1
  int v9; // r5
  int *v10; // r0

  v1 = dword_124C44;
  v2 = *(int **)off_124C40;
  v4 = *a1;
  v5 = (int *)off_124C48;
  v6 = (int *)off_124C4C;
  v7 = a1[2];
  *v2 = **(uint32_t **)off_124C40 & dword_124C44 | (v4 << 12);
  *v5 = *v5 & v1 | (v4 << 12);
  v8 = a1[1];
  v2[1] = v2[1] & v1 | (v8 << 12);
  v9 = a1[3];
  *v6 = *v6 & v1 | (v8 << 12);
  v2[2] = v2[2] & v1 | (v7 << 12);
  v10 = (int *)off_124C50;
  v6[1] = v6[1] & v1 | (v7 << 12);
  v2[3] = v2[3] & v1 | (v9 << 12);
  *v10 = v1 & *v10 | (v9 << 12);
  wait_rf_calibration();
  ke_event_schedule(dword_124C54, *a1, a1[1]);
  return 0;
}

