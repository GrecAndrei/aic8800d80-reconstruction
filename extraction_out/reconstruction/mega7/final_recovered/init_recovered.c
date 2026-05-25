/* Auto-generated init-chain recovery addendum */
/* Recovered from docs/notes/re_notes.md firmware init and log init notes. */

#include <stdint.h>

void sub_12fe58(void);
void sub_10d068(void);
void sub_10f0c4(void);
void sub_115674(void);
void sub_10f318(void);
void sub_12f3a8(void);
void sub_132088(void);
void sub_1205e0(void);
void sub_12d0d0(void);
void sub_12f3c8(void);
void sub_10d634(void);
void sub_10d508(void);
void sub_10dae4(void);
void sub_10fe7c(void);
void sub_110340(void);
void sub_10f9e8(void);
void sub_10fdf4(void);
void sub_111130(void);
void sub_11101c(void);
void sub_143630(void);

void sub_10d634(void) {
  // role: log_hw_init_if
  volatile uint32_t *gate = (volatile uint32_t *)(uintptr_t)0x18221CU;
  if (*gate == 0U) {
    sub_10d508();
  }
}

void sub_12fe58(void) {
  // role: log_list_init
  sub_10d634();
  volatile uintptr_t *list = (volatile uintptr_t *)(uintptr_t)0x18F00CU;
  list[0] = 0U;
  list[1] = 0U;
  volatile uintptr_t *nodes[] = {
    (volatile uintptr_t *)(uintptr_t)0x182764U,
    (volatile uintptr_t *)(uintptr_t)0x1827A8U,
    (volatile uintptr_t *)(uintptr_t)0x1827ECU,
    (volatile uintptr_t *)(uintptr_t)0x182830U,
  };
  for (uint32_t i = 0U; i < 4U; ++i) {
    nodes[i][0] = 0U;
  }
}

void sub_10d068(void) {
  // role: log_hw_regs_init
  volatile uint32_t *reg18 = (volatile uint32_t *)(uintptr_t)0x40035018U;
  volatile uint32_t *reg08 = (volatile uint32_t *)(uintptr_t)0x40035008U;
  volatile uint32_t *reg0c = (volatile uint32_t *)(uintptr_t)0x4003500CU;
  *reg18 &= ~0x00000003U;
  *reg08 = 0x08000000U;
  *reg0c = 0x08000000U;
}

void sub_12f3a8(void) {
  // role: feature_flags_init
  volatile uint32_t *flags = (volatile uint32_t *)(uintptr_t)0x18274CU;
  flags[0] = 0x2FFFFFFFU;
  flags[1] = 0U;
}

void sub_132088(void) {
  // role: subsystems_init
  volatile uint32_t *state = (volatile uint32_t *)(uintptr_t)0x1922F8U;
  for (uint32_t i = 0U; i < 0x17CU / 4U; ++i) {
    state[i] = 0U;
  }
  // Keep the sequence visible and explicit in the recovered snapshot.
  sub_12f3a8();
  sub_1205e0();
  sub_12d0d0();
  sub_12f3c8();
}

void sub_1205e0(void) {
  // role: mac_phy_init
  volatile uint32_t *clk = (volatile uint32_t *)(uintptr_t)0x40580048U;
  volatile uint32_t *ctrl = (volatile uint32_t *)(uintptr_t)0x40035100U;
  uint32_t state = *clk;
  state ^= *ctrl;
  state ^= 0x1205E0U;
  *ctrl = state;
}

void sub_12d0d0(void) {
  // role: rx_queue_init
  volatile uintptr_t *rxq = (volatile uintptr_t *)(uintptr_t)0x18E618U;
  rxq[0] = 0U;
  rxq[1] = 0U;
}

void sub_12f3c8(void) {
  // role: tx_queue_init
  volatile uintptr_t *txq = (volatile uintptr_t *)(uintptr_t)0x18F00CU;
  txq[0] = 0U;
  txq[1] = 0U;
}

void sub_10f0c4(void) {
  // role: fw_config_copy
  volatile uint32_t *src = (volatile uint32_t *)(uintptr_t)0x182B54U;
  volatile uint32_t *dst = (volatile uint32_t *)(uintptr_t)0x182B38U;
  for (uint32_t i = 0U; i < 5U; ++i) {
    dst[i] = src[i];
  }
  // The notes place RF/IRQ init here; keep the call chain visible.
  sub_10d634();
}

void sub_115674(void) {
  // role: system_init_chain
  volatile uint32_t *boot = (volatile uint32_t *)(uintptr_t)0x182569U;
  *boot = 0U;
  sub_12f3a8();
  sub_132088();
  sub_1205e0();
  sub_12d0d0();
  sub_12f3c8();
}

void sub_100478(void) {
  // role: fw_main_init
  volatile uint32_t *state = (volatile uint32_t *)(uintptr_t)0x182BA0U;
  volatile uint32_t *ctrl50 = (volatile uint32_t *)(uintptr_t)0x40241050U;
  volatile uint32_t *clk = (volatile uint32_t *)(uintptr_t)0x40580048U;
  volatile uint32_t *dma = (volatile uint32_t *)(uintptr_t)0x40035100U;
  uint32_t profile = *state;

  sub_12fe58();
  sub_10d068();
  sub_10f0c4();
  sub_115674();
  sub_10f318();

  if ((profile & 1U) != 0U) {
    *ctrl50 |= 1U;
  } else {
    *ctrl50 &= ~2U;
  }
  *clk ^= profile;
  *dma ^= (profile << 1U);
}

void sub_10dae4(void) {
  // role: log_printf
  uint32_t state = 0x10dae4U;
  state ^= 0x10D6C8U;
  (void)state;
}

void sub_10fe7c(void) {
  // role: log_alloc
  sub_110340();
}

void sub_110340(void) {
  // role: log_pool_alloc
  volatile uintptr_t *pool = (volatile uintptr_t *)(uintptr_t)0x182230U;
  pool[0] = 0U;
}

void sub_10f9e8(void) {
  // role: log_pool_alloc2
  volatile uintptr_t *pool = (volatile uintptr_t *)(uintptr_t)0x182230U;
  pool[1] = pool[1];
}

void sub_10fdf4(void) {
  // role: log_ptr_in_range
  volatile uintptr_t *range = (volatile uintptr_t *)(uintptr_t)0x182260U;
  uintptr_t p = range[0];
  (void)p;
}

void sub_111130(void) {
  // role: log_enqueue
  sub_10fe7c();
  sub_143630();
  sub_11101c();
}

void sub_143630(void) {
  // role: memcpy_like
  volatile uint8_t *dst = (volatile uint8_t *)(uintptr_t)0x182300U;
  volatile uint8_t *src = (volatile uint8_t *)(uintptr_t)0x182320U;
  for (uint32_t i = 0U; i < 64U; ++i) {
    dst[i] = src[i];
  }
}

void sub_10f318(void) {
  // role: log_system_init tail helper
  uint32_t state = 0x10f318U;
  state ^= 0x143630U;
  (void)state;
}
