// v23 annotated: sub_11702C @ 0x11702c
// Original: 11702c_sub_11702C.c
// Primary struct: <unclustered>
//
// sub_11702C @ 0x11702c, size 278 bytes
int __fastcall sub_11702C(int *a1, int a2, _WORD *a3)
{
  _BYTE *v3; // r7
  int v4; // r6
  int v5; // r5
  int *v6; // r9
  _WORD *v7; // r10
  int *v8; // r11
  __int16 v9; // r8
  int v10; // r4
  int v11; // r3
  int v12; // r12
  int v13; // r0
  char v14; // r2
  char v15; // r3
  int *v16; // r3
  int v17; // r3
  int v18; // r3
  __int16 v19; // r0
  __int16 v20; // r3
  int v21; // r2
  int *v22; // r3
  int v23; // r3
  int v25; // [sp+0h] [bp-14h]
  int v26; // [sp+4h] [bp-10h]

  v3 = off_117144;
  v4 = *a1;
  v5 = (unsigned __int16)*a3;
  v6 = (int *)off_117158;
  v7 = off_11715C;
  v8 = (int *)off_117160;
  v9 = 0;
  *((_BYTE *)off_117144 + 2) = 0;
  v26 = 0;
  while ( 1 )
  {
    v19 = *(_WORD *)(v4 + 8);
    v20 = *(_DWORD *)(v4 + 12) + 1;
    v21 = (unsigned __int16)(v20 - v19);
    if ( a2 + v5 >= v21 )
    {
      LOWORD(v10) = v19 - v20 + v5 + a2;
      a2 = (unsigned __int16)(v21 - v5);
      v10 = (unsigned __int16)v10;
      v5 = 0;
    }
    else
    {
      v10 = 0;
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_117148 = 1;
    }
    v11 = (unsigned __int16)*v7;
    v12 = *v6;
    v25 = *v8;
    v13 = *v8 + 8 * v11;
    *(_DWORD *)(v13 + 4) = *(_DWORD *)(v4 + 8);
    *v6 = v12 + 1;
    *(_DWORD *)(v25 + 8 * v11) = a2;
    v14 = v3[3] + 1;
    v9 += a2;
    *v7 = v11 + 1;
    v3[3] = v14;
    if ( v10 )
    {
      if ( v12 == -1 )
        goto LABEL_10;
      v22 = (int *)off_117148;
      *v6 = v12;
      v23 = *v22;
      if ( v12 || !v23 )
        goto LABEL_10;
      goto LABEL_9;
    }
    v15 = *(_BYTE *)(v13 + 3);
    *(_WORD *)v3 = v9;
    *(_BYTE *)(v13 + 3) = v15 | 4;
    v3[2] = 1;
    *((_DWORD *)v3 + 2) = v13;
    if ( v12 == -1 )
      break;
    v16 = (int *)off_117148;
    *v6 = v12;
    v17 = *v16;
    if ( v12 || !v17 )
      break;
LABEL_9:
    __enable_irq();
    if ( !v10 )
      break;
LABEL_10:
    v18 = *(_DWORD *)(v4 + 4);
    if ( **(__int16 **)off_11714C < 0 && !v18 )
    {
      rf_cmd_send_n264(dword_117154, dword_117150, 615);
      v18 = 0;
    }
    v26 = v4;
    a2 = v10;
    v4 = v18;
  }
  *a1 = v4;
  *a3 = v5;
  return v26;
}

