// patch_ctrl_write_magic @ 0x123b30, size 130 bytes
// Doc: patch_ctrl_write_magic [patch]: Writes cafefade magic and control word to indexed register slot
// patch_ctrl_write_magic [patch]: Writes cafefade magic and control word to indexed register slot
int  patch_ctrl_write_magic(uint32_t *a1, int a2, int a3)
{
  int v3; // r2
  int v4; // r4
  int v5; // r7
  int v6; // r5
  int *v7; // r8
  int v8; // r2
  int v10; // r0
  int *v11; // r3
  int v12; // r12
  int *v13; // r4

  v3 = 300 * a3;
  v4 = dword_123BB4;
  v5 = dword_123BB8;
  v6 = a1[4];
  *(uint32_t *)(dword_123BB4 + v3) = dword_123BB8;
  if ( a2 >= 0x10000 )
    a2 = 0x10000;
  v7 = (int *)(v4 + v3);
  v8 = a2 - 4096;
  v7[2] = v6;
  v7[4] = 0;
  if ( a2 - 4096 <= 4096 )
  {
    v12 = a2 - 4096;
    v13 = v7;
  }
  else
  {
    v10 = a1[5];
    v11 = v7 + 5;
    v12 = a2 - 61440;
    while ( 1 )
    {
      v8 -= 4096;
      v13 = v11;
      *(v11 - 2) = v10;
      *v11 = v5;
      v11[2] = v6;
      v11[4] = 0;
      *(v11 - 4) = (int)v11;
      v11 += 5;
      if ( v8 <= 4096 )
        break;
      if ( v8 == v12 )
        goto LABEL_7;
    }
    v12 = v8;
  }
LABEL_7:
  v13[3] = v6 - 1 + v12;
  v13[1] = 0;
  a1[3] = v7;
  return a2;
}

