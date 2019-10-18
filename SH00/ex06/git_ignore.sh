#!/bin/sh
git status --ignored -s | grep '^!!' | cut -b 4-
