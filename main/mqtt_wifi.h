#ifndef MQTT_WIFI_H
#define MQTT_WIFI_H


#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "mqtt_client.h"
#include "esp_err.h"

#include "lwip/err.h"
#include "lwip/sys.h"


//***********************wifi***********************

/* The examples use WiFi configuration that you can set via project configuration menu

   If you'd rather not, just change the below entries to strings with
   the config you want - ie #define EXAMPLE_WIFI_SSID "mywifissid"
*/
#define SSID           "OpenWrt"
#define PASSWORD       "superiot"
#define MAXIMUM_RETRY  500


/* The event group allows multiple bits for each event, but we only care about two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries */
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1


void init_wifi(void);
void event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data);
void wifi_init_sta(void);


//***************MQTT***************
void mqtt_app_start(void);
esp_err_t mqtt_event_handler(esp_mqtt_event_handle_t event);

esp_err_t mqtt_publish(const char *data, size_t data_len);

#define MQTT_URL "mqtt://192.168.0.223:1883"
#define SUBSCRIBE_TOPIC "ararar"
#define PUBLISH_TOPIC "/dev/topic"



#endif
