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
# <Build system using GNU tools, GCC and GNU Make>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <.i, .asm, .o, compile-all, build, clean>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM=HOST

## Target , creates ./c1m2.out
TARGET = c1m2

# Compiler 
ifeq ($(PLATFORM),MSP432)

	# Architecture Specific Flags
	CPU = cortex-m4
	ARCH = armv7e-m
	
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size

	# // Flatform Specific Flags (MSP432/HOST)
	SOURCES = 	./startup_msp432p401r_gcc.c \
				./system_msp432p401r.c \
				./interrupts_msp432p401r_gcc.c
	
	INCLUDES = 	-I ../include/CMSIS/ \
				-I ../include/msp432/

	# // Linker File
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	
	# -Wall: Enable all warnings -Werror: Treat warnings as errors -g: Debugging -O0: No optimization -std=c99: C99 standard
	CFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -DMSP432 $(INCLUDES)

else
	CC = gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -DHOST $(INCLUDES)
	SIZE = size

endif

# // File Generation: Preprocessor, Assembly, Object, Dependency
PREP = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)	
DEPS = $(SOURCES:.c=.d)	

.PHONY: compile-all
build: $(TARGET).out

# // Build the final output
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@
	
# // Generate the preprocessor files, of all c-program implementation files
%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

# // Generate the assembly files, of all c-program implementation files and final output
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

# // Generate the object files, by specifying object file 
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

# // Generate the dependancy files
%.d: %c
	$(CC) -E -M $<  $(CPPFLAGS) -o $@


.PHONY: compile-all
# // Compile all the source files without linking
compile-all: $(OBJS)

.PHONY: clean
# // Clean the generated files
clean:
	rm -f *.out *.map *.i *.asm *.o *.d
