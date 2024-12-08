import os, sys

profan_path = "../profanOS"
if sys.argv[1:]:
    profan_path = sys.argv[1]
if not os.path.exists(profan_path):
    print(f"path {profan_path} does not exist")
    exit(1)

CC      = "gcc"
LD      = "ld"
AR      = "ar"

TCC_NAME  = "tcc"
LIB_NAME  = "libtcc"

CC_FLAGS = f"-ffreestanding -fno-exceptions -m32 -nostdinc -O3 -fno-stack-protector -fno-omit-frame-pointer -I {profan_path}/include/zlibs -I {profan_path}/include/addons"
SO_FLAGS = f"-m elf_i386 -L {profan_path}/out/zlibs -nostdlib -shared"
LD_FLAGS = f"-nostdlib -L {profan_path}/out/zlibs -T link.ld -lc -lm"

OBJDIR  = "build"
SRCDIR  = "src"

TCCSRC = [e for e in os.listdir(SRCDIR) if e.endswith(".c")]

def execute_command(cmd):
    print(cmd)
    rcode = os.system(cmd)
    if rcode == 0: return
    print(f"Command '{cmd}' failed with exit code {rcode}")
    exit(rcode if rcode < 256 else 1)

def compile_file(src, dir = SRCDIR, pic = False):
    obj = os.path.join(OBJDIR, f"{os.path.splitext(src)[0]}.o")
    cmd = f"{CC} -c {os.path.join(dir, src)} -o {obj} {CC_FLAGS}{f' -fPIC' if pic else ''}"
    execute_command(cmd)
    return obj

def link_to_exec(entry, objs):
    execute_command(f"{LD} {LD_FLAGS} -o {TCC_NAME}.elf {entry} {' '.join(objs)} {LIB_NAME}.a")

def link_to_lib(objs):
    execute_command(f"{LD} {SO_FLAGS} -o {LIB_NAME}.so {' '.join(objs)} -lc -lm")
    execute_command(f"{AR} rcs {LIB_NAME}.a {' '.join(objs)} ")

def main():
    execute_command(f"mkdir -p {OBJDIR}")
    objs = [compile_file(src, pic = True) for src in TCCSRC if src != "tcc.c"]

    link_to_lib(objs)

    link_to_exec(compile_file("entry.c", "."), [compile_file("tcc.c")])

    print("=== Done ===")

if __name__ == "__main__":
    main()
