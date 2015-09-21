CC=g++
CFLAGS= -std=c++11
objects = AnalyzeImpl_LTE_PS_DATASTAT.o AnalyzeImpl_LTE_PS_APPSTAT.o AnalyzeImplBase.o AnalyzeImpl_LTE.o \
 LogInfoBase.o LogInfo_LTE_Attach.o LogInfo_LTE_CS_CSFB.o LogInfo_LTE_PS.o LTE_PS_DataStat.o

all:$(objects)
#	g++   -o libevent_server $(objects) -Wl,-dn -std=c++11 -levent -lnettle -lz -luuid -Wl,-dy -lpthread
$(objects): %.o: %.cpp
	$(CC) -c -g $(CFLAGS) $< -o $@
clean:
	rm -f *.o 
