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


extern uint32_t off_13DCA4;
extern uint32_t off_13DCA8;
extern uint32_t off_13DCAC;
extern uint32_t off_13DCB0;
extern uint32_t off_13DCB4;
extern uint32_t off_13DCB8;
extern uint32_t off_13DCBC;
extern uint32_t off_13DCC0;
extern uint32_t off_13DCC4;
extern uint32_t off_13DFCC;
extern uint32_t off_13DFD0;
extern uint32_t off_13DFD4;
extern uint32_t off_13DFD8;
extern uint32_t off_13DFDC;
extern uint32_t off_13DFE0;
extern uint32_t off_13DFE4;
extern uint32_t off_13DFE8;
extern uint32_t off_13DFEC;
extern uint32_t off_13DFF0;
extern uint32_t off_13DFF4;
extern uint32_t off_13DFF8;
extern uint32_t off_13DFFC;
extern uint32_t off_13E000;
extern uint32_t off_13E004;
extern uint32_t off_13E008;
extern uint32_t off_13E00C;
extern uint32_t off_13E010;
extern uint32_t off_13E014;
extern uint32_t off_13E018;
extern uint32_t off_13E01C;
extern uint32_t off_13E07C;
extern uint32_t off_13E080;
extern uint32_t off_13E084;
extern uint32_t off_13E088;
extern uint32_t off_13E08C;

// sub_13D950 @ 0x13d950, size 1834 bytes
int  sub_13D950(int a1, int a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r2
  int v5; // r8
  int result; // r0
  int v7; // r3
  unsigned int v8; // r10
  unsigned int v9; // r11
  unsigned int v10; // r9
  unsigned int v11; // r6
  unsigned int v12; // r4
  uint16_t **v13; // r7
  int v14; // r1
  int v15; // r4
  char *v16; // r1
  char *v17; // r0
  int v18; // r2
  int v19; // r3
  char v20; // [sp+0h] [bp-Ch]
  int v21; // [sp+4h] [bp-8h]
  int v22; // [sp+4h] [bp-8h]
  int v23; // [sp+4h] [bp-8h]
  int v24; // [sp+4h] [bp-8h]
  int v25; // [sp+4h] [bp-8h]
  int v26; // [sp+4h] [bp-8h]
  int v27; // [sp+4h] [bp-8h]

  v2 = *(uint16_t *)(a1 + 12 * a2 + 10);
  v3 = v2 >> 11;
  v5 = (v2 >> 11) & 7;
  result = (v2 >> 11) & 4;
  v7 = (v2 >> 10) & 1;
  v8 = v2 >> 9;
  v9 = (v2 >> 9) & 1;
  v20 = v2 >> 7;
  v10 = (v2 >> 7) & 3;
  if ( result )
  {
    v11 = (v2 >> 4) & 7;
    v12 = v2 & 0xF;
LABEL_3:
    v13 = (uint16_t **)off_13DCA4;
    v14 = **(uint16_t **)off_13DCA4;
    switch ( *(uint8_t *)(a1 + 169) )
    {
      case 0:
      case 1:
        goto LABEL_18;
      case 2:
      case 3:
        goto LABEL_15;
      case 4:
        goto LABEL_7;
      case 5:
        goto LABEL_32;
      default:
        goto LABEL_12;
    }
  }
  v11 = (v2 >> 11) & 6;
  if ( (v3 & 6) == 0 )
  {
    v12 = v2 & 0x7F;
    goto LABEL_3;
  }
  v13 = (uint16_t **)off_13DCA4;
  v11 = (v2 >> 3) & 3;
  v14 = **(uint16_t **)off_13DCA4;
  v12 = v2 & 7;
  switch ( *(uint8_t *)(a1 + 169) )
  {
    case 0:
    case 1:
LABEL_18:
      if ( v14 >= 0 )
        goto LABEL_17;
      if ( (v3 & 6) == 0 )
        goto LABEL_20;
      v26 = v7;
      result = sub_12F32C(off_13E018[0], off_13DFCC[0], 614);
      v7 = v26;
      goto LABEL_12;
    case 2:
    case 3:
LABEL_15:
      if ( *(uint8_t *)(a1 + 177) > 3u )
      {
        if ( v14 >= 0 )
          goto LABEL_17;
        if ( (unsigned int)(v5 - 2) > 1 )
        {
          v22 = v7;
          result = sub_12F32C(off_13DFD0[0], off_13DFCC[0], 626);
          v7 = v22;
          goto LABEL_12;
        }
LABEL_72:
        if ( !v7 || (result = sub_12F32C(off_13DFF0[0], off_13DFCC[0], 692), **v13 < 0) )
        {
          if ( *(uint8_t *)(a1 + 181) >= v9
            || (result = sub_12F32C(off_13DFEC[0], off_13DFCC[0], 693), **v13 < 0) )
          {
            if ( *(uint8_t *)(a1 + 179) >= v10
              || (result = sub_12F32C(off_13DFE8[0], off_13DFCC[0], 694), **v13 < 0) )
            {
              if ( *(uint8_t *)(a1 + 180) >= v11
                || (result = sub_12F32C(off_13DFE4[0], off_13DFCC[0], 695), **v13 < 0) )
              {
                if ( *(uint8_t *)(a1 + 176) >= v12
                  || (result = sub_12F32C(off_13DFE0[0], off_13DFCC[0], 696), **v13 < 0) )
                {
                  if ( ((*(uint8_t *)(a1 + v11 + 170) >> v12) & 1) == 0 )
                  {
                    v16 = off_13DCA8[0];
                    v17 = off_13DCC4;
                    v18 = 697;
                    return sub_12F32C(v17, v16, v18);
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        if ( v14 >= 0 )
          goto LABEL_17;
        if ( result )
        {
          v25 = v7;
          result = sub_12F32C(off_13E014[0], off_13DFCC[0], 622);
          v7 = v25;
          goto LABEL_12;
        }
LABEL_20:
        switch ( v5 )
        {
          case 0:
          case 1:
            goto LABEL_22;
          case 2:
          case 3:
            goto LABEL_72;
          case 4:
            goto LABEL_58;
          case 5:
            goto LABEL_42;
          case 7:
            goto LABEL_49;
          default:
            return result;
        }
      }
      return result;
    case 4:
LABEL_7:
      if ( *(uint8_t *)(a1 + 177) > 3u )
      {
        if ( v14 >= 0 )
          goto LABEL_17;
        if ( v5 != 4 )
        {
          v24 = v7;
          result = sub_12F32C(off_13DFD8[0], off_13DFCC[0], 640);
          v7 = v24;
          goto LABEL_12;
        }
      }
      else
      {
        if ( v14 >= 0 )
          goto LABEL_17;
        if ( v5 != 4 )
        {
          if ( !v5 )
            goto LABEL_37;
          v21 = v7;
          result = sub_12F32C(off_13DCAC[0], off_13DCA8[0], 636);
          v7 = v21;
          goto LABEL_12;
        }
      }
LABEL_58:
      if ( v7 )
      {
        result = sub_12F32C(off_13DFF0[0], off_13DFCC[0], 704);
        if ( **v13 >= 0 )
          return result;
      }
      if ( *(uint8_t *)(a1 + 181) < v9 )
      {
        result = sub_12F32C(off_13DFEC[0], off_13DFCC[0], 705);
        if ( **v13 >= 0 )
          return result;
      }
      if ( *(uint8_t *)(a1 + 179) < v10 )
      {
        result = sub_12F32C(off_13DFE8[0], off_13DFCC[0], 706);
        if ( **v13 >= 0 )
          return result;
      }
      if ( *(uint8_t *)(a1 + 180) < v11 )
      {
        result = sub_12F32C(off_13DFE4[0], off_13DFCC[0], 707);
        if ( **v13 >= 0 )
          return result;
      }
      if ( *(uint8_t *)(a1 + 176) < v12 )
      {
        result = sub_12F32C(off_13DFE0[0], off_13DFCC[0], 708);
        if ( **v13 >= 0 )
          return result;
      }
      if ( (int)v12 > (((int)*(uint16_t *)(a1 + 170) >> (2 * v11)) & 3) + 7 )
      {
        result = sub_12F32C(off_13DFF4[0], off_13DFCC[0], 709);
        if ( **v13 >= 0 )
          return result;
      }
      if ( v12 == 6 )
      {
        if ( v10 == 2 && (v11 == 3 || v11 == 6) )
        {
          v16 = off_13DFCC[0];
          v17 = off_13DFDC[0];
          v18 = 710;
          return sub_12F32C(v17, v16, v18);
        }
        return result;
      }
      if ( v12 != 9 )
        return result;
      if ( !v10 )
      {
        if ( v11 != 2 && v11 != 5 )
        {
          v16 = off_13DCA8[0];
          v17 = off_13DCC0[0];
          v18 = 711;
          return sub_12F32C(v17, v16, v18);
        }
        return result;
      }
      if ( v10 == 2 )
      {
        if ( v11 != 5 )
          return result;
        v16 = off_13E07C[0];
        v17 = off_13E084[0];
        v18 = 712;
        return sub_12F32C(v17, v16, v18);
      }
      if ( v10 == 3 && v11 == 2 )
      {
        v16 = off_13E07C[0];
        v17 = off_13E088[0];
        v18 = 713;
        return sub_12F32C(v17, v16, v18);
      }
      return result;
    case 5:
LABEL_32:
      if ( *(uint8_t *)(a1 + 177) <= 3u )
      {
        if ( v14 < 0 )
        {
          if ( v5 != 5 )
          {
            if ( v5 != 7 )
            {
              if ( !v5 )
              {
LABEL_37:
                if ( v12 > 3 )
                  goto LABEL_25;
                if ( *(uint8_t *)(a1 + 182) == 1 )
                {
LABEL_39:
                  if ( v7 )
                    goto LABEL_25;
                  result = sub_12F32C(off_13DCB4[0], off_13DCA8[0], 674);
                  v14 = **v13;
                }
LABEL_24:
                if ( v14 >= 0 )
                  return result;
LABEL_25:
                if ( v9 )
                {
                  result = sub_12F32C(off_13E010[0], off_13DFCC[0], 680);
                  if ( **v13 >= 0 )
                    return result;
                  if ( !v10 )
                  {
LABEL_27:
                    if ( !v11 )
                    {
LABEL_28:
                      if ( *(uint8_t *)(a1 + 177) <= v12
                        || (result = sub_12F32C(off_13E004[0], off_13DFCC[0], 683), **v13 < 0) )
                      {
                        if ( *(uint8_t *)(a1 + 178) >= v12
                          || (result = sub_12F32C(off_13E000[0], off_13DFCC[0], 684), **v13 < 0) )
                        {
                          v15 = *(uint16_t *)(a1 + 174) >> v12;
                          result = v15 << 31;
                          if ( (v15 & 1) == 0 )
                          {
                            v16 = off_13DCA8[0];
                            v17 = off_13DCB0[0];
                            v18 = 685;
                            return sub_12F32C(v17, v16, v18);
                          }
                        }
                      }
                      return result;
                    }
LABEL_132:
                    result = sub_12F32C(off_13E008[0], off_13DFCC[0], 682);
                    if ( **v13 >= 0 )
                      return result;
                    goto LABEL_28;
                  }
                }
                else if ( !v10 )
                {
                  goto LABEL_27;
                }
                result = sub_12F32C(off_13E00C[0], off_13DFCC[0], 681);
                if ( **v13 >= 0 )
                  return result;
                if ( !v11 )
                  goto LABEL_28;
                goto LABEL_132;
              }
              v27 = v7;
              result = sub_12F32C(off_13E08C, off_13E07C[0], 651);
              v7 = v27;
LABEL_12:
              switch ( v5 )
              {
                case 0:
                case 1:
                  goto LABEL_21;
                case 2:
                case 3:
                  goto LABEL_71;
                case 4:
                  goto LABEL_13;
                case 5:
                  goto LABEL_41;
                case 7:
                  goto LABEL_48;
                default:
                  return result;
              }
              return result;
            }
            goto LABEL_50;
          }
          goto LABEL_42;
        }
LABEL_17:
        switch ( v5 )
        {
          case 0:
          case 1:
LABEL_21:
            v14 = **v13;
LABEL_22:
            if ( v12 > 3 || *(uint8_t *)(a1 + 182) != 1 )
              goto LABEL_24;
            if ( v14 < 0 )
              goto LABEL_39;
            break;
          case 4:
LABEL_13:
            if ( **v13 < 0 )
              goto LABEL_58;
            break;
          case 5:
LABEL_41:
            if ( **v13 < 0 )
              goto LABEL_42;
            break;
          case 7:
LABEL_48:
            v14 = **v13;
LABEL_49:
            if ( v14 < 0 )
              goto LABEL_50;
            break;
          default:
            return result;
        }
        return result;
      }
      if ( v14 >= 0 )
        goto LABEL_17;
      v23 = v7;
      if ( v5 != 5 )
      {
        if ( v5 != 7 )
        {
          result = sub_12F32C(off_13DFD4[0], off_13DFCC[0], 657);
          v7 = v23;
          goto LABEL_12;
        }
LABEL_50:
        if ( (v8 & 3) == 3 )
        {
          result = sub_12F32C(off_13E01C, off_13DFCC[0], 732);
          if ( **v13 >= 0 )
            return result;
        }
        if ( (v20 & 2) != 0 )
        {
          result = sub_12F32C(off_13DFFC[0], off_13DFCC[0], 733);
          if ( **v13 >= 0 )
            return result;
          if ( !v11 )
            goto LABEL_53;
        }
        else if ( !v11 )
        {
LABEL_53:
          if ( v10 )
            v19 = 0;
          else
            v19 = 2;
          if ( (int)v12 > v19 )
          {
            v16 = off_13DCA8[0];
            v17 = off_13DCBC[0];
            v18 = 735;
            return sub_12F32C(v17, v16, v18);
          }
          return result;
        }
        result = sub_12F32C(off_13DFF8[0], off_13DFCC[0], 734);
        if ( **v13 >= 0 )
          return result;
        goto LABEL_53;
      }
LABEL_42:
      if ( (v8 & 3) != 3 || (result = sub_12F32C(off_13E080[0], off_13E07C[0], 722), **v13 < 0) )
      {
        if ( *(uint8_t *)(a1 + 179) >= v10
          || (result = sub_12F32C(off_13DFE8[0], off_13DFCC[0], 723), **v13 < 0) )
        {
          if ( *(uint8_t *)(a1 + 180) >= v11
            || (result = sub_12F32C(off_13DFE4[0], off_13DFCC[0], 724), **v13 < 0) )
          {
            if ( *(uint8_t *)(a1 + 176) >= v12
              || (result = sub_12F32C(off_13DFE0[0], off_13DFCC[0], 725), **v13 < 0) )
            {
              if ( (int)v12 > 2 * (((int)*(uint16_t *)(a1 + 170) >> (2 * v11)) & 3) + 7 )
              {
                v16 = off_13DCA8[0];
                v17 = off_13DCB8[0];
                v18 = 726;
                return sub_12F32C(v17, v16, v18);
              }
            }
          }
        }
      }
      return result;
    default:
LABEL_71:
      if ( **v13 < 0 )
        goto LABEL_72;
      return result;
  }
}
