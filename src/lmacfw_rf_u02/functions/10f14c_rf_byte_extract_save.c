// mmio_set_reg_0x70001408 @ 0x10f14c, size 12 bytes
// Doc: mmio_set_reg_0x70001408 [rf]: Extracts high byte and saves to stack
// mmio_set_reg_0x70001408 [rf]: Extracts high byte and saves to stack
int mmio_set_reg_0x70001408()
{
  return critical_enter3(dword_10F158, 0, 2, 1);
}

