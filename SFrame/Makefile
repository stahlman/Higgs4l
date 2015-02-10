 ###########################################################################
 # @author James Degenhardt <jdegenha@cern.ch>             - Penn          #
 #                                                                         #
 # Top level Makefile for compiling all the SFrame code                    #
 #                                                                         #
 ###########################################################################
 
DIRS = SFrame D3PDObjects AtlasSFrameUtils CommonTools ZZSelection 
#Zgamma ZXSelection
#DIRS = ZXSelection


all::
	@ for dir in $(DIRS); \
	do (cd $$dir && make ); \
	done

clean::
	@ for dir in $(DIRS); \
	do (cd $$dir && make clean ); \
	done

distclean::
	@ for dir in $(DIRS); \
	do (cd $$dir && make distclean ); \
	done

