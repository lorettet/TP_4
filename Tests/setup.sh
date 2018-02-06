let "dirnb = 1"

#for cmd in '../../bin/analog ../../logs/anonyme.log' './analog emptylog.log' './analog anonyme.log'
for cmd in '../../bin/analog ../../logs/anonyme.log' '../../bin/analog ../../logs/emptylog.log''../../bin/analog anonyme.log' '../../bin/analog' '../../bin/analog ../../logs/notlog.txt''../../bin/analog ../../logs/noextension''../../bin/analog ../../logs/inexistant.log' '../../bin/analog -g testresult.dot ../../logs/anonyme.log''../../bin/analog -g testresult.pdf ../../logs/anonyme.log' '../../bin/analog -g emptytestresult.dot ../../logs/emptylog.log' '../../bin/analog -g exists.dot ../../logs/anonyme.log''../../bin/analog -g ../../logs/anonyme.log' '../../bin/analog -e ../../logs/anonyme.log''../../bin/analog -t 12 ../../logs/anonyme.log''../../bin/analog -t 12.5 ../../logs/anonyme.log' '../../bin/analog -t 13 ../../logs/anonyme.log' '../../bin/analog -t toto ../../logs/anonyme.log' '../../bin/analog -t 40 ../../logs/anonyme.log' '../../bin/analog -t ../../logs/anonyme.log' '../../bin/analog -e -t 12 ../../logs/anonyme.log' '../../bin/analog -g testgraphext.dot -e ../../logs/anonyme.log' '../../bin/analog -g testgraphtime.dot -t 12 ../../logs/anonyme.log' '../../bin/analog -g testgraphall.dot -e -t 12 ../../logs/anonyme.log' '../../bin/analog -t 12 -g testlog.dot -e ../../logs/anonyme.log' '../../bin/analog -g testtime.dot -t 12 -t 13 testtime.log' '../../bin/analog -g testlog.dot h ../../logs/anonyme.log' '../../bin/analog -g testlog.dot -h ../../logs/anonyme.log'
do
#echo "$cmd"
mkdir Test$dirnb
echo "$cmd">./Test$dirnb/run
let "dirnb = $dirnb + 1"
done


let "dirnb = 1"

for descr in '../../analog testlog.log' '../../bin/analog ../logs/testtime.log'
do
#description
#echo "$descr"
echo "Ce fichier permet de vérifier $descr">./Test$dirnb/description

let "dirnb = $dirnb + 1"
done

for dirnb in `seq 1 20`
do

#oui réecrire le document
echo 'y' > ./Test$dirnb/std.in

done

