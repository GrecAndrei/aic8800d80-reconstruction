// rf_event_dispatch_n_690 @ 0x123690, size 54 bytes
// Doc: rf_event_dispatch_n_690 [rf]: Dispatches RF event with up to 4 args to handler
// rf_event_dispatch_n_690 [rf]: Dispatches RF event with up to 4 args to handler
int  rf_event_dispatch_n_690(int a1, uint8_t *a2, int a3, int a4)
{
  char v7; // r0
  char v9; // r6
  uint8_t *v10; // r0

  v7 = sub_127B5C(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (uint8_t *)sub_12C92C(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    sdio_buffer_prepare_n_4e8(v10);
  }
  return 0;
}

