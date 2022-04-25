#ifndef AD5641_H
#define AD5641_H
#include "typedef_global.h"

typedef enum{
    AD5641_NormalOperation,
    AD5641_1k_toGND,
    AD5641_100k_toGND,
    AD5641_ThreeState,
} AD5641_OutputType;


typedef struct{
    uint32_t data_pin;
    uint32_t clk_pin;
    uint32_t sync_pin;
    AD5641_OutputType output_type;
    uint32_t value;
}AD5641;



bool ad5641_write(AD5641 *pdev, uint32_t value);
#endif