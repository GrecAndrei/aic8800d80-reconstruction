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


extern uint32_t off_114D74;
extern uint32_t off_114D78;
extern uint32_t off_114D80;
extern uint32_t off_114D84;
extern uint32_t off_114D88;
extern uint32_t off_114D8C;
extern uint32_t off_114D90;
extern uint32_t off_114D94;
extern uint32_t off_114D98;
extern uint32_t off_114D9C;
extern uint32_t off_114DA0;
extern uint32_t off_114DA4;
extern uint32_t off_114DA8;
extern uint32_t off_114DB0;
extern uint32_t off_114DB4;
extern uint32_t off_114DB8;

// command_enqueue @ 0x114c98, size 218 bytes
int  command_enqueue(int a1, int a2, int a3, int a4, char a5)
{
  uint8_t *v5; // r8
  uint32_t *v8; // r7
  int *v9; // r2
  char *v10; // r3
  unsigned int *v11; // r2
  uint32_t *v12; // r6
  uint32_t *v13; // r5
  uint32_t *v14; // r4
  unsigned int v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r1
  uint8_t *v19; // r3
  uint32_t *v20; // r4
  uint32_t *v21; // r3
  uint8_t *v22; // r2

  if ( a1 )
    return 1;
  if ( a2 )
    return 2;
  v5 = off_114DB8;
  if ( *(uint8_t *)off_114DB8 )
  {
    v8 = off_114D74;
  }
  else
  {
    v21 = off_114D98;
    v8 = off_114D74;
    *(uint32_t *)off_114DA8 = off_114D74;
    *v21 = 196608;
    ke_event_schedule_1("SetVector irq = %d\n", 38);
    v22 = off_114DA4;
    *(uint32_t *)(*((uint32_t *)off_114DB0 + 2) + 216) = off_114DB4;
    v22[806] = -4;
    *v5 = 1;
  }
  *(uint32_t *)off_114D78 = 196608;
  ke_event_schedule_1("enable irq = %d\n", 38);
  v9 = (int *)off_114D84;
  *(uint32_t *)off_114D80 = a3;
  v10 = (char *)off_114D88;
  *v9 = a4;
  v11 = (unsigned int *)off_114D8C;
  *v10 = a5;
  v12 = off_114D94;
  v13 = off_114D98;
  v14 = off_114D9C;
  v16 = *v11 & 0xFFFFFFFC;
  *(uint32_t *)off_114D90 = 0;
  *v8 = 0;
  *v11 = v16;
  v17 = *v11;
  v12[3] = 0;
  *v11 = v17 & 0xFFFFFFF3;
  *v13 = 4980736;
  *v14 = 0x10000;
  *v13 = 0x4000000;
  *v14 = 0x4000000;
  v18 = *v11;
  v19 = off_114DA0;
  v20 = off_114DA4;
  *((uint8_t *)off_114DA0 + 16) = 0;
  *v11 = v18 & 0xFFCFFFFF;
  v19[36] = 0;
  v19[56] = 0;
  v19[76] = 0;
  v19[96] = 0;
  v19[116] = 0;
  v20[1] = 64;
  return 0;
}
