// v23 annotated: sub_11E1E4 @ 0x11e1e4
// Original: 11e1e4_sub_11E1E4.c
// Primary struct: <unclustered>
//
// sub_11E1E4 @ 0x11e1e4, size 300 bytes
// Doc: sub_121E1E4 [rf]: LMAC handler checking RF state flags
// sub_121E1E4 [rf]: LMAC handler checking RF state flags
_DWORD *__fastcall sub_11E1E4(unsigned int a1, int a2)
{
  __int16 **v2; // r7
  unsigned int v5; // r9
  unsigned int v6; // r6
  _WORD *v7; // r9
  _DWORD *result; // r0
  int (__fastcall *v9)(_DWORD *, int); // r8
  int v10; // r7
  int *v11; // r6
  int *v12; // r5
  int v13; // r0
  int v14; // r3
  int v15; // r2
  int v16; // r6

  v2 = (__int16 **)off_11E310;
  v5 = a1 >> 8;
  v6 = (unsigned __int8)a1;
  if ( **(__int16 **)off_11E310 >= 0 )
    goto LABEL_2;
  if ( (unsigned __int8)a1 <= 4u )
    goto LABEL_15;
  rf_cmd_send_n264(dword_11E334, dword_11E32C, 173);
  if ( **v2 >= 0 )
  {
LABEL_2:
    v7 = (_WORD *)(*(_DWORD *)(dword_11E314 + 16 * v6 + 8) + 2 * v5);
    goto LABEL_3;
  }
  if ( v6 <= 5 )
  {
LABEL_15:
    if ( (a1 & 0xFC) == 0 )
    {
      v16 = dword_11E314 + 16 * v6;
      if ( *(unsigned __int16 *)(v16 + 14) > v5 )
        goto LABEL_17;
      goto LABEL_25;
    }
  }
  else
  {
    rf_cmd_send_n264(dword_11E33C, dword_11E338, 183);
    if ( (a1 & 0xFC) == 0 )
      goto LABEL_23;
  }
  rf_cmd_send_n264(dword_11E340, dword_11E32C, 174);
LABEL_23:
  if ( **v2 >= 0 )
    goto LABEL_2;
  v16 = dword_11E314 + 16 * v6;
  if ( *(unsigned __int16 *)(v16 + 14) > v5 )
  {
LABEL_17:
    v7 = (_WORD *)(*(_DWORD *)(v16 + 8) + 2 * v5);
    if ( v7 )
      goto LABEL_3;
    goto LABEL_18;
  }
LABEL_25:
  rf_cmd_send_n264(dword_11E344, dword_11E32C, 175);
  v7 = (_WORD *)(*(_DWORD *)(v16 + 8) + 2 * v5);
  if ( **v2 < 0 && !v7 )
LABEL_18:
    rf_cmd_send_n264(dword_11E330, dword_11E32C, 180);
LABEL_3:
  result = (_DWORD *)msg_parse(dword_11E318, a1);
  if ( (unsigned __int16)*v7 != a2 )
  {
    v9 = (int (__fastcall *)(_DWORD *, int))dword_11E348;
    v10 = dword_11E31C;
    v11 = (int *)off_11E320;
    *v7 = a2;
    while ( 1 )
    {
      result = list_find_remove(v10, v9, a1);
      if ( !result )
        break;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v11 = 1;
      }
      v12 = (int *)off_11E324;
      v13 = dword_11E328;
      ++*(_DWORD *)off_11E324;
      list_push_tail(v13);
      v14 = *v12 - 1;
      if ( *v12 )
      {
        v15 = *v11;
        *v12 = v14;
        if ( !v14 )
        {
          if ( v15 )
            __enable_irq();
        }
      }
      irq_nesting_or(0x4000000);
    }
  }
  return result;
}

