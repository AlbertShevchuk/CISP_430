CC = gcc
CFLAGS = -O0 -Wall -g
ASFLAGS = -g -gstabs
CXXFLAGS = -O0 -Wall -g
LDFLAGS = -g
CSRC = main.c #strfcpy.c
CCSRC = 
EXE = main
INC = 
ASRC =  strfcpy.S

$(EXE):	$(CSRC:.c=.o) $(ASRC:.S=.o) $(CCSRC:.cpp=.o)

%.d: %.c
	$(CC) $^ -MM -MF $@

%.d: %.cpp
	$(CC) $^ -MM -MF $@

%.d: %.S
	$(CC) $^ -MM -MF $@

clean:	
	rm -f $(EXE) $(CSRC:.c=.o) $(ASRC:.S=.o) $(CSRC:.c=.d) $(ASRC:.S=.d) $(INC) $(CCSRC:.cpp=.o)

$(EXE).gdb: $(EXE)
	gdb $(EXE)

$(EXE).test: $(EXE)
	gdb $(EXE) < test.gdb

include $(CSRC:.c=.d)
include $(ASRC:.S=.d)
