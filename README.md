# ProjectTM

ProjectTM is an attempt to bring the Xbox 360 version of **Grand Theft Auto IV**
to Nintendo Switch homebrew through static recompilation.

This has been a long-running learning project. It began with a custom Switch
runtime built around the recompiled game code. That version taught us a great
deal about GTA IV's memory layout, streaming, Xbox services, GPU commands and
frame timing, and eventually rendered the Rockstar logos and loading
slideshow on real hardware.

Rebuilding every compatibility service from scratch was taking more time than
improving the game itself, so ProjectTM later moved to **Theft4-NX** as its
runtime foundation. That project had already solved much of the ARM64 startup
path. ProjectTM now combines that base with its own Switch fixes, hardware
research and direction. The history changed; the goal did not.

## Current state

ProjectTM is still experimental and is **not yet a finished or reliably
playable port**.

The inherited runtime has reached `Starting New Game` and `The Cousins Bellic`
on a Nintendo Switch, with real GTA IV rendering and game-generated audio.
Current work is focused on making that route stable, restoring video after a
clean rebuild, improving audio output and continuing into the playable opening
mission.

The latest source version is **0.2.2**. It includes:

- a clean four-buffer Switch audio driver with a verified class layout;
- 2.5x output gain with safe sample saturation;
- a Vulkan/NVK compatibility fix for the Xenos color format that caused 0.2.1
  to present black frames;
- all 246 required Xbox imports and all 85 generated GTA IV translation units.

Version 0.2.2 is built and locally verified, but its video fix still needs a
hardware run. Development notes for each version live in the
[`BUILD-PROJECTTM-*.md`](BUILD-PROJECTTM-0.2.2.md) files.

## What you need

- A homebrew-capable Nintendo Switch.
- A devkitPro/libnx development environment.
- Your own legally obtained Xbox 360 copy of GTA IV and matching title update.
- The generated static-recompilation sources and a Switch NVK SDK checkout.

This repository does **not** contain game assets, the Xbox executable, title
updates, encryption keys, firmware or saves. It does not download them either.

## Building the Switch version

The Switch app is built from `tools/switch-game`, not from the repository root.
The paths below are examples; point them at your own generated source and NVK
SDK directories.

```sh
export DEVKITPRO=/opt/devkitpro

cmake -S tools/switch-game -B out/build/projecttm-switch \
  -G "Unix Makefiles" \
  -DCMAKE_MAKE_PROGRAM=/usr/bin/make.exe \
  -DCMAKE_TOOLCHAIN_FILE="$PWD/toolchains/switch-libnx.cmake" \
  -DCMAKE_BUILD_TYPE=Release \
  -DTHEFT4_GENERATED_DIR=/path/to/GTA-IV-RECOMP-XBOX-360/generated/default \
  -DTHEFT4_SWITCH_GAME_VULKAN=ON \
  -DTHEFT4_SWITCH_NVK_SDK=/path/to/nvk-switch-sdk

make -C out/build/projecttm-switch -j2
```

When a public header or class layout changes, use a new build directory. A
partially reused build once mixed two different audio-driver layouts and
corrupted the heap, so clean builds are not optional for ABI changes.

More platform notes are in [`README-SWITCH.md`](README-SWITCH.md). The older
research documents under [`docs/switch-port/`](docs/switch-port/) are retained
because they explain how the port reached its present architecture, but some
milestone descriptions there are historical.

## Testing and reporting problems

Hardware reports are most useful when they include:

- the exact ProjectTM version and NRO hash;
- how many seconds the app ran;
- what appeared on screen and what was heard;
- whether it exited normally, froze or showed Horizon's error dialog;
- the main and crash logs from `sdmc:/switch/ProjectTM/logs/`.

Please do not report results from a renamed or unknown NRO as though its build
identity were known. Reproducible evidence is more valuable than a guess.

## Credits and license

ProjectTM stands on years of work by the Theft4, Theft4-NX,
LibertyRecompAndroid, LibertyRecomp, ReXGlue, Xenia, XenonRecomp, nfsmw-nx,
project8-sw, Mesa/NVK, devkitPro and libnx communities. See
[`CREDITS.md`](CREDITS.md) for links and details.

ProjectTM is distributed under GPL-3.0 where applicable. Vendored dependencies
retain their own licenses; see [`COPYING`](COPYING).

ProjectTM is not affiliated with or endorsed by Rockstar Games, Take-Two
Interactive, Microsoft or Nintendo.
