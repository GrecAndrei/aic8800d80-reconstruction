// bt_rf_param_set_n_5d0 @ 0x11f5d0, size 258 bytes
// Doc: bt_rf_param_set_n_5d0 [bt]: Indexes per-link BT RF parameter table (0x2b8 stride) and stores a field.
// bt_rf_param_set_n_5d0 [bt]: Indexes per-link BT RF parameter table (0x2b8 stride) and stores a field.
int  bt_rf_param_set_n_5d0(int a1, unsigned __int8 a2)
{
  int v2; // r4
  int v3; // r8
  unsigned __int8 *v4; // r7
  int *v5; // r6
  int v7; // r9
  int *v8; // r0
  int v9; // r0
  int *v10; // r2
  int v11; // r3
  int result; // r0
  uint64_t v13; // kr00_8
  int v14; // r1
  int v15; // r2
  int v16; // r0
  int v17; // r1
  int v18; // r3

  v2 = *(unsigned __int8 *)(a1 + 1);
  v3 = dword_11F6EC;
  v4 = (unsigned __int8 *)(dword_11F6EC + 696 * v2);
  v4[162] = a2;
  v4[160] = *(uint8_t *)(a1 + 40);
  v4[161] = *(uint8_t *)a1;
  v5 = (int *)(696 * v2 + 64 + v3);
  v7 = v4[34];
  v8 = memset_thunk(v5, 0, 0x48u);
  switch ( v4[160] )
  {
    case 0u:
    case 3u:
      v9 = sub_143A18(v8);
      v10 = (int *)(v3 + 696 * v2 + 136);
      *v10 = v9 & 0xFFFFFF;
      v10[1] = 0;
      break;
    case 1u:
      v18 = v3 + 696 * v2;
      *(uint32_t *)(v18 + 144) = *(uint32_t *)(a1 + 24);
      *(uint32_t *)(v18 + 148) = *(uint32_t *)(a1 + 28);
      *(uint32_t *)(v18 + 152) = *(uint32_t *)(a1 + 32);
      *(uint32_t *)(v18 + 156) = *(uint32_t *)(a1 + 36);
      *(QWORD *)(v18 + 136) = 0;
      break;
    case 4u:
      v16 = *(unsigned __int8 *)(dword_11F6E8 + 1320 * v7 + 106);
      v17 = v3 + 696 * v2;
      *(QWORD *)(v17 + 136) = *(QWORD *)&dword_11F6D8;
      if ( v16 == 2 )
        *(QWORD *)(v17 + 136) = *(QWORD *)&dword_11F6E0;
      break;
    default:
      *(QWORD *)(v3 + 696 * v2 + 136) = 0;
      break;
  }
  v11 = v3 + 696 * v2;
  v13 = *(QWORD *)(a1 + 8);
  result = *(uint32_t *)(a1 + 12);
  v14 = *(uint32_t *)(a1 + 16);
  *(uint8_t *)(v11 + 163) = 1;
  v15 = *(uint32_t *)(a1 + 20);
  *(uint32_t *)(v11 + 184) = v5;
  *(QWORD *)(v11 + 164) = v13;
  *(uint32_t *)(v11 + 172) = v14;
  *(uint32_t *)(v11 + 176) = v15;
  *(uint8_t *)(v11 + 180) = *(uint8_t *)(a1 + 4);
  return result;
}

