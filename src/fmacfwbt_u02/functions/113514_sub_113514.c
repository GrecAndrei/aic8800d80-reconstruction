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

extern uint32_t off_11363C;
extern uint32_t off_113648;
extern uint32_t dword_113664;
extern uint32_t off_113644;
extern uint32_t dword_113650;
extern uint32_t off_113640;
extern uint32_t off_113654;
extern uint32_t off_11366C;
extern uint32_t off_113658;
extern uint32_t dword_11365C;
extern uint32_t dword_113660;
extern uint32_t dword_113668;

// sub_113514 @ 0x113514, size 294 bytes
void sub_113514()
{
  uint8_t *v0; // r5
  int v1; // r0
  uint32_t *v2; // r4
  uint32_t *v3; // r8
  unsigned int *v4; // r6
  unsigned int v5; // r1
  int v6; // r0
  int v7; // r0
  uint8_t *v8; // r7
  int v9; // r9
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r0
  int v13; // r1

  v0 = off_11363C;
  if ( *(uint8_t *)off_11363C )
  {
    if ( !*(uint16_t *)off_113648 )
    {
      sub_12EEF8(512, dword_113664);
      return;
    }
    if ( *(uint8_t *)off_113644 >= (unsigned int)*(uint16_t *)off_113648 )
    {
      v13 = dword_113650;
      *(uint8_t *)off_113640 = 1;
      sub_12EEF8(512, v13);
    }
  }
  else
  {
    if ( *(uint8_t *)off_113640 )
      return;
    if ( *(uint8_t *)off_113644 >= (unsigned int)*(uint16_t *)off_113648 && !*(uint8_t *)off_113640 )
    {
      *(uint8_t *)off_113640 = 1;
      sub_12EEF8(512, dword_113650);
      return;
    }
  }
  v1 = (*(int ( **)(uint32_t))(*((uint32_t *)off_113654 + 2) + 16))(*((uint32_t *)off_113654 + 1));
  v2 = (uint32_t *)v1;
  if ( v1 )
  {
    if ( *v0 )
    {
      v3 = off_11366C;
      v4 = (unsigned int *)off_113658;
      v5 = *(uint32_t *)off_113658;
      v6 = *(uint32_t *)off_11366C + v1;
      if ( *(uint8_t *)off_113640 )
        v7 = sub_11324C(v6, v5);
      else
        v7 = sub_1131AC(v6, v5);
    }
    else
    {
      v3 = off_11366C;
      v4 = (unsigned int *)off_113658;
      v7 = sub_1131AC(*(uint32_t *)off_11366C + v1, *(uint32_t *)off_113658);
    }
    if ( v7 )
    {
      v8 = off_113640;
      sub_10DA7C(dword_11365C, v7);
      v9 = 5;
      while ( 1 )
      {
        if ( *v0 )
        {
          v10 = *v4;
          v11 = (int)v2 + *v3;
          v12 = *v8 ? sub_11324C(v11, v10) : sub_1131AC(v11, v10);
        }
        else
        {
          v12 = sub_1131AC((int)v2 + *v3, *v4);
        }
        if ( !v12 )
          break;
        if ( !--v9 )
        {
          sub_10DA7C(dword_113660, 5);
          sub_10FE60(v2);
          sub_12D32C(32);
          return;
        }
      }
    }
  }
  else
  {
    sub_12D32C(32);
    sub_10DA7C(dword_113668);
  }
}

