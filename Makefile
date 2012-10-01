main.ihx: main.c
	sdcc $(^)

main.bin: main.ihx
	hex2bin main.ihx

stcdude: main.bin
	stcdude -p "/dev/ttyUSB0" \
	-b 1200:57600 \
	-a wflash -f $(^)

