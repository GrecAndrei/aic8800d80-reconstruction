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

extern uint32_t off_11E3DC;
extern uint32_t dword_11E3EC;
extern uint32_t dword_11E3E4;
extern uint32_t dword_11E3E0;
extern uint32_t dword_11E3F4;
extern uint32_t dword_11E3F0;
extern uint32_t dword_11E3F8;
extern uint32_t dword_11E3E8;

// flash_write_byte @ 0x11e34c, size 142 bytes
int  flash_write_byte(unsigned int a1)
{
  int16_t **v1; // r6
  unsigned int v2; // r7
  unsigned int v3; // r5
  int v4; // r4
  int v5; // r5
  char v7; // r4
  int v8; // r3

  v1 = (int16_t **)off_11E3DC;
  v2 = a1 >> 8;
  v3 = (uint8_t)a1;
  if ( **(int16_t **)off_11E3DC >= 0 )
    goto LABEL_2;
  v7 = a1;
  if ( (uint8_t)a1 <= 4u )
    goto LABEL_5;
  flash_ctrl_init(dword_11E3EC, dword_11E3E4, 210);
  if ( **v1 >= 0 )
  {
LABEL_2:
    v4 = dword_11E3E0;
    v5 = 16 * v3;
    return *(uint16_t *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
  }
  if ( v3 <= 5 )
  {
LABEL_5:
    if ( (v7 & 0xFC) == 0 )
      goto LABEL_6;
  }
  else
  {
    flash_ctrl_init(dword_11E3F4, dword_11E3F0, 183);
    if ( (v7 & 0xFC) == 0 )
      goto LABEL_12;
  }
  flash_ctrl_init(dword_11E3F8, dword_11E3E4, 211);
LABEL_12:
  if ( **v1 >= 0 )
    goto LABEL_2;
LABEL_6:
  v4 = dword_11E3E0;
  v8 = dword_11E3E0 + 16 * v3;
  v5 = 16 * v3;
  if ( *(uint16_t *)(v8 + 14) > v2 )
    return *(uint16_t *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
  flash_ctrl_init(dword_11E3E8, dword_11E3E4, 212);
  return *(uint16_t *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
}

