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

extern uint32_t off_12672C;
extern uint32_t off_126734;
extern uint32_t off_126730;
extern uint32_t off_12673C;
extern uint32_t off_126758;
extern uint32_t dword_126748;
extern uint32_t off_126738;
extern uint32_t off_126740;
extern uint32_t off_126744;
extern uint32_t off_12674C;
extern uint32_t off_126750;
extern uint32_t off_126754;
extern uint32_t dword_12675C;
extern uint32_t off_126760;

// rf_state_machine @ 0x126588, size 418 bytes
int rf_state_machine()
{
  int v0; // r3
  uint8_t *v1; // r5
  uint8_t *v2; // r6
  char *v3; // r4
  int v4; // r7
  char *v5; // r3
  int v6; // r7
  int v7; // r10
  float v8; // r3
  float v9; // r9
  uint64_t v10; // r0
  uint64_t v11; // r0
  unsigned int v12; // r2
  unsigned uint64_t v13; // r8
  uint64_t v14; // r0
  uint64_t v15; // r2
  unsigned uint64_t v16; // r0
  uint64_t v17; // r8
  char *v18; // r4
  char v19; // r0
  int v20; // r2
  int v21; // r3
  int v22; // r0
  int *v23; // r0
  int *v24; // r1
  uint32_t *v25; // r2
  int v26; // r3
  uint8_t *v27; // r4
  int v28; // r6
  uint64_t v29; // r0
  unsigned int v30; // r2
  unsigned uint64_t v31; // r6
  uint64_t v32; // r0
  int v33; // r0
  float v34; // r0
  uint64_t v35; // r0
  uint64_t v36; // r0
  char v37; // r3
  int v38; // r0
  uint64_t v40; // r8
  uint64_t v41; // r0
  int v42; // r0
  int v43; // r0
  uint32_t *v44; // r3

  v0 = *(uint8_t *)off_12672C;
  v1 = off_126734;
  *(uint16_t *)off_126730 = 0;
  if ( v0 )
  {
    if ( *v1 == 2 )
    {
      v27 = off_12673C;
      v28 = *(uint16_t *)off_12673C;
      if ( *(uint16_t *)off_12673C )
      {
        v29 = aeabi_i2d(*(uint32_t *)off_126758);
        v30 = v29;
        LODWORD(v29) = v28;
        v31 = __PAIR64__(HIDWORD(v29), v30);
        v32 = aeabi_i2d(v29);
        v33 = aeabi_dsub(v31, HIDWORD(v31), v32, HIDWORD(v32));
        v34 = aeabi_dmul(v33);
        v35 = aeabi_d2f(LODWORD(v34));
      }
      else
      {
        v35 = 0;
      }
      v36 = parse_data_field(v35, HIDWORD(v35));
      v37 = double_to_float(v36, HIDWORD(v36));
      v38 = dword_126748;
      v27[5] = v37;
      *v1 = 3;
      dispatch_event_handler(v38);
      return set_busy_flag_alt(0x2000);
    }
    else
    {
      return ll_state_reset();
    }
  }
  else if ( *v1 )
  {
    v2 = off_126738;
    v3 = (char *)off_12673C;
    v4 = *(uint8_t *)off_126738 - 1;
    v5 = (char *)off_12673C + 8 * v4;
    v6 = 8 * v4;
    v7 = (uint8_t)v5[2];
    if ( v5[2] )
    {
      v40 = aeabi_i2d(*(uint32_t *)off_126758);
      v41 = aeabi_i2d(v7);
      v42 = aeabi_dsub(v40, HIDWORD(v40), v41, HIDWORD(v41));
      v9 = aeabi_dmul(v42);
      v8 = *(float *)off_126740 / (float)v7;
      *(float *)off_126740 = v8;
    }
    else
    {
      v8 = *(float *)off_126740;
      v9 = 0.0;
    }
    v10 = aeabi_d2f(LODWORD(v8));
    v11 = parse_data_field(v10, HIDWORD(v10));
    v12 = v11;
    *(float *)&v11 = v9;
    v13 = __PAIR64__(HIDWORD(v11), v12);
    v14 = aeabi_d2f(v11);
    v15 = parse_data_field(v14, HIDWORD(v14));
    v16 = v13;
    v17 = v15;
    v18 = &v3[v6];
    v18[4] = double_to_float(v16, HIDWORD(v16));
    v19 = double_to_float(v17, HIDWORD(v17));
    v20 = (uint8_t)*v2;
    v21 = *(uint8_t *)off_126744;
    v18[3] = v19;
    v22 = dword_126748;
    if ( v20 == v21 )
    {
      *v1 = 4;
      dispatch_event_handler(v22);
    }
    else
    {
      *v1 = 2;
      dispatch_event_handler(v22);
      v23 = (int *)off_12674C;
      v24 = (int *)off_126750;
      v25 = off_126754;
      ++*v2;
      v26 = *v23;
      *v24 = *v23;
      *v25 = v26 + 1000000;
    }
    return set_busy_flag_alt(0x2000);
  }
  else
  {
    dispatch_event_handler(dword_12675C);
    v43 = dword_126748;
    *v1 = 1;
    dispatch_event_handler(v43);
    v44 = off_126760;
    *(uint32_t *)off_126760 |= 0x100u;
    *v44 |= 0x200u;
    *v44 |= 0x400u;
    return set_busy_flag_alt(0x2000);
  }
}

