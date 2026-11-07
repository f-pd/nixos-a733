#!/usr/bin/env bash
# Opens one issue per kernel version listing the optional patches that did
# not apply. Does nothing when every optional patch applied.
# Usage: report-skipped.sh <skipped-list> <kernel-version>
set -euo pipefail

list=$1
version=$2

if [ ! -s "$list" ]; then
  echo "Every optional patch applied"
  exit 0
fi

title="Optional patches skipped on Linux $version"

if gh issue list --state open --search "in:title \"$title\"" --json number --jq '.[].number' | grep -q .; then
  echo "Issue already open: $title"
  exit 0
fi

body=$(mktemp)
{
  echo "These optional patches do not apply on Linux $version and were left out of the build."
  echo "The kernel was built without the features they provide."
  echo
  sed 's/^/- `/; s/$/`/' "$list"
} > "$body"

# The label may not exist yet: fall back to an unlabelled issue.
gh issue create --title "$title" --label patches --body-file "$body" \
  || gh issue create --title "$title" --body-file "$body"
