// bt_state_check_4c8 @ 0x12a568, size 164 bytes
// Doc: bt_state_check_4c8 [bt]: Check state field at offset 0x4c8 and branch on zero
// bt_state_check_4c8 [bt]: Check state field at offset 0x4c8 and branch on zero
unsigned int __fastcall bt_state_check_4c8(_BYTE *a1, int a2, int a3)
{
  unsigned int v3; // r4
  unsigned int v5; // r0
  int v8; // r7
  unsigned __int8 *v9; // r3
  unsigned int v10; // r7
  int v11; // r5
  int v12; // r2
  unsigned __int8 *v13; // r4
  unsigned int v14; // r5

  v3 = (unsigned __int8)a1[1224];
  if ( !a1[1224] )
    return v3;
  if ( !a1[106] )
  {
    v5 = (unsigned __int8)a1[1225];
    if ( **(__int16 **)off_12A60C < 0 && v5 > 1 )
    {
      sub_12F694(dword_12A610, dword_12A614, 1420);
      v5 = (unsigned __int8)a1[1225];
    }
    v8 = *(_DWORD *)(a2 + 8);
    v9 = (unsigned __int8 *)(v8 + 36);
    v10 = v8 + *(unsigned __int16 *)(a3 + 28);
    if ( (unsigned int)v9 < v10 )
    {
      while ( 1 )
      {
        v11 = v9[1];
        v12 = *v9;
        v13 = v9;
        v9 += v11 + 2;
        if ( v12 == 221 && v13[5] == 9 )
        {
          v3 = (unsigned int)(v13 + 6);
          v14 = v3 + (unsigned __int16)(v11 - 4);
          if ( v3 < v14 )
          {
            while ( *(_BYTE *)v3 != 12 )
            {
              v3 += *(unsigned __int16 *)(v3 + 1) + 3;
              if ( v14 <= v3 )
                goto LABEL_6;
            }
            if ( v3 )
              break;
          }
        }
LABEL_6:
        if ( v10 <= (unsigned int)v9 )
          goto LABEL_19;
      }
    }
    else
    {
LABEL_19:
      v3 = 0;
    }
    sub_129FAC(v5, v3, *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 8) + 8) + 24));
    return v3;
  }
  return 0;
}

