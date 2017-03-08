CC=avr-gcc
CFLAGS=-g3 -Os -Wall -pedantic -ffunction-sections -fdata-sections \
       -mmcu=atmega2560
DEFINES=-DF_CPU=16000000L -MMD -DUSB_VID=null -D__PROG_TYPES_COMPAT__
INCLUDES=
LINKFLAGS=-Os -Wl,--gc-sections,--relax -mmcu=atmega2560
OBJCOPY=avr-objcopy
HEXFLAGS=-O ihex -R .eeprom 

AVRDUDE=avrdude
DUDEFLAGS=-pm2560 -cwiring -P/dev/ttyACM0 -b115200 -D

all: main.hex main.elf

main.o:
	$(CC) $(CFLAGS) $(DEFINES) -c -o main.o main.c

main.elf: main.o
	$(CC) $(LINKFLAGS) -o main.elf main.o

main.hex: main.elf
	$(OBJCOPY) $(HEXFLAGS) main.elf main.hex


clean:
	rm *.o *.hex *.elf *.d


install: all
	$(AVRDUDE) $(DUDEFLAGS) -Uflash:w:main.hex:i
