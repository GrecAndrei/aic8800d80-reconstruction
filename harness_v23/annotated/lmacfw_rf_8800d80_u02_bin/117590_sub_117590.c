// v23 annotated: sub_117590 @ 0x117590
// Original: 117590_sub_117590.c
// Primary struct: <unclustered>
//
// sub_117590 @ 0x117590, size 936 bytes
int __fastcall sub_117590(int a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r9
  unsigned __int8 **v5; // r5
  unsigned __int8 *v6; // r3
  int v8; // r3
  unsigned int v9; // r1
  int v10; // r2
  int v11; // r3
  int *v12; // r6
  int v13; // r3
  int v14; // r10
  unsigned __int8 v15; // r8
  unsigned __int8 *v16; // r2
  _BYTE *v17; // r5
  int v18; // r2
  int *v19; // r6
  int v20; // r0
  int v21; // r0
  int v22; // r1
  int v23; // r3
  int v24; // r2
  _WORD *v26; // r7
  int *v27; // r8
  bool v28; // cc
  int v29; // r0
  int v30; // r10
  int v31; // r0
  int v32; // r12
  int v33; // r3
  int *v34; // r0
  _BYTE *v35; // r12
  int v36; // r1
  char v37; // r10
  int v38; // r1
  int v39; // r3
  _DWORD *v40; // r1
  int v41; // r1
  int v42; // r0
  _DWORD *v43; // r0
  int v44; // r1
  int v45; // r8
  int v46; // r2
  int v47; // r12
  int v48; // r2
  unsigned __int8 *v49; // r0
  int v50; // r1
  int v51; // r1
  unsigned int CPSR; // r3
  int *v53; // r4
  int v54; // r0
  int v55; // r2
  int v56; // r3
  int v57; // r0
  int v58; // [sp+Ch] [bp-Ch]
  __int16 v59; // [sp+12h] [bp-6h] BYREF
  int v60; // [sp+14h] [bp-4h] BYREF

  v5 = (unsigned __int8 **)off_11786C;
  v6 = *(unsigned __int8 **)off_11786C;
  v60 = *(_DWORD *)(a1 + 28);
  v59 = 0;
  v8 = *v6;
  if ( v8 == 3 )
  {
    v3 = sub_121A80();
    v8 = **v5;
    a3 = v3 + 56;
  }
  if ( v8 == 2 )
  {
    v26 = off_117890;
    if ( !*((_DWORD *)off_117890 + 2057) )
    {
      v50 = v60;
      *(_BYTE *)(a1 + 16) |= 1u;
      scan_channel_done_n_180(a1, v50);
      CPSR = __get_CPSR();
      if ( (CPSR & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_117944 = 1;
      }
      v53 = (int *)off_117948;
      ++*(_DWORD *)off_117948;
      v54 = rf_bus_mark_ne0(CPSR << 31, v51);
      if ( *v53 )
      {
        v56 = *v53 - 1;
        v55 = *(_DWORD *)off_117944;
        *v53 = v56;
        if ( !v56 )
        {
          if ( v55 )
            __enable_irq();
        }
      }
      return sub_10DA6C(dword_11794C, v54, v55);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_117880 = 1;
    }
    v27 = (int *)off_117884;
    v58 = a3;
    v28 = (unsigned __int16)v26[4122] > 0x186u;
    ++*(_DWORD *)off_117884;
    v29 = dword_117894;
    v30 = dword_1178B0;
    if ( v28 )
      v26[4122] = 0;
    v31 = sub_11E7AC(v29);
    a3 = v58;
    v32 = *(_DWORD *)off_117898;
    v4 = v31;
    v33 = (unsigned __int16)v26[4122];
    *(_WORD *)(v31 + 12) = v33;
    v34 = (int *)(v32 + 8 * v33);
    v34[1] = a1 + 48;
    *v34 = v30;
    v35 = off_11787C;
    *(_DWORD *)(v4 + 4) = v34;
    v36 = *v27;
    v37 = *((_BYTE *)v26 + 3074) + 1;
    LOBYTE(v34) = v35[3] + 1;
    v26[4122] = v33 + 1;
    *((_BYTE *)v26 + 3074) = v37;
    v35[3] = (_BYTE)v34;
    if ( v36 )
    {
      v38 = v36 - 1;
      v39 = *(_DWORD *)off_117880;
      *v27 = v38;
      if ( !v38 )
      {
        if ( v39 )
          __enable_irq();
      }
    }
    v9 = *(unsigned __int16 *)(a1 + 48);
    v8 = **(__int16 **)off_117870;
    if ( v8 >= 0 )
    {
LABEL_37:
      v8 = **v5;
      if ( v8 == 2 )
      {
        sub_11702C(&v60, v9, &v59);
        goto LABEL_7;
      }
LABEL_5:
      if ( v8 == 1 )
        sub_117164(&v60, v9, &v59);
      else
        sub_117284(&v60, v9, a3, &v59, 0);
LABEL_7:
      get_cached_1828f8((_QWORD *)(a1 + 88), 0);
      v11 = **v5;
      if ( v11 == 3 )
      {
        v40 = off_11789C;
        *(_DWORD *)(a1 + 96) = dword_1178A0;
        v41 = v40[1];
        *(_DWORD *)(a1 + 104) = v3;
        *(_DWORD *)(a1 + 100) = a1 + 48;
        v42 = dword_1178A4;
        *(_DWORD *)(v41 + 32) = a1 + 100;
        *(_DWORD *)(a1 + 108) = v42;
        *(_DWORD *)(a1 + 132) = 0;
        *(_DWORD *)(a1 + 112) = 54;
        *(_DWORD *)(a1 + 116) = 54;
        *(_DWORD *)(a1 + 120) = 262148;
LABEL_24:
        scan_channel_done_n_180(a1, v60);
        return list_push_tail(dword_11788C);
      }
      if ( v11 == 1 )
      {
        v12 = (int *)off_117874;
        v13 = *((unsigned __int8 *)off_117874 + 32);
        if ( !*((_BYTE *)off_117874 + 32) )
          goto LABEL_10;
        v43 = (_DWORD *)sub_1101AC();
        v45 = (int)v43;
        if ( v43 )
        {
          v13 = *((unsigned __int8 *)v12 + 32);
          if ( *((_BYTE *)v12 + 32) )
          {
            v46 = *v12;
            v47 = v12[1] + 1;
            v43[2] = (v47 << 24) & 0x7F000000 | v43[2] & 0x80FFFFFF;
            v12[1] = v47;
            sub_110B44(v43, a1 + 48, v46, 0x36u, 0);
            v48 = *((unsigned __int8 *)off_1178A8 + 192);
            v12[3] += 54;
            if ( v48 )
              sub_117538(v45);
            else
              sub_110AB8(v45, v12[1], v12[2]);
            v49 = *v5;
            *(_BYTE *)off_1178AC |= 1u;
            v12[1] = 0;
            v12[3] = 0;
            *v12 = 0;
            v12[2] = 0;
            *((_BYTE *)v12 + 32) = 0;
            v11 = *v49;
            goto LABEL_15;
          }
        }
        else
        {
          v57 = dword_117950;
          *(_BYTE *)(a1 + 16) |= 1u;
          msg_parse(v57, v44);
          *((_BYTE *)v12 + 32) = 0;
        }
LABEL_10:
        sub_11F74C(1024, dword_117878, v10, v13);
        v14 = *v12;
        *(_BYTE *)(a1 + 16) |= 1u;
        if ( v14 && v12[1] )
        {
          v15 = 0;
          do
          {
            v14 = *(_DWORD *)(v14 + 4);
            rf_lmac_init_n1ec();
            ++v15;
          }
          while ( v15 < (unsigned int)v12[1] );
        }
        v16 = *v5;
        v12[1] = 0;
        v12[3] = 0;
        *v12 = 0;
        v12[2] = 0;
        v11 = *v16;
      }
LABEL_15:
      if ( v11 == 2 )
      {
        v17 = off_11787C;
        if ( *((_BYTE *)off_11787C + 2) )
        {
          v18 = *(_DWORD *)(v4 + 4);
          *(_DWORD *)(v4 + 8) = *(unsigned __int16 *)off_11787C + 58;
          *(_BYTE *)(v18 + 3) &= 0x3Fu;
          *(_BYTE *)(v4 + 14) = v17[3];
          *(_DWORD *)v4 = 0;
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(_DWORD *)off_117880 = 1;
          }
          v19 = (int *)off_117884;
          v20 = dword_117888;
          ++*(_DWORD *)off_117884;
          v21 = list_push_tail(v20);
          rf_bus_mark_ne0(v21, v22);
          if ( *v19 )
          {
            v23 = *v19 - 1;
            v24 = *(_DWORD *)off_117880;
            *v19 = v23;
            if ( !v23 )
            {
              if ( v24 )
                __enable_irq();
            }
          }
          *(_DWORD *)v17 = 0;
          *((_DWORD *)v17 + 1) = 0;
        }
      }
      goto LABEL_24;
    }
  }
  else
  {
    v9 = *(unsigned __int16 *)(a1 + 48);
    if ( **(__int16 **)off_117870 >= 0 )
      goto LABEL_5;
  }
  if ( !v9 )
    return sub_121960(dword_11793C, dword_117938, 1545, v8);
  if ( v9 <= 0x3000 )
    goto LABEL_37;
  return sub_121960(dword_117940, dword_117938, 1547, v8);
}

