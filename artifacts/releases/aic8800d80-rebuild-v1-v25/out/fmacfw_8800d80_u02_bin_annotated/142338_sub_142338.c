// fwstruct annotate: 142338_sub_142338.c
// sub_142338 @ 0x142338, size 162 bytes
int __fastcall sub_142338(int result, __int16 a2, _WORD *a3)
{
  _BYTE *v3; // r6
  __int16 v4; // r2
  int v5; // r3
  int v6; // r4
  int v7; // r1
  int v8; // r5
  _DWORD *v9; // r5
  _DWORD *v10; // r4
  __int16 *v11; // t1
  __int16 v12; // r3
  int v13; // r3
  _DWORD _0[12]; // [sp+0h] [bp-20h] BYREF

  v3 = off_1423DC;
  if ( (*a3 & 0x300) == 0x300 )
    v4 = a3[15];
  else
    v4 = a3[12];
  if ( *((_BYTE *)off_1423DC + 1) )
  {
    if ( (a2 & 0x88) == 0x88 )
    {
      if ( (v4 & 0x10) == 0 )
        return result;
    }
    else if ( (a2 & 0x2000) == 0 )
    {
      return result;
    }
    v5 = dword_1423E0;
    v6 = *(unsigned __int8 *)(result + 116);
    result = *(unsigned __int8 *)(result + 107);
    v7 = dword_1423E0 + 576;
    v8 = 0;
    do
    {
      while ( (*(_WORD *)v5 & 1) == 0 || *(unsigned __int8 *)(v5 + 47) != result || *(unsigned __int8 *)(v5 + 46) != v6 )
      {
        v5 += 72;
        if ( v5 == v7 )
          goto LABEL_13;
      }
      _0[v8] = v5;
      v5 += 72;
      v8 = (unsigned __int8)(v8 + 1);
    }
    while ( v5 != v7 );
LABEL_13:
    if ( v8 )
    {
      v9 = &_0[(unsigned __int8)(v8 - 1)];
      v10 = &_0[-1];
      do
      {
        v11 = (__int16 *)v10[1];
        ++v10;
        result = (int)v11;
        v12 = *v11;
        if ( (*v11 & 8) != 0 )
        {
          v13 = v12 & 9;
          if ( v3[1] )
          {
            if ( v13 == 9 )
              result = (int)fmac_init_handler_1e48(result);
          }
        }
      }
      while ( v10 != v9 );
    }
  }
  return result;
}

