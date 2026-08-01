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

extern uint32_t off_1218B4;
extern uint32_t off_121950;
extern uint32_t off_1218B8;
extern uint32_t off_1218BC;
extern uint32_t off_121954;
extern uint32_t off_121958;
extern uint32_t off_1218C0;
extern uint32_t dword_1218B0;
extern uint32_t off_1218AC;
extern uint32_t dword_1218C8;
extern uint32_t off_1218C4;
extern uint32_t dword_1218CC;
extern uint32_t dword_1218D0;
extern uint32_t dword_1218D4;
extern uint32_t dword_1218D8;
extern uint32_t dword_1218DC;
extern uint32_t dword_1218E0;
extern uint32_t dword_1218F4;
extern uint32_t off_1218E4;
extern uint32_t off_1218E8;
extern uint32_t off_1218EC;
extern uint32_t off_1218F0;
extern uint32_t off_12195C;
extern uint32_t dword_1218F8;
extern uint32_t dword_1218FC;
extern uint32_t dword_121900;
extern uint32_t dword_121904;
extern uint32_t dword_121908;
extern uint32_t off_121948;
extern uint32_t dword_12194C;
extern uint32_t dword_12190C;
extern uint32_t off_121910;
extern uint32_t dword_121914;
extern uint32_t off_121918;
extern uint32_t dword_12191C;
extern uint32_t dword_121924;
extern uint32_t off_121920;
extern uint32_t dword_12192C;
extern uint32_t off_121928;
extern uint32_t dword_121934;
extern uint32_t off_121930;
extern uint32_t dword_12193C;
extern uint32_t off_121938;
extern uint32_t dword_121944;
extern uint32_t off_121940;

// rf_init_phy @ 0x1216ec, size 448 bytes
int rf_init_phy()
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

  v0 = off_1218B4;
  v1 = off_121950;
  v2 = off_1218B8;
  v3 = off_1218BC;
  v4 = off_121954;
  v5 = off_121958;
  v6 = off_1218C0;
  dispatch_event_handler(dword_1218B0, *(uint32_t *)off_1218AC & 0xF);
  dispatch_event_handler(dword_1218C8, *v0, *(uint32_t *)off_1218C4);
  dispatch_event_handler(dword_1218CC, *v1);
  dispatch_event_handler(dword_1218D0, *v2);
  dispatch_event_handler(dword_1218D4, *v3);
  dispatch_event_handler(dword_1218D8, *v4);
  dispatch_event_handler(dword_1218DC, *v5);
  dispatch_event_handler(dword_1218E0, *v6);
  dispatch_event_handler(
    dword_1218F4,
    *(uint32_t *)off_1218E4,
    *(uint32_t *)off_1218E8,
    *(uint32_t *)off_1218EC,
    *(uint32_t *)off_1218F0,
    *(uint32_t *)off_12195C);
  dispatch_event_handler(dword_1218F8, *(uint32_t *)(*v2 + 60));
  dispatch_event_handler(dword_1218FC, *(uint32_t *)(*v3 + 60));
  dispatch_event_handler(dword_121900, *(uint32_t *)(*v4 + 60));
  dispatch_event_handler(dword_121904, *(uint32_t *)(*v5 + 60));
  dispatch_event_handler(dword_121908, *(uint32_t *)(*v6 + 60));
  v7 = *v0 << 6;
  if ( (*v0 & 0x2000000) != 0 )
  {
    v0 = (uint32_t *)*v6;
  }
  else if ( (*v0 & 0x200000) != 0 )
  {
    v0 = *(uint32_t **)off_121948;
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
        v16 = (uint32_t **)dword_12194C;
      else
        v0 = (uint32_t *)*v1;
      if ( v15 )
        v0 = *v16;
    }
  }
  if ( v0 )
  {
    handle_ipc_request((unsigned int)v0, 68, 1, 0);
    handle_ipc_request(v0[9], 52, 1, 0);
    dispatch_event_handler(dword_12190C, v0[6]);
    v8 = v0[4];
    if ( v8 )
    {
      handle_ipc_request(v8, v0[5] + 1 - v8, 1, 0);
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
    handle_ipc_request(*(uint32_t *)(v9 + 8), *(uint32_t *)(v9 + 12) + 1 - *(uint32_t *)(v9 + 8), 1, 0);
  }
LABEL_6:
  v10 = off_121910;
  v11 = dword_121914;
  v12 = off_121918;
  LOBYTE(v13) = 8;
  do
  {
    dispatch_event_handler(v11, *v10, v7);
    dispatch_event_handler(dword_12191C, *v12);
    v13 = (uint8_t)(v13 - 1);
  }
  while ( v13 );
  dispatch_event_handler(dword_121924, *(uint32_t *)off_121920);
  dispatch_event_handler(dword_12192C, *(uint32_t *)off_121928);
  dispatch_event_handler(dword_121934, *(uint32_t *)off_121930);
  dispatch_event_handler(dword_12193C, *(uint32_t *)off_121938);
  return dispatch_event_handler(dword_121944, *(uint32_t *)off_121940);
}

