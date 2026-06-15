// sub_116AB4 @ 0x116ab4, size 384 bytes
int __fastcall sub_116AB4(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  int result; // r0
  int v9; // r8
  int v10; // r6
  int v11; // r3
  int v12; // r3
  char v13; // r2
  char v14; // r2
  __int16 v15; // r3
  __int16 v16; // r2
  __int16 v17; // r1
  char v18; // r3
  char v19; // r3
  char v20; // r3
  _BYTE v21[8]; // [sp+0h] [bp-8h] BYREF

  v5 = *(unsigned __int16 *)(a2 + 4);
  result = *(unsigned __int16 *)(a1 + 82) | 4;
  *(_WORD *)(a1 + 82) = result;
  if ( !v5 )
    goto LABEL_4;
  if ( (*(_DWORD *)(a2 + 36) & 0x200000) == 0 )
  {
    v9 = *(_DWORD *)(a2 + 76);
    if ( **(__int16 **)off_116C34 >= 0 )
    {
      v10 = *(_DWORD *)(v9 + 28);
      if ( v10 )
      {
LABEL_11:
        if ( a4 == 4 )
        {
          v12 = dword_116C38 + 1320 * *(unsigned __int8 *)(a2 + 28);
          v13 = *(_BYTE *)(v12 + 230);
          if ( (*(_WORD *)v10 & 0x2000) != 0 )
            v14 = v13 | 2;
          else
            v14 = v13 & 0xFD;
          *(_BYTE *)(v12 + 230) = v14;
        }
        if ( *(unsigned __int8 *)(a2 + 27) == 255 )
        {
          v15 = *(_BYTE *)(v10 + 22) & 0xF;
          if ( (*(_BYTE *)(v10 + 22) & 0xF) != 0 )
          {
            v16 = *((_WORD *)off_116C3C + 254);
          }
          else
          {
            v16 = *((_WORD *)off_116C3C + 254) + 1;
            *((_WORD *)off_116C3C + 254) = v16;
          }
          v17 = *(_WORD *)(a2 + 30);
          *(_WORD *)(v10 + 22) = v15 | (16 * v16);
          if ( (v17 & 8) != 0 )
          {
            if ( (*(_WORD *)v10 & 0xDC) == 0x10 && !*(_WORD *)(v10 + 26) )
            {
              *(_WORD *)(a2 + 30) = v17 | 0x20;
              v18 = *(_BYTE *)(v10 + 5);
              v21[0] = *(_BYTE *)(v10 + 4);
              v21[1] = v18;
              v19 = *(_BYTE *)(v10 + 7);
              v21[2] = *(_BYTE *)(v10 + 6);
              v21[3] = v19;
              v20 = *(_BYTE *)(v10 + 9);
              v21[4] = *(_BYTE *)(v10 + 8);
              v21[5] = v20;
              sub_13A4B0(v21);
              v17 = *(_WORD *)(a2 + 30);
            }
            if ( (v17 & 0x80) != 0 )
            {
              if ( *(_BYTE *)(a2 + 51) )
              {
                fmac_main_loop_0a0(a2, v10, 24);
              }
              else if ( *(_BYTE *)(a2 + 53) )
              {
                sub_13C710(a2, v10, *(unsigned __int16 *)(a2 + 4));
              }
            }
          }
        }
        goto LABEL_3;
      }
      goto LABEL_9;
    }
    if ( *(_DWORD *)(a2 + 72) )
    {
      v10 = *(_DWORD *)(v9 + 28);
      if ( v10 )
        goto LABEL_11;
    }
    else
    {
      sub_12F46C(dword_116C48, dword_116C40, 518);
      v10 = *(_DWORD *)(v9 + 28);
      if ( v10 )
        goto LABEL_11;
      if ( **(__int16 **)off_116C34 >= 0 )
        goto LABEL_9;
    }
    v11 = *(_DWORD *)(v9 + 24);
    if ( v11 )
      goto LABEL_10;
    sub_12F46C(dword_116C44, dword_116C40, 525);
LABEL_9:
    v11 = *(_DWORD *)(v9 + 24);
LABEL_10:
    v10 = *(_DWORD *)(v11 + 8);
    goto LABEL_11;
  }
LABEL_3:
  result = sub_116324(a2, a4);
LABEL_4:
  if ( (*(_DWORD *)(a1 + 36) & 0x200000) == 0 )
    return sub_1169A0(*(_DWORD *)(a1 + 76) + 12, *(_DWORD *)(a1 + 76) + 12, a4);
  *(_WORD *)(*(_DWORD *)(a1 + 68) + 8) |= 2u;
  return result;
}

