// fwstruct annotate: 127fdc_sub_127FDC.c
// sub_127FDC @ 0x127fdc, size 354 bytes
int __fastcall sub_127FDC(int result)
{
  _DWORD *v1; // r5
  int v2; // r2
  int v3; // r4
  int v4; // r3
  int v5; // r1
  int v6; // r6
  int v7; // r3
  int v8; // r2
  int v9; // r7
  int v10; // r8
  int v11; // r7
  int v12; // r4
  int v13; // r3
  int *v14; // r4
  int v15; // r1
  int v16; // r3
  int v17; // r2
  int v18; // r0
  int *v19; // r2
  int v20; // r2

  v1 = off_128140;
  if ( *((unsigned __int8 *)off_128140 + 90) > 1u )
  {
    v2 = *(unsigned __int8 *)(result + 85);
    v3 = result;
    if ( (v2 & 0x10) != 0 )
    {
      v4 = dword_128144;
      while ( 1 )
      {
        if ( *(unsigned __int8 *)(v4 + 24) != 255 )
        {
          v5 = *(unsigned __int8 *)(v4 + 27);
          if ( v5 != 255 )
            break;
        }
        v4 += 28;
        if ( dword_128144 + 84 == v4 )
          goto LABEL_7;
      }
      sub_125D38((_DWORD *)(dword_128158 + 1320 * v5));
      LOBYTE(v2) = *(_BYTE *)(v3 + 85);
LABEL_7:
      v2 &= 0xEFu;
      *(_BYTE *)(v3 + 85) = v2;
    }
    result = v2 << 30;
    if ( (v2 & 2) == 0 )
    {
      v6 = v1[9];
      if ( (v2 & 4) != 0 )
        *(_BYTE *)(v3 + 85) = v2 & 0xFB;
      if ( !v6 || *(_DWORD *)(v6 + 12) != v3 + 76 )
        return sub_126444(v3, *(_DWORD *)(v3 + 36), 0);
      v9 = *(_DWORD *)(v3 + 80);
      v10 = *(_DWORD *)(v3 + 36);
      if ( v9 - v10 < 0 )
      {
        if ( v10 - 4000 - v9 - sub_101944() < 0 )
        {
LABEL_23:
          v11 = *(_DWORD *)(v3 + 36);
          *(_DWORD *)(v3 + 80) = v11;
          result = sub_101944();
          if ( v11 - *(_DWORD *)(v6 + 4) - result - 4000 < 0 )
          {
            v12 = *(_DWORD *)(v3 + 80);
            result = sub_101944();
            v13 = v1[18];
            *(_DWORD *)(v6 + 4) = v12 - 4000 - result;
            if ( v13 == v6 )
            {
              sub_124CF4(dword_128148);
              v1[18] = v6;
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(_DWORD *)off_12814C = 1;
              }
              v14 = (int *)off_128154;
              v15 = *(_DWORD *)(v6 + 4);
              v16 = *(_DWORD *)off_128154;
              v17 = v15 - *((_DWORD *)off_128150 + 4);
              v18 = *(_DWORD *)off_128154 + 1;
              *(_DWORD *)off_128154 = v18;
              if ( v17 - 64 >= 0 )
              {
                result = sub_124BFC(dword_128148, v15);
                if ( *v14 )
                {
                  v7 = *v14 - 1;
                  v8 = *(_DWORD *)off_12814C;
                  *v14 = v7;
                  if ( !v7 )
                  {
                    if ( v8 )
                      __enable_irq();
                  }
                }
              }
              else
              {
                if ( v18 )
                {
                  v19 = (int *)off_12814C;
                  *v14 = v16;
                  v20 = *v19;
                  if ( !v16 )
                  {
                    if ( v20 )
                      __enable_irq();
                  }
                }
                return ((int (__fastcall *)(int))v1[17])(v6);
              }
            }
          }
          return result;
        }
        v10 = *(_DWORD *)(v3 + 36);
        v9 = *(_DWORD *)(v3 + 80);
      }
      if ( v10 - v9 >= 0 || v9 - 4000 - v10 - sub_101944() >= 0 )
      {
        sub_1266A0();
        sub_126444(v3, *(_DWORD *)(v3 + 36), 0);
        return sub_1266E4(v3, *((_DWORD *)off_128150 + 4), 0);
      }
      goto LABEL_23;
    }
  }
  return result;
}

