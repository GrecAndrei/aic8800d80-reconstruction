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

extern uint32_t off_12A60C;
extern uint32_t dword_12A610;
extern uint32_t dword_12A614;

// bt_conn_validate @ 0x12a568, size 164 bytes
// Doc: bt_conn_validate [bt]: Check state field at offset 0x4c8 and branch on zero
// bt_conn_validate [bt]: Check state field at offset 0x4c8 and branch on zero
unsigned int  bt_conn_validate(uint8_t *a1, int a2, int a3)
{
  unsigned int v3; // r4
  unsigned int v5; // r0
  int v8; // r7
  uint8_t *v9; // r3
  unsigned int v10; // r7
  int v11; // r5
  int v12; // r2
  uint8_t *v13; // r4
  unsigned int v14; // r5

  v3 = (uint8_t)a1[1224];
  if ( !a1[1224] )
    return v3;
  if ( !a1[106] )
  {
    v5 = (uint8_t)a1[1225];
    if ( **(int16_t **)off_12A60C < 0 && v5 > 1 )
    {
      mmio_irq_clear(dword_12A610, dword_12A614, 1420);
      v5 = (uint8_t)a1[1225];
    }
    v8 = *(uint32_t *)(a2 + 8);
    v9 = (uint8_t *)(v8 + 36);
    v10 = v8 + *(uint16_t *)(a3 + 28);
    if ( (unsigned int)v9 < v10 )
    {
      while ( 1 )
      {
        v11 = v9[1];
        v12 = *v9;
        v13 = v9;
        v9 += v11 + 2;
        if ( v12 == 221 && v13[5] == 9 )
        {
          v3 = (unsigned int)(v13 + 6);
          v14 = v3 + (uint16_t)(v11 - 4);
          if ( v3 < v14 )
          {
            while ( *(uint8_t *)v3 != 12 )
            {
              v3 += *(uint16_t *)(v3 + 1) + 3;
              if ( v14 <= v3 )
                goto LABEL_6;
            }
            if ( v3 )
              break;
          }
        }
LABEL_6:
        if ( v10 <= (unsigned int)v9 )
          goto LABEL_19;
      }
    }
    else
    {
LABEL_19:
      v3 = 0;
    }
    get_struct_ptr(v5, v3, *(uint32_t *)(*(uint32_t *)(*(uint32_t *)(a3 + 8) + 8) + 24));
    return v3;
  }
  return 0;
}

