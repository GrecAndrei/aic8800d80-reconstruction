// fwstruct annotate: 11f4a8_sub_11F4A8.c
// sub_11F4A8 @ 0x11f4a8, size 260 bytes
// Doc: sub_121F4A8 [mac]: Processes indexed per-station context entry with size-scaled offsets
// sub_121F4A8 [mac]: Processes indexed per-station context entry with size-scaled offsets
unsigned int __fastcall sub_11F4A8(int a1)
{
  int v1; // r7
  int v2; // r8
  int v3; // r4
  int v4; // r6
  _DWORD *v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r0
  int v10; // r12
  int v11; // r0
  unsigned int result; // r0
  int *v13; // r0
  int v14; // r2
  int *v15; // r3

  v1 = dword_11F5AC;
  v2 = dword_11F5C8;
  v3 = dword_11F5AC + 696 * a1;
  v4 = 1320 * *(unsigned __int8 *)(v3 + 34);
  if ( *(_BYTE *)(dword_11F5C8 + v4 + 1224) )
    --*(_BYTE *)(dword_11F5C8 + v4 + 1226);
  feature_guard_sdio(256, dword_11F5B4);
  list_remove_node_d510(v4 + 240 + v2, v3);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11F5B8 = 1;
  }
  v6 = off_11F5BC;
  v7 = v1 + 696 * a1;
  v8 = *(_DWORD *)off_11F5BC;
  v9 = *(_DWORD *)(v7 + 44);
  v10 = *(_DWORD *)off_11F5BC + 1;
  *(_DWORD *)off_11F5BC = v10;
  *(_BYTE *)(v7 + 37) = 0;
  if ( v9 )
  {
    *(_BYTE *)(v9 + 37) = 0;
    if ( !v10 )
    {
LABEL_7:
      rf_phy_field_clear_n_23c(v9);
      list_push_tail(dword_11F5C0);
      goto LABEL_8;
    }
    v13 = (int *)off_11F5B8;
    *v6 = v8;
    v14 = *v13;
    if ( v8 )
    {
      v9 = *(_DWORD *)(v7 + 44);
      goto LABEL_7;
    }
  }
  else
  {
    if ( !v10 )
      goto LABEL_8;
    v15 = (int *)off_11F5B8;
    *v6 = v8;
    v14 = *v15;
    if ( v8 )
      goto LABEL_8;
  }
  if ( v14 )
    __enable_irq();
  v9 = *(_DWORD *)(v1 + 696 * a1 + 44);
  if ( v9 )
    goto LABEL_7;
LABEL_8:
  rf_phy_field_clear_n_23c(v3);
  v11 = list_push_tail(dword_11F5C0);
  result = sub_122B1C(v11);
  if ( !result )
  {
    if ( *((_BYTE *)off_11F5C4 + 408) )
      return mmio_reg_init_patch(v2 + v4);
    else
      return rf_power_set(0xC2u);
  }
  return result;
}

