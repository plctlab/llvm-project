This repository contains a fork of LLVM (see https://llvm.org) with patches
towards supporting the RISC-V vector extension (see
https://github.com/riscv/riscv-v-spec/). This is very much a work in progress.

See `docs/RISCVVectorCodegen.md` for some documentation.

These patches are regularly rebased to track LLVM trunk, which means commit
hashes will change. To mitigate the annoyance that causes, development always
happens on a branch named `rvv-<date>` where `<date>` is the date of the last
rebase, and on the next rebase this branch is left alone and a new branch is
created. The downside of this is that you will have to check the list of
branches to find the latest version.
