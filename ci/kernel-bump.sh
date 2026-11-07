#!/usr/bin/env bash
# Pins the latest stable kernel.org release in kernel/version.json.
# Writes changed=true|false and version=<x.y.z> to $GITHUB_OUTPUT.
set -euo pipefail

file=kernel/version.json
out=${GITHUB_OUTPUT:-/dev/stdout}

latest=$(curl -fsSL https://www.kernel.org/releases.json | jq -r .latest_stable.version)
current=$(jq -r .version "$file")

echo "version=$latest" >> "$out"

if [ "$latest" = "$current" ]; then
  echo "Kernel $current is still the latest stable release"
  echo "changed=false" >> "$out"
  exit 0
fi

major=${latest%%.*}
url="https://cdn.kernel.org/pub/linux/kernel/v${major}.x/linux-${latest}.tar.xz"
hash=$(nix-prefetch-url --type sha256 "$url")

jq --arg v "$latest" --arg h "sha256:$hash" '.version = $v | .hash = $h' "$file" > "$file.new"
mv "$file.new" "$file"

echo "Kernel $current -> $latest"
echo "changed=true" >> "$out"
