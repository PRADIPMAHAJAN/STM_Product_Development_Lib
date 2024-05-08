################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Drivers/Uart/uart.c 

OBJS += \
./Src/Drivers/Uart/uart.o 

C_DEPS += \
./Src/Drivers/Uart/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Drivers/Uart/%.o Src/Drivers/Uart/%.su Src/Drivers/Uart/%.cyclo: ../Src/Drivers/Uart/%.c Src/Drivers/Uart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -c -I../Inc -I"C:/Users/Pradip/STM32CubeIDE/workspace_1.13.1/F4_chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Pradip/STM32CubeIDE/workspace_1.13.1/F4_chip_headers/CMSIS/Include" -I"C:/Users/Pradip/STM32CubeIDE/workspace_1.13.1/Protocol_Development/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Drivers-2f-Uart

clean-Src-2f-Drivers-2f-Uart:
	-$(RM) ./Src/Drivers/Uart/uart.cyclo ./Src/Drivers/Uart/uart.d ./Src/Drivers/Uart/uart.o ./Src/Drivers/Uart/uart.su

.PHONY: clean-Src-2f-Drivers-2f-Uart

