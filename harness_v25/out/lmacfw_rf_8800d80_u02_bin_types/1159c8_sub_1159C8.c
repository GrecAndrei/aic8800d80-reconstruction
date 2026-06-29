// sub_1159C8 @ 0x1159c8, size 226 bytes
int  sub_1159C8(int result)
{
  uint32_t *v1; // r5
  int v2; // r4
  int v3; // r11
  uint32_t *v4; // r9
  int v5; // r8
  uint32_t *v6; // r7
  int *v7; // r3
  int v8; // r10
  int v9; // r2
  int v10; // r3
  uint32_t *v11; // r2
  int *v12; // r5
  int v13; // r1
  int v14; // r4
  int *v15; // r3
  int v16; // r3
  int v17; // [sp+4h] [bp-8h]

  if ( result == 5 )
    v1 = (uint32_t *)dword_115AB0;
  else
    v1 = (uint32_t *)dword_115AAC;
  if ( result != 5 )
    v1 += 7 * result;
  v2 = v1[3];
  v3 = result;
  if ( v2 )
  {
    v4 = off_115AC8;
    v5 = dword_115ACC;
    v17 = result + dword_115AB4;
    v6 = (uint32_t *)(4 * (result + dword_115AB4));
    while ( 1 )
    {
      v7 = *(int **)(v2 + 32);
      v8 = v7[17];
      if ( v8 >= 0 )
        break;
      v9 = v7[3];
      *v7 = v8;
      if ( v9 )
      {
        if ( *(int *)(v9 + 60) >= 0 )
        {
          *(uint32_t *)(4 * v17) = *(uint32_t *)off_115AC8 + *(uint32_t *)(dword_115ACC + 4 * v3);
          return result;
        }
      }
      else
      {
        *v1 = 0;
        rf_event_handler_8a4(v3);
      }
      sub_11E7AC(v1 + 3);
      if ( *(uint16_t *)(v2 + 4) )
        result = sub_115FF0(v2, v8, v3);
      else
        result = sub_11660C(v2, v8, v3);
      v2 = v1[3];
      *v6 = *v4 + *(uint32_t *)(v5 + 4 * v3);
      if ( !v2 )
        goto LABEL_16;
    }
  }
  else
  {
LABEL_16:
    v10 = *(uint32_t *)off_115AB8;
    *v1 = 0;
    result = 1 << v3;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_115ABC = 1;
    }
    v11 = off_115AC0;
    v12 = (int *)off_115AB8;
    v13 = *(uint32_t *)off_115AC0;
    v14 = *(uint32_t *)off_115AC0 + 1;
    *(uint32_t *)off_115AC0 = v14;
    *v12 = v10 & ~result;
    if ( v14 )
    {
      v15 = (int *)off_115ABC;
      *v11 = v13;
      v16 = *v15;
      if ( !v13 )
      {
        if ( v16 )
          __enable_irq();
      }
    }
    *(uint32_t *)off_115AC4 = result;
  }
  return result;
}

