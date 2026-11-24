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


extern uint32_t dword_1149EC;
extern uint32_t dword_1149F0;
extern uint32_t off_1149E8;

// find_object_by_key @ 0x114944, size 164 bytes
int  find_object_by_key(char a1, uint16_t a2, int a3)
{
  uint32_t *v6; // r0
  uint32_t *v7; // r4
  uint32_t *v8; // r6
  unsigned int v9; // r5
  uint16_t *v10; // r3
  int v11; // r5
  uint16_t v12; // r1
  uint16_t v13; // r2
  int v14; // r3
  int v15; // r2
  int v16; // r3
  uint64_t v17; // r4

  v6 = critical_enter_2();
  if ( v6 )
  {
    v7 = v6;
    v8 = critical_enter_0();
    if ( v8 )
    {
      v9 = *(uint32_t *)a3;
      v10 = off_1149E8;
      *((uint8_t *)v7 + 2) = a1;
      v11 = (uint16_t)(v9 + 4);
      *(uint8_t *)v7 = v11 + 12;
      *((uint8_t *)v7 + 1) = ((uint16_t)(v11 + 12) >> 8) & 0xF;
      *((uint8_t *)v7 + 3) = 0;
      v12 = v10[13];
      v13 = v10[12];
      v14 = dword_1149EC;
      *((uint16_t *)v7 + 3) = v12;
      *((uint16_t *)v7 + 4) = v13;
      *((uint16_t *)v7 + 5) = v11;
      *((uint16_t *)v7 + 2) = a2;
      v7[3] = v14;
      if ( v11 )
      {
        v7[4] = *(uint32_t *)a3;
        memcpy_aligned((char *)v7 + 20, (char *)(a3 + 4), *(uint32_t *)a3);
      }
      v15 = v8[2];
      v16 = dword_1149F0;
      *v8 = v7;
      LODWORD(v17) = 0;
      HIDWORD(v17) = (uint16_t)(v11 + 16) | v16 & v15 | 0x80000000;
      *(uint64_t *)(v8 + 1) = v17;
      ke_mutex_lock((int)v8);
      return 0;
    }
    else
    {
      ke_event_schedule_1(aErrSendMsgCfgT);
      memory_pool_free(v7);
      return -2;
    }
  }
  else
  {
    ke_event_schedule_1(aErrSdioBtNoDat);
    return -1;
  }
}
