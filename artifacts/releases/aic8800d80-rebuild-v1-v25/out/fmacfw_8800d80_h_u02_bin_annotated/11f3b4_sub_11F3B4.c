// fwstruct annotate: 11f3b4_sub_11F3B4.c
// sub_11F3B4 @ 0x11f3b4, size 412 bytes
int __fastcall sub_11F3B4(int result)
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
    result = sub_12A1DC();
  if ( *(_DWORD *)(v1 + 72) )
    result = sub_12815C(v1);
  if ( (*(_DWORD *)(v1 + 4) & 1) != 0 )
  {
    if ( (*(_DWORD *)off_11F550 & 0x2000000) != 0 || (result = *(_DWORD *)off_11F550 << 6, *((_BYTE *)off_11F554 + 36)) )
    {
      result = sub_12EB90(2, dword_11F558);
      v2 = (bool *)off_11F55C;
      v3 = *((unsigned __int8 *)off_11F55C + 1);
      *(_DWORD *)(v1 + 4) &= ~1u;
      *v2 = v3 > 1;
      if ( *((_BYTE *)off_11F560 + 190) )
      {
        if ( **(_BYTE **)off_11F564 == 2 )
        {
          result = sub_117978();
          v4 = off_11F568;
          *(_DWORD *)off_11F568 &= ~1u;
          *v4 &= ~0x80u;
          if ( *(unsigned __int8 *)(v1 + 128) > 9u )
          {
            v5 = off_11F550;
            v6 = off_11F56C;
            v7 = dword_11F570;
            *(_DWORD *)off_11F550 &= ~4u;
            if ( (*v6 & v7) == 0 )
              sub_114434((int)v6, v7, (int)v5);
            if ( *(_DWORD *)off_11F574 << 28 )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(_DWORD *)off_11F578 = 1;
              }
              v8 = (int *)off_11F57C;
              v9 = off_11F574;
              v10 = off_11F580;
              ++*(_DWORD *)off_11F57C;
              *v9 = 0;
              v11 = v10[4];
              while ( *v9 << 28 )
              {
                if ( (unsigned int)(v10[4] - v11) > 0x7530 )
                  sub_12EB90(2, dword_11F5A4);
              }
              v12 = off_11F580;
              v13 = *((_DWORD *)off_11F580 + 4);
              if ( (*(_DWORD *)off_11F584 & *(_DWORD *)off_11F588 & 4) == 0 )
              {
                v14 = off_11F584;
                v15 = off_11F588;
                do
                {
                  v16 = *v14 & *v15;
                  if ( (unsigned int)(v12[4] - v13) > 0x7530 )
                    sub_12EB90(2, dword_11F58C);
                }
                while ( (v16 & 4) == 0 );
              }
              *(_DWORD *)off_11F590 = 4;
              if ( *v8 )
              {
                v17 = *v8 - 1;
                v18 = *(_DWORD *)off_11F578;
                *v8 = v17;
                if ( !v17 )
                {
                  if ( v18 )
                    __enable_irq();
                }
              }
            }
            v19 = off_11F598;
            v20 = **(__int16 **)off_11F594;
            v21 = *((_DWORD *)off_11F598 + 1) | 0x200;
            *((_DWORD *)off_11F598 + 1) = v21;
            if ( v20 < 0 )
            {
              if ( *(_DWORD *)off_11F574 << 28 )
              {
                sub_12F35C(dword_11F5AC, dword_11F5A8, 472);
                v21 = v19[1];
              }
            }
            v22 = off_11F574;
            v23 = off_11F5A0;
            *(_DWORD *)off_11F59C = v21 | *v19;
            *v22 = 48;
            return sub_12B170(*(unsigned __int8 *)(v1 + 107), v23, v1);
          }
        }
      }
    }
  }
  return result;
}

