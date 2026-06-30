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

extern uint32_t off_12BCDC;
extern uint32_t off_12BCE4;
extern uint32_t off_12BCE0;
extern uint32_t dword_12BCE8;
extern uint32_t off_12BCEC;
extern uint32_t off_12BCF0;
extern uint32_t off_12BCF4;
extern uint32_t dword_12BD40;
extern uint32_t dword_12BD3C;
extern uint32_t off_12BCF8;
extern uint32_t dword_12BD00;
extern uint32_t dword_12BCFC;
extern uint32_t off_12BD04;
extern uint32_t dword_12BD08;
extern uint32_t off_12BD0C;
extern uint32_t off_12BD10;
extern uint32_t off_12BD18;
extern uint32_t off_12BD14;
extern uint32_t off_12BD20;
extern uint32_t off_12BD1C;
extern uint32_t off_12BD24;
extern uint32_t off_12BD28;
extern uint32_t off_12BD2C;
extern uint32_t off_12BD30;
extern uint32_t off_12BD34;
extern uint32_t off_12BD44;
extern uint32_t off_12BD38;

// sub_12BAE4 @ 0x12bae4, size 502 bytes
// Doc: sub_122BAE4 [bt]: Initialize BT mailbox control register to 1
// sub_122BAE4 [bt]: Initialize BT mailbox control register to 1
int sub_12BAE4()
{
  uint32_t *v0; // r2
  unsigned int variant_cached; // r0
  uint32_t *v2; // r3
  uint32_t *v3; // r2
  int16_t **v4; // r1
  char *v5; // r0
  int *v6; // r3
  uint32_t *v7; // r1
  int v8; // r2
  int *v9; // r4
  int v10; // r5
  uint8_t *v11; // r1
  int *v12; // r3
  uint32_t *v13; // r3
  uint32_t *v14; // r4
  unsigned int *v15; // r6
  uint32_t *v16; // r2
  uint32_t *v17; // r5
  int result; // r0
  uint32_t *v19; // r1
  uint8_t **v20; // r2
  uint32_t *v21; // r4
  uint32_t *v22; // r6
  int v23; // r0
  unsigned int *v24; // r5
  uint8_t v25; // [sp+6h] [bp-2h] BYREF
  uint8_t v26; // [sp+7h] [bp-1h] BYREF

  v0 = off_12BCDC;
  *(uint32_t *)off_12BCDC = 1;
  while ( (uint8_t)*v0 )
    ;
  variant_cached = get_variant_cached();
  sub_12B7C8(variant_cached);
  v2 = off_12BCE4;
  *(uint32_t *)off_12BCE0 = dword_12BCE8;
  v3 = off_12BCEC;
  *v2 = 0x80000000;
  v4 = (int16_t **)off_12BCF0;
  *v3 &= ~0x800u;
  if ( **v4 < 0 && *(uint32_t *)off_12BCF4 < 0x2F000000u )
    sub_12F694(dword_12BD40, dword_12BD3C, 284);
  v5 = (char *)off_12BCF4;
  v6 = (int *)off_12BCF8;
  v7 = off_12BCEC;
  v8 = dword_12BD00;
  *(uint32_t *)off_12BCF4 = dword_12BCFC;
  *v6 = v8;
  v9 = (int *)off_12BD04;
  v10 = dword_12BD08;
  *v7 |= 0x40007C0u;
  *v7 &= ~0x4000000u;
  v11 = off_12BD0C;
  v12 = v6 - 8199;
  *(uint32_t *)&v5[-132] |= 0x10000u;
  *v9 = v10;
  *v12 |= 0xFF000000;
  *v12 |= 0x800000u;
  *v12 = *v12 & 0xFF80FFFF | 0x100000;
  if ( !v11[2] )
    *v12 = (HIWORD(*v12) << 16) | 0x64;
  v13 = off_12BD10;
  v14 = off_12BCEC;
  v15 = (unsigned int *)off_12BD18;
  *(uint32_t *)off_12BD14 = 12288;
  *v13 = 0;
  bt_fw_init_or_handler(&v26, &v25);
  v16 = off_12BD20;
  *(uint32_t *)off_12BD1C = (v26 << 8) | (v25 << 16) | v26;
  v17 = off_12BD24;
  *v14 |= 0x1000u;
  *v14 |= 0x2000u;
  *v16 |= 0x80000u;
  *v16 &= ~0x80u;
  result = sub_101954();
  v19 = off_12BD28;
  *v15 = ((result + 1) << 26) & 0x1C000000 | *v15 & 0xE3FFFFFF;
  v20 = (uint8_t **)off_12BD2C;
  *v14 |= 0x20u;
  *v17 &= ~1u;
  *v19 |= 2u;
  if ( **v20 == 1 )
    *(uint32_t *)off_12BD30 &= 0x80FFFFFF;
  v21 = off_12BCEC;
  v22 = off_12BD34;
  *(uint32_t *)off_12BCEC |= 0x2000000u;
  if ( (*v22 & 0x20000) != 0 )
  {
    result = sdio_buffer_prepare_n_2e2();
    if ( result )
    {
      v23 = chip_rev_get();
      v24 = (unsigned int *)off_12BD44;
      result = v23 << 8;
      *(uint32_t *)off_12BD44 = result & 0x700 | *(uint32_t *)off_12BD44 & 0xFFFFF8FF;
      *v24 = *v24 & 0xFFFFFF1F | 0x60;
      *v24 |= 4u;
      *v24 |= 1u;
      if ( (*v22 & 0x8000) != 0 )
      {
        result = chip_feature_check();
        if ( result )
        {
          *v21 |= 0x80000u;
          *v24 = *v24 & 0xF1FFFFFF | 0x4000000;
        }
      }
      if ( (*(uint32_t *)off_12BD34 & 0x20000) != 0 )
      {
        result = sysctl_chip_id_get();
        if ( result )
          *(uint32_t *)off_12BD44 |= 2u;
      }
    }
  }
  *(uint32_t *)off_12BD38 |= 1u;
  return result;
}

