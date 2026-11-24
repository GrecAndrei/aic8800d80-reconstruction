// sub_116574 @ 0x116574, size 652 bytes
int __fastcall sub_116574(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r3
  int *v6; // r0
  int *v7; // r3
  int v8; // r2
  int v9; // r4
  int *v10; // r3
  int *v11; // r1
  int result; // r0
  int v13; // r2
  int v14; // r4
  _DWORD *v15; // r2
  _DWORD *v16; // r3
  _DWORD *v17; // r3
  _DWORD *v18; // r3
  _DWORD *v19; // r3
  _DWORD *v20; // r3

  switch ( a2 )
  {
    case 0:
      if ( ((*(_DWORD *)off_116800 >> 4) & 3) != 2 )
        goto LABEL_12;
      while ( ((*(_DWORD *)off_116800 >> 4) & 3) == 2 )
        ;
      if ( **(__int16 **)off_116838 >= 0 || ((*(_DWORD *)off_116800 >> 4) & 3) != 2 )
      {
LABEL_12:
        v16 = off_116808;
        *(_DWORD *)off_116828 = a1;
        *v16 = 512;
        goto LABEL_4;
      }
      result = sub_12F2C8(dword_116854, dword_116840, 1919, a4);
      break;
    case 1:
      if ( ((*(_DWORD *)off_116800 >> 8) & 3) != 2 )
        goto LABEL_14;
      while ( ((*(_DWORD *)off_116800 >> 8) & 3) == 2 )
        ;
      if ( **(__int16 **)off_116838 >= 0 || ((*(_DWORD *)off_116800 >> 8) & 3) != 2 )
      {
LABEL_14:
        v17 = off_116808;
        *(_DWORD *)off_11682C = a1;
        *v17 = 1024;
        goto LABEL_4;
      }
      result = sub_12F2C8(dword_116850, dword_116840, 1907, a4);
      break;
    case 2:
      if ( ((*(_DWORD *)off_116800 >> 12) & 3) != 2 )
        goto LABEL_16;
      while ( ((*(_DWORD *)off_116800 >> 12) & 3) == 2 )
        ;
      if ( **(__int16 **)off_116838 >= 0 || ((*(_DWORD *)off_116800 >> 12) & 3) != 2 )
      {
LABEL_16:
        v18 = off_116808;
        *(_DWORD *)off_116830 = a1;
        *v18 = 2048;
        goto LABEL_4;
      }
      result = sub_12F2C8(dword_11684C, dword_116840, 1895, a4);
      break;
    case 3:
      if ( (HIWORD(*(_DWORD *)off_116800) & 3) != 2 )
        goto LABEL_18;
      while ( (HIWORD(*(_DWORD *)off_116800) & 3) == 2 )
        ;
      if ( **(__int16 **)off_116838 >= 0 || (HIWORD(*(_DWORD *)off_116800) & 3) != 2 )
      {
LABEL_18:
        v19 = off_116808;
        *(_DWORD *)off_116834 = a1;
        *v19 = 4096;
        goto LABEL_4;
      }
      result = sub_12F2C8(dword_116848, dword_116840, 1883, a4);
      break;
    case 4:
      if ( **(__int16 **)off_116838 >= 0 || (*(_DWORD *)off_116800 & 3) != 2 )
      {
        v20 = off_116808;
        *(_DWORD *)off_11683C = a1;
        *v20 = 256;
        goto LABEL_4;
      }
      result = sub_12F2C8(dword_116844, dword_116840, 1871, a4);
      break;
    case 5:
      if ( (HIBYTE(*(_DWORD *)off_116800) & 3) != 2 )
        goto LABEL_3;
      while ( (HIBYTE(*(_DWORD *)off_116800) & 3) == 2 )
        ;
      if ( **(__int16 **)off_116838 >= 0 || (HIBYTE(*(_DWORD *)off_116800) & 3) != 2 )
      {
LABEL_3:
        v5 = off_116808;
        *(_DWORD *)off_116804 = a1;
        *v5 = 0x4000;
        goto LABEL_4;
      }
      result = sub_12F2C8(dword_116858, dword_116840, 1931, a4);
      break;
    default:
      if ( **(__int16 **)off_116838 < 0 )
        sub_12F32C(dword_11685C, dword_116840, 1937);
LABEL_4:
      v6 = (int *)off_116818;
      v7 = (int *)(4 * (dword_116814 + a2));
      v8 = *(_DWORD *)off_116810 + *(_DWORD *)(dword_11680C + 4 * a2);
      v9 = 1 << a2;
      *v7 = v8;
      *v6 = v9;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_11681C = 1;
      }
      v10 = (int *)off_116820;
      v11 = (int *)off_116824;
      result = *(_DWORD *)off_116820;
      v13 = *(_DWORD *)off_116820 + 1;
      v14 = v9 | *(_DWORD *)off_116824;
      *(_DWORD *)off_116820 = v13;
      *v11 = v14;
      if ( v13 )
      {
        v15 = off_11681C;
        *v10 = result;
        if ( !result )
        {
          if ( *v15 )
            __enable_irq();
        }
      }
      break;
  }
  return result;
}

