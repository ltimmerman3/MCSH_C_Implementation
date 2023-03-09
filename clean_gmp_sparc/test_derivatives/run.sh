CWD=$(pwd)
module purge
ml gcc/10.3.0 mkl mvapich2/2.3.6
cd ~/p-amedford6-0/githubRepos/MCSH_C_Implementation/clean_gmp_sparc/src
make clean
make -j
cp ../lib/gmp $CWD
cd $CWD
