Tiny C Compiler - C Scripting Everywhere - The Smallest ANSI C compiler
-----------------------------------------------------------------------

### build tcc.elf (for profanOS)
```
python3 build.py
```

### build libtcc.a (for profanOS)
```
sh makelib.sh
```

### copy tcc.elf and libtcc.a to profanOS
```
cp tcc.elf (profanOS)/out/zapps/fatpath/
cp libtcc.a (profanOS)/out/sys/
```

Features:
--------

- SMALL! You can compile and execute C code everywhere, for example on
  rescue disks.

- FAST! tcc generates optimized x86 code. No byte code
  overhead. Compile, assemble and link about 7 times faster than 'gcc
  -O0'.

- UNLIMITED! Any C dynamic library can be used directly. TCC is
  heading toward full ISOC99 compliance. TCC can of course compile
  itself.

- SAFE! tcc includes an optional memory and bound checker. Bound
  checked code can be mixed freely with standard code.

- Compile and execute C source directly. No linking or assembly
  necessary. Full C preprocessor included.

- C script supported : just add '#!/usr/local/bin/tcc -run' at the first
  line of your C source, and execute it directly from the command
  line.

License:
-------

TCC is distributed under the GNU Lesser General Public License (see
COPYING file).

original author - Fabrice Bellard.
