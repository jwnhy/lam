clang -O1 -S -emit-llvm ./input/$1.c -o ./input/$1.ll
opt -load-pass-plugin ./pass_lam/libPassLam.so -p="lam-module" -disable-output ./input/$1.ll
