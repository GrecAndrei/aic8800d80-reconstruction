// sub_121984 @ 0x121984, size 212 bytes
int  sub_121984(int a1)
{
  uint32_t *v1; // r2
  unsigned int v2; // r3
  unsigned int v3; // r6
  int v4; // r4
  int *v5; // r5
  uint32_t *v6; // r7
  int v7; // r0
  int v8; // r1
  unsigned int v9; // r7
  int v10; // r1
  unsigned int v11; // r0
  int v12; // r1
  int v13; // r0
  int v14; // r3
  int v15; // r2
  unsigned int v17; // r1
  int v18; // r0
  int v19; // r0

  v1 = off_121A58;
  if ( !*((uint8_t *)off_121A58 + 48) )
  {
    if ( !a1 )
      return 0;
    v2 = (unsigned __int16)*(uint32_t *)off_121A5C << 10;
    *((uint8_t *)off_121A58 + 48) = 1;
    v3 = abs32(a1);
    if ( a1 <= 0 )
    {
      if ( v3 <= v2 >> 1 )
        v4 = a1;
      else
        v4 = -(v2 >> 1);
    }
    else
    {
      v4 = v2 >> 1;
      if ( v3 <= v2 >> 1 )
        v4 = a1;
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_121A60 = 1;
    }
    v5 = (int *)off_121A64;
    v6 = off_121A68;
    v7 = *(uint32_t *)off_121A6C;
    ++*(uint32_t *)off_121A64;
    v8 = v6[4];
    v9 = 32 * v7;
    v10 = v8 + 32 * v7;
    v11 = v2 >> 2;
    if ( v4 <= 0 )
    {
      if ( v3 + v11 >= v9 )
      {
        v19 = dword_121A70;
        v1[10] = v4;
        timestamp_update(v19, v10 + 100);
        goto LABEL_12;
      }
    }
    else
    {
      if ( v11 > v9 )
      {
        v17 = v10 + v2 - v11;
        v18 = dword_121A70;
        v1[10] = v4;
        timestamp_update(v18, v17);
        goto LABEL_12;
      }
      if ( v3 + 100 > v2 - v9 )
      {
        v12 = v10 - v11;
        v13 = dword_121A70;
        v1[10] = v4;
        timestamp_update(v13, v12);
LABEL_12:
        if ( *v5 )
        {
          v14 = *v5 - 1;
          v15 = *(uint32_t *)off_121A60;
          *v5 = v14;
          if ( !v14 )
          {
            if ( v15 )
              __enable_irq();
          }
        }
        return v4;
      }
    }
    ipc_msg_send_n048c(v4);
    goto LABEL_12;
  }
  return 0;
}

