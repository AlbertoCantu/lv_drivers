/**
 * @file lv_drv_conf.h
 * 
 */

#if 0 /*Remove this to enable the content*/

#ifndef LV_DRV_CONF_H
#define LV_DRV_CONF_H

#include "lv_conf.h"

/*********************
 *      INCLUDES
 *********************/

/*********************
 *       OPTION
 *********************/
#define LV_DRIVER_ENABLE_COMMON 1
#define LV_DRIVER_ENABLE_DELAY 1
#define LV_DRIVER_ENABLE_I2C 1
#define LV_DRIVER_ENABLE_SPI 1
#define LV_DRIVER_ENABLE_PAR 1

/*********************
 * 	HAL INTERFACE
 *********************/
/*
 * All used peripherals must be initialized in user application, library only
 * manipulate them.
 * You can use a device descriptor from your SDK or  do your own in this file too.
 * example:
 * typedef struct lv_spi_dev_t { .... };
 */

/*------------
 *  Delay
 *------------*/
#if LV_DRIVER_ENABLE_DELAY

/**
 * Delay the given number of microseconds
 * @param us Time to wait in us
 */
void lv_delay_us(uint32_t us);

/**
 * Delay the given number of milliseconds
 * @param ms Time to wait in ms
 */
void lv_delay_ms(uint32_t ms);

#endif
/*------------
 *  Common
 *------------*/
#if LV_DRIVER_ENABLE_COMMON

/**
 * Change a pin level
 * @param pin gpio Number
 * @param val Level to set
 */
void lv_gpio_write(uint16_t pin, uint8_t val);

/**
 * Read current level gpio
 * @param pin gpio to read
 * @return gpio value
 */
uint8_t lv_gpio_read(uint16_t pin);

#endif
/*---------
 *  I2C
 *---------*/
#if LV_DRIVER_ENABLE_I2C

/**
 * Do a I2C write transmission on 8 bits register device.
 * @param i2c_dev Pointer to i2c device
 * @param reg Pointer to register address to send if non-null
 * @param data_out Pointer to data buffer to send if non-null
 * @param datalen Number of data byte to send
 * @return Non-Zero if error occured
 */
int lv_i2c_write(void* i2c_dev, const uint8_t* reg, const void* data_out, uint16_t datalen);

/**
 * Do a I2C read transmission on 8 bits register device.
 * @param i2c_dev Pointer to i2c device
 * @param reg Pointer to register address to send if non-null
 * @param data_out Pointer to data buffer to send if non-null
 * @param datalen Number of data byte to send
 * @return Non-Zero if error occured
 */
int lv_i2c_read(void* i2c_dev, const uint8_t* reg, void* data_in, uint16_t datalen);

/**
 * Do a I2C write transmissionon 16 bits register device
 * @param i2c_dev Pointer to i2c device
 * @param reg Pointer to register address to send if non-null
 * @param data_out Pointer to data buffer to send if non-null
 * @param datalen Number of data byte to send
 * @return Non-Zero if error occured
 */
int lv_i2c_write16(void* i2c_dev, const uint16_t* reg, const void* data_out, uint16_t datalen);

/**
 * Do a I2C write transmissionon 16 bits register device.
 * @param i2c_dev Pointer to i2c device
 * @param reg Pointer to register address to send if non-null
 * @param data_out Pointer to data buffer to send if non-null
 * @param datalen Number of data byte to send
 * @return Non-Zero if error occured
 */
int lv_i2c_read16(void* i2c_dev, const uint16_t* reg, void* data_in, uint16_t datalen);

#endif
/*---------
 *  SPI
 *---------*/
#if LV_DRIVER_ENABLE_SPI

/**
 * Do a SPI transaction .
 * @param spi_dev Pointer to spi device
 * @param data_in Receive buffer. If NULL, received data will be lost.
 * @param data_out Data to send buffer. If NULL, it will only receive data.
 * @param len Buffer size in words
 * @param word_size Size of the word in byte
 * @return Non-Zero if error occured
 */
int lv_spi_transaction(void* spi_dev, void* data_in, const void* data_out, uint16_t len, uint8_t word_size);

/**
 * Do a SPI repeat send.
 * @param spi_dev Pointer to spi device
 * @param template Pointer toTemplate to send throw spi (Send 0 if NULL )
 * @param repeats Copy number
 * @param template_size Size of the template in byte
 * @return Non-Zero if error occured
 */
int lv_spi_repeat(void* spi_dev, const void* template, uint32_t repeats, uint8_t template_size);

/**
 * Set command to send for spi transaction
 * @param spi_dev Pointer to spi device
 * @param value Value
 * @param bits Bits number
 * @return Non-Zero if error occured
 */
int lv_spi_set_command(void* spi_dev, uint32_t value, uint8_t bits);

/**
 * Set address to send for spi transaction
 * @param spi_dev Pointer to spi device
 * @param value Value
 * @param bits Bits number
 * @return Non-Zero if error occured
 */
int lv_spi_set_address(void* spi_dev, uint32_t value, uint8_t bits);

/**
 * Set Dummy bits to send for spi transaction
 * @param spi_dev Pointer to spi device
 * @param bits Bits number
 * @return Non-Zero if error occured
 */
int lv_spi_set_dummy(void* spi_dev, uint8_t bits);

/**
 * Clear spi bus command
 * @param spi_dev Pointer to spi device
 * @return Non-Zero if error occured
 */
int lv_spi_clear_command(void* spi_dev);

/**
 * Clear spi bus address
 * @param spi_dev Pointer to spi device
 * @return Non-Zero if error occured
 */
int lv_spi_clear_address(void* spi_dev);

/**
 * Clear spi bus dummy bits
 * @param spi_dev Pointer to spi device
 * @return Non-Zero if error occured
 */
int lv_spi_clear_dummy(void* spi_dev);

#endif
/*------------------
 *  Parallel port
 *-----------------*/
#if LV_DRIVER_ENABLE_PAR
/**
 * Do a Parallel port write.
 * @param par_dev Pointer to parallel port device
 * @param data_out Pointer to data buffer to send
 * @param len Buffer size in words
 * @param word_size Size of the word in byte
 * @return Non-Zero if error occured
 */
int lv_par_write(void* par_dev, const void* data_out, uint16_t len, uint8_t word_size));


/**
 * Do a Parallel port read.
 * @param par_dev Pointer to parallel port device
 * @param data_in Pointer to data buffer to read
 * @param len Buffer size in words
 * @param word_size Size of the word in byte
 * @return Non-Zero if error occured
 */
int lv_par_read(void* par_dev, void* data_in, uint16_t len, uint8_t word_size);

#endif
/*********************
 *  DISPLAY DRIVERS
 *********************/

/*-------------------
 *  Monitor of PC
 *-------------------*/
#define USE_MONITOR         0
#if USE_MONITOR
#define MONITOR_HOR_RES     LV_HOR_RES
#define MONITOR_VER_RES     LV_HOR_VER
#endif

/*----------------
 *    SSD1963
 *--------------*/
#define USE_SSD1963         0
#if USE_SSD1963
#define SSD1963_HOR_RES     LV_HOR_RES
#define SSD1963_VER_RES     LV_VER_RES
#define SSD1963_HDP         479
#define SSD1963_HT          531
#define SSD1963_HPS         43
#define SSD1963_LPS         8
#define SSD1963_HPW         10
#define SSD1963_VDP         271
#define SSD1963_VT          288
#define SSD1963_VPS         12
#define SSD1963_FPS         4
#define SSD1963_VPW         10
#define SSD1963_HS_NEG      0   /*Negative hsync*/
#define SSD1963_VS_NEG      0   /*Negative vsync*/
#define SSD1963_ORI         0   /*0, 90, 180, 270*/
#define SSD1963_COLOR_DEPTH 16
#endif

/*----------------
 *    SSD1306
 *--------------*/
#define USE_SSD1306        1
#if USE_SSD1306
#define SSD1306_HOR_RES     LV_HOR_RES
#define SSD1306_VER_RES     LV_VER_RES
#define SSD1306_I2C_SUPPORT  1
#define SSD1306_SPI4_SUPPORT 1
#define SSD1306_SPI3_SUPPORT 1
#define SSD1306_MANUAL_DC	 1
#define SSD1306_MANUAL_CS	 1
#endif

/*----------------
 *    R61581
 *--------------*/
#define USE_R61581          0
#if USE_R61581 != 0
#define R61581_HOR_RES      LV_HOR_RES
#define R61581_VER_RES      LV_VER_RES
#define R61581_HDP          479
#define R61581_HT           531
#define R61581_HPS          43
#define R61581_LPS          8
#define R61581_HPW          10
#define R61581_VDP          271
#define R61581_VT           319
#define R61581_VPS          12
#define R61581_FPS          4
#define R61581_VPW          10
#define R61581_HS_NEG       0       /*Negative hsync*/
#define R61581_VS_NEG       0       /*Negative vsync*/
#define R61581_ORI          180     /*0, 90, 180, 270*/
#define R61581_LV_COLOR_DEPTH 16
#endif

/*------------------------------
 *  ST7565 (Monochrome, low res.)
 *-----------------------------*/
#define USE_ST7565          0
#if USE_ST7565 != 0
/*No settings*/
#endif  /*USE_ST7565*/

/*-----------------------------------------
 *  Linux frame buffer device (/dev/fbx)
 *-----------------------------------------*/
#define USE_FBDEV           0
#if USE_FBDEV != 0
#define FBDEV_PATH          "/dev/fb0"
#endif

/*====================
 * Input devices
 *===================*/

/*--------------
 *    XPT2046
 *--------------*/
#define USE_XPT2046         0
#if USE_XPT2046 != 0
#define XPT2046_HOR_RES     480
#define XPT2046_VER_RES     320
#define XPT2046_X_MIN       200
#define XPT2046_Y_MIN       200 
#define XPT2046_X_MAX       3800
#define XPT2046_Y_MAX       3800
#define XPT2046_AVG         4 
#define XPT2046_INV         0 
#endif

/*-----------------
 *    FT5406EE8
 *-----------------*/
#define USE_FT5406EE8       0
#if USE_FT5406EE8
#define FT5406EE8_I2C_ADR   0x38                  /*7 bit address*/
#endif

/*-------------------------------
 *    Mouse or touchpad on PC
 *------------------------------*/
#define USE_MOUSE           0
#if USE_MOUSE
/*No settings*/
#endif


/*-------------------------------
 *   Keyboard of a PC
 *------------------------------*/
#define USE_KEYBOARD        0
#if USE_KEYBOARD
/*No settings*/
#endif

#endif  /*LV_DRV_CONF_H*/

#endif /*Remove this to enable the content*/
