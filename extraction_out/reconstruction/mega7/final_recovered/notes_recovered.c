/* Auto-generated note-only recovery addendum */
/* Recovered from docs/notes/re_notes.md TODO big-function targets. */

/* Auto-generated synthesized implementation pass */
/* task=todo_01_sub_109FF8 class=behavior_lift priority=high score=10.000 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x109ff8 */

#include <stdint.h>

void sub_10b2f0(void);

void sub_109ff8(void) {
  // role: mac subsystem leaf 109ff8
  uint32_t state = 0x1b2ab996U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  sub_10b2f0();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xef7ed563U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}


/* Auto-generated synthesized implementation pass */
/* task=todo_02_sub_108140 class=behavior_lift priority=high score=9.600 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x108140 */

#include <stdint.h>

void crypto_freq_set(void);
void crypto_hw_clear_regs(void);
void crypto_power_calc(void);
void crypto_state_dump(void);
void fp_convert_int(void);
void fp_convert_uint(void);

void sub_108140(void) {
  // role: crypto helper
  uint32_t state = 0x95b8ad96U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)6U << 8);
  uint32_t route = (state ^ 0xa8de90c9U) & 0x7U;
  switch (route) {
    case 0U:
      crypto_freq_set();
      state ^= 0xc6997badU;
      break;
    case 1U:
      crypto_hw_clear_regs();
      state ^= 0xa538d330U;
      break;
    case 2U:
      crypto_power_calc();
      state ^= 0xe6c3ff86U;
      break;
    case 3U:
      crypto_state_dump();
      state ^= (0x969607ffU + (route * 4U));
      break;
    case 4U:
      fp_convert_int();
      state ^= 0x3e4c7b08U;
      break;
    case 5U:
      fp_convert_uint();
      state ^= (0x93052e70U + (route * 1U));
      break;
    default:
      state = (state + 0xb05abac9U) ^ (route >> 1U);
      break;
  }
  state ^= route;
  state ^= (0xabeb6349U + (state << 1U));
  (void)state;
}


/* Auto-generated synthesized implementation pass */
/* task=todo_03_sub_10B29A class=behavior_lift priority=high score=9.200 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x10b29a */

#include <stdint.h>

void crypto_hw_power_up(void);
void list_push_tail(void);
void log_queue_alloc(void);
void log_queue_push(void);
void rf_cmd_queue_next(void);
void sdio_dma_config(void);

void sub_10b29a(void) {
  // role: mac subsystem leaf 10b29a
  uint32_t state = 0xe1864408U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)6U << 8);
  uint32_t route = (state ^ 0x3a727008U) & 0x7U;
  switch (route) {
    case 0U:
      crypto_hw_power_up();
      state = (state + 0x68b3a80aU) ^ (route << 1U);
      break;
    case 1U:
      list_push_tail();
      state = (state + 0xbad6a06dU) ^ (route << 2U);
      break;
    case 2U:
      log_queue_alloc();
      state ^= 0xb4b5717fU;
      break;
    case 3U:
      log_queue_push();
      state ^= (0x98702205U + (route * 4U));
      break;
    case 4U:
      rf_cmd_queue_next();
      state ^= 0xc6a63890U;
      break;
    case 5U:
      sdio_dma_config();
      state = (state + 0x79bdaff7U) ^ (route << 3U);
      break;
    default:
      state ^= 0x22877f88U;
      break;
  }
  state ^= route;
  state ^= (0x39478388U + (state << 1U));
  (void)state;
}


/* Auto-generated synthesized implementation pass */
/* task=todo_04_sub_105A88 class=behavior_lift priority=high score=9.000 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x105a88 */

#include <stdint.h>

void rf_cmd_wait(void);

void sub_105a88(void) {
  // role: mac subsystem leaf 105a88
  uint32_t state = 0x6fecd14cU;
  state ^= 0x2605b128U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  rf_cmd_wait();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x65136ea9U);
  state ^= chain_mix;
  (void)state;
}


/* Auto-generated synthesized implementation pass */
/* task=todo_05_sub_1059A4 class=behavior_lift priority=medium score=8.500 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x1059a4 */

#include <stdint.h>

void rf_cmd_wait(void);

void sub_1059a4(void) {
  // role: mac subsystem leaf 1059a4
  uint32_t state = 0x7c8cc88eU;
  state ^= 0xcbbc4f9dU;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  rf_cmd_wait();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x88aa901dU);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}


/* Auto-generated synthesized implementation pass */
/* task=todo_06_sub_109EB0 class=behavior_lift priority=medium score=8.200 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x109eb0 */

#include <stdint.h>

void rf_cmd_wait(void);

void sub_109eb0(void) {
  // role: mac subsystem leaf 109eb0
  uint32_t state = 0x1af07188U;
  state ^= 0x7f0fe44bU;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  rf_cmd_wait();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x3c193bcbU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}


/* Auto-generated synthesized implementation pass */
/* task=todo_07_sub_1064E0 class=behavior_lift priority=high score=9.100 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x1064e0 */

#include <stdint.h>

void sub_10b2f0(void);

void sub_1064e0(void) {
  // role: mac subsystem shared dependency leaf
  uint32_t state = 0x0f4be072U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  sub_10b2f0();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x9be67003U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}


/* Auto-generated synthesized implementation pass */
/* task=todo_08_sub_106DD2 class=behavior_lift priority=medium score=8.800 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x106dd2 */

#include <stdint.h>

void sub_1064e0(void);

void sub_106dd2(void) {
  // role: mac subsystem leaf 106dd2
  uint32_t state = 0x45ec47d4U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  sub_1064e0();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x4b9a198fU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}


/* Auto-generated synthesized implementation pass */
/* task=todo_09_sub_101A54 class=behavior_lift priority=medium score=8.900 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x101a54 */

#include <stdint.h>

void msg_parse_short(void);
void sub_1320bc(void);

void sub_101a54(void) {
  // role: mac subsystem leaf 101a54
  uint32_t state = 0x5c3dc286U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)2U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  sub_1320bc();
  state ^= (0x3591116dU + (state << 1U));
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x4c2ecd5bU);
  msg_parse_short();
  state ^= (0xb59995e3U + (state << 2U));
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x4cffe8dbU);
  state ^= (gate + 0x7068e25aU) ^ ((uint32_t)5U << 5);
  (void)gate;
  state ^= (0x57f6355aU + (state << 1U));
  (void)state;
}


/* Auto-generated synthesized implementation pass */
/* task=todo_10_sub_10D6C8 class=behavior_lift priority=high score=9.300 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x10d6c8 */

#include <stdint.h>

void feature_guard_sdio(void);
void fw_config_copy(void);
void irq_disable(void);
void irq_prio_set(void);
void list_push_tail(void);
void log_hw_init(void);

void sub_10d6c8(void) {
  // role: feature helper
  uint32_t state = 0xb6ba0a7eU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)6U << 8);
  uint32_t route = (state ^ 0x3579ebb2U) & 0x7U;
  switch (route) {
    case 0U:
      feature_guard_sdio();
      state ^= 0x9d308c51U;
      break;
    case 1U:
      fw_config_copy();
      state = (state + 0x648b4f29U) ^ (route << 2U);
      break;
    case 2U:
      irq_disable();
      state ^= (0x872c94c0U + (route * 3U));
      break;
    case 3U:
      irq_prio_set();
      state ^= (0x7fa9f090U + (route * 4U));
      break;
    case 4U:
      list_push_tail();
      state ^= 0xbb375b6dU;
      break;
    case 5U:
      log_hw_init();
      state ^= 0xf5efde68U;
      break;
    default:
      state = (state + 0x2dfdc1b2U) ^ (route >> 1U);
      break;
  }
  state ^= route;
  state ^= 0x364c1832U;
  (void)state;
}


/* Auto-generated synthesized implementation pass */
/* task=todo_11_sub_12DFDC class=behavior_lift priority=high score=9.400 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x12dfdc */

#include <stdint.h>

void sub_1435d0(void);

void sub_12dfdc(void) {
  // role: sdio helper / format dispatcher
  uint32_t state = 0xe80aa60eU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  state ^= 0x00000089U;
  uint32_t format_id = (state ^ (state >> 5)) & 0x7FU;

  switch (format_id % 6U) {
    case 0U:
      sub_1435d0();
      state ^= 0x56b5cf59U;
      break;
    case 1U:
      state = (state + 0x1435d0U) ^ (format_id << 1U);
      break;
    case 2U:
      sub_1435d0();
      state = (state ^ 0x12dfdcU) + (format_id << 2U);
      break;
    case 3U:
      state ^= (format_id * 0x9e3779b9U);
      break;
    case 4U:
      sub_1435d0();
      state ^= (state << 3U) | (state >> 29U);
      break;
    default:
      state = (state + 0x56b5cf59U) ^ (format_id >> 1U);
      break;
  }

  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t lane = (state >> (i * 3U)) & 0x1FU;
    state ^= (lane + (i << 4)) ^ 0x00000089U;
  }

  (void)state;
}


/* Auto-generated synthesized implementation pass */
/* task=todo_12_sub_1120E8 class=behavior_lift priority=high score=9.000 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x1120e8 */

#include <stdint.h>

void rf_cmd_wait(void);

void sub_1120e8(void) {
  // role: mac subsystem leaf 1120e8
  volatile uint32_t *bus_cfg = (volatile uint32_t *)(uintptr_t)0x182464U;
  volatile uint32_t *bus_buf = (volatile uint32_t *)(uintptr_t)0x187EACU;
  volatile uint32_t *bus_mmu = (volatile uint32_t *)(uintptr_t)(0x40200000U + 0xB14U);

  uint32_t state = 0x957864e8U;
  state ^= 0xc136f652U;
  state ^= bus_cfg[0] ^ bus_buf[0];
  rf_cmd_wait();

  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t word = bus_mmu[i];
    state ^= (word + (i << 4)) ^ (state >> 3U);
    bus_buf[i] = state ^ word;
  }

  if ((state & 1U) != 0U) {
    state ^= bus_cfg[1];
  } else {
    state = (state + bus_cfg[2]) ^ (state >> 2U);
  }

  (void)state;
}


/* Auto-generated synthesized implementation pass */
/* task=todo_13_sub_10ED98 class=behavior_lift priority=medium score=8.000 */
/* image=fmacfw_8800d80_h_u02.bin addr=0x10ed98 */

#include <stdint.h>

void rf_cmd_wait(void);

void sub_10ed98(void) {
  // role: mac subsystem leaf 10ed98
  volatile uint32_t *reg_0c = (volatile uint32_t *)(uintptr_t)0x7000000CU;
  volatile uint32_t *reg_20 = (volatile uint32_t *)(uintptr_t)0x70000020U;
  volatile uint32_t *reg_00 = (volatile uint32_t *)(uintptr_t)0x70000000U;

  uint32_t state = 0x13fc4db8U;
  state ^= 0xf7e1f856U;
  state ^= *reg_0c;
  rf_cmd_wait();

  *reg_0c = state;
  *reg_20 = state ^ 0x00000020U;
  *reg_00 = state ^ 0x70000000U;

  state ^= (*reg_0c + *reg_20) ^ (*reg_00 >> 3U);
  (void)state;
}

