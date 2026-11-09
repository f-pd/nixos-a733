# A manufacturer file kept in vendor/blobs/<repo>/<path>, added to the store
# under the same name and hash the download from upstream would have, so the
# store path does not change. Evaluation fails if the file does not match the
# hash pinned in sources.json.
{
  repo,
  path,
  hash,
  name ? "a733-vendor-${baseNameOf path}",
}:
builtins.path {
  path = ./blobs + "/${repo}/${path}";
  inherit name;
  recursive = false;
  sha256 = hash;
}
