ANONPATH="/tmp/"
#ANONPATH="../../logs/"
let "dirnb = 1"

for cmd in "../../bin/analog ${ANONPATH}anonyme.log" "../../bin/analog ../../logs/emptylog.log" "../../bin/analog ../../logs/fourofour.log" "../../bin/analog" "../../bin/analog ../../logs/notlog.txt" "../../bin/analog ../../logs/noextension" "../../bin/analog ../../logs/inexistant.log" "../../bin/analog -g graph.dot ${ANONPATH}anonyme.log" "../../bin/analog -g graph.pdf ${ANONPATH}anonyme.log" "../../bin/analog -g emptygraph.dot ../../logs/emptylog.log" "echo 'digraph{
}' > ./exists.dot;../../bin/analog -g exists.dot ${ANONPATH}anonyme.log" "echo 'digraph{
}' > ./exists.dot;../../bin/analog -g exists.dot ${ANONPATH}anonyme.log" "echo 'digraph{
}' > ./exists.dot;../../bin/analog -g exists.dot ${ANONPATH}anonyme.log" "../../bin/analog -g ${ANONPATH}anonyme.log" "../../bin/analog -e ${ANONPATH}anonyme.log" "../../bin/analog -t 12 ${ANONPATH}anonyme.log" "../../bin/analog -t 12.5 ${ANONPATH}anonyme.log" "../../bin/analog -t 14 ../../logs/testtime.log" "../../bin/analog -t toto ${ANONPATH}anonyme.log" "../../bin/analog -t 40 ${ANONPATH}anonyme.log" "../../bin/analog -t ${ANONPATH}anonyme.log" "../../bin/analog -t" "../../bin/analog -e -t 12 ${ANONPATH}anonyme.log" "../../bin/analog -g graph.dot -e ${ANONPATH}anonyme.log" "../../bin/analog -g graph.dot -t 12 ${ANONPATH}anonyme.log" "../../bin/analog -g graph.dot -e -t 12 ${ANONPATH}anonyme.log" "../../bin/analog -t 12 -g graph.dot -e ${ANONPATH}anonyme.log" "../../bin/analog -t 12 -t 13 ../../logs/testtime.log" "../../bin/analog -t 12 h ${ANONPATH}anonyme.log" "../../bin/analog -t 12 -h ${ANONPATH}anonyme.log"
do
echo "$cmd">./Test$dirnb/run
let "dirnb = $dirnb + 1"
done
