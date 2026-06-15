// v23 annotated: sub_1222F4 @ 0x1222f4
// Original: 1222f4_sub_1222F4.c
// Primary struct: <unclustered>
//
// sub_1222F4 @ 0x1222f4, size 660 bytes
// Doc: sub_12222F4 [unknown]: Main dispatcher loading signed byte from shared table
// sub_12222F4 [unknown]: Main dispatcher loading signed byte from shared table
_DWORD *__fastcall sub_1222F4(_DWORD *result, int a2)
{
  float *v2; // r4
  int v3; // r7
  int v4; // r5
  int v5; // r6
  int v6; // r8
  float v7; // s17
  float v8; // s16
  int v9; // r3
  _BYTE *v10; // r7
  _DWORD *v11; // r10
  unsigned int *v12; // r9
  unsigned int *v13; // r8
  _DWORD *v14; // r0
  unsigned int v15; // r12
  char *v16; // r11
  _DWORD *v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r3
  unsigned int v20; // r0
  unsigned int v21; // r2
  char v22; // r2
  int v23; // r1
  int v24; // r2
  int v25; // r1
  unsigned int *v26; // r3
  unsigned int *v27; // r2
  unsigned int v28; // r3
  int v29; // r2
  _DWORD *v30; // r12
  _DWORD *v31; // r1
  _BYTE *v32; // r2
  int v33; // r3
  _BYTE *v34; // r0
  int v35; // r2
  unsigned int v37; // [sp+18h] [bp-Ch]
  unsigned __int8 *v38; // [sp+18h] [bp-Ch]

  v2 = (float *)off_122588;
  v3 = *(char *)off_122588;
  if ( !*(_BYTE *)off_122588 )
    return result;
  v4 = (int)result;
  v5 = *((unsigned __int8 *)off_122588 + 2);
  v6 = *((char *)off_122588 + 1);
  v7 = *((float *)off_122588 + 1);
  result = (_DWORD *)msg_get_value(4);
  if ( result )
    return result;
  v8 = (float)((float)(v7 * flt_12258C) + (float)a2) * flt_122590;
  v9 = (char)(int)v8;
  if ( v9 < v3 - v6 )
  {
    v10 = off_122598;
    v5 = 1;
    if ( *((_BYTE *)off_122594 + 408) )
      goto LABEL_8;
LABEL_27:
    v29 = *(unsigned __int8 *)off_1225C0;
    v30 = off_1225D4;
    result = off_1225C4;
    v31 = off_1225C8;
    *(_BYTE *)off_1225D8 = 0;
    *(_DWORD *)v10 = 0;
    *v30 = 0;
    *result = 0;
    *v31 = 0;
    if ( !v29 )
      goto LABEL_22;
    goto LABEL_28;
  }
  if ( v3 < v9 )
    v5 = 0;
  v10 = off_122598;
  if ( !*((_BYTE *)off_122594 + 408) )
    goto LABEL_27;
LABEL_8:
  if ( !v10[8] )
    goto LABEL_27;
  v11 = off_1225D4;
  v12 = (unsigned int *)off_1225C4;
  v13 = (unsigned int *)off_1225C8;
  v14 = off_1225A0;
  v15 = *(_DWORD *)v10;
  v16 = (char *)off_1225D8;
  v17 = (_DWORD *)((char *)off_12259C + 268);
  *(_DWORD *)off_1225D4 += *(_DWORD *)off_12259C;
  v18 = *v13;
  v19 = *v17 + *v12;
  *v12 = v19;
  v20 = *v14 + v18;
  if ( v20 <= v15 )
    v21 = 0;
  else
    v21 = v20 - v15;
  v37 = v21;
  v22 = *v16;
  v23 = *(unsigned __int8 *)off_1225A4;
  *v13 = v20;
  v24 = (unsigned __int8)(v22 + 1);
  *v16 = v24;
  if ( v23 == v24 )
  {
    if ( *(_BYTE *)off_1225B4 == 1 && v19 <= 0x13 && v37 <= 9 )
    {
      v38 = (unsigned __int8 *)off_1225A8;
      *(_BYTE *)off_1225A8 = 2;
    }
    else if ( *((unsigned __int8 *)off_1225A4 + 3) <= v37 || v19 <= v37 * *((unsigned __int8 *)off_1225A4 + 2) )
    {
      v38 = (unsigned __int8 *)off_1225A8;
      *(_BYTE *)off_1225A8 = 0;
    }
    else
    {
      v38 = (unsigned __int8 *)off_1225A8;
      *(_BYTE *)off_1225A8 = 1;
    }
    feature_guard_check(64, dword_1225D0);
    v25 = *v38;
    *v16 = 0;
    *v11 = 0;
    *v12 = 0;
    *v13 = 0;
    *(_DWORD *)v10 = 0;
    if ( v25 == 1 )
    {
      v34 = off_1225B0;
      v35 = *(unsigned __int8 *)off_1225B0;
      *(_BYTE *)off_1225CC = 0;
      if ( v35 != 255 )
        *v34 = v35 + 1;
    }
    else if ( !v25 )
    {
      v32 = off_1225CC;
      v33 = *(unsigned __int8 *)off_1225CC;
      *(_BYTE *)off_1225B0 = 0;
      if ( v33 != 255 )
        *v32 = v33 + 1;
    }
  }
  else
  {
    v25 = *(unsigned __int8 *)off_1225A8;
  }
  v26 = (unsigned int *)off_1225AC;
  *(_DWORD *)off_1225AC &= ~0x4000u;
  *v26 = (unsigned __int16)*v26;
  *v26 = *v26 & 0xFFFFFC00 | 0x44;
  *v26 |= 0x8000u;
  while ( (*v26 & 0x8000) != 0 )
    ;
  v27 = (unsigned int *)off_1225AC;
  *v26 = *v26 & 0xFFFFFC00 | 0x54;
  result = (_DWORD *)(*v26 | 0x8000);
  *v26 = (unsigned int)result;
  while ( (*v27 & 0x8000) != 0 )
    ;
  *v27 = *v27 & 0xFFFFFC00 | 1;
  *v27 |= 0x8000u;
  if ( v25 == 2 )
    goto LABEL_22;
  v28 = *((unsigned __int8 *)off_1225A4 + 1);
  if ( *(unsigned __int8 *)off_1225B0 > v28 )
  {
    if ( *(_BYTE *)off_1225B4 != 1 )
      result = (_DWORD *)sub_12221C(v4);
    goto LABEL_22;
  }
  if ( *(unsigned __int8 *)off_1225CC > v28 >> 1 && *(_BYTE *)off_1225B4 )
LABEL_28:
    result = (_DWORD *)mmio_region_setup_n148(v4);
LABEL_22:
  if ( !v5 || *((_BYTE *)off_1225BC + 18) )
    *(_DWORD *)off_1225B8 &= ~0x200u;
  else
    *(_DWORD *)off_1225B8 |= 0x200u;
  *((_BYTE *)v2 + 2) = v5;
  v2[1] = v8;
  return result;
}

