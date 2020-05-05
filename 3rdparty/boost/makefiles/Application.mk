NDK_TOOLCHAIN_VERSION=clang
APP_STL=c++_shared
APP_CFLAGS := -Wno-error=format-security
APP_ABI := arm64-v8a armeabi-v7a x86
APP_PLATFORM := android-21
APP_CPPFLAGS := -std=c++11
APP_MODULES := boost_context boost_coroutine boost_date_time boost_system boost_thread boost_filesystem

