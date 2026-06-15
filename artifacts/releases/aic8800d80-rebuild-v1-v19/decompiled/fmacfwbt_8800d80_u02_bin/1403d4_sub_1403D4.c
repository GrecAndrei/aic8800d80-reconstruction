// sub_1403D4 @ 0x1403d4, size 92 bytes
// Doc: sub_12403D4 [bt]: BT firmware helper with register shifts and stack args
// sub_12403D4 [bt]: BT firmware helper with register shifts and stack args
int __fastcall sub_1403D4(int result, unsigned int a2, int a3, int a4, unsigned __int8 a5, int a6, int a7, char a8)
{
  unsigned int v8; // r2
  unsigned int v9; // r1
  unsigned int v10; // r1
  unsigned int v11; // r3
  unsigned int v12; // r3

  v8 = a2 >> 11;
  if ( ((a2 >> 11) & 6) == 0 )
  {
    v12 = *(_DWORD *)(result + 60) & 0xFFFFFFEF;
    goto LABEL_11;
  }
  v9 = a2 & 0x7F;
  if ( (v8 & 7) == 4 )
    v10 = v9 >> 4;
  else
    v10 = (v9 >> 3) & 3;
  if ( a4 && v10 == a5 )
  {
    v11 = *(_DWORD *)(result + 60) | 4;
    *(_DWORD *)(result + 60) = v11;
    if ( !a8 )
      goto LABEL_10;
LABEL_7:
    *(_DWORD *)(result + 60) = v11 | 0x10;
    return result;
  }
  v11 = *(_DWORD *)(result + 60) & 0xFFFFFFFB;
  *(_DWORD *)(result + 60) = v11;
  if ( a8 )
    goto LABEL_7;
LABEL_10:
  v12 = v11 & 0xFFFFFFEF;
LABEL_11:
  *(_DWORD *)(result + 60) = v12;
  return result;
}

