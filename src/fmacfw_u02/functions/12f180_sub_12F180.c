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

extern uint32_t off_12F35C;
extern uint32_t off_12F3F8;
extern uint32_t off_12F360;
extern uint32_t off_12F364;
extern uint32_t off_12F3FC;
extern uint32_t off_12F400;
extern uint32_t off_12F368;
extern uint32_t dword_12F358;
extern uint32_t off_12F354;
extern uint32_t dword_12F370;
extern uint32_t off_12F36C;
extern uint32_t dword_12F374;
extern uint32_t dword_12F378;
extern uint32_t dword_12F37C;
extern uint32_t dword_12F380;
extern uint32_t dword_12F384;
extern uint32_t dword_12F388;
extern uint32_t dword_12F39C;
extern uint32_t off_12F38C;
extern uint32_t off_12F390;
extern uint32_t off_12F394;
extern uint32_t off_12F398;
extern uint32_t off_12F404;
extern uint32_t dword_12F3A0;
extern uint32_t dword_12F3A4;
extern uint32_t dword_12F3A8;
extern uint32_t dword_12F3AC;
extern uint32_t dword_12F3B0;
extern uint32_t off_12F3F0;
extern uint32_t dword_12F3F4;
extern uint32_t dword_12F3B4;
extern uint32_t off_12F3B8;
extern uint32_t dword_12F3BC;
extern uint32_t off_12F3C0;
extern uint32_t dword_12F3C4;
extern uint32_t dword_12F3CC;
extern uint32_t off_12F3C8;
extern uint32_t dword_12F3D4;
extern uint32_t off_12F3D0;
extern uint32_t dword_12F3DC;
extern uint32_t off_12F3D8;
extern uint32_t dword_12F3E4;
extern uint32_t off_12F3E0;
extern uint32_t dword_12F3EC;
extern uint32_t off_12F3E8;

// weird_sp_sequence @ 0x12f180, size 468 bytes
// Doc: fmac_init_subsystems [mac]: Initializes FMAC subsystem registers and pointers
// fmac_init_subsystems [mac]: Initializes FMAC subsystem registers and pointers
int weird_sp_sequence()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r10
  uint32_t *v2; // r6
  uint32_t *v3; // r7
  uint32_t *v4; // r8
  uint32_t *v5; // r9
  uint32_t *v6; // r5
  int v7; // r2
  unsigned int v8; // r0
  int v9; // r3
  uint32_t *v10; // r7
  int v11; // r6
  uint32_t *v12; // r5
  int v13; // r4
  int v15; // nf
  uint32_t **v16; // r3

  v0 = off_12F35C;
  v1 = off_12F3F8;
  v2 = off_12F360;
  v3 = off_12F364;
  v4 = off_12F3FC;
  v5 = off_12F400;
  v6 = off_12F368;
  event_dispatch(dword_12F358, *(uint32_t *)off_12F354 & 0xF);
  event_dispatch(dword_12F370, *v0, *(uint32_t *)off_12F36C);
  event_dispatch(dword_12F374, *v1);
  event_dispatch(dword_12F378, *v2);
  event_dispatch(dword_12F37C, *v3);
  event_dispatch(dword_12F380, *v4);
  event_dispatch(dword_12F384, *v5);
  event_dispatch(dword_12F388, *v6);
  event_dispatch(
    dword_12F39C,
    *(uint32_t *)off_12F38C,
    *(uint32_t *)off_12F390,
    *(uint32_t *)off_12F394,
    *(uint32_t *)off_12F398,
    *(uint32_t *)off_12F404);
  event_dispatch(dword_12F3A0, *(uint32_t *)(*v2 + 60));
  event_dispatch(dword_12F3A4, *(uint32_t *)(*v3 + 60));
  event_dispatch(dword_12F3A8, *(uint32_t *)(*v4 + 60));
  event_dispatch(dword_12F3AC, *(uint32_t *)(*v5 + 60));
  event_dispatch(dword_12F3B0, *(uint32_t *)(*v6 + 60));
  v7 = *v0 << 6;
  if ( (*v0 & 0x2000000) != 0 )
  {
    v0 = (uint32_t *)*v6;
  }
  else if ( (*v0 & 0x200000) != 0 )
  {
    v0 = *(uint32_t **)off_12F3F0;
  }
  else if ( (*v0 & 0x20) != 0 )
  {
    v0 = (uint32_t *)*v2;
  }
  else if ( (*v0 & 0x200) != 0 )
  {
    v0 = (uint32_t *)*v3;
  }
  else if ( (*v0 & 0x2000) != 0 )
  {
    v0 = (uint32_t *)*v4;
  }
  else
  {
    v7 = *v0 << 14;
    if ( (*v0 & 0x20000) != 0 )
    {
      v0 = (uint32_t *)*v5;
    }
    else
    {
      v16 = (uint32_t **)(*v0 << 30);
      v15 = (*v0 & 2) != 0;
      if ( (*v0 & 2) != 0 )
        v16 = (uint32_t **)dword_12F3F4;
      else
        v0 = (uint32_t *)*v1;
      if ( v15 )
        v0 = *v16;
    }
  }
  if ( v0 )
  {
    send_msg((unsigned int)v0, 68, 1, 0);
    send_msg(v0[9], 52, 1, 0);
    event_dispatch(dword_12F3B4, v0[6]);
    v8 = v0[4];
    if ( v8 )
    {
      send_msg(v8, v0[5] + 1 - v8, 1, 0);
      v9 = v0[3];
      if ( !v9 )
        goto LABEL_6;
    }
    else
    {
      v9 = v0[3];
      if ( !v9 )
        goto LABEL_6;
    }
    send_msg(*(uint32_t *)(v9 + 8), *(uint32_t *)(v9 + 12) + 1 - *(uint32_t *)(v9 + 8), 1, 0);
  }
LABEL_6:
  v10 = off_12F3B8;
  v11 = dword_12F3BC;
  v12 = off_12F3C0;
  LOBYTE(v13) = 8;
  do
  {
    event_dispatch(v11, *v10, v7);
    event_dispatch(dword_12F3C4, *v12);
    v13 = (uint8_t)(v13 - 1);
  }
  while ( v13 );
  event_dispatch(dword_12F3CC, *(uint32_t *)off_12F3C8);
  event_dispatch(dword_12F3D4, *(uint32_t *)off_12F3D0);
  event_dispatch(dword_12F3DC, *(uint32_t *)off_12F3D8);
  event_dispatch(dword_12F3E4, *(uint32_t *)off_12F3E0);
  return event_dispatch(dword_12F3EC, *(uint32_t *)off_12F3E8);
}

