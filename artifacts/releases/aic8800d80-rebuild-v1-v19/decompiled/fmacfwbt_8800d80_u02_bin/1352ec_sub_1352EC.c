// sub_1352EC @ 0x1352ec, size 142 bytes
int __fastcall sub_1352EC(int a1, int a2)
{
  int v2; // r5
  _BYTE *v3; // r7
  int result; // r0
  __int16 v7; // r5

  v2 = *(_DWORD *)(a1 + 72);
  v3 = off_13537C;
  feature_guard_sdio(
    256,
    dword_135380,
    *((unsigned __int8 *)off_13537C + 34),
    a2,
    (unsigned __int8)*(_WORD *)(v2 + 108));
  if ( !v3[34] )
    return sub_135020(1);
  v7 = *(_WORD *)(v2 + 108);
  if ( msg_get_value(6u) != 5 )
  {
    result = msg_get_value(6u);
    if ( result != 8 )
    {
LABEL_5:
      v3[34] = 0;
      return result;
    }
  }
  result = msg_get_value(6u);
  if ( result == 5 && (v7 & 0xFC) == 0xB0 || (result = msg_get_value(6u), result == 8) && (v7 & 0xDC) == 0 )
  {
    if ( (a2 & 0x800000) == 0 )
    {
      result = sub_1190B4(a1, 5);
      *(_BYTE *)(a1 + 98) = 1;
      return result;
    }
    goto LABEL_5;
  }
  return result;
}

