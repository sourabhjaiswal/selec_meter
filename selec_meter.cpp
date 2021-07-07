#include "selec_meter.h"
#include "selec_meter_registers.h"
#include "esphome/core/log.h"

namespace esphome {
namespace selec_meter {

static const char *const TAG = "selec_meter";

static const uint8_t MODBUS_CMD_READ_IN_REGISTERS = 0x04;
static const uint8_t MODBUS_REGISTER_COUNT = 34;  // 74 x 16-bit registers

void SelecMeter::on_modbus_data(const std::vector<uint8_t> &data) {
  if (data.size() < MODBUS_REGISTER_COUNT * 2) {
    ESP_LOGW(TAG, "Invalid size for SelecMeter!");
    return;
  }

  auto selec_meter_get_float = [&](size_t i) -> float {
    uint32_t temp = encode_uint32(data[i+2], data[i + 3], data[i], data[i+1]);
    
    float f;
    memcpy(&f, &temp, sizeof(f));
    return f;
  };

  float voltage = selec_meter_get_float(SELEC_VOLTAGE * 2);
  float current = selec_meter_get_float(SELEC_CURRENT * 2);
//  float active_power = selec_meter_get_float(SELEC_PHASE_1_ACTIVE_POWER * 2 + (i * 4));
//  float apparent_power = selec_meter_get_float(SELEC_PHASE_1_APPARENT_POWER * 2 + (i * 4));
//  float reactive_power = selec_meter_get_float(SELEC_PHASE_1_REACTIVE_POWER * 2 + (i * 4));
//  float power_factor = selec_meter_get_float(SELEC_PHASE_1_POWER_FACTOR * 2 + (i * 4));
//  float phase_angle = selec_meter_get_float(SELEC_PHASE_1_ANGLE * 2 + (i * 4));
//
//    ESP_LOGD(
//        TAG,
//        "SelecMeter Phase %c: V=%.3f V, I=%.3f A, Active P=%.3f W, Apparent P=%.3f VA, Reactive P=%.3f VAR, PF=%.3f, "
//        "PA=%.3f °",
//        i + 'A', voltage, current, active_power, apparent_power, reactive_power, power_factor, phase_angle);
    if (this->voltage_sensor_ != nullptr)
      this->voltage_sensor_->publish_state(voltage);
    if (this->current_sensor_ != nullptr)
      this->current_sensor_->publish_state(current);
//    if (phase.active_power_sensor_ != nullptr)
//      phase.active_power_sensor_->publish_state(active_power);
//    if (phase.apparent_power_sensor_ != nullptr)
//      phase.apparent_power_sensor_->publish_state(apparent_power);
//    if (phase.reactive_power_sensor_ != nullptr)
//      phase.reactive_power_sensor_->publish_state(reactive_power);
//    if (phase.power_factor_sensor_ != nullptr)
//      phase.power_factor_sensor_->publish_state(power_factor);
//    if (phase.phase_angle_sensor_ != nullptr)
//      phase.phase_angle_sensor_->publish_state(phase_angle);
//
//  float frequency = selec_meter_get_float(SELEC_FREQUENCY * 2);
//  float import_active_energy = selec_meter_get_float(SELEC_IMPORT_ACTIVE_ENERGY * 2);
//  float export_active_energy = selec_meter_get_float(SELEC_EXPORT_ACTIVE_ENERGY * 2);
//  float import_reactive_energy = selec_meter_get_float(SELEC_IMPORT_REACTIVE_ENERGY * 2);
//  float export_reactive_energy = selec_meter_get_float(SELEC_EXPORT_REACTIVE_ENERGY * 2);
//
//  ESP_LOGD(TAG, "SelecMeter: F=%.3f Hz, Im.A.E=%.3f Wh, Ex.A.E=%.3f Wh, Im.R.E=%.3f VARh, Ex.R.E=%.3f VARh", frequency,
//           import_active_energy, export_active_energy, import_reactive_energy, export_reactive_energy);
//
//  if (this->frequency_sensor_ != nullptr)
//    this->frequency_sensor_->publish_state(frequency);
//  if (this->import_active_energy_sensor_ != nullptr)
//    this->import_active_energy_sensor_->publish_state(import_active_energy);
//  if (this->export_active_energy_sensor_ != nullptr)
//    this->export_active_energy_sensor_->publish_state(export_active_energy);
//  if (this->import_reactive_energy_sensor_ != nullptr)
//    this->import_reactive_energy_sensor_->publish_state(import_reactive_energy);
//  if (this->export_reactive_energy_sensor_ != nullptr)
//    this->export_reactive_energy_sensor_->publish_state(export_reactive_energy);
}

void SelecMeter::update() { this->send(MODBUS_CMD_READ_IN_REGISTERS, 0, MODBUS_REGISTER_COUNT); }
void SelecMeter::dump_config() {
  ESP_LOGCONFIG(TAG, "SELEC Meter:");
  ESP_LOGCONFIG(TAG, "  Address: 0x%02X", this->address_);
  LOG_SENSOR("    ", "Voltage", this->voltage_sensor_);
  LOG_SENSOR("    ", "Current", this->current_sensor_);
//  LOG_SENSOR("    ", "Active Power", phase.active_power_sensor_);
//  LOG_SENSOR("    ", "Apparent Power", phase.apparent_power_sensor_);
//  LOG_SENSOR("    ", "Reactive Power", phase.reactive_power_sensor_);
//  LOG_SENSOR("    ", "Power Factor", phase.power_factor_sensor_);
//  LOG_SENSOR("    ", "Phase Angle", phase.phase_angle_sensor_);
//  LOG_SENSOR("  ", "Frequency", this->frequency_sensor_);
//  LOG_SENSOR("  ", "Import Active Energy", this->import_active_energy_sensor_);
//  LOG_SENSOR("  ", "Export Active Energy", this->export_active_energy_sensor_);
//  LOG_SENSOR("  ", "Import Reactive Energy", this->import_reactive_energy_sensor_);
//  LOG_SENSOR("  ", "Export Reactive Energy", this->export_reactive_energy_sensor_);
}

}  // namespace selec_meter
}  // namespace esphome
