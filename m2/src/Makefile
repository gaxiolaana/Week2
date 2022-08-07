#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefike for HOST and MSP432 platform
# Author: Ana Gaxiola 
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o [PLATFORM-OVERRIDES] - Builds <FILE>.o object file
#      <FILE>.s [PLATFORM-OVERRIDES] - Generates assembly output of .c file
#      <FILE>.i [PLATFORM-OVERRIDES] - Generates preprocessed output of all .c files
#      build - Builds and links all source files
#      all - Same as build
#      compile-all - Builds but NOT links all source files
#      clean - removes all generated files
#
# Platform Overrides:
#      PLATFORM (either HOST or MSP432)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags (MSP432)
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
MARCH = armv7e-m
ABI = hard
FPU = fpv4-sp-d16
SPECS = nosys.specs

# Compiler Flags and Defines (common)
TARGET = c1m2
STD = c99
CPPFLAGS = -MT $@ -MD -MP -MF $*.d
GENERALFLAGS = -Wall -Werror -g -O0
               
ifeq ($(PLATFORM),HOST)
	# Compiler Flags and Defines (HOST)  
	CC = gcc
	CFLAGS = $(GENERALFLAGS) -std=$(STD) $(INCLUDESGCC) -DHOST
	LDFLAGS = -Wl,-Map=$(TARGET).map
	SRCS = $(SOURCESGCC)
else
	# Compiler Flags and Defines (MSP432)
	PLATFORM = MSP432
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	PTARGET = -DMSP432
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=$(MARCH) -mfloat-abi=$(ABI) -mfpu=$(FPU) --specs=$(SPECS) $(GENERALFLAGS) -std=$(STD) $(INCLUDESMSP) -DMSP432
	SRCS = $(SOURCESMSP)
endif

OBJS = $(SRCS:.c=.o)

%.o : %.c 
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.i : %.c
	$(CC) -E $(CFLAGS) $^
	
%.asm : %.c
	$(CC) -S $(CFLAGS) $<

.PHONY: build
build: all

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -c $< 

.PHONY: all
all: ./$(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ 

DEPFILES := $(SRCS:.c=.d)
$(DEPFILES):
include $(DEPFILES)

.PHONY: clean
clean:
	rm -f *.out *.s *.i *.map *.o *.d

