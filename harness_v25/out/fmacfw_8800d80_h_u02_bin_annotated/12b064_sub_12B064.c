// fwstruct annotate: 12b064_sub_12B064.c
// sub_12B064 @ 0x12b064, size 192 bytes
int sub_12B064()
{
  _DWORD *v0; // r6
  int v1; // r7
  int v2; // r5
  int v3; // r4
  char v4; // r8
  int v5; // r1
  int v6; // r3
  int v7; // r2
  int v8; // r1
  int v10; // r1

  v0 = off_12B124;
  v1 = *(_DWORD *)off_12B124;
  v2 = *(_DWORD *)off_12B124 + 6 * *((unsigned __int8 *)off_12B124 + 10);
  v3 = 6 * *((unsigned __int8 *)off_12B124 + 10);
  v4 = *(_BYTE *)(v2 + 3);
  if ( (v4 & 5) != 0 )
  {
    v5 = *(_DWORD *)(*(_DWORD *)off_12B128 + 20);
    if ( !v5 )
    {
      v5 = dword_12B12C;
      goto LABEL_4;
    }
  }
  else
  {
    v5 = sub_12AFD4((unsigned __int16 *)(*(_DWORD *)off_12B124 + 6 * *((unsigned __int8 *)off_12B124 + 10)));
    if ( !v5 )
    {
      v5 = 30000;
      goto LABEL_4;
    }
  }
  if ( (v4 & 1) == 0 && *((_BYTE *)off_12B134 + 3850) == 1 )
    v5 += 170000;
LABEL_4:
  sub_127990((__int16 *)v2, v5, *(_BYTE *)(v1 + 366));
  v6 = v0[1];
  if ( v6 )
  {
    v7 = *(unsigned __int8 *)(v2 + 2);
    v8 = *(unsigned __int16 *)(v1 + v3);
    if ( *(_BYTE *)(v2 + 2) )
    {
      if ( v7 == 1 && (v10 = v8 - 4992, (unsigned __int16)(v10 - 13) <= 0x370u) )
        *(_BYTE *)(v6 + 2) = (unsigned int)(((unsigned int)dword_12B130 * (unsigned __int64)(unsigned int)(v10 - 8)) >> 32) >> 2;
      else
        *(_BYTE *)(v6 + 2) = 0;
    }
    else
    {
      if ( (unsigned int)(v8 - 2412) <= 0x48 )
      {
        if ( v8 == 2484 )
        {
          *(_BYTE *)(v6 + 2) = 14;
          return sub_12CBF4(2);
        }
        LOBYTE(v7) = (unsigned int)(((unsigned int)dword_12B130 * (unsigned __int64)(unsigned int)(v8 - 2407)) >> 32) >> 2;
      }
      *(_BYTE *)(v6 + 2) = v7;
    }
  }
  return sub_12CBF4(2);
}

