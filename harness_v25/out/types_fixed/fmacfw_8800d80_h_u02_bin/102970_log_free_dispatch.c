// log_free_dispatch @ 0x102970, size 152 bytes
int __fastcall log_free_dispatch(unsigned __int16 *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  unsigned __int8 *v8; // r0
  int v9; // r1
  unsigned int v10; // r1
  unsigned int v11; // r2
  int v12; // r3
  int result; // r0
  int v14; // r1
  int v15; // r3
  int v16; // r2
  void *v17; // r0
  char *v18; // r1

  if ( a2 )
  {
    v16 = a2;
    v17 = off_102A18;
    v18 = off_102A1C;
  }
  else
  {
    if ( *(_BYTE *)off_102A08 )
      goto LABEL_4;
    v8 = (unsigned __int8 *)off_102A10;
    v9 = *((unsigned __int16 *)off_102A10 + 18);
    *(_DWORD *)off_102A0C &= ~0x200u;
    if ( v9 != *a1 )
      goto LABEL_4;
    v12 = *((unsigned __int8 *)a1 + 9);
    v10 = *(_DWORD *)(a1 + 0x4);
    if ( *(_DWORD *)(v8 + 0xb4) != v12 )
    {
      v11 = *(_DWORD *)(a1 + 0x8);
      goto LABEL_5;
    }
    v11 = *(_DWORD *)(a1 + 0x8);
    if ( *((unsigned __int16 *)v8 + 19) != v10
      || *((unsigned __int16 *)v8 + 20) != v11
      || *((unsigned __int16 *)v8 + 21) != *(_DWORD *)(a1 + 0xc) )
    {
      goto LABEL_5;
    }
    if ( sub_12CD48(7) == 1 || sub_12CD48(6) == 3 )
    {
LABEL_4:
      v10 = *(_DWORD *)(a1 + 0x4);
      v11 = *(_DWORD *)(a1 + 0x8);
      LOBYTE(v12) = *((_BYTE *)a1 + 9);
LABEL_5:
      sub_101EC0(*(unsigned __int8 *)a1, v10, v11, *((unsigned __int8 *)a1 + 1), v12, 0);
      result = *(_DWORD *)a1;
      v14 = *((_DWORD *)a1 + 1);
      v15 = dword_102A14;
      *(_DWORD *)dword_102A14 = *(_DWORD *)a1;
      *(_DWORD *)(v15 + 4) = v14;
      *(_WORD *)(v15 + 8) = *(_DWORD *)(a1 + 0x10);
      return result;
    }
    v18 = off_102A1C;
    v17 = off_102A20;
  }
  return msg_parse(v17, v18, v16, a4, a5, a6, a7);
}

