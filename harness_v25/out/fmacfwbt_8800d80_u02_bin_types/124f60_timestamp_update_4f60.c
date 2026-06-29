// timestamp_update_4f60 @ 0x124f60, size 212 bytes
// Doc: timestamp_update_4f60 [util]: Update firmware timestamp counter
// timestamp_update_4f60 [util]: Update firmware timestamp counter
int  timestamp_update_4f60(int a1, int a2)
{
  int *v4; // r7
  uint32_t *v5; // r2
  int *v6; // r6
  void *v7; // r2
  int result; // r0
  int v9; // r3
  int v10; // r3
  int v11; // r2
  void *v12; // r2
  uint32_t *v13; // r2
  int v14; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_125034 = 1;
  }
  v4 = (int *)off_125038;
  v5 = off_12503C;
  ++*(uint32_t *)off_125038;
  if ( a2 - v5[4] < 0 )
  {
    sub_12ECB0(dword_125048, *(uint32_t *)(a1 + 4), a2);
    if ( **(__int16 **)off_12504C < 0 )
      sub_12F694(dword_125054, dword_125050, 131);
  }
  v6 = (int *)off_125040;
  if ( a1 == *(uint32_t *)off_125040 )
  {
    sub_12D4F8(off_125040);
    v12 = off_125044;
    *(uint32_t *)(a1 + 12) = a2;
    result = list_insert_sorted(v6, a1, v12);
    v9 = *v6;
    if ( !*v6 )
    {
      *((uint32_t *)off_12503C + 2) = 1024;
      goto LABEL_6;
    }
    goto LABEL_14;
  }
  list_remove_node_d510(off_125040, a1);
  v7 = off_125044;
  *(uint32_t *)(a1 + 12) = a2;
  result = list_insert_sorted(v6, a1, v7);
  v9 = *v6;
  if ( a1 == *v6 )
  {
LABEL_14:
    v13 = off_12503C;
    v14 = *(uint32_t *)(v9 + 12);
    result = 0x40000;
    *((uint32_t *)off_12503C + 2) = 0x40000;
    v13[12] = v14;
    v13[2] = 4;
  }
LABEL_6:
  if ( *v4 && (v10 = *v4 - 1, v11 = *(uint32_t *)off_125034, (*v4 = v10) == 0) && v11 )
  {
    __enable_irq();
    if ( a2 - *((uint32_t *)off_12503C + 4) < 0 )
      return irq_nesting_or(0x20000000);
  }
  else if ( a2 - *((uint32_t *)off_12503C + 4) < 0 )
  {
    return irq_nesting_or(0x20000000);
  }
  return result;
}

