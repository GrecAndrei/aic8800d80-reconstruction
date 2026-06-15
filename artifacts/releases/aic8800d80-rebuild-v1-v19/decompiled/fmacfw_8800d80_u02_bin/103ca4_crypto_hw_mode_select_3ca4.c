// crypto_hw_mode_select_3ca4 @ 0x103ca4, size 496 bytes
// Doc: crypto_hw_mode_select_3ca4 [mac]: Selects crypto hardware mode by writing config word to register
// crypto_hw_mode_select_3ca4 [mac]: Selects crypto hardware mode by writing config word to register
int __fastcall crypto_hw_mode_select_3ca4(int a1)
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

  *(_DWORD *)off_103E94 = dword_103E98;
  if ( a1 )
  {
    switch ( a1 )
    {
      case 1:
        v15 = (unsigned int *)off_103E9C;
        v16 = (int *)off_103EA0;
        v17 = dword_103EC8;
        v18 = *(_DWORD *)off_103E9C;
        v19 = dword_103ECC;
        v20 = *(_DWORD *)off_103E9C & 0x70 | 1;
        break;
      case 10:
        v1 = (unsigned int *)off_103E9C;
        v2 = (int *)off_103EA0;
        v3 = *(_DWORD *)off_103E9C;
        v4 = dword_103EC0;
        v5 = *(_DWORD *)off_103E9C;
        v6 = dword_103EC4;
        goto LABEL_24;
      case 14:
        v1 = (unsigned int *)off_103E9C;
        v2 = (int *)off_103EA0;
        v3 = *(_DWORD *)off_103E9C;
        v4 = dword_103ED0;
        v5 = *(_DWORD *)off_103E9C;
        v6 = dword_103ED4;
        goto LABEL_24;
      case 2:
        v15 = (unsigned int *)off_103E9C;
        v16 = (int *)off_103EA0;
        v17 = dword_103ED8;
        v18 = *(_DWORD *)off_103E9C;
        v19 = dword_103EDC;
        v20 = *(_DWORD *)off_103E9C & 0x70 | 2;
        break;
      default:
        switch ( a1 )
        {
          case 3:
            v1 = (unsigned int *)off_103E9C;
            v2 = (int *)off_103EA0;
            v3 = *(_DWORD *)off_103E9C;
            v4 = dword_103EE0;
            v5 = *(_DWORD *)off_103E9C;
            v6 = dword_103EE4;
            break;
          case 30:
            v1 = (unsigned int *)off_103E9C;
            v2 = (int *)off_103EA0;
            v3 = *(_DWORD *)off_103E9C;
            v4 = dword_103EE8;
            v5 = *(_DWORD *)off_103E9C;
            v6 = dword_103EEC;
            break;
          case 31:
            v1 = (unsigned int *)off_103E9C;
            v2 = (int *)off_103EA0;
            v3 = *(_DWORD *)off_103E9C;
            v4 = dword_103EF8;
            v5 = *(_DWORD *)off_103E9C;
            v6 = dword_103EFC;
            break;
          case 32:
            v1 = (unsigned int *)off_103E9C;
            v2 = (int *)off_103EA0;
            v3 = *(_DWORD *)off_103E9C;
            v4 = dword_103F00;
            v5 = *(_DWORD *)off_103E9C;
            v6 = dword_103F04;
            break;
          case 33:
            v1 = (unsigned int *)off_103E9C;
            v2 = (int *)off_103EA0;
            v3 = *(_DWORD *)off_103E9C;
            v4 = dword_103F08;
            v5 = *(_DWORD *)off_103E9C;
            v6 = dword_103F0C;
            break;
          default:
            if ( a1 != 4 )
            {
              if ( a1 == 5 )
              {
                v1 = (unsigned int *)off_103E9C;
                v2 = (int *)off_103EA0;
                v3 = *(_DWORD *)off_103E9C;
                v4 = dword_103F10;
                v5 = *(_DWORD *)off_103E9C;
                v6 = dword_103F14;
                break;
              }
              if ( a1 != 50 )
              {
                switch ( a1 )
                {
                  case 6:
                    v1 = (unsigned int *)off_103E9C;
                    v2 = (int *)off_103EA0;
                    v3 = *(_DWORD *)off_103E9C;
                    v4 = dword_103F18;
                    v5 = *(_DWORD *)off_103E9C;
                    v6 = dword_103F1C;
                    break;
                  case 7:
                    v22 = off_103E9C;
                    v23 = (unsigned int *)off_103EB0;
                    v24 = (int *)off_103EA0;
                    v25 = dword_103EB4;
                    v26 = dword_103F20;
                    v27 = *(_DWORD *)off_103E9C & 0x70;
                    *(_DWORD *)off_103E9C &= 0xFFFFFF70;
                    *v23 = *v23 & 0xFF00FFFF | 0x540000;
                    *v24 = v25;
                    msg_parse(v26, v27, v22);
                    goto LABEL_22;
                  case 8:
                    v1 = (unsigned int *)off_103E9C;
                    v2 = (int *)off_103EA0;
                    v4 = dword_103EB4;
                    v6 = dword_103F24;
                    *(_DWORD *)off_103EB0 = *(_DWORD *)off_103EB0 & 0xFF00FFFF | 0x570000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  case 81:
                    v1 = (unsigned int *)off_103E9C;
                    v2 = (int *)off_103EA0;
                    v4 = dword_103EB4;
                    v6 = dword_103F28;
                    *(_DWORD *)off_103EB0 = *(_DWORD *)off_103EB0 & 0xFF00FFFF | 0x30000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  default:
                    v1 = (unsigned int *)off_103E9C;
                    v2 = (int *)off_103EA0;
                    v3 = *(_DWORD *)off_103E9C;
                    v4 = dword_103EA4;
                    v5 = *(_DWORD *)off_103E9C;
                    if ( a1 == 9 )
                      v6 = dword_103EA8;
                    else
                      v6 = dword_103EAC;
                    break;
                }
                break;
              }
            }
            v1 = (unsigned int *)off_103E9C;
            v2 = (int *)off_103EA0;
            v3 = *(_DWORD *)off_103E9C;
            v4 = dword_103EF0;
            v5 = *(_DWORD *)off_103E9C;
            v6 = dword_103EF4;
            break;
        }
LABEL_24:
        v14 = v3 & 0x70;
        *v1 = v5 & 0xFFFFFF00 | v14;
        *v2 = v4;
        msg_parse(v6, v14, v1);
        goto LABEL_22;
    }
    v21 = v18 & 0xFFFFFF00;
    *v15 = v20 | v21;
    *v16 = v17;
    msg_parse(v19, v21, v15);
    goto LABEL_22;
  }
  v7 = off_103E9C;
  v8 = (unsigned int *)off_103EB0;
  v9 = (int *)off_103EA0;
  v10 = dword_103EB4;
  v11 = dword_103EB8;
  v12 = *(_DWORD *)off_103E9C & 0x70;
  *(_DWORD *)off_103E9C &= 0xFFFFFF70;
  *v8 = *v8 & 0xFF00FFFF | 0x770000;
  *v9 = v10;
  msg_parse(v11, v12, v7);
LABEL_22:
  *(_DWORD *)off_103EBC = 769;
  return delay_us_0644(500);
}

