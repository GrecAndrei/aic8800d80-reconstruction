// sub_10F2B0 @ 0x10f2b0, size 192 bytes
int sub_10F2B0()
{
  unsigned __int8 **v0; // r4
  int v1; // r3
  uint32_t *v2; // r3
  int v3; // r2
  uint64_t v4; // r0
  int v5; // r3
  uint32_t *v6; // r3
  int v7; // r2
  uint32_t *v8; // r3
  int v9; // r2
  int ( **v10)(int); // r4
  int v11; // r0
  int v12; // r2
  int ( **v13)(int); // r5
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int ( **v17)(int); // r5
  int v18; // r0
  int v19; // r0
  int v20; // r0
  int v21; // r0

  v0 = (unsigned __int8 **)off_10F370;
  v1 = **(unsigned __int8 **)off_10F370;
  switch ( v1 )
  {
    case 1:
      v8 = off_10F374;
      v9 = dword_10F38C;
      *((uint32_t *)off_10F374 + 2) = dword_10F388;
      v8[3] = v9;
      break;
    case 2:
      v2 = off_10F374;
      v3 = dword_10F37C;
      *((uint32_t *)off_10F374 + 6) = dword_10F378;
      v2[7] = v3;
      break;
    case 3:
      v6 = off_10F374;
      v7 = dword_10F384;
      *((uint32_t *)off_10F374 + 8) = dword_10F380;
      v6[9] = v7;
      break;
  }
  sub_10F1D4();
  v4 = sub_10F208();
  v5 = **v0;
  if ( v5 == 1 )
  {
    v17 = (int ( **)(int))off_10F374;
    *(uint32_t *)off_10F390 = dword_10F3A4;
    v18 = sub_11003C(v4, HIDWORD(v4));
    v19 = sub_11007C(v18);
    v20 = sub_1100D4(v19);
    sub_10FFE4(v20);
    v21 = v17[2](dword_10F398);
    LODWORD(v4) = v17[3](v21);
    v5 = **v0;
  }
  if ( v5 == 2 )
  {
    v12 = dword_10F3A0;
    *(uint32_t *)off_10F390 = dword_10F39C;
    v13 = (int ( **)(int))off_10F374;
    *(uint16_t *)(v12 + 8244) = 0;
    v14 = sub_113824();
    sub_113670(v14);
    v15 = v13[6](dword_10F398);
    v16 = v13[7](v15);
    LODWORD(v4) = sub_113FC4(v16);
    v5 = **v0;
  }
  if ( v5 == 3 )
  {
    v10 = (int ( **)(int))off_10F374;
    *(uint32_t *)off_10F390 = dword_10F394;
    sub_114090();
    v11 = v10[8](dword_10F398);
    LODWORD(v4) = v10[9](v11);
  }
  return v4;
}

