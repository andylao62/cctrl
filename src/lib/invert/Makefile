###############################################################################
## Copyright(C) 2013-2014 Qiware technology Co., Ltd
##
## 文件名: Makefile
## 版本号: 1.0
## 描  述: 倒排索引模块的编译
## 作  者: # Qifeng.zou # 2015.04.22 #
###############################################################################
include $(PROJ)/make/build.mak

INCLUDE = -I. \
		  -I$(PROJ)/src/incl
INCLUDE += $(GLOBAL_INCLUDE)
LIBS_PATH = -L$(PROJ)/lib
LIBS = -lpthread -lcore
LIBS += $(SHARED_LIB)

SRC_LIST = invtab.c

OBJS = $(subst .c,.o, $(SRC_LIST))
HEADS = $(call func_get_dep_head_list, $(SRC_LIST))

TARGET = libinvtab.so
TARGET_A = libinvtab.a

.PHONY: all clean

all: $(TARGET) $(TARGET_A)
$(TARGET): $(OBJS)
	@$(CC) $(LFLAGS) -o $@ $(OBJS) $(INCLUDE) $(LIBS_PATH) $(LIBS)
	@echo "CC $@"
	@mv $@ $(PROJ_LIB)
	@echo "$@ is OK!"

$(TARGET_A): $(OBJS)
	@$(AR) $(AFLAGS) -s $@ $(OBJS)
	@echo "AR $@"
	@mv $@ $(PROJ_LIB)
	@echo "$@ is OK!"

$(OBJS): %.o : %.c $(HEADS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "CC $(PWD)/$<"

clean:
	@rm -fr *.o $(PROJ_LIB)/$(TARGET) $(PROJ_LIB)/$(TARGET_A)
	@echo "rm -fr *.o $(PROJ_LIB)/$(TARGET) $(PROJ_LIB)/$(TARGET_A)"
