// sub_12419C @ 0x12419c, size 140 bytes
int __fastcall sub_12419C(int a1, int a2, int a3, int a4, int a5)
{
  _BYTE *v5; // r9
  char v8; // r8
  int v10; // r3
  int *v11; // r3
  int v12; // r5
  int v13; // r6
  int v14; // r4
  int v15; // r5

  v5 = off_124240;
  v8 = a3;
  msg_parse(dword_124228, a1, a2, a3, a4, a5, *((unsigned __int8 *)off_124240 + 36));
  if ( v5[36] )
  {
    if ( a1 == 2 )
    {
      v10 = *(_DWORD *)off_12423C;
    }
    else
    {
      if ( a1 == 1 )
        v11 = (int *)dword_124230;
      else
        v11 = (int *)dword_124234;
      v10 = *v11;
    }
  }
  else if ( a1 )
  {
    v10 = *(_DWORD *)off_12422C;
  }
  else
  {
    v10 = *(_DWORD *)off_124238;
  }
  v12 = v10 + 4 * a2;
  v13 = ~(a4 << v8);
  v14 = v12 + 12;
  v15 = v12 + 204;
  do
  {
    *(_DWORD *)(v14 - 12) = *(_DWORD *)(v14 - 12) & v13 | (a5 << v8);
    v14 += 12;
  }
  while ( v15 != v14 );
  return lmac_sub_init(1, (16 * a1) & 0xF0, 0x10u, v10);
}

