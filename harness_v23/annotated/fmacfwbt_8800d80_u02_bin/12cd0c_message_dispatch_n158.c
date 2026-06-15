// v23 annotated: message_dispatch_n158 @ 0x12cd0c
// Original: 12cd0c_message_dispatch_n158.c
// Primary struct: <unclustered>
//
// message_dispatch_n158 @ 0x12cd0c, size 200 bytes
// Doc: message_dispatch_n1a8 [ipc]: Dispatch message after null-check on header
// message_dispatch_n1a8 [ipc]: Dispatch message after null-check on header
int __fastcall message_dispatch_n158(int a1)
{
  __int16 **v1; // r7
  unsigned int v2; // r4
  unsigned int v3; // r6
  _DWORD *v4; // r3
  int *v5; // r5
  int v6; // r12
  _DWORD *v7; // r1
  unsigned int v8; // r2
  _DWORD *v9; // r2
  unsigned int v10; // r3
  int result; // r0
  int v12; // r2

  v1 = (__int16 **)msg_dispatch_branch_24_6c;
  v2 = (a1 + 3) & 0xFFFFFFFC;
  v3 = v2 + 4;
  if ( **(__int16 **)msg_dispatch_branch_24_6c < 0 && v3 <= 7 )
    sub_12F694(rf_cmd_process_n_1a6, message_dispatch_n230, 132);
  v4 = *((_DWORD **)message_dispatch_n224 + 7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)message_dispatch_n228_ddc = 1;
  }
  v5 = (int *)message_dispatch_n22c_cde0;
  v6 = *(_DWORD *)message_dispatch_n22c_cde0 + 1;
  *(_DWORD *)message_dispatch_n22c_cde0 = v6;
  if ( v4 )
  {
    v7 = nullptr;
    while ( 1 )
    {
      while ( 1 )
      {
        v8 = v4[1];
        if ( v8 >= v2 + 12 )
          break;
LABEL_8:
        v4 = (_DWORD *)*v4;
        if ( !v4 )
          goto message_dispatch_n1bb;
      }
      if ( v7 )
      {
        if ( v8 < v7[1] )
          v7 = v4;
        goto LABEL_8;
      }
      v7 = v4;
      v4 = (_DWORD *)*v4;
      if ( !v4 )
      {
message_dispatch_n1bb:
        if ( **v1 < 0 && !v7 )
          goto LABEL_20;
        v9 = v7;
        goto LABEL_14;
      }
    }
  }
  if ( **v1 >= 0 )
    __und(0xFFu);
LABEL_20:
  sub_12F694(message_dispatch_init_cde8, message_dispatch_n230, 160);
  v9 = nullptr;
  v6 = *v5;
  v7 = nullptr;
LABEL_14:
  v10 = v7[1] - v3;
  v7[1] = v10;
  result = (int)v9 + v10 + 4;
  *(_DWORD *)((char *)v9 + v10) = v3;
  if ( v6 )
  {
    v12 = *(_DWORD *)message_dispatch_n228_ddc;
    *v5 = v6 - 1;
    if ( v6 == 1 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}

