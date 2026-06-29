// fwstruct annotate: 1268ec_rf_level_apply_n_4ec.c
// rf_level_apply_n_4ec @ 0x1268ec, size 1078 bytes
// Doc: rf_level_apply_n_42e [rf]: Apply TX/RF power level by programming level MMIO registers
// rf_level_apply_n_42e [rf]: Apply TX/RF power level by programming level MMIO registers
unsigned int *__fastcall rf_level_apply_n_4ec(int a1)
{
  unsigned int *result; // r0
  int v3; // r6
  unsigned int v4; // r5
  _DWORD *v5; // r1
  _DWORD *v6; // r2
  _DWORD *v7; // r2
  int *v8; // r3
  int v9; // r2
  _DWORD *v10; // r3
  _DWORD *v11; // r3
  _DWORD *v12; // r5
  _DWORD *v13; // r4
  _DWORD *v14; // r1
  _DWORD *v15; // r1
  int *v16; // r3
  int v17; // r2
  unsigned int *v18; // r4
  _DWORD *v19; // r2
  int v20; // r2
  _DWORD *v21; // r8
  unsigned int v22; // r6
  unsigned int v23; // r7
  int v24; // r5
  _DWORD *v25; // r4
  _DWORD *v26; // r0
  unsigned int *v27; // r3
  int v28; // r2
  _DWORD *v29; // r2
  _DWORD *v30; // r5
  int *v31; // r3
  int v32; // r2
  unsigned int v33; // r4
  int *v34; // r1
  int *v35; // r5
  int v36; // r6
  int v37; // r4
  int v38; // r2
  _DWORD *v39; // r2
  int *v40; // r3
  int v41; // r2
  _DWORD *v42; // r1
  int *v43; // r3
  unsigned int *v44; // r0
  int v45; // r4
  int v46; // r2
  _DWORD *v47; // r2
  int v48; // r2
  int *v49; // r3
  int v50; // r2
  __int64 v51; // [sp+8h] [bp-8h] BYREF

  if ( a1 )
  {
    if ( a1 != 1 )
    {
      if ( (unsigned int)(a1 - 2) > 1 )
        return (unsigned int *)msg_parse(dword_126BC4, a1);
      get_cached_1828f8(&v51, 0);
      v3 = BYTE1(v51);
      v4 = WORD1(v51);
      msg_parse(rf_level_apply_n_210, a1, WORD2(v51), WORD1(v51), BYTE1(v51));
      result = (unsigned int *)rf_level_apply_n_207;
      v5 = rf_level_apply_n_203;
      v6 = rf_level_apply_n_200;
      *(_DWORD *)rf_level_apply_n_207 = *(_DWORD *)rf_level_apply_n_20c & 0xFFFFBFFF;
      *v5 |= 0x80000000;
      *v6 |= 0x8000u;
      if ( a1 == 3 )
      {
        v6[80] |= 0x1000u;
        if ( v3 )
        {
          if ( v3 == 1 )
          {
            v42 = off_126D3C;
            v43 = (int *)off_126D40;
            v44 = (unsigned int *)off_126D44;
            v45 = dword_126D48;
            v46 = dword_126D4C;
            *(_DWORD *)off_126D3C = dword_126D48;
            *v43 = v46;
            v47 = off_126D24;
            *v44 = *v44 & 0xFFFFFF00 | 1;
            *v44 = *v44 & 0xFFFF00FF | 0x7F00;
            *(_DWORD *)(v45 + 1174608113) = *(_DWORD *)(v45 + 1174608113) & 0xC000FFFF | 0x1490000;
            v42[5] = v42[5] & 0xFFFFF0FF | 0x100;
            result = v44 - 146;
            *v47 &= ~0x80000000;
            *result &= ~0x80000000;
            if ( v4 == 2412 )
            {
              v49 = (int *)off_126D30;
              result = (unsigned int *)dword_126D58;
              v50 = dword_126D5C;
              *(_DWORD *)off_126D2C = dword_126D58;
              *v49 = v50;
            }
            else if ( v4 == 2472 )
            {
              result = (unsigned int *)rf_level_apply_n_88;
              v48 = dword_126D54;
              *(_DWORD *)off_126D2C = rf_level_apply_n_88;
              REG_4034_2088 = v48;
            }
          }
          else
          {
            v39 = off_126D28;
            *(_DWORD *)off_126D24 &= ~0x80000000;
            *v39 &= ~0x80000000;
          }
        }
        else
        {
          v15 = v5 - 101;
          v16 = (int *)rf_level_apply_n_1d3;
          v17 = dword_126C0C;
          *v15 = rf_level_apply_n_1d0;
          *v16 = v17;
          v18 = (unsigned int *)rf_level_apply_n_1c8;
          v19 = rf_level_apply_n_1fc;
          result[21] = result[21] & 0xFFFFFF00 | 1;
          result[21] = result[21] & 0xFFFF00FF | 0x7F00;
          *v18 = *v18 & 0xC000FFFF | 0x390000;
          v15[5] = v15[5] & 0xFFFFF0FF | 0x100;
          result -= 125;
          *v19 &= ~0x80000000;
          *result &= ~0x80000000;
          if ( v4 == 2412 )
          {
            v40 = (int *)off_126D30;
            result = (unsigned int *)dword_126D34;
            v41 = dword_126D38;
            *(_DWORD *)off_126D2C = dword_126D34;
            *v40 = v41;
          }
          else if ( v4 == 2472 )
          {
            result = (unsigned int *)rf_level_apply_n_1c4;
            v20 = dword_126C18;
            *(_DWORD *)rf_level_apply_n_1f4 = rf_level_apply_n_1c4;
            REG_4034_2088 = v20;
          }
        }
      }
      else
      {
        v7 = ipc_doorbell_handler_n1ae;
        *(_DWORD *)rf_level_apply_n_1fc &= ~0x80000000;
        *v7 &= ~0x80000000;
        if ( v3 )
        {
          if ( v3 == 1 )
          {
            v31 = (int *)off_126BE8;
            result = (unsigned int *)dword_126C38;
            v32 = rf_level_apply_n_19c;
            *(_DWORD *)rf_level_apply_n_1f4 = dword_126C38;
            *v31 = v32;
          }
        }
        else
        {
          v8 = (int *)off_126BE8;
          result = (unsigned int *)dword_126BEC;
          v9 = rf_level_apply_n_1e7;
          *(_DWORD *)rf_level_apply_n_1f4 = dword_126BEC;
          *v8 = v9;
        }
      }
      v10 = rf_level_bit_extract;
LABEL_10:
      *v10 |= 2u;
      *v10 |= 1u;
      return result;
    }
    v21 = rf_level_apply_n_198;
    v22 = (*(_DWORD *)rf_level_apply_n_1bc >> 11) & 7;
    v23 = *(_DWORD *)rf_level_apply_n_1bc & 0x7F;
    v24 = (*(_DWORD *)rf_level_apply_n_1bc >> 7) & 3;
    check_param_eq1(v22, v23, v24);
    if ( !*v21 )
    {
      get_cached_1828f8(&v51, 0);
      v33 = WORD1(v51);
      result = (unsigned int *)msg_parse(rf_level_apply_n_1b8, WORD2(v51), WORD1(v51), BYTE1(v51));
      if ( v33 == 2412 )
      {
        v34 = (int *)off_126D28;
        v35 = (int *)off_126D2C;
        result = (unsigned int *)off_126D30;
        v36 = dword_126D34;
        v37 = dword_126D38;
        *(_DWORD *)off_126D24 &= ~0x80000000;
        v38 = *v34;
      }
      else
      {
        if ( v33 != 2472 )
          return result;
        v34 = (int *)ipc_doorbell_handler_n1ae;
        v35 = (int *)rf_level_apply_n_1f4;
        result = (unsigned int *)off_126BE8;
        v36 = rf_level_apply_n_1c4;
        v37 = dword_126C18;
        *(_DWORD *)rf_level_apply_n_1fc &= ~0x80000000;
        v38 = *v34;
      }
      v10 = rf_level_bit_extract;
      *v34 = v38 & 0x7FFFFFFF;
      *v35 = v36;
      *result = v37;
      goto LABEL_10;
    }
    msg_parse(rf_level_apply_n_1b8, v22, v23, v24);
    result = (unsigned int *)sub_12686C(a1);
    if ( !*(_BYTE *)rf_level_apply_n_1b4 && *(_DWORD *)off_126C28 )
    {
      v25 = rf_level_apply_n_200;
      v26 = rf_level_apply_n_1db;
      v27 = (unsigned int *)rf_level_apply_n_1ac;
      v28 = rf_level_apply_n_1a8;
      *(_DWORD *)rf_level_apply_n_200 |= 0x4000u;
      *v26 |= 0x10000u;
      *v27 = v28 & ((*v21 - 1) << 16) | *v27 & 0x8000FFFF;
      *v27 |= 0x60u;
      *v27 |= 1u;
      result = v26 + 2071;
      v25[79] = v25[79] & 0xFFFFFF | 0xA0000000;
      *result = *result & 0xFF87FFFF | 0x700000;
    }
  }
  else
  {
    result = (unsigned int *)msg_parse(rf_level_apply_n_1e0);
    v11 = rf_level_apply_n_1db;
    if ( (*(_DWORD *)rf_level_apply_n_1db & 0x10000) != 0 )
    {
      v29 = rf_level_apply_n_1ac;
      v30 = rf_level_apply_calc;
      *(_DWORD *)rf_level_apply_n_200 &= ~0x4000u;
      *v11 &= ~0x10000u;
      *v29 &= ~1u;
      *v29 &= 0xFFFFFF9F;
      *v30 &= 0xFF87FFFF;
      result = (unsigned int *)sub_12686C(0);
    }
    if ( *(int *)rf_level_apply_n_1fc >= 0 )
    {
      v12 = ipc_doorbell_handler_n1ae;
      v13 = rf_level_apply_n_203;
      result = (unsigned int *)rf_level_apply_n_200;
      v14 = rf_level_apply_n_1d7;
      *(_DWORD *)rf_level_apply_n_1fc |= 0x80000000;
      *v12 |= 0x80000000;
      *v13 &= ~0x80000000;
      *result &= ~0x8000u;
      *v14 &= ~0x1000u;
    }
  }
  return result;
}

