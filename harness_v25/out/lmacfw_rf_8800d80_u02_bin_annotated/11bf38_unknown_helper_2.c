// fwstruct annotate: 11bf38_unknown_helper_2.c
// unknown_helper_2 @ 0x11bf38, size 216 bytes
// Doc: unknown_helper_2 [unknown]: unknown helper, low-confidence guess
// unknown_helper_2 [unknown]: unknown helper, low-confidence guess
BOOL __fastcall unknown_helper_2(int a1, int a2)
{
  _BYTE *v2; // r10
  int *v3; // r4
  int v5; // r3
  int v6; // r7
  int v7; // r9
  int v9; // r11
  int v10; // r1

  v2 = off_11C014;
  v3 = *((int **)off_11C014 + 4);
  if ( !v3 )
  {
    v6 = *(_DWORD *)(a1 + 72);
    v7 = *((_DWORD *)off_11C014 + 10);
    goto LABEL_11;
  }
  v5 = v3[1];
  v6 = *(_DWORD *)(a1 + 72);
  v7 = *((_DWORD *)off_11C014 + 10);
  if ( v5 != a2 )
  {
    v9 = dword_11C018;
    while ( v5 - a2 < 0 )
    {
      v10 = *((unsigned __int8 *)v3 + 8);
      if ( v10 == *(unsigned __int8 *)(a1 + 95) )
      {
        msg_parse(v9, v10);
        list_remove_node(v2 + 16, v3);
        *((_BYTE *)v3 + 9) &= ~1u;
        v3 = (int *)*v3;
        if ( !v3 )
          break;
      }
      else
      {
        v3 = (int *)*v3;
        if ( !v3 )
          break;
      }
      v5 = v3[1];
      if ( v5 == a2 )
        goto LABEL_8;
    }
LABEL_11:
    if ( (unsigned __int8)v2[90] > 1u )
    {
      *(_BYTE *)(a1 + 85) |= 4u;
      return v6 != v7;
    }
    goto LABEL_14;
  }
LABEL_8:
  if ( (unsigned __int8)v2[90] > 1u )
  {
    list_remove_node(dword_11C010, a1 + 76);
    *(_BYTE *)(a1 + 85) = *(_BYTE *)(a1 + 85) & 0xFC | 2;
    ++v2[91];
    return v6 != v7;
  }
LABEL_14:
  *(_BYTE *)(a1 + 85) |= 2u;
  ++v2[91];
  return v6 != v7;
}

