// sub_102898 @ 0x102898, size 152 bytes
int __fastcall sub_102898(unsigned __int16 *a1, int a2)
{
  unsigned __int8 *v3; // r0
  int v4; // r1
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int result; // r0
  int v9; // r1
  int v10; // r3
  int v11; // r2

  if ( a2 )
    return sub_12ECB0(dword_102940, dword_102944, a2);
  if ( *(_BYTE *)off_102930 )
    goto LABEL_4;
  v3 = (unsigned __int8 *)off_102938;
  v4 = *((unsigned __int16 *)off_102938 + 18);
  *(_DWORD *)off_102934 &= ~0x200u;
  if ( v4 != *a1 )
    goto LABEL_4;
  v7 = *((unsigned __int8 *)a1 + 9);
  v5 = *(_DWORD *)(a1 + 0x4);
  if ( *(_DWORD *)(v3 + 0xb4) != v7 )
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
    v7 = *((unsigned __int8 *)a1 + 9);
LABEL_5:
    sub_101DE8(*(unsigned __int8 *)a1, v5, v6, *((unsigned __int8 *)a1 + 1), v7, 0);
    result = *(_DWORD *)a1;
    v9 = *((_DWORD *)a1 + 1);
    v10 = dword_10293C;
    *(_DWORD *)dword_10293C = *(_DWORD *)a1;
    *(_DWORD *)(v10 + 4) = v9;
    *(_WORD *)(v10 + 8) = *(_DWORD *)(a1 + 0x10);
    return result;
  }
  return sub_12ECB0(dword_102948, dword_102944, v11);
}
