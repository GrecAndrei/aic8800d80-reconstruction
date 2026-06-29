// fwstruct annotate: 1242f0_sub_1242F0.c
// sub_1242F0 @ 0x1242f0, size 476 bytes
int __fastcall sub_1242F0(unsigned int a1)
{
  int v2; // r7
  int v3; // r5
  int v4; // r0
  int result; // r0
  int v6; // r6
  int v7; // r5
  int v8; // r3
  int v9; // r2
  _BYTE *v10; // r3
  char v11; // r0
  char v12; // r1
  _BYTE *v13; // r1
  __int16 v14; // r3
  __int16 v15; // r2
  _BYTE *v16; // r7
  char v17; // r0
  __int16 *v18; // r8
  unsigned int v19; // r4
  __int16 v20; // r3
  _BYTE *v21; // r2
  char v22; // r1
  unsigned int v23; // r3
  char *v24; // r0
  __int16 v25; // r2
  bool v26; // cc
  char v27; // r3
  int v28; // r0
  __int64 v29; // [sp+0h] [bp-8h] BYREF

  if ( a1 == 128 )
  {
    v3 = 100;
    v2 = 10240;
  }
  else if ( a1 == 129 )
  {
    v3 = 500;
    v2 = 10244;
  }
  else
  {
    v2 = 10249;
    if ( a1 == 1 )
    {
      v3 = 2000;
    }
    else
    {
      v3 = 200;
      v2 = 10240;
    }
  }
  sub_1019EC(&v29, 0);
  v4 = (unsigned __int8)v29;
  if ( (_BYTE)v29 )
    v4 = 1;
  result = sub_116580(v4, v3);
  v6 = result;
  if ( result )
  {
    v7 = *(_DWORD *)(result + 28);
    v8 = *(_DWORD *)off_1244D0;
    *(_DWORD *)(v7 + 48) = *(_DWORD *)off_1244CC;
    v9 = dword_1244D4;
    *(_DWORD *)(v7 + 64) = v2;
    *(_DWORD *)(v7 + 80) = v9;
    *(_DWORD *)(v7 + 52) = v8;
    if ( a1 == 128 )
    {
      sub_123AB4(v7 + 104);
      v23 = *(unsigned __int8 *)off_1244EC;
      v24 = (char *)off_1244E0;
      v25 = *(_WORD *)off_1244DC;
      *(_BYTE *)(v7 + 128) = 0x80;
      v23 -= 2;
      v26 = v23 > 1;
      if ( v23 <= 1 )
        v22 = -106;
      v27 = *v24;
      *(_BYTE *)(v7 + 134) = v25;
      if ( v26 )
        v22 = -105;
      *(_BYTE *)(v7 + 132) = v22;
      *(_BYTE *)(v7 + 133) = v27;
      *(_BYTE *)(v7 + 135) = HIBYTE(v25);
      *(_BYTE *)(v7 + 129) = -64;
      *(_BYTE *)(v7 + 130) = -75;
      *(_BYTE *)(v7 + 131) = 122;
      *(_BYTE *)(v7 + 136) = -1;
      goto LABEL_14;
    }
    if ( a1 > 0x80 )
    {
      if ( a1 == 129 )
      {
        sub_123AB4(v7 + 104);
        v13 = off_1244D8;
        v14 = *(_WORD *)off_1244DC;
        v15 = *(_WORD *)off_1244D8;
        v16 = off_1244E0;
        *(_BYTE *)(v7 + 130) = *(_WORD *)off_1244DC;
        v17 = v13[5];
        *(_BYTE *)(v7 + 128) = -127;
        LOBYTE(v13) = *v16;
        *(_BYTE *)(v7 + 131) = HIBYTE(v14);
        *(_WORD *)(v7 + 132) = v15;
        *(_BYTE *)(v7 + 134) = v17;
        *(_BYTE *)(v7 + 129) = (_BYTE)v13;
        *(_BYTE *)(v7 + 135) = -1;
        goto LABEL_14;
      }
    }
    else
    {
      if ( a1 == 1 )
      {
        v18 = (__int16 *)off_1244DC;
        v19 = *(_DWORD *)off_1244E8 - *(_DWORD *)off_1244E4;
        if ( v19 <= 0x4E1F )
        {
          v28 = dword_1244F4;
          v19 = (1000 - *(unsigned __int16 *)off_1244DC)
              * ((*(_DWORD *)off_1244E4 - *(_DWORD *)off_1244F0)
               / (unsigned int)*(unsigned __int16 *)off_1244DC)
              + 20000;
          *(_DWORD *)off_1244E8 = *(_DWORD *)off_1244E4 + v19;
          sub_11F504(v28, v19);
        }
        sub_123A20(v7 + 104);
        v20 = *v18;
        v21 = off_1244E0;
        *(_BYTE *)(v7 + 130) = *v18;
        LOBYTE(v21) = *v21;
        *(_BYTE *)(v7 + 131) = HIBYTE(v20);
        *(_BYTE *)(v7 + 132) = v19;
        *(_BYTE *)(v7 + 129) = (_BYTE)v21;
        *(_BYTE *)(v7 + 128) = 1;
        *(_BYTE *)(v7 + 133) = BYTE1(v19);
        *(_BYTE *)(v7 + 134) = BYTE2(v19);
        *(_BYTE *)(v7 + 135) = HIBYTE(v19);
        *(_BYTE *)(v7 + 136) = -1;
        goto LABEL_14;
      }
      if ( a1 == 2 )
      {
        sub_123A20(v7 + 104);
        v10 = off_1244D8;
        *(_BYTE *)(v7 + 128) = 2;
        v11 = v10[3];
        v12 = v10[4];
        *(_BYTE *)(v7 + 130) = v10[2];
        *(_BYTE *)(v7 + 131) = v11;
        *(_BYTE *)(v7 + 132) = v12;
        *(_BYTE *)(v7 + 129) = 1;
        *(_BYTE *)(v7 + 133) = -1;
LABEL_14:
        *(_DWORD *)(v6 + 44) = 0;
        *(_DWORD *)(v6 + 48) = 0;
        return sub_1165B0(v6, 0);
      }
    }
    sub_123A20(v7 + 104);
    *(_BYTE *)(v7 + 128) = 0;
    *(_BYTE *)(v7 + 129) = -1;
    goto LABEL_14;
  }
  return result;
}

