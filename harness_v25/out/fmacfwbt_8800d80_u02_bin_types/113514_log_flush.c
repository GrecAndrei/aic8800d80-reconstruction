// log_flush @ 0x113514, size 294 bytes
// Doc: rf_stream_start_354e [rf]: Start RF data stream and check link state
// rf_stream_start_354e [rf]: Start RF data stream and check link state
void log_flush()
{
  uint8_t *v0; // r5
  int v1; // r0
  uint32_t *v2; // r4
  uint32_t *v3; // r8
  unsigned int *v4; // r6
  unsigned int v5; // r1
  int v6; // r0
  int started; // r0
  uint8_t *v8; // r7
  int v9; // r9
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r0
  int v13; // r1

  v0 = rf_stream_start2_n3f0;
  if ( *(uint8_t *)rf_stream_start2_n3f0 )
  {
    if ( !*(uint16_t *)off_113648 )
    {
      feature_guard_sdio(512, dword_113664);
      return;
    }
    if ( *(unsigned __int8 *)rf_stream_start2_n3f8 >= (unsigned int)*(unsigned __int16 *)off_113648 )
    {
      v13 = rf_stream_start2_650;
      *(uint8_t *)off_113640 = 1;
      feature_guard_sdio(512, v13);
    }
  }
  else
  {
    if ( *(uint8_t *)off_113640 )
      return;
    if ( *(unsigned __int8 *)rf_stream_start2_n3f8 >= (unsigned int)*(unsigned __int16 *)off_113648
      && !*(uint8_t *)off_113640 )
    {
      *(uint8_t *)off_113640 = 1;
      feature_guard_sdio(512, rf_stream_start2_650);
      return;
    }
  }
  v1 = (*(int ( **)(uint32_t))(*((uint32_t *)rf_stream_start2_n408 + 2) + 16))(*((uint32_t *)rf_stream_start2_n408
                                                                                     + 1));
  v2 = (uint32_t *)v1;
  if ( v1 )
  {
    if ( *v0 )
    {
      v3 = rf_stream_start2_alt_0;
      v4 = (unsigned int *)rf_stream_start2_n40c;
      v5 = *(uint32_t *)rf_stream_start2_n40c;
      v6 = *(uint32_t *)rf_stream_start2_alt_0 + v1;
      if ( *(uint8_t *)off_113640 )
        started = rf_stream_start2_324c(v6, v5);
      else
        started = rf_stream_start_1ac(v6, v5);
    }
    else
    {
      v3 = rf_stream_start2_alt_0;
      v4 = (unsigned int *)rf_stream_start2_n40c;
      started = rf_stream_start_1ac(*(uint32_t *)rf_stream_start2_alt_0 + v1, *(uint32_t *)rf_stream_start2_n40c);
    }
    if ( started )
    {
      v8 = off_113640;
      log_printf(rf_stream_start2_n410, started);
      v9 = 5;
      while ( 1 )
      {
        if ( *v0 )
        {
          v10 = *v4;
          v11 = (int)v2 + *v3;
          v12 = *v8 ? rf_stream_start2_324c(v11, v10) : rf_stream_start_1ac(v11, v10);
        }
        else
        {
          v12 = rf_stream_start_1ac((int)v2 + *v3, *v4);
        }
        if ( !v12 )
          break;
        if ( !--v9 )
        {
          log_printf(rf_stream_start2_n414, 5);
          log_free_dispatch_2(v2);
          irq_nesting_or(32);
          return;
        }
      }
    }
  }
  else
  {
    irq_nesting_or(32);
    log_printf(rf_stream_start2_n41c);
  }
}

