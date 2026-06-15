// sub_13A980 @ 0x13a980, size 346 bytes
// Doc: sub_123A980 [unknown]: Init/setup routine reading from data table at 0x188428
// sub_123A980 [unknown]: Init/setup routine reading from data table at 0x188428
_WORD *__fastcall sub_13A980(int a1, _WORD *a2, int a3)
{
  int v4; // r5
  int v5; // r3
  _WORD *v6; // r9
  _BYTE *v7; // r8
  int v9; // r4
  int v10; // r5
  int v11; // r3
  __int16 v12; // r3
  int v13; // r2

  v4 = *(unsigned __int8 *)(a1 + 29);
  v5 = dword_13AADC + 696 * v4;
  v6 = a2;
  v7 = **(_BYTE ***)(v5 + 188);
  if ( v7 )
  {
    v9 = dword_13AAE0 + 1320 * *(unsigned __int8 *)(a1 + 28);
    if ( *(_DWORD *)(v9 + 1200) )
    {
      if ( (*(_DWORD *)(v9 + 1208) & 2) == 0
        || *(unsigned __int16 *)(v5 + 56) != (unsigned __int16)__rev16(*(unsigned __int16 *)(a1 + 24)) )
      {
        v10 = dword_13AADC + 696 * v4;
        v11 = *(_DWORD *)(v10 + 184);
        if ( !v11 || (unsigned int)*(unsigned __int8 *)(v11 + 96) - 1 > 1 || *(unsigned __int8 *)(v10 + 669) > 1u )
        {
          switch ( v7[96] )
          {
            case 0:
            case 3:
              *(a2 - 2) = *(_WORD *)(a1 + 56);
              v6 = a2 - 2;
              *(a2 - 1) = *(_WORD *)(a1 + 58) | ((unsigned __int8)v7[97] << 14);
              if ( a3 )
                goto LABEL_11;
              goto LABEL_17;
            case 1:
              *(a2 - 4) = *(_WORD *)(a1 + 56) & 0x5F00 | 0x2000 | HIBYTE(*(_WORD *)(a1 + 56));
              v6 = a2 - 4;
              v12 = *(unsigned __int8 *)(a1 + 56) | (unsigned __int16)((unsigned __int8)v7[97] << 14);
              goto LABEL_9;
            case 2:
            case 6:
            case 7:
            case 8:
              *(a2 - 4) = *(_WORD *)(a1 + 56);
              v6 = a2 - 4;
              v12 = (unsigned __int8)v7[97] << 14;
LABEL_9:
              v6[1] = v12 | 0x2000;
              v6[2] = *(_WORD *)(a1 + 58);
              v6[3] = *(_WORD *)(a1 + 60);
              break;
            case 4:
              *(a2 - 9) = (unsigned __int8)v7[97];
              v6 = a2 - 9;
              v6[1] = *(_WORD *)(a1 + 56);
              v6[2] = *(_WORD *)(a1 + 58);
              v6[3] = *(_WORD *)(a1 + 60);
              v6[4] = *(_WORD *)(a1 + 62);
              v6[5] = 23606;
              v6[6] = 23606;
              v6[7] = 23606;
              v6[8] = 23606;
              break;
            default:
              if ( **(__int16 **)off_13AAE8 < 0 )
                sub_12F46C(dword_13AAF0, dword_13AAEC, 743);
              break;
          }
          if ( a3 )
LABEL_11:
            v13 = *(_DWORD *)(a1 + 44);
          else
LABEL_17:
            v13 = *(_DWORD *)(a1 + 72) + 44;
          *(_DWORD *)(v13 + 12) = dword_13AAE4 & *(_DWORD *)(v13 + 12) | (unsigned __int8)v7[98];
        }
      }
    }
  }
  return v6;
}

