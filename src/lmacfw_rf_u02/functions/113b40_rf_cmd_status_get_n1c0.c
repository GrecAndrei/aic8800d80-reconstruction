// rf_set_reg1_bit9 @ 0x113b40, size 10 bytes
// Doc: rf_set_reg1_bit9 [rf]: Read RF command status field and extract nibble
// rf_set_reg1_bit9 [rf]: Read RF command status field and extract nibble
int rf_set_reg1_bit9()
{
  return mmio_write32(1u, 512);
}

