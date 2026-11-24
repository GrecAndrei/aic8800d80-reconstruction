// accum_update_addr_pair @ 0x116ca4, size 38 bytes
// Doc: accum_update_addr_pair [util]: Add two 32-bit address pairs and store accumulator
// accum_update_addr_pair [util]: Add two 32-bit address pairs and store accumulator
int accum_update_addr_pair()
{
  _DWORD *v0; // r3
  __int64 v1; // kr00_8
  __int64 v2; // kr08_8

  v0 = off_116CD0;
  v1 = *((_QWORD *)off_116CCC + 17);
  v2 = *((_QWORD *)off_116CCC + 18);
  *((_DWORD *)off_116CD0 + 1) = HIDWORD(v1) + v1;
  *(_DWORD *)(v0 + 0x8) = v1;
  *(_DWORD *)(v0 + 0xc) = v2;
  *(_DWORD *)(v0 + 0x10) = HIDWORD(v2) + v2;
  *v0 = v1;
  *(_DWORD *)(v0 + 0x14) = v2;
  return rf_temp_sensor_read();
}

