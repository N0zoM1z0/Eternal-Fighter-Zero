#!/usr/bin/env bash
# Reuse existing tools without installing software or touching shared state.
set -euo pipefail
repo_root=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
mkdir -p "$repo_root/.tools"
while [[ $# -gt 0 ]]; do
  if [[ $# -lt 2 ]]; then echo 'Expected --msvc|--ghidra|--jdk PATH' >&2; exit 2; fi
  case "$1" in
    --msvc) link_name=msvc710 ;;
    --ghidra) link_name=ghidra ;;
    --jdk) link_name=jdk ;;
    *) echo "Unknown option: $1" >&2; exit 2 ;;
  esac
  selected_root=$(realpath -- "$2")
  if [[ ! -d "$selected_root" ]]; then echo "Missing tool directory: $2" >&2; exit 1; fi
  destination="$repo_root/.tools/$link_name"
  if [[ -e "$destination" || -L "$destination" ]]; then
    if [[ $(realpath -- "$destination") != "$selected_root" ]]; then
      echo "Existing tool selection differs: $destination" >&2; exit 1
    fi
  else
    ln -s -- "$selected_root" "$destination"
  fi
  shift 2
done
"$repo_root/scripts/repo-python" "$repo_root/scripts/verify-toolchain.py" --check
"$repo_root/scripts/repo-python" "$repo_root/scripts/ghidra.py" tools
