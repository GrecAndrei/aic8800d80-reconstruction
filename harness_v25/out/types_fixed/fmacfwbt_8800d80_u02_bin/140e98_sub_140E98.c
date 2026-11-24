// sub_140E98 @ 0x140e98, size 1658 bytes
int __fastcall sub_140E98(char a1, char a2, int a3, _DWORD *a4, int a5)
{
  int v5; // r2
  int result; // r0
  int v8; // r8
  unsigned __int8 *v9; // r7
  _DWORD *v10; // r10
  _BYTE *v11; // r4
  _BYTE *v12; // t1
  int v13; // r5
  char v14; // r3
  int v15; // r2
  int v16; // r1
  char v17; // r3
  int v18; // r6
  __int16 v19; // r4
  unsigned int v20; // r0
  int v21; // r1
  int v22; // r2
  char v23; // r3
  unsigned int v24; // r1
  unsigned int v25; // r3
  unsigned __int8 *v26; // lr
  unsigned __int8 *v27; // r3
  char v28; // r3
  unsigned int v29; // r2
  unsigned __int8 *v30; // r3
  unsigned __int8 *v31; // r5
  unsigned __int8 *v32; // r8
  unsigned int v33; // r4
  unsigned int v34; // r1
  unsigned __int8 *v35; // r2
  unsigned int v36; // r0
  unsigned int v37; // r11
  unsigned __int8 *v38; // r11
  unsigned int v39; // r4
  unsigned __int8 *v40; // r4
  _BYTE *v41; // r2
  int v42; // r1
  unsigned int v43; // r2
  int v44; // r2
  unsigned __int8 *v45; // r3
  unsigned int v46; // r6
  unsigned __int8 *v47; // r5
  int v48; // r1
  unsigned __int8 *v49; // r6
  char v50; // r4
  unsigned __int8 *v51; // r2
  int i; // r3
  unsigned __int8 *v53; // r2
  int j; // r3
  int v55; // r5
  int v56; // r2
  unsigned __int8 *v57; // r1
  char v58; // r3
  unsigned __int8 v59; // r3
  unsigned int v60; // r2
  __int16 **v61; // r3
  unsigned int v62; // r1
  unsigned int v63; // r3
  unsigned int v64; // r1
  unsigned int v65; // r3
  unsigned int v67; // [sp+8h] [bp-ACh]
  unsigned int v70; // [sp+14h] [bp-A0h]
  int v71; // [sp+18h] [bp-9Ch]
  unsigned int v72; // [sp+1Ch] [bp-98h]
  _BYTE *(_DWORD *)(v73 + 0x230); // [sp+28h] [bp-8Ch] BYREF

  v5 = dword_141198;
  *(_BYTE *)(dword_141198 + 6488) = a2;
  *(_BYTE *)(v5 + 6489) = a1;
  result = -1;
  *(_DWORD *)(v5 + 6480) = -1;
  *(_DWORD *)(v5 + 6484) = 0;
  if ( a5 <= 0 )
    return result;
  v8 = 0;
  v9 = (unsigned __int8 *)(v5 + 6336);
  do
  {
    v10 = a4;
    v12 = (_BYTE *)*a4++;
    v11 = v12;
    v13 = (unsigned __int8)*(_DWORD *)(v12 + 0x4);
    if ( (unsigned int)(v13 + 2) <= 4 )
    {
      v16 = 4;
      goto LABEL_8;
    }
    result = sub_100200(v9, 0, 136);
    *(_DWORD *)(v9 + 0x4) = *(_DWORD *)(v11 + 0x8);
    v14 = *(_DWORD *)(v11 + 0xc);
    v15 = (unsigned __int8)*(_DWORD *)(v11 + 0x10);
    *(_DWORD *)(v9 + 0x8) = v15;
    if ( (v14 & 1) != 0 )
      goto LABEL_7;
    if ( (v14 & 2) != 0 )
    {
      if ( *v9 == a3 )
        goto LABEL_23;
      goto LABEL_11;
    }
    if ( v15 != 5 )
      goto LABEL_7;
    if ( (unsigned int)(v13 - 3) <= 0xC )
      goto LABEL_46;
    v25 = (unsigned __int8)*(_DWORD *)(v11 + 0x2c);
    *(_DWORD *)(v9 + 0xc) = v25;
    if ( v25 > 2 )
    {
LABEL_7:
      v11 = (_BYTE *)*v10;
      v16 = 2;
      goto LABEL_8;
    }
    v70 = (unsigned __int8)*(_DWORD *)(v11 + 0x14);
    v72 = (unsigned __int8)*(_DWORD *)(v11 + 0x18);
    *((_WORD *)v9 + 24) = (unsigned __int8)*(_DWORD *)(v11 + 0x24);
    v26 = v9 + 58;
    v27 = v9 + 52;
    do
    {
      *v27 = v27[v11 - v9 - 40];
      ++v27;
    }
    while ( v26 != v27 );
    v28 = -1;
    LOWORD(v29) = v13 - 16;
    if ( *((unsigned __int16 *)v9 + 26) == 0xFFFF )
      v28 = 1;
    v29 = (unsigned __int16)v29;
    if ( *((unsigned __int16 *)v9 + 26) == 0xFFFF )
      *(_DWORD *)(v9 + 0xc8) = v28;
    v30 = v11 + 18;
    *(_DWORD *)(v9 + 0x10) = 2;
    if ( (unsigned __int16)v29 <= 2u )
    {
      if ( *(_DWORD *)(v9 + 0xc) > 1u )
        goto LABEL_22;
      if ( v70 <= 0x72 )
      {
        *(_DWORD *)(v9 + 0x190) = 0;
        if ( v72 == 255 )
          goto LABEL_46;
        goto LABEL_77;
      }
      *(_DWORD *)(v9 + 0x190) = 1;
      if ( v72 == 255 )
        goto LABEL_46;
      goto LABEL_82;
    }
    v31 = nullptr;
    v71 = v8;
    v32 = nullptr;
    do
    {
      while ( 1 )
      {
        result = *(_DWORD *)(v30 + 0x4);
        v33 = *v30;
        v34 = result + 2;
        if ( result + 2 > v29 )
          goto LABEL_46;
        if ( v33 <= 0xB )
        {
          switch ( *v30 )
          {
            case 0u:
              if ( v34 > 0x22 )
                goto LABEL_46;
              *(_DWORD *)(v9 + 0xe8) = result;
              if ( !result )
                goto LABEL_40;
              v40 = &v26[result];
              result = (int)(v9 + 58);
              do
              {
                *(_BYTE *)(result + 1) = v30[result + -56 - (_DWORD)v9];
                ++result;
              }
              while ( v40 != (unsigned __int8 *)result );
              v29 = (unsigned __int16)(v29 - v34);
              v30 += v34;
              if ( v29 <= 2 )
                goto LABEL_41;
              continue;
            case 2u:
              v29 = (unsigned __int16)(v29 - v34);
              result = *(_DWORD *)(v30 + 0x8);
              *(_DWORD *)(v9 + 0x10) = result;
              v30 += v34;
              if ( v29 <= 2 )
                goto LABEL_41;
              continue;
            case 0xAu:
              v39 = *(_DWORD *)(v30 + 0x4);
              if ( v39 >= 8 )
                v39 = 8;
              *((_DWORD *)v9 + 2) = v39;
              if ( !result )
                goto LABEL_40;
              result = (int)(v9 + 11);
              do
              {
                *(_BYTE *)(result + 1) = v30[result + -9 - (_DWORD)v9];
                ++result;
              }
              while ( &v9[v39 + 11] != (unsigned __int8 *)result );
              v29 = (unsigned __int16)(v29 - v34);
              v30 += v34;
              if ( v29 <= 2 )
                goto LABEL_41;
              continue;
            case 0xBu:
              if ( !*(_DWORD *)(v30 + 0x4) )
                goto LABEL_46;
              if ( *(_DWORD *)(v30 + 0x8) != 255 )
                goto LABEL_40;
              v37 = (unsigned __int8)(result - 1);
              if ( v37 >= 8 )
                v37 = 8;
              *((_DWORD *)v9 + 5) = v37;
              if ( result == 1 )
                goto LABEL_40;
              result = (int)(v9 + 23);
              v38 = &v9[v37 + 23];
              do
              {
                *(_BYTE *)(result + 1) = v30[result + -20 - (_DWORD)v9];
                ++result;
              }
              while ( (unsigned __int8 *)result != v38 );
              v29 = (unsigned __int16)(v29 - v34);
              v30 += v34;
              if ( v29 <= 2 )
                goto LABEL_41;
              continue;
            default:
              goto LABEL_40;
          }
        }
        if ( v33 == 163 )
        {
          v32 = v30;
          goto LABEL_40;
        }
        if ( v33 != 164 )
          break;
        result = *(_DWORD *)(v30 + 0x8);
        *(_DWORD *)(v9 + 0x80) = result;
LABEL_40:
        v29 = (unsigned __int16)(v29 - v34);
        v30 += v34;
        if ( v29 <= 2 )
          goto LABEL_41;
      }
      v29 = (unsigned __int16)(v29 - v34);
      if ( v33 == 51 )
        v31 = v30;
      v30 += v34;
    }
    while ( v29 > 2 );
LABEL_41:
    v35 = v32;
    v8 = v71;
    if ( *(_DWORD *)(v9 + 0xc) > 1u )
      goto LABEL_22;
    if ( v70 > 0x72 )
    {
      result = 1;
      *(_DWORD *)(v9 + 0x190) = 1;
      if ( v35 )
      {
        v20 = *(unsigned __int16 *)(v35 + 3);
        v21 = *((unsigned __int16 *)v35 + 2);
        v22 = *(_DWORD *)(v35 + 0x8);
        *(_DWORD *)(v9 + 0x190) = v20 > 0x1388;
        if ( v20 > 0x1388 && v70 <= 0xB1 )
          goto LABEL_17;
        goto LABEL_46;
      }
      if ( v72 == 255 )
        goto LABEL_88;
LABEL_82:
      if ( v72 )
      {
        if ( v72 > 0xB1 )
          goto LABEL_46;
LABEL_79:
        *(_DWORD *)(v9 + 0x198) = v72;
        *(_DWORD *)(v9 + 0x194) = 1;
LABEL_80:
        v41 = v9 + 102;
        switch ( v70 )
        {
          case 0x53u:
          case 0x74u:
          case 0x77u:
          case 0x7Au:
          case 0x7Eu:
            goto LABEL_20;
          case 0x54u:
          case 0x75u:
          case 0x78u:
          case 0x7Bu:
          case 0x7Fu:
            goto LABEL_86;
          case 0x80u:
            goto LABEL_141;
          case 0x81u:
            v70 = v72;
            goto LABEL_129;
          default:
            goto LABEL_85;
        }
      }
LABEL_107:
      v49 = v9 + 102;
      switch ( v70 )
      {
        case 0x51u:
        case 0x53u:
        case 0x54u:
          result = 1;
          v56 = 1;
          v50 = 0;
          v55 = 14;
          goto LABEL_115;
        case 0x52u:
          v50 = 0;
          result = 1;
          v55 = 15;
          v56 = 14;
          goto LABEL_115;
        case 0x73u:
        case 0x74u:
        case 0x75u:
          v50 = 0;
          result = 4;
          v55 = 49;
          v56 = 36;
          goto LABEL_115;
        case 0x76u:
        case 0x77u:
        case 0x78u:
          v50 = 0;
          result = 4;
          v55 = 65;
          v56 = 52;
          goto LABEL_115;
        case 0x79u:
        case 0x7Au:
        case 0x7Bu:
          v50 = 0;
          result = 4;
          v55 = 145;
          v56 = 100;
          goto LABEL_115;
        case 0x7Cu:
          v50 = 0;
          result = 4;
          v55 = 162;
          v56 = 149;
          goto LABEL_115;
        case 0x7Du:
        case 0x7Eu:
        case 0x7Fu:
          v55 = 178;
          result = 4;
          v50 = 0;
          v56 = 149;
          goto LABEL_115;
        case 0x80u:
        case 0x82u:
          *((_WORD *)v9 + 51) = -30588;
          *((_WORD *)v9 + 52) = -28532;
          v49 = v9 + 106;
          v50 = 20;
          goto LABEL_110;
        case 0x81u:
          v50 = 16;
LABEL_110:
          v51 = v49 - 1;
          for ( i = 36; i != 68; i += 4 )
            *++v51 = i;
          v53 = v49 + 7;
          for ( j = 100; j != 132; j += 4 )
            *++v53 = j;
          v49 += 16;
          result = 4;
          v55 = 178;
          v56 = 149;
LABEL_115:
          v57 = v49 - 1;
          do
          {
            v58 = (_BYTE)v57 + 2;
            *++v57 = v56;
            v56 += result;
            v59 = v58 + v50 - (_BYTE)v49;
          }
          while ( v55 > v56 );
          v60 = v59;
          v61 = (__int16 **)off_141514;
          *(_DWORD *)(v9 + 0x194) = v60;
          v67 = v60;
          if ( **v61 < 0 && v60 > 0x1C )
          {
            result = sub_12F694(off_14151C, off_141518[0], 769);
            v67 = *(_DWORD *)(v9 + 0x194);
          }
          if ( !v67 )
            goto LABEL_46;
          goto LABEL_105;
        default:
          *(_DWORD *)(v9 + 0x194) = 0;
          goto LABEL_46;
      }
    }
    *(_DWORD *)(v9 + 0x190) = 0;
    if ( v35 )
    {
      v36 = *(unsigned __int16 *)(v35 + 3);
      v21 = *((unsigned __int16 *)v35 + 2);
      v22 = *(_DWORD *)(v35 + 0x8);
      *(_DWORD *)(v9 + 0x190) = v36 > 0x1388;
      if ( v36 <= 0x1388 )
      {
        if ( (unsigned __int8)(v70 - 1) > 0xDu )
          goto LABEL_46;
LABEL_17:
        result = v70;
        *(_DWORD *)(v9 + 0x198) = v70;
        v23 = 1;
        *(_DWORD *)(v9 + 0x194) = 1;
        if ( !v22 )
        {
          v24 = v72;
          *(_DWORD *)(v9 + 0x190) = 0;
          if ( v70 != v72 )
          {
            LOBYTE(v72) = v70;
            if ( v70 >= v24 )
            {
LABEL_86:
              *(_DWORD *)(v9 + 0x19c) = v72 - 4;
              v23 = 2;
            }
            else
            {
LABEL_20:
              *(_DWORD *)(v9 + 0x19c) = v72 + 4;
              v23 = 2;
            }
          }
          goto LABEL_21;
        }
        if ( v22 != 1 || v21 )
        {
          v41 = v9 + 102;
LABEL_129:
          if ( v70 >= 0x41 )
            v62 = 128;
          else
            v62 = 64;
          if ( v70 >= 0x41 )
            v63 = 100;
          else
            v63 = 36;
          do
          {
            result = v63 + 4;
            *v41++ = v63;
            v63 = (unsigned __int8)(v63 + 4);
          }
          while ( v62 >= v63 );
          v23 = 8;
          goto LABEL_21;
        }
        v72 = v70;
        v41 = v9 + 102;
LABEL_141:
        if ( v72 <= 0x23 )
          goto LABEL_85;
        if ( v72 <= 0x30 )
        {
          v64 = 48;
          v65 = 36;
        }
        else if ( v72 <= 0x40 )
        {
          v64 = 64;
          v65 = 52;
        }
        else if ( v72 <= 0x70 )
        {
          v64 = 112;
          v65 = 100;
        }
        else
        {
          if ( v72 > 0x80 )
          {
            if ( v72 <= 0x90 )
            {
              v64 = 144;
              v65 = 132;
              goto LABEL_148;
            }
LABEL_85:
            v23 = 1;
LABEL_21:
            *(_DWORD *)(v9 + 0x194) = v23;
            goto LABEL_22;
          }
          v64 = 128;
          v65 = 116;
        }
        do
        {
LABEL_148:
          result = v65 + 4;
          *v41++ = v65;
          v65 = (unsigned __int8)(v65 + 4);
        }
        while ( v64 >= v65 );
        v23 = 4;
        goto LABEL_21;
      }
      if ( v70 )
        goto LABEL_17;
LABEL_46:
      v11 = (_BYTE *)*v10;
      v16 = 4;
LABEL_8:
      v17 = *(_DWORD *)(v11 + 0x10);
      *(_DWORD *)(v73 + 0x0) = a3;
      *(_DWORD *)(v73 + 0x8) = v17;
      v18 = dword_141198;
      v19 = *(_WORD *)(dword_141198 + 6488);
      *(_BYTE *)(dword_141198 + 6488) = a2;
      *(_BYTE *)(v18 + 6489) = a1;
      result = sub_140B80(v73, v16);
      *(_WORD *)(v18 + 6488) = v19;
      return result;
    }
    if ( v72 != 255 )
    {
LABEL_77:
      if ( v72 )
      {
        if ( v72 > 0xE )
          goto LABEL_46;
        goto LABEL_79;
      }
      goto LABEL_107;
    }
    result = 0;
LABEL_88:
    if ( !v31 )
      goto LABEL_46;
    v42 = *(_DWORD *)(v31 + 0x4);
    v43 = (unsigned __int8)(v42 - 1);
    if ( v43 >= 0x1C )
      LOBYTE(v43) = 28;
    v44 = (unsigned __int8)(v43 - 1);
    v45 = v31 + 3;
    if ( v42 == 1 )
      goto LABEL_46;
    v46 = 0;
    v47 = &v31[v44 + 4];
    while ( 2 )
    {
      v48 = *v45;
      if ( result )
      {
        if ( (unsigned __int8)(v48 - 1) > 0xB0u )
          goto LABEL_95;
LABEL_94:
        v9[v46 + 102] = v48;
        v46 = (unsigned __int8)(v46 + 1);
        goto LABEL_95;
      }
      if ( (unsigned int)(v48 - 1) <= 0xD )
        goto LABEL_94;
LABEL_95:
      if ( ++v45 != v47 )
        continue;
      break;
    }
    v67 = v46;
    if ( !v46 )
      goto LABEL_46;
    *(_DWORD *)(v9 + 0x194) = v46;
LABEL_105:
    if ( v67 == 1 )
    {
      v72 = *(_DWORD *)(v9 + 0x198);
      goto LABEL_80;
    }
LABEL_22:
    *v9 = a3;
LABEL_23:
    v9 += 136;
    ++*(_DWORD *)off_14119C;
LABEL_11:
    ++v8;
  }
  while ( a5 != v8 );
  return result;
}

