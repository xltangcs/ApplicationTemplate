@echo off

pushd ..

git checkout --orphan latest_branch
git add .
git branch -D main
git branch -m main

git remote rm origin

echo ---------------- Restart Successfully --------------
echo ---------------- New Repository Information --------

git branch -a

popd

pause