// fwstruct annotate: 125780_sub_125780.c
// sub_125780 @ 0x125780, size 258 bytes
void sub_125780()
{
  int v0; // r4
  _BYTE *v1; // r6
  int v2; // r5
  _DWORD *v3; // r2
  int v4; // r7
  _BYTE *v5; // r8
  char v6; // r9
  int v7; // r10
  int v8; // r0
  int v9; // r3

  v0 = *((_DWORD *)off_125888 + 2);
  v1 = off_12588C;
  if ( **(__int16 **)off_125884 < 0 && *((_DWORD *)off_12588C + 1) )
  {
    sub_12F32C(dword_125898, dword_125894, 1074);
    v2 = (unsigned __int8)v1[9];
    if ( v1[9] )
      goto LABEL_20;
  }
  else
  {
    v2 = *((unsigned __int8 *)off_12588C + 9);
    if ( *((_BYTE *)off_12588C + 9) )
    {
LABEL_20:
      v1[8] = 1;
      return;
    }
  }
  v3 = off_125890;
  v1[8] = v2;
  v4 = 32 * *v3;
  if ( v0 )
  {
    v5 = off_12589C;
    v6 = v2;
    v7 = 1;
    while ( 1 )
    {
      if ( *(_BYTE *)(v0 + 106) != 2
        || !*(_BYTE *)(v0 + 226)
        || !*(_BYTE *)(v0 + 108)
        || *(unsigned __int8 *)(v0 + 225) != *(unsigned __int8 *)(v0 + 224) )
      {
        goto LABEL_6;
      }
      if ( sub_1254A8(v0) )
        ++*v5;
      if ( v7 && (unsigned int)(v4 - 50) > 0xBB6 )
      {
        sub_128350(v0);
LABEL_16:
        *v5 = v6;
        v0 = *(_DWORD *)v0;
        v7 = 0;
        v2 = 1;
        if ( !v0 )
          return;
      }
      else
      {
        if ( v2 )
          goto LABEL_16;
        v7 = sub_128350(v0);
        if ( v7 )
        {
          *(_BYTE *)(v0 + 144) = *(_BYTE *)(v0 + 107);
          *(_BYTE *)(v0 + 145) = -1;
          v8 = sub_118B34(v0 + 116, 4);
          v9 = *((_DWORD *)v1 + 1);
          if ( v8 )
            *((_DWORD *)v1 + 1) = ++v9;
          if ( v9 == 1 )
            sub_121AC8();
          v7 = 0;
        }
        else
        {
          *v5 = 0;
        }
LABEL_6:
        v0 = *(_DWORD *)v0;
        if ( !v0 )
          return;
      }
    }
  }
}

