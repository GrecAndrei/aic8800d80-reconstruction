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

extern uint32_t off_135654;
extern uint32_t dword_13565C;
extern uint32_t off_135658;
extern uint32_t dword_135664;
extern uint32_t dword_135660;

// bt_send_profile_cmd @ 0x135598, size 186 bytes
void  bt_send_profile_cmd(
        char *a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v14; // r8
  unsigned int v15; // r1
  int v16; // r6
  int v17; // r3
  int v18; // r1
  char *v19; // r4
  int v20; // r12
  char *v21; // r3
  char v22; // t1
  int v23; // r1
  int v24; // r2
  int v25; // r1

  v14 = *((uint32_t *)off_135654 + 5);
  ke_int_lock(6154, 6);
  v15 = *(uint16_t *)a1;
  v16 = *((uint16_t *)a1 + 7);
  if ( v15 <= 5 )
  {
    v25 = dword_13565C;
    *(uint16_t *)(v14 + 16) = 0;
    check_status_bits(256, v25, v16);
    if ( !v16 )
    {
LABEL_9:
      bt_send_vendor_cmd(*((uint16_t *)a1 + 8) & 0x3FFF);
      return;
    }
  }
  else
  {
    v17 = *(uint16_t *)(v14 + 14);
    v18 = (uint16_t)(v15 - 6);
    v19 = a1 + 18;
    if ( v18 + v17 > 800 )
    {
      if ( **(int16_t **)off_135658 < 0 )
      {
        call_shared_handler(dword_135664, dword_135660, 1236);
        v17 = *(uint16_t *)(v14 + 14);
      }
      v18 = (uint16_t)(800 - v17);
    }
    v20 = v14 + 20 + v17;
    if ( v18 )
    {
      do
      {
        v21 = v19 - 18;
        v22 = *v19++;
        *(uint8_t *)(v21 - a1 + v20) = v22;
      }
      while ( v19 != &a1[v18 + 18] );
    }
    *(uint16_t *)(v14 + 16) = v18;
    check_status_bits(256, dword_13565C, v16);
    if ( !v16 )
      goto LABEL_9;
  }
  bt_setup_conn_profile(v16, v23, v24, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
}

