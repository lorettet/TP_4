
#for i in Test*
#do
#  sRun=`cat ./$i/run`
  #sRun="$sRun <std.in"
  #echo "$sRun"
#  $sRun > ./$i/std.out
#  $sRun 2> ./$i/stderr.out
#  echo $? > ./$i/Returncode
#done


#echo "./$i/"
for i in Test*
do
cd $i
if [ -r "run" ]
then
  sRun=`cat run`
else
  echo "No run file found. Exiting."
  exit 2
fi

# stdin has been specified
if [ -r "std.in" ]
then 
  sRun="$sRun <std.in"
fi

# stdout has been specified
  sRun="$sRun >std.out"


# stderr has been specified
  sRun="$sRun 2>stderr.out"


echo $sRun
# execute the command line
eval $sRun
returnCode=$?
echo "$returnCode" > Returncode
cd ..
done
