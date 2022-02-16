################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
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
Drivers/SRC/%.o: ../Drivers/SRC/%.c Drivers/SRC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"E:/LAB/STM32F407/STM32_projects/STM32F407VGTx/stm32f407xx_drivers_development/Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-SRC

clean-Drivers-2f-SRC:
	-$(RM) ./Drivers/SRC/I2C_driver.d ./Drivers/SRC/I2C_driver.o ./Drivers/SRC/SPI_driver.d ./Drivers/SRC/SPI_driver.o ./Drivers/SRC/stm32f407xx_gpio_driver.d ./Drivers/SRC/stm32f407xx_gpio_driver.o

.PHONY: clean-Drivers-2f-SRC

