# AIC8800D80 MMIO Register Dictionary

Auto-generated from the full LLM classification run (tools/mmio_classify.py).
Source: build/mmio/classifications.json — 2083 registers, 309 behavioral rules.

Conventions:
- **role**: config (write-once), status (read to check), clock (PLL/clk tree), data (FIFO/buffer),
  strobe (write self-clears), mask (field mask), irq (interrupt ctrl), unknown.
- **behavior**: poll (emulator holds not-ready until N reads), strobe (self-clears after N insns),
  echo (read returns last written). Applied only to dynamic-source registers at conf >= 0.4.
- **source**: dynamic = observed in firmware execution; static = sibling in a touched page (naming only).

## Page 0x4000

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40000000 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40000001 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40000006 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40000014 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40000015 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40000016 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000008e |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40000393 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40003420 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40003f8c |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40004034 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40004040 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40004050 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000608f |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000bd70 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000bf00 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000e7f1 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000e9c2 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000e9c5 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000e9cd |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000e9d2 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000ea03 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000ea42 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000ea43 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f001 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f011 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f020 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f022 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f023 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f040 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f042 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f04f |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f06f |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f080 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f3c1 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f420 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f440 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f44f |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f5a0 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f81c |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f829 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f88a |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f88e |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f898 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f8c9 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f8ca |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f8cb |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f8cc |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f8ce |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f8d8 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f8d9 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f8da |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f8db |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f8dc |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f8de |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000f9b4 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000fb03 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4000fb05 |  | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x4002

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40020000 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4002114c |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40021248 | unknown_0x40021248 | unknown |  | 0.0 | dynamic | 4 | 4 |
| 0x400212c8 | unknown_0x400212c8 | unknown |  | 0.0 | dynamic | 4 | 4 |
| 0x40024000 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40026822 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x400268da |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4002e9c3 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4002e9d5 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4002f80e |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4002f88d |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4002f8b8 |  | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x4003

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40030109 | unknown_rf_register_0x40030109 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40031ff4 |  | unknown |  | 0.0 | dynamic | 1 | 1 |
| 0x40031ff8 |  | unknown |  | 0.0 | dynamic | 3 | 0 |
| 0x40031ffa |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40031ffc |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40032000 | rf_cmd_data | data |  | 0.7 | dynamic | 4 | 2910 |
| 0x40032001 | unknown_rf_register_0x40032001 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40032004 |  | unknown |  | 0.0 | dynamic | 3 | 0 |
| 0x40032008 | rf_busy_status | status | poll ready=0x1 n=133 | 0.5 | dynamic | 535 | 0 |
| 0x4003200c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003200e |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032010 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032014 | rf_status | status | poll ready=0x1 n=266 | 0.5 | dynamic | 1130 | 0 |
| 0x40032018 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003201c |  | unknown |  | 0.0 | dynamic | 3 | 0 |
| 0x40032020 | rf_cmd_status | status | poll ready=0x1 n=1 | 0.5 | dynamic | 3710 | 3 |
| 0x40032021 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40032022 |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x40032024 | rf_chan_status | status | poll ready=0x40000 n=1 | 0.6 | dynamic | 14 | 0 |
| 0x40032025 | rf_status_0x400 | status | poll ready=0x400 n=1 | 0.3 | dynamic | 3 | 0 |
| 0x40032026 | rf_config | config |  | 0.5 | dynamic | 2 | 1 |
| 0x40032028 |  | unknown |  | 0.0 | dynamic | 6 | 0 |
| 0x40032029 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003202c |  | unknown |  | 0.0 | dynamic | 3 | 0 |
| 0x4003202d |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032030 |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x40032031 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032034 |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x40032035 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032037 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032038 |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x4003203b |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003203c |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x4003203f |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032040 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032043 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032044 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032047 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032048 |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x4003204b |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003204c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003204f |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032050 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032053 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032054 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032055 | rf_cmd_strobe | strobe | strobe n= | 0.3 | dynamic | 1 | 1 |
| 0x40032057 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032058 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032059 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003205c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003205d |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032060 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032061 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032064 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032068 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003206c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032070 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032074 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032078 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003207c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032080 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032084 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032088 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003208c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032090 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032094 | rf_echo_data | data |  | 0.4 | dynamic | 2 | 1 |
| 0x40032098 |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x4003209c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320a0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320a4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320a8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320ac |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320b0 |  | unknown |  | 0.0 | dynamic | 3 | 0 |
| 0x400320b4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320b8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320bc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320c0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320c4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320c8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320cc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320d0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320d4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320d8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320dc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320e0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320e4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320e8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320ec |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320f0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320f4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320f8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400320fc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032100 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032104 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032108 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003210c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032110 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032114 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032118 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003211c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032120 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032124 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032128 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003212c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032130 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032134 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032138 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003213c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032140 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032144 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032148 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003214c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032150 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032154 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032158 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003215c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032160 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032164 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032168 |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x4003216c |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x40032170 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032174 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032178 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003217c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032180 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032184 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032188 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003218c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032190 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032194 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032198 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003219c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321a0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321a4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321a8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321ac |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321b0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321b4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321b8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321bc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321c0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321c4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321c8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321cc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321d0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321d4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321d8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321dc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321e0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321e4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321e8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321ec |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321f0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321f4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321f8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400321fc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032200 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032204 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032208 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003220c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032210 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032214 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032218 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003221c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032220 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032224 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032228 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003222c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032230 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032234 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032238 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003223c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032240 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032244 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032248 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003224c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032250 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032254 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40032258 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003225c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4003404b |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40034f37 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40035000 | irq_event_trigger | strobe | strobe n= | 0.5 | dynamic | 0 | 12 |
| 0x40035004 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40035008 | rf_init_cfg | config |  | 0.6 | dynamic | 0 | 6 |
| 0x4003500c | rf_init_cfg | config |  | 0.6 | dynamic | 0 | 6 |
| 0x40035010 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40035018 | rf_indirect_data | data |  | 0.4 | dynamic | 15 | 15 |
| 0x4003501c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40035040 | sdio_transfer_status | status | poll ready=0x1 n=4 | 0.4 | dynamic | 24221 | 0 |
| 0x40035048 |  | unknown |  | 0.0 | dynamic | 3 | 0 |
| 0x4003504c | log_patch_status | status | poll ready=0x1 n=4 | 0.4 | dynamic | 1052 | 0 |
| 0x40035050 | radio_unlock_status | status | poll ready=0x100 n=4 | 0.5 | dynamic | 308 | 0 |
| 0x40035054 | rf_tx_status | status | poll ready=0x1 n=4 | 0.4 | dynamic | 1599 | 0 |
| 0x40035058 | efuse_read_status | status | poll ready=0x1 n=4 | 0.5 | dynamic | 1064 | 0 |
| 0x4003505c | rf_reg_write_status | status | poll ready=0x1 n=4 | 0.7 | dynamic | 18883 | 0 |
| 0x40035072 |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x40035074 |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x40035076 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40035078 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40035080 | rf_unknown_40035080 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40035084 | rf_unknown_40035084 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40035094 | rf_power_config | config |  | 0.7 | dynamic | 12 | 14 |
| 0x40035098 | rf_init_reset | config |  | 0.3 | dynamic | 0 | 3 |
| 0x400350e5 |  | unknown |  | 0.0 | dynamic | 0 | 1 |
| 0x400350e6 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x400350e8 |  | unknown |  | 0.0 | dynamic | 0 | 1 |
| 0x400350ea |  | unknown |  | 0.0 | dynamic | 0 | 1 |
| 0x40035100 | radio_unlock | config |  | 0.5 | dynamic | 0 | 14 |
| 0x40035104 | mac_status | status |  | 0.3 | dynamic | 8 | 0 |
| 0x40035108 |  | unknown |  | 0.0 | dynamic | 0 | 1 |
| 0x4003510c | mac_ctrl | config |  | 0.3 | dynamic | 0 | 21 |
| 0x40035110 | rf_unknown_40035110 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40035114 | sdio_dma_cfg | config |  | 0.5 | dynamic | 40 | 40 |
| 0x40035118 | sdio_dma_cfg2 | config |  | 0.5 | dynamic | 16 | 16 |
| 0x4003511c | mmio_status | status |  | 0.3 | dynamic | 8 | 0 |
| 0x40035240 | phy_rf_status | status | poll ready=0x1 n=1053 | 0.4 | dynamic | 1052 | 0 |
| 0x40035244 | rf_status | status | poll ready=0x1 n=7926 | 0.5 | dynamic | 7925 | 0 |
| 0x40035248 | phy_status | status | poll ready=0x1 n=8026 | 0.4 | dynamic | 8025 | 0 |
| 0x40035888 | rf_unknown_40035888 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40036813 | rf_unknown_40036813 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40036888 | rf_unknown_40036888 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40036890 | rf_unknown_40036890 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40038000 |  | unknown |  | 0.0 | dynamic | 0 | 2 |
| 0x40038004 | unknown_0x40038004 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4003800c |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x40038010 |  | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x40038030 | unknown_0x40038030 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4003ea40 | unknown_0x4003ea40 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4003f240 | unknown_0x4003f240 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4003f241 | unknown_0x4003f241 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4003f641 | unknown_0x4003f641 | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x4010

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40100000 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40100014 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40100016 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4010001e | rf_start_ctrl | config |  | 0.3 | dynamic | 0 | 5 |
| 0x40100024 | rf_clock_status | status |  | 0.3 | dynamic | 6 | 0 |
| 0x40100038 | rf_cmd_opcode | config |  | 0.4 | dynamic | 0 | 48 |
| 0x40103000 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40104000 | rf_msg_data | data |  | 0.4 | dynamic | 4 | 9 |
| 0x40104008 | rf_flag_reg | mask |  | 0.4 | dynamic | 8 | 17 |
| 0x4010400c | rf_msg_trigger | strobe | strobe n= | 0.4 | dynamic | 0 | 5 |
| 0x40104010 | rf_fault_status | status |  | 0.5 | dynamic | 4 | 0 |
| 0x40104034 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40104050 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40104843 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4010b000 | rf_flag_status | status |  | 0.5 | dynamic | 3 | 2 |
| 0x4010b004 | rf_bitmask_set | mask |  | 0.3 | dynamic | 1 | 1 |
| 0x4010b008 | rf_bitmask_clear | mask |  | 0.3 | dynamic | 2 | 2 |
| 0x4010c000 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4010d000 | rf_cmd_addr | config |  | 0.4 | dynamic | 0 | 34 |
| 0x4010d004 | rf_cmd_trigger | strobe | strobe n= | 0.3 | dynamic | 0 | 39 |
| 0x4010d008 | rf_cmd_data0 | data |  | 0.5 | dynamic | 46 | 47 |
| 0x4010d00c | rf_cmd_data1 | data |  | 0.5 | dynamic | 82 | 83 |
| 0x4010d010 | rf_hw_timer_ctrl | config |  | 0.3 | dynamic | 0 | 1 |
| 0x4010d01c | rf_busy_status | status | poll ready=0x1 n=4 | 0.3 | dynamic | 4886 | 0 |
| 0x4010e8bd |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4010f888 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4010f8c8 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4010f8c9 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4010f8d9 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4010f8da |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4010f8db |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4010ffff |  | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x4020

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40200000 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40200010 | rf_bus_arm_status | status |  | 0.6 | dynamic | 2116 | 8 |
| 0x40200014 | rf_bus_reset_status | status | poll ready=0xC0 n=88 | 0.6 | static+dynamic | 356 | 4 |
| 0x40200018 | rf_bus_status | status |  | 0.2 | dynamic | 8 | 0 |
| 0x40200804 | rf_bus_reset_cmd | strobe | strobe n= | 0.5 | dynamic | 8 | 8 |
| 0x40200900 | rf_bus_write2_status | status |  | 0.2 | dynamic | 6 | 0 |
| 0x40200908 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40200914 | rf_bus_mark | strobe | strobe n= | 0.2 | dynamic | 0 | 2 |
| 0x40200920 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40200b00 | rf_bus_write_status | status |  | 0.2 | dynamic | 8 | 0 |
| 0x40200b08 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40200b14 | rf_bus_mark2 | strobe | strobe n= | 0.2 | dynamic | 0 | 6 |
| 0x40200b20 | hw_event_flag | status |  | 0.5 | dynamic | 8 | 0 |
| 0x40200b24 | log_free_pool | unknown |  | 0.3 | dynamic | 4 | 4 |
| 0x40200c15 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40200e00 | rf_cmd_stop | strobe | strobe n= | 0.3 | dynamic | 8 | 8 |
| 0x40204033 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40204034 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40206e6f |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4020c100 | rf_bus_write_status1 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x4020f881 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4020f89c |  | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x4024

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40240004 | rf_status | status |  | 0.2 | dynamic | 8 | 0 |
| 0x4024000c |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240010 | rf_cmd_wait_status | strobe | strobe n= | 0.4 | dynamic | 1790 | 4 |
| 0x40240014 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240016 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240018 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4024001c | rf_msg_status | status |  | 0.2 | dynamic | 4 | 0 |
| 0x40240048 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4024004c | rf_field_ctrl | config |  | 0.5 | dynamic | 8 | 12 |
| 0x40240100 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240110 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240114 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240118 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240120 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240124 | rf_cmd_addr | config |  | 0.3 | dynamic | 0 | 8 |
| 0x40240134 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240140 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240144 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240148 | mbox_data0 | data |  | 0.3 | dynamic | 8 | 8 |
| 0x4024014c | mbox_data1 | data |  | 0.2 | dynamic | 0 | 8 |
| 0x40240150 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240154 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240160 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240168 | mbox_ctrl0 | config |  | 0.2 | dynamic | 4 | 4 |
| 0x4024016c | mbox_ctrl1 | config |  | 0.2 | dynamic | 4 | 4 |
| 0x40240170 | mbox_ptr | config |  | 0.2 | dynamic | 4 | 4 |
| 0x40240174 | mbox_len | config |  | 0.2 | dynamic | 4 | 4 |
| 0x40240188 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4024018c |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240190 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240194 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40240198 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4024019c | rf_afe_cfg_0 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x402401a0 | rf_afe_cfg_1 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x402401a4 | rf_afe_cfg_2 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x402401ac | rf_afe_cfg_3 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x402401b4 | rf_afe_cfg_4 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x402401b8 | rf_afe_cfg_5 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x402401bc | rf_afe_cfg_6 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x4024020c | rf_pll_cfg_0 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x40240210 | rf_pll_cfg_1 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x40240214 | rf_pll_cfg_2 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x40240218 | rf_pll_cfg_3 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x40241000 | rf_global_ctrl | config |  | 0.1 | dynamic | 0 | 0 |
| 0x40241050 | rf_timer_ctrl | config |  | 0.6 | dynamic | 6 | 6 |
| 0x40241a2e | rf_status_byte | config |  | 0.1 | dynamic | 0 | 0 |
| 0x40244034 | rf_tx_cfg | config |  | 0.1 | dynamic | 0 | 0 |
| 0x4024f240 | rf_fw_ctrl | config |  | 0.1 | dynamic | 0 | 0 |
| 0x4024f850 | rf_debug_0 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x4024f893 | rf_debug_1 | config |  | 0.1 | dynamic | 0 | 0 |
| 0x4024f8c9 | rf_debug_2 | config |  | 0.1 | dynamic | 0 | 0 |

## Page 0x4032

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40320004 | rf_status_04 | status |  | 0.2 | dynamic | 3 | 0 |
| 0x40320008 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320010 | rf_init_config_10 | config |  | 0.6 | dynamic | 1 | 8 |
| 0x40320014 | rf_init_config_14 | config |  | 0.6 | dynamic | 0 | 8 |
| 0x40320018 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4032001c | rf_init_config_1c | config |  | 0.6 | dynamic | 0 | 8 |
| 0x40320020 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320024 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4032002c | rf_clear_config_2c | config |  | 0.4 | dynamic | 0 | 8 |
| 0x40320034 | bt_doorbell | strobe | strobe n= | 0.6 | dynamic | 0 | 3 |
| 0x40320038 | mailbox_data | data |  | 0.5 | dynamic | 78 | 512 |
| 0x40320044 | rf_ctrl_data_44 | config |  | 0.3 | dynamic | 3 | 3 |
| 0x4032004c | message_data_4c | data |  | 0.5 | dynamic | 100 | 82 |
| 0x40320050 | rf_status_50 | status |  | 0.2 | dynamic | 3 | 0 |
| 0x40320054 | rf_mask_54 | mask |  | 0.3 | dynamic | 6 | 12 |
| 0x40320060 | rf_syscfg_60 | config |  | 0.6 | dynamic | 0 | 25 |
| 0x40320064 | rf_ctrl_64 | config |  | 0.3 | dynamic | 10 | 4 |
| 0x40320068 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4032006c | rf_ctrl_6c | config |  | 0.4 | dynamic | 10 | 10 |
| 0x40320070 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320074 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320078 | rf_cmd_strobe_78 | strobe | strobe n= | 0.3 | dynamic | 6 | 6 |
| 0x40320080 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4032008c |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320090 | rf_ctrl_90 | config |  | 0.4 | dynamic | 6 | 6 |
| 0x4032009c |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x403200a0 | rf_mac_status_a0 | status | poll ready=0x1500 n=104 | 0.4 | dynamic | 384 | 26 |
| 0x403200ac | rf_chan_table_0 | config |  | 0.6 | dynamic | 0 | 7 |
| 0x403200b0 | rf_chan_table_1 | config |  | 0.6 | dynamic | 0 | 7 |
| 0x403200b4 | rf_chan_table_2 | config |  | 0.6 | dynamic | 0 | 7 |
| 0x403200b8 | rf_chan_table_3 | config |  | 0.6 | dynamic | 0 | 7 |
| 0x403200bc | rf_chan_table_4 | config |  | 0.5 | dynamic | 0 | 10 |
| 0x403200c0 | rf_chan_table_data | config |  | 0.6 | dynamic | 0 | 10 |
| 0x403200c4 | rf_chan_table_cmd | strobe | strobe n= | 0.5 | dynamic | 2377 | 10 |
| 0x403200c8 | rf_chan_table_reg3 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x403200d8 | rf_chan_table_status | status | poll ready=0x1 n=6 | 0.5 | dynamic | 19 | 0 |
| 0x403200dc | rf_chan_table_clear | config |  | 0.3 | dynamic | 0 | 1 |
| 0x403200e4 | rf_bt_cfg0 | config |  | 0.6 | dynamic | 32 | 16 |
| 0x403200e8 | rf_bt_cfg1 | config |  | 0.6 | dynamic | 14 | 10 |
| 0x403200ec | rf_bt_cfg2 | config |  | 0.5 | dynamic | 16 | 8 |
| 0x403200f0 | rf_ctrl0 | config |  | 0.4 | dynamic | 11 | 11 |
| 0x403200f4 | rf_bt_cfg3 | config |  | 0.5 | dynamic | 16 | 12 |
| 0x403200f8 | rf_bt_cfg4 | config |  | 0.5 | dynamic | 10 | 6 |
| 0x403200fc | rf_cmd_strobe | strobe | strobe n= | 0.6 | dynamic | 4 | 4 |
| 0x40320100 | rf_bt_cfg5 | config |  | 0.5 | dynamic | 10 | 10 |
| 0x40320104 | rf_bt_cfg6 | config |  | 0.4 | dynamic | 16 | 8 |
| 0x4032010c | rf_fmac_cfg | config |  | 0.7 | dynamic | 32 | 32 |
| 0x40320118 | rf_fmac_reg2 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4032011c | log_tick_status | status |  | 0.3 | dynamic | 4 | 0 |
| 0x40320120 | phy_status | status | poll ready=0x1 n=192 | 0.7 | dynamic | 975 | 0 |
| 0x40320128 | phy_status2 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4032012c | rf_timer_load | config |  | 0.5 | dynamic | 0 | 3 |
| 0x40320130 | rf_timer_ctrl | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320134 | rf_timer_status | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320140 | rf_ana_cfg0 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320144 | rf_ana_cfg1 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320148 | rf_ana_cfg2 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320150 | rf_ana_cfg3 | config |  | 0.4 | dynamic | 0 | 2 |
| 0x40320154 | rf_ana_cfg4 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320158 | rf_ana_cfg5 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320200 | rf_indirect_status | status | poll ready=0x1825000 n=5 | 0.4 | dynamic | 21 | 4 |
| 0x40320204 | rf_indirect_data0 | config |  | 0.5 | dynamic | 18 | 10 |
| 0x40320208 | rf_indirect_data1 | config |  | 0.5 | dynamic | 16 | 10 |
| 0x4032020c | rf_indirect_cmd | strobe | strobe n= | 0.4 | dynamic | 20 | 10 |
| 0x40320210 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320220 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320224 | rf_state_reg | status |  | 0.5 | dynamic | 10 | 10 |
| 0x40320309 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320310 | wifi_mac_init_config | config |  | 0.5 | dynamic | 4 | 4 |
| 0x40320324 | rf_phy_config | config |  | 0.8 | dynamic | 30 | 33 |
| 0x40320350 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320400 | rf_init_flags | status |  | 0.6 | dynamic | 3 | 3 |
| 0x40320420 | wifi_mac_config_420 | config |  | 0.5 | dynamic | 4 | 4 |
| 0x40320428 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4032042c | wifi_mac_config_42c | config |  | 0.4 | dynamic | 16 | 16 |
| 0x40320434 | wifi_mac_config_434 | config |  | 0.5 | dynamic | 4 | 4 |
| 0x40320440 | wifi_mac_config_440 | config |  | 0.5 | dynamic | 4 | 4 |
| 0x40320444 | wifi_mac_config_444 | config |  | 0.5 | dynamic | 4 | 4 |
| 0x40320480 | wifi_mac_config_480 | config |  | 0.4 | dynamic | 4 | 4 |
| 0x40320500 | rf_status_500 | status | poll ready=0x1 n=8 | 0.5 | dynamic | 16 | 0 |
| 0x40320504 | rf_status_504 | status | poll ready=0x1 n=8 | 0.4 | dynamic | 16 | 0 |
| 0x40320510 | rf_status_510 | status |  | 0.3 | dynamic | 3 | 0 |
| 0x40320514 | rf_status_514 | status |  | 0.2 | dynamic | 2 | 0 |
| 0x40320518 | rf_status_518 | status |  | 0.2 | dynamic | 2 | 0 |
| 0x4032051c | rf_status_51c | status |  | 0.2 | dynamic | 2 | 0 |
| 0x40320520 | rf_status_520 | status |  | 0.2 | dynamic | 2 | 0 |
| 0x40320560 | rf_status_560 | status |  | 0.2 | dynamic | 2 | 0 |
| 0x40320564 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320580 | wifi_mac_config_580 | config |  | 0.4 | dynamic | 0 | 4 |
| 0x40320600 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320604 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320608 | wifi_mac_addr_608 | config |  | 0.4 | dynamic | 0 | 4 |
| 0x4032060c | wifi_mac_addr_60c | config |  | 0.4 | dynamic | 0 | 4 |
| 0x40320614 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320618 | wifi_mac_addr_618 | config |  | 0.4 | dynamic | 0 | 4 |
| 0x4032061c | wifi_mac_addr_61c | config |  | 0.4 | dynamic | 0 | 4 |
| 0x4032062c | wifi_mac_init_control | config |  | 0.4 | dynamic | 4 | 4 |
| 0x40320630 | rf_event_status | status |  | 0.5 | dynamic | 7 | 6 |
| 0x40320634 | rf_event_info | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40320638 | rf_event_type | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40320804 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40320950 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40322c0c |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40328040 | rf_msg_status | status |  | 0.4 | dynamic | 9 | 0 |
| 0x40328044 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40328048 | ipc_doorbell_status | status | poll ready=0x1 n=256 | 0.6 | dynamic | 515 | 5 |
| 0x40328050 | boot_flag_status | status |  | 0.5 | dynamic | 3955 | 15 |
| 0x40328060 | rf_status | status |  | 0.4 | dynamic | 4 | 0 |
| 0x40328064 | rf_control | config |  | 0.3 | dynamic | 0 | 4 |
| 0x40328068 | rf_config_flags | config |  | 0.5 | dynamic | 20 | 16 |
| 0x4032806c | rf_link_status | status |  | 0.6 | dynamic | 15 | 0 |
| 0x40328070 | rf_control_cfg | config |  | 0.5 | dynamic | 1 | 29 |
| 0x40328074 | rf_config_status | config |  | 0.5 | dynamic | 57 | 41 |
| 0x40328078 | phy_status | status |  | 0.4 | dynamic | 13 | 0 |
| 0x4032807c | rf_control_write | config |  | 0.4 | dynamic | 1 | 22 |
| 0x40328080 | rf_config_flags2 | config |  | 0.5 | dynamic | 26 | 23 |
| 0x40328084 | rf_status2 | status |  | 0.4 | dynamic | 4 | 0 |
| 0x40328088 | rf_flag_set | config |  | 0.5 | dynamic | 0 | 28 |
| 0x4032808c | fw_flag_status | status | poll ready=0x1 n=6 | 0.5 | dynamic | 56 | 34 |
| 0x40328090 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40328094 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40328098 | rf_init_reg | config |  | 0.4 | dynamic | 3 | 6 |
| 0x403280a4 | rf_reg_init_cfg | config |  | 0.5 | dynamic | 12 | 8 |
| 0x403280a8 | rf_reg_init_cfg2 | config |  | 0.5 | dynamic | 8 | 8 |
| 0x40328160 | rf_event_config | config |  | 0.4 | dynamic | 0 | 1 |
| 0x40328164 | rf_event_control | config |  | 0.3 | dynamic | 1 | 1 |
| 0x4032816c | rf_event_busy | status | poll ready=0x0 n=191 | 0.4 | dynamic | 191 | 1 |
| 0x40328180 | rf_subcmd_flag_set | config |  | 0.5 | dynamic | 0 | 23 |
| 0x40328184 | rf_event_flag_set | config |  | 0.4 | dynamic | 0 | 13 |
| 0x40328188 | rf_event_status | status | poll ready=0x1 n=8 | 0.4 | dynamic | 30 | 0 |
| 0x4032818c | rf_status0 | status |  | 0.3 | dynamic | 3 | 0 |
| 0x40328198 | rf_status1 | status |  | 0.1 | dynamic | 0 | 0 |
| 0x4032819c | rf_status2 | status |  | 0.3 | dynamic | 2 | 0 |
| 0x403281a0 | rf_status3 | status |  | 0.3 | dynamic | 2 | 0 |
| 0x403281a4 | rf_status4 | status |  | 0.3 | dynamic | 2 | 0 |
| 0x403281a8 | rf_status5 | status |  | 0.3 | dynamic | 2 | 0 |
| 0x403281ac | rf_config0 | config |  | 0.3 | dynamic | 0 | 6 |
| 0x403281c8 | fmac_cfg0 | config |  | 0.3 | dynamic | 0 | 8 |
| 0x403281cc | fmac_cfg1 | config |  | 0.3 | dynamic | 0 | 8 |
| 0x403281d0 | fmac_cmd_data | data |  | 0.4 | dynamic | 9 | 16 |
| 0x403281d4 | fmac_cmd_status | status |  | 0.3 | dynamic | 10 | 8 |
| 0x403281d8 | fmac_cfg2 | config |  | 0.3 | dynamic | 0 | 8 |
| 0x403281dc | fmac_cfg3 | config |  | 0.3 | dynamic | 0 | 8 |
| 0x403281e0 | fmac_data1 | data |  | 0.3 | dynamic | 6 | 11 |
| 0x403281e4 | fmac_data2 | data |  | 0.3 | dynamic | 9 | 8 |
| 0x403281e8 | fmac_cmd_trigger | strobe | strobe n= | 0.3 | dynamic | 0 | 8 |
| 0x40328330 | rf_status6 | status |  | 0.1 | dynamic | 0 | 0 |
| 0x40328334 | rf_status7 | status |  | 0.3 | dynamic | 2 | 0 |
| 0x40328358 | rf_status8 | status |  | 0.1 | dynamic | 0 | 0 |
| 0x4032835c | rf_status9 | status |  | 0.1 | dynamic | 0 | 0 |
| 0x40328360 | rf_status10 | status |  | 0.1 | dynamic | 0 | 0 |
| 0x40328364 | rf_status11 | status |  | 0.1 | dynamic | 0 | 0 |
| 0x40328524 | rf_status12 | status |  | 0.1 | dynamic | 0 | 0 |
| 0x40328528 | rf_status13 | status |  | 0.3 | dynamic | 4 | 0 |
| 0x4032852c | rf_status14 | status |  | 0.3 | dynamic | 4 | 0 |
| 0x40328530 | rf_status15 | status |  | 0.3 | dynamic | 4 | 0 |
| 0x40328534 | rf_status16 | status |  | 0.3 | dynamic | 4 | 0 |
| 0x40328538 | rf_status17 | status |  | 0.1 | dynamic | 0 | 0 |
| 0x4032853c | rf_status18 | status |  | 0.3 | dynamic | 4 | 0 |
| 0x40328540 | rf_status19 | status |  | 0.3 | dynamic | 4 | 0 |
| 0x40328564 | unknown_40328564 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40328568 | unknown_40328568 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40328808 | unknown_40328808 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4032f853 | unknown_4032f853 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4032f890 | unknown_4032f890 | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x4033

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40330000 | chip_info_status | status | poll ready=0x1 n=6 | 0.5 | dynamic | 194 | 0 |
| 0x4033003c | chip_info_data | status |  | 0.35 | dynamic | 22 | 0 |
| 0x40330054 | unknown_0x40330054 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033005c | unknown_0x4033005c | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40330304 | unknown_0x40330304 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40330320 | unknown_0x40330320 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40330800 | crypto_hw_mode_select | config |  | 0.6 | dynamic | 4 | 11 |
| 0x40330804 | unknown_0x40330804 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40330820 | unknown_0x40330820 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40330824 | unknown_0x40330824 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40330830 | hardware_status_word_00 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330834 | hardware_status_word_01 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330838 | hardware_status_word_02 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x4033083c | hardware_status_word_03 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330840 | hardware_status_word_04 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330844 | hardware_status_word_05 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330848 | hardware_status_word_06 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x4033084c | hardware_status_word_07 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330850 | hardware_status_word_08 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330854 | hardware_status_word_09 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330858 | hardware_status_word_10 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x4033085c | hardware_status_word_11 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330860 | hardware_status_word_12 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330864 | hardware_status_word_13 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330868 | hardware_status_word_14 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x4033086c | hardware_status_word_15 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330870 | hardware_status_word_16 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330874 | hardware_status_word_17 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330878 | hardware_status_word_18 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x4033087c | hardware_status_word_19 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330880 | hardware_status_word_20 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330884 | hardware_status_word_21 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x40330888 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4033088c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330890 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330894 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330898 | data_register | data |  | 0.3 | dynamic | 10 | 9 |
| 0x4033089c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308a0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308a4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308a8 | config_register | config |  | 0.4 | dynamic | 1 | 3 |
| 0x403308ac | config_register | config |  | 0.4 | dynamic | 1 | 3 |
| 0x403308b0 | config_register | config |  | 0.4 | dynamic | 1 | 3 |
| 0x403308b4 | config_register | config |  | 0.4 | dynamic | 1 | 3 |
| 0x403308b8 | config_register | config |  | 0.4 | dynamic | 1 | 3 |
| 0x403308bc | config_register | config |  | 0.4 | dynamic | 1 | 3 |
| 0x403308c0 | data_register | data |  | 0.6 | dynamic | 4 | 3 |
| 0x403308c4 | config_register | config |  | 0.4 | dynamic | 4 | 6 |
| 0x403308c8 | config_register | config |  | 0.4 | dynamic | 4 | 6 |
| 0x403308cc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308d0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308d4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308d8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308dc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308e0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308e4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308e8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308ec |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308f0 | status_register | status |  | 0.3 | dynamic | 4 | 0 |
| 0x403308f4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308f8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403308fc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330900 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330904 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330908 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4033090c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330910 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330914 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330918 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4033091c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330920 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330924 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330928 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4033092c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330930 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330934 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330938 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4033093c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330940 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330944 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330948 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4033094c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330950 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330954 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330958 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4033095c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330960 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330964 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330968 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4033096c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330970 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330974 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330978 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4033097c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330980 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330984 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330988 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4033098c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330990 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330994 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330998 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4033099c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309a0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309a4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309a8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309ac |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309b0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309b4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309b8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309bc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309c0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309c4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309c8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309cc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309d0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309d4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309d8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309dc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309e0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309e4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309e8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309ec |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309f0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309f4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309f8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403309fc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a00 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a04 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a08 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a0c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a10 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a14 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a18 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a1c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a20 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a24 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a28 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a2c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a30 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a34 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a38 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a3c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a40 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a44 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a48 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a4c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a50 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a54 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a58 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a5c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a60 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a64 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a68 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a6c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a70 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a74 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a78 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a7c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a80 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a84 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a88 | sub_10397C_ro_0xa88 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330a8c | sub_10397C_ro_0xa8c | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330c60 | crypto_table_init_ro_0xc60 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330c64 | crypto_table_init_ro_0xc64 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330c68 | crypto_table_init_ro_0xc68 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330c6c | crypto_table_init_ro_0xc6c | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330c70 | crypto_table_init_ro_0xc70 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330c74 | crypto_table_init_ro_0xc74 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330c78 | crypto_table_init_ro_0xc78 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330c7c | crypto_table_init_ro_0xc7c | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330c80 | crypto_table_init_ro_0xc80 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330c84 | crypto_table_init_ro_0xc84 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330c88 | crypto_table_init_ro_0xc88 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40330c8c | crypto_table_init_ro_0xc8c | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4033682b | static_ref_0x4033682b | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40339929 | static_ref_0x40339929 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033992b | static_ref_0x4033992b | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033992d | static_ref_0x4033992d | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033992f | static_ref_0x4033992f | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033a000 | clock_gate_ctrl_0 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a004 | clock_gate_ctrl_1 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a008 | clock_gate_ctrl_2 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a00c | clock_gate_ctrl_3 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a010 | clock_gate_ctrl_4 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a014 | clock_gate_ctrl_5 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a018 | clock_gate_ctrl_6 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a01c | clock_gate_ctrl_7 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a020 | clock_gate_ctrl_8 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a024 | clock_gate_ctrl_9 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a028 | clock_gate_ctrl_10 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a02c | clock_gate_ctrl_11 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a030 | clock_gate_ctrl_12 | clock |  | 0.9 | dynamic | 0 | 9 |
| 0x4033a034 | clock_gate_ctrl_034 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a038 | clock_gate_ctrl_038 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a03c | clock_gate_ctrl_03c | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a040 | clock_gate_ctrl_040 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a044 | clock_gate_ctrl_044 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a048 | clock_gate_ctrl_048 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a04c | clock_gate_ctrl_04c | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a050 | clock_gate_ctrl_050 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a054 | clock_gate_ctrl_054 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a058 | clock_gate_ctrl_058 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a05c | clock_gate_ctrl_05c | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a060 | clock_gate_ctrl_060 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a064 | clock_gate_ctrl_064 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a068 | clock_gate_ctrl_068 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a06c | clock_gate_ctrl_06c | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a070 | clock_gate_ctrl_070 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a074 | clock_gate_ctrl_074 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a078 | clock_gate_ctrl_078 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a07c | clock_gate_ctrl_07c | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a080 | clock_gate_ctrl_080 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a084 | clock_gate_ctrl_084 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a088 | clock_gate_ctrl_088 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a08c | clock_gate_ctrl_08c | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a090 | clock_gate_ctrl_090 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a094 | clock_gate_ctrl_094 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a098 | clock_gate_ctrl_098 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a09c | clock_gate_ctrl_09c | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0a0 | clock_gate_ctrl_0a0 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0a4 | clock_gate_ctrl_0a4 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0a8 | clock_gate_ctrl_0a8 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0ac | clock_gate_ctrl_0ac | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0b0 | clock_gate_ctrl_0b0 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0b4 | clock_gate_ctrl_00 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0b8 | clock_gate_ctrl_01 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0bc | clock_gate_ctrl_02 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0c0 | clock_gate_ctrl_03 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0c4 | clock_gate_ctrl_04 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0c8 | clock_gate_ctrl_05 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0cc | clock_gate_ctrl_06 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0d0 | clock_gate_ctrl_07 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0d4 | clock_gate_ctrl_08 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0d8 | clock_gate_ctrl_09 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0dc | clock_gate_ctrl_10 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0e0 | clock_gate_ctrl_11 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0e4 | clock_gate_ctrl_12 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0e8 | clock_gate_ctrl_13 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0ec | clock_gate_ctrl_14 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0f0 | clock_gate_ctrl_15 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0f4 | clock_gate_ctrl_16 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0f8 | clock_gate_ctrl_17 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a0fc | clock_gate_ctrl_18 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a100 | clock_gate_ctrl_19 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a104 | clock_gate_ctrl_20 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a108 | clock_gate_ctrl_21 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a10c | clock_gate_ctrl_22 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a110 | clock_gate_ctrl_23 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a114 | clock_gate_ctrl_24 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a118 | clock_gate_ctrl_25 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a11c | clock_gate_ctrl_26 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a120 | clock_gate_ctrl_27 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a124 | clock_gate_ctrl_28 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a128 | clock_gate_ctrl_29 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a12c | clock_gate_ctrl_30 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a130 | clock_gate_ctrl_31 | clock |  | 0.8 | dynamic | 0 | 9 |
| 0x4033a134 | clock_gate_ctrl_134 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a138 | clock_gate_ctrl_138 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a13c | clock_gate_ctrl_13c | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a140 | clock_gate_ctrl_140 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a144 | clock_gate_ctrl_144 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a148 | clock_gate_ctrl_148 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a14c | clock_gate_ctrl_14c | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a150 | clock_gate_ctrl_150 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a154 | clock_gate_ctrl_154 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a158 | clock_gate_ctrl_158 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a15c | clock_gate_ctrl_15c | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a160 | clock_gate_ctrl_160 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a164 | clock_gate_ctrl_164 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a168 | clock_gate_ctrl_168 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a16c | clock_gate_ctrl_16c | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a170 | clock_gate_ctrl_170 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a174 | clock_gate_ctrl_174 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a178 | clock_gate_ctrl_178 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a17c | clock_gate_ctrl_17c | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a180 | clock_gate_ctrl_180 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a184 | clock_gate_ctrl_184 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a188 | clock_gate_ctrl_188 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a18c | clock_gate_ctrl_18c | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a190 | clock_gate_ctrl_190 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a194 | clock_gate_ctrl_194 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a198 | clock_gate_ctrl_198 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a19c | clock_gate_ctrl_19c | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1a0 | clock_gate_ctrl_1a0 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1a4 | clock_gate_ctrl_1a4 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1a8 | clock_gate_ctrl_1a8 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1ac | clock_gate_ctrl_1ac | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1b0 | clock_gate_ctrl_1b0 | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1b4 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1b8 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1bc | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1c0 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1c4 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1c8 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1cc | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1d0 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1d4 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1d8 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1dc | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1e0 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1e4 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1e8 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1ec | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1f0 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1f4 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1f8 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 9 |
| 0x4033a1fc | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 8 |
| 0x4033a200 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 8 |
| 0x4033a204 | clock_gate_cfg | clock |  | 0.7 | dynamic | 0 | 8 |
| 0x4033b080 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033b100 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033b104 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033b198 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033b20c |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033b300 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033b390 | clock_gate_control | clock |  | 0.6 | dynamic | 18 | 18 |
| 0x4033b3ac | rf_power_control | config |  | 0.5 | dynamic | 83 | 83 |
| 0x4033b3b0 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033b3b4 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033b3c0 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033b3d4 | rf_tx_power_cfg | config |  | 0.6 | dynamic | 82 | 82 |
| 0x4033b414 | rf_calib_ctrl | config |  | 0.55 | dynamic | 4 | 4 |
| 0x4033b41c | rf_irq_status | status |  | 0.55 | dynamic | 2 | 0 |
| 0x4033b420 | rf_irq_clear | strobe |  | 0.5 | dynamic | 0 | 4 |
| 0x4033b610 | rf_phy_mode_cfg | config |  | 0.55 | dynamic | 16 | 16 |
| 0x4033c040 | rf_calib_cfg0 | config |  | 0.45 | dynamic | 3 | 3 |
| 0x4033c044 | rf_calib_cfg1 | config |  | 0.45 | dynamic | 1 | 1 |
| 0x4033f832 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033f85a |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4033f85b |  | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x4034

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40340008 | reg_40008 | unknown |  | 0.0 | dynamic | 4 | 4 |
| 0x40340010 | crypto_clk_reset_ctrl | clock |  | 0.7 | dynamic | 110 | 82 |
| 0x40340014 | ipc_mailbox_40014 | data |  | 0.2 | dynamic | 0 | 0 |
| 0x40340018 | ipc_doorbell | status |  | 0.8 | dynamic | 6 | 14 |
| 0x4034001c | ipc_mailbox_4001c | data |  | 0.2 | dynamic | 0 | 0 |
| 0x4034006c | hw_config_init_ctrl | config |  | 0.6 | dynamic | 0 | 4 |
| 0x40341000 | syscfg_init_ctrl | config |  | 0.6 | dynamic | 1 | 1 |
| 0x40341080 | rf_cmd_status_80 | status |  | 0.4 | dynamic | 1 | 0 |
| 0x40341084 | rf_cmd_status_84 | status |  | 0.4 | dynamic | 1 | 0 |
| 0x403410a0 | bit_modify_ctrl_a0 | config |  | 0.6 | dynamic | 5 | 4 |
| 0x403410a4 | status_a4 | status |  | 0.3 | dynamic | 1 | 0 |
| 0x403410a8 | status_a8 | status |  | 0.4 | dynamic | 4 | 0 |
| 0x403410ac | status_ac | status |  | 0.2 | dynamic | 0 | 0 |
| 0x403410b0 | read_quad_b0 | status |  | 0.4 | dynamic | 4 | 0 |
| 0x403410b4 | read_quad_b4 | status |  | 0.4 | dynamic | 4 | 0 |
| 0x403410b8 | read_quad_b8 | status |  | 0.4 | dynamic | 4 | 0 |
| 0x403410bc | read_quad_bc | status |  | 0.4 | dynamic | 4 | 0 |
| 0x40341424 | chip_info_status | status |  | 0.7 | dynamic | 7 | 0 |
| 0x40342000 | crypto_mode_ctrl | config |  | 0.7 | dynamic | 0 | 11 |
| 0x40342004 | crypto_mode_select | config |  | 0.8 | dynamic | 4 | 16 |
| 0x40342008 | crypto_hw_config | config |  | 0.8 | dynamic | 16 | 16 |
| 0x40342010 | crypto_config_42010 | config |  | 0.2 | dynamic | 0 | 0 |
| 0x40342014 | crypto_config_42014 | config |  | 0.2 | dynamic | 0 | 0 |
| 0x40342018 | crypto_config_42018 | config |  | 0.2 | dynamic | 0 | 0 |
| 0x4034201c | crypto_config_4201c | config |  | 0.2 | dynamic | 0 | 0 |
| 0x40342024 | adc_capture_ctrl | config |  | 0.8 | dynamic | 16 | 16 |
| 0x4034202c | crypto_hw_ctrl | config |  | 0.8 | dynamic | 57 | 53 |
| 0x40342030 | rf_bus_reset | clock |  | 0.6 | dynamic | 12 | 8 |
| 0x40342034 | crypto_reset_seq_ctrl | clock |  | 0.5 | dynamic | 0 | 8 |
| 0x4034204c | crypto_config_4c | config |  | 0.5 | dynamic | 4 | 4 |
| 0x40342054 | crypto_status_54 | status |  | 0.2 | dynamic | 0 | 0 |
| 0x40342058 | crypto_status_58 | status |  | 0.2 | dynamic | 0 | 0 |
| 0x4034205c | rf_phy_ctrl | config |  | 0.6 | dynamic | 10 | 10 |
| 0x40342060 | rf_aux_config | config |  | 0.4 | dynamic | 1 | 1 |
| 0x40342064 | rf_phy_aux_ctrl | config |  | 0.5 | dynamic | 3 | 3 |
| 0x40342068 | rf_aux_config_clear | config |  | 0.3 | dynamic | 0 | 1 |
| 0x4034206c | crypto_rf_calib_ctrl | config |  | 0.6 | dynamic | 44 | 44 |
| 0x40342074 | crypto_calib_cmd | strobe | strobe n= | 0.35 | dynamic | 4 | 4 |
| 0x40342078 | crypto_rf_clear_ctrl | config |  | 0.5 | dynamic | 8 | 8 |
| 0x4034207c | rf_phy_reg_7c | config |  | 0.15 | dynamic | 0 | 0 |
| 0x40342084 | rf_phy_reg_84 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x40342088 | rf_phy_reg_88 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x403420c8 | crypto_hw_ctrl | config |  | 0.7 | dynamic | 64 | 64 |
| 0x403420cc | crypto_sram_clear_ctrl | config |  | 0.6 | dynamic | 156 | 156 |
| 0x403420d0 | crypto_sram_clear_data | config |  | 0.5 | dynamic | 156 | 156 |
| 0x403420d4 | crypto_rf_tune_cfg | config |  | 0.6 | dynamic | 151 | 151 |
| 0x403420e0 | crypto_rf_reg_e0 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x403420e4 | crypto_rf_reg_e4 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x403420e8 | crypto_rf_reg_e8 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x403420ec | crypto_rf_reg_ec | config |  | 0.15 | dynamic | 0 | 0 |
| 0x403420f0 | crypto_rf_reg_f0 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x403420f4 | crypto_rf_reg_f4 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x40342148 | fmac_hw_setup_cmd | strobe | strobe n= | 0.3 | dynamic | 4 | 4 |
| 0x40342164 | param_check_reg | config |  | 0.4 | dynamic | 2 | 1 |
| 0x40342170 | rf_calib_reg_170 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x40342180 | crypto_rf_common_ctrl | config |  | 0.5 | dynamic | 4 | 4 |
| 0x40342184 | mac_init_cfg | config |  | 0.25 | dynamic | 0 | 4 |
| 0x403421d4 | rf_calib_ctrl | config |  | 0.65 | dynamic | 388 | 194 |
| 0x403421d8 | rf_calib_status | status | poll ready=0x1 n=97 | 0.5 | dynamic | 194 | 0 |
| 0x403421dc | rf_calib_enable | config |  | 0.6 | dynamic | 8 | 8 |
| 0x403421e8 | rf_calib_aux | config |  | 0.6 | dynamic | 4 | 4 |
| 0x40342200 | mac_init_status | status |  | 0.3 | dynamic | 8 | 0 |
| 0x40342204 | rf_config_reg_204 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x4034220c | rf_chan_status | status |  | 0.3 | dynamic | 8 | 0 |
| 0x40342210 | unknown_40342210 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40342214 | unknown_40342214 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40342218 | unknown_40342218 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40342228 | rf_crypto_status | status |  | 0.4 | dynamic | 16 | 0 |
| 0x40342248 | fmac_control | config |  | 0.5 | dynamic | 14 | 25 |
| 0x4034224c | crypto_control | config |  | 0.6 | dynamic | 22 | 22 |
| 0x4034226c | clock_gate_control | clock |  | 0.6 | dynamic | 20 | 16 |
| 0x40342270 | unknown_40342270 | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40342274 | crypto_dma_addr | config |  | 0.4 | dynamic | 292 | 288 |
| 0x40342278 | rf_chan_param | config |  | 0.4 | dynamic | 16 | 8 |
| 0x4034227c | ipc_doorbell | strobe | strobe n= | 0.4 | dynamic | 8 | 8 |
| 0x40342280 | crypto_command | strobe | strobe n= | 0.4 | dynamic | 0 | 28 |
| 0x403422c4 | crypto_key_config | config |  | 0.5 | dynamic | 24 | 24 |
| 0x403422c8 | unknown_403422c8 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40342400 | bt_bd_addr_0 | config |  | 0.3 | dynamic | 0 | 17 |
| 0x40342404 | bt_bd_addr_1 | config |  | 0.3 | dynamic | 2 | 14 |
| 0x40342408 | bt_bd_addr_2 | config |  | 0.3 | dynamic | 0 | 14 |
| 0x4034240c | bt_bd_addr_3 | config |  | 0.3 | dynamic | 0 | 14 |
| 0x40342410 | bt_bd_addr_4 | config |  | 0.3 | dynamic | 0 | 14 |
| 0x40342414 | bt_bd_addr_5 | config |  | 0.3 | dynamic | 0 | 14 |
| 0x40342418 | bt_bd_addr_6 | config |  | 0.3 | dynamic | 0 | 12 |
| 0x4034241c | bt_bd_addr_7 | config |  | 0.3 | dynamic | 0 | 11 |
| 0x40342420 | bt_bd_addr_8 | config |  | 0.3 | dynamic | 0 | 11 |
| 0x40342424 | bt_bd_addr_9 | config |  | 0.3 | dynamic | 0 | 11 |
| 0x40342428 | bt_bd_addr_10 | config |  | 0.3 | dynamic | 0 | 11 |
| 0x4034242c | bt_bd_addr_11 | config |  | 0.3 | dynamic | 0 | 11 |
| 0x40342430 | bt_bd_addr_12 | config |  | 0.3 | dynamic | 0 | 11 |
| 0x40342434 | bt_bd_addr_13 | config |  | 0.3 | dynamic | 0 | 11 |
| 0x40342438 | bt_bd_addr_14 | config |  | 0.3 | dynamic | 0 | 11 |
| 0x4034243c | bt_bd_addr_15 | config |  | 0.3 | dynamic | 0 | 11 |
| 0x40342440 | bt_bd_addr_16 | config |  | 0.3 | dynamic | 0 | 14 |
| 0x40342444 | bt_bd_addr_17 | config |  | 0.3 | dynamic | 0 | 14 |
| 0x40342448 | rf_cfg_00 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x4034244c | rf_cfg_01 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x40342450 | rf_cfg_02 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x40342454 | rf_cfg_03 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x40342458 | rf_cfg_04 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x4034245c | rf_cfg_05 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x40342460 | rf_cfg_06 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x40342464 | rf_cfg_07 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x40342468 | rf_cfg_08 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x4034246c | rf_cfg_09 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x40342470 | rf_cfg_10 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x40342474 | rf_cfg_11 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x40342478 | rf_cfg_12 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x4034247c | rf_cfg_13 | config |  | 0.6 | dynamic | 0 | 14 |
| 0x40342480 | rf_cfg_14 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x40342484 | rf_cfg_15 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x40342488 | rf_cfg_16 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x4034248c | rf_cfg_17 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x40342490 | rf_cfg_18 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x40342494 | rf_cfg_19 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x40342498 | rf_cfg_20 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x4034249c | rf_cfg_21 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x403424a0 | rf_cfg_22 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x403424a4 | rf_cfg_23 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x403424a8 | rf_cfg_24 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x403424ac | rf_cfg_25 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x403424b0 | rf_cfg_26 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x403424b4 | rf_cfg_27 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x403424b8 | rf_cfg_28 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x403424bc | rf_cfg_29 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x403424c0 | rf_cfg_30 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x403424c4 | rf_cfg_31 | config |  | 0.6 | dynamic | 0 | 11 |
| 0x403424c8 | rf_phy_cfg_00 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424cc | rf_phy_cfg_01 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424d0 | rf_phy_cfg_02 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424d4 | rf_phy_cfg_03 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424d8 | rf_phy_cfg_04 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424dc | rf_phy_cfg_05 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424e0 | rf_phy_cfg_06 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424e4 | rf_phy_cfg_07 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424e8 | rf_phy_cfg_08 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424ec | rf_phy_cfg_09 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424f0 | rf_phy_cfg_10 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424f4 | rf_phy_cfg_11 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424f8 | rf_phy_cfg_12 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x403424fc | rf_phy_cfg_13 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342500 | rf_phy_cfg_14 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342504 | rf_phy_cfg_15 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342508 | rf_phy_cfg_16 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x4034250c | rf_phy_cfg_17 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342510 | rf_phy_cfg_18 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342514 | rf_phy_cfg_19 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342518 | rf_phy_cfg_20 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x4034251c | rf_phy_cfg_21 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342520 | rf_phy_cfg_22 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342524 | rf_phy_cfg_23 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342528 | rf_phy_cfg_24 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x4034252c | rf_phy_cfg_25 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342530 | rf_phy_cfg_26 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342534 | rf_phy_cfg_27 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342538 | rf_phy_cfg_28 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x4034253c | rf_phy_cfg_29 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342540 | rf_phy_cfg_30 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342544 | rf_phy_cfg_31 | config |  | 0.8 | dynamic | 0 | 11 |
| 0x40342548 | rf_cal_table_entry_0 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x4034254c | rf_cal_table_entry_1 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x40342550 | rf_cal_table_entry_2 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x40342554 | rf_cal_table_entry_3 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x40342558 | rf_cal_table_entry_4 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x4034255c | rf_cal_table_entry_5 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x40342560 | rf_cal_table_entry_6 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x40342564 | rf_cal_table_entry_7 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x40342568 | rf_cal_table_entry_8 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x4034256c | rf_cal_table_entry_9 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x40342570 | rf_cal_table_entry_10 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x40342574 | rf_cal_table_entry_11 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x40342578 | rf_cal_table_entry_12 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x4034257c | rf_cal_table_entry_13 | config |  | 0.5 | dynamic | 0 | 11 |
| 0x403425d0 | unknown_static_ref | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40342600 | crypto_key_buf_0 | data |  | 0.4 | dynamic | 0 | 21 |
| 0x40342604 | crypto_key_buf_1 | data |  | 0.4 | dynamic | 0 | 21 |
| 0x40342608 | crypto_key_buf_2 | data |  | 0.4 | dynamic | 0 | 21 |
| 0x4034260c | crypto_key_buf_3 | data |  | 0.4 | dynamic | 0 | 21 |
| 0x40342610 | crypto_key_buf_4 | data |  | 0.4 | dynamic | 0 | 21 |
| 0x40342614 | crypto_key_buf_5 | data |  | 0.4 | dynamic | 0 | 21 |
| 0x40342618 | crypto_key_buf_6 | data |  | 0.4 | dynamic | 0 | 21 |
| 0x4034261c | crypto_key_buf_7 | data |  | 0.4 | dynamic | 0 | 21 |
| 0x40342620 | crypto_key_buf_8 | data |  | 0.4 | dynamic | 0 | 21 |
| 0x40342624 | crypto_key_buf_9 | data |  | 0.4 | dynamic | 0 | 21 |
| 0x40342628 | crypto_key_buf_10 | data |  | 0.4 | dynamic | 0 | 21 |
| 0x4034262c | crypto_key_buf_11 | data |  | 0.4 | dynamic | 0 | 21 |
| 0x40342630 | crypto_key_buf_12 | data |  | 0.4 | dynamic | 0 | 20 |
| 0x40342634 | crypto_key_buf_13 | data |  | 0.4 | dynamic | 0 | 20 |
| 0x40342638 | crypto_key_buf_14 | data |  | 0.4 | dynamic | 0 | 20 |
| 0x4034263c | crypto_key_buf_15 | data |  | 0.4 | dynamic | 0 | 20 |
| 0x40342640 | crypto_key_buf_16 | data |  | 0.4 | dynamic | 0 | 20 |
| 0x40342644 | trace_msg_data_0 | data |  | 0.55 | dynamic | 0 | 20 |
| 0x40342648 | trace_msg_data_1 | data |  | 0.55 | dynamic | 0 | 20 |
| 0x4034264c | trace_msg_data_2 | data |  | 0.55 | dynamic | 0 | 20 |
| 0x40342650 | trace_msg_data_3 | data |  | 0.55 | dynamic | 0 | 20 |
| 0x40342654 | trace_msg_data_4 | data |  | 0.55 | dynamic | 0 | 20 |
| 0x40342658 | trace_msg_data_5 | data |  | 0.55 | dynamic | 0 | 20 |
| 0x4034265c | trace_msg_data_6 | data |  | 0.55 | dynamic | 0 | 20 |
| 0x40342660 | trace_msg_data_7 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x40342664 | trace_msg_data_8 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x40342668 | trace_msg_data_9 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x4034266c | trace_msg_data_10 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x40342670 | trace_msg_data_11 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x40342674 | trace_msg_data_12 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x40342678 | trace_msg_data_13 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x4034267c | trace_msg_data_14 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x40342680 | trace_msg_data_15 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x40342684 | trace_msg_data_16 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x40342688 | trace_msg_data_17 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x4034268c | trace_msg_data_18 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x40342690 | trace_msg_data_19 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x40342694 | trace_msg_data_20 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x40342698 | trace_msg_data_21 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x4034269c | trace_msg_data_22 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x403426a0 | trace_msg_data_23 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x403426a4 | trace_msg_data_24 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x403426a8 | trace_msg_data_25 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x403426ac | trace_msg_data_26 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x403426b0 | trace_msg_data_27 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x403426b4 | trace_msg_data_28 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x403426b8 | trace_msg_data_29 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x403426bc | trace_msg_data_30 | data |  | 0.55 | dynamic | 0 | 12 |
| 0x403426c0 | trace_msg_data_31 | data |  | 0.55 | dynamic | 0 | 11 |
| 0x403426c4 | data_buf_0 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426c8 | data_buf_1 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426cc | data_buf_2 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426d0 | data_buf_3 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426d4 | data_buf_4 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426d8 | data_buf_5 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426dc | data_buf_6 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426e0 | data_buf_7 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426e4 | data_buf_8 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426e8 | data_buf_9 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426ec | data_buf_10 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426f0 | data_buf_11 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426f4 | data_buf_12 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426f8 | data_buf_13 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403426fc | data_buf_14 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342700 | data_buf_15 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342704 | data_buf_16 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342708 | data_buf_17 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x4034270c | data_buf_18 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342710 | data_buf_19 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342714 | data_buf_20 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342718 | data_buf_21 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x4034271c | data_buf_22 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342720 | data_buf_23 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342724 | data_buf_24 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342728 | data_buf_25 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x4034272c | data_buf_26 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342730 | data_buf_27 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342734 | data_buf_28 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342738 | data_buf_29 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x4034273c | data_buf_30 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342740 | data_buf_31 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342744 | dbg_buf_00 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342748 | dbg_buf_01 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x4034274c | dbg_buf_02 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342750 | dbg_buf_03 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342754 | dbg_buf_04 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342758 | dbg_buf_05 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x4034275c | dbg_buf_06 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342760 | dbg_buf_07 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342764 | dbg_buf_08 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342768 | dbg_buf_09 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x4034276c | dbg_buf_10 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342770 | dbg_buf_11 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342774 | dbg_buf_12 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342778 | dbg_buf_13 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x4034277c | dbg_buf_14 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342780 | dbg_buf_15 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342784 | dbg_buf_16 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342788 | dbg_buf_17 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x4034278c | dbg_buf_18 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342790 | dbg_buf_19 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342794 | dbg_buf_20 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x40342798 | dbg_buf_21 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x4034279c | dbg_buf_22 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403427a0 | dbg_buf_23 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403427a4 | dbg_buf_24 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403427a8 | dbg_buf_25 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403427ac | dbg_buf_26 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403427b0 | dbg_buf_27 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403427b4 | dbg_buf_28 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403427b8 | dbg_buf_29 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403427bc | dbg_buf_30 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403427c0 | dbg_buf_31 | data |  | 0.6 | dynamic | 0 | 11 |
| 0x403427c4 | crypto_key_word0 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427c8 | crypto_key_word1 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427cc | crypto_key_word2 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427d0 | crypto_key_word3 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427d4 | crypto_key_word4 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427d8 | crypto_key_word5 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427dc | crypto_key_word6 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427e0 | crypto_key_word7 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427e4 | crypto_key_word8 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427e8 | crypto_key_word9 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427ec | crypto_key_word10 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427f0 | crypto_key_word11 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427f4 | crypto_key_word12 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427f8 | crypto_key_word13 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x403427fc | crypto_key_word14 | data |  | 0.5 | dynamic | 0 | 11 |
| 0x40343004 | rf_clock_ctrl | clock |  | 0.4 | dynamic | 8 | 8 |
| 0x40343048 | rf_cmd_strobe | strobe | strobe n= | 0.3 | dynamic | 3 | 3 |
| 0x40343050 | rf_clk_enable | clock |  | 0.5 | dynamic | 4 | 8 |
| 0x40343054 | rf_status0 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x40343058 | rf_status1 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x4034305c | rf_status2 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x40343060 | rf_status3 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x40343064 | rf_status4 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x40343068 | rf_status5 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x4034306c | rf_status6 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x40343070 | rf_status7 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x40343074 | rf_status8 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x40343078 | rf_status9 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x4034307c | rf_status10 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x40343080 | rf_status11 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x40343084 | rf_status12 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x40343088 | rf_status13 | status |  | 0.2 | dynamic | 4 | 0 |
| 0x4034308c | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343090 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343094 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343098 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x4034309c | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430a0 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430a4 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430a8 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430ac | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430b0 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430b4 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430b8 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430bc | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430c0 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430c4 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430c8 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430cc | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430d0 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430d4 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430d8 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430dc | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430e0 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430e4 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430e8 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430ec | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430f0 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430f4 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430f8 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403430fc | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343100 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343104 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343108 | unknown_register | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x4034310c |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343110 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343114 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343118 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x4034311c |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343120 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343124 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343128 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x4034312c |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343130 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343134 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343138 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x4034313c |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343140 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343144 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343148 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x4034314c |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343150 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343154 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343158 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x4034315c |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343160 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343164 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343168 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x4034316c |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343170 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343174 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343178 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x4034317c |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343180 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343184 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343188 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x4034318c |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343190 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343194 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40343198 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x4034319c |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403431a0 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403431a4 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403431a8 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403431ac |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403431b0 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403431b4 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403431b8 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403431bc |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403431c0 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403431c4 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403431c8 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x403431cc |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40344000 | rf_ahb_gate_ctrl | clock |  | 0.8 | dynamic | 48 | 32 |
| 0x40344003 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40344004 | rf_phy_status | status | poll ready=0x300000 n=8 | 0.5 | dynamic | 48 | 8 |
| 0x40344008 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40344010 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40344014 | rf_config_trigger | config |  | 0.3 | dynamic | 1 | 1 |
| 0x40344018 | rf_clk_gate1 | clock |  | 0.8 | dynamic | 18 | 17 |
| 0x4034401c | rf_clk_gate2 | clock |  | 0.8 | dynamic | 24 | 24 |
| 0x40344020 | rf_pll_ctrl | config |  | 0.3 | dynamic | 4 | 3 |
| 0x40344024 | rf_freq_ctrl | config |  | 0.3 | dynamic | 8 | 7 |
| 0x40344028 | rf_clk_sel | clock |  | 0.5 | dynamic | 8 | 11 |
| 0x4034402c | rf_synth_freq | config |  | 0.4 | dynamic | 4 | 7 |
| 0x40344030 | rf_chan_freq | config |  | 0.4 | dynamic | 12 | 15 |
| 0x40344034 | rf_ref_freq | config |  | 0.4 | dynamic | 12 | 12 |
| 0x40344038 | rf_ana_ctrl | config |  | 0.4 | dynamic | 4 | 4 |
| 0x4034403c | rf_phy_control | config |  | 0.5 | dynamic | 36 | 28 |
| 0x40344040 | rf_clock_gate | clock |  | 0.6 | dynamic | 20 | 20 |
| 0x40344044 | rf_clock_reset | clock |  | 0.6 | dynamic | 20 | 20 |
| 0x40344048 | rf_clock_div | clock |  | 0.5 | dynamic | 20 | 20 |
| 0x4034404c | rf_phy_config | config |  | 0.4 | dynamic | 18 | 14 |
| 0x40344050 |  | unknown |  | 0.0 | dynamic | 8 | 4 |
| 0x40344054 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40344058 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4034405c | rf_phy_control2 | config |  | 0.5 | dynamic | 16 | 4 |
| 0x40344060 |  | unknown |  | 0.0 | dynamic | 4 | 0 |
| 0x40344068 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40344070 | rf_pll_ctrl | clock |  | 0.5 | dynamic | 8 | 8 |
| 0x40344074 | rf_pll_config | clock |  | 0.5 | dynamic | 8 | 8 |
| 0x40344078 | rf_clock_sel | clock |  | 0.5 | dynamic | 16 | 16 |
| 0x40344084 | crypto_power_ctrl | clock |  | 0.6 | dynamic | 21 | 24 |
| 0x40344088 | crypto_clk_reset_ctrl | clock |  | 0.7 | dynamic | 36 | 32 |
| 0x4034408c | crypto_power_seq0 | config |  | 0.3 | dynamic | 0 | 4 |
| 0x40344090 | crypto_power_seq1 | config |  | 0.3 | dynamic | 0 | 4 |
| 0x40344094 | crypto_hw_enable | config |  | 0.7 | dynamic | 13 | 40 |
| 0x40344098 | crypto_control0 | config |  | 0.3 | dynamic | 1 | 4 |
| 0x4034409c | crypto_state_ctrl | config |  | 0.5 | dynamic | 49 | 36 |
| 0x403440a0 | crypto_control1 | config |  | 0.3 | dynamic | 1 | 4 |
| 0x403440a4 | crypto_control2 | config |  | 0.3 | dynamic | 1 | 4 |
| 0x403440a8 | crypto_power_status | status |  | 0.4 | dynamic | 17 | 4 |
| 0x403440ac | crypto_control3 | config |  | 0.3 | dynamic | 1 | 4 |
| 0x403440b0 | crypto_control4 | config |  | 0.3 | dynamic | 1 | 4 |
| 0x403440b4 | crypto_control5 | config |  | 0.3 | dynamic | 1 | 4 |
| 0x403440b8 | crypto_control6 | config |  | 0.3 | dynamic | 1 | 4 |
| 0x403440bc | crypto_control7 | config |  | 0.3 | dynamic | 1 | 4 |
| 0x403440c0 | crypto_control8 | config |  | 0.3 | dynamic | 1 | 4 |
| 0x403440c4 | crypto_control9 | config |  | 0.3 | dynamic | 1 | 4 |
| 0x403440c8 | crypto_control10 | config |  | 0.3 | dynamic | 1 | 4 |
| 0x403440cc | crypto_key_data_0 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x403440d0 | crypto_key_data_1 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x403440d4 | crypto_key_data_2 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x403440d8 | crypto_key_data_3 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x403440dc | crypto_key_data_4 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x403440e0 | crypto_key_data_5 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x403440e4 | crypto_key_data_6 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x403440e8 | crypto_key_data_7 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x403440ec | crypto_key_data_8 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x403440f0 | crypto_key_data_9 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x403440f4 | crypto_key_data_10 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x403440f8 | crypto_key_data_11 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x403440fc | crypto_key_data_12 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344100 | crypto_key_data_13 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344104 | crypto_key_data_14 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344108 | crypto_key_data_15 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x4034410c | crypto_key_data_16 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344110 | crypto_key_data_17 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344114 | crypto_key_data_18 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344118 | crypto_key_data_19 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x4034411c | crypto_key_data_20 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344120 | crypto_key_data_21 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344124 | crypto_key_data_22 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344128 | crypto_key_data_23 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x4034412c | crypto_key_data_24 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344130 | crypto_key_data_25 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344134 | crypto_key_data_26 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344138 | crypto_key_data_27 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x4034413c | crypto_key_data_28 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344140 | crypto_key_data_29 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344144 | crypto_key_data_30 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x40344148 | crypto_key_data_31 | data |  | 0.6 | dynamic | 1 | 4 |
| 0x4034414c | crypto_key_load_word0 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344150 | crypto_key_load_word1 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344154 | crypto_key_load_word2 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344158 | crypto_key_load_word3 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x4034415c | crypto_key_load_word4 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344160 | crypto_key_load_word5 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344164 | crypto_key_load_word6 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344168 | crypto_key_load_word7 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x4034416c | crypto_key_load_word8 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344170 | crypto_key_load_word9 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344174 | crypto_key_load_word10 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344178 | crypto_key_load_word11 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x4034417c | crypto_key_load_word12 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344180 | crypto_key_load_word13 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344184 | crypto_key_load_word14 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344188 | crypto_key_load_word15 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x4034418c | crypto_key_load_word16 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344190 | crypto_key_load_word17 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344194 | crypto_key_load_word18 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x40344198 | crypto_key_load_word19 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x4034419c | crypto_key_load_word20 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x403441a0 | crypto_key_load_word21 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x403441a4 | crypto_key_load_word22 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x403441a8 | crypto_key_load_word23 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x403441ac | crypto_key_load_word24 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x403441b0 | crypto_key_load_word25 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x403441b4 | crypto_key_load_word26 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x403441b8 | crypto_key_load_word27 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x403441bc | crypto_key_load_word28 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x403441c0 | crypto_key_load_word29 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x403441c4 | crypto_key_load_word30 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x403441c8 | crypto_key_load_word31 | config |  | 0.5 | dynamic | 1 | 4 |
| 0x403441cc | crypto_key_data_00 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x403441d0 | crypto_key_data_01 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x403441d4 | crypto_key_data_02 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x403441d8 | crypto_key_data_03 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x403441dc | crypto_key_data_04 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x403441e0 | crypto_key_data_05 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x403441e4 | crypto_key_data_06 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x403441e8 | crypto_key_data_07 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x403441ec | crypto_key_data_08 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x403441f0 | crypto_key_data_09 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x403441f4 | crypto_key_data_10 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x403441f8 | crypto_key_data_11 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x403441fc | crypto_key_data_12 | data |  | 0.7 | dynamic | 1 | 4 |
| 0x40344200 | crypto_key_data_13 | data |  | 0.7 | dynamic | 1 | 7 |
| 0x40344204 | unclassified_00 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344208 | unclassified_01 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034420c | unclassified_02 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344210 | unclassified_03 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344214 | unclassified_04 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344218 | unclassified_05 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034421c | unclassified_06 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344220 | unclassified_07 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344224 | unclassified_08 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344228 | unclassified_09 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034422c | unclassified_10 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344230 | unclassified_11 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344234 | unclassified_12 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344238 | unclassified_13 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034423c | unclassified_14 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344240 | unclassified_15 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344244 | unclassified_16 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344248 | unclassified_17 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034424c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344250 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344254 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344258 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034425c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344260 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344264 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344268 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034426c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344270 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344274 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344278 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034427c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344280 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344284 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344288 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034428c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344290 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344294 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344298 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034429c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442a0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442a4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442a8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442ac |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442b0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442b4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442b8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442bc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442c0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442c4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442c8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442cc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442d0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442d4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442d8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442dc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442e0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442e4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442e8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442ec |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442f0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442f4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442f8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403442fc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344300 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344304 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344308 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034430c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344310 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344314 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344318 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034431c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344320 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344324 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344328 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034432c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344330 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344334 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344338 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034433c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344340 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344344 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344348 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034434c | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344350 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344354 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344358 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034435c | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344360 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344364 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344368 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034436c | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344370 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344374 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344378 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034437c | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344380 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344384 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344388 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034438c | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344390 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344394 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344398 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034439c | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443a0 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443a4 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443a8 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443ac | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443b0 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443b4 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443b8 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443bc | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443c0 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443c4 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443c8 | unknown_crypto_register | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443cc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443d0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443d4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443d8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443dc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443e0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443e4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443e8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443ec |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443f0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443f4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443f8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403443fc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344400 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344404 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344408 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034440c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344410 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344414 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344418 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034441c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344420 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344424 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344428 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034442c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344430 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344434 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344438 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034443c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344440 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344444 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344448 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034444c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344450 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344454 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344458 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034445c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344460 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344464 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344468 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034446c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344470 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344474 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344478 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034447c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344480 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344484 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344488 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034448c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344490 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344494 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344498 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034449c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444a0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444a4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444a8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444ac |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444b0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444b4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444b8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444bc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444c0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444c4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444c8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444cc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444d0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444d4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444d8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444dc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444e0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444e4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444e8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444ec |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444f0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444f4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444f8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403444fc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344500 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344504 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344508 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034450c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344510 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344514 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344518 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034451c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344520 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344524 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344528 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034452c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344530 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344534 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344538 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034453c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344540 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344544 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344548 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034454c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344550 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344554 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344558 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034455c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344560 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344564 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344568 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034456c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344570 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344574 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344578 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034457c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344580 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344584 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344588 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034458c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344590 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344594 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344598 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034459c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445a0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445a4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445a8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445ac |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445b0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445b4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445b8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445bc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445c0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445c4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445c8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445cc | crypto_key_load_status_0 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445d0 | crypto_key_load_status_1 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445d4 | crypto_key_load_status_2 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445d8 | crypto_key_load_status_3 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445dc | crypto_key_load_status_4 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445e0 | crypto_key_load_status_5 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445e4 | crypto_key_load_status_6 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445e8 | crypto_key_load_status_7 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445ec | crypto_key_load_status_8 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445f0 | crypto_key_load_status_9 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445f4 | crypto_key_load_status_10 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445f8 | crypto_key_load_status_11 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403445fc | crypto_key_load_status_12 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344600 | crypto_key_load_status_13 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344604 | crypto_key_load_status_14 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344608 | crypto_key_load_status_15 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034460c | crypto_key_load_status_16 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344610 | crypto_key_load_status_17 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344614 | crypto_key_load_status_18 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344618 | crypto_key_load_status_19 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034461c | crypto_key_load_status_20 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344620 | crypto_key_load_status_21 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344624 | crypto_key_load_status_22 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344628 | crypto_key_load_status_23 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034462c | crypto_key_load_status_24 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344630 | crypto_key_load_status_25 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344634 | crypto_key_load_status_26 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344638 | crypto_key_load_status_27 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034463c | crypto_key_load_status_28 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344640 | crypto_key_load_status_29 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344644 | crypto_key_load_status_30 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344648 | crypto_key_load_status_31 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034464c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344650 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344654 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344658 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034465c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344660 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344664 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344668 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034466c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344670 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344674 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344678 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034467c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344680 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344684 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344688 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034468c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344690 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344694 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x40344698 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x4034469c |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403446a0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403446a4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403446a8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403446ac |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403446b0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403446b4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403446b8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403446bc |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403446c0 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403446c4 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403446c8 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x403446cc | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x403446d0 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x403446d4 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x403446d8 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x403446dc | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x403446e0 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x403446e4 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x403446e8 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x403446ec | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x403446f0 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x403446f4 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x403446f8 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x403446fc | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344700 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344704 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344708 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x4034470c | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344710 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344714 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344718 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x4034471c | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344720 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344724 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344728 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x4034472c | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344730 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344734 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344738 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x4034473c | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344740 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344744 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x40344748 | crypto_key_data | data |  | 0.6 | dynamic | 1 | 0 |
| 0x4034474c | crypto_key_load_status | status |  | 0.2 | dynamic | 1 | 0 |
| 0x40344750 | crypto_key_load_status2 | status |  | 0.2 | dynamic | 1 | 0 |
| 0x403450e0 | ipc_doorbell_data | data |  | 0.5 | dynamic | 8 | 8 |
| 0x40346000 | crypto_engine_region0 | unknown |  | 0.1 | dynamic | 0 | 0 |
| 0x40346010 | crypto_engine_region1 | unknown |  | 0.1 | dynamic | 0 | 0 |
| 0x40346200 | crypto_engine_region2 | unknown |  | 0.1 | dynamic | 0 | 0 |
| 0x40346400 | crypto_engine_region3 | unknown |  | 0.1 | dynamic | 0 | 0 |
| 0x40346600 | crypto_engine_region4 | unknown |  | 0.1 | dynamic | 0 | 0 |
| 0x40346800 | crypto_engine_region5 | unknown |  | 0.1 | dynamic | 0 | 0 |
| 0x40346c00 | crypto_engine_region6 | unknown |  | 0.1 | dynamic | 0 | 0 |

## Page 0x4050

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40500000 | rf_status | status |  | 0.5 | dynamic | 24 | 0 |
| 0x40500010 | clock_status_0 | status |  | 0.3 | dynamic | 6 | 0 |
| 0x40500020 | clock_status_1 | status |  | 0.3 | dynamic | 6 | 0 |
| 0x40500034 | rf_config | config |  | 0.4 | dynamic | 0 | 2 |
| 0x40500038 | ipc_doorbell_status | status |  | 0.3 | dynamic | 5 | 5 |
| 0x40500040 | unknown_40500040 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40500058 | rf_init_config | config |  | 0.3 | dynamic | 1 | 1 |
| 0x40500100 | rf_mem_addr | config |  | 0.4 | dynamic | 0 | 6 |
| 0x40500104 | rf_mem_write_data | data |  | 0.5 | dynamic | 0 | 1 |
| 0x40500128 | rf_mode_status | status | poll ready=0x1 n=5 | 0.5 | dynamic | 11 | 0 |
| 0x4050012c | sdio_status | status |  | 0.4 | dynamic | 6 | 0 |
| 0x40501000 | timer_control | config |  | 0.4 | dynamic | 5 | 9 |
| 0x40501004 | timer_load | config |  | 0.4 | dynamic | 1 | 5 |
| 0x40501008 | timer_config | config |  | 0.3 | dynamic | 7 | 32 |
| 0x4050100c | timer_mask | mask |  | 0.3 | dynamic | 7 | 1 |
| 0x40501010 | timer_value | status | poll ready=0x1 n=85 | 0.3 | dynamic | 1138 | 4 |
| 0x40501014 | timer_control_2 | config |  | 0.3 | dynamic | 0 | 4 |
| 0x40501030 | timestamp_load | config |  | 0.5 | dynamic | 0 | 14 |
| 0x40504000 | bitmask_set | strobe | strobe n= | 0.3 | dynamic | 1 | 1 |
| 0x40504004 | unknown_40504004 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40504008 | unknown_40504008 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4050400c | unknown_4050400c | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40504010 | unknown_40504010 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40504034 | unknown_40504034 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40504080 | irq_prio_0 | config |  | 0.4 | dynamic | 8 | 8 |
| 0x40504084 | irq_prio_1 | config |  | 0.4 | dynamic | 3 | 3 |
| 0x40504088 | irq_prio_2 | config |  | 0.4 | dynamic | 3 | 3 |
| 0x4050408c | irq_config_3 | config |  | 0.4 | dynamic | 3 | 3 |
| 0x40505000 | irq_enable | mask |  | 0.7 | dynamic | 25 | 20 |
| 0x40505004 | irq_config_0 | config |  | 0.4 | dynamic | 17 | 17 |
| 0x40505008 | irq_config_1 | config |  | 0.4 | dynamic | 24 | 24 |
| 0x4050500c | irq_config_2 | config |  | 0.4 | dynamic | 6 | 6 |
| 0x40505010 | irq_config_enable | mask |  | 0.3 | dynamic | 6 | 6 |
| 0x40505014 | irq_config | config |  | 0.2 | dynamic | 3 | 3 |
| 0x40505018 | irq_status | status |  | 0.3 | dynamic | 6 | 6 |
| 0x40505020 | irq_status_id | status |  | 0.2 | dynamic | 3 | 0 |
| 0x40505024 | irq_enable_set | mask |  | 0.3 | dynamic | 0 | 6 |
| 0x40505028 | irq_status2 | status |  | 0.3 | dynamic | 6 | 6 |
| 0x4050502c | irq_mask | mask |  | 0.4 | dynamic | 6 | 6 |
| 0x40506000 | rf_bus_base | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40506004 | irq_event_set | irq |  | 0.4 | dynamic | 15 | 15 |
| 0x40506008 | rf_mode_status | status | poll ready=0x1 n=5 | 0.4 | dynamic | 13 | 2 |
| 0x40506030 | rf_cmd_wait_status | status | poll ready=0x1 n=394 | 0.4 | dynamic | 1182 | 0 |
| 0x4050605c | rf_mac_status | status |  | 0.2 | dynamic | 9 | 0 |
| 0x40509000 | phy_ctrl | config |  | 0.35 | dynamic | 16 | 16 |
| 0x40509004 | phy_ctrl_reserved | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40509008 | phy_ctrl_reserved | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4050900c | phy_data | data |  | 0.5 | dynamic | 33 | 25 |
| 0x40509010 | phy_cmd | config |  | 0.5 | dynamic | 36 | 36 |
| 0x40509014 | phy_status | status |  | 0.2 | dynamic | 4 | 0 |
| 0x4050901c | phy_addr | config |  | 0.3 | dynamic | 8 | 8 |
| 0x4050902c | phy_sel_reserved | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40509030 | phy_sel | config |  | 0.4 | dynamic | 16 | 16 |
| 0x4050ea6f | unknown_const | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4050f89d | unknown_const | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4050f8bd | unknown_const | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x4058

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40580008 | pmu_cfg_0008 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x4058000c | pmu_cfg_000c | config |  | 0.6 | dynamic | 3 | 3 |
| 0x40580010 | pmu_cfg_0010 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x40580016 | pmu_cfg_0016 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x40580018 | pmu_cfg_0018 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x40580020 | pmu_cfg_0020 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x40580048 | pmu_cfg_0048 | config |  | 0.15 | dynamic | 0 | 0 |
| 0x40580104 | pmu_cfg_0104 | config |  | 0.6 | dynamic | 0 | 3 |
| 0x405830a8 | pmu_cfg_30a8 | config |  | 0.15 | dynamic | 0 | 0 |

## Page 0x4060

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x406000f4 | rf_phy_cfg_f4 | config |  | 0.2 | dynamic | 0 | 0 |
| 0x406000f8 | rf_phy_cfg_f8 | config |  | 0.2 | dynamic | 0 | 0 |
| 0x40600110 | rf_phy_cfg_110 | config |  | 0.6 | dynamic | 0 | 3 |
| 0x4060048c | rf_phy_cfg_48c | config |  | 0.6 | dynamic | 0 | 3 |
| 0x40600880 | rf_phy_cfg_880 | config |  | 0.6 | dynamic | 0 | 3 |
| 0x40600884 | rf_phy_cfg_884 | config |  | 0.6 | dynamic | 0 | 3 |
| 0x40600888 | rf_phy_cfg_888 | config |  | 0.6 | dynamic | 0 | 3 |
| 0x4060088c | rf_phy_cfg_88c | config |  | 0.6 | dynamic | 0 | 3 |
| 0x40604034 | rf_phy_cfg_4034 | config |  | 0.2 | dynamic | 0 | 0 |
| 0x40604050 | rf_phy_cfg_4050 | config |  | 0.2 | dynamic | 0 | 0 |
| 0x4060f020 | rf_phy_cfg_f020 | config |  | 0.2 | dynamic | 0 | 0 |

## Page 0x4062

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40620508 | rf_analog_cfg_0 | config |  | 0.7 | dynamic | 0 | 3 |
| 0x4062050c | rf_analog_cfg_1 | config |  | 0.7 | dynamic | 0 | 3 |
| 0x4062051c | rf_analog_cfg_2 | config |  | 0.7 | dynamic | 0 | 3 |
| 0x40620530 | rf_analog_cfg_3 | config |  | 0.7 | dynamic | 0 | 3 |
| 0x406205a0 | rf_analog_cfg_4 | config |  | 0.7 | dynamic | 0 | 3 |
| 0x406205a4 | rf_analog_cfg_5 | config |  | 0.7 | dynamic | 0 | 3 |
| 0x406205b0 | rf_analog_cfg_6 | config |  | 0.7 | dynamic | 0 | 3 |
| 0x406205f0 | rf_analog_cfg_7 | config |  | 0.7 | dynamic | 0 | 3 |
| 0x40622000 | rf_phy_cfg_0 | config |  | 0.2 | dynamic | 0 | 0 |
| 0x40622004 | rf_phy_cfg_1 | config |  | 0.2 | dynamic | 0 | 0 |
| 0x4062200c | rf_phy_cfg_2 | config |  | 0.2 | dynamic | 0 | 0 |

## Page 0x40B1

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x40b12107 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x40b18d78 | rf_status_8d78 | status |  | 0.2 | dynamic | 1 | 0 |
| 0x40b18d7d | rf_status_8d7d | status |  | 0.2 | dynamic | 1 | 0 |
| 0x40b18d80 | rf_status_8d80 | status |  | 0.2 | dynamic | 1 | 0 |
| 0x40b18d81 | rf_status_8d81 | status |  | 0.2 | dynamic | 1 | 0 |
| 0x40b18d82 | rf_status_8d82 | status |  | 0.2 | dynamic | 1 | 0 |

## Page 0x414B

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x414b70e2 | crypto_key_schedule_config_0 | config |  | 0.6 | dynamic | 0 | 4 |
| 0x414b70e6 | crypto_key_schedule_config_1 | config |  | 0.6 | dynamic | 0 | 4 |
| 0x414b70ea | crypto_key_schedule_config_2 | config |  | 0.6 | dynamic | 0 | 4 |

## Page 0x4300

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x43000012 | unknown_reg | unknown |  | 0.0 | dynamic | 3 | 0 |
| 0x43000016 | unknown_reg | unknown |  | 0.0 | dynamic | 3 | 0 |
| 0x4300003e | unknown_reg | unknown |  | 0.0 | dynamic | 2 | 0 |
| 0x4300e9c5 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300e9c6 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300e9cd | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300ea43 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f000 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f003 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f010 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f011 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f020 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f023 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f029 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f043 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f04f | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f083 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f103 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f403 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f423 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f443 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f44f | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4300f5a3 | unknown_reg | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x431B

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x431bde83 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x431bde87 |  | unknown |  | 0.0 | dynamic | 3 | 0 |
| 0x431bde8b |  | unknown |  | 0.0 | dynamic | 3 | 0 |
| 0x431bdeb1 |  | unknown |  | 0.0 | dynamic | 3 | 0 |

## Page 0x432C

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x432c0080 | rf_unknown_0080 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x432c1c42 | rf_unknown_1c42 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x432c1c51 | rf_unknown_1c51 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x432c320c | rf_unknown_320c | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x432c4015 | rf_unknown_4015 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x432c58c4 | rf_unknown_58c4 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x432c64e0 | rf_unknown_64e0 | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x4330

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x43300000 | rf_state_status | status |  | 0.4 | dynamic | 3 | 0 |
| 0x43302082 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4330403d |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x43304670 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4330b280 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4330f043 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4330f606 |  | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x45AF

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x45afdf05 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x45afdf09 |  | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x45afdf0d |  | unknown |  | 0.0 | dynamic | 1 | 0 |

## Page 0x4703

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x47033129 |  | unknown |  | 0.0 | dynamic | 3 | 0 |
| 0x4703cc0c |  | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x474E

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x474e0000 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x474e4148 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x474e4944 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x474e494e |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x474e4950 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x474e4954 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x474e4956 |  | unknown |  | 0.0 | dynamic | 1 | 0 |

## Page 0x4C55

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x4c554445 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4c554e20 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x4c554e28 |  | unknown |  | 0.0 | dynamic | 1 | 1 |
| 0x4c559414 |  | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x5555

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x55555556 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0x5555555c | dsp_input_data | data |  | 0.3 | dynamic | 0 | 4 |
| 0x55555560 | dsp_output_data | data |  | 0.3 | dynamic | 4 | 0 |
| 0x5555ebd4 |  | unknown |  | 0.0 | dynamic | 0 | 0 |

## Page 0x5718

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0x57189d40 | unknown_57189d40 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x57189d48 | unknown_57189d48 | unknown |  | 0.0 | dynamic | 1 | 0 |
| 0x57189f04 | unknown_57189f04 | unknown |  | 0.0 | dynamic | 1 | 0 |

## Page 0xE000

| addr | name | role | behavior | conf | src | reads | writes |
|------|------|------|----------|------|-----|-------|--------|
| 0xe0000000 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe0000019 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe00000a8 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe00000c4 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe0000964 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000097f |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe0001081 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe0002001 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000306b |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe0003fff |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe0004034 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe0004408 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe0004628 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe0004663 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe0004700 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000497e |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe00061fa |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe0008402 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe0009808 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000b662 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000e100 | nvic_iser0 | irq |  | 0.95 | dynamic | 11 | 38 |
| 0xe000e104 | nvic_iser1 | irq |  | 0.9 | dynamic | 5 | 11 |
| 0xe000e108 | nvic_iser2 | irq |  | 0.95 | dynamic | 5 | 5 |
| 0xe000e10c | nvic_iser3 | irq |  | 0.7 | dynamic | 3 | 0 |
| 0xe000e110 | nvic_iser4 | irq |  | 0.7 | dynamic | 3 | 0 |
| 0xe000e114 | nvic_iser5 | irq |  | 0.7 | dynamic | 3 | 0 |
| 0xe000e118 | nvic_iser6 | irq |  | 0.7 | dynamic | 3 | 0 |
| 0xe000e11c | nvic_iser7 | irq |  | 0.7 | dynamic | 3 | 0 |
| 0xe000e180 | nvic_icer0 | irq |  | 0.9 | dynamic | 0 | 14 |
| 0xe000e188 | nvic_icer2 | irq |  | 0.9 | dynamic | 0 | 24 |
| 0xe000e200 | nvic_ispr0 | irq |  | 0.85 | dynamic | 5 | 0 |
| 0xe000e204 | nvic_ispr1 | irq |  | 0.85 | dynamic | 7 | 0 |
| 0xe000e208 | nvic_ispr2 | irq |  | 0.7 | dynamic | 5 | 0 |
| 0xe000e20c | nvic_ispr3 | irq |  | 0.7 | dynamic | 3 | 0 |
| 0xe000e400 | nvic_ipr0 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e401 | nvic_ipr1 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e402 | nvic_ipr2 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e403 | nvic_ipr3 | irq |  | 0.9 | dynamic | 0 | 5 |
| 0xe000e404 | nvic_ipr4 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e405 | nvic_ipr5 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e406 | nvic_ipr6 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e407 | nvic_ipr7 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e408 | nvic_ipr8 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e409 | nvic_ipr9 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e40a | nvic_ipr10 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e40b | nvic_ipr11 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e40c | nvic_ipr12 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e40d | nvic_ipr13 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e40e | nvic_ipr14 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e40f | nvic_ipr15 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e410 | nvic_ipr16 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e411 | nvic_ipr17 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e412 | nvic_ipr18 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e413 | nvic_ipr19 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e414 | nvic_ipr20 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e415 | nvic_ipr21 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e416 | nvic_ipr22 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e417 | nvic_ipr23 | irq |  | 0.9 | dynamic | 0 | 4 |
| 0xe000e418 | nvic_ipr24 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e419 | nvic_ipr25 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e41a | nvic_ipr26 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e41b | nvic_ipr27 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e41c | nvic_ipr28 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e41d | nvic_ipr29 | irq |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e41e | nvic_ipr_irq30 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e41f | nvic_ipr_irq31 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e420 | nvic_ipr_irq32 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e421 | nvic_ipr_irq33 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e422 | nvic_ipr_irq34 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e423 | nvic_ipr_irq35 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e424 | nvic_ipr_irq36 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e425 | nvic_ipr_irq37 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e426 | nvic_ipr_irq38 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e427 | nvic_ipr_irq39 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e428 | nvic_ipr_irq40 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e429 | nvic_ipr_irq41 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e42a | nvic_ipr_irq42 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e42b | nvic_ipr_irq43 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e42c | nvic_ipr_irq44 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e42d | nvic_ipr_irq45 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e42e | nvic_ipr_irq46 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e42f | nvic_ipr_irq47 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e430 | nvic_ipr_irq48 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e431 | nvic_ipr_irq49 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e432 | nvic_ipr_irq50 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e433 | nvic_ipr_irq51 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e434 | nvic_ipr_irq52 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e435 | nvic_ipr_irq53 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e436 | nvic_ipr_irq54 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e437 | nvic_ipr_irq55 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e438 | nvic_ipr_irq56 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e439 | nvic_ipr_irq57 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e43a | nvic_ipr_irq58 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e43b | nvic_ipr_irq59 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e43c | nvic_ipr_irq60 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e43d | nvic_ipr_irq61 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e43e | nvic_ipr_irq62 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e43f | nvic_ipr_irq63 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e440 | nvic_ipr_irq64 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e441 | nvic_ipr_irq65 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e442 | nvic_ipr_irq66 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e443 | nvic_ipr_irq67 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e444 | nvic_ipr_irq68 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e445 | nvic_ipr_irq69 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e446 | nvic_ipr_irq70 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e447 | nvic_ipr_irq71 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e448 | nvic_ipr_irq72 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e449 | nvic_ipr_irq73 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e44a | nvic_ipr_irq74 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e44b | nvic_ipr_irq75 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e44c | nvic_ipr_irq76 | config |  | 0.9 | dynamic | 0 | 6 |
| 0xe000e44d | nvic_ipr_irq77 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e44e | nvic_ipr_irq78 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e44f | nvic_ipr_irq79 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e450 | nvic_ipr_irq80 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e451 | nvic_ipr_irq81 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e452 | nvic_ipr_irq82 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e453 | nvic_ipr_irq83 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e454 | nvic_ipr_irq84 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000e455 | nvic_ipr_irq85 | config |  | 0.9 | dynamic | 0 | 1 |
| 0xe000ed00 | scb_cpuid | status |  | 0.7 | dynamic | 6 | 0 |
| 0xe000ed08 | scb_vtor | config |  | 0.95 | dynamic | 43 | 1 |
| 0xe000ed88 | scb_cpacr | config |  | 0.9 | dynamic | 1 | 1 |
| 0xe000f4f4 | unknown_0xe000f4f4 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f817 | unknown_0xe000f817 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f894 | unknown_0xe000f894 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8a4 | unknown_0xe000f8a4 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8a5 | unknown_0xe000f8a5 | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8c3 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8c4 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8c5 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8c6 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8c9 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8ca |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8cb |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8cc |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8d2 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8d3 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8d4 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8d6 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8d7 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8d8 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8db |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8dc |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000f8dd |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000fb01 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
| 0xe000fff0 |  | unknown |  | 0.0 | dynamic | 0 | 0 |
