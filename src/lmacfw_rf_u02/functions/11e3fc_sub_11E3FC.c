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

extern uint32_t off_11E4B8;
extern uint32_t dword_11E4C8;
extern uint32_t dword_11E4C0;
extern uint32_t dword_11E4BC;
extern uint32_t dword_11E4D0;
extern uint32_t dword_11E4CC;
extern uint32_t dword_11E4D4;
extern uint32_t dword_11E4C4;

// flash_read_byte @ 0x11e3fc, size 186 bytes
int  flash_read_byte(int a1, unsigned int a2)
{
  int16_t **v2; // r4
  unsigned int v4; // r7
  unsigned int v5; // r8
  int v6; // r4
  int v7; // r7
  int v8; // r1
  int v9; // r4
  int v10; // r1
  int result; // r0
  int v12; // r1
  char v13; // r5
  int v14; // r3

  v2 = (int16_t **)off_11E4B8;
  v4 = (uint8_t)a2;
  v5 = a2 >> 8;
  if ( **(int16_t **)off_11E4B8 >= 0 )
    goto LABEL_2;
  v13 = a2;
  if ( (uint8_t)a2 <= 4u )
    goto LABEL_9;
  flash_ctrl_init(dword_11E4C8, dword_11E4C0, 267);
  if ( **v2 >= 0 )
  {
LABEL_2:
    v6 = dword_11E4BC;
    v7 = 16 * v4;
    goto LABEL_3;
  }
  if ( v4 <= 5 )
  {
LABEL_9:
    if ( (v13 & 0xFC) == 0 )
      goto LABEL_10;
  }
  else
  {
    flash_ctrl_init(dword_11E4D0, dword_11E4CC, 183);
    if ( (v13 & 0xFC) == 0 )
      goto LABEL_16;
  }
  flash_ctrl_init(dword_11E4D4, dword_11E4C0, 268);
LABEL_16:
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_10:
  v6 = dword_11E4BC;
  v14 = dword_11E4BC + 16 * v4;
  v7 = 16 * v4;
  if ( *(uint16_t *)(v14 + 14) <= v5 )
    flash_ctrl_init(dword_11E4C4, dword_11E4C0, 269);
LABEL_3:
  v8 = *(uint32_t *)(v6 + v7);
  v9 = v6 + v7;
  if ( !v8
    || (v10 = v8 + 8 * *(uint16_t *)(*(uint32_t *)(v9 + 8) + 2 * v5),
        (result = process_list_entries(a1, (int *)v10, *(uint16_t *)(v10 + 4))) == 0) )
  {
    v12 = *(uint32_t *)(v9 + 4);
    if ( v12 )
      return process_list_entries(a1, (int *)v12, *(uint16_t *)(v12 + 4));
    else
      return 0;
  }
  return result;
}

