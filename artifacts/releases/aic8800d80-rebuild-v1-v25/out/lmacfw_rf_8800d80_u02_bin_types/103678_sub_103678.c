// sub_103678 @ 0x103678, size 496 bytes
int  sub_103678(int a1)
{
  unsigned int *v1; // r2
  int *v2; // r4
  unsigned int v3; // r1
  int v4; // r5
  unsigned int v5; // r3
  int v6; // r0
  unsigned int *v7; // r4
  int *v8; // r5
  int v9; // r6
  int v10; // r0
  int v11; // r1
  int v13; // r1
  unsigned int *v14; // r2
  int *v15; // r4
  int v16; // r5
  int v17; // r1
  int v18; // r0
  int v19; // r3
  unsigned int v20; // r1
  unsigned int *v21; // r4
  int *v22; // r5
  int v23; // r6
  int v24; // r0
  int v25; // r1

  *(uint32_t *)off_103868 = dword_10386C;
  if ( a1 )
  {
    switch ( a1 )
    {
      case 1:
        v14 = (unsigned int *)off_103870;
        v15 = (int *)off_103874;
        v16 = dword_10389C;
        v17 = *(uint32_t *)off_103870;
        v18 = dword_1038A0;
        v19 = *(uint32_t *)off_103870 & 0x70 | 1;
        break;
      case 10:
        v1 = (unsigned int *)off_103870;
        v2 = (int *)off_103874;
        v3 = *(uint32_t *)off_103870;
        v4 = dword_103894;
        v5 = *(uint32_t *)off_103870;
        v6 = dword_103898;
        goto LABEL_24;
      case 14:
        v1 = (unsigned int *)off_103870;
        v2 = (int *)off_103874;
        v3 = *(uint32_t *)off_103870;
        v4 = dword_1038A4;
        v5 = *(uint32_t *)off_103870;
        v6 = dword_1038A8;
        goto LABEL_24;
      case 2:
        v14 = (unsigned int *)off_103870;
        v15 = (int *)off_103874;
        v16 = dword_1038AC;
        v17 = *(uint32_t *)off_103870;
        v18 = dword_1038B0;
        v19 = *(uint32_t *)off_103870 & 0x70 | 2;
        break;
      default:
        switch ( a1 )
        {
          case 3:
            v1 = (unsigned int *)off_103870;
            v2 = (int *)off_103874;
            v3 = *(uint32_t *)off_103870;
            v4 = dword_1038B4;
            v5 = *(uint32_t *)off_103870;
            v6 = dword_1038B8;
            break;
          case 30:
            v1 = (unsigned int *)off_103870;
            v2 = (int *)off_103874;
            v3 = *(uint32_t *)off_103870;
            v4 = dword_1038BC;
            v5 = *(uint32_t *)off_103870;
            v6 = dword_1038C0;
            break;
          case 31:
            v1 = (unsigned int *)off_103870;
            v2 = (int *)off_103874;
            v3 = *(uint32_t *)off_103870;
            v4 = dword_1038CC;
            v5 = *(uint32_t *)off_103870;
            v6 = dword_1038D0;
            break;
          case 32:
            v1 = (unsigned int *)off_103870;
            v2 = (int *)off_103874;
            v3 = *(uint32_t *)off_103870;
            v4 = dword_1038D4;
            v5 = *(uint32_t *)off_103870;
            v6 = dword_1038D8;
            break;
          case 33:
            v1 = (unsigned int *)off_103870;
            v2 = (int *)off_103874;
            v3 = *(uint32_t *)off_103870;
            v4 = dword_1038DC;
            v5 = *(uint32_t *)off_103870;
            v6 = dword_1038E0;
            break;
          default:
            if ( a1 != 4 )
            {
              if ( a1 == 5 )
              {
                v1 = (unsigned int *)off_103870;
                v2 = (int *)off_103874;
                v3 = *(uint32_t *)off_103870;
                v4 = dword_1038E4;
                v5 = *(uint32_t *)off_103870;
                v6 = dword_1038E8;
                break;
              }
              if ( a1 != 50 )
              {
                switch ( a1 )
                {
                  case 6:
                    v1 = (unsigned int *)off_103870;
                    v2 = (int *)off_103874;
                    v3 = *(uint32_t *)off_103870;
                    v4 = dword_1038EC;
                    v5 = *(uint32_t *)off_103870;
                    v6 = dword_1038F0;
                    break;
                  case 7:
                    v21 = (unsigned int *)off_103884;
                    v22 = (int *)off_103874;
                    v23 = dword_103888;
                    v24 = dword_1038F4;
                    v25 = *(uint32_t *)off_103870 & 0x70;
                    *(uint32_t *)off_103870 &= 0xFFFFFF70;
                    *v21 = *v21 & 0xFF00FFFF | 0x540000;
                    *v22 = v23;
                    msg_parse(v24, v25);
                    goto LABEL_22;
                  case 8:
                    v1 = (unsigned int *)off_103870;
                    v2 = (int *)off_103874;
                    v4 = dword_103888;
                    v6 = dword_1038F8;
                    *(uint32_t *)off_103884 = *(uint32_t *)off_103884 & 0xFF00FFFF | 0x570000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  case 81:
                    v1 = (unsigned int *)off_103870;
                    v2 = (int *)off_103874;
                    v4 = dword_103888;
                    v6 = dword_1038FC;
                    *(uint32_t *)off_103884 = *(uint32_t *)off_103884 & 0xFF00FFFF | 0x30000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  default:
                    v1 = (unsigned int *)off_103870;
                    v2 = (int *)off_103874;
                    v3 = *(uint32_t *)off_103870;
                    v4 = dword_103878;
                    v5 = *(uint32_t *)off_103870;
                    if ( a1 == 9 )
                      v6 = dword_10387C;
                    else
                      v6 = dword_103880;
                    break;
                }
                break;
              }
            }
            v1 = (unsigned int *)off_103870;
            v2 = (int *)off_103874;
            v3 = *(uint32_t *)off_103870;
            v4 = dword_1038C4;
            v5 = *(uint32_t *)off_103870;
            v6 = dword_1038C8;
            break;
        }
LABEL_24:
        v13 = v3 & 0x70;
        *v1 = v5 & 0xFFFFFF00 | v13;
        *v2 = v4;
        msg_parse(v6, v13);
        goto LABEL_22;
    }
    v20 = v17 & 0xFFFFFF00;
    *v14 = v19 | v20;
    *v15 = v16;
    msg_parse(v18, v20);
    goto LABEL_22;
  }
  v7 = (unsigned int *)off_103884;
  v8 = (int *)off_103874;
  v9 = dword_103888;
  v10 = dword_10388C;
  v11 = *(uint32_t *)off_103870 & 0x70;
  *(uint32_t *)off_103870 &= 0xFFFFFF70;
  *v7 = *v7 & 0xFF00FFFF | 0x770000;
  *v8 = v9;
  msg_parse(v10, v11);
LABEL_22:
  *(uint32_t *)off_103890 = 769;
  return delay_us(500);
}

