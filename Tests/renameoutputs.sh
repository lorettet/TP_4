
for i in Test14
do
  cd $i
  	#ensures that if there are no matching files, the loop will exit 
  	#without trying to process a non-existent file name *.dot
  shopt -s nullglob
  for j in *.dot;
  do
	#ensures that if there are no matching files, the loop will exit 
	#without trying to process a non-existent file name *.dot
	#[ -f "$j" ] || break
    mv $j ./$j.outfile
  done
cd ..
done
