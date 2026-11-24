// sub_102A20 @ 0x102a20, size 152 bytes
int __fastcall sub_102A20(unsigned __int16 *a1, int a2)
{
  unsigned __int8 *v3; // r0
  int v4; // r1
  int v5; // r1
  int v6; // r2
  int result; // r0
  int v8; // r1
  int v9; // r3
  int v10; // r2

  if ( a2 )
    return msg_parse(dword_102AC8, dword_102ACC, a2);
  if ( *(_BYTE *)off_102AB8 )
    goto LABEL_4;
  v3 = (unsigned __int8 *)off_102AC0;
  v4 = *((unsigned __int16 *)off_102AC0 + 18);
  *(_DWORD *)off_102ABC &= ~0x200u;
  if ( v4 != *a1 )
    goto LABEL_4;
  v5 = *(_DWORD *)(a1 + 0x4);
  if ( *(_DWORD *)(v3 + 0xb4) != *((unsigned __int8 *)a1 + 9) )
  {
    v6 = *(_DWORD *)(a1 + 0x8);
    goto LABEL_5;
  }
  v6 = *(_DWORD *)(a1 + 0x8);
  if ( *((unsigned __int16 *)v3 + 19) != v5
    || *((unsigned __int16 *)v3 + 20) != v6
    || *((unsigned __int16 *)v3 + 21) != *(_DWORD *)(a1 + 0xc) )
  {
    goto LABEL_5;
  }
  if ( msg_get_value(7u) == 1 || msg_get_value(6u) == 3 )
  {
LABEL_4:
    v5 = *(_DWORD *)(a1 + 0x4);
    v6 = *(_DWORD *)(a1 + 0x8);
LABEL_5:
    sub_101F70(*(unsigned __int8 *)a1, v5, v6, *((unsigned __int8 *)a1 + 1));
    result = *(_DWORD *)a1;
    v8 = *((_DWORD *)a1 + 1);
    v9 = dword_102AC4;
    *(_DWORD *)dword_102AC4 = *(_DWORD *)a1;
    *(_DWORD *)(v9 + 4) = v8;
    *(_WORD *)(v9 + 8) = *(_DWORD *)(a1 + 0x10);
    return result;
  }
  return msg_parse(dword_102AD0, dword_102ACC, v10);
}
