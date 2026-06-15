// sub_114F00 @ 0x114f00, size 90 bytes
// Doc: sub_1214F00 [unknown]: Unidentified function at 0x1214F00
// sub_1214F00 [unknown]: Unidentified function at 0x1214F00
int __fastcall sub_114F00(_DWORD *a1, unsigned int *a2)
{
  unsigned int v4; // r4
  unsigned int v5; // r0
  unsigned int v6; // r4
  int v7; // r4
  unsigned __int16 v8; // r0
  unsigned int v9; // r3
  int result; // r0

  v4 = MEMORY[0x1FC](8);
  v5 = MEMORY[0x1FC](9);
  v6 = HIWORD(v4) << 16;
  if ( v6 | v5 )
  {
    *a1 = (v5 << 16) | HIWORD(v6);
    *a2 = HIWORD(v5);
    return 0;
  }
  else
  {
    v7 = MEMORY[0x1FC](7);
    v8 = MEMORY[0x1FC](8);
    v9 = v8;
    if ( v7 )
    {
      *a1 = v7;
      *a2 = v8;
      return 1;
    }
    else
    {
      *a1 = 0;
      if ( v8 )
        result = 1;
      else
        result = 2;
      *a2 = v9;
    }
  }
  return result;
}

