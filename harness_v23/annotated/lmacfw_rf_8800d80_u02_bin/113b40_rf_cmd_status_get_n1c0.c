// v23 annotated: rf_cmd_status_get_n1c0 @ 0x113b40
// Original: 113b40_rf_cmd_status_get_n1c0.c
// Primary struct: <unclustered>
//
// rf_cmd_status_get_n1c0 @ 0x113b40, size 10 bytes
// Doc: rf_cmd_status_get_n1c0 [rf]: Read RF command status field and extract nibble
// rf_cmd_status_get_n1c0 [rf]: Read RF command status field and extract nibble
int rf_cmd_status_get_n1c0()
{
  return host_reg_wait_set(1u, 512);
}

