################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Git-Manne-Robson-1.cpp 

OBJS += \
./src/Git-Manne-Robson-1.o 

CPP_DEPS += \
./src/Git-Manne-Robson-1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -DIL_STD -I/home/lapo/cplex/cplex126/concert/include -I/home/lapo/cplex/cplex126/cplex/include -O0 -g3 -Wall -c -fmessage-length=0 -m64 -O -fPIC -fexceptions -DIL_STD -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" -c "$<"
	@echo 'Finished building: $<'
	@echo ' '


