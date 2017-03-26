#
# (C) Copyright 2012-2017
# Software Engineering, depply@126.com.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
#

BINS	= queue_test

#
# Use native tools and options
#
CPPFLAGS   = -idirafter ./include -DTEXT_BASE=$(TEXT_BASE) -DUSE_HOSTCC
CFLAGS     = $(HOST_CFLAGS) $(CPPFLAGS) -O
AFLAGS	   = -D__ASSEMBLY__ $(CPPFLAGS)
MAKEDEPEND = makedepend
CC	   = gcc
STRIP	   = strip

all: $(BINS) 

queue_test: queue_test.o

clean:
	rm -f *.o queue_test

