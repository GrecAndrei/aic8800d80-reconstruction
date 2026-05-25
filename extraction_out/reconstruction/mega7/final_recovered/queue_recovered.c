/* Auto-generated queue-path recovery addendum */
/* Recovered from the raw h_u02 helper at 0x121017C. */

#include <stdint.h>

void list_pop(void);

void sub_121017C(void) {
  /*
   * Raw role:
   *   - snapshot interrupt state
   *   - gate a queue-pop critical section
   *   - bump/decrement a small nesting counter
   *   - call the queue pop helper
   *
   * The original firmware uses PRIMASK/CPSID/CPSIE here. In the recovered
   * C slice we model that state through the same RAM words the body touches,
   * so the harness can still validate the observable side effects.
   */
  volatile uint32_t *irq_gate = (volatile uint32_t *)(uintptr_t)0x187F8CU;
  volatile uint32_t *irq_depth = (volatile uint32_t *)(uintptr_t)0x182560U;
  volatile uintptr_t *queue_head = (volatile uintptr_t *)(uintptr_t)0x187E38U;

  uint32_t primask = *irq_gate;
  if ((primask & 1U) == 0U) {
    *irq_gate = 1U;
  }

  ++*irq_depth;
  (void)*queue_head;
  list_pop();

  if (*irq_depth != 0U) {
    uint32_t gate = *irq_gate;
    --*irq_depth;
    if (*irq_depth == 0U && gate != 0U) {
      *irq_gate = 0U;
    }
  }
}
