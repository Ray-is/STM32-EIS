#include <Arduino.h>
#include "l9965a.h"

// Time between measurement cycles. Keep it under 2 s (the chip's default communication
// timeout), or call disable_comm_timeout() in setup().
static const unsigned long MEASUREMENT_PERIOD_MS = 100;

static unsigned long lastCycleMs = 0;

static void run_conversion_cycle() {
    start_conversion();
    wait_for_data();
    read_cell_voltages();
}

void setup() {
    init_spi();
    Serial.println(F("L9965A initial test"));

    send_wakeup_spi();
    set_vif_id(1);
    check_nvm();
    enable_cells();
    turnoff_balancing();
    turnoff_busbar();
    // disable_comm_timeout();   // only needed if MEASUREMENT_PERIOD_MS >= 2000

    // The gain correction only applies from the second conversion after wake-up,
    // so run one conversion now and discard its result.
    run_conversion_cycle();

    Serial.println(F("Setup done, measuring"));
    lastCycleMs = millis();
}

void loop() {
    if (millis() - lastCycleMs < MEASUREMENT_PERIOD_MS) return;
    lastCycleMs += MEASUREMENT_PERIOD_MS;

    run_conversion_cycle();
    print_measurements();
}
