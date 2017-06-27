#!/usr/bin/env bash

if [[ $1 == *"add"* ]]; then
   git add --all
fi

if [[ $1 == *"commit"* ]]; then
   read message
   git commit -m "$message"
fi

if [[ $1 == *"push"* ]]; then
   git push github master
   git push bitbucket master
fi