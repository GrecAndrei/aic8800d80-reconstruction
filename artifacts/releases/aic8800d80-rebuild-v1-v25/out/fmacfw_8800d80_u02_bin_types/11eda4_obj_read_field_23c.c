// obj_read_field_23c @ 0x11eda4, size 76 bytes
// Doc: obj_read_field_23c [util]: Read 32-bit field at offset 0x23c from object handle
// obj_read_field_23c [util]: Read 32-bit field at offset 0x23c from object handle
int * obj_read_field_23c(int a1)
{
  int v2; // r5
  int v3; // r0
  int *result; // r0
  int v5; // r3

  v2 = a1 + 572;
  while ( *(uint32_t *)(a1 + 572) )
  {
    v3 = rf_bus_mark_n100_d2d0(v2);
    sub_118CFC(v3, 1);
  }
  result = memset_thunk((int *)a1, 0, 0x2B8u);
  v5 = a1;
  do
  {
    *(uint8_t *)(v5 + 452) = 33;
    *(uint8_t *)(v5 + 453) = 33;
    v5 += 12;
  }
  while ( v5 != a1 + 108 );
  *(uint8_t *)(a1 + 34) = -1;
  return result;
}

