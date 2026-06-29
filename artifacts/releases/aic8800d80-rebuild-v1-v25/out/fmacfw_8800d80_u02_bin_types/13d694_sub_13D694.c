// sub_13D694 @ 0x13d694, size 1020 bytes
int  sub_13D694(int a1)
{
  int v2; // r0
  int v3; // r1
  int v4; // r2
  unsigned int v5; // r3
  int result; // r0
  int v7; // r5
  unsigned int v8; // r1
  int v9; // r1
  int v10; // r2
  int v11; // r1
  int v12; // r7
  int v13; // r12
  int v14; // r4
  unsigned int v15; // r1
  int v16; // r7
  signed int v17; // r12
  int v18; // r2
  int v19; // r5
  __int16 v20; // r1
  __int16 v21; // r5
  unsigned int v22; // r6
  int v23; // r6
  unsigned int v24; // r5
  unsigned int v25; // r7
  int v26; // r6
  __int16 v27; // lr
  int v28; // r2
  signed int v29; // r12
  unsigned int v30; // r9
  __int16 v31; // r12
  unsigned __int16 v32; // r8
  __int16 v33; // r6
  int v34; // r6
  int v35; // r12
  unsigned int v36; // r1
  unsigned int v37; // r7
  unsigned int v38; // r4

  v2 = random_mix_64(a1);
  v3 = *(unsigned __int8 *)(a1 + 169);
  v4 = *(unsigned __int8 *)(a1 + 179);
  v5 = v2;
  result = (unsigned __int16)((uint16_t)v3 << 11);
  if ( *(uint8_t *)(a1 + 179) )
    v7 = (unsigned __int8)(v4 - 1);
  else
    v7 = *(unsigned __int8 *)(a1 + 179);
  switch ( *(uint8_t *)(a1 + 169) )
  {
    case 0:
    case 1:
      v10 = (unsigned __int8)(*(uint8_t *)(a1 + 177)
                            + (unsigned __int8)(v5 & 0x7F)
                            % (*(unsigned __int8 *)(a1 + 178) - *(unsigned __int8 *)(a1 + 177) + 1));
      if ( ((*(unsigned __int16 *)(a1 + 174) >> v10) & 1) == 0 )
        v10 = *(unsigned __int8 *)(a1 + 178);
      result |= v10;
      if ( !v10 )
        return (unsigned __int16)result | 0x400;
      if ( (unsigned __int8)(v10 - 1) <= 2u )
        return (unsigned __int16)result | v5 & 0x400 | (unsigned __int16)(*(unsigned __int8 *)(a1 + 182) << 10);
      return result;
    case 2:
    case 3:
      v8 = *(unsigned __int8 *)(a1 + 177);
      if ( v8 <= 3 && (v5 & 0x800) != 0 )
        goto LABEL_6;
      v34 = *(unsigned __int8 *)(a1 + 176);
      v35 = *(unsigned __int8 *)(a1 + 181);
      v36 = ((v5 >> 3) & 3) % ((unsigned int)*(unsigned __int8 *)(a1 + 180) + 1);
      v37 = *(unsigned __int8 *)(a1 + v36 + 170);
      v38 = (v5 & 7) % (v34 + 1);
      if ( ((v37 >> v38) & 1) != 0 )
        v34 = (unsigned __int8)v38;
      return (unsigned __int16)(result
                              | (8 * v36)
                              | ((((v5 >> 9) & 1) % (v35 + 1)) << 9)
                              | (((uint16_t)v7 + (unsigned __int16)((int)((v5 >> 7) & 3) % (v4 - v7 + 1))) << 7))
           | v34;
    case 4:
      v8 = *(unsigned __int8 *)(a1 + 177);
      if ( v8 > 3 || (v5 & 0x800) == 0 )
      {
        v11 = *(unsigned __int8 *)(a1 + 180);
        v12 = *(unsigned __int16 *)(a1 + 170);
        v13 = *(unsigned __int8 *)(a1 + 176);
        v14 = *(unsigned __int8 *)(a1 + 181);
        v15 = ((v5 >> 4) & 7) % (v11 + 1);
        v16 = ((v12 >> (2 * v15)) & 3) + 7;
        v17 = (v5 & 0xF) % (v13 + 1);
        v18 = v4 - v7;
        if ( v17 <= v16 )
        {
          v19 = (unsigned __int8)(v7 + (int)((v5 >> 7) & 3) % (v18 + 1));
          v16 = (unsigned __int8)v17;
          if ( v17 == 6 )
          {
            if ( v19 == 2 )
            {
              if ( v15 == 3 || v15 == 6 )
              {
                v20 = 16 * (unsigned __int8)(v15 - 1);
                LOWORD(v17) = 6;
                v21 = 256;
              }
              else
              {
                v20 = 16 * v15;
                v21 = 256;
              }
            }
            else
            {
              v20 = 16 * v15;
              v21 = (uint16_t)v19 << 7;
            }
            return (unsigned __int16)v17 | (unsigned __int16)(result | ((((v5 >> 9) & 1) % (v14 + 1)) << 9) | v21 | v20);
          }
        }
        else
        {
          v16 = (unsigned __int8)v16;
          v19 = (unsigned __int8)(v7 + (int)((v5 >> 7) & 3) % (v18 + 1));
        }
        if ( v16 == 9 )
        {
          if ( v19 )
          {
            if ( v19 == 2 )
            {
              if ( v15 == 5 )
              {
                LOWORD(v17) = 9;
                v20 = 64;
              }
              else
              {
                v20 = 16 * v15;
                LOWORD(v17) = 9;
              }
              v21 = 256;
            }
            else if ( v19 == 3 )
            {
              if ( v15 == 2 )
              {
                LOWORD(v17) = 9;
                v20 = 16;
              }
              else
              {
                v20 = 16 * v15;
                LOWORD(v17) = 9;
              }
              v21 = 384;
            }
            else
            {
              v20 = 16 * v15;
              v21 = (uint16_t)v19 << 7;
              LOWORD(v17) = 9;
            }
          }
          else
          {
            if ( v15 == 2 )
            {
              LOWORD(v17) = 9;
            }
            else if ( (unsigned __int8)v15 == 5 )
            {
              LOWORD(v17) = 9;
            }
            else
            {
              LOWORD(v17) = 8;
            }
            v20 = 16 * v15;
            v21 = 0;
          }
        }
        else
        {
          v20 = 16 * v15;
          v21 = (uint16_t)v19 << 7;
          LOWORD(v17) = v16;
        }
        return (unsigned __int16)v17 | (unsigned __int16)(result | ((((v5 >> 9) & 1) % (v14 + 1)) << 9) | v21 | v20);
      }
LABEL_6:
      v9 = (unsigned __int8)(v8 + (unsigned __int8)(v5 & 0x7F) % (int)(*(unsigned __int8 *)(a1 + 178) - v8 + 1));
      if ( ((*(unsigned __int16 *)(a1 + 174) >> v9) & 1) == 0 )
        v9 = *(unsigned __int8 *)(a1 + 178);
      if ( !v9 )
        return 1024;
      return v5 & 0x400 | (unsigned __int16)(*(unsigned __int8 *)(a1 + 182) << 10) | (unsigned __int16)v9;
    case 5:
      v22 = *(unsigned __int8 *)(a1 + 177);
      if ( v22 > 3 || (v5 & 0x800) == 0 )
      {
        v24 = (unsigned __int8)(v7 + (int)((v5 >> 7) & 3) % (v4 - v7 + 1));
        v25 = ((v5 >> 4) & 7) % ((unsigned int)*(unsigned __int8 *)(a1 + 180) + 1);
        v26 = (v5 >> 9) & 3;
        if ( (v5 & 0xF) == 0xF )
        {
          if ( (uint8_t)v24 )
          {
            v27 = (unsigned __int8)v24 << 7;
          }
          else
          {
            if ( !v25 )
            {
              v24 = *(unsigned __int8 *)(a1 + 183);
              if ( *(uint8_t *)(a1 + 183) )
              {
                v27 = 128;
                v31 = 14336;
                v3 = 7;
                v24 = 1;
              }
              else
              {
                v27 = *(unsigned __int8 *)(a1 + 183);
                v31 = 10240;
              }
              v30 = 0;
              LOWORD(v28) = 0;
              goto LABEL_40;
            }
            v27 = 0;
          }
        }
        else
        {
          v27 = (uint16_t)v24 << 7;
        }
        v28 = 2 * (((int)*(unsigned __int16 *)(a1 + 170) >> (2 * v25)) & 3) + 7;
        v29 = (v5 & 0xF) % ((unsigned int)*(unsigned __int8 *)(a1 + 176) + 1);
        if ( v29 > v28 )
        {
          v30 = (unsigned __int8)v28;
        }
        else
        {
          v30 = (unsigned __int8)v29;
          LOWORD(v28) = (v5 & 0xF) % ((unsigned int)*(unsigned __int8 *)(a1 + 176) + 1);
        }
        v31 = 10240;
LABEL_40:
        v32 = *(unsigned __int8 *)(a1 + 194);
        if ( v26 == 3 )
          v33 = 1024;
        else
          v33 = (uint16_t)v26 << 9;
        if ( *(uint8_t *)(a1 + 194) )
        {
          if ( v3 == 7 && v24 == 1
            || v30 != 2
            && *(unsigned __int8 *)(a1 + 195) >= v30
            && *(unsigned __int8 *)(a1 + 196) >= (unsigned int)(unsigned __int8)v25
            && *(unsigned __int8 *)(a1 + 197) >= v24 )
          {
            v32 = v5 & 0x4000;
          }
          else
          {
            v32 = 0;
          }
        }
        return v32 | (unsigned __int16)(v33 | v27 | v31 | v28 | result & 0xC7FF | (16 * v25));
      }
      v23 = (unsigned __int8)(v22 + (unsigned __int8)(v5 & 0x7F) % (int)(*(unsigned __int8 *)(a1 + 178) - v22 + 1));
      if ( ((*(unsigned __int16 *)(a1 + 174) >> v23) & 1) == 0 )
        v23 = *(unsigned __int8 *)(a1 + 178);
      if ( v23 )
        return v5 & 0x400 | (unsigned __int16)(*(unsigned __int8 *)(a1 + 182) << 10) | (unsigned __int16)v23;
      else
        return 1024;
    default:
      return result;
  }
}

