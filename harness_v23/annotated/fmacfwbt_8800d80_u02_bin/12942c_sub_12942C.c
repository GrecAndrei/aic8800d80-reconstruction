// v23 annotated: sub_12942C @ 0x12942c
// Original: 12942c_sub_12942C.c
// Primary struct: <unclustered>
//
// sub_12942C @ 0x12942c, size 184 bytes
void __fastcall sub_12942C(unsigned __int16 *a1, __int16 a2, int a3)
{
  _BYTE *v3; // r5
  unsigned __int16 v4; // r6
  int v6; // r3
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r1

  v3 = off_1294E4;
  if ( *(_BYTE *)off_1294E4 )
  {
    v4 = *a1;
    if ( (a1[2] & 1) != 0 )
    {
      if ( *((_BYTE *)off_1294E4 + 29) == 5 )
      {
        sub_125058((int)off_1294E4 + 12);
        v3[29] = 0;
      }
      if ( (v4 & 0x2000) == 0 || *(_BYTE *)(a3 + 114) )
      {
        *(_DWORD *)(a3 + 4) &= ~2u;
      }
      else
      {
        *(_DWORD *)(a3 + 4) |= 2u;
        if ( !v3[29] )
        {
          v9 = *((_DWORD *)off_1294F0 + 4);
          v10 = *(unsigned __int16 *)(*(_DWORD *)off_1294EC + 56);
          *((_DWORD *)v3 + 5) = a3;
          v3[29] = 5;
          sub_124F60(dword_1294F4, v10 + v9);
        }
      }
    }
    else if ( *(_BYTE *)off_1294E8 )
    {
      sub_1423D4(a3, *a1, a1);
    }
    else if ( (a2 & 0x200) == 0 )
    {
      v6 = *((_DWORD *)off_1294F0 + 4);
      v7 = *(unsigned __int16 *)(*(_DWORD *)off_1294EC + 54);
      *((_DWORD *)off_1294E4 + 5) = a3;
      v3[29] = 2;
      sub_124F60((int)(v3 + 12), v7 + v6);
      v8 = *(_DWORD *)(a3 + 4);
      if ( (v4 & 0x2000) != 0 )
      {
        if ( (v8 & 4) == 0 )
          *(_DWORD *)(a3 + 4) = v8 | 4;
        sub_1290C4();
      }
      else
      {
        *(_DWORD *)(a3 + 4) = v8 & 0xFFFFFFFB;
      }
    }
  }
}

