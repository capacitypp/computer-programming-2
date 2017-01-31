OBJS=kadai7.o Color.o JpegImage.o Histogram.o DifferenceWithURL.o ImageRetrieval.o
BUILDPATH=./build
OBJPATHS=$(addprefix $(BUILDPATH)/, $(OBJS))
CPPFLAGS=$(INCLUDE) -Wall -std=c++11 -MMD
LDFLAGS=

all : makefolder $(OBJPATHS)
	$(CXX) -o Main $(LDFLAGS) $(OBJPATHS) libjpeg.a

$(BUILDPATH)/%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -o $@ -c $<

makefolder :
	@mkdir -p $(BUILDPATH)

clean :
	$(RM) *.o
	$(RM) Main
	$(RM) -r -f $(BUILDPATH)

boot :
	./Main

-include $(BUILDPATH)/*.d

