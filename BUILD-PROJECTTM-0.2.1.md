# ProjectTM 0.2.1 — audio layout repair

Status: clean rebuild completed; ready for Nintendo Switch hardware validation.

## Purpose

Preserve every ProjectTM 0.2.0 mission-transition and audio change while
repairing the mixed `SwitchAudioDriver` object layout that corrupted the host
heap before the logos appeared.

## Root cause

The four-wave-buffer audio header makes `SwitchAudioDriver` 584 bytes
(`0x248`). The incremental 0.2.0 output contained a stale consumer that still
allocated the former 456-byte (`0x1c8`) object, while the current destructor
and implementation used 584 bytes. Audio initialization therefore wrote 128
bytes beyond the allocation. The next allocator operation, while opening
`general.rpf`, observed the damaged heap and faulted in `_malloc_r`.

## Repair

- Build in a brand-new directory so every header consumer is recompiled.
- Keep the four genuine audren buffers, makeup gain, and mission-transition
  compatibility hook from 0.2.0.
- Add a compile-time Switch ABI assertion requiring
  `sizeof(SwitchAudioDriver) == 0x248` in the allocation translation unit.
- Use separate 0.2.1 log and crash paths.
- Verify the linked ELF allocates and deletes the same `0x248` bytes before
  releasing the NRO for hardware testing.

## Hardware success criteria

1. No `_malloc_r` fault while opening `general.rpf`.
2. Legal screens, logos, slideshow and genuine game audio return.
3. The sequence reaches `Starting New Game` and `The Cousins Bellic`.
4. The retained mission-transition hook executes at its genuine boundary.
5. Any subsequent stop is captured in `projecttm-0.2.1-crash.log` and is
   treated as the next real post-transition blocker.

## Build verification

- Clean build completed from `out/b21`; all 85 TU8 generated units rebuilt.
- Missing imports: `0 of 246`.
- Linked `CreateDriver` passes `0x248` (584) to `operator new`.
- Linked deleting destructor passes `0x248` (584) to `operator delete`.
- `sub_828E02E8` remains the strong compatibility symbol (`T`) at ELF offset
  `0x1C47E0`.
- NRO: `ProjectTM-0.2.1-TU8-audio-layout-repair.nro`
- Size: 70,236,357 bytes.
- SHA-256: `AC16B85A826810405B3D857C8B39CDEADD26E7D019C560E118F6DB2DDF7D4799`
