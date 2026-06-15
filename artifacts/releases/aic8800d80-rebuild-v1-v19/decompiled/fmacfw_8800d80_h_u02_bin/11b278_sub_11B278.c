// sub_11B278 @ 0x11b278, size 194 bytes
int __fastcall sub_11B278(int a1)
{
  unsigned int CPSR; // r3
  int result; // r0
  _BYTE *v4; // r7
  int *v5; // r6
  char *v6; // r2
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // r1

  CPSR = __get_CPSR();
  result = CPSR << 31;
  if ( (CPSR & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11B33C = 1;
  }
  v4 = off_11B340;
  v5 = (int *)off_11B344;
  v6 = (char *)off_11B340 + 28 * a1;
  v7 = (unsigned __int8)v6[47];
  v8 = *(_DWORD *)off_11B344 + 1;
  *(_DWORD *)off_11B344 = v8;
  if ( v7 )
  {
    v9 = *((_DWORD *)v6 + 10);
    v6[47] = 0;
    if ( v9 << 28 )
    {
      *(_DWORD *)(dword_11B34C + 4 * a1) = v9;
      sub_11B228((unsigned __int8)a1);
    }
    else if ( !v6[46] )
    {
      v6[46] = 1;
    }
    v4[28 * a1 + 45] = v4[28 * a1 + 44];
    goto LABEL_8;
  }
  if ( !v6[45] )
  {
LABEL_17:
    *(_DWORD *)&v4[28 * a1 + 24] = 0;
    goto LABEL_9;
  }
  v12 = (unsigned __int8)(v6[45] - 1);
  v6[45] = v12;
  if ( !v12 )
  {
    *(_DWORD *)(dword_11B34C + 4 * a1) = *(_DWORD *)(*((_DWORD *)v4 + 4) + 4 * (a1 + 2));
    result = sub_11B228((unsigned __int8)a1);
    v8 = *v5;
    goto LABEL_17;
  }
LABEL_8:
  result = sub_124BFC(&v4[28 * a1 + 20], *((_DWORD *)off_11B348 + 4) + 0x2000);
  v8 = *v5;
LABEL_9:
  if ( v8 )
  {
    v10 = v8 - 1;
    v11 = *(_DWORD *)off_11B33C;
    *v5 = v10;
    if ( !v10 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

