// ipc_doorbell_handler_33b @ 0x115640, size 296 bytes
// Doc: ipc_doorbell_handler_6aa [ipc]: IPC doorbell interrupt handler (variant 2d2)
// ipc_doorbell_handler_6aa [ipc]: IPC doorbell interrupt handler (variant 2d2)
int ipc_doorbell_handler_33b()
{
  uint32_t *v0; // r2
  uint8_t *v1; // r4
  uint32_t *v2; // r2
  uint8_t *v3; // r6
  uint32_t *v4; // r3
  uint8_t **v5; // r5
  int v6; // r3
  int result; // r0
  uint8_t *v8; // r7
  int v9; // r3
  int v10; // r3
  int v11; // r1
  uint32_t *v12; // r4

  v0 = ipc_doorbell_handler_n_210;
  *((uint32_t *)off_115768 + 14) |= 0x10u;
  *v0 &= ~0x2000000u;
  v1 = ipc_doorbell_handler_n_208;
  feature_guard_check(2, ipc_doorbell_handler_n_20c);
  v2 = ipc_doorbell_handler_n_204;
  *(uint32_t *)ipc_doorbell_handler_n_204 |= 0x80000000;
  v1[1] = 0;
  while ( (*v2 & 0x40000000) == 0 )
    ;
  v3 = ipc_doorbell_dispatch;
  if ( *((uint8_t *)ipc_doorbell_dispatch + 189) && **(__int16 **)off_115780 < 0 && *v1 != (*(uint32_t *)off_115794 & 0xF) )
    sub_12F46C(ipc_doorbell_handler_n_1cc, dword_1157AC, 968);
  v4 = ipc_doorbell_handler_n_204;
  v5 = (uint8_t **)ipc_doorbell_handler_n_1f8;
  *(uint32_t *)ipc_doorbell_handler_n_204 &= ~0x40000000u;
  *v4 &= ~0x80000000;
  v6 = (unsigned __int8)**v5;
  if ( v6 == 3 )
  {
    *(uint32_t *)ipc_doorbell_handler_n_1d4 &= ~1u;
  }
  else if ( v6 == 1 )
  {
    *(uint32_t *)ipc_doorbell_handler_n_1d8 &= ~0x20u;
  }
  if ( *(uint8_t *)off_115788 )
    *(uint32_t *)ipc_doorbell_handler_n_210 |= 0x2000000u;
  else
    *((uint32_t *)off_115768 + 14) &= ~0x10u;
  result = feature_guard_check(2, ipc_doorbell_handler_n_1f0);
  v8 = *(uint8_t **)ipc_doorbell_handler_n_1ec;
  v9 = **(unsigned __int8 **)ipc_doorbell_handler_n_1ec;
  if ( v9 == 2 )
  {
    if ( **v5 == 3 )
sdio_buffer_prepare_n58:
      *(uint32_t *)ipc_doorbell_handler_n_1d4 &= ~1u;
  }
  else
  {
    if ( !v3[189] )
    {
      *(uint32_t *)off_115794 = (unsigned __int8)(16 * *v1);
      v9 = (unsigned __int8)*v8;
    }
    if ( v9 == 1 )
    {
      v10 = ipc_doorbell_handler_n_1e4;
      v11 = dword_11579C;
      v12 = off_1157A0;
      do
      {
        if ( *(uint8_t *)(v10 + 37) )
        {
          result = v12[4];
          **(uint32_t **)(v10 + 340) = result;
        }
        v10 += 696;
      }
      while ( v10 != v11 );
    }
    if ( **v5 == 3 && *v8 == 2 )
      goto sdio_buffer_prepare_n58;
  }
  return result;
}

