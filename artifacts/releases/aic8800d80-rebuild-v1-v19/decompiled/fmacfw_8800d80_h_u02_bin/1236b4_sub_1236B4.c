// sub_1236B4 @ 0x1236b4, size 184 bytes
int __fastcall sub_1236B4(int a1, unsigned __int8 *a2, int a3, int a4)
{
  _BYTE *v5; // r0
  __int16 **v6; // r6
  _BYTE *v7; // r5
  int v8; // r3

  v5 = (_BYTE *)sub_12C7EC(37, a4, a3, 2);
  v6 = (__int16 **)off_12376C;
  *v5 = 1;
  v7 = v5;
  if ( **v6 < 0 )
  {
    if ( *a2 <= 5u || (sub_12F32C(dword_12377C, dword_123774, 1725), **v6 < 0) )
    {
      if ( a2[4] > 0x20u )
        sub_12F32C(dword_123778, dword_123774, 1726);
    }
  }
  switch ( a2[40] )
  {
    case 0u:
    case 1u:
    case 3u:
      v8 = (*(_DWORD *)off_123770 >> 6) & 1;
      goto LABEL_4;
    case 2u:
    case 5u:
    case 8u:
      v8 = (*(_DWORD *)off_123770 >> 7) & 1;
      goto LABEL_4;
    case 4u:
      v8 = (*(_DWORD *)off_123770 >> 13) & 1;
      goto LABEL_4;
    case 6u:
    case 7u:
      v8 = (*(_DWORD *)off_123770 >> 9) & 1;
LABEL_4:
      if ( v8 && a2[4] <= 0x20u && *a2 <= 5u )
      {
        v7[1] = sub_1212D8(a2);
        *v7 = 0;
      }
      break;
    default:
      break;
  }
  sub_12C84C(v7);
  return 0;
}

