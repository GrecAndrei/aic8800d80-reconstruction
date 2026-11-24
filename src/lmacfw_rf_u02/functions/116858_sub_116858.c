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


extern uint32_t dword_116B38;
extern uint32_t dword_116B40;
extern uint32_t dword_116B48;
extern uint32_t dword_116B4C;
extern uint32_t dword_116B50;
extern uint32_t dword_116B54;
extern uint32_t dword_116B58;
extern uint32_t dword_116B5C;
extern uint32_t dword_116B60;
extern uint32_t dword_116B64;
extern uint32_t dword_116B6C;
extern uint32_t dword_116B70;
extern uint32_t dword_116B80;
extern uint32_t dword_116B88;
extern uint32_t dword_116B8C;
extern uint32_t dword_116C28;
extern uint32_t dword_116C2C;
extern uint32_t dword_116C30;
extern uint32_t dword_116C34;
extern uint32_t dword_116C38;

// sub_116858 @ 0x116858, size 974 bytes
int  sub_116858(int a1)
{
  uint16_t **v1; // r7
  int v2; // r5
  int v3; // r1
  uint16_t *v5; // r0
  uint16_t v6; // r8
  unsigned int v7; // r3
  int v9; // r6
  unsigned int v10; // r2
  int v11; // r5
  int v12; // r9
  unsigned int v13; // r3
  unsigned int v14; // r2
  int v15; // r2
  int v16; // r11
  int v17; // r8
  uint32_t *v18; // r2
  uint32_t *v19; // r8
  uint32_t *v20; // r4
  volatile unsigned int v21; // r6
  unsigned int v22; // r3
  volatile unsigned int v23; // r6
  uint32_t *v24; // r11
  uint32_t *v25; // r10
  int v26; // r4
  unsigned int v27; // r9
  int v28; // r4
  int v29; // r0
  uint64_t v30; // r0
  uint64_t v31; // r6
  uint64_t v32; // r0
  uint64_t v33; // r0
  uint64_t v34; // r0
  int v35; // r0
  int v36; // r11
  uint32_t *v37; // r4
  int v38; // r1
  unsigned int v39; // r3
  int v40; // r3
  int v41; // r2
  uint32_t *v42; // r4
  int v43; // r2
  unsigned int v44; // r3
  int v45; // [sp+4h] [bp-10h]
  uint8_t *a4; // [sp+Ch] [bp-8h] BYREF

  if ( *(uint16_t *)(a1 + 48) )
  {
    v1 = (uint16_t **)dword_116B48;
    v2 = *(uint32_t *)(a1 + 28);
    v3 = **(uint16_t **)dword_116B48;
    if ( v3 < 0 && !v2 )
    {
      sub_121960((int)aRhdFirstPbdPtr, (int)aRxlFrameHandle, 423);
      return v2;
    }
    v5 = *(uint16_t **)(v2 + 8);
    v6 = *v5;
    v7 = *(uint32_t *)(a1 + 84);
    if ( *(uint8_t *)(dword_116B4C + 0x198)
      && (*(uint32_t *)(dword_116B50 + 4) & 0x40) != 0
      && (*(uint32_t *)(a1 + 84) & 0x600) == 0x200 )
    {
      if ( (v6 & 0xFC) == 0xC4 )
        ++*(uint32_t *)dword_116B80;
    }
    else
    {
      if ( (dword_116B54 & ~v7) != 0 )
        return 0;
      *(uint32_t *)(a1 + 84) = v7 & 0xFEFFFFFF;
      if ( v3 < 0 )
      {
        v2 = (v7 >> 15) & 0x1F0;
        if ( !v2 )
        {
          sub_121960((int)aKeyIdxHwMmSecD, (int)aRxlFrameHandle, 475);
          return v2;
        }
      }
      v9 = (uint8_t)((v7 >> 15) - 16);
      v10 = dword_116B58 + 152 * v9;
      v2 = *(uint8_t *)(v10 + 35);
      if ( !*(uint8_t *)(v10 + 35) )
      {
        *(uint32_t *)(a1 + 84) = v7 & 0xFCFFFFFF;
        return v2;
      }
      if ( *(uint16_t *)(v10 + 30) == 0xFFFF )
      {
        if ( (v6 & 0xFC) != 0x80 )
        {
          *(uint32_t *)(a1 + 84) = v7 & 0xFCFFFFFF;
          return 0;
        }
        v11 = *(uint32_t *)(v10 + 44);
        *(uint32_t *)(a1 + 84) = v7 & 0xFE007FFF | ((*(uint8_t *)(v11 + 33) + 16) << 15);
      }
      else
      {
        v11 = dword_116B58 + 152 * v9;
      }
      v12 = *(uint8_t *)(v11 + 32);
      v13 = dword_116B5C;
      v14 = dword_116B5C + 224 * v12;
      if ( !*(uint8_t *)(v14 + 96) )
        return 0;
      v15 = *(uint8_t *)(v14 + 94);
      v16 = 224 * v12;
      if ( v15 )
      {
        if ( (v6 & 4) != 0 )
          goto LABEL_44;
        goto LABEL_42;
      }
      if ( (v6 & 0x300) != 0x200 )
      {
        if ( (v6 & 4) != 0 )
        {
LABEL_17:
          v17 = v6 & 0xFC;
          if ( v17 == 128 )
          {
            v36 = v16 + v13;
            a4 = nullptr;
            v2 = !sub_119218(a1 + 20, v36, v11, &a4);
            sub_118324(v36);
            return v2;
          }
          if ( v17 == 80 )
          {
            v18 = (uint32_t *)dword_116B60;
            v45 = *(uint32_t *)dword_116B60 & 0xF;
            if ( v45 )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(uint32_t *)dword_116B64 = 1;
              }
              v19 = (uint32_t *)dword_116B8C;
              v20 = (uint32_t *)dword_116B60;
              ++*(uint32_t *)dword_116B8C;
              *v20 = 0;
              v21 = (*(volatile uint32_t *)0x40501010u);
              while ( 1 )
              {
                v2 = *v20 & 0xF;
                if ( !v2 )
                  break;
                v22 = (*(volatile uint32_t *)0x40501010u) - v21;
                if ( v22 > 0x7530 )
                  sub_11F74C(2, aIdleErr, 30000);
              }
              v23 = (*(volatile uint32_t *)0x40501010u);
              if ( (*(uint32_t *)dword_116B70 & *(uint32_t *)dword_116B6C & 4) == 0 )
              {
                v24 = (uint32_t *)dword_116B6C;
                v25 = (uint32_t *)dword_116B70;
                do
                {
                  v26 = *v25 & *v24;
                  if ( (*(volatile uint32_t *)0x40501010u) - v23 > 0x7530 )
                    sub_11F74C(2, aIdleIntErr);
                }
                while ( (v26 & 4) == 0 );
              }
              *(uint32_t *)dword_116C28 = 4;
              if ( *v19 )
              {
                v40 = *v19 - 1;
                v41 = *(uint32_t *)dword_116C2C;
                *v19 = v40;
                if ( !v40 )
                {
                  if ( v41 )
                    __enable_irq();
                }
              }
              v42 = (uint32_t *)dword_116C30;
              v43 = **v1;
              v44 = *(uint32_t *)(dword_116C30 + 4) & 0xFFFFFDFF;
              *(uint32_t *)(dword_116C30 + 4) = v44;
              if ( v43 < 0 )
              {
                if ( *(uint32_t *)dword_116C38 << 28 )
                {
                  sub_1219F4((int)aNxmacCurrentSt, (int)aMmRxFilterSet_2, 472);
                  v44 = v42[1];
                }
              }
              *(uint32_t *)dword_116C34 = v44 | *v42;
              *(uint32_t *)dword_116C38 = 16 * v45;
              return v2;
            }
            v37 = (uint32_t *)dword_116B50;
            v38 = **v1;
            v39 = *(uint32_t *)(dword_116B50 + 4) & 0xFFFFFDFF;
            *(uint32_t *)(dword_116B50 + 4) = v39;
            if ( v38 >= 0 )
            {
              v2 = 0;
              *(uint32_t *)dword_116B88 = v39 | *v37;
              return v2;
            }
            v2 = *v18 & 0xF;
            if ( !v2 )
            {
              *(uint32_t *)dword_116C34 = v39 | *v37;
              return v2;
            }
            sub_1219F4((int)aNxmacCurrentSt, (int)aMmRxFilterSet_2, 472);
            *(uint32_t *)dword_116C34 = v37[1] | *v37;
          }
          return 0;
        }
        goto LABEL_42;
      }
      v35 = sub_128288((unsigned int)(v5 + 8), v16 + 88 + dword_116B5C, 6u);
      v13 = dword_116B5C;
      if ( v35 )
      {
        if ( (v6 & 4) != 0 )
        {
LABEL_43:
          v27 = v13 + 224 * v12;
          v15 = *(uint8_t *)(v27 + 94);
          if ( !*(uint8_t *)(v27 + 94) )
            goto LABEL_17;
LABEL_44:
          if ( v15 == 2 && *(uint8_t *)(v11 + 33) <= 3u )
          {
            v28 = *(char *)(a1 + 65);
            sub_101AB0();
            v29 = *(char *)(v11 + 145);
            if ( !*(uint8_t *)(v11 + 145) )
            {
              *(uint8_t *)(v11 + 145) = v28;
              return v29;
            }
            v30 = sub_12754C(v29);
            v31 = sub_127620(v30, *(uint64_t *)&dword_116B38);
            v32 = sub_12754C(v28);
            v33 = sub_127620(v32, *(uint64_t *)&dword_116B40);
            v34 = sub_1272B4(v31, v33);
            *(uint8_t *)(v11 + 145) = sub_127B54(v34);
          }
          return 0;
        }
LABEL_42:
        sub_11C834(*(uint8_t *)(v13 + 224 * v12 + 95), v9, 1);
        v13 = dword_116B5C;
        goto LABEL_43;
      }
    }
  }
  return 1;
}
