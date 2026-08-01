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

extern uint32_t dword_1418D4;
extern uint32_t dword_141A2C;

// ke_timer_set @ 0x1415f0, size 1082 bytes
int * ke_timer_set(int a1, int a2, int a3, int a4, char a5, char a6, char a7)
{
  int v7; // r7
  int v9; // r0
  int v10; // cc
  int *result; // r0
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r12
  int v18; // r5
  uint16_t v19; // r1
  uint16_t v20; // r2
  uint8_t *v21; // r8
  uint8_t *v22; // r4
  int v23; // r3
  char v24; // t1
  int v25; // r9
  int v26; // r11
  int v27; // r10
  int v28; // r6
  int v29; // r3
  unsigned int v30; // r4
  uint8_t *v31; // r1
  unsigned int v32; // r2
  int16_t v33; // r10
  unsigned int v34; // r3
  char v35; // r3
  uint8_t *v36; // r3
  int v37; // r1
  int v38; // r2
  int v39; // r2
  int v40; // zf
  int v41; // r2
  int v42; // r2
  int v43; // r2
  char v44; // r3
  int v45; // [sp+4h] [bp-28h]
  int v47; // [sp+18h] [bp-14h]
  int v48; // [sp+1Ch] [bp-10h]
  uint16_t v49; // [sp+20h] [bp-Ch] BYREF
  uint16_t v50; // [sp+22h] [bp-Ah]
  uint16_t v51; // [sp+24h] [bp-8h]

  v7 = dword_1418D4;
  v9 = *(uint32_t *)(dword_1418D4 + 6480);
  v49 = *(uint16_t *)(a1 + 16);
  v10 = v9 < 0;
  if ( v9 >= 0 )
    v9 *= 17;
  LOBYTE(v50) = *(uint8_t *)(a1 + 18);
  if ( !v10 )
    v9 = dword_1418D4 + 8 * v9;
  HIBYTE(v50) = *(uint8_t *)(a1 + 19);
  if ( !v10 )
    v7 = v9 + 6336;
  LOBYTE(v51) = *(uint8_t *)(a1 + 20);
  if ( v10 )
    v7 = 0;
  HIBYTE(v51) = *(uint8_t *)(a1 + 21);
  result = (int *)util_memcmp(&v49, 0, v7);
  if ( !result )
    return result;
  v14 = dword_1418D4;
  v15 = 0;
  v16 = dword_1418D4 + 6336;
  v17 = 0;
  v18 = 0;
  do
  {
    while ( 1 )
    {
      if ( *(uint16_t *)(v14 + 6) == v49 && *(uint16_t *)(v14 + 8) == v50 )
      {
        result = (int *)*(uint16_t *)(v14 + 10);
        if ( result == (int *)v51 )
        {
          v18 = v14;
          goto LABEL_25;
        }
      }
      result = (int *)*(uint16_t *)(v14 + 4);
      if ( result == (int *)1 )
      {
        if ( v17 )
        {
          result = (int *)*(char *)(v17 + 20);
          if ( *(char *)(v14 + 20) < (int)result )
            v17 = v14;
        }
        else
        {
          v17 = v14;
        }
        goto LABEL_15;
      }
      if ( result == (int *)3 )
      {
        if ( v15 )
        {
          result = (int *)*(char *)(v15 + 20);
          if ( *(char *)(v14 + 20) < (int)result )
            v15 = v14;
        }
        else
        {
          v15 = v14;
        }
        goto LABEL_15;
      }
      if ( !*(uint16_t *)(v14 + 4) )
        break;
LABEL_15:
      v14 += 528;
      if ( v14 == v16 )
        goto LABEL_23;
    }
    if ( !v18 )
      v18 = v14;
    v14 += 528;
  }
  while ( v14 != v16 );
LABEL_23:
  if ( v18 )
    goto LABEL_24;
  if ( v15 )
  {
    v18 = v15;
    goto LABEL_24;
  }
  if ( v17 && *(char *)(v17 + 20) < a6 )
  {
    v18 = v17;
LABEL_24:
    result = sub_100200((int *)v18, 0, 0x210u);
LABEL_25:
    if ( *(uint16_t *)(v18 + 4) != 3 )
    {
      v19 = v49;
      v20 = v50;
      *(uint32_t *)(v18 + 12) = a3;
      *(uint16_t *)(v18 + 10) = v51;
      if ( a5 )
        result = (int *)4;
      else
        result = (int *)5;
      v21 = (uint8_t *)(a1 + 36);
      *(uint8_t *)(v18 + 17) = a7;
      *(uint8_t *)(v18 + 18) = (uint8_t)result;
      *(uint16_t *)(v18 + 6) = v19;
      *(uint16_t *)(v18 + 8) = v20;
      v22 = (uint8_t *)(a1 + 24);
      v23 = v18 + 63;
      do
      {
        v24 = *v22++;
        *(uint8_t *)++v23 = v24;
      }
      while ( v22 != v21 );
      v25 = a2 - 36;
      v26 = v18 + 76;
      v47 = 0;
      v48 = 0;
      if ( a2 - 36 > 2 )
      {
        v27 = 452;
        while ( 1 )
        {
          v28 = *v21;
          v29 = v21[2];
          v30 = v21[1] + 2;
          v31 = v21 + 2;
          if ( *v21 )
          {
            if ( v28 == 3 )
            {
              *(uint8_t *)(v18 + 21) = v26 - (v18 + 64);
              *(uint8_t *)(v18 + 16) = *v31;
            }
            else
            {
              v32 = *(uint8_t *)(v18 + 18);
              if ( v32 > 5 )
              {
                if ( v32 == 6 )
                {
LABEL_37:
                  if ( v28 == 61 )
                  {
                    if ( v21[1] == 22 )
                    {
                      *(uint8_t *)(v18 + 18) = 7;
                      v48 = v21[3] & 3;
                      v38 = v47;
                      if ( (v21[3] & 3) != 0 )
                        v38 = 1;
                      v47 = v38;
                    }
                    goto LABEL_41;
                  }
LABEL_38:
                  if ( v28 == 192 )
                  {
                    if ( v21[1] == 5 )
                    {
                      *(uint8_t *)(v18 + 18) = 9;
                      v39 = (uint8_t)*v31;
                      if ( *v31 )
                      {
                        if ( v39 == 1 )
                        {
                          v47 = 2;
                        }
                        else if ( v39 == 2 )
                        {
                          v47 = 3;
                        }
                        else
                        {
                          v40 = v39 == 3;
                          v41 = v47;
                          if ( v40 )
                            v41 = 4;
                          v47 = v41;
                        }
                      }
                    }
                    goto LABEL_41;
                  }
LABEL_39:
                  if ( v28 == 255 && v30 > 8 && v29 == 36 )
                  {
                    if ( v32 != 9 && v30 > 0xB && (*(uint32_t *)(v21 + 3) & 0x4000) != 0 )
                    {
                      v42 = v21[9];
                      if ( v21[9] )
                      {
                        if ( v42 == 1 )
                        {
                          v47 = 2;
                        }
                        else if ( v42 == 2 )
                        {
                          v47 = 3;
                        }
                        else
                        {
                          v40 = v42 == 3;
                          v43 = v47;
                          if ( v40 )
                            v43 = 4;
                          v47 = v43;
                        }
                      }
                    }
                    *(uint8_t *)(v18 + 18) = 14;
                  }
                  goto LABEL_41;
                }
                if ( v32 <= 8 )
                  goto LABEL_38;
                if ( v32 <= 0xD )
                  goto LABEL_39;
              }
              else
              {
                if ( v28 != 42 )
                  goto LABEL_37;
                *(uint8_t *)(v18 + 18) = 6;
              }
            }
          }
          else
          {
            v45 = v21[2];
            memcpy(v18 + 28, v21, v21[1] + 2);
            result = (int *)util_memcmp((uint16_t *)(v18 + 6), (int)v21, v7);
            v29 = v45;
            if ( !result )
            {
              *(uint16_t *)(v18 + 4) = 0;
              return result;
            }
          }
LABEL_41:
          if ( (int)v30 <= v27 && (result = (int *)find_ll_item(v28, v29, v7)) != 0 )
          {
            v36 = v21;
            v37 = v26 - (uint32_t)v21;
            v21 += v30;
            do
            {
              v36[v37] = *v36;
              ++v36;
            }
            while ( v21 != v36 );
            v26 += v30;
            v27 -= v30;
          }
          else
          {
            v21 += v30;
          }
          v25 -= v30;
          if ( v25 <= 2 )
          {
            v33 = 464 - v27;
            goto LABEL_46;
          }
        }
      }
      v33 = 12;
LABEL_46:
      v34 = *(uint8_t *)(v18 + 21);
      *(uint16_t *)(v18 + 26) = v33;
      if ( v34 )
      {
        *(uint8_t *)(v18 + 20) = a6;
        v34 = *(uint8_t *)(v18 + 16);
        goto LABEL_48;
      }
      if ( *(uint16_t *)(v18 + 4) && *(char *)(v18 + 20) >= a6 )
      {
        v34 = *(uint8_t *)(v18 + 16);
      }
      else
      {
        *(uint8_t *)(v18 + 20) = a6;
        if ( a5 )
        {
          if ( a5 != 1 || (uint16_t)(a4 - 5005) > 0x370u )
            goto LABEL_96;
          v34 = (uint8_t)((unsigned int)(((unsigned int)dword_141A2C
                                                * (unsigned uint64_t)(unsigned int)(a4 - 5000)) >> 32) >> 2);
          *(uint8_t *)(v18 + 16) = v34;
        }
        else if ( (unsigned int)(a4 - 2412) > 0x48 )
        {
          v34 = 0;
          *(uint8_t *)(v18 + 16) = 0;
        }
        else
        {
          if ( a4 != 2484 )
          {
            v34 = (uint8_t)((unsigned int)(((unsigned int)dword_141A2C
                                                  * (unsigned uint64_t)(unsigned int)(a4 - 2407)) >> 32) >> 2);
LABEL_96:
            *(uint8_t *)(v18 + 16) = v34;
            goto LABEL_48;
          }
          v34 = 14;
          *(uint8_t *)(v18 + 16) = 14;
        }
      }
LABEL_48:
      if ( v47 != 4 )
      {
        if ( v47 == 3 )
        {
          v35 = -127;
          goto LABEL_57;
        }
        if ( v47 == 2 )
        {
          v35 = 0x80;
          goto LABEL_57;
        }
        if ( !a5 )
        {
          if ( v34 == 14 )
          {
            v35 = 82;
          }
          else if ( v47 )
          {
            if ( v48 == 1 )
              v35 = 84;
            else
              v35 = 83;
          }
          else
          {
            v35 = 81;
          }
          goto LABEL_57;
        }
        if ( v34 <= 0x30 )
        {
          if ( !v47 )
          {
            v35 = 115;
            goto LABEL_57;
          }
          v44 = 0;
        }
        else if ( v34 <= 0x40 )
        {
          if ( !v47 )
          {
            v35 = 118;
            goto LABEL_57;
          }
          v44 = 3;
        }
        else
        {
          if ( v34 > 0x90 )
          {
            if ( v34 <= 0xA4 )
            {
              if ( v47 )
                goto LABEL_115;
              v35 = 124;
            }
            else
            {
              if ( v47 )
              {
LABEL_115:
                v44 = 10;
                goto LABEL_116;
              }
              v35 = 125;
            }
LABEL_57:
            *(uint8_t *)(v18 + 19) = v35;
            *(uint16_t *)(v18 + 4) = 1;
            return result;
          }
          if ( !v47 )
          {
            v35 = 121;
            goto LABEL_57;
          }
          v44 = 6;
        }
LABEL_116:
        if ( v48 == 1 )
          v35 = v44 + 116;
        else
          v35 = v44 + 117;
        goto LABEL_57;
      }
      v35 = -126;
      goto LABEL_57;
    }
  }
  return result;
}

