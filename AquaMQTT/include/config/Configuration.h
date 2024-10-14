#ifndef AQUAMQTT_CONFIGURATION_H
#define AQUAMQTT_CONFIGURATION_H

/**
 * Possibility to include your own configuration file (added to .gitignore)
 */
//#define CUSTOM_CONFIGURATION

#ifdef CUSTOM_CONFIGURATION
#    include "CustomConfiguration.h"
#else
#    include "ExampleConfiguration.h"
#endif

#include "Modes.h"

namespace aquamqtt
{
namespace config
{
/**
 * Defines the network name of your esp32 device in your network
 */
constexpr char networkName[] = "aquamqtt";

/**
 * Choose a timezone which is used for NTP time updates:
 * https://gist.github.com/alwynallan/24d96091655391107939
 */
constexpr char timeZoneInfo[] = "CET-1CEST,M3.5.0,M10.5.0/3";  // Europe/Berlin

/**
 * The NTP Time Server used for fetching the current time
 */
constexpr char ntpServer[] = "pool.ntp.org";

/**
 * The OperationMode which is used for AquaMqtt. Refer to EOperationMode
 */
constexpr EOperationMode OPERATION_MODE = EOperationMode::MITM;

/**
 * Choose if the time and date values sent to the main controller should override the ones sent by the hmi controller.
 */
constexpr bool OVERRIDE_TIME_AND_DATE_IN_MITM = true;

/**
 * Choose to publish raw messages represented as hex-string on debug mqtt topics
 */
constexpr bool DEBUG_RAW_SERIAL_MESSAGES = false;

/**
 * Change the time interval where all known attributes are re-published to the MQTT broker.
 */
constexpr uint32_t MQTT_FULL_UPDATE_MS = 1000 * 60 * 30;

/**
 * Change the fixed time interval where the attributes published to the stats topic are updated.
 */
constexpr uint16_t MQTT_STATS_UPDATE_MS = 5000;

/**
 * Use kalman filters for removing noise from the temperature values. This reduces updates sent to MQTT.
 * Note: Filters are only applied within the MQTT channel, the communication between HMI and Controller
 * are still using raw temperature values and is not altered.
 */
constexpr bool MQTT_FILTER_TEMPERATURE_NOISE = true;

/**
 * Parametrize kalman filter for reading temperature values
 * Measurement Uncertainty - How much do we expect to our measurement vary
 */

constexpr float KALMAN_MEA_E = 0.1;

/**
 * Parametrize kalman filter for reading temperature values
 * Estimation Uncertainty - Can be initialized with the same value as e_mea since the kalman filter will adjust its
 * value.
 */

constexpr float KALMAN_EST_E = 0.1;

/**
 * Parametrize kalman filter for reading temperature values
 * Process Variance - usually a small number between 0.001 and 1 - how fast your measurement moves.
 */
constexpr float KALMAN_Q = 0.01;

/**
 * Self explanatory internal settings: most probably you don't want to change them.
 */
constexpr uint8_t  WATCHDOG_TIMEOUT_S     = 60;
constexpr uint16_t WIFI_RECONNECT_CYCLE_S = 10;
constexpr uint8_t  MQTT_MAX_TOPIC_SIZE    = 80;
constexpr uint8_t  MQTT_MAX_PAYLOAD_SIZE  = 255;

/**
 * Pin assignments for AquaMQTT Board Rev 1.0
 */
constexpr uint8_t GPIO_MAIN_RX = 2;
constexpr uint8_t GPIO_MAIN_TX = 3;
constexpr uint8_t GPIO_HMI_RX  = 4;
constexpr uint8_t GPIO_HMI_TX  = 5;
constexpr uint8_t GPIO_SDA_RTC = A4;
constexpr uint8_t GPIO_SCL_RTC = A5;

}  // namespace config
}  // namespace aquamqtt

#endif  // AQUAMQTT_CONFIGURATION_H
