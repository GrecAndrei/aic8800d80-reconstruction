// v23 annotated: sub_117F1C @ 0x117f1c
// Original: 117f1c_sub_117F1C.c
// Primary struct: <unclustered>
//
// sub_117F1C @ 0x117f1c, size 178 bytes
_DWORD *sub_117F1C()
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

  result = (_DWORD *)(*(int (__fastcall **)(_DWORD))(*((_DWORD *)off_117FD0 + 2) + 16))(*((_DWORD *)off_117FD0 + 1));
  if ( result )
  {
    v1 = result;
    v2 = (_DWORD *)sub_11017C();
    v3 = v2;
    if ( v2 )
    {
      v4 = (int *)off_117FD4;
      *v2 = 0;
      v5 = *v4;
      v3[1] = 0;
      v3[2] = 0;
      *v3 = (char *)v1 + v5;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_117FD8 = 1;
      }
      v6 = (int *)off_117FDC;
      v7 = off_117FE0;
      v8 = *(_DWORD *)off_117FDC + 1;
      *(_DWORD *)off_117FDC = v8;
      *v7 = 1;
      while ( (*v7 & 2) != 0 )
        ;
      if ( *(_DWORD *)off_117FE4 )
      {
        v9 = off_117FEC;
        v15 = *((_DWORD *)off_117FEC + 1);
        if ( v15 )
        {
          *(_DWORD *)(v15 + 4) = v3;
        }
        else
        {
          sub_12E948(dword_117FF8, v8, v7);
          v8 = *v6;
        }
      }
      else
      {
        if ( *(_DWORD *)off_117FE8 )
        {
          sub_12E948(dword_117FF4, v8, v7);
          v8 = *v6;
        }
        v9 = off_117FEC;
        *(_DWORD *)off_117FE8 = v3;
      }
      result = off_117FE4;
      v10 = v9[6];
      v11 = *(_DWORD *)off_117FE4;
      *((_DWORD *)v9 + 1) = v3;
      v12 = off_117FF0;
      v9[6] = v10 + 1;
      *result = v11 + 1;
      *v12 = 1;
      if ( v8 )
      {
        v13 = v8 - 1;
        v14 = *(_DWORD *)off_117FD8;
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
      return (_DWORD *)sub_10FEC8(v1);
    }
  }
  return result;
}

