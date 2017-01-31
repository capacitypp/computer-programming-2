#
#	File: Makefile
#	Author: Masaki Aono
#	Date: 12/08/05(日) 21:31:50 creation
#
# Files

CC = gcc
C++ = g++
LIB = libjpeg.a
INCLUDE = -I. -I./include
OPTIMIZE = -O3
CFLAGS = $(CCFLAGS) $(INCLUDE) $(OPTIMIZE)

CFLAGS = -I./include -O3
CFILES = cdjpeg.c jaricom.c jcapimin.c jcapistd.c jcarith.c \
	jccoefct.c jccolor.c jcdctmgr.c jchuff.c jcinit.c jcmainct.c jcmarker.c \
	jcmaster.c jcomapi.c jcparam.c jcprepct.c jcsample.c \
	jctrans.c jdapimin.c jdapistd.c jdarith.c jdatadst.c jdatasrc.c \
	jdcoefct.c jdcolor.c jddctmgr.c jdhuff.c jdinput.c jdmainct.c \
	jdmarker.c jdmaster.c jdmerge.c jdpostct.c jdsample.c jdtrans.c \
	jerror.c jfdctflt.c jfdctfst.c jfdctint.c jidctflt.c jidctfst.c jidctint.c \
	jmemansi.c jmemmgr.c jquant1.c jquant2.c jutils.c rdbmp.c \
	rdcolmap.c rdgif.c rdppm.c rdswitch.c rdtarga.c transupp.c \
	wrbmp.c wrgif.c wrppm.c wrtarga.c 
CPPFILES = jpegio.cpp
OFILES = $(CFILES:.c=.o)
OOFILES = jpegio.o
RANLIB = ranlib

all:MKLIB

MKLIB:$(OFILES) $(OOFILES)
	ar ruv $(LIB) $(OFILES) $(OOFILES)
	$(RANLIB) $(LIB)

jpegio.o: ./include/jpegio.h jpegio.cpp
	$(C++) $(CFLAGS) -c jpegio.cpp
clean:
	rm -f $(OFILES) $(OOFILES)
