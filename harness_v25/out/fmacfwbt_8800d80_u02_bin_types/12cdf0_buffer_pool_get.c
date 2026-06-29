// buffer_pool_get @ 0x12cdf0, size 226 bytes
// Doc: message_dispatch_n246 [ipc]: Dispatch incoming message via shared queue
// message_dispatch_n246 [ipc]: Dispatch incoming message via shared queue
uint32_t * buffer_pool_get(char *a1)
{
  __int16 **v1; // r9
  char *v2; // r4
  int v3; // r8
  char *v5; // r5
  uint32_t *result; // r0
  int v7; // r12
  int v8; // r7
  int v9; // r3
  uint32_t *v10; // r1
  int *v11; // r3
  int v12; // r3
  int v13; // r3
  char *v14; // r2
  int v15; // r1
  uint64_t v16; // r2

  v1 = (__int16 **)off_12CEEC;
  v2 = *((char **)off_12CED4 + 7);
  v3 = *((uint32_t *)a1 - 1);
  v5 = a1 - 4;
  if ( **(__int16 **)off_12CEEC < 0 && a1 <= v2 )
    sub_12F694(dword_12CEE4, dword_12CEE0, 220);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)message_dispatch_n324 = 1;
  }
  result = off_12CEDC;
  v7 = *(uint32_t *)off_12CEDC;
  v8 = *(uint32_t *)off_12CEDC + 1;
  *(uint32_t *)off_12CEDC = v8;
  if ( !v2 )
  {
    MEMORY[0] = v5;
    __und(0xFFu);
  }
  v9 = *((uint32_t *)v2 + 1);
  if ( &v2[v9] != v5 )
  {
    if ( v2 > v5 )
    {
      if ( **v1 < 0 )
        sub_12F694(message_dispatch_n334_cee8, dword_12CEE0, 247);
      MEMORY[0] = v5;
      __und(0xFFu);
    }
    while ( 1 )
    {
      v10 = v2;
      v2 = *(char **)v2;
      if ( !v2 )
        break;
      v9 = *((uint32_t *)v2 + 1);
      if ( &v2[v9] == v5 )
        goto message_dispatch_n2ce;
      if ( v2 > v5 )
      {
        *v10 = v5;
        if ( v2 == &v5[v3] )
        {
          *((uint32_t *)a1 - 1) = *(uint32_t *)v2;
          *(uint32_t *)a1 = &v2[v9] - v5;
          goto LABEL_13;
        }
LABEL_12:
        *((uint32_t *)a1 - 1) = v2;
        *(uint32_t *)a1 = v3;
        goto LABEL_13;
      }
    }
    *v10 = v5;
    goto LABEL_12;
  }
message_dispatch_n2ce:
  v13 = v9 + v3;
  v14 = *(char **)v2;
  *((uint32_t *)v2 + 1) = v13;
  if ( v14 == &v2[v13] )
  {
    v15 = *((uint32_t *)v14 + 1);
    LODWORD(v16) = *(uint32_t *)v14;
    HIDWORD(v16) = v13 + v15;
    *(QWORD *)v2 = v16;
  }
LABEL_13:
  if ( v8 )
  {
    v11 = (int *)message_dispatch_n324;
    *result = v7;
    v12 = *v11;
    if ( !v7 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}

