// v23 annotated: sub_1232F0 @ 0x1232f0
// Original: 1232f0_sub_1232F0.c
// Primary struct: <unclustered>
//
// sub_1232F0 @ 0x1232f0, size 612 bytes
int __fastcall sub_1232F0(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v6; // r1
  int v8; // r2
  int v9; // r8
  int v10; // r11
  int v11; // r9
  unsigned int v12; // r4
  unsigned int v13; // t1
  int v14; // r2
  int v16; // r3
  int v17; // r5
  int v18; // r6
  int v19; // r0
  void (__fastcall *v20)(unsigned int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int); // r10
  int v21; // [sp+0h] [bp-6Ch]
  int v22; // [sp+4h] [bp-68h]
  int v23; // [sp+8h] [bp-64h]
  int v24; // [sp+Ch] [bp-60h]
  int v25; // [sp+10h] [bp-5Ch]
  int v26; // [sp+14h] [bp-58h]
  int v27; // [sp+18h] [bp-54h]
  int v28; // [sp+1Ch] [bp-50h]
  int v29; // [sp+20h] [bp-4Ch]
  int v30; // [sp+24h] [bp-48h]
  int v31; // [sp+28h] [bp-44h]
  int v32; // [sp+2Ch] [bp-40h]
  int v33; // [sp+30h] [bp-3Ch]
  int v34; // [sp+40h] [bp-2Ch]
  int v35; // [sp+4Ch] [bp-20h]
  char v36[5]; // [sp+67h] [bp-5h] BYREF

  v4 = dword_123558;
  v6 = dword_12355C;
  *(_BYTE *)off_123554 = 1;
  msg_parse(v4, v6, 708);
  v33 = 704;
  v32 = 703;
  v31 = 702;
  v30 = 670;
  v29 = 660;
  v23 = 136;
  v24 = 248;
  v22 = 112;
  v27 = 592;
  v28 = 640;
  v25 = 504;
  v26 = 520;
  msg_parse(dword_123560, 0, 4);
  v21 = 112;
  msg_parse(dword_123564, 32, 44);
  v8 = a2 + 520;
  if ( *(_BYTE *)(a2 + 702) )
  {
    v9 = 0;
    v10 = dword_123578;
    v35 = 0;
    v11 = a2 + 668;
    while ( 1 )
    {
      while ( 1 )
      {
        v13 = *(unsigned __int16 *)(v11 + 2);
        v11 += 2;
        v12 = v13;
        msg_parse(v10, v13, v8);
        if ( v13 <= 0x89 )
          break;
        if ( v12 == 5120 )
        {
          v16 = 5;
          v18 = a2 + 136;
          v17 = 5;
          goto LABEL_12;
        }
        if ( v12 == 5122 )
        {
          v16 = 5;
          v18 = a2 + 248;
          v17 = 5;
          goto LABEL_12;
        }
LABEL_16:
        msg_parse(dword_123570, v12, v14);
        if ( *(unsigned __int8 *)(a2 + 702) <= ++v9 )
          goto LABEL_9;
      }
      if ( v12 > 0x64 )
      {
        switch ( v12 )
        {
          case 0x65u:
            v16 = 0;
            v18 = a2 + 504;
            v17 = 0;
            goto LABEL_12;
          case 0x69u:
            v16 = 0;
            v18 = a2 + 112;
            v17 = 0;
            goto LABEL_12;
          case 0x77u:
            v16 = 0;
            v18 = a2 + 4;
            v17 = 0;
            goto LABEL_12;
          case 0x79u:
            v16 = 0;
            v18 = a2 + 83;
            v17 = 0;
            goto LABEL_12;
          case 0x7Bu:
            v16 = 0;
            v17 = 0;
            v18 = a2;
            goto LABEL_12;
          case 0x87u:
            v16 = 0;
            v18 = a2 + 12 * v35 + 592;
            v35 = (unsigned __int8)(v35 + 1);
            v17 = 0;
            goto LABEL_12;
          case 0x89u:
            v16 = 0;
            v18 = a2 + 73;
            v17 = 0;
            goto LABEL_12;
          default:
            goto LABEL_16;
        }
      }
      if ( v12 == 2 )
      {
        v16 = 0;
        v18 = a2 + 520;
        v17 = 0;
        goto LABEL_12;
      }
      if ( v12 == 6 )
      {
        v21 = *(unsigned __int16 *)(a2 + 664);
        v22 = *(unsigned __int16 *)(a2 + 666);
        msg_parse(dword_123568, *(_DWORD *)(a2 + 704), *(unsigned __int8 *)(a2 + 668));
        if ( *(_DWORD *)(a2 + 704) )
        {
          sub_11F7C0((int *)(a2 + 662), *(unsigned __int8 *)(a2 + 660), *(unsigned __int8 *)(a2 + 668), v36);
          if ( *(unsigned __int8 *)(a2 + 702) <= ++v9 )
            break;
        }
        else if ( *(unsigned __int8 *)(a2 + 702) <= ++v9 )
        {
          break;
        }
      }
      else
      {
        if ( v12 )
          goto LABEL_16;
        v17 = 0;
        v16 = 0;
        v18 = 0;
LABEL_12:
        v34 = v16;
        v19 = sub_12CF2C(v12, v17);
        v20 = (void (__fastcall *)(unsigned int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int))v19;
        if ( v19 )
        {
          msg_parse(dword_12356C, v19, v12);
          v20(v12, v18, v17, a4, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33);
          if ( *(unsigned __int8 *)(a2 + 702) <= ++v9 )
            break;
        }
        else
        {
          msg_parse(dword_123574, v12, v34);
          if ( *(unsigned __int8 *)(a2 + 702) <= ++v9 )
            break;
        }
      }
    }
  }
LABEL_9:
  *(_BYTE *)off_123554 = 0;
  return 0;
}

