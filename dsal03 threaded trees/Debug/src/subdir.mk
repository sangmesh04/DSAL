################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/dsal03\ threaded\ trees.cpp 

OBJS += \
./src/dsal03\ threaded\ trees.o 

CPP_DEPS += \
./src/dsal03\ threaded\ trees.d 


# Each subdirectory must supply rules for building sources it contributes
src/dsal03\ threaded\ trees.o: ../src/dsal03\ threaded\ trees.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/dsal03 threaded trees.d" -MT"src/dsal03\ threaded\ trees.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


