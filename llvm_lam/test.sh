clang -O3 -S -g -emit-llvm ./input/$1.c -o ./input/$1.ll
opt -load-pass-plugin ./pass_lam/libPassLam.so -p="lam-module" ./input/$1.ll -o ./input/$1.ll
clang ./input/$1.ll -o ./input/$1
