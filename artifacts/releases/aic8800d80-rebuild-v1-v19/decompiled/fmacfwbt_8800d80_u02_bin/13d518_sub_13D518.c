// sub_13D518 @ 0x13d518, size 206 bytes
int __fastcall sub_13D518(int a1)
{
  char v1; // r5
  unsigned int v2; // r3
  int result; // r0
  int v5; // r3
  unsigned int v6; // r2
  unsigned int v7; // r3
  int v8; // r2

  v1 = *(_BYTE *)(a1 + 166);
  v2 = *(unsigned __int8 *)(a1 + 177);
  *(_BYTE *)(a1 + 166) = v1 & 0xFB;
  if ( v2 > 0xB )
    goto LABEL_11;
  result = ((int)*(unsigned __int16 *)(a1 + 12 * *(unsigned __int16 *)(a1 + 136) + 10) >> 11) & 6;
  if ( !result )
    return result;
  result = ((int)*(unsigned __int16 *)(a1 + 12 * *(unsigned __int16 *)(a1 + 138) + 10) >> 11) & 6;
  if ( !result )
    return result;
  result = ((int)*(unsigned __int16 *)(a1 + 12 * *(unsigned __int16 *)(a1 + 140) + 10) >> 11) & 6;
  if ( !result )
    return result;
  result = v1 & 0x20;
  if ( (v1 & 0x20) != 0 )
  {
LABEL_11:
    *(_BYTE *)(a1 + 166) = v1 & 0xFB | 4;
    return 1;
  }
  v5 = a1 + 12 * *(unsigned __int16 *)(a1 + 2 * (*(unsigned __int8 *)(a1 + 168) + 68));
  v6 = *(unsigned __int16 *)(v5 + 10);
  if ( (v6 & 0x2000) != 0 )
  {
    if ( (v6 & 0xF) > 2 )
      goto LABEL_9;
    v8 = (v6 >> 4) & 7;
  }
  else
  {
    if ( ((v6 >> 11) & 6) == 0 )
    {
      if ( (v6 & 0x7F) > 2 )
      {
LABEL_9:
        v7 = *(unsigned __int16 *)(v5 + 8);
        goto LABEL_10;
      }
      goto LABEL_16;
    }
    if ( (v6 & 7) > 2 )
      goto LABEL_9;
    v8 = (v6 >> 3) & 3;
  }
  if ( v8 )
    goto LABEL_9;
LABEL_16:
  v7 = *(unsigned __int16 *)(v5 + 8);
  if ( v7 > 0x1998 )
  {
LABEL_10:
    if ( v7 <= 0x28E )
      return result;
    goto LABEL_11;
  }
  return result;
}

