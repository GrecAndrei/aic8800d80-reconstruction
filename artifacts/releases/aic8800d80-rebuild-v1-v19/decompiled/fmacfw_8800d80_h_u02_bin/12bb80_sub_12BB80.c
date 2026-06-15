// sub_12BB80 @ 0x12bb80, size 110 bytes
int __fastcall sub_12BB80(int a1)
{
  unsigned int v1; // r2
  _DWORD *v2; // r5
  int v3; // r6
  int v4; // r3
  int v5; // r7
  unsigned int v6; // r1
  int v7; // r3
  int *v8; // r1
  int *v9; // r4
  int v10; // r0
  int result; // r0
  int *v12; // r3
  int v13; // r3

  v1 = abs32(a1);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12BBF0 = 1;
  }
  v2 = off_12BBF4;
  v3 = *(_DWORD *)off_12BBF4;
  v4 = *(_DWORD *)off_12BBF8;
  v5 = *(_DWORD *)off_12BBF4 + 1;
  v6 = *(_DWORD *)off_12BBFC;
  *(_DWORD *)off_12BBF4 = v5;
  v7 = v4 | 0x1000000;
  if ( a1 <= 0 )
  {
    if ( !a1 || ~v6 >= v1 + 32 )
      goto LABEL_5;
LABEL_13:
    result = -1;
    goto LABEL_6;
  }
  if ( v1 > v6 )
    goto LABEL_13;
LABEL_5:
  v8 = (int *)off_12BBFC;
  v9 = (int *)off_12BBF8;
  v10 = *(_DWORD *)off_12BBFC - a1;
  *(_DWORD *)off_12BBFC = v10;
  *v9 = v7;
  *v8 = v10;
  *v9 = v7;
  *v8 = v10;
  result = 0;
  *v9 = v7;
LABEL_6:
  if ( v5 )
  {
    v12 = (int *)off_12BBF0;
    *v2 = v3;
    v13 = *v12;
    if ( !v3 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  return result;
}

