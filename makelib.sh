CFLAGS="-m32 -nostdlib -I profan_zlib -ffreestanding -fno-exceptions -fno-stack-protector -nostdinc -O1"
OUTDIR="build_lib/"

rm -rf $OUTDIR
mkdir $OUTDIR

gcc $CFLAGS -c lib/libtcc1.c -o $OUTDIR/libtcc1.o
gcc $CFLAGS -c lib/alloca.S -o $OUTDIR/alloca.o
gcc $CFLAGS -c lib/alloca-bt.S -o $OUTDIR/alloca-bt.o
gcc $CFLAGS -c lib/stdatomic.c -o $OUTDIR/stdatomic.o
gcc $CFLAGS -c lib/atomic.S -o $OUTDIR/atomic.o
gcc $CFLAGS -c lib/builtin.c -o $OUTDIR/builtin.o
gcc $CFLAGS -c lib/tcov.c -o $OUTDIR/tcov.o
gcc $CFLAGS -c lib/va_list.c -o $OUTDIR/va_list.o
gcc $CFLAGS -c lib/dsohandle.c -o $OUTDIR/dsohandle.o

ar rcs libtcc.a $OUTDIR*.o
