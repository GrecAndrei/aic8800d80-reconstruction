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

extern uint32_t dword_13EAEC;
extern uint32_t off_13EAF0;
extern uint32_t dword_13EB78;
extern uint32_t dword_13EB74;
extern uint32_t dword_13EAE4;
extern uint32_t dword_13EAE0;
extern uint32_t dword_13EAE8;

// sub_13E670 @ 0x13e670, size 1282 bytes
unsigned int  sub_13E670(int a1, unsigned int a2, unsigned int a3, int a4, int a5)
{
  unsigned int result; // r0
  int v8; // r1
  int v10; // lr
  int16_t v11; // r2
  int16_t v12; // r5
  int v13; // r2
  int v14; // r1
  int16_t **v15; // r11
  int v16; // r9
  int v17; // r4
  int v18; // r1
  int v19; // r10
  uint8_t *v20; // r12
  int v21; // t1
  int v22; // r5
  int v23; // r2
  int v24; // r3
  int v25; // r4
  int16_t v26; // r3
  int16_t v27; // r3
  int16_t v28; // r8
  int16_t v29; // r2
  unsigned int *v30; // r3
  uint8_t *v31; // r10
  unsigned int v32; // r2
  int v33; // r6
  int v34; // r5
  int v35; // r7
  unsigned int v36; // r4
  unsigned int v37; // r8
  int v38; // r2
  int v39; // t1
  unsigned int v40; // t1
  unsigned int v41; // r1
  int v42; // r2
  int v43; // r12
  int16_t v44; // r3
  unsigned int *v45; // r3
  uint8_t *v46; // r10
  unsigned int v47; // r2
  int v48; // r6
  int v49; // r5
  int v50; // r7
  unsigned int v51; // r4
  unsigned int v52; // r8
  int v53; // r2
  int v54; // t1
  unsigned int v55; // t1
  unsigned int v56; // r1
  int v57; // r2
  int v58; // r12
  int16_t v59; // r2
  uint16_t *v60; // r3
  int16_t *v61; // r4
  unsigned int v62; // r2
  unsigned int v63; // r1
  int16_t v64; // r2
  unsigned int v65; // r2
  int16_t v66; // r3
  int16_t v67; // r2
  int16_t v68; // r2
  int v69; // [sp+0h] [bp-24h]
  unsigned int *v70; // [sp+0h] [bp-24h]
  unsigned int *v71; // [sp+0h] [bp-24h]
  int v73; // [sp+8h] [bp-1Ch]
  int v74; // [sp+Ch] [bp-18h]
  unsigned int *v75; // [sp+14h] [bp-10h]
  uint8_t v76[8]; // [sp+1Ch] [bp-8h] BYREF

  result = *(uint8_t *)(a1 + 29);
  *(uint32_t *)v76 = -1;
  if ( result > 0x1F )
    return result;
  v8 = *(uint32_t *)(a1 + 76);
  result = dword_13EAEC + 696 * result;
  v10 = *(uint8_t *)(result + 34);
  v11 = *(uint16_t *)(a1 + 30);
  v12 = v11 & 0xDFFF;
  v73 = *(uint32_t *)(v8 + 72) & 0x400000;
  v13 = v11 & 0x2000;
  v14 = (*(uint32_t *)(v8 + 64) & 0x2000) != 0 ? a4 : 1;
  v69 = v14;
  *(uint16_t *)(a1 + 30) = v12;
  v74 = v13;
  if ( v10 == 255 )
    return result;
  v15 = (int16_t **)off_13EAF0;
  v16 = *(uint32_t *)(result + 340);
  if ( **(int16_t **)off_13EAF0 < 0 )
  {
    if ( v16 )
    {
      if ( !a4 )
        goto LABEL_26;
      if ( a5 )
        goto LABEL_9;
    }
    else
    {
      sub_12F694(dword_13EB78, dword_13EB74, 2470);
      if ( !a4 )
        goto LABEL_26;
      if ( **v15 >= 0 || a5 )
        goto LABEL_9;
    }
    sub_12F694(dword_13EAE4, dword_13EAE0, 2473);
    goto LABEL_9;
  }
  if ( !a4 )
  {
LABEL_26:
    v17 = *(uint32_t *)(a1 + 72) + 44;
    goto LABEL_10;
  }
LABEL_9:
  v17 = a5 + 272;
LABEL_10:
  v18 = *(uint16_t *)(v16 + 184);
  result = v17 + 20;
  v75 = (unsigned int *)(v17 + 20);
  v19 = v17 + 36;
  v20 = v76;
  do
  {
    v21 = *(uint32_t *)result;
    result += 4;
    v22 = v21 & 0x3FFF;
    if ( v18 )
    {
      v23 = v16 + 12 * v18;
      v24 = 0;
      while ( 1 )
      {
        v25 = *(uint16_t *)(v23 - 2);
        v23 -= 12;
        if ( v25 == v22 )
          break;
        if ( ++v24 == v18 )
          goto LABEL_16;
      }
      *v20 = v18 - 1 - v24;
    }
LABEL_16:
    if ( v69 )
    {
      if ( ((*(uint8_t *)(a1 + 54) >> 2) & 7) == *(uint8_t *)(v16 + 167) )
      {
        v64 = *(uint16_t *)(v16 + 146);
        result = (uint16_t)a2;
        *(uint16_t *)(v16 + 144) += a2;
        *(uint16_t *)(v16 + 146) = v64 + 1;
        if ( !v73 )
        {
          if ( v74 )
          {
LABEL_83:
            if ( v76[0] == 255 )
            {
LABEL_38:
              *(uint8_t *)(v16 + 154) = 0;
              return result;
            }
            v60 = (uint16_t *)(v16 + 12 * v76[0] + 4);
            *(uint8_t *)(v16 + 154) = 0;
            goto LABEL_55;
          }
          if ( v76[0] == 255 )
            v60 = 0;
          else
            v60 = (uint16_t *)(v16 + 12 * v76[0] + 4);
          v65 = *(uint8_t *)(v16 + 168);
          if ( a2 >= 2 * a3 )
          {
            if ( *(uint8_t *)(v16 + 168) )
            {
              *(uint8_t *)(v16 + 168) = v65 - 1;
              if ( !v60 )
                return result;
              goto LABEL_55;
            }
          }
          else
          {
            if ( v65 <= 1 )
            {
              *(uint8_t *)(v16 + 168) = v65 + 1;
              if ( !v60 )
                return result;
              goto LABEL_55;
            }
            if ( v65 == 2 )
            {
              *(uint32_t *)v16 -= 75000;
              if ( !v60 )
                return result;
              goto LABEL_55;
            }
          }
          if ( !v60 )
            return result;
LABEL_55:
          v61 = *v15;
          v62 = (uint16_t)(result - a3 + v60[1]);
          v63 = (uint16_t)(*v60 + result);
          v60[1] = v62;
          *v60 = v63;
          if ( *v61 < 0 && v63 < v62 )
            return sub_12F694(dword_13EAE8, dword_13EAE0, 2589);
          return result;
        }
      }
      else
      {
        if ( !v73 )
        {
          v59 = *(uint16_t *)(v16 + 144);
          result = (uint16_t)a2;
          ++*(uint16_t *)(v16 + 146);
          *(uint16_t *)(v16 + 144) = v59 + a2;
          if ( !v74 )
          {
            if ( v76[0] == 255 )
              return result;
            v60 = (uint16_t *)(v16 + 12 * v76[0] + 4);
            goto LABEL_55;
          }
          goto LABEL_83;
        }
        result = (uint16_t)a2;
        v66 = *(uint16_t *)(v16 + 146) + 1;
        *(uint16_t *)(v16 + 144) += a2;
        *(uint16_t *)(v16 + 146) = v66;
      }
      v60 = (uint16_t *)(v16 + 124);
      goto LABEL_55;
    }
    ++v20;
  }
  while ( v19 != result );
  if ( ((*(uint8_t *)(a1 + 54) >> 2) & 7) != *(uint8_t *)(v16 + 167) )
  {
    if ( v73 )
    {
      v26 = *(uint16_t *)(v16 + 144) + 1;
      ++*(uint16_t *)(v16 + 146);
      *(uint16_t *)(v16 + 144) = v26;
      goto LABEL_21;
    }
    v44 = *(uint16_t *)(v16 + 144) + 1;
    ++*(uint16_t *)(v16 + 146);
    *(uint16_t *)(v16 + 144) = v44;
LABEL_28:
    if ( v74 )
    {
      v31 = v76;
      v30 = v75;
      v32 = a3;
      v33 = dword_13EAE0;
      v34 = dword_13EAE8;
      v35 = 0;
      v36 = a2;
      v37 = v32;
      while ( 1 )
      {
        if ( !v36 )
          goto LABEL_38;
        v39 = *v31++;
        v38 = v39;
        v40 = *v30++;
        v41 = v40 >> 29;
        if ( v38 != 255 )
        {
          v42 = 12 * v38;
          result = v42 + 4;
          v43 = v16 + v42 + 4;
          if ( v35 )
          {
            if ( v35 != 3 )
              goto LABEL_34;
            goto LABEL_74;
          }
          if ( v37 )
          {
            --v37;
            --v36;
            ++*(uint16_t *)(v42 + v16 + 4);
LABEL_34:
            if ( v41 <= v37 )
              goto LABEL_35;
LABEL_74:
            v68 = *(uint16_t *)(v43 + 2) + v36 - v37;
            v37 = 0;
            *(uint16_t *)(v16 + result) += v36;
            v36 = 0;
            *(uint16_t *)(v43 + 2) = v68;
          }
          else
          {
            if ( v41 )
              goto LABEL_74;
LABEL_35:
            *(uint16_t *)(v16 + result) += v41;
            v36 -= v41;
            v37 -= v41;
          }
          if ( **v15 < 0 && *(uint16_t *)(v16 + result) < (unsigned int)*(uint16_t *)(v43 + 2) )
          {
            v70 = v30;
            result = sub_12F694(v34, v33, 2657);
            v30 = v70;
          }
          goto LABEL_37;
        }
        if ( v35 )
        {
          if ( v35 == 3 )
            goto LABEL_38;
        }
        else
        {
          if ( !v37 )
          {
            if ( v41 )
              goto LABEL_38;
            goto LABEL_78;
          }
          --v37;
          --v36;
        }
        if ( v41 > v37 )
          goto LABEL_38;
LABEL_78:
        v36 -= v41;
        v37 -= v41;
LABEL_37:
        if ( ++v35 == 4 )
          goto LABEL_38;
      }
    }
    v46 = v76;
    v45 = v75;
    v47 = a3;
    v48 = dword_13EAE0;
    v49 = dword_13EAE8;
    v50 = 0;
    v51 = a2;
    v52 = v47;
    while ( 2 )
    {
      if ( !v51 )
        return result;
      v54 = *v46++;
      v53 = v54;
      v55 = *v45++;
      v56 = v55 >> 29;
      if ( v53 != 255 )
      {
        v57 = 12 * v53;
        result = v57 + 4;
        v58 = v16 + v57 + 4;
        if ( v50 )
        {
          if ( v50 != 3 )
            goto LABEL_45;
          goto LABEL_72;
        }
        if ( v52 )
        {
          --v52;
          --v51;
          ++*(uint16_t *)(v57 + v16 + 4);
LABEL_45:
          if ( v56 <= v52 )
            goto LABEL_46;
LABEL_72:
          v67 = *(uint16_t *)(v58 + 2) + v51 - v52;
          v52 = 0;
          *(uint16_t *)(v16 + result) += v51;
          v51 = 0;
          *(uint16_t *)(v58 + 2) = v67;
        }
        else
        {
          if ( v56 )
            goto LABEL_72;
LABEL_46:
          *(uint16_t *)(v16 + result) += v56;
          v51 -= v56;
          v52 -= v56;
        }
        if ( **v15 < 0 && *(uint16_t *)(v16 + result) < (unsigned int)*(uint16_t *)(v58 + 2) )
        {
          v71 = v45;
          result = sub_12F694(v49, v48, 2704);
          v45 = v71;
        }
LABEL_48:
        if ( ++v50 == 4 )
          return result;
        continue;
      }
      break;
    }
    if ( v50 )
    {
      if ( v50 == 3 )
        return result;
      goto LABEL_81;
    }
    if ( v52 )
    {
      --v52;
      --v51;
LABEL_81:
      if ( v56 > v52 )
        return result;
    }
    else if ( v56 )
    {
      return result;
    }
    v51 -= v56;
    v52 -= v56;
    goto LABEL_48;
  }
  v29 = *(uint16_t *)(v16 + 146);
  ++*(uint16_t *)(v16 + 144);
  *(uint16_t *)(v16 + 146) = v29 + 1;
  if ( !v73 )
    goto LABEL_28;
LABEL_21:
  v27 = a2 - a3 + *(uint16_t *)(v16 + 126);
  v28 = a2 + *(uint16_t *)(v16 + 124);
  *(uint16_t *)(v16 + 126) = v27;
  *(uint16_t *)(v16 + 124) = v28;
  return result;
}

