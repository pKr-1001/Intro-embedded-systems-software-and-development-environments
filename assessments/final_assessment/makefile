SHELL=/bin/bash

SOURCES = 	./src/main.c \
			./src/course1.c \
			./src/memory.c \
			./src/stats.c \
			./src/data.c 

INCLUDES = -I include/common/

# Platform Overrides
PLATFORM=HOST

TARGET = c1final

# Compile time
COURSE1=false
VERBOSE=false

# Platform Dependant Variables
ifeq ($(PLATFORM),MSP432)
	# MSP432 dependant build options
	CPU = cortex-m4
	ARCH = armv7e-m
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size

	SOURCES = 	./startup_msp432p401r_gcc.c \
				./system_msp432p401r.c \
				./interrupts_msp432p401r_gcc.c
	
	INCLUDES = 	-I include/CMSIS/ \
				-I include/msp432/

	# Linker Flags
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE) -lm
	
	# Compiler Flags
	CFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs -Wall -g -O0 -std=c99
	CPPFLAGS = -DMSP432 $(INCLUDES)
else
	CC = gcc
	CFLAGS = -Wall -g -O0 -std=c99
	CPPFLAGS = -DHOST $(INCLUDES)
	SIZE = size
	LDFLAGS = -lm
endif

# IF VERBOSE is defined, add a flag
ifeq ($(VERBOSE), true)
	CPPFLAGS += -DVERBOSE
endif

# IF COURSE1 is defined, add a flag
ifeq ($(COURSE1), true)
	CPPFLAGS += -DCOURSE1
endif


PREP = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

.PHONY: compile-all build clean run

# // Build all
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@
	
%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.d: %c
	$(CC) -E -M $<  $(CPPFLAGS) -o $@

# Compile all object files, without linking
compile-all: $(OBJS)

clean:
	rm -f $(OBJS) $(PREP) $(ASMS) $(DEPS) $(TARGET).out $(TARGET).map

# Build all and run file
run: $(TARGET).out
	./$(TARGET).out
