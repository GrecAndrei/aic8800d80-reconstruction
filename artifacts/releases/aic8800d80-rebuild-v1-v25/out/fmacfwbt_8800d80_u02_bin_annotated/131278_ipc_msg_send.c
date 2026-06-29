// fwstruct annotate: 131278_ipc_msg_send.c
// ipc_msg_send @ 0x131278, size 162 bytes
// Doc: ipc_msg_send [ipc]: Send IPC message via dispatch helper
// ipc_msg_send [ipc]: Send IPC message via dispatch helper
unsigned __int8 *__fastcall ipc_msg_send(unsigned __int8 *a1, int a2, int a3, _BYTE *a4)
{
  unsigned __int8 *result; // r0
  unsigned __int8 v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r5
  __int64 v10; // r2

  result = sdio_buffer_prepare_df08(a1, a2);
  *a4 = 0;
  if ( result )
  {
    v7 = result[8];
    if ( *(_BYTE *)(a3 + 18) != (v7 & 0xF) )
    {
      *a4 = 1;
      *(_BYTE *)(a3 + 16) = v7;
      *(_BYTE *)(a3 + 18) = v7 & 0xF;
      v8 = *(_DWORD *)(result + 14);
      v9 = *(_DWORD *)(result + 10);
      HIDWORD(v10) = *(_DWORD *)(result + 22) & 0xF | (16 * (*(_DWORD *)(result + 22) >> 8));
      LODWORD(v10) = *(_DWORD *)(result + 18) & 0xF | (16 * (*(_DWORD *)(result + 18) >> 8));
      *(_BYTE *)(a3 + 17) = ((v8 & 0x10) != 0)
                          | (*(_DWORD *)(result + 18) >> 2) & 4
                          | (*(_DWORD *)(result + 22) >> 1) & 8
                          | (v9 >> 3) & 2;
      *(_DWORD *)a3 = v8 & 0xF | (16 * (v8 >> 8));
      *(_DWORD *)(a3 + 4) = v9 & 0xF | (16 * (v9 >> 8));
      *(_QWORD *)(a3 + 8) = v10;
    }
    return (unsigned __int8 *)1;
  }
  else
  {
    *(_DWORD *)a3 = 2627;
    *(_DWORD *)(a3 + 4) = 2627;
    *(_DWORD *)(a3 + 8) = 2627;
    *(_DWORD *)(a3 + 12) = 2627;
  }
  return result;
}

