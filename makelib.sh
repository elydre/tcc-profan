CFLAGS="-m32 -I profan_zlib -Wno-implicit-function-declaration"

mkdir -p build_lib

tcc $CFLAGS -c lib/libtcc1.c -o build_lib/libtcc1.o
tcc $CFLAGS -c lib/alloca.S -o build_lib/alloca.o
tcc $CFLAGS -c lib/alloca-bt.S -o build_lib/alloca-bt.o
tcc $CFLAGS -c lib/stdatomic.c -o build_lib/stdatomic.o
tcc $CFLAGS -c lib/atomic.S -o build_lib/atomic.o
tcc $CFLAGS -c lib/builtin.c -o build_lib/builtin.o
tcc $CFLAGS -c lib/tcov.c -o build_lib/tcov.o
tcc $CFLAGS -c lib/va_list.c -o build_lib/va_list.o
tcc $CFLAGS -c lib/dsohandle.c -o build_lib/dsohandle.o
ar rcs libtcc.a build_lib/libtcc1.o build_lib/alloca.o build_lib/alloca-bt.o build_lib/stdatomic.o build_lib/atomic.o build_lib/builtin.o build_lib/tcov.o build_lib/va_list.o build_lib/dsohandle.o
