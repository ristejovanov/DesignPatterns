This are Android mk files to build boost static libraries.

This prebuilted static libraries should be put in MINC/Genesis/3rdparty/asio-boost/lib/android/XXX but usually
they are already in the repository. 

How to build:

* download boost source code
* unpack
* create jni folder and put Android.mk, Application.mk, in this folder
* build it with: ndk-build
