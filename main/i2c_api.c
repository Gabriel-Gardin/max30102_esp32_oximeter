#include "i2c_api.h"

i2c_port_t i2c_port = 0;

esp_err_t i2c_init(void)
{
	i2c_config_t i2c_configuration = {
			.mode              = I2C_MODE_MASTER, //I2C COMO MASTER
			.sda_io_num        = SDA_PIN,
			.sda_pullup_en     = 1,
			.scl_io_num        = SCL_PIN,
			.scl_pullup_en     = 1,
			.master.clk_speed  = 200000           //SCL CLOCK SPEED 200KHZ
	};
	i2c_param_config(i2c_port, &i2c_configuration);
	esp_err_t err = i2c_driver_install(i2c_port, i2c_configuration.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
	return err;
}

esp_err_t i2c_sensor_read(uint8_t *data_rd, size_t size)
{
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (MAX30102_ADDR << 1) | I2C_MASTER_READ, ACK_CHECK_EN);
    if (size > 1) {
        i2c_master_read(cmd, data_rd, size - 1, ACK_VAL);
    }
    i2c_master_read_byte(cmd, data_rd + size - 1, NACK_VAL);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(i2c_port, cmd, 1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);
    return ret;
}


esp_err_t i2c_sensor_write(uint8_t *data_wr, size_t size)
{
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (MAX30102_ADDR << 1) | I2C_MASTER_WRITE, ACK_CHECK_EN);
    i2c_master_write(cmd, data_wr, size, ACK_CHECK_EN);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(i2c_port, cmd, 1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);
    return ret;
}


