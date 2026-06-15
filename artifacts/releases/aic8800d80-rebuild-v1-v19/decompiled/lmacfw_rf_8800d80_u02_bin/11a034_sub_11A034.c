// sub_11A034 @ 0x11a034, size 1760 bytes
int __fastcall sub_11A034(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v8; // r0
  __int16 **v10; // r8
  int v11; // r3
  char **v12; // r7
  int v13; // r5
  _BYTE *v14; // r5
  _BYTE *v15; // r0
  unsigned int v16; // r0
  char *v17; // r2
  int v18; // r0
  int v19; // r6
  _DWORD *v20; // r2
  int v21; // r2
  int v22; // r1
  int v23; // r3
  int v24; // r2
  char *v25; // r3
  int v26; // r1
  int v27; // r0
  bool v28; // zf
  char *v29; // r5
  int v30; // r2
  int v31; // r7
  int v32; // r9
  int v33; // r8
  int v34; // r0
  int v35; // r11
  int v36; // r1
  _DWORD *v37; // r1
  _DWORD *v38; // r3
  int v39; // r2
  int v40; // r2
  int v41; // r2
  int v42; // r3
  _DWORD *v43; // r3
  int v44; // r2
  char v45; // r7
  _BYTE *v46; // r0
  int v47; // r3
  int v48; // [sp+Ch] [bp-18h]
  int v49; // [sp+10h] [bp-14h]
  int v50; // [sp+10h] [bp-14h]
  _BYTE v51[5]; // [sp+1Fh] [bp-5h] BYREF

  v8 = sub_11E34C(a3);
  if ( v8 )
  {
    if ( (unsigned __int16)(v8 - 2) > 2u )
    {
      v14 = off_11A2E4;
      *((_BYTE *)off_11A2E4 + 17) = *(_BYTE *)off_11A2E8 & 0xF;
      v14[16] = sub_11E34C(a3);
      sub_11D01C();
      sub_11E1E4(a3);
    }
    return 2;
  }
  else
  {
    v10 = (__int16 **)off_11A308;
    v11 = **(__int16 **)off_11A308;
    if ( v11 < 0 )
    {
      if ( *(_DWORD *)off_11A2E8 << 28 )
      {
        rf_cmd_send_n264(dword_11A688, dword_11A680, 2493);
        switch ( a1 )
        {
          case 6:
          case 7:
          case 8:
          case 9:
          case 10:
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 21:
          case 22:
          case 23:
          case 24:
          case 25:
          case 26:
          case 27:
          case 28:
          case 29:
          case 30:
          case 31:
          case 32:
          case 33:
          case 34:
          case 35:
          case 36:
          case 37:
          case 38:
          case 39:
          case 40:
          case 41:
          case 42:
          case 43:
          case 44:
          case 45:
          case 46:
          case 47:
          case 48:
          case 49:
          case 50:
          case 51:
          case 52:
          case 53:
          case 54:
          case 55:
          case 56:
          case 57:
          case 58:
          case 59:
            MEMORY[4] = 0;
            JUMPOUT(0x13E292);
          default:
            if ( **v10 < 0 )
            {
LABEL_58:
              v12 = (char **)off_11A660;
              rf_cmd_send_n264(dword_11A684, dword_11A680, 2552);
              v13 = 2;
            }
            else
            {
              v12 = (char **)off_11A660;
              v13 = 2;
            }
            break;
        }
      }
      else
      {
        switch ( a1 )
        {
          case 6:
LABEL_12:
            v15 = (_BYTE *)rf_setup_dispatch(7, a4, a3, 2);
            v13 = 0;
            *v15 = 0;
            sub_11DE50(v15);
            v12 = (char **)off_11A2E4;
            break;
          case 8:
LABEL_13:
            v16 = *a2;
            if ( v16 <= 3 )
              v16 = sub_1180B8(v16);
            if ( !*((_DWORD *)off_11A2EC + 2) )
              sub_11D3DC(v16);
            sub_11DED8(9, a4, a3);
            v12 = (char **)off_11A2E4;
            v13 = 0;
            break;
          case 14:
LABEL_18:
            v12 = (char **)off_11A2E4;
            v17 = *(char **)a2;
            *(_DWORD *)off_11A2E4 = *(_DWORD *)a2;
            if ( v11 < 0 && *(_DWORD *)off_11A68C << 28 )
            {
              sub_1219F4(dword_11A688, dword_11A690, 472);
              v17 = *v12;
            }
            *(_DWORD *)off_11A2F0 = (unsigned int)v17 | (unsigned int)v12[1];
            sub_11DED8(15, a4, a3);
            v13 = 0;
            break;
          case 16:
LABEL_20:
            v18 = rf_setup_dispatch(17, a4, a3, 2);
            v12 = (char **)off_11A2E4;
            v19 = v18;
            sub_102908(a2, a2[10]);
            sub_11DE50(v19);
            v13 = 0;
            break;
          case 18:
LABEL_21:
            v20 = off_11A2F4;
            v12 = (char **)off_11A2E4;
            *(_DWORD *)off_11A2F4 = *(_DWORD *)off_11A2F4 & 0xFFFFFF00 | *a2;
            *v20 |= 0x80000000;
            sub_11DED8(19, a4, a3);
            v13 = 0;
            break;
          case 20:
LABEL_22:
            v21 = a2[2];
            v22 = *(unsigned __int16 *)a2;
            v23 = dword_11A2F8 + 224 * v21;
            if ( *(_BYTE *)(v23 + 94) )
            {
              sub_118340(dword_11A2F8 + 224 * v21, v22);
            }
            else
            {
              v24 = *(unsigned __int8 *)(v23 + 102);
              if ( v24 == 255 )
                *(_WORD *)(v23 + 100) = v22;
              else
                *(_DWORD *)(dword_11A2FC + 152 * v24 + 8) = v22 << 10;
            }
            sub_11DED8(21, a4, a3);
            v12 = (char **)off_11A2E4;
            v13 = 0;
            break;
          case 22:
LABEL_26:
            v25 = *(char **)a2;
            v26 = a2[5];
            v12 = (char **)off_11A2E4;
            v27 = *((_DWORD *)off_11A300 + 10);
            v29 = (char *)(*(_DWORD *)a2 & 0xFFFFF1FF);
            v28 = v29 == nullptr;
            v30 = v26 + 4;
            if ( v29 )
              v25 = (char *)off_11A2E4 + 4 * v30;
            else
              v29 = (char *)off_11A2E4 + 4 * v30;
            if ( v28 )
              *((_DWORD *)v29 + 1) = v25;
            else
              *((_DWORD *)v25 + 1) = v29;
            if ( v27 && *(unsigned __int8 *)(v27 + 4) == v26 )
              *(_DWORD *)off_11A304 = v12[v30 + 1];
            sub_11DED8(23, a4, a3);
            v13 = 0;
            break;
          case 24:
LABEL_52:
            v12 = (char **)off_11A660;
            sub_1282E8(dword_11A66C + 224 * a2[6] + 64, a2, 6);
            v43 = off_11A674;
            v44 = *((unsigned __int16 *)a2 + 2);
            *(_DWORD *)off_11A670 = *(_DWORD *)a2;
            *v43 = v44;
            sub_11DED8(25, a4, a3);
            v13 = 0;
            break;
          case 28:
LABEL_53:
            v12 = (char **)off_11A660;
            *(_DWORD *)off_11A678 = (*a2 << 14) & 0x1C000 | *(_DWORD *)off_11A678 & 0xFFFE3FFF;
            sub_11DED8(29, a4, a3);
            v13 = 0;
            break;
          case 30:
LABEL_36:
            v31 = a2[3];
            v32 = dword_11A66C;
            v33 = dword_11A66C + 224 * v31;
            v51[0] = 0;
            v34 = sub_118374(v51);
            v35 = *(unsigned __int8 *)(v33 + 94);
            v36 = a2[2];
            *(_BYTE *)(v33 + 96) = v36;
            if ( !v35 )
            {
              v48 = 224 * v31;
              if ( v36 )
              {
                v49 = dword_11A63C + 152 * *(unsigned __int8 *)(v33 + 102);
                sub_11AB18(v48 + 24 + v32, *((_DWORD *)off_11A640 + 4) + *(_DWORD *)(v49 + 8));
                *(_WORD *)(v49 + 30) = *(_WORD *)a2;
                sub_118354();
                sub_11F74C(256, dword_11A644, *(unsigned __int8 *)(v49 + 33), *(unsigned __int16 *)(v49 + 30));
                *(_DWORD *)off_11A648 = (unsigned __int16)*(_DWORD *)off_11A648 | (*(unsigned __int16 *)a2 << 16);
                v37 = off_11A640;
                *(_BYTE *)(v33 + 116) = 0;
                *(_DWORD *)(v33 + 112) = 0;
                *(_DWORD *)(v33 + 108) = v37[4];
                rf_msg_handler_n0ec(v32 + v48);
                v36 = a2[2];
              }
              else
              {
                v50 = v34;
                timestamp_remove(v48 + 24 + v32);
                sub_11F74C(256, dword_11A714, v50, v50);
                if ( (*(_DWORD *)off_11A718 & 0x8000) != 0 )
                  sub_101A2C();
                v47 = v32 + 224 * v31;
                *(_BYTE *)(v47 + 140) = 0;
                *(_DWORD *)(v47 + 144) = 0;
                v36 = a2[2];
              }
            }
            if ( v36 )
            {
              v38 = *(_DWORD **)off_11A64C;
              v39 = **(_DWORD **)off_11A64C;
              if ( v39 )
                *(_DWORD *)off_11A650 = v39;
              else
                *(_DWORD *)off_11A724 = *(_DWORD *)(v32 + 224 * v31 + 8);
              v40 = v38[1];
              if ( v40 )
              {
                if ( (v40 & 0xFFF) != 0 )
                  *(_DWORD *)off_11A720 = v40;
                else
                  *(_DWORD *)off_11A654 = v40 & 0xFFFFF000 | *(_DWORD *)(v32 + 224 * v31 + 12) & 0xFFF;
              }
              else
              {
                *(_DWORD *)off_11A720 = *(_DWORD *)(v32 + 224 * v31 + 12);
              }
              v41 = v38[2];
              if ( v41 )
                *(_DWORD *)off_11A658 = v41;
              else
                *(_DWORD *)off_11A71C = *(_DWORD *)(v32 + 224 * v31 + 16);
              v42 = v38[3];
              if ( v42 )
                *(_DWORD *)off_11A65C = v42;
              else
                *(_DWORD *)off_11A65C = *(_DWORD *)(v32 + 224 * v31 + 20);
              sub_1183A0();
            }
            sub_11DED8(31, a4, a3);
            v12 = (char **)off_11A660;
            v13 = 0;
            break;
          case 32:
LABEL_51:
            v12 = (char **)off_11A660;
            *(_DWORD *)off_11A668 = *a2 | (((unsigned __int8)*(_DWORD *)off_11A664 * *a2) << 8);
            sub_11DED8(33, a4, a3);
            v13 = 0;
            break;
          case 40:
LABEL_54:
            if ( *a2 )
            {
              *(_DWORD *)off_11A67C |= 0x80u;
              v45 = 0;
            }
            else
            {
              v45 = 5;
            }
            v46 = (_BYTE *)rf_setup_dispatch(41, a4, a3, 3);
            *v46 = a2[1];
            v46[1] = a2[2];
            v46[2] = v45;
            sub_11DE50(v46);
            v12 = (char **)off_11A660;
            v13 = 0;
            break;
          case 48:
LABEL_57:
            sub_121A10(a2);
            v12 = (char **)off_11A660;
            v13 = 0;
            break;
          case 59:
LABEL_11:
            sub_11BE28(a2);
            sub_11DED8(60, a4, a3);
            v12 = (char **)off_11A2E4;
            v13 = 0;
            break;
          default:
            goto LABEL_58;
        }
      }
    }
    else
    {
      switch ( a1 )
      {
        case 6:
          goto LABEL_12;
        case 8:
          goto LABEL_13;
        case 14:
          goto LABEL_18;
        case 16:
          goto LABEL_20;
        case 18:
          goto LABEL_21;
        case 20:
          goto LABEL_22;
        case 22:
          goto LABEL_26;
        case 24:
          goto LABEL_52;
        case 28:
          goto LABEL_53;
        case 30:
          goto LABEL_36;
        case 32:
          goto LABEL_51;
        case 40:
          goto LABEL_54;
        case 48:
          goto LABEL_57;
        case 59:
          goto LABEL_11;
        default:
          v12 = (char **)off_11A2E4;
          v13 = 2;
          break;
      }
    }
    *(_DWORD *)off_11A2E8 = (unsigned __int8)(16 * *((_BYTE *)v12 + 17));
    sub_11E1E4(a3);
    return v13;
  }
}

