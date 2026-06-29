// fwstruct annotate: 140540_sub_140540.c
// sub_140540 @ 0x140540, size 1418 bytes
// Doc: sub_1240540 [util]: Helper setting up 9-register save frame, branches on input flag.
// sub_1240540 [util]: Helper setting up 9-register save frame, branches on input flag.
_DWORD *__fastcall sub_140540(int a1, int a2, int a3, int a4)
{
  int v4; // r11
  int v5; // r0
  _WORD *v8; // r5
  int v9; // r1
  __int16 v10; // r3
  int v11; // r3
  _BYTE *v12; // r1
  int v13; // r10
  int v14; // r3
  _DWORD *result; // r0
  int v16; // r3
  int v17; // r3
  int v18; // r6
  int v19; // r2
  int v20; // r1
  unsigned int v21; // r4
  int v22; // r3
  unsigned int v23; // r5
  int v24; // r2
  int v25; // r5
  __int64 v26; // kr00_8
  char *v27; // r3
  char v28; // t1
  __int16 v29; // r4
  __int16 v30; // r4
  void *v31; // r0
  int v32; // r2
  unsigned int v33; // r3
  int v34; // r0
  unsigned __int16 v35; // r3
  int v36; // r5
  int v37; // r12
  char *v38; // r2
  char *v39; // r3
  char v40; // t1
  int v41; // r3
  int v42; // r6
  char *v43; // r7
  _BYTE *v44; // r11
  int v45; // r10
  char v46; // r8
  unsigned int v47; // r5
  _BYTE *v48; // r1
  unsigned __int8 *v49; // r0
  int v50; // r2
  unsigned int v51; // r0
  unsigned int v52; // r1
  int v53; // r3
  int v54; // r3
  int v55; // r8
  int v56; // r2
  int v57; // r8
  unsigned __int8 *v58; // r7
  int v59; // r0
  int v60; // r11
  unsigned int i; // r6
  int v62; // [sp+4h] [bp-20h]
  unsigned int v63; // [sp+8h] [bp-1Ch]
  int v64; // [sp+Ch] [bp-18h]
  _BYTE *v65; // [sp+10h] [bp-14h]
  int v66; // [sp+14h] [bp-10h]
  unsigned int v67; // [sp+18h] [bp-Ch]
  int v68; // [sp+1Ch] [bp-8h]

  v4 = a1;
  v5 = *(_DWORD *)(a1 + 72);
  v8 = (_WORD *)(v5 + 108);
  if ( a2 )
  {
    v17 = dword_140858;
    v18 = dword_14085C;
    *(_BYTE *)(v5 + 109) = 0;
    *(_BYTE *)(v5 + 110) = 0;
    *(_BYTE *)(v5 + 111) = 0;
    *(_BYTE *)(v5 + 108) = -48;
    v19 = dword_140860;
    *(_WORD *)(v5 + 112) = *(_WORD *)(696 * *(unsigned __int8 *)(v17 + 6488) + v18);
    *(_WORD *)(v5 + 114) = *(_WORD *)(v18 + 696 * *(unsigned __int8 *)(v17 + 6488) + 2);
    *(_WORD *)(v5 + 116) = *(_WORD *)(v18 + 696 * *(unsigned __int8 *)(v17 + 6488) + 4);
    *(_WORD *)(v5 + 118) = *(_WORD *)(1320 * *(unsigned __int8 *)(v17 + 6489) + v19);
    *(_WORD *)(v5 + 120) = *(_WORD *)(v19 + 1320 * *(unsigned __int8 *)(v17 + 6489) + 2);
    *(_WORD *)(v5 + 122) = *(_WORD *)(v19 + 1320 * *(unsigned __int8 *)(v17 + 6489) + 4);
    v20 = 1320 * *(unsigned __int8 *)(v17 + 6489);
    if ( *(_BYTE *)(v19 + v20 + 6) == 2 )
    {
      *(_WORD *)(v5 + 124) = *(_WORD *)(v20 + v19);
      v9 = 208;
      *(_WORD *)(v5 + 126) = *(_WORD *)(v19 + 1320 * *(unsigned __int8 *)(v17 + 6489) + 2);
      *(_WORD *)(v5 + 128) = *(_WORD *)(v19 + 1320 * *(unsigned __int8 *)(v17 + 6489) + 4);
    }
    else
    {
      v9 = 208;
      *(_WORD *)(v5 + 124) = *(_WORD *)(696 * *(unsigned __int8 *)(v17 + 6488) + v18);
      *(_WORD *)(v5 + 126) = *(_WORD *)(v18 + 696 * *(unsigned __int8 *)(v17 + 6488) + 2);
      *(_WORD *)(v5 + 128) = *(_WORD *)(v18 + 696 * *(unsigned __int8 *)(v17 + 6488) + 4);
    }
  }
  else
  {
    v9 = *(unsigned __int16 *)(v5 + 108);
  }
  v10 = *((_WORD *)off_140854 + 254) + 1;
  *((_WORD *)off_140854 + 254) = v10;
  *(_WORD *)(v5 + 130) = 16 * v10;
  if ( rf_msg_process_body_n37(v4, v9, 5) == 1 )
  {
    fmac_main_loop_0a0(v4, v8, 24);
    v24 = *(unsigned __int8 *)(v4 + 51);
    v11 = v24 + 24;
    v64 = v24 + 27;
  }
  else
  {
    v64 = 27;
    v11 = 24;
  }
  v12 = (char *)v8 + v11;
  *((_BYTE *)v8 + v11) = 5;
  v12[1] = 1;
  v12[2] = *(_BYTE *)a4;
  v13 = (int)v8 + v11 + 3;
  if ( a3 )
  {
    v12[3] = 39;
    v12[4] = 3;
    v12[5] = *(_BYTE *)(a4 + 1);
    v12[6] = a3;
    v12[7] = *(_BYTE *)(a4 + 2);
    v14 = v11 + 8;
  }
  else
  {
    v62 = 0;
    v63 = (unsigned __int16)(512 - v64);
    v66 = v4;
    do
    {
      v21 = (unsigned __int16)(v63 - 5);
      if ( *(_BYTE *)(a4 + 2) == 5 )
      {
        v32 = *(_DWORD *)off_140ACC;
        if ( *(_DWORD *)off_140ACC )
        {
          if ( v21 <= 0x19 )
            break;
          v33 = (unsigned __int16)(v63 - 31);
          if ( *(_BYTE *)(a4 + 32) )
          {
            if ( v33 <= 2 )
              break;
            v33 = (unsigned __int16)(v63 - 34);
          }
          if ( *(_BYTE *)(a4 + 4) )
          {
            if ( v33 <= 3 )
              break;
            v34 = *(unsigned __int16 *)(v32 + 24);
            v35 = v33 - 4;
            v36 = v35;
            if ( *(_WORD *)(v32 + 24) )
            {
              v55 = *(unsigned __int16 *)(v32 + 26);
              v56 = v32 + 64;
              v57 = v55 - v34;
              v58 = (unsigned __int8 *)(v56 + v34);
              if ( *(_BYTE *)(a4 + 4) == 1 )
              {
                v59 = *(unsigned __int8 *)(v56 + v34);
                v60 = v58[2];
                for ( i = (unsigned __int8)(v58[1] + 2);
                      !sub_1404B0(v59, v60, a4) || i > 0xD9;
                      i = (unsigned __int8)(v58[1] + 2) )
                {
                  v57 -= i;
                  v58 += i;
                  if ( !v57 )
                    goto LABEL_90;
                  v59 = *v58;
                }
              }
              if ( v57 )
              {
                if ( v58[1] + 3 >= v36 )
                  break;
              }
              else
              {
LABEL_90:
                if ( **(__int16 **)off_140AD0 < 0 )
                  sub_12F49C(dword_140AE0, dword_140ADC, 1043);
              }
            }
            else if ( v35 <= 0xDu )
            {
              break;
            }
          }
        }
      }
      *(_BYTE *)v13 = 39;
      *(_BYTE *)(v13 + 2) = *(_BYTE *)(a4 + 1);
      *(_BYTE *)(v13 + 3) = 0;
      v22 = *(unsigned __int8 *)(a4 + 2);
      *(_BYTE *)(v13 + 4) = v22;
      if ( v22 == 5 )
      {
        v25 = *(_DWORD *)off_140868;
        ++*(_DWORD *)(a4 + 92);
        v65 = (_BYTE *)(v13 + 5);
        if ( !v25 )
        {
          *(_BYTE *)(v13 + 1) = 3;
          if ( **(__int16 **)off_140AD0 >= 0 )
          {
            v13 += 5;
            v63 = (unsigned __int16)(v63 - 5);
            v23 = 5;
            goto LABEL_14;
          }
          v23 = 5;
          goto LABEL_73;
        }
        *(_BYTE *)(v13 + 5) = *(_BYTE *)(v25 + 19);
        *(_BYTE *)(v13 + 6) = *(_BYTE *)(v25 + 16);
        v26 = *(_QWORD *)(a4 + 40);
        *(_WORD *)(v13 + 15) = *(_WORD *)(a4 + 48);
        *(_QWORD *)(v13 + 7) = v26;
        *(_BYTE *)(v13 + 17) = *(_BYTE *)(v25 + 18);
        *(_BYTE *)(v13 + 18) = sub_12E100(*(char *)(v25 + 20));
        *(_BYTE *)(v13 + 19) = -1;
        v27 = (char *)(v25 + 6);
        do
        {
          v28 = *v27++;
          v27[v13 + 13 - v25] = v28;
        }
        while ( v27 != (char *)(v25 + 12) );
        *(_BYTE *)(v13 + 26) = *(_BYTE *)(v25 + 17);
        *(_DWORD *)(v13 + 27) = *(_DWORD *)(v25 + 12);
        v29 = 257;
        if ( v63 <= 0x101 )
          v29 = v63;
        v65 = (_BYTE *)(v13 + 31);
        if ( *(_BYTE *)(a4 + 32) )
          v30 = v29 - 34;
        else
          v30 = v29 - 31;
        if ( !*(_BYTE *)(a4 + 4) )
        {
          *(_WORD *)(v25 + 24) = *(_WORD *)(v25 + 26);
          goto LABEL_29;
        }
        *v65 = 1;
        v67 = (unsigned __int16)(v30 - 6);
        v37 = v13 + 33;
        if ( *(unsigned __int16 *)(v25 + 24) <= 0xBu )
        {
          if ( **(__int16 **)off_140AD0 < 0 && (unsigned __int16)(v30 - 6) <= 0xBu )
            sub_12F46C(dword_140AD8, dword_140AD4, 1149);
          v38 = (char *)(v25 + 64);
          do
          {
            v39 = v38 - 31;
            v40 = *v38++;
            v39[v13 - v25] = v40;
          }
          while ( v38 != (char *)(v25 + 76) );
          *(_WORD *)(v25 + 24) = 12;
          v67 = (unsigned __int16)(v30 - 18);
          v37 = v13 + 45;
        }
        if ( *(_BYTE *)(a4 + 4) == 1 && !*(_DWORD *)(a4 + 8) && !*(_DWORD *)(a4 + 20) )
        {
          *(_WORD *)(v25 + 24) = *(_WORD *)(v25 + 26);
          goto LABEL_66;
        }
        v41 = *(unsigned __int16 *)(v25 + 24);
        LOWORD(v42) = *(_WORD *)(v25 + 26) - v41;
        v43 = (char *)(v25 + 64 + v41);
        if ( !(_WORD)v42 )
          goto LABEL_66;
        v68 = v13;
        v44 = (_BYTE *)v37;
        v45 = v25;
        while ( 1 )
        {
          v46 = *v43;
          v47 = (unsigned __int8)(v43[1] + 2);
          if ( sub_1404B0((unsigned __int8)*v43, (unsigned __int8)v43[2], a4) && v47 <= 0xD9 )
          {
            if ( (unsigned __int8)v47 > v67 )
            {
LABEL_71:
              v25 = v45;
              v37 = (int)v44;
              v13 = v68;
LABEL_66:
              *(_BYTE *)(v13 + 32) = -2 - (_BYTE)v65 + v37;
              *(_BYTE *)v37 = 2;
              *(_BYTE *)(v37 + 1) = 2;
              v50 = *(unsigned __int8 *)(v25 + 22);
              v51 = *(unsigned __int16 *)(v25 + 24);
              v52 = *(unsigned __int16 *)(v25 + 26);
              v53 = *(unsigned __int8 *)(a4 + 1);
              *(_BYTE *)(v25 + 22) = v50 + 1;
              v54 = v53 | (v50 << 8);
              if ( v51 < v52 )
              {
                *(_WORD *)(v37 + 2) = ~((unsigned int)~(v54 << 17) >> 17);
                v65 = (_BYTE *)(v37 + 4);
LABEL_30:
                if ( *(_BYTE *)(a4 + 32) )
                {
                  *v65 = -92;
                  v65[1] = 1;
                  v65[2] = mmio_read_status();
                  v65 += 3;
                }
                v23 = (unsigned int)&v65[-v13];
                *(_BYTE *)(v13 + 1) = (_BYTE)v65 - v13 - 2;
                v21 = (unsigned __int16)(v63 - ((_WORD)v65 - v13));
                if ( **(__int16 **)off_140864 < 0 && v63 < v23 )
                {
                  v13 = (int)v65;
                  sub_12F46C(dword_140870, dword_14086C, 1287);
                  v63 = v21;
                  goto LABEL_14;
                }
LABEL_73:
                v13 = (int)v65;
                v63 = v21;
                goto LABEL_14;
              }
              *(_WORD *)(v37 + 2) = v54;
              v65 = (_BYTE *)(v37 + 4);
LABEL_29:
              v31 = off_140868;
              *(_WORD *)(v25 + 4) = 3;
              sub_12D2E8((int)v31, (_DWORD *)v25);
              goto LABEL_30;
            }
            if ( v47 )
            {
              v48 = v44;
              v49 = (unsigned __int8 *)(v43 - v44);
              v44 += v47;
              while ( 1 )
              {
                *v48++ = v46;
                if ( v44 == v48 )
                  break;
                v46 = v48[(_DWORD)v49];
              }
            }
            v67 = (unsigned __int16)(v67 - (unsigned __int8)v47);
          }
          v42 = (unsigned __int16)(v42 - (unsigned __int8)v47);
          v43 += v47;
          *(_WORD *)(v45 + 24) += (unsigned __int8)v47;
          if ( !v42 )
            goto LABEL_71;
        }
      }
      *(_BYTE *)(v13 + 1) = 3;
      v63 = (unsigned __int16)(v63 - 5);
      v13 += 5;
      v23 = 5;
LABEL_14:
      v62 += v23;
    }
    while ( !mmio_read_status() && v21 > 4 );
    v4 = v66;
    if ( **(__int16 **)off_140864 < 0 && !v62 )
      sub_12F49C(dword_140874, dword_14086C, 1298);
    v14 = v62 + v64;
  }
  result = *(_DWORD **)(v4 + 76);
  v16 = v14 + *(unsigned __int8 *)(v4 + 53);
  result[8] = result[7] - 1 + v16;
  result[9] = v16 + 4;
  return result;
}

