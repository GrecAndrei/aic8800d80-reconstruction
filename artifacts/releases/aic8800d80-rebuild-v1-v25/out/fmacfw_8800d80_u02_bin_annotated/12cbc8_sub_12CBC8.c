// fwstruct annotate: 12cbc8_sub_12CBC8.c
// sub_12CBC8 @ 0x12cbc8, size 226 bytes
// Doc: message_dispatch_n2fa [ipc]: Dispatches host messages to subsystem handlers
// message_dispatch_n2fa [ipc]: Dispatches host messages to subsystem handlers
_DWORD *__fastcall sub_12CBC8(char *a1)
{
  __int16 **v1; // r9
  char *v2; // r4
  int v3; // r8
  char *v5; // r5
  _DWORD *result; // r0
  int v7; // r12
  int v8; // r7
  int v9; // r3
  _DWORD *v10; // r1
  int *v11; // r3
  int v12; // r3
  int v13; // r3
  char *v14; // r2
  int v15; // r1
  __int64 v16; // r2

  v1 = (__int16 **)message_id_match_n338;
  v2 = *((char **)off_12CCAC + 7);
  v3 = *((_DWORD *)a1 - 1);
  v5 = a1 - 4;
  if ( **(__int16 **)message_id_match_n338 < 0 && a1 <= v2 )
    sub_12F46C(message_dispatch_ccbc, dword_12CCB8, 220);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)message_dispatch_n324 = 1;
  }
  result = message_dispatch_n328;
  v7 = *(_DWORD *)message_dispatch_n328;
  v8 = *(_DWORD *)message_dispatch_n328 + 1;
  *(_DWORD *)message_dispatch_n328 = v8;
  if ( !v2 )
  {
    MEMORY[0] = v5;
    __und(0xFFu);
  }
  v9 = *((_DWORD *)v2 + 1);
  if ( &v2[v9] != v5 )
  {
    if ( v2 > v5 )
    {
      if ( **v1 < 0 )
        sub_12F46C(message_dispatch_n334, dword_12CCB8, 247);
      MEMORY[0] = v5;
      __und(0xFFu);
    }
    while ( 1 )
    {
      v10 = v2;
      v2 = *(char **)v2;
      if ( !v2 )
        break;
      v9 = *((_DWORD *)v2 + 1);
      if ( &v2[v9] == v5 )
        goto LABEL_20;
      if ( v2 > v5 )
      {
        *v10 = v5;
        if ( v2 == &v5[v3] )
        {
          *((_DWORD *)a1 - 1) = *(_DWORD *)v2;
          *(_DWORD *)a1 = &v2[v9] - v5;
          goto LABEL_13;
        }
LABEL_12:
        *((_DWORD *)a1 - 1) = v2;
        *(_DWORD *)a1 = v3;
        goto LABEL_13;
      }
    }
    *v10 = v5;
    goto LABEL_12;
  }
LABEL_20:
  v13 = v9 + v3;
  v14 = *(char **)v2;
  *((_DWORD *)v2 + 1) = v13;
  if ( v14 == &v2[v13] )
  {
    v15 = *((_DWORD *)v14 + 1);
    LODWORD(v16) = *(_DWORD *)v14;
    HIDWORD(v16) = v13 + v15;
    *(_QWORD *)v2 = v16;
  }
LABEL_13:
  if ( v8 )
  {
    v11 = (int *)message_dispatch_n324;
    *result = v7;
    v12 = *v11;
    if ( !v7 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}

