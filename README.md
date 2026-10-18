# ProjectTM

ProjectTM is a community project to bring the Xbox 360 version of Grand Theft Auto IV to Nintendo Switch homebrew.

The project began as a Switch-specific runtime written around the recompiled game code. That work taught us a lot about the Xbox memory layout, graphics commands, frame timing, streaming, and the services GTA IV expects. It also produced real rendered frames, loading screens, and a great deal of useful hardware data.

At some point it became clear that rebuilding the whole compatibility layer from scratch was slowing the project down. Theft4-NX already had a working ARM64 runtime and had reached the opening mission transition on hardware. ProjectTM therefore moved to that codebase as its foundation. The goal did not change: ProjectTM keeps its own name, Switch focus, fixes, experiments, and direction while building on a runtime that has already solved much of the difficult startup work.

That transition is the main reason this repository exists. It brings the original ProjectTM work together with the Theft4-NX runtime, the ReXGlue services, and the lessons learned from the PC, Android, iOS, and other Switch recompilation projects.

## Where it is now

The combined runtime has reached `Starting New Game` and `The Cousins Bellic` on tested Switch hardware, with real game rendering and audio in the working reference path. The next work is about making that path stable and practical: improving audio reliability, renderer speed, input, saves, and the transition into the playable mission.

This is an active development project, so hardware results can change as the runtime is improved. The repository is mainly for development, testing, and sharing the work with other people interested in recompilation and Switch ports.

## Getting started

You need a homebrew-capable Nintendo Switch, a devkitPro/libnx development environment, and your own legally obtained Xbox 360 copy of GTA IV with its matching title update. Game files, saves, firmware, keys, and other copyrighted material are not included.

The Switch toolchain and platform notes are documented in `README-SWITCH.md` and `docs/switch-port/`. A normal source build looks like this:

```sh
cmake -S . -B out/build/switch-tu8-vulkan -G Ninja \
  -DCMAKE_TOOLCHAIN_FILE=toolchains/switch-libnx.cmake \
  -DCMAKE_BUILD_TYPE=Release
ninja -C out/build/switch-tu8-vulkan
```

For a clean rebuild after changing public headers or class layouts, remove the selected build directory first.

## Thanks

ProjectTM stands on the work of many projects and contributors. The separate [`CREDITS.md`](CREDITS.md) file lists them and explains how they fit into the project.

ProjectTM is released under GPL-3.0 where applicable. Vendored dependencies keep their own licenses; see [`COPYING`](COPYING).

ProjectTM is not affiliated with Rockstar Games, Take-Two Interactive, Microsoft, Nintendo, or Apple.
