################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Drivers/GPIO/gpioDriver.c 

OBJS += \
./Src/Drivers/GPIO/gpioDriver.o 

C_DEPS += \
./Src/Drivers/GPIO/gpioDriver.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Drivers/GPIO/%.o Src/Drivers/GPIO/%.su Src/Drivers/GPIO/%.cyclo: ../Src/Drivers/GPIO/%.c Src/Drivers/GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -c -I../Inc -I"C:/Users/Pradip/STM32CubeIDE/workspace_1.13.1/F4_chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Pradip/STM32CubeIDE/workspace_1.13.1/F4_chip_headers/CMSIS/Include" -I"C:/Users/Pradip/STM32CubeIDE/workspace_1.13.1/Protocol_Development/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Drivers-2f-GPIO

clean-Src-2f-Drivers-2f-GPIO:
	-$(RM) ./Src/Drivers/GPIO/gpioDriver.cyclo ./Src/Drivers/GPIO/gpioDriver.d ./Src/Drivers/GPIO/gpioDriver.o ./Src/Drivers/GPIO/gpioDriver.su

.PHONY: clean-Src-2f-Drivers-2f-GPIO

