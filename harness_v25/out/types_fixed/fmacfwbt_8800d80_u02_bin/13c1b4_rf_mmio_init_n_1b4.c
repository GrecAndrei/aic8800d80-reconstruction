// rf_mmio_init_n_1b4 @ 0x13c1b4, size 344 bytes
// Doc: rf_mmio_init_n_1b4 [mmio]: Initialize RF MMIO register block at 0x40501000
// rf_mmio_init_n_1b4 [mmio]: Initialize RF MMIO register block at 0x40501000
unsigned int __fastcall rf_mmio_init_n_1b4(unsigned int result)
{
  int v1; // r1
  int v2; // r2
  int v3; // r5
  int v4; // r6
  int v5; // r12
  unsigned int v6; // r4
  int v7; // r3
  int v8; // r7
  int v9; // r2
  int v10; // r8
  int v11; // r9
  int v12; // r7
  int v13; // r9
  __int16 v14; // r3
  int (__fastcall *v15)(int, int); // r2
  __int16 v16; // r1

  v1 = *(unsigned __int8 *)(result + 27);
  v2 = *((_DWORD *)off_13C30C + 4);
  if ( v1 != 255 )
  {
    v3 = *(unsigned __int8 *)(result + 29);
    v4 = dword_13C310;
    v5 = dword_13C310 + 696 * v3;
    v6 = result;
    result = *(_DWORD *)(v5 + 4) << 30;
    if ( (*(_DWORD *)(v5 + 4) & 2) != 0 )
    {
      v7 = 696 * v3 + 12 * v1 + dword_13C310;
      v8 = *(unsigned __int8 *)(v7 + 453);
      ++*(_BYTE *)(v7 + 455);
      if ( v8 == 33 )
      {
        result = v2 + 1000000 - *(_DWORD *)(v7 + 444);
        if ( result > dword_13C328 && v2 - 500000 - *(_DWORD *)(v7 + 448) >= 0 && *(_BYTE *)(v5 + 36) != 1 )
        {
          result = dword_13C318;
          v9 = *(unsigned __int8 *)(dword_13C314 + v1);
          if ( !*(_DWORD *)(dword_13C318 + 84 * v9)
            && !*(_DWORD *)(dword_13C320 + 8 * v9)
            && !*(_DWORD *)(v4 + 8 * (v9 + 87 * v3 + 78)) )
          {
            result = dword_13C324;
            if ( !*(_DWORD *)(dword_13C324 + 8 * (165 * *(unsigned __int8 *)(v6 + 28) + v9 + 159)) )
              return sub_13C050(v3, v1, *(_WORD *)(v6 + 32));
          }
        }
      }
      else
      {
        v10 = dword_13C32C;
        v11 = dword_13C32C + 32 * v8;
        *(_DWORD *)(v11 + 8) = v2;
        result = msg_get_value((v8 << 8) | 8);
        v12 = 32 * v8;
        if ( result == 1 )
        {
          v13 = *(_DWORD *)(v11 + 28);
          v14 = *(_WORD *)(v6 + 30);
          result = *(unsigned __int16 *)(v13 + 4);
          *(_WORD *)(v6 + 34) = result;
          if ( (v14 & 1) == 0 || (v14 & 3) == 3 )
          {
            if ( (*(_BYTE *)(*(_DWORD *)(v4 + 696 * v3 + 340) + 166) & 4) != 0 )
              *(_DWORD *)(v6 + 36) |= 0x200000u;
            v15 = *(int (__fastcall **)(int, int))v13;
            v16 = *(_WORD *)(v6 + 32) - result;
            *(_WORD *)(v6 + 30) = v14 | 2;
            result = v15(v13, v16 & 0xFFF) + v13;
            *(_BYTE *)(result + 6) = 1;
            if ( (*(_WORD *)(v6 + 30) & 1) == 0 )
              *(_WORD *)(v6 + 64) = *((_WORD *)off_13C31C + 22) + (*((_DWORD *)off_13C30C + 4) >> 10);
            ++*(_DWORD *)(v12 + v10 + 4);
          }
        }
      }
    }
  }
  return result;
}

