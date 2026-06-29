// fwstruct annotate: 11f4f4_rf_cmd_dispatch_n_125.c
// rf_cmd_dispatch_n_125 @ 0x11f4f4, size 412 bytes
// Doc: rf_cmd_dispatch_n_125 [rf]: Dispatch RF command by shifted index
// rf_cmd_dispatch_n_125 [rf]: Dispatch RF command by shifted index
int __fastcall rf_cmd_dispatch_n_125(int result)
{
  int v1; // r4
  bool *v2; // r2
  unsigned int v3; // r1
  _DWORD *v4; // r3
  void *v5; // r2
  _DWORD *v6; // r0
  int v7; // r1
  int *v8; // r6
  _DWORD *v9; // r5
  _DWORD *v10; // r7
  int v11; // r8
  _DWORD *v12; // r7
  int v13; // r10
  _DWORD *v14; // r9
  _DWORD *v15; // r8
  int v16; // r5
  int v17; // r3
  int v18; // r2
  _DWORD *v19; // r5
  int v20; // r2
  int v21; // r3
  _DWORD *v22; // r2
  void *v23; // r1

  v1 = result;
  if ( *(_BYTE *)(result + 1224) )
    result = sub_12A31C();
  if ( *(_DWORD *)(v1 + 72) )
    result = sub_12829C(v1);
  if ( (*(_DWORD *)(v1 + 4) & 1) != 0 )
  {
    if ( (*(_DWORD *)off_11F690 & 0x2000000) != 0 || (result = *(_DWORD *)off_11F690 << 6, *((_BYTE *)off_11F694 + 36)) )
    {
      result = feature_guard_check(2, dword_11F698);
      v2 = (bool *)off_11F69C;
      v3 = *((unsigned __int8 *)off_11F69C + 1);
      *(_DWORD *)(v1 + 4) &= ~1u;
      *v2 = v3 > 1;
      if ( *((_BYTE *)off_11F6A0 + 190) )
      {
        if ( **(_BYTE **)off_11F6A4 == 2 )
        {
          result = sub_117AB8();
          v4 = off_11F6A8;
          *(_DWORD *)off_11F6A8 &= ~1u;
          *v4 &= ~0x80u;
          if ( *(unsigned __int8 *)(v1 + 128) > 9u )
          {
            v5 = off_11F690;
            v6 = off_11F6AC;
            v7 = dword_11F6B0;
            *(_DWORD *)off_11F690 &= ~4u;
            if ( (*v6 & v7) == 0 )
              rf_fault_dump_n_1d4((int)v6, v7, (int)v5);
            if ( *(_DWORD *)off_11F6B4 << 28 )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(_DWORD *)off_11F6B8 = 1;
              }
              v8 = (int *)off_11F6BC;
              v9 = off_11F6B4;
              v10 = off_11F6C0;
              ++*(_DWORD *)off_11F6BC;
              *v9 = 0;
              v11 = v10[4];
              while ( *v9 << 28 )
              {
                if ( (unsigned int)(v10[4] - v11) > 0x7530 )
                  feature_guard_check(2, dword_11F6E4);
              }
              v12 = off_11F6C0;
              v13 = *((_DWORD *)off_11F6C0 + 4);
              if ( (*(_DWORD *)off_11F6C4 & *(_DWORD *)off_11F6C8 & 4) == 0 )
              {
                v14 = off_11F6C4;
                v15 = off_11F6C8;
                do
                {
                  v16 = *v14 & *v15;
                  if ( (unsigned int)(v12[4] - v13) > 0x7530 )
                    feature_guard_check(2, dword_11F6CC);
                }
                while ( (v16 & 4) == 0 );
              }
              *(_DWORD *)off_11F6D0 = 4;
              if ( *v8 )
              {
                v17 = *v8 - 1;
                v18 = *(_DWORD *)off_11F6B8;
                *v8 = v17;
                if ( !v17 )
                {
                  if ( v18 )
                    __enable_irq();
                }
              }
            }
            v19 = off_11F6D8;
            v20 = **(__int16 **)off_11F6D4;
            v21 = *((_DWORD *)off_11F6D8 + 1) | 0x200;
            *((_DWORD *)off_11F6D8 + 1) = v21;
            if ( v20 < 0 )
            {
              if ( *(_DWORD *)off_11F6B4 << 28 )
              {
                sub_12F49C(dword_11F6EC, dword_11F6E8, 472);
                v21 = v19[1];
              }
            }
            v22 = off_11F6B4;
            v23 = off_11F6E0;
            *(_DWORD *)off_11F6DC = v21 | *v19;
            *v22 = 48;
            return sub_12B2B0(*(unsigned __int8 *)(v1 + 107), v23, v1);
          }
        }
      }
    }
  }
  return result;
}

