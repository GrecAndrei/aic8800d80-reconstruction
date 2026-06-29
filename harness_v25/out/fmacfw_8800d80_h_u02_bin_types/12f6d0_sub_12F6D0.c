// sub_12F6D0 @ 0x12f6d0, size 304 bytes
int  sub_12F6D0(unsigned int a1, uint8_t *a2, int a3)
{
  int *v3; // r6
  char v4; // r4
  int *v6; // r7
  uint32_t *v7; // r3
  int v8; // r2
  int *v9; // r8
  int result; // r0
  int v11; // r0
  int *v12; // r2
  uint32_t *v13; // r3
  int *v14; // r8
  int v15; // r1
  unsigned int v16; // r0
  unsigned __int8 *v17; // r0
  int v18; // r2
  int v19; // r3
  unsigned int v20; // r1
  uint8_t *v21; // r0
  uint32_t *v22; // r3
  uint8_t *v23; // r3
  int v24; // r2

  v3 = (int *)off_12F800;
  v4 = a1;
  if ( *(uint32_t *)off_12F800 )
  {
    if ( !a3 )
      goto LABEL_3;
LABEL_11:
    v11 = sub_143D00(a3);
    v12 = (int *)off_12F804;
    v13 = off_12F80C;
    *v3 = (int)a2;
    *v12 = v11;
    *v13 = 0;
    return 0;
  }
  *(uint32_t *)off_12F800 = a2;
  if ( a3 )
    goto LABEL_11;
LABEL_3:
  v6 = (int *)off_12F804;
  v7 = off_12F808;
  v8 = *(uint32_t *)off_12F804;
  *(uint32_t *)off_12F808 = *(uint32_t *)off_12F804;
  if ( a1 <= 0x17 )
  {
    switch ( a1 )
    {
      case 0u:
        return -1;
      case 3u:
        result = 0;
        *a2 = 0;
        return result;
      case 8u:
        goto LABEL_19;
      case 0xAu:
      case 0xDu:
        v21 = (uint8_t *)dword_12F810;
        *(uint8_t *)*v3 = 0;
        sub_10D674(v21);
        return *v3 - (uint32_t)a2;
      case 0x15u:
        v22 = off_12F80C;
        *v3 = (int)a2;
        *v22 = 0;
        return -1;
      case 0x17u:
        v14 = (int *)off_12F80C;
        v15 = *v3;
        if ( *(uint32_t *)off_12F80C )
        {
          v16 = (unsigned int)a2;
          while ( 1 )
          {
            v17 = (unsigned __int8 *)sub_12F51C(v16, v15, v8);
            v18 = *v14;
            *v3 = (int)v17;
            v15 = (int)v17;
            if ( v18 <= 0 )
              break;
            v19 = *v17;
            v16 = (unsigned int)a2;
            if ( v19 == 32 )
              break;
            v8 = *v6;
          }
        }
        return -1;
      default:
        v9 = (int *)off_12F80C;
        if ( *(int *)off_12F80C > 61 )
          goto LABEL_7;
        if ( a1 != 9 )
          goto LABEL_28;
        sub_10D674((uint8_t *)(dword_12F814 + (v8 & 7)));
        *(uint32_t *)off_12F808 = (*(uint32_t *)off_12F808 & 0xFFFFFFF8) + 8;
        break;
    }
    goto LABEL_27;
  }
  if ( a1 == 127 )
  {
LABEL_19:
    v20 = *v3;
    if ( *(uint32_t *)off_12F80C )
      v20 = sub_12F51C((unsigned int)a2, v20, v8);
    *v3 = v20;
    return -1;
  }
  else
  {
    v9 = (int *)off_12F80C;
    if ( *(int *)off_12F80C <= 61 )
    {
LABEL_28:
      *v7 = v8 + 1;
      sub_10D65C(a1);
LABEL_27:
      v23 = (uint8_t *)*v3;
      *v23 = v4;
      v24 = *v9 + 1;
      *v3 = (int)(v23 + 1);
      *v9 = v24;
      return -1;
    }
LABEL_7:
    sub_10D65C(7);
    return -1;
  }
}

