################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Segment\ Trees.cpp 

OBJS += \
./Segment\ Trees.o 

CPP_DEPS += \
./Segment\ Trees.d 


# Each subdirectory must supply rules for building sources it contributes
Segment\ Trees.o: ../Segment\ Trees.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"Segment Trees.d" -MT"Segment\ Trees.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


