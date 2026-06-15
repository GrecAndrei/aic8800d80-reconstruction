// v23 annotated: ipc_doorbell_handler @ 0x11597c
// Original: 11597c_ipc_doorbell_handler.c
// Primary struct: <unclustered>
//
// ipc_doorbell_handler @ 0x11597c, size 300 bytes
// Doc: ipc_doorbell_irq_handler_5a6a [ipc]: Handles IPC doorbell interrupt by setting MMIO flags
// ipc_doorbell_irq_handler_5a6a [ipc]: Handles IPC doorbell interrupt by setting MMIO flags
_BYTE *ipc_doorbell_handler()
{
  _DWORD *v0; // r4
  _BYTE *v1; // r5
  int v2; // r1
  _DWORD *v3; // r2
  _DWORD *v4; // r2
  unsigned __int8 *v5; // r1
  int v6; // r1
  _DWORD *v7; // r2
  _DWORD *v8; // r1
  unsigned __int8 **v9; // r1
  int v10; // r3
  _BYTE *result; // r0
  int v12; // r2
  _DWORD *v13; // r3
  _DWORD *v14; // r3
  _DWORD *v15; // r3

  v0 = ipc_doorbell_handler_n12c;
  v1 = ipc_doorbell_handler_aac;
  v2 = ipc_doorbell_handler_n134;
  *(_BYTE *)ipc_doorbell_handler_aac = *(_BYTE *)ipc_doorbell_handler_n12c & 0xF;
  feature_guard_check(2, v2);
  if ( *v0 << 28 )
  {
    v3 = ipc_doorbell_handler_n13c;
    *(_DWORD *)off_115AB4 &= ~0x80000000;
    *v0 = 0;
    while ( (*v3 & 4) == 0 )
      ;
    v4 = off_115AB4;
    v5 = (unsigned __int8 *)ipc_doorbell_handler_n144;
    *(_DWORD *)off_115ABC = 4;
    v6 = v5[189];
    *v4 |= 0x80000000;
    if ( v6 )
      *(_DWORD *)((char *)v4 + 0xFFFFFFD4) |= 0x8000000u;
  }
  else
  {
    *(_DWORD *)ipc_doorbell_handler_3 &= ~0x8000000u;
  }
  v7 = ipc_doorbell_handler_n148;
  v8 = ipc_doorbell_handler_n12c;
  *(_DWORD *)ipc_doorbell_handler_n148 |= 0x111u;
  v1[1] = 1;
  *v8 = 32;
  v9 = (unsigned __int8 **)ipc_doorbell_handler_n14c;
  *v7 &= 0xFFFFFEEE;
  v10 = **v9;
  if ( v10 == 3 )
  {
    v14 = off_115AD4;
    *(_DWORD *)off_115AD4 |= 1u;
    if ( (*v14 & 4) != 0 )
      *(_DWORD *)off_115AD8 = 512;
  }
  else if ( v10 == 1 )
  {
    sdio_wait_busy_clear();
    v15 = off_115AE0;
    *(_DWORD *)ipc_doorbell_isr_entry |= 0x20u;
    v15[20] |= 0x20000u;
    v15[20] |= 0x8000u;
    v15[20] |= 0x10000u;
    v15[20] = v15[20] & 0xFFFFFFC0 | 0x37;
    v15[23] = v15[23] & 0x7FFFFFFC | 0x80000001;
  }
  result = off_115ACC;
  v12 = 0;
  *(_BYTE *)off_115ACC = 0;
  while ( 1 )
  {
    v13 = (_DWORD *)(4 * v12++ - 536813312);
    if ( (v13[64] & *v13) != 0 )
      break;
    if ( v12 == 3 )
      return result;
  }
  *result = 1;
  return result;
}

