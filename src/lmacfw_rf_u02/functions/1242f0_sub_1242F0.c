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


extern uint32_t dword_1244D4;
extern uint32_t off_1244CC;
extern uint32_t off_1244D0;
extern uint32_t off_1244D8;
extern uint32_t off_1244DC;
extern uint32_t off_1244E0;
extern uint32_t off_1244E8;
extern uint32_t off_1244EC;
extern uint32_t off_1244F0;

// ke_handle_message @ 0x1242f0, size 476 bytes
int  ke_handle_message(unsigned int a1)
{
  int v2; // r7
  int v3; // r5
  int v4; // r0
  int result; // r0
  int v6; // r6
  int v7; // r5
  int v8; // r3
  int v9; // r2
  uint8_t *v10; // r3
  char v11; // r0
  char v12; // r1
  uint8_t *v13; // r1
  uint16_t v14; // r3
  uint16_t v15; // r2
  char *v16; // r7
  char v17; // r0
  volatile unsigned int v18; // r1
  uint16_t *v19; // r8
  unsigned int v20; // r4
  uint16_t v21; // r3
  char *v22; // r2
  char v23; // r1
  unsigned int v24; // r3
  char *v25; // r0
  uint16_t v26; // r2
  int v27; // cc
  char v28; // r3
  volatile unsigned int v29; // r3
  uint64_t v30; // [sp+0h] [bp-8h] BYREF

  if ( a1 == 128 )
  {
    v3 = 100;
    v2 = 10240;
  }
  else if ( a1 == 129 )
  {
    v3 = 500;
    v2 = 10244;
  }
  else
  {
    v2 = 10249;
    if ( a1 == 1 )
    {
      v3 = 2000;
    }
    else
    {
      v3 = 200;
      v2 = 10240;
    }
  }
  mac_time_get(&v30, 0);
  v4 = (uint8_t)v30;
  if ( (uint8_t)v30 )
    v4 = 1;
  result = (int)call_global_185c7c(v4, v3);
  v6 = result;
  if ( result )
  {
    v7 = *(uint32_t *)(result + 28);
    v8 = *off_1244D0;
    *(uint32_t *)(v7 + 48) = *(uint32_t *)off_1244CC;
    v9 = dword_1244D4;
    *(uint32_t *)(v7 + 64) = v2;
    *(uint32_t *)(v7 + 80) = v9;
    *(uint32_t *)(v7 + 52) = v8;
    if ( a1 == 128 )
    {
      build_hci_event(v7 + 104);
      v24 = *(uint8_t *)off_1244EC;
      v25 = off_1244E0[0];
      v26 = *(uint16_t *)off_1244DC;
      *(uint8_t *)(v7 + 128) = 0x80;
      v24 -= 2;
      v27 = v24 > 1;
      if ( v24 <= 1 )
        v23 = -106;
      v28 = *v25;
      *(uint8_t *)(v7 + 134) = v26;
      if ( v27 )
        v23 = -105;
      *(uint8_t *)(v7 + 132) = v23;
      *(uint8_t *)(v7 + 133) = v28;
      *(uint8_t *)(v7 + 135) = HIBYTE(v26);
      *(uint8_t *)(v7 + 129) = -64;
      *(uint8_t *)(v7 + 130) = -75;
      *(uint8_t *)(v7 + 131) = 122;
      *(uint8_t *)(v7 + 136) = -1;
      goto LABEL_14;
    }
    if ( a1 > 0x80 )
    {
      if ( a1 == 129 )
      {
        build_hci_event(v7 + 104);
        v13 = off_1244D8;
        v14 = *(uint16_t *)off_1244DC;
        v15 = *(uint16_t *)off_1244D8;
        v16 = off_1244E0[0];
        *(uint8_t *)(v7 + 130) = *(uint16_t *)off_1244DC;
        v17 = v13[5];
        *(uint8_t *)(v7 + 128) = -127;
        LOBYTE(v13) = *v16;
        *(uint8_t *)(v7 + 131) = HIBYTE(v14);
        *(uint16_t *)(v7 + 132) = v15;
        *(uint8_t *)(v7 + 134) = v17;
        *(uint8_t *)(v7 + 129) = (uint8_t)v13;
        *(uint8_t *)(v7 + 135) = -1;
        goto LABEL_14;
      }
    }
    else
    {
      if ( a1 == 1 )
      {
        v18 = REG_4032_0120;
        v19 = (uint16_t *)off_1244DC;
        v20 = *(uint32_t *)off_1244E8 - v18;
        if ( v20 <= 0x4E1F )
        {
          v29 = REG_4032_0120;
          v20 = (1000 - *(uint16_t *)off_1244DC)
              * ((v29 - *(uint32_t *)off_1244F0)
               / *(uint16_t *)off_1244DC)
              + 20000;
          *(uint32_t *)off_1244E8 = v29 + v20;
          dispatch_event_handler_1("txpwr_measure_time move %d\n", v20);
        }
        build_hci_command(v7 + 104);
        v21 = *v19;
        v22 = off_1244E0[0];
        *(uint8_t *)(v7 + 130) = *v19;
        LOBYTE(v22) = *v22;
        *(uint8_t *)(v7 + 131) = HIBYTE(v21);
        *(uint8_t *)(v7 + 132) = v20;
        *(uint8_t *)(v7 + 129) = (uint8_t)v22;
        *(uint8_t *)(v7 + 128) = 1;
        *(uint8_t *)(v7 + 133) = BYTE1(v20);
        *(uint8_t *)(v7 + 134) = BYTE2(v20);
        *(uint8_t *)(v7 + 135) = HIBYTE(v20);
        *(uint8_t *)(v7 + 136) = -1;
        goto LABEL_14;
      }
      if ( a1 == 2 )
      {
        build_hci_command(v7 + 104);
        v10 = off_1244D8;
        *(uint8_t *)(v7 + 128) = 2;
        v11 = v10[3];
        v12 = v10[4];
        *(uint8_t *)(v7 + 130) = v10[2];
        *(uint8_t *)(v7 + 131) = v11;
        *(uint8_t *)(v7 + 132) = v12;
        *(uint8_t *)(v7 + 129) = 1;
        *(uint8_t *)(v7 + 133) = -1;
LABEL_14:
        *(uint32_t *)(v6 + 44) = 0;
        *(uint32_t *)(v6 + 48) = 0;
        return wlan_tx_submit(v6, 0);
      }
    }
    build_hci_command(v7 + 104);
    *(uint8_t *)(v7 + 128) = 0;
    *(uint8_t *)(v7 + 129) = -1;
    goto LABEL_14;
  }
  return result;
}
