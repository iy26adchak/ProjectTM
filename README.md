# THIS IS STILL A WORK IN PROGRESS
# The nice thing is that it is moving forward :)

# ProjectTM

ProjectTM is a work-in-progress attempt to bring the Xbox 360 version of
**Grand Theft Auto IV** to Nintendo Switch homebrew through static
recompilation.

This is a personal learning project made with a lot of testing, broken builds,
small victories and help from other open-source projects. It is not finished,
but it has already gone much further than a simple technical demo.

## How far along is it?

**Estimated progress toward a completely playable game: 20%**

`██░░░░░░░░ 20%`

This number is only an honest estimate. It can move up or down as new problems
are found. Reaching the opening mission does not mean the whole game is ready:
every mission, interior, vehicle, save, cutscene and gameplay system still has
to be tested.

What already works or has worked on real Switch hardware:

- the game boots and reads the original GTA IV data;
- the Rockstar logos and loading slideshow can appear;
- real game-generated graphics are presented;
- real game-generated audio can play;
- controller input is connected;
- the game has reached `Starting New Game` and `The Cousins Bellic`;
- an earlier runtime reached the opening cutscene and drivable gameplay, but it
  was extremely slow and unstable.

What still needs work:

- make the route to the opening mission reliable on every boot;
- keep video and audio stable at the same time;
- continue past crashes and freezes during startup and gameplay;
- improve rendering speed and frame pacing;
- test saving, loading, missions, physics, collision and the rest of the game;
- eventually reach a stable 30 FPS where the Switch hardware allows it.

## A short history

ProjectTM started with a custom Switch runtime built around the recompiled GTA
IV code. That first version taught us a lot about the game's memory, files,
streaming, Xbox services, graphics commands and frame timing. It eventually
showed the Rockstar logos and loading slideshow on real hardware.

Building every compatibility service from zero was slowing the project down,
so ProjectTM later moved to **Theft4-NX** as its foundation. That gave the
project a runtime which had already reached gameplay on ARM64. ProjectTM keeps
its own fixes, hardware research, TU8 work and direction on top of that base.

The foundation changed, but the goal is still the same: make GTA IV run as
well as possible on Nintendo Switch.

## Current focus

The current work is about making one reliable path through:

`boot -> logos -> loading slideshow -> Starting New Game -> The Cousins Bellic -> gameplay`

The latest development build restores the game's real graphics-state path and
adds safety checks around invalid calls. It also keeps the real audio, input,
filesystem and profile systems enabled. Nothing is pretending that the game
finished loading, and no music or mission is manually injected.

## What you need

- A homebrew-capable Nintendo Switch.
- A devkitPro/libnx development environment.
- Your own legally obtained Xbox 360 copy of GTA IV and matching title update.
- The generated static-recompilation sources and a Switch NVK SDK checkout.

This repository does **not** contain GTA IV assets, the Xbox executable, title
updates, encryption keys, firmware or save files. It does not download them
for you.

## Building the Switch version

The Switch app is built from `tools/switch-game`. The paths below are examples;
replace them with the locations on your own computer.

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

Use a fresh build folder after changing a public header or class layout. An old
incremental build once mixed two audio-driver layouts and damaged the heap, so
this small precaution matters.

More Switch notes are available in [`README-SWITCH.md`](README-SWITCH.md).
Older research under [`docs/switch-port/`](docs/switch-port/) is kept because
it shows how the project reached its current design, although some milestones
there are now historical.

## Reporting a problem

If you test the project, the most helpful report includes:

- the exact ProjectTM version or NRO hash;
- how long it ran;
- what appeared on screen and what you heard;
- whether it closed normally, froze or showed an error;
- the main and crash logs from `sdmc:/switch/ProjectTM/logs/`.

A clear report is much more useful than a guess. Even a failed run can tell us
exactly what needs attention next.

## Credits and license

ProjectTM is only possible because of work from the Theft4, Theft4-NX,
LibertyRecompAndroid, LibertyRecomp, ReXGlue, Xenia, XenonRecomp, nfsmw-nx,
project8-sw, Mesa/NVK, devkitPro and libnx communities. Please read
[`CREDITS.md`](CREDITS.md) for links and details.

ProjectTM is distributed under GPL-3.0 where applicable. Included dependencies
keep their own licenses; see [`COPYING`](COPYING).

ProjectTM is not affiliated with or endorsed by Rockstar Games, Take-Two
Interactive, Microsoft or Nintendo.
