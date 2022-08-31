#!/bin/bash
for i in */*/
do
  cd $i
  if [ ! -f README.md.base ]
  then
    probname=${PWD##*/}
    probname="${probname//-/ }"
    probname="${probname^}"
    link="$(grep -o '[^ ]*http[^ ]*' -R Sol* -h)"
    if [ -z "${link}" ]
    then
      >&2 echo URL missing: "$probname"
    else
      echo "# $probname" > README.md.base
      echo "" >> README.md.base
      echo "[Problem link]($link)" >> README.md.base
    fi
  fi
  cd ../..
done
