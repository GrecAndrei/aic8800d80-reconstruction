// sub_1153F4 @ 0x1153f4, size 594 bytes
// Doc: sub_12153F4 [util]: Switch dispatch on input code (<=5) with 4 saved regs
// sub_12153F4 [util]: Switch dispatch on input code (<=5) with 4 saved regs
int * sub_1153F4(int a1, int a2, int a3, int a4)
{
  uint32_t *v5; // r3
  int *v6; // r0
  int *v7; // r3
  int v8; // r2
  int v9; // r4
  uint32_t *v10; // r3
  int *result; // r0
  int v12; // r2
  int v13; // r1
  int v14; // r4
  uint32_t *v15; // r1
  uint32_t *v16; // r3
  uint32_t *v17; // r3
  uint32_t *v18; // r3
  uint32_t *v19; // r3

  switch ( a2 )
  {
    case 0:
      if ( ((*(uint32_t *)off_115648 >> 4) & 3) != 2 )
        goto LABEL_12;
      while ( ((*(uint32_t *)off_115648 >> 4) & 3) == 2 )
        ;
      if ( **(__int16 **)off_115680 >= 0 || ((*(uint32_t *)off_115648 >> 4) & 3) != 2 )
      {
LABEL_12:
        v16 = off_115650;
        *(uint32_t *)off_115670 = a1;
        *v16 = 512;
        goto LABEL_4;
      }
      result = (int *)sub_121960(dword_115690, dword_115684, 1919, a4);
      break;
    case 1:
      if ( ((*(uint32_t *)off_115648 >> 8) & 3) != 2 )
        goto LABEL_16;
      while ( ((*(uint32_t *)off_115648 >> 8) & 3) == 2 )
        ;
      if ( **(__int16 **)off_115680 >= 0 || ((*(uint32_t *)off_115648 >> 8) & 3) != 2 )
      {
LABEL_16:
        v18 = off_115650;
        *(uint32_t *)off_115678 = a1;
        *v18 = 1024;
        goto LABEL_4;
      }
      result = (int *)sub_121960(dword_115694, dword_115684, 1907, a4);
      break;
    case 2:
      if ( ((*(uint32_t *)off_115648 >> 12) & 3) != 2 )
        goto LABEL_14;
      while ( ((*(uint32_t *)off_115648 >> 12) & 3) == 2 )
        ;
      if ( **(__int16 **)off_115680 >= 0 || ((*(uint32_t *)off_115648 >> 12) & 3) != 2 )
      {
LABEL_14:
        v17 = off_115650;
        *(uint32_t *)off_115674 = a1;
        *v17 = 2048;
        goto LABEL_4;
      }
      result = (int *)sub_121960(dword_115698, dword_115684, 1895, a4);
      break;
    case 3:
      if ( (HIWORD(*(uint32_t *)off_115648) & 3) != 2 )
        goto LABEL_18;
      while ( (HIWORD(*(uint32_t *)off_115648) & 3) == 2 )
        ;
      if ( **(__int16 **)off_115680 >= 0 || (HIWORD(*(uint32_t *)off_115648) & 3) != 2 )
      {
LABEL_18:
        v19 = off_115650;
        *(uint32_t *)off_11567C = a1;
        *v19 = 4096;
        goto LABEL_4;
      }
      result = (int *)sub_121960(dword_11569C, dword_115684, 1883, a4);
      break;
    case 5:
      if ( (HIBYTE(*(uint32_t *)off_115648) & 3) != 2 )
        goto LABEL_3;
      while ( (HIBYTE(*(uint32_t *)off_115648) & 3) == 2 )
        ;
      if ( **(__int16 **)off_115680 >= 0 || (HIBYTE(*(uint32_t *)off_115648) & 3) != 2 )
      {
LABEL_3:
        v5 = off_115650;
        *(uint32_t *)off_11564C = a1;
        *v5 = 0x4000;
        goto LABEL_4;
      }
      result = (int *)sub_121960(dword_11568C, dword_115684, 1931, a4);
      break;
    default:
      if ( **(__int16 **)off_115680 < 0 )
        rf_cmd_send_n264(dword_115688, dword_115684, 1937);
LABEL_4:
      v6 = (int *)off_115660;
      v7 = (int *)(4 * (dword_11565C + a2));
      v8 = *(uint32_t *)off_115658 + *(uint32_t *)(dword_115654 + 4 * a2);
      v9 = 1 << a2;
      *v7 = v8;
      *v6 = v9;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_115664 = 1;
      }
      v10 = off_115668;
      result = (int *)off_11566C;
      v12 = *(uint32_t *)off_115668;
      v13 = *(uint32_t *)off_115668 + 1;
      v14 = v9 | *(uint32_t *)off_11566C;
      *(uint32_t *)off_115668 = v13;
      *result = v14;
      if ( v13 )
      {
        v15 = off_115664;
        *v10 = v12;
        if ( !v12 )
        {
          if ( *v15 )
            __enable_irq();
        }
      }
      break;
  }
  return result;
}

