// fwstruct annotate: 11f308_sub_11F308.c
// sub_11F308 @ 0x11f308, size 172 bytes
int __fastcall sub_11F308(int a1, int a2, int a3)
{
  int v3; // r5
  int v7; // r10
  int v8; // r11
  int v9; // r3
  int v10; // r8
  int v11; // r0
  int v12; // r2
  int v13; // r3
  int v15; // [sp+4h] [bp-8h]

  v3 = 0;
  v7 = a2 + 624;
  v8 = a2 + 584;
  v15 = 0;
  while ( sub_116DBC(a1) )
  {
    v9 = 0;
    while ( 1 )
    {
      v10 = (unsigned __int8)v9;
      if ( *(_DWORD *)(v7 + 8 * v9) )
      {
        v11 = sub_12D190(a2 + 8 * (v9 + 78));
        goto LABEL_9;
      }
      if ( *(_DWORD *)(v8 + 8 * v9) )
        break;
      if ( ++v9 == 4 )
        return v3;
    }
    v11 = sub_12D190(a2 + 8 * (v9 + 73));
LABEL_9:
    if ( !v11 )
      break;
    v12 = a2;
    while ( !*(_DWORD *)(v12 + 624) )
    {
      v13 = *(_DWORD *)(v12 + 584);
      v12 += 8;
      if ( v13 )
        break;
      if ( a2 + 32 == v12 )
      {
        if ( !v15 )
          goto LABEL_15;
        break;
      }
    }
    v12 = *(_DWORD *)(v11 + 72);
    *(_WORD *)(v12 + 108) |= 0x2000u;
    v15 = 1;
LABEL_15:
    sub_13AA68(v11, v10, v12);
    ++v3;
    sub_11A6A8(v10);
    if ( a3 )
    {
      if ( v3 == a3 )
        break;
    }
  }
  return v3;
}

