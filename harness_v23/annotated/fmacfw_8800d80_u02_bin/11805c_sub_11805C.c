// v23 annotated: sub_11805C @ 0x11805c
// Original: 11805c_sub_11805C.c
// Primary struct: <unclustered>
//
// sub_11805C @ 0x11805c, size 178 bytes
_DWORD *sub_11805C()
{
  _DWORD *result; // r0
  _DWORD *v1; // r4
  _DWORD *v2; // r0
  _DWORD *v3; // r5
  int *v4; // r2
  int v5; // r0
  int *v6; // r6
  _DWORD *v7; // r2
  int v8; // r1
  _WORD *v9; // r4
  __int16 v10; // r2
  int v11; // r3
  _DWORD *v12; // r5
  int v13; // r1
  int v14; // r3
  int v15; // r3

  result = (_DWORD *)(*(int (__fastcall **)(_DWORD))(*((_DWORD *)off_118110 + 2) + 16))(*((_DWORD *)off_118110 + 1));
  if ( result )
  {
    v1 = result;
    v2 = (_DWORD *)sub_1102BC();
    v3 = v2;
    if ( v2 )
    {
      v4 = (int *)off_118114;
      *v2 = 0;
      v5 = *v4;
      v3[1] = 0;
      v3[2] = 0;
      *v3 = (char *)v1 + v5;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_118118 = 1;
      }
      v6 = (int *)off_11811C;
      v7 = off_118120;
      v8 = *(_DWORD *)off_11811C + 1;
      *(_DWORD *)off_11811C = v8;
      *v7 = 1;
      while ( (*v7 & 2) != 0 )
        ;
      if ( *(_DWORD *)off_118124 )
      {
        v9 = off_11812C;
        v15 = *((_DWORD *)off_11812C + 1);
        if ( v15 )
        {
          *(_DWORD *)(v15 + 4) = v3;
        }
        else
        {
          msg_parse(dword_118138, v8, v7);
          v8 = *v6;
        }
      }
      else
      {
        if ( *(_DWORD *)off_118128 )
        {
          msg_parse(dword_118134, v8, v7);
          v8 = *v6;
        }
        v9 = off_11812C;
        *(_DWORD *)off_118128 = v3;
      }
      result = off_118124;
      v10 = v9[6];
      v11 = *(_DWORD *)off_118124;
      *((_DWORD *)v9 + 1) = v3;
      v12 = off_118130;
      v9[6] = v10 + 1;
      *result = v11 + 1;
      *v12 = 1;
      if ( v8 )
      {
        v13 = v8 - 1;
        v14 = *(_DWORD *)off_118118;
        *v6 = v13;
        if ( !v13 )
        {
          if ( v14 )
            __enable_irq();
        }
      }
    }
    else
    {
      return (_DWORD *)log_free_dispatch_2(v1);
    }
  }
  return result;
}

