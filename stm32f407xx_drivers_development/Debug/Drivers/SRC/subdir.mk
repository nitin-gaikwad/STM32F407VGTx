################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/SRC/I2C_driver.c \
../Drivers/SRC/SPI_driver.c \
../Drivers/SRC/stm32f407xx_gpio_driver.c 

OBJS += \
./Drivers/SRC/I2C_driver.o \
./Drivers/SRC/SPI_driver.o \
./Drivers/SRC/stm32f407xx_gpio_driver.o 

C_DEPS += \
./Drivers/SRC/I2C_driver.d \
./Drivers/SRC/SPI_driver.d \
./Drivers/SRC/stm32f407xx_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SRC/%.o Drivers/SRC/%.su: ../Drivers/SRC/%.c Drivers/SRC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"D:/Ni3/STM32F407VGTx/stm32f407xx_drivers_development/Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-SRC

clean-Drivers-2f-SRC:
	-$(RM) ./Drivers/SRC/I2C_driver.d ./Drivers/SRC/I2C_driver.o ./Drivers/SRC/I2C_driver.su ./Drivers/SRC/SPI_driver.d ./Drivers/SRC/SPI_driver.o ./Drivers/SRC/SPI_driver.su ./Drivers/SRC/stm32f407xx_gpio_driver.d ./Drivers/SRC/stm32f407xx_gpio_driver.o ./Drivers/SRC/stm32f407xx_gpio_driver.su

.PHONY: clean-Drivers-2f-SRC

