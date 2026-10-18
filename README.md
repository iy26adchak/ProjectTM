# ProjectTM

ProjectTM is a Switch homebrew port of the Xbox 360 version of Grand Theft Auto IV (TU8).

The project started from the Theft4-NX runtime and adds the ProjectTM Switch launcher, platform fixes, audio work, and compatibility changes. It uses statically recompiled PowerPC game code together with the ReXGlue runtime and a Vulkan/NVK renderer.

This is an unfinished research project. It is not an emulator, and it is not a finished or generally playable port. The Switch build has reached the opening mission transition on test hardware; stability, performance, audio, input, saves, and later gameplay are still being worked on.

## What you need

- A homebrew-capable Nintendo Switch.
- devkitPro, devkitA64, libnx, CMake, and Ninja for building.
- Your own legally obtained Xbox 360 copy of GTA IV and its matching title update.

Game files, title updates, firmware, keys, saves, logs, and prebuilt payloads are not included. See `.gitignore` before adding local files.

## Building the Switch version

The normal build uses the Switch toolchain in this repository:

```sh
cmake -S . -B out/build/switch-tu8-vulkan -G Ninja \
  -DCMAKE_TOOLCHAIN_FILE=toolchains/switch-libnx.cmake \
  -DCMAKE_BUILD_TYPE=Release
ninja -C out/build/switch-tu8-vulkan
```

For a clean rebuild, remove the selected build directory first. This matters after changing public headers or class layouts.

More Switch-specific notes are in `README-SWITCH.md` and `docs/switch-port/`.

## Credits and license

ProjectTM is released under GPL-3.0 where applicable. The separate [`CREDITS.md`](CREDITS.md) file lists the projects and people whose work made this possible. Vendored dependencies keep their own licenses; see [`COPYING`](COPYING).

ProjectTM is not affiliated with Rockstar Games, Take-Two Interactive, Microsoft, Nintendo, or Apple.

