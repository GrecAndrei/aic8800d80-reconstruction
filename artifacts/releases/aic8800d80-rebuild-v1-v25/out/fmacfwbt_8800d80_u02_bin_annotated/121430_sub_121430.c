// fwstruct annotate: 121430_sub_121430.c
// sub_121430 @ 0x121430, size 332 bytes
// Doc: sub_1221430 [unknown]: Unknown helper in fmacfwbt module
// sub_1221430 [unknown]: Unknown helper in fmacfwbt module
int sub_121430()
{
  int v0; // r4
  int *v1; // r5
  int updated; // r0
  int v3; // r1
  int v4; // r3
  int v5; // r2
  _DWORD *v6; // r5
  _DWORD **v7; // r6
  _DWORD *v8; // r7
  int v9; // r3
  _DWORD *v10; // r3
  _DWORD *v11; // r2
  unsigned int v12; // r8
  int v13; // r8
  int **i; // r3
  int v16; // r2
  int v17; // r1
  int v18; // r12
  int v19; // r2

  v0 = *((_DWORD *)off_12157C + 2);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_121580 = 1;
  }
  v1 = (int *)off_121584;
  ++*(_DWORD *)off_121584;
  patch_sub_1217374(4);
  updated = sub_1178DC(4);
  if ( *v1 )
  {
    v4 = *v1 - 1;
    v5 = *(_DWORD *)off_121580;
    *v1 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( v0 )
  {
    v6 = off_121588;
    v7 = (_DWORD **)off_12158C;
    v8 = off_121590;
    do
    {
      while ( 1 )
      {
        if ( *(_BYTE *)(v0 + 106) != 2 )
          goto LABEL_7;
        v9 = (unsigned __int8)(*(_BYTE *)(v0 + 225) - 1);
        *(_BYTE *)(v0 + 225) = v9;
        if ( v9 )
          goto LABEL_7;
        v10 = *v7;
        *(_BYTE *)(v0 + 225) = *(_BYTE *)(v0 + 224);
        if ( v10 )
          break;
LABEL_15:
        mmio_reg_write_helper(v0);
        updated = sub_12A4A8(v0, *(_DWORD *)(v0 + 36) + 3048);
        v3 = *(unsigned __int16 *)(v0 + 222);
        v12 = 32 * *v6;
        if ( v12 <= 0xBE7 )
          v12 += v3 << 10;
        v13 = v12 + v8[4] - 3048;
        if ( *(_DWORD *)(v0 + 72) )
          updated = sub_128160(v0, *(_DWORD *)(v0 + 36), v13);
        if ( *(_BYTE *)(v0 + 1224) )
        {
          updated = timestamp_update_4f60(v0 + 24, v13);
          goto LABEL_7;
        }
        if ( *((unsigned __int8 *)off_121594 + 90) > 1u )
        {
          for ( i = *((int ***)off_121594 + 4); i; i = (int **)*i )
          {
            v3 = *((unsigned __int8 *)i + 8);
            if ( v3 == *(unsigned __int8 *)(v0 + 107) )
            {
              v16 = *(unsigned __int16 *)(v0 + 222);
              v17 = *(_DWORD *)(v0 + 36);
              updated = (int)i[1];
              v18 = v17 + (v16 << 10);
              v19 = v16 << 10;
              if ( updated == v18 )
              {
                i[1] = (int *)v13;
                updated = v13;
                v19 = *(unsigned __int16 *)(v0 + 222) << 10;
              }
              v3 = v17 + 2 * v19;
              if ( v3 == updated )
                i[1] = (int *)(v19 + v13);
            }
          }
        }
        *(_DWORD *)(v0 + 36) = v13;
        v0 = *(_DWORD *)v0;
        if ( !v0 )
          return rf_msg_process_body_n446(updated);
      }
      v11 = (_DWORD *)(v0 + 48);
      while ( v10 != v11 )
      {
        v10 = (_DWORD *)*v10;
        if ( !v10 )
          goto LABEL_15;
      }
      updated = sub_12ECB0(dword_121598, v3, v11);
LABEL_7:
      v0 = *(_DWORD *)v0;
    }
    while ( v0 );
  }
  return rf_msg_process_body_n446(updated);
}

