#ifndef ALGORITHM_H
#define ALGORITHM_H


//#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void remove_dc_part(int32_t *ir_buffer, int32_t *red_buffer, uint64_t *ir_mean, uint64_t *red_mean);
void calculate_linear_regression(double *angular_coef, double *linear_coef, int32_t *data);
double correlation_datay_datax(int32_t *data_red, int32_t *data_ir);
double calculate_pearson_r(int32_t *data_red, int32_t *data_ir);
void remove_trend_line(int32_t *buffer);


//Para calcular a regressão linear.
double sum_of_xy_elements(int32_t *data);
int64_t sum_of_elements(int32_t *data);
double sum_of_squared_elements(int32_t *data);
double somatoria_x2() __attribute__ ((optimize(2))); //Otimiza a função para que a mesma não seja chamada toda hora. Não soube fazer tudo com macros...
void init_time_array();
int calculate_heart_rate(int32_t *ir_data, double *r0, double *auto_correlationated_data);
double spo2_measurement(int32_t *ir_data, int32_t *red_data, uint64_t ir_mean, uint64_t red_mean);
double rms_value(int32_t *data);
double auto_correlation_function(int32_t *data, int32_t lag);

#define BUFFER_SIZE 128
#define DELAY_AMOSTRAGEM 40


#endif
