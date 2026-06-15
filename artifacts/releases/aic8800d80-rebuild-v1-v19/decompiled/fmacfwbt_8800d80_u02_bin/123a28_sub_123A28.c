// sub_123A28 @ 0x123a28, size 184 bytes
// Doc: ipc_msg_send [ipc]: Send IPC message with opcode 0x25 to peer core
// ipc_msg_send [ipc]: Send IPC message with opcode 0x25 to peer core
int __fastcall sub_123A28(int a1, unsigned __int8 *a2, int a3, int a4)
{
  _BYTE *v5; // r0
  __int16 **v6; // r6
  _BYTE *v7; // r5
  int v8; // r3

  v5 = (_BYTE *)rf_bus_setup_n3a8(37, a4, a3, 2);
  v6 = (__int16 **)off_123AE0;
  *v5 = 1;
  v7 = v5;
  if ( **v6 < 0 )
  {
    if ( *a2 <= 5u || (sub_12F694(dword_123AF0, dword_123AE8, 1725), **v6 < 0) )
    {
      if ( a2[4] > 0x20u )
        sub_12F694(dword_123AEC, dword_123AE8, 1726);
    }
  }
  switch ( a2[40] )
  {
    case 0u:
    case 1u:
    case 3u:
      v8 = (*(_DWORD *)off_123AE4 >> 6) & 1;
      goto LABEL_4;
    case 2u:
    case 5u:
    case 8u:
      v8 = (*(_DWORD *)off_123AE4 >> 7) & 1;
      goto LABEL_4;
    case 4u:
      v8 = (*(_DWORD *)off_123AE4 >> 13) & 1;
      goto LABEL_4;
    case 6u:
    case 7u:
      v8 = (*(_DWORD *)off_123AE4 >> 9) & 1;
LABEL_4:
      if ( v8 && a2[4] <= 0x20u && *a2 <= 5u )
      {
        v7[1] = sub_121678(a2);
        *v7 = 0;
      }
      break;
    default:
      break;
  }
  sub_12CBB4(v7);
  return 0;
}

