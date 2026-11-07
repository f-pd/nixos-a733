# Reads patches/index.json and checks it, so a broken index fails at
# evaluation time instead of halfway through a kernel build.
{ lib }:
let
  index = lib.importJSON ./index.json;
  layers = [
    "base"
    "optional"
  ];

  check =
    entry:
    let
      path = ./. + "/${entry.layer}/${entry.file}";
    in
    if !(lib.elem entry.layer layers) then
      throw "patches/index.json: ${entry.file} has unknown layer '${entry.layer}'"
    else if !(entry ? origin) || entry.origin == "" then
      throw "patches/index.json: ${entry.file} has no origin"
    else if !(builtins.pathExists path) then
      throw "patches/index.json: ${entry.layer}/${entry.file} does not exist"
    else
      entry // { inherit path; };

  all = map check index.patches;
in
{
  inherit all;
  base = lib.filter (p: p.layer == "base") all;
  optional = lib.filter (p: p.layer == "optional") all;
}
