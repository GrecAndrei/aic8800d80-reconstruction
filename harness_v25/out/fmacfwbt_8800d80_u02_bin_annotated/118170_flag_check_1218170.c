// fwstruct annotate: 118170_flag_check_1218170.c
// flag_check_1218170 @ 0x118170, size 380 bytes
// Doc: flag_check_1218170 [util]: Checks a flag/subsystem state and global byte
// flag_check_1218170 [util]: Checks a flag/subsystem state and global byte
void __fastcall flag_check_1218170(int a1, _DWORD *a2)
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
    v3 = **(unsigned __int8 **)off_1182EC;
    switch ( v3 )
    {
      case 2:
        v6 = (_BYTE *)sub_113864();
        if ( v6 )
        {
          v7 = off_118318;
          if ( *((_DWORD *)off_118318 + 2057) )
          {
            v8 = sub_12D4F8(dword_1182F0);
            *v6 = 8;
            v6[1] = 0;
            v6[3] = 0;
            v6[2] = 18;
            v9 = *a2 & 0xF;
            v10 = v8;
            v26 = *(_DWORD *)(a1 + 84) & 0x3FFFFFFF;
            v25 = v9;
            sub_14380C(v6 + 4, &v25, 8);
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
            v14 = off_1182F4;
            *(_WORD *)(v10 + 12) = v11;
            v15 = dword_1182F8;
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
              *(_DWORD *)off_1182FC = 1;
            }
            v17 = (int *)off_118300;
            v18 = *(unsigned __int16 *)(a1 + 32);
            v19 = dword_118304;
            ++*(_DWORD *)off_118300;
            sub_12ECB0(v19, a1, v18);
            v20 = list_push_tail(dword_118308);
            phy_reg_init_n_2c4(v20, v21);
            if ( *v17 )
            {
              v22 = *v17 - 1;
              v23 = *(_DWORD *)off_1182FC;
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
            log_printf(dword_118310);
          }
        }
        else
        {
          log_printf(dword_118314);
        }
        break;
      case 1:
        v24 = *a2 & 0xF;
        v26 = v2 & 0x3FFFFFFF;
        v25 = v24;
        msg_alloc_and_send_n0cc(18, (int)&v25, 8);
        sub_12ECB0(dword_118304, a1, *(unsigned __int16 *)(a1 + 32));
        break;
      case 3:
        **(_DWORD **)off_11830C = *a2 & 0xF;
        sub_10CAEC();
        break;
    }
  }
}

