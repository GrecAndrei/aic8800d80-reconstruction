// v23 annotated: sub_117BF0 @ 0x117bf0
// Original: 117bf0_sub_117BF0.c
// Primary struct: <unclustered>
//
// sub_117BF0 @ 0x117bf0, size 380 bytes
void __fastcall sub_117BF0(int a1, _DWORD *a2)
{
  int v2; // r3
  int v3; // r2
  _BYTE *v6; // r6
  _BYTE *v7; // r9
  int v8; // r0
  int v9; // r12
  int v10; // r7
  unsigned int v11; // r3
  __int16 v12; // lr
  int v13; // r2
  _DWORD *v14; // r1
  int v15; // r3
  int *v16; // r12
  int *v17; // r6
  int v18; // r2
  int v19; // r0
  int v20; // r0
  int v21; // r1
  int v22; // r3
  int v23; // r2
  int v24; // r6
  int v25; // [sp+0h] [bp-28h] BYREF
  int v26; // [sp+4h] [bp-24h]

  v2 = *(_DWORD *)(a1 + 84);
  if ( v2 < 0 )
  {
    v3 = **(unsigned __int8 **)off_117D6C;
    switch ( v3 )
    {
      case 2:
        v6 = (_BYTE *)sub_1138C8();
        if ( v6 )
        {
          v7 = off_117D98;
          if ( *((_DWORD *)off_117D98 + 2057) )
          {
            v8 = sub_12D190(dword_117D70);
            *v6 = 8;
            v6[1] = 0;
            v6[3] = 0;
            v6[2] = 18;
            v9 = *a2 & 0xF;
            v10 = v8;
            v26 = *(_DWORD *)(a1 + 84) & 0x3FFFFFFF;
            v25 = v9;
            sub_143630(v6 + 4, &v25, 8);
            v11 = *((unsigned __int16 *)v7 + 4122);
            if ( v11 > 0x186 )
            {
              v13 = 0;
              LOWORD(v11) = 0;
              v12 = 1;
            }
            else
            {
              v12 = v11 + 1;
              v13 = 8 * v11;
            }
            v14 = off_117D74;
            *(_WORD *)(v10 + 12) = v11;
            v15 = dword_117D78;
            v16 = (int *)(*v14 + v13);
            v16[1] = (int)v6;
            *v16 = v15 & *v16 | 0x400000C;
            LOBYTE(v15) = v7[3074];
            *((_WORD *)v7 + 4122) = v12;
            v7[3074] = v15 + 1;
            *(_DWORD *)(v10 + 4) = v16;
            *(_BYTE *)(v10 + 14) = 1;
            *(_DWORD *)v10 = 0;
            *(_DWORD *)(v10 + 8) = 12;
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(_DWORD *)off_117D7C = 1;
            }
            v17 = (int *)off_117D80;
            v18 = *(unsigned __int16 *)(a1 + 32);
            v19 = dword_117D84;
            ++*(_DWORD *)off_117D80;
            sub_12E948(v19, a1, v18);
            v20 = sub_12D108(dword_117D88);
            sub_113374(v20, v21);
            if ( *v17 )
            {
              v22 = *v17 - 1;
              v23 = *(_DWORD *)off_117D7C;
              *v17 = v22;
              if ( !v22 )
              {
                if ( v23 )
                  __enable_irq();
              }
            }
          }
          else
          {
            sub_10DAE4(dword_117D90);
          }
        }
        else
        {
          sub_10DAE4(dword_117D94);
        }
        break;
      case 1:
        v24 = *a2 & 0xF;
        v26 = v2 & 0x3FFFFFFF;
        v25 = v24;
        sub_111130(18, (int)&v25, 8);
        sub_12E948(dword_117D84, a1, *(unsigned __int16 *)(a1 + 32));
        break;
      case 3:
        **(_DWORD **)off_117D8C = *a2 & 0xF;
        sub_10CB54();
        break;
    }
  }
}

