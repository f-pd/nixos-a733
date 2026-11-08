#!/usr/bin/env bash
# Opens an issue when a build fails, once per kernel version.
# Usage: report-failure.sh <kernel-version> <run-url>
set -euo pipefail

version=${1:-unknown}
run_url=$2
title="Build failed on Linux $version"

if gh issue list --state open --search "in:title \"$title\"" --json number --jq '.[].number' | grep -q .; then
  echo "Issue already open: $title"
  exit 0
fi

gh issue create --title "$title" --body "The build failed: $run_url

If the failure is in a base patch, it no longer applies and needs a rebase."
