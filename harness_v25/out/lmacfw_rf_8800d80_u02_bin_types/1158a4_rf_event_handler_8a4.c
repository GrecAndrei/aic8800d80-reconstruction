// rf_event_handler_8a4 @ 0x1158a4, size 250 bytes
// Doc: rf_event_handler_8a4 [rf]: RF event/state handler
// rf_event_handler_8a4 [rf]: RF event/state handler
int  rf_event_handler_8a4(int result)
{
  int v1; // r3
  int v2; // r6
  uint32_t *v3; // r2
  int *v4; // r5
  int v5; // r4
  int v6; // r1
  int *v7; // r3
  int v8; // r3
  uint32_t *v9; // r2
  uint32_t *v10; // r2
  uint32_t *v11; // r2
  uint32_t *v12; // r2
  uint32_t *v13; // r2

  v1 = *(uint32_t *)off_1159A0;
  v2 = 1 << result;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1159A4 = 1;
  }
  v3 = off_1159A8;
  v4 = (int *)off_1159A0;
  v5 = *(uint32_t *)off_1159A8;
  v6 = *(uint32_t *)off_1159A8 + 1;
  *(uint32_t *)off_1159A8 = v6;
  *v4 = v1 & ~v2;
  if ( v6 )
  {
    v7 = (int *)off_1159A4;
    *v3 = v5;
    v8 = *v7;
    if ( !v5 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  *(uint32_t *)off_1159AC = v2;
  switch ( result )
  {
    case 0:
      v10 = off_1159B4;
      *(uint32_t *)off_1159B0 = 0x10000;
      while ( (*v10 & 0x30) != 0 )
        ;
      *(uint32_t *)off_1159B8 = 0x10000;
      break;
    case 1:
      v12 = off_1159B4;
      *(uint32_t *)off_1159B0 = 0x20000;
      while ( (*v12 & 0x300) != 0 )
        ;
      *(uint32_t *)off_1159B8 = 0x20000;
      break;
    case 2:
      v11 = off_1159B4;
      *(uint32_t *)off_1159B0 = 0x40000;
      while ( (*v11 & 0x3000) != 0 )
        ;
      *(uint32_t *)off_1159B8 = 0x40000;
      break;
    case 3:
      v13 = off_1159B4;
      *(uint32_t *)off_1159B0 = 0x80000;
      while ( (*v13 & 0x30000) != 0 )
        ;
      *(uint32_t *)off_1159B8 = 0x80000;
      break;
    case 5:
      v9 = off_1159B4;
      *(uint32_t *)off_1159B0 = 0x200000;
      while ( (*v9 & 0x3000000) != 0 )
        ;
      *(uint32_t *)off_1159B8 = 0x200000;
      break;
    default:
      if ( **(__int16 **)off_1159BC < 0 )
        result = rf_cmd_send_n264(dword_1159C4, dword_1159C0, 2338);
      break;
  }
  return result;
}

