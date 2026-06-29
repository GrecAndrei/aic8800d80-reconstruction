// accum_update_addr_pair @ 0x116ca4, size 38 bytes
// Doc: accum_update_addr_pair [util]: Add two 32-bit address pairs and store accumulator
// accum_update_addr_pair [util]: Add two 32-bit address pairs and store accumulator
int accum_update_addr_pair()
{
  uint32_t *v0; // r3
  uint64_t v1; // kr00_8
  uint64_t v2; // kr08_8

  v0 = off_116CD0;
  v1 = *((QWORD *)off_116CCC + 17);
  v2 = *((QWORD *)off_116CCC + 18);
  *((uint32_t *)off_116CD0 + 1) = HIDWORD(v1) + v1;
  v0[2] = v1;
  v0[3] = v2;
  v0[4] = HIDWORD(v2) + v2;
  *v0 = v1;
  v0[5] = v2;
  return rf_temp_sensor_read();
}

