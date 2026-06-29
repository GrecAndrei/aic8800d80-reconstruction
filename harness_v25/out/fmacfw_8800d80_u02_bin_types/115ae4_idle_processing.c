// idle_processing @ 0x115ae4, size 532 bytes
// Doc: ipc_doorbell_handler_n1d2 [ipc]: Handles IPC doorbell interrupt, sets flag byte
// ipc_doorbell_handler_n1d2 [ipc]: Handles IPC doorbell interrupt, sets flag byte
int  idle_processing(int result)
{
  uint8_t **v1; // r5
  unsigned __int8 **v2; // r6
  int v3; // r3
  int *v4; // r3
  uint8_t *v5; // r4
  int v6; // r3
  int v7; // r1
  void *v8; // r2
  char v9; // r0
  int v10; // r1
  void *v11; // r2
  int v12; // r0

  if ( *(uint8_t *)ipc_doorbell_handler_n37c && (*((uint32_t *)ipc_doorbell_handler_n380 + 4) & 0xFFFF00) == 0x10000 )
  {
    v6 = *(unsigned __int8 *)off_115D1C;
    *(uint8_t *)rf_level_apply_n3aa = 0;
    if ( v6 )
      return feature_guard_check(2, rf_msg_handler_n4dc_0);
    if ( !*(uint8_t *)off_115D24 )
      return feature_guard_check(2, ipc_doorbell_handler_n3d0);
    if ( *(uint32_t *)off_115D28 && *(uint32_t *)(*(uint32_t *)off_115D28 + 12) - *((uint32_t *)off_115D2C + 4) - 5000 < 0 )
      return feature_guard_check(2, ipc_doorbell_handler_d54);
    if ( !*(uint8_t *)off_115D30
      && !*((uint32_t *)ipc_doorbell_handler_n38c + 126)
      && ((ipc_doorbell_handler_n3bc & *(uint32_t *)off_115D34) == 0
       || (unsigned int)(32 * *(uint32_t *)ipc_doorbell_handler_n3c0) > 0x1387) )
    {
      ((void (*)(void))sdio_wait_busy_clear)();
      while ( 1 )
        ;
    }
    return result;
  }
  if ( *((uint8_t *)ipc_doorbell_handler_n380 + 18) )
  {
    v5 = ipc_doorbell_handler_n398;
    goto ipc_doorbell_handler_n20e;
  }
  v1 = (uint8_t **)ipc_doorbell_handler_n384;
  if ( **(uint8_t **)ipc_doorbell_handler_n384 )
  {
    v2 = (unsigned __int8 **)rf_bus_reset2_5d04;
    goto ipc_doorbell_handler_n192;
  }
  v4 = *((int **)ipc_doorbell_handler_n380 + 2);
  v5 = ipc_doorbell_handler_n398;
  *(uint8_t *)ipc_doorbell_handler_n398 = 1;
  if ( !v4 )
  {
ipc_doorbell_handler_n2c8:
    v2 = (unsigned __int8 **)rf_bus_reset2_5d04;
    if ( **(uint8_t **)rf_bus_reset2_5d04 == 3 )
      goto ipc_doorbell_handler_n1a0;
    result = feature_guard_check(2, dword_115D18);
    *v5 = 1;
ipc_doorbell_handler_n192:
    v3 = **v2;
    if ( v3 == 1 )
    {
      if ( **v1 == 3 )
      {
        v9 = sub_10D304();
        v11 = rf_level_apply_n3aa;
        *(uint8_t *)rf_level_apply_n3aa = v9;
        if ( v9 )
          msg_parse(dword_115D5C, v10, v11);
        else
          msg_parse(ipc_doorbell_handler_n3d4, v10, v11);
        if ( sub_1112F4() )
          ipc_doorbell_handler();
        return ((int (*)(void))sdio_wait_busy_clear)();
      }
      result = sub_1112F4();
      if ( !result || *(uint8_t *)off_115D30 )
        return result;
    }
    else if ( v3 == 2 )
    {
      return result;
    }
ipc_doorbell_handler_n1a0:
    result = sub_128F1C(result);
    if ( result )
    {
      if ( !*((uint32_t *)ipc_doorbell_handler_n38c + 126) )
      {
        if ( (*(uint32_t *)ipc_doorbell_handler_n390 >> 25) & 1 | *((unsigned __int8 *)ipc_doorbell_handler_5d10 + 36) )
        {
          if ( !*((uint8_t *)ipc_doorbell_handler_5d10 + 29) )
          {
            result = sub_12BD40();
            if ( result )
            {
              LOBYTE(result) = sub_10D304();
              v8 = rf_level_apply_n3aa;
              result = (unsigned __int8)result;
              *(uint8_t *)rf_level_apply_n3aa = result;
              if ( !(uint8_t)result )
              {
                v12 = msg_parse(ipc_doorbell_handler_n3dc, v7, v8);
                result = sdio_wait_busy_clear(v12);
              }
              if ( (unsigned __int8)**v1 <= 1u )
                return (int)ipc_doorbell_handler();
            }
          }
        }
      }
    }
    return result;
  }
  while ( !*((uint8_t *)v4 + 106) )
  {
    if ( *((uint8_t *)v4 + 108) )
      goto ipc_doorbell_handler_n1f4;
LABEL_17:
    v4 = (int *)*v4;
    if ( !v4 )
      goto ipc_doorbell_handler_n2c8;
  }
  if ( *((uint8_t *)v4 + 106) != 2 )
    goto LABEL_17;
ipc_doorbell_handler_n1f4:
  if ( **(uint8_t **)rf_bus_reset2_5d04 != 3 )
    result = feature_guard_check(2, dword_115D18);
ipc_doorbell_handler_n20e:
  *v5 = 0;
  return result;
}

