CFLAGS="-m32 -nostdlib -I profan_zlib -ffreestanding -fno-exceptions -fno-stack-protector -nostdinc -O1"
OUTDIR="build_lib/"

rm -rf $OUTDIR
mkdir $OUTDIR

gcc $CFLAGS -c libtcc/libtcc1.c -o $OUTDIR/libtcc1.o
gcc $CFLAGS -c libtcc/alloca.S -o $OUTDIR/alloca.o
gcc $CFLAGS -c libtcc/alloca-bt.S -o $OUTDIR/alloca-bt.o
gcc $CFLAGS -c libtcc/stdatomic.c -o $OUTDIR/stdatomic.o
gcc $CFLAGS -c libtcc/atomic.S -o $OUTDIR/atomic.o
gcc $CFLAGS -c libtcc/builtin.c -o $OUTDIR/builtin.o
gcc $CFLAGS -c libtcc/tcov.c -o $OUTDIR/tcov.o
gcc $CFLAGS -c libtcc/va_list.c -o $OUTDIR/va_list.o
gcc $CFLAGS -c libtcc/dsohandle.c -o $OUTDIR/dsohandle.o

ar rcs libtcc1.a $OUTDIR*.o
