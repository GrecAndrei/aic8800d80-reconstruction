// sub_11E078 @ 0x11e078, size 226 bytes
uint32_t * sub_11E078(char *a1)
{
  __int16 **v1; // r9
  char *v2; // r4
  int v3; // r8
  char *v5; // r5
  uint32_t *result; // r0
  int v7; // r12
  int v8; // r7
  int v9; // r3
  uint32_t *v10; // r1
  int *v11; // r3
  int v12; // r3
  int v13; // r3
  char *v14; // r2
  int v15; // r1
  uint64_t v16; // r2

  v1 = (__int16 **)off_11E174;
  v2 = *((char **)off_11E15C + 7);
  v3 = *((uint32_t *)a1 - 1);
  v5 = a1 - 4;
  if ( **(__int16 **)off_11E174 < 0 && a1 <= v2 )
    rf_cmd_send_n264(dword_11E16C, dword_11E168, 220);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11E160 = 1;
  }
  result = off_11E164;
  v7 = *(uint32_t *)off_11E164;
  v8 = *(uint32_t *)off_11E164 + 1;
  *(uint32_t *)off_11E164 = v8;
  if ( !v2 )
  {
    MEMORY[0] = v5;
    __und(0xFFu);
  }
  v9 = *((uint32_t *)v2 + 1);
  if ( &v2[v9] != v5 )
  {
    if ( v2 > v5 )
    {
      if ( **v1 < 0 )
        rf_cmd_send_n264(dword_11E170, dword_11E168, 247);
      MEMORY[0] = v5;
      __und(0xFFu);
    }
    while ( 1 )
    {
      v10 = v2;
      v2 = *(char **)v2;
      if ( !v2 )
        break;
      v9 = *((uint32_t *)v2 + 1);
      if ( &v2[v9] == v5 )
        goto LABEL_20;
      if ( v2 > v5 )
      {
        *v10 = v5;
        if ( v2 == &v5[v3] )
        {
          *((uint32_t *)a1 - 1) = *(uint32_t *)v2;
          *(uint32_t *)a1 = &v2[v9] - v5;
          goto LABEL_13;
        }
LABEL_12:
        *((uint32_t *)a1 - 1) = v2;
        *(uint32_t *)a1 = v3;
        goto LABEL_13;
      }
    }
    *v10 = v5;
    goto LABEL_12;
  }
LABEL_20:
  v13 = v9 + v3;
  v14 = *(char **)v2;
  *((uint32_t *)v2 + 1) = v13;
  if ( v14 == &v2[v13] )
  {
    v15 = *((uint32_t *)v14 + 1);
    LODWORD(v16) = *(uint32_t *)v14;
    HIDWORD(v16) = v13 + v15;
    *(QWORD *)v2 = v16;
  }
LABEL_13:
  if ( v8 )
  {
    v11 = (int *)off_11E160;
    *result = v7;
    v12 = *v11;
    if ( !v7 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}

