################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/dsal06\ adjancency\ graph.cpp 

OBJS += \
./src/dsal06\ adjancency\ graph.o 

CPP_DEPS += \
./src/dsal06\ adjancency\ graph.d 


# Each subdirectory must supply rules for building sources it contributes
src/dsal06\ adjancency\ graph.o: ../src/dsal06\ adjancency\ graph.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/dsal06 adjancency graph.d" -MT"src/dsal06\ adjancency\ graph.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


