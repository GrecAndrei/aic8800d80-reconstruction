// sub_11AA8C @ 0x11aa8c, size 114 bytes
int __fastcall sub_11AA8C(int a1, unsigned __int16 *a2, int a3, void *a4)
{
  int v4; // r4
  void *v6; // r1
  int v8; // [sp+0h] [bp-8h]
  int v9; // [sp+0h] [bp-8h]
  int v10; // [sp+0h] [bp-8h]
  int v11; // [sp+0h] [bp-8h]
  int v12; // [sp+0h] [bp-8h]

  v4 = *(_DWORD *)a2;
  v6 = a4;
  switch ( v4 )
  {
    case 0:
      v8 = a3;
      rf_reg_probe_id(a2 + 2);
      a3 = v8;
      v6 = a4;
      break;
    case 1:
      v10 = a3;
      rf_state_copy_to_shm((unsigned __int8 *)a2 + 4);
      a3 = v10;
      v6 = a4;
      break;
    case 2:
      v11 = a3;
      rf_mmio_status_read((unsigned __int8 *)a2 + 4);
      a3 = v11;
      v6 = a4;
      break;
    case 3:
      v12 = a3;
      sub_11A9BC((unsigned __int8 *)a2 + 4, a4);
      a3 = v12;
      v6 = a4;
      break;
    case 4:
      v9 = a3;
      sub_11AA5C((unsigned __int8 *)a2 + 4);
      a3 = v9;
      v6 = a4;
      break;
    default:
      break;
  }
  sub_11DED8(127, v6, a3);
  return 0;
}

