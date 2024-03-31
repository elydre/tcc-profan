import os, sys

profan_path = "../profanOS"
if sys.argv[1:]:
    profan_path = sys.argv[1]
if not os.path.exists(profan_path):
    print(f"path {profan_path} does not exist")
    exit(1)

CC      = "gcc"
LD      = "ld"

OUTPUT  = "tcc"

CFLAGS  = "-ffreestanding -fno-exceptions -m32 -I ./profan_zlib -I ./local_lib"
LDFLAGS = f"-nostdlib -L {profan_path}/out/zlibs -T link.ld -z max-page-size=0x1000 -lc -lm"

OBJDIR  = "build"
SRCDIR  = "src"

DOOMSRC = [e for e in os.listdir(SRCDIR) if e.endswith(".c")]

def execute_command(cmd):
    print(cmd)
    rcode = os.system(cmd)
    if rcode == 0: return
    print(f"Command failed with exit code {rcode}")
    exit(rcode if rcode < 256 else 1)

def compile_file(src, dir = SRCDIR):
    obj = os.path.join(OBJDIR, f"{os.path.splitext(src)[0]}.o")
    cmd = f"{CC} -c {os.path.join(dir, src)} -o {obj} {CFLAGS}"
    execute_command(cmd)
    return obj

def link_files(entry, objs, output = OUTPUT):
    execute_command(f"{LD} {LDFLAGS} -o {output}.elf {entry} {' '.join(objs)} ")

def main():
    execute_command(f"mkdir -p {OBJDIR}")
    objs = [compile_file(src) for src in DOOMSRC]
    objs.append(compile_file("bordel.c", "local_lib"))

    entry = compile_file("entry.c", ".")
    link_files(entry, objs)

if __name__ == "__main__":
    main()
