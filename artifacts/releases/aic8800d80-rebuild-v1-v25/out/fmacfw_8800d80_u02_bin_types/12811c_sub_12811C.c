// sub_12811C @ 0x12811c, size 354 bytes
int  sub_12811C(int result)
{
  uint32_t *v1; // r5
  int v2; // r2
  int v3; // r4
  int v4; // r3
  int v5; // r1
  int v6; // r6
  int v7; // r3
  int v8; // r2
  int v9; // r7
  int v10; // r8
  int v11; // r7
  int v12; // r4
  int v13; // r3
  int *v14; // r4
  int v15; // r1
  int v16; // r3
  int v17; // r2
  int v18; // r0
  int *v19; // r2
  int v20; // r2

  v1 = off_128280;
  if ( *((unsigned __int8 *)off_128280 + 90) > 1u )
  {
    v2 = *(unsigned __int8 *)(result + 85);
    v3 = result;
    if ( (v2 & 0x10) != 0 )
    {
      v4 = dword_128284;
      while ( 1 )
      {
        if ( *(unsigned __int8 *)(v4 + 24) != 255 )
        {
          v5 = *(unsigned __int8 *)(v4 + 27);
          if ( v5 != 255 )
            break;
        }
        v4 += 28;
        if ( dword_128284 + 84 == v4 )
          goto LABEL_7;
      }
      sub_125E78((uint32_t *)(dword_128298 + 1320 * v5));
      LOBYTE(v2) = *(uint8_t *)(v3 + 85);
LABEL_7:
      v2 &= 0xEFu;
      *(uint8_t *)(v3 + 85) = v2;
    }
    result = v2 << 30;
    if ( (v2 & 2) == 0 )
    {
      v6 = v1[9];
      if ( (v2 & 4) != 0 )
        *(uint8_t *)(v3 + 85) = v2 & 0xFB;
      if ( !v6 || *(uint32_t *)(v6 + 12) != v3 + 76 )
        return sub_126584(v3, *(uint32_t *)(v3 + 36), 0);
      v9 = *(uint32_t *)(v3 + 80);
      v10 = *(uint32_t *)(v3 + 36);
      if ( v9 - v10 < 0 )
      {
        if ( v10 - 4000 - v9 - sub_1019F0() < 0 )
        {
LABEL_23:
          v11 = *(uint32_t *)(v3 + 36);
          *(uint32_t *)(v3 + 80) = v11;
          result = sub_1019F0();
          if ( v11 - *(uint32_t *)(v6 + 4) - result - 4000 < 0 )
          {
            v12 = *(uint32_t *)(v3 + 80);
            result = sub_1019F0();
            v13 = v1[18];
            *(uint32_t *)(v6 + 4) = v12 - 4000 - result;
            if ( v13 == v6 )
            {
              timestamp_remove(dword_128288);
              v1[18] = v6;
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(uint32_t *)off_12828C = 1;
              }
              v14 = (int *)off_128294;
              v15 = *(uint32_t *)(v6 + 4);
              v16 = *(uint32_t *)off_128294;
              v17 = v15 - *((uint32_t *)off_128290 + 4);
              v18 = *(uint32_t *)off_128294 + 1;
              *(uint32_t *)off_128294 = v18;
              if ( v17 - 64 >= 0 )
              {
                result = timestamp_update(dword_128288, v15);
                if ( *v14 )
                {
                  v7 = *v14 - 1;
                  v8 = *(uint32_t *)off_12828C;
                  *v14 = v7;
                  if ( !v7 )
                  {
                    if ( v8 )
                      __enable_irq();
                  }
                }
              }
              else
              {
                if ( v18 )
                {
                  v19 = (int *)off_12828C;
                  *v14 = v16;
                  v20 = *v19;
                  if ( !v16 )
                  {
                    if ( v20 )
                      __enable_irq();
                  }
                }
                return ((int ( *)(int))v1[17])(v6);
              }
            }
          }
          return result;
        }
        v10 = *(uint32_t *)(v3 + 36);
        v9 = *(uint32_t *)(v3 + 80);
      }
      if ( v10 - v9 >= 0 || v9 - 4000 - v10 - sub_1019F0() >= 0 )
      {
        bt_event_handler();
        sub_126584(v3, *(uint32_t *)(v3 + 36), 0);
        return sub_126824(v3, *((uint32_t *)off_128290 + 4), 0);
      }
      goto LABEL_23;
    }
  }
  return result;
}

