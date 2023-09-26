CC = g++ #compile
CFLAGS = -g -Wall -Wextra
Target = Steganography

default
default: Steg

Commands
Steg: $(Target)

$(Target): main.o Steganography.o 
    $(CC) $(CFlags) -o $(Target) main.o Steganography.o


Steganography.o:    Steganography.cpp Steganography.h
    $(CC) $(CFLAGS) -c Steganography.cpp


main.o:    main.cpp Steganography.h
    $(CC) $(CFLAGS) -c main.cpp

Now the logic to clean using "make clean"
clean:
    $(RM) $(Target) .o~