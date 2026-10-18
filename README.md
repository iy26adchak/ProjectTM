# ProjectTM

ProjectTM is a community effort to bring the Xbox 360 version of Grand Theft Auto IV to Nintendo Switch homebrew.

The project began as a Switch-specific runtime built around the recompiled game code. That work taught us a lot about the Xbox memory layout, graphics commands, frame timing, streaming, and the services GTA IV expects. It also gave us real rendered frames, loading screens, and a large amount of useful hardware experience.

Over time, it became clear that rebuilding the entire compatibility layer from scratch was slowing us down. Theft4-NX already had a working ARM64 runtime and had reached the opening mission transition on hardware. ProjectTM therefore moved to that codebase as its foundation. The goal did not change: ProjectTM keeps its own name, Switch focus, fixes, experiments, and direction while building on a runtime that has already solved much of the difficult startup work.

That transition is the story behind this repository. It brings together the original ProjectTM work, the Theft4-NX runtime, ReXGlue services, and lessons learned from the PC, Android, iOS, and other Switch recompilation projects.

## Where it is now

The combined runtime has reached `Starting New Game` and `The Cousins Bellic` on tested Switch hardware, with real game rendering and audio in the working reference path. The next work is making that path reliable and practical: improving audio consistency, renderer speed, input, saves, and the transition into the playable mission.

This repository is meant to be a friendly place to follow that work, reproduce it, and help move it forward.

## Remember
Thsi is only a WIP and is local for now until i personally try and get a fully running build :)

## Thanks

ProjectTM stands on the work of many projects and contributors. The separate [`CREDITS.md`](CREDITS.md) file lists them and explains how they fit into the project.

ProjectTM is released under GPL-3.0 where applicable. Vendored dependencies keep their own licenses; see [`COPYING`](COPYING).

ProjectTM is not affiliated with Rockstar Games, Take-Two Interactive, Microsoft, Nintendo, or Apple.
