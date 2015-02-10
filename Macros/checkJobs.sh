myDir=$1

#find $myDir -type d '!' -exec test -e "{}/ZZCutFlow.data.batch.root" ";" -print
#find $myDir -type d '!' -exec test -e "{}/ZZCutFlow.MC.batch.root" ";" -print
#find $myDir -type d '!' -exec test -e "{}/ZXCutflow.data.batch.root" ";" -print
find $myDir -type d '!' -exec test -e "{}/ZXCutflow.MC.batch.root" ";" -print

