ANONPATH="../../logs/"
apostrophe="'"
let "dirnb = 1"

#creation des dossiers de test individuels et des fichiers run
for cmd in "../../bin/analog ${ANONPATH}anonyme.log" "../../bin/analog ../../logs/emptylog.log" "../../bin/analog ../../logs/fourofour.log" "../../bin/analog" "../../bin/analog ../../logs/notlog.txt" "../../bin/analog ../../logs/noextension" "../../bin/analog ../../logs/inexistant.log" "../../bin/analog -g graph.dot ${ANONPATH}anonyme.log" "../../bin/analog -g graph.pdf ${ANONPATH}anonyme.log" "../../bin/analog -g emptygraph.dot ../../logs/emptylog.log" "echo 'digraph{
}' > ./exists.dot;../../bin/analog -g exists.dot ${ANONPATH}anonyme.log" "echo 'digraph{
}' > ./exists.dot;../../bin/analog -g exists.dot ${ANONPATH}anonyme.log" "echo 'digraph{
}' > ./exists.dot;../../bin/analog -g exists.dot ${ANONPATH}anonyme.log" "../../bin/analog -g ${ANONPATH}anonyme.log" "../../bin/analog -e ${ANONPATH}anonyme.log" "../../bin/analog -t 12 ${ANONPATH}anonyme.log" "../../bin/analog -t 12.5 ${ANONPATH}anonyme.log" "../../bin/analog -t 14 ../../logs/testtime.log" "../../bin/analog -t toto ${ANONPATH}anonyme.log" "../../bin/analog -t 40 ${ANONPATH}anonyme.log" "../../bin/analog -t ${ANONPATH}anonyme.log" "../../bin/analog -t" "../../bin/analog -e -t 12 ${ANONPATH}anonyme.log" "../../bin/analog -g graph.dot -e ${ANONPATH}anonyme.log" "../../bin/analog -g graph.dot -t 12 ${ANONPATH}anonyme.log" "../../bin/analog -g graph.dot -e -t 12 ${ANONPATH}anonyme.log" "../../bin/analog -t 12 -g graph.dot -e ${ANONPATH}anonyme.log" "../../bin/analog -t 12 -t 13 testtime.log" "../../bin/analog --t 12 h ${ANONPATH}anonyme.log" "../../bin/analog -t 12 -h ${ANONPATH}anonyme.log"
do
echo "$cmd"
mkdir Test$dirnb
echo "$cmd">./Test$dirnb/run
let "dirnb = $dirnb + 1"
done

#création des fichiers description pour chaque test
let "dirnb = 1"

for descr in "le comportement normal de l'affichage du top 10 sans aucune option" "l${apostrophe}affichage du top 10 vide quand le fichier log à analyser n${apostrophe}a aucune ligne" "l${apostrophe}affichage du top 10 vide quand le fichier log à analyser n${apostrophe}a que des requêtes dont le code de retour est 404" "la gestion du cas où l${apostrophe}utilisateur ne spécifie pas le fichier log à analyser" "la gestion du cas où le fichier log spécifié a une extension différente que .log" "la gestion du cas où le fichier log spécifié n${apostrophe}a pas d${apostrophe}extension" "la gestion du cas où le fichier log spécifié n${apostrophe}existe pas" "le comportement normal de l${apostrophe}affichage du top 10 et la création du document de type GraphViz" "la gestion de l'erreur dans le cas où le nom du fichier de sortie spécifié a une extension différente que .dot" "la création du document de type GraphViz sans aucun arc dans le cas où le fichier log à analyser n${apostrophe}a aucune ligne" "la gestion du cas où le nom pour le fichier de sortie GraphViz correspond à un fichier existant si l${apostrophe}utilisateur veut écraser le fichier existant" "la gestion du cas où le nom pour le fichier de sortie GraphViz correspond à un fichier existant si l${apostrophe}utilisateur ne veut pas écraser le fichier existant" "la gestion de l${apostrophe}erreur dans le cas où le nom pour le fichier de sortie GraphViz correspond à un fichier existant et l${apostrophe}utilisateur rentre quelque chose d${apostrophe}autre que ${apostrophe}y${apostrophe} et ${apostrophe}n${apostrophe}" "la gestion de l${apostrophe}erreur dans le cas où le nom pour le fichier de sortie GraphViz n${apostrophe}est pas spécifié" "le comportement normal de l${apostrophe}affichage du top 10 pour l${apostrophe}option -e" "le comportement normal de l${apostrophe}affichage du top 10 pour l${apostrophe}option -t en ne prenant en compte que les requêtes effectuées à 12h" "l${apostrophe}affichage du top 10 pour l${apostrophe}option -t si l${apostrophe}utilisateur rentre un nombre non entier. Le nombre entré est tronqué" "l${apostrophe}affichage du top 10 vide quand aucune requête du fichier log analysé n${apostrophe}a été effectuée à l${apostrophe}heure demandée" "la gestion de l${apostrophe}erreur pour l${apostrophe}option -t  dans le cas où l${apostrophe}utilisateur rentre autre chose qu${apostrophe}un nombre" "la gestion de l${apostrophe}erreur pour l${apostrophe}option -t  dans le cas où l${apostrophe}utilisateur rentre un nombre qui n${apostrophe}est pas compris entre 0 et 23" "la gestion de l${apostrophe}erreur pour l${apostrophe}option -t dans le cas où l${apostrophe}heure n${apostrophe}est pas spécifiée" "la gestion de l${apostrophe}erreur pour l${apostrophe}option -t dans le cas où ni l${apostrophe}heure ni le fichier log à analyser sont spécifiés" "le comportement normal de l${apostrophe}affichage du top 10 en ignorant certaines extensions et en sélectionnant uniquement les requêtes comprises dans [heure; heure+1[" "le comportement normal de l${apostrophe}affichage du top 10 et la création d${apostrophe}un document en format GraphViz en ignorant certaines extensions " "le comportement normal de affichage du top 10 et la création d${apostrophe}un document en format GraphViz en sélectionnant uniquement les requêtes comprises dans [heure; heure+1[" "le comportement normal de l${apostrophe}affichage du top 10 et la création d${apostrophe}un document en format GraphViz en ignorant certaines extensions et en sélectionnant uniquement les requêtes comprises dans [heure; heure+1[" "le comportement normal du programme même si les options de la ligne de commande sont écrites dans le mauvais ordre" "le comportement du programme si les options de la ligne de commande sont répétées. On garde la dernière instance de l${apostrophe}option" "le comportement du programme si l${apostrophe}utilisateur rentre un argument qui n${apostrophe}existe pas. L${apostrophe}argument sera ignoré." "le comportement du programme si l${apostrophe}utilisateur rentre une option qui n${apostrophe}existe pas. L${apostrophe}option sera ignorée et l${apostrophe}utilisateur averti."
do
#description
#echo "$descr"
echo "Ce fichier permet de vérifier $descr">./Test$dirnb/description

let "dirnb = $dirnb + 1"
done

#for dirnb in `seq 8 11`
#do
#oui réecrire le document
#echo 'y' > ./Test$dirnb/std.in
#done


echo 'y' > ./Test11/std.in
echo 'n' > ./Test12/std.in
echo '42
y' > ./Test13/std.in

#for dirnb in `seq 11 13`
#do
#oui réecrire le document
#echo 'digraph{
#}' > ./Test$dirnb/exists.dot
#done


