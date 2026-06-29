// fwstruct annotate: 13e090_sub_13E090.c
// sub_13E090 @ 0x13e090, size 160 bytes
int __fastcall sub_13E090(int result, int a2)
{
  unsigned int v2; // r11
  int v4; // r9
  int v5; // r5
  int v6; // r7
  _DWORD *v7; // r4
  int v8; // r6
  unsigned int v9; // r1
  __int64 v10; // r2
  unsigned int v11; // t1
  __int64 v12; // kr00_8
  _BYTE v13[52]; // [sp+4h] [bp-34h] BYREF

  if ( *(_WORD *)(result + 184) )
  {
    v2 = (unsigned __int16)(*(_WORD *)(result + 184) - 1);
    v4 = result + 16;
    if ( v2 > 1 )
    {
      do
      {
        v5 = 1;
        v6 = 1;
        v7 = (_DWORD *)(a2 + 4);
        v8 = v4;
        v9 = 0;
        do
        {
          while ( 1 )
          {
            LODWORD(v10) = *v7;
            v11 = v7[1];
            ++v7;
            HIDWORD(v10) = v11;
            if ( (unsigned int)v10 > v11 || !v10 && !*(_BYTE *)(v8 + 9) && *(_BYTE *)(v8 + 21) == 1 )
              break;
            v6 = (unsigned __int16)++v5;
            v8 += 12;
            if ( (unsigned __int16)v5 >= v2 )
              goto LABEL_10;
          }
          sub_143764(v13, v8);
          sub_143764(v8, v8 + 12);
          result = sub_143764(v8 + 12, v13);
          ++v5;
          v12 = *(_QWORD *)(v7 - 1);
          v9 = v6;
          v6 = (unsigned __int16)v5;
          *(v7 - 1) = HIDWORD(v12);
          *v7 = v12;
          v8 += 12;
        }
        while ( (unsigned __int16)v5 < v2 );
LABEL_10:
        if ( !v9 )
          break;
        v2 = v9;
      }
      while ( v9 > 1 );
    }
  }
  return result;
}

