// sub_103AFC @ 0x103afc, size 496 bytes
int __fastcall sub_103AFC(int a1)
{
  unsigned int *v1; // r2
  int *v2; // r4
  unsigned int v3; // r1
  int v4; // r5
  unsigned int v5; // r3
  int v6; // r0
  void *v7; // r2
  unsigned int *v8; // r4
  int *v9; // r5
  int v10; // r6
  int v11; // r0
  int v12; // r1
  int v14; // r1
  unsigned int *v15; // r2
  int *v16; // r4
  int v17; // r5
  int v18; // r1
  int v19; // r0
  int v20; // r3
  unsigned int v21; // r1
  void *v22; // r2
  unsigned int *v23; // r4
  int *v24; // r5
  int v25; // r6
  int v26; // r0
  int v27; // r1

  *(_DWORD *)off_103CEC = dword_103CF0;
  if ( a1 )
  {
    switch ( a1 )
    {
      case 1:
        v15 = (unsigned int *)off_103CF4;
        v16 = (int *)off_103CF8;
        v17 = dword_103D20;
        v18 = *(_DWORD *)off_103CF4;
        v19 = dword_103D24;
        v20 = *(_DWORD *)off_103CF4 & 0x70 | 1;
        break;
      case 10:
        v1 = (unsigned int *)off_103CF4;
        v2 = (int *)off_103CF8;
        v3 = *(_DWORD *)off_103CF4;
        v4 = dword_103D18;
        v5 = *(_DWORD *)off_103CF4;
        v6 = dword_103D1C;
        goto LABEL_24;
      case 14:
        v1 = (unsigned int *)off_103CF4;
        v2 = (int *)off_103CF8;
        v3 = *(_DWORD *)off_103CF4;
        v4 = dword_103D28;
        v5 = *(_DWORD *)off_103CF4;
        v6 = dword_103D2C;
        goto LABEL_24;
      case 2:
        v15 = (unsigned int *)off_103CF4;
        v16 = (int *)off_103CF8;
        v17 = dword_103D30;
        v18 = *(_DWORD *)off_103CF4;
        v19 = dword_103D34;
        v20 = *(_DWORD *)off_103CF4 & 0x70 | 2;
        break;
      default:
        switch ( a1 )
        {
          case 3:
            v1 = (unsigned int *)off_103CF4;
            v2 = (int *)off_103CF8;
            v3 = *(_DWORD *)off_103CF4;
            v4 = dword_103D38;
            v5 = *(_DWORD *)off_103CF4;
            v6 = dword_103D3C;
            break;
          case 30:
            v1 = (unsigned int *)off_103CF4;
            v2 = (int *)off_103CF8;
            v3 = *(_DWORD *)off_103CF4;
            v4 = dword_103D40;
            v5 = *(_DWORD *)off_103CF4;
            v6 = dword_103D44;
            break;
          case 31:
            v1 = (unsigned int *)off_103CF4;
            v2 = (int *)off_103CF8;
            v3 = *(_DWORD *)off_103CF4;
            v4 = dword_103D50;
            v5 = *(_DWORD *)off_103CF4;
            v6 = dword_103D54;
            break;
          case 32:
            v1 = (unsigned int *)off_103CF4;
            v2 = (int *)off_103CF8;
            v3 = *(_DWORD *)off_103CF4;
            v4 = dword_103D58;
            v5 = *(_DWORD *)off_103CF4;
            v6 = dword_103D5C;
            break;
          case 33:
            v1 = (unsigned int *)off_103CF4;
            v2 = (int *)off_103CF8;
            v3 = *(_DWORD *)off_103CF4;
            v4 = dword_103D60;
            v5 = *(_DWORD *)off_103CF4;
            v6 = dword_103D64;
            break;
          default:
            if ( a1 != 4 )
            {
              if ( a1 == 5 )
              {
                v1 = (unsigned int *)off_103CF4;
                v2 = (int *)off_103CF8;
                v3 = *(_DWORD *)off_103CF4;
                v4 = dword_103D68;
                v5 = *(_DWORD *)off_103CF4;
                v6 = dword_103D6C;
                break;
              }
              if ( a1 != 50 )
              {
                switch ( a1 )
                {
                  case 6:
                    v1 = (unsigned int *)off_103CF4;
                    v2 = (int *)off_103CF8;
                    v3 = *(_DWORD *)off_103CF4;
                    v4 = dword_103D70;
                    v5 = *(_DWORD *)off_103CF4;
                    v6 = dword_103D74;
                    break;
                  case 7:
                    v22 = off_103CF4;
                    v23 = (unsigned int *)off_103D08;
                    v24 = (int *)off_103CF8;
                    v25 = dword_103D0C;
                    v26 = dword_103D78;
                    v27 = *(_DWORD *)off_103CF4 & 0x70;
                    *(_DWORD *)off_103CF4 &= 0xFFFFFF70;
                    *v23 = *v23 & 0xFF00FFFF | 0x540000;
                    *v24 = v25;
                    sub_12ECB0(v26, v27, v22);
                    goto LABEL_22;
                  case 8:
                    v1 = (unsigned int *)off_103CF4;
                    v2 = (int *)off_103CF8;
                    v4 = dword_103D0C;
                    v6 = dword_103D7C;
                    *(_DWORD *)off_103D08 = *(_DWORD *)off_103D08 & 0xFF00FFFF | 0x570000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  case 81:
                    v1 = (unsigned int *)off_103CF4;
                    v2 = (int *)off_103CF8;
                    v4 = dword_103D0C;
                    v6 = dword_103D80;
                    *(_DWORD *)off_103D08 = *(_DWORD *)off_103D08 & 0xFF00FFFF | 0x30000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  default:
                    v1 = (unsigned int *)off_103CF4;
                    v2 = (int *)off_103CF8;
                    v3 = *(_DWORD *)off_103CF4;
                    v4 = dword_103CFC;
                    v5 = *(_DWORD *)off_103CF4;
                    if ( a1 == 9 )
                      v6 = dword_103D00;
                    else
                      v6 = dword_103D04;
                    break;
                }
                break;
              }
            }
            v1 = (unsigned int *)off_103CF4;
            v2 = (int *)off_103CF8;
            v3 = *(_DWORD *)off_103CF4;
            v4 = dword_103D48;
            v5 = *(_DWORD *)off_103CF4;
            v6 = dword_103D4C;
            break;
        }
LABEL_24:
        v14 = v3 & 0x70;
        *v1 = v5 & 0xFFFFFF00 | v14;
        *v2 = v4;
        sub_12ECB0(v6, v14, v1);
        goto LABEL_22;
    }
    v21 = v18 & 0xFFFFFF00;
    *v15 = v20 | v21;
    *v16 = v17;
    sub_12ECB0(v19, v21, v15);
    goto LABEL_22;
  }
  v7 = off_103CF4;
  v8 = (unsigned int *)off_103D08;
  v9 = (int *)off_103CF8;
  v10 = dword_103D0C;
  v11 = dword_103D10;
  v12 = *(_DWORD *)off_103CF4 & 0x70;
  *(_DWORD *)off_103CF4 &= 0xFFFFFF70;
  *v8 = *v8 & 0xFF00FFFF | 0x770000;
  *v9 = v10;
  sub_12ECB0(v11, v12, v7);
LABEL_22:
  *(_DWORD *)off_103D14 = 769;
  return sub_100644(500);
}

