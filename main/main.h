#ifndef MAIN_H
#define MAIN_H

#include "esp_err.h"
#include "max30102_api.h"


void sensor_data_processor(void *pvParameters);
void sensor_data_reader(void *pvParameters);
void fill_buffers_data();

#define BUFFER_SIZE 128

//Configuração dos registradores do modo de funcionamento do sensor MAX30102. Basta colocar o valor binário da configuração que o compilador fará o trabalho de setar os bits corretos.
max_config max30102_configuration = {

		.INT_EN_1.A_FULL_EN         = 1,
		.INT_EN_1.PPG_RDY_EN        = 1,
		.INT_EN_1.ALC_OVF_EN        = 0,
		.INT_EN_1.PROX_INT_EN       = 0,

		.INT_EN_2.DIE_TEMP_RDY_EN   = 0,

		.FIFO_WRITE_PTR.FIFO_WR_PTR = 0,

		.OVEF_COUNTER.OVF_COUNTER   = 0,

		.FIFO_READ_PTR.FIFO_RD_PTR  = 0,

		.FIFO_CONF.SMP_AVE          = 0b010,  //média de 4 valores
		.FIFO_CONF.FIFO_ROLLOVER_EN = 1,      //fifo rollover enable
		.FIFO_CONF.FIFO_A_FULL      = 0,      //0

		.MODE_CONF.SHDN             = 0,
		.MODE_CONF.RESET            = 0,
		.MODE_CONF.MODE             = 0b011,  //SPO2 mode

		.SPO2_CONF.SPO2_ADC_RGE     = 0b01,   //16384 nA(Escala do DAC)
		.SPO2_CONF.SPO2_SR          = 0b001,  //200 samples per second
		.SPO2_CONF.LED_PW           = 0b10,   //pulso de 215 uS do led.

		.LED1_PULSE_AMP.LED1_PA     = 0x24,   //CORRENTE DO LED1 25.4mA
		.LED2_PULSE_AMP.LED2_PA     = 0x24,   //CORRENTE DO LED2 25.4mA

		.PROX_LED_PULS_AMP.PILOT_PA = 0X7F,

		.MULTI_LED_CONTROL1.SLOT2   = 0,      //Desabilitado
		.MULTI_LED_CONTROL1.SLOT1   = 0,      //Desabilitado

		.MULTI_LED_CONTROL2.SLOT4   = 0,      //Desabilitado
		.MULTI_LED_CONTROL2.SLOT3   = 0,      //Desabilitado
};

#endif
