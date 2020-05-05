
MY_BUILD_SHARED  :=  0

#########################################################
#########################################################

LOCAL_PATH := $(call my-dir)/../

include $(CLEAR_VARS)
LOCAL_MODULE := boost_context

LOCAL_ARM_MODE := arm
LOCAL_CPPFLAGS := -DANDROID -O3 -frtti -fexceptions -fvisibility=hidden -fvisibility-inlines-hidden -D__STDC_LIMIT_MACROS -fpermissive -fPIC -DPIC

LOCAL_C_INCLUDES := \
$(LOCAL_PATH)/ \

$(info LOCAL_C_INCLUDES=$(LOCAL_C_INCLUDES))

LOCAL_SRC_FILES := \
./libs/context/src/posix/stack_traits.cpp \
./libs/context/src/execution_context.cpp \

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
	LOCAL_SRC_FILES += \
	./libs/context/src/asm/make_arm_aapcs_elf_gas.S \
	./libs/context/src/asm/jump_arm_aapcs_elf_gas.S \
	./libs/context/src/asm/ontop_arm_aapcs_elf_gas.S
endif


ifeq ($(TARGET_ARCH_ABI),arm64-v8a)
	LOCAL_SRC_FILES += \
	./libs/context/src/asm/jump_arm64_aapcs_elf_gas.S \
	./libs/context/src/asm/make_arm64_aapcs_elf_gas.S \
	./libs/context/src/asm/ontop_arm64_aapcs_elf_gas.S



#jump_arm64_aapcs_elf_gas.S
#jump_arm64_aapcs_macho_gas.S
#make_arm64_aapcs_elf_gas.S
#make_arm64_aapcs_macho_gas.S
#ontop_arm64_aapcs_elf_gas.S
#ontop_arm64_aapcs_macho_gas.S

endif

ifeq ($(TARGET_ARCH_ABI),x86)
	LOCAL_SRC_FILES += \
	./libs/context/src/asm/make_i386_sysv_elf_gas.S \
	./libs/context/src/asm/jump_i386_sysv_elf_gas.S \
	./libs/context/src/asm/ontop_i386_sysv_elf_gas.S
endif


ifeq ($(MY_BUILD_SHARED),1)
	include $(BUILD_SHARED_LIBRARY)
else
	include $(BUILD_STATIC_LIBRARY)
endif

#######################

include $(CLEAR_VARS)
LOCAL_MODULE := boost_coroutine
LOCAL_ARM_MODE := arm
LOCAL_CPPFLAGS := -DANDROID -O3 -frtti -fexceptions -fvisibility=hidden -fvisibility-inlines-hidden -D__STDC_LIMIT_MACROS -fpermissive -fPIC -DPIC

LOCAL_C_INCLUDES := \
$(LOCAL_PATH)/ \

LOCAL_SRC_FILES := \
./libs/coroutine/src/detail/coroutine_context.cpp \
./libs/coroutine/src/exceptions.cpp \
./libs/coroutine/src/posix/stack_traits.cpp \

LOCAL_SHARED_LIBRARIES += boost_context boost_system boost_thread

ifeq ($(MY_BUILD_SHARED),1)
        include $(BUILD_SHARED_LIBRARY)
else
        include $(BUILD_STATIC_LIBRARY)
endif

#######################

include $(CLEAR_VARS)
LOCAL_MODULE := boost_date_time
LOCAL_ARM_MODE := arm
LOCAL_CPPFLAGS := -DANDROID -O3 -frtti -fexceptions -fvisibility=hidden -fvisibility-inlines-hidden -D__STDC_LIMIT_MACROS -fpermissive -fPIC -DPIC

LOCAL_C_INCLUDES := \
$(LOCAL_PATH)/ \

LOCAL_SRC_FILES := \
./libs/date_time/src/gregorian/date_generators.cpp \
./libs/date_time/src/gregorian/greg_month.cpp \
./libs/date_time/src/gregorian/greg_weekday.cpp \


ifeq ($(MY_BUILD_SHARED),1)
        include $(BUILD_SHARED_LIBRARY)
else
        include $(BUILD_STATIC_LIBRARY)
endif

#######################

include $(CLEAR_VARS)
LOCAL_MODULE := boost_system
LOCAL_ARM_MODE := arm
LOCAL_CPPFLAGS := -DANDROID -O3 -frtti -fexceptions -D__STDC_LIMIT_MACROS -fpermissive -fPIC -DPIC

LOCAL_C_INCLUDES := \
$(LOCAL_PATH)/ \

LOCAL_SRC_FILES := \
./libs/system/src/error_code.cpp \


ifeq ($(MY_BUILD_SHARED),1)
        include $(BUILD_SHARED_LIBRARY)
else
        include $(BUILD_STATIC_LIBRARY)
endif

#######################

include $(CLEAR_VARS)
LOCAL_MODULE := boost_thread
LOCAL_ARM_MODE := arm
LOCAL_CPPFLAGS := -DANDROID -O3 -frtti -fexceptions -fvisibility=hidden -fvisibility-inlines-hidden -D__STDC_LIMIT_MACROS -fpermissive -fPIC -DPIC

LOCAL_C_INCLUDES := \
$(LOCAL_PATH)/ \

LOCAL_SRC_FILES := \
./libs/thread/src/pthread/once.cpp \
./libs/thread/src/pthread/thread.cpp \
./libs/thread/src/tss_null.cpp \
./libs/thread/src/future.cpp \

#./libs/thread/src/pthread/once_atomic.cpp \

LOCAL_SHARED_LIBRARIES += boost_system

ifeq ($(MY_BUILD_SHARED),1)
        include $(BUILD_SHARED_LIBRARY)
else
        include $(BUILD_STATIC_LIBRARY)
endif

#######################

include $(CLEAR_VARS)
LOCAL_MODULE := boost_filesystem
LOCAL_ARM_MODE := arm
LOCAL_CPPFLAGS := -DANDROID -O3 -frtti -fexceptions -fvisibility=hidden -fvisibility-inlines-hidden -D__STDC_LIMIT_MACROS -fpermissive -fPIC -DPIC

LOCAL_C_INCLUDES := \
$(LOCAL_PATH)/ \

LOCAL_SRC_FILES := \
./libs/filesystem/src/codecvt_error_category.cpp \
./libs/filesystem/src/operations.cpp \
./libs/filesystem/src/path_traits.cpp \
./libs/filesystem/src/path.cpp \
./libs/filesystem/src/portability.cpp \
./libs/filesystem/src/unique_path.cpp \
./libs/filesystem/src/utf8_codecvt_facet.cpp \
./libs/filesystem/src/windows_file_codecvt.cpp \

LOCAL_SHARED_LIBRARIES += boost_system

ifeq ($(MY_BUILD_SHARED),1)
        include $(BUILD_SHARED_LIBRARY)
else
        include $(BUILD_STATIC_LIBRARY)
endif

