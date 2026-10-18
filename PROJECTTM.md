# ProjectTM

ProjectTM is a Nintendo Switch homebrew fork focused on running the Xbox 360
release of Grand Theft Auto IV through static ARM64 recompilation. It combines
ahead-of-time translated PowerPC game code with ReXGlue's Xbox compatibility
runtime, the GTA IV native Vulkan renderer and Switch-specific platform code.

The project is distributed under GPL-3.0, following the license of its fork
base. See `COPYING`. Source corresponding to distributed ProjectTM binaries
must remain available under that license.

## Lineage and credit

ProjectTM is derived from and indebted to:

- **Theft4-NX**, the direct Nintendo Switch fork base;
- **Theft4 / Theft4-Android / LibertyRecompAndroid**, whose ARM64 runtime,
  title hooks and hardware findings informed the Switch work;
- **LibertyRecomp**, the GTA IV static-recompilation project;
- **ReXGlue SDK**, the compatibility runtime and code-generation ecosystem;
- **GTA-IV-RECOMP-XBOX-360**, used as the PC behavior oracle;
- **nfsmw-nx**, **project8-sw** and related Xbox 360 recompilation projects
  whose Switch threading, I/O, exception and renderer work provided reference
  designs.

Copyright remains with each original contributor. ProjectTM branding does not
claim authorship of upstream work.

## Game data

No Rockstar Games assets, executable images, title updates, encryption keys or
copyrighted game data are included. Users must supply a legally obtained Xbox
360 copy and the matching title update. ProjectTM is not affiliated with or
endorsed by Rockstar Games or Take-Two Interactive.

## Current Switch milestone

The imported runtime has reached `Starting New Game` and `The Cousins Bellic`
on hardware with genuine game audio and rendering. ProjectTM 0.2.0 carries the
first post-mission-title stability repair: it handles the duplicate retail
render-state dispatch in the same way as the two independently working ARM64
references, expands the Switch audio runway and reduces default tracing cost.
Gameplay beyond that transition still requires hardware validation.


