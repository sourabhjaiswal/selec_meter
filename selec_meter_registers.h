#pragma once

namespace esphome {
namespace selec_meter {

/* PHASE STATUS REGISTERS */
static const uint16_t SELEC_VOLTAGE = 0x14;
static const uint16_t SELEC_CURRENT = 0x16;
static const uint16_t SELEC_ACTIVE_POWER = 0x000C;
static const uint16_t SELEC_APPARENT_POWER = 0x0012;
static const uint16_t SELEC_REACTIVE_POWER = 0x0018;
static const uint16_t SELEC_POWER_FACTOR = 0x001E;
static const uint16_t SELEC_ANGLE = 0x0024;


static const uint16_t SELEC_FREQUENCY = 0x0046;

static const uint16_t SELEC_IMPORT_ACTIVE_ENERGY = 0x0048;
static const uint16_t SELEC_EXPORT_ACTIVE_ENERGY = 0x004A;
static const uint16_t SELEC_IMPORT_REACTIVE_ENERGY = 0x004C;
static const uint16_t SELEC_EXPORT_REACTIVE_ENERGY = 0x004E;

static const uint16_t SELEC_TOTAL_ACTIVE_ENERGY = 0x0156;
static const uint16_t SELEC_TOTAL_REACTIVE_ENERGY = 0x0158;

static const uint16_t SELEC_MAXIMUM_DEMAND_ACTIVE_POWER = 0x0050;
static const uint16_t SELEC_MAXIMUM_DEMAND_REACTIVE_POWER = 0x0050;
static const uint16_t SELEC_MAXIMUM_DEMAND_APPARENT_POWER = 0x0050;


static const uint16_t SELEC_VAH_SINCE_LAST_RESET = 0x0050;
static const uint16_t SELEC_AH_SINCE_LAST_RESET = 0x0052;
static const uint16_t SELEC_TOTAL_SYSTEM_POWER_DEMAND = 0x0054;
static const uint16_t SELEC_MAXIMUM_TOTAL_SYSTEM_POWER_DEMAND = 0x0056;
static const uint16_t SELEC_CURRENT_SYSTEM_POSITIVE_POWER_DEMAND = 0x0058;
static const uint16_t SELEC_MAXIMUM_SYSTEM_POSITIVE_POWER_DEMAND = 0x005A;
static const uint16_t SELEC_CURRENT_SYSTEM_REVERSE_POWER_DEMAND = 0x005C;
static const uint16_t SELEC_MAXIMUM_SYSTEM_REVERSE_POWER_DEMAND = 0x005E;
static const uint16_t SELEC_TOTAL_SYSTEM_VA_DEMAND = 0x0064;
static const uint16_t SELEC_MAXIMUM_TOTAL_SYSTEM_VA_DEMAND = 0x0066;
static const uint16_t SELEC_NEUTRAL_CURRENT_DEMAND = 0x0068;
static const uint16_t SELEC_MAXIMUM_NEUTRAL_CURRENT = 0x006A;
static const uint16_t SELEC_LINE_1_TO_LINE_2_VOLTS = 0x00C8;
static const uint16_t SELEC_LINE_2_TO_LINE_3_VOLTS = 0x00CA;
static const uint16_t SELEC_LINE_3_TO_LINE_1_VOLTS = 0x00CC;
static const uint16_t SELEC_AVERAGE_LINE_TO_LINE_VOLTS = 0x00CE;
static const uint16_t SELEC_NEUTRAL_CURRENT = 0x00E0;


static const uint16_t SELEC_CURRENT_RESETTABLE_TOTAL_ACTIVE_ENERGY = 0x0180;
static const uint16_t SELEC_CURRENT_RESETTABLE_TOTAL_REACTIVE_ENERGY = 0x0182;
static const uint16_t SELEC_CURRENT_RESETTABLE_IMPORT_ENERGY = 0x0184;
static const uint16_t SELEC_CURRENT_RESETTABLE_EXPORT_ENERGY = 0x0186;
static const uint16_t SELEC_IMPORT_POWER = 0x0500;
static const uint16_t SELEC_EXPORT_POWER = 0x0502;

}  // namespace selec_meter
}  // namespace esphome
