// v23 annotated: sub_1062DC @ 0x1062dc
// Original: 1062dc_sub_1062DC.c
// Primary struct: <unclustered>
//
// sub_1062DC @ 0x1062dc, size 188 bytes
int __fastcall sub_1062DC(int a1, int a2, int a3, int a4, int a5)
{
  int v9; // r4
  unsigned int v10; // r4
  int v11; // r8
  int v12; // r1

  if ( *(_DWORD *)(a4 + 132) <= a2 )
  {
    sub_105118(*(float *)(a4 + 4 * a2 + 148), (unsigned __int8)a1, a4);
    v9 = *(unsigned __int8 *)(a4 + 104);
  }
  else
  {
    v9 = (unsigned __int8)a1;
  }
  v10 = v9 | a1 & 0xFFFFF000 | (a2 << 8);
  if ( a3 )
  {
    if ( a2 == 7 )
    {
      v11 = 83886080;
      goto LABEL_8;
    }
    goto LABEL_11;
  }
  if ( a2 != 4 )
  {
    if ( a2 == 7 )
      goto LABEL_6;
LABEL_11:
    if ( (unsigned int)(a2 - 4) > 0xB )
      goto LABEL_9;
    if ( a2 > 6 )
    {
      if ( a3 )
      {
        v11 = (15 - a2) << 24;
        goto LABEL_8;
      }
    }
    else if ( a3 )
    {
      goto LABEL_14;
    }
    a3 = 15 - a2;
    goto LABEL_6;
  }
  a3 = 1;
LABEL_6:
  if ( (a5 & 0xFFFFFFFD) == 0 )
  {
LABEL_14:
    v10 |= 0xC08000u;
    sub_12EB90(1, dword_1063A0);
    goto LABEL_9;
  }
  v11 = a3 << 24;
LABEL_8:
  v10 = v10 & 0xFF3F7FFF | v11;
LABEL_9:
  v12 = dword_10639C;
  *(_DWORD *)off_106398 = v10;
  return sub_12EB90(1, v12);
}

