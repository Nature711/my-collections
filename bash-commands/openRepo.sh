. ./metadata.sh
REPO_PATH=$PATH_TO_REPO

cd $REPO_PATH
REPO_NAME=$1
if [ $# -eq 0 ] 
    then 
        ls
        read REPO_NAME
fi 

cd $REPO_NAME
code .