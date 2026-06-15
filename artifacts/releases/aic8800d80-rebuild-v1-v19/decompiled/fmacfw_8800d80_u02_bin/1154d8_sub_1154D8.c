// sub_1154D8 @ 0x1154d8, size 180 bytes
// Doc: sdio_buffer_prepare_n_11c [util]: Initializes SDIO buffer descriptor chain
// sdio_buffer_prepare_n_11c [util]: Initializes SDIO buffer descriptor chain
int sub_1154D8()
{
  _BYTE *v0; // r4
  int result; // r0
  _DWORD *v2; // r3
  int v3; // r3

  v0 = off_11558C;
  if ( !*(_BYTE *)off_11558C && *(_BYTE *)ipc_doorbell_handler_n_3ec )
  {
    result = feature_guard_check(2, patch_apply_n2e0);
    v2 = ipc_doorbell_handler_n_3dc;
    *v0 = 1;
    if ( (unsigned __int16)*v2 )
    {
      switch ( *(_BYTE *)off_1155A4 )
      {
        case 1:
          v3 = 700 * (unsigned __int16)*(_DWORD *)ipc_doorbell_handler_n_3dc;
          break;
        case 2:
          v3 = 500 * (unsigned __int16)*(_DWORD *)ipc_doorbell_handler_n_3dc;
          break;
        case 3:
          v3 = 300 * (unsigned __int16)*(_DWORD *)ipc_doorbell_handler_n_3dc;
          break;
        case 4:
          v3 = 200 * (unsigned __int16)*(_DWORD *)ipc_doorbell_handler_n_3dc;
          break;
        case 5:
          v3 = 100 * (unsigned __int16)*(_DWORD *)ipc_doorbell_handler_n_3dc;
          break;
        default:
          v3 = 100 * (unsigned __int16)*(_DWORD *)ipc_doorbell_handler_n_3dc;
          break;
      }
      return timestamp_update(dword_1155AC, *((_DWORD *)ipc_doorbell_handler_n_3d4 + 4) + v3);
    }
  }
  else
  {
    result = feature_guard_check(2, dword_115594);
    if ( *((_BYTE *)ipc_doorbell_handler_n_3e4 + 18) )
      *v0 = 0;
  }
  return result;
}

