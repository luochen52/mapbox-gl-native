MBGL_ROOT = /home/simon.eves/src/mapbox-gl-native

INC_DIRS += -I${MBGL_ROOT}/include
INC_DIRS += -I${MBGL_ROOT}/platform/default
#INC_DIRS += -I${MBGL_ROOT}/mason_packages/headers/boost/1.65.1/include
#INC_DIRS += -I${MBGL_ROOT}/mason_packages/headers/geojson/0.4.2/include
INC_DIRS += -I${MBGL_ROOT}/mason_packages/headers/args/6.2.0/include
INC_DIRS += -I${MBGL_ROOT}/mason_packages/headers/geometry/0.9.3/include
INC_DIRS += -I${MBGL_ROOT}/mason_packages/headers/variant/1.1.4/include
#INC_DIRS += -I${MBGL_ROOT}/mason_packages/headers/swiftshader/2018-05-31/include
INC_DIRS += -I${MBGL_ROOT}/mason_packages/headers/libpng/1.6.25/include/libpng16
#INC_DIRS += -I${MBGL_ROOT}/mason_packages/headers/libjpeg-turbo/1.5.0/include
#INC_DIRS += -I${MBGL_ROOT}/mason_packages/headers/libuv/1.9.1/include
INC_DIRS += -I${MBGL_ROOT}/vendor/expected/include
#INC_DIRS += -I${MBGL_ROOT}/vendor/sqlite/include

LIB_DIRS += -L${MBGL_ROOT}/build/linux-x86_64/Debug
LIB_DIRS += -L${MBGL_ROOT}/mason_packages/linux-x86_64/libpng/1.6.25/lib
LIB_DIRS += -L${MBGL_ROOT}/mason_packages/linux-x86_64/libjpeg-turbo/1.5.0/lib
LIB_DIRS += -L${MBGL_ROOT}/mason_packages/linux-x86_64/libuv/1.9.1/lib

# build
LIBS += -lmbgl-filesource
LIBS += -lmbgl-loop-uv
LIBS += -lsqlite
LIBS += -lmbgl-core
LIBS += -lnunicode
LIBS += -licu

# system DSO (dlopened)
LIBS += -Wl,--no-as-needed -lcurl -Wl,--as-needed

# system DSO (auto)
LIBS += -lEGL
LIBS += -lGL
LIBS += -lz
LIBS += -lpthread
LIBS += -ldl

# mason static
LIBS += -ljpeg
LIBS += -lpng
LIBS += -luv

OPTS += -g
OPTS += -fPIE
OPTS += -std=c++14

#OPTS += -static-libstdc++
#OPTS += -ftemplate-depth=1024 # this app doesn't seem to need it
#OPTS += -Wall
#OPTS += -Wextra
#OPTS += -Wshadow
#OPTS += -Wnon-virtual-dtor
#OPTS += -Wno-variadic-macros
#OPTS += -Wno-unknown-pragmas
#OPTS += -Werror
#OPTS += -fext-numeric-literals
#OPTS += -fvisibility=hidden # may need this again if we make a lib
#OPTS += -fvisibility-inlines-hidden # ditto

all: my_render cert

my_render: my_render.cpp Makefile
	g++ my_render.cpp -o my_render ${OPTS} ${INC_DIRS} ${LIB_DIRS} ${LIBS}

cert: ../../misc/ca-bundle.crt
	@cp ../../misc/ca-bundle.crt .

clean:
	@rm -f my_render ca-bundle.crt cache.sqlite *.png
