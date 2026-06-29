// fwstruct annotate: 100898_sub_100898.c
// sub_100898 @ 0x100898, size 234 bytes
int __fastcall sub_100898(int a1, unsigned int a2, _DWORD *a3)
{
  char *v3; // r5
  int v4; // r7
  int v5; // r1
  int v6; // r6
  int j; // r3
  int v8; // t1
  bool v9; // nf
  int v10; // r0
  int result; // r0
  int v12; // r7
  int v13; // r5
  char *v14; // r6
  int v15; // r1
  unsigned __int8 *v16; // r4
  int i; // r5
  int v18; // t1
  int v19; // r3
  bool v20; // zf

  if ( a1 )
  {
    if ( a2 > 0x1666 )
    {
      v13 = 1920;
      v12 = 5;
    }
    else if ( a2 > 0x1616 )
    {
      v13 = 1536;
      v12 = 4;
    }
    else if ( a2 > 0x15C6 )
    {
      v13 = 1152;
      v12 = 3;
    }
    else if ( a2 > 0x1571 )
    {
      v13 = 768;
      v12 = 2;
    }
    else
    {
      v12 = a2 > 0x1486;
      if ( a2 <= 0x1486 )
        v13 = 0;
      else
        v13 = 384;
    }
    v14 = (char *)dword_10099C;
    v15 = 0;
    result = dword_100998 + v13;
    v16 = (unsigned __int8 *)(*(_DWORD *)off_100994 + v12);
    for ( i = 0; i != 3; ++i )
    {
      v18 = *v14++;
      v19 = *v16 + v18 + *((unsigned __int8 *)off_100988 + 1);
      v20 = (v19 & 1) == 0;
      if ( (v19 & 1) != 0 )
        v19 = 1 << i;
      if ( !v20 )
        v15 |= v19;
      v16 += 6;
    }
    *a3 = v15;
  }
  else
  {
    if ( a2 > 0x97B )
    {
      if ( a2 > 0x994 )
        a1 = 2;
      else
        a1 = 1;
    }
    v3 = (char *)dword_10098C;
    v4 = *(unsigned __int8 *)off_100988;
    v5 = 0;
    v6 = *(_DWORD *)off_100984 + a1;
    for ( j = 0; j != 3; ++j )
    {
      v8 = *v3++;
      v10 = (*(unsigned __int8 *)(v6 + 3 * j) + v8 + v4) << 31;
      v9 = ((*(unsigned __int8 *)(v6 + 3 * j) + v8 + v4) & 1) != 0;
      if ( ((*(unsigned __int8 *)(v6 + 3 * j) + v8 + v4) & 1) != 0 )
        v10 = 1 << j;
      if ( v9 )
        v5 |= v10;
    }
    result = dword_100990;
    *a3 = v5;
  }
  return result;
}

