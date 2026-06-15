// v23 annotated: sub_116AF4 @ 0x116af4
// Original: 116af4_sub_116AF4.c
// Primary struct: <unclustered>
//
// sub_116AF4 @ 0x116af4, size 652 bytes
int __fastcall sub_116AF4(int a1, int a2, int a3, int a4)
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
      if ( ((*(_DWORD *)off_116D80 >> 4) & 3) != 2 )
        goto LABEL_12;
      while ( ((*(_DWORD *)off_116D80 >> 4) & 3) == 2 )
        ;
      if ( **(__int16 **)off_116DB8 >= 0 || ((*(_DWORD *)off_116D80 >> 4) & 3) != 2 )
      {
LABEL_12:
        v16 = off_116D88;
        *(_DWORD *)off_116DA8 = a1;
        *v16 = 512;
        goto LABEL_4;
      }
      result = sub_12F630(dword_116DD4, dword_116DC0, 1919, a4);
      break;
    case 1:
      if ( ((*(_DWORD *)off_116D80 >> 8) & 3) != 2 )
        goto LABEL_14;
      while ( ((*(_DWORD *)off_116D80 >> 8) & 3) == 2 )
        ;
      if ( **(__int16 **)off_116DB8 >= 0 || ((*(_DWORD *)off_116D80 >> 8) & 3) != 2 )
      {
LABEL_14:
        v17 = off_116D88;
        *(_DWORD *)off_116DAC = a1;
        *v17 = 1024;
        goto LABEL_4;
      }
      result = sub_12F630(dword_116DD0, dword_116DC0, 1907, a4);
      break;
    case 2:
      if ( ((*(_DWORD *)off_116D80 >> 12) & 3) != 2 )
        goto LABEL_16;
      while ( ((*(_DWORD *)off_116D80 >> 12) & 3) == 2 )
        ;
      if ( **(__int16 **)off_116DB8 >= 0 || ((*(_DWORD *)off_116D80 >> 12) & 3) != 2 )
      {
LABEL_16:
        v18 = off_116D88;
        *(_DWORD *)off_116DB0 = a1;
        *v18 = 2048;
        goto LABEL_4;
      }
      result = sub_12F630(dword_116DCC, dword_116DC0, 1895, a4);
      break;
    case 3:
      if ( (HIWORD(*(_DWORD *)off_116D80) & 3) != 2 )
        goto LABEL_18;
      while ( (HIWORD(*(_DWORD *)off_116D80) & 3) == 2 )
        ;
      if ( **(__int16 **)off_116DB8 >= 0 || (HIWORD(*(_DWORD *)off_116D80) & 3) != 2 )
      {
LABEL_18:
        v19 = off_116D88;
        *(_DWORD *)off_116DB4 = a1;
        *v19 = 4096;
        goto LABEL_4;
      }
      result = sub_12F630(dword_116DC8, dword_116DC0, 1883, a4);
      break;
    case 4:
      if ( **(__int16 **)off_116DB8 >= 0 || (*(_DWORD *)off_116D80 & 3) != 2 )
      {
        v20 = off_116D88;
        *(_DWORD *)off_116DBC = a1;
        *v20 = 256;
        goto LABEL_4;
      }
      result = sub_12F630(dword_116DC4, dword_116DC0, 1871, a4);
      break;
    case 5:
      if ( (HIBYTE(*(_DWORD *)off_116D80) & 3) != 2 )
        goto LABEL_3;
      while ( (HIBYTE(*(_DWORD *)off_116D80) & 3) == 2 )
        ;
      if ( **(__int16 **)off_116DB8 >= 0 || (HIBYTE(*(_DWORD *)off_116D80) & 3) != 2 )
      {
LABEL_3:
        v5 = off_116D88;
        *(_DWORD *)off_116D84 = a1;
        *v5 = 0x4000;
        goto LABEL_4;
      }
      result = sub_12F630(dword_116DD8, dword_116DC0, 1931, a4);
      break;
    default:
      if ( **(__int16 **)off_116DB8 < 0 )
        sub_12F694(dword_116DDC, dword_116DC0, 1937);
LABEL_4:
      v6 = (int *)off_116D98;
      v7 = (int *)(4 * (dword_116D94 + a2));
      v8 = *(_DWORD *)off_116D90 + *(_DWORD *)(dword_116D8C + 4 * a2);
      v9 = 1 << a2;
      *v7 = v8;
      *v6 = v9;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_116D9C = 1;
      }
      v10 = (int *)off_116DA0;
      v11 = (int *)off_116DA4;
      result = *(_DWORD *)off_116DA0;
      v13 = *(_DWORD *)off_116DA0 + 1;
      v14 = v9 | *(_DWORD *)off_116DA4;
      *(_DWORD *)off_116DA0 = v13;
      *v11 = v14;
      if ( v13 )
      {
        v15 = off_116D9C;
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

