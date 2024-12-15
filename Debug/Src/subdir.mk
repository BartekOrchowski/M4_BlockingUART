################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/led.c \
../Src/lpuart.c \
../Src/main.c \
../Src/software_timers.c \
../Src/sys_clocks.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/tester.c 

OBJS += \
./Src/led.o \
./Src/lpuart.o \
./Src/main.o \
./Src/software_timers.o \
./Src/sys_clocks.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/tester.o 

C_DEPS += \
./Src/led.d \
./Src/lpuart.d \
./Src/main.d \
./Src/software_timers.d \
./Src/sys_clocks.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/tester.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32G4 -DSTM32G474xx -DSTM32G474RETx -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/led.cyclo ./Src/led.d ./Src/led.o ./Src/led.su ./Src/lpuart.cyclo ./Src/lpuart.d ./Src/lpuart.o ./Src/lpuart.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/software_timers.cyclo ./Src/software_timers.d ./Src/software_timers.o ./Src/software_timers.su ./Src/sys_clocks.cyclo ./Src/sys_clocks.d ./Src/sys_clocks.o ./Src/sys_clocks.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/tester.cyclo ./Src/tester.d ./Src/tester.o ./Src/tester.su

.PHONY: clean-Src

