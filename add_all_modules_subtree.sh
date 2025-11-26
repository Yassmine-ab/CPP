#!/bin/zsh
# Script pour ajouter les modules C---Module-00 à C---Module-09 en tant que subtrees

GITHUB_USER="Yassmine-ab"

for i in {00..09}
do
    MODULE="C---Module-$i"
    REMOTE_NAME="module$i"
    REPO_URL="https://github.com/$GITHUB_USER/$MODULE.git"
    echo "Ajout du remote $REMOTE_NAME ($REPO_URL)"
    git remote add $REMOTE_NAME $REPO_URL 2>/dev/null || echo "Remote $REMOTE_NAME déjà ajouté."
    git fetch $REMOTE_NAME
    echo "Ajout du subtree $MODULE dans le dossier $MODULE"
    git subtree add --prefix=$MODULE $REMOTE_NAME main --squash
done
