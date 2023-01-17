1. Vérifiez les arguments passés en entrée pour vous assurer qu'ils sont valides et 
qu'il y a bien 4 d'entre eux.

2. Ouvrez les fichiers file1 et file2 en utilisant la fonction open.

3. Créez un tube avec la fonction pipe.

4. Utilisez la fonction fork pour créer un processus fils. Dans ce processus fils, 
utilisez dup2 pour rediriger l'entrée standard vers le descripteur de fichier du fichier 
file1 et la sortie standard vers le descripteur de fichier du tube. 
Ensuite, exécutez la première commande en utilisant execve.

5. Dans le processus père, utilisez à nouveau dup2 pour rediriger l'entrée standard vers le 
descripteur de fichier du tube et la sortie standard vers le descripteur de fichier du 
fichier file2. Ensuite, exécutez la seconde commande en utilisant execve.

6. Attendre la fin de l'exécution des commandes en utilisant wait ou waitpid.

7. Fermez les descripteurs de fichier et le tube, et libérez toute la mémoire allouée 
dynamiquement avec free.

$> ./pipex infile "ls -l" "wc -l" outfile
Devrait être identique à < infile ls -l | wc -l > outfile