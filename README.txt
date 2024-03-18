# Calculatrice Simplifiée

Ce projet est une calculatrice simplifiée écrite en C. 
Elle supporte les opérations de base telles que l'addition, la soustraction, la multiplication, la division, ainsi que les nombres flottants et les opérations parenthésées.

## Fonctionnalités

- Opérations arithmétiques de base : addition (+), soustraction (-), multiplication (*) et division (/).
- Gestion des expressions parenthésées pour respecter les priorités des opérations.
- Support des nombres entiers et flottants, y compris la notation scientifique pour les flottants.

## Compilation

Le projet inclut un `Makefile` pour une compilation facile.

Pour compiler le projet, exécutez la commande suivante dans le répertoire du projet :

make 

Cela générera un exécutable nommé `calc`.

## Utilisation

Pour démarrer la calculatrice, exécutez l'exécutable généré en tapant la commande suivante dans votre terminal :

./calc 

Une fois la calculatrice lancée, vous pouvez entrer des expressions à calculer. Tapez `q` pour quitter le programme.

## Exemples

Voici quelques exemples d'expressions que vous pouvez entrer :
5 + 3 * 2
11
(5 + 3) * 2
16
5.5 + 2.25 * 2
10
1e2 + 5.5e1
155


## Nettoyage

Pour nettoyer le répertoire en supprimant les fichiers objet et l'exécutable, utilisez la commande :

make clean

