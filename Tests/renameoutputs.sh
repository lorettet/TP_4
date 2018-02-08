
for i in Test*
do
  cd $i
  	#ensures that if there are no matching files, the loop will exit 
  	#without trying to process a non-existent file name *.dot
  shopt -s nullglob
  for j in 'graph.dot' 'emptygraph.dot' 'exists.dot'
  do
	#ensures that if there are no matching files, the loop will exit 
	#without trying to process a non-existent file name *.dot
	[ -f "$j" ] || continue
    mv $j ./$j.outfile
  done
cd ..
done

#for dirnb in `seq 11 13`
#do
#cp -f Test$dirnb/exists.dot Test$dirnb/exists.dot.outfile
#done
