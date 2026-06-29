// fwstruct annotate: 128288_sub_128288.c
// sub_128288 @ 0x128288, size 94 bytes
int __fastcall sub_128288(unsigned int a1, unsigned int a2, unsigned int a3)
{
  int *v3; // r4
  int *v4; // r3
  int v5; // r5
  int v6; // t1
  int v7; // t1
  unsigned int v8; // r6
  char *v9; // r1
  char *v10; // r4
  int v11; // r5
  int v12; // t1
  int v13; // r2
  int v14; // t1

  if ( a3 <= 3 )
  {
LABEL_5:
    v8 = a3 - 1;
    if ( !a3 )
      return 0;
  }
  else
  {
    v3 = (int *)a1;
    v4 = (int *)a2;
    if ( !((a1 | a2) << 30) )
    {
      while ( 1 )
      {
        a2 = (unsigned int)v4;
        a1 = (unsigned int)v3;
        v6 = *v4++;
        v5 = v6;
        v7 = *v3++;
        if ( v7 != v5 )
          break;
        a3 -= 4;
        a1 = (unsigned int)v3;
        a2 = (unsigned int)v4;
        if ( a3 <= 3 )
          goto LABEL_5;
      }
    }
    v8 = a3 - 1;
  }
  v9 = (char *)(a2 - 1);
  v10 = (char *)(a1 - 1);
  do
  {
    v12 = (unsigned __int8)*++v10;
    v11 = v12;
    v14 = (unsigned __int8)*++v9;
    v13 = v14;
    if ( v11 != v14 )
      return v11 - v13;
  }
  while ( a1 + v8 - (_DWORD)v10 );
  return 0;
}

