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

// sub_11AA8C @ 0x11aa8c, size 114 bytes
int  sub_11AA8C(int a1, uint16_t *a2, int a3, void *a4)
{
  int v4; // r4
  void *v6; // r1
  int v8; // [sp+0h] [bp-8h]
  int v9; // [sp+0h] [bp-8h]
  int v10; // [sp+0h] [bp-8h]
  int v11; // [sp+0h] [bp-8h]
  int v12; // [sp+0h] [bp-8h]

  v4 = *(uint32_t *)a2;
  v6 = a4;
  switch ( v4 )
  {
    case 0:
      v8 = a3;
      rf_reg_probe_id(a2 + 2);
      a3 = v8;
      v6 = a4;
      break;
    case 1:
      v10 = a3;
      rf_state_copy_to_shm((uint8_t *)a2 + 4);
      a3 = v10;
      v6 = a4;
      break;
    case 2:
      v11 = a3;
      rf_mmio_status_read((uint8_t *)a2 + 4);
      a3 = v11;
      v6 = a4;
      break;
    case 3:
      v12 = a3;
      sub_11A9BC((uint8_t *)a2 + 4, a4);
      a3 = v12;
      v6 = a4;
      break;
    case 4:
      v9 = a3;
      sub_11AA5C((uint8_t *)a2 + 4);
      a3 = v9;
      v6 = a4;
      break;
    default:
      break;
  }
  sub_11DED8(127, v6, a3);
  return 0;
}

