// fwstruct annotate: 11b8d0_message_dispatch_n34c.c
// message_dispatch_n34c @ 0x11b8d0, size 204 bytes
// Doc: message_dispatch_n34c [ipc]: Dispatch incoming host message by opcode
// message_dispatch_n34c [ipc]: Dispatch incoming host message by opcode
int __fastcall message_dispatch_n34c(int result, int a2, int a3, int a4)
{
  _DWORD *v4; // r5
  char *v5; // r3
  int v6; // r2
  int v7; // r4
  int v8; // r6
  BOOL v9; // r3
  __int16 **v10; // r7

  v4 = off_11B99C;
  if ( *((_BYTE *)off_11B99C + 160) )
  {
    v5 = (char *)off_11B99C + 28 * result;
    v6 = *((_DWORD *)v5 + 6);
    v5[47] = 1;
    v7 = result;
    v8 = 8 * result;
    if ( !v6 )
    {
      switch ( (char)result )
      {
        case 0:
          v9 = (*(_DWORD *)off_11B9A0 & 0x30) == 0;
          goto LABEL_6;
        case 1:
          v9 = (*(_DWORD *)off_11B9A0 & 0x300) == 0;
          goto LABEL_6;
        case 2:
          v9 = (*(_DWORD *)off_11B9A0 & 0x3000) == 0;
          goto LABEL_6;
        case 3:
          v9 = (*(_DWORD *)off_11B9A0 & 0x30000) == 0;
          goto LABEL_6;
        case 4:
          v9 = (*(_DWORD *)off_11B9A0 & 3) == 0;
LABEL_6:
          if ( v9 )
            goto LABEL_9;
          v10 = (__int16 **)off_11B9A4;
          break;
        default:
          v10 = (__int16 **)off_11B9A4;
          if ( **(__int16 **)off_11B9A4 >= 0 )
            goto LABEL_9;
          sub_12F694(dword_11B9B0, dword_11B9B4, 520);
          break;
      }
      if ( **v10 < 0 )
      {
        return sub_12F630(dword_11B9B0, dword_11B9AC, 684, a4);
      }
      else
      {
LABEL_9:
        v4[v8 - v7 + 6] = dword_11B9A8;
        return sub_11B7F8(v7);
      }
    }
  }
  return result;
}

