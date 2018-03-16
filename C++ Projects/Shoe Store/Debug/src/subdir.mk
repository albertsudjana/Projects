################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CISProject.cpp \
../src/Order.cpp \
../src/Shoes.cpp \
../src/Shoes2.cpp 

OBJS += \
./src/CISProject.o \
./src/Order.o \
./src/Shoes.o \
./src/Shoes2.o 

CPP_DEPS += \
./src/CISProject.d \
./src/Order.d \
./src/Shoes.d \
./src/Shoes2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


