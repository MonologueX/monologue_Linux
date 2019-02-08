WORK_DIR=$(shell pwd)
cc=gcc
bin=httpd 
src=httpd.c
LDFLAGS=-lpthread

$(bin):$(src)
	$(cc) -o $@ $^ $(LDFLAGS)

.PHONY:clean
	rm -f $(bin)
