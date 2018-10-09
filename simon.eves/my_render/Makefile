MBGL_ROOT = /home/simon.eves/src/mapbox-gl-native

# necessary include dirs for public header tree
INC_DIRS += -I${MBGL_ROOT}/include # regular MBGL includes
INC_DIRS += -I${MBGL_ROOT}/platform/default # for default_styles.hpp only (header only, no deps, could be moved into ^)
INC_DIRS += -I${MBGL_ROOT}/mason_packages/headers/geometry/0.9.3/include # template headers only
INC_DIRS += -I${MBGL_ROOT}/mason_packages/headers/variant/1.1.4/include # template headers only
INC_DIRS += -I${MBGL_ROOT}/vendor/expected/include # template headers only

# necessary lib dirs
# need PNG and JPEG to be the same as Core
LIB_DIRS += -L${MBGL_ROOT}/build/linux-x86_64/Debug
LIB_DIRS += -L${MBGL_ROOT}/mason_packages/linux-x86_64/libpng/1.6.25/lib
LIB_DIRS += -L${MBGL_ROOT}/mason_packages/linux-x86_64/libjpeg-turbo/1.5.0/lib
LIB_DIRS += -L${MBGL_ROOT}/mason_packages/linux-x86_64/libuv/1.9.1/lib

# MBGL static libs
LIBS += -lmbgl-filesource
LIBS += -lmbgl-loop-uv
LIBS += -lmbgl-core
LIBS += -lsqlite
LIBS += -lnunicode
LIBS += -licu

# system DSOs (dlopened)
LIBS += -Wl,--no-as-needed -lcurl -Wl,--as-needed

# system DSOs (auto)
LIBS += -lEGL
LIBS += -lGL
LIBS += -lz
LIBS += -lpthread
LIBS += -ldl

# MBGL/mason static libs
LIBS += -ljpeg
LIBS += -lpng
LIBS += -luv

# compile options
OPTS += -g
OPTS += -fPIE

all: my_render cert

my_render: my_render.cpp Makefile
	g++ my_render.cpp -o my_render ${OPTS} ${INC_DIRS} ${LIB_DIRS} ${LIBS}

cert: ../../misc/ca-bundle.crt
	@cp ../../misc/ca-bundle.crt .

clean:
	@rm -f my_render ca-bundle.crt cache.sqlite *.png
