# ProjectTM 0.2.0 — mission transition

Status: built for Nintendo Switch hardware validation.

## Purpose

Preserve the Theft4-NX-derived path already observed on hardware through the
legal screens, logos, slideshow, `Starting New Game` and `The Cousins Bellic`,
then pass the exact v4r1 crash boundary and continue into the boat introduction
and mission runtime.

## Behavior changes

- Strongly overrides `sub_828E02E8` in the directly linked TU8 compatibility
  object. The retail routine calls through an Xbox device dispatch table that
  is not a host-callable table. ReXGlue already translates the corresponding
  render state. Both Theft4-NX and LibertyRecompAndroid use the same no-op
  safety hook. The v4r1 crash PC and guest LR identify this boundary exactly.
- Expands Switch audren output from two to four 256-sample buffers (about
  21.3 ms of total runway) to reduce underruns during Vulkan work.
- Applies 1.75x post-downmix makeup gain with saturation. Audio remains genuine
  GTA IV XAudio/XMA output; no song, sample or test tone is injected.
- Disables high-frequency export tracing and vector-font tracing by default.
  Fault/crash logs, lifecycle logs and ordinary errors remain enabled.
- Establishes ProjectTM 0.2.0 identity, SD log names and GPL fork attribution.

## Verification

- Build completed successfully with devkitA64.
- Missing imports: `0 of 246`.
- `sub_828E02E8` is a strong ELF symbol (`T`) at host offset `0x1C47E0`; it no
  longer aliases the weak generated implementation at `0x2603040`.
- NRO: `ProjectTM-0.2.0-TU8-mission-transition.nro`
- Size: 70,236,357 bytes.
- SHA-256: `3C001DEB81374B983110D2C52FA08E7C4D794853A1012D8A1DA6FB6B120E8D47`

## Hardware success criteria

1. Audio starts from the game's own mixer and is louder/less discontinuous.
2. The sequence reaches `Starting New Game` and `The Cousins Bellic` as before.
3. No crash with guest LR `828C8F7C` / `sub_828E02E8`.
4. Boat-intro frames and subsequent mission frames continue to present.
5. Any later crash is captured in `projecttm-0.2.0-crash.log` for exact
   symbolization against this build's retained `switch-game.elf`.

