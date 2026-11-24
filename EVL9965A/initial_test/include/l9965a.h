// Minimal L9965A driver for bench testing over the SPI target interface
// (EVL9965A jumpers J5:J8 = 1-2, J2 = 1-2, J1 = 2-3).
//
// Typical call order:
//   init_spi();
//   send_wakeup_spi();
//   set_vif_id(1);
//   check_nvm();
//   enable_cells();
//   turnoff_balancing();
//   turnoff_busbar();
//   // optional: disable_comm_timeout();  (only if frames are > 2 s apart)
//   then, at a fixed rate:
//     start_conversion(); wait_for_data(); read_cell_voltages(); print_measurements();
//
// Single-threaded only. Any failed check calls handle_error(), which never returns.

#ifndef L9965A_H
#define L9965A_H

#include <Arduino.h>

#define L9965A_NUM_CELLS 18

extern int devId;                              // -1 until set_vif_id() succeeds
extern float cellVoltages[L9965A_NUM_CELLS];   // volts; -1.0 until first read

void init_spi();
void handle_error(const char* msg);
void handle_error(const __FlashStringHelper* msg);

void send_wakeup_spi();
void set_vif_id(int id);
void check_nvm();
void enable_cells();
void turnoff_balancing();
void turnoff_busbar();
void disable_comm_timeout();

void start_conversion();
void wait_for_data();
void read_cell_voltages();
void print_measurements();

#endif
