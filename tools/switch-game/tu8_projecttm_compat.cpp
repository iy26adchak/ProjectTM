// Compatibility bridge for the USA TU8 source tree used by ProjectTM.
// The generated files contain a handful of safety/diagnostic calls added while
// bringing up the earlier standalone Switch host.  The full ReXGlue runtime
// owns memory, TLS and diagnostics now, so keep only their semantic contracts.

#include "gta4_init.h"

#include <cstring>
#include <limits>

#include <rex/kernel.h>
bool ProjectTMGuestRangeValid(uint32_t address, size_t size) {
  if (!address || !size || size > std::numeric_limits<uint32_t>::max())
    return false;
  const uint64_t end = uint64_t(address) + uint64_t(size) - 1;
  if (end > std::numeric_limits<uint32_t>::max())
    return false;
  // On NX the runtime reserves the complete translated guest windows, and the
  // public Memory API intentionally exposes no committed-page query.  Preserve
  // the original guard's important properties here: reject null and wrapping
  // ranges before any translated access.
  return REX_KERNEL_MEMORY() != nullptr;
}

extern "C" uint32_t ProjectTMEnsurePcrTls(uint32_t pcr_address) {
  if (!ProjectTMGuestRangeValid(pcr_address, sizeof(uint32_t)))
    return 0;
  const uint8_t* pcr = REX_KERNEL_MEMORY()->TranslateVirtual<const uint8_t*>(pcr_address);
  uint32_t tls_be = 0;
  std::memcpy(&tls_be, pcr, sizeof(tls_be));
  return __builtin_bswap32(tls_be);
}

extern "C" void ProjectTMResourceRelocationRejected(uint32_t, uint32_t, uint32_t,
                                                       uint32_t, uint32_t) {
  // The generated guard already fails the unresolved relocation closed.  The
  // old host wrote an auxiliary trace here; no state mutation is required.
}

extern "C" void ProjectTmTraceGraphicsManagerIndirectBefore(PPCContext&, uint8_t*,
                                                               uint32_t) {}
extern "C" void ProjectTmTraceGraphicsManagerIndirectAfter(PPCContext&, uint8_t*,
                                                              uint32_t) {}

// The retail function indexes a device-owned render-state dispatch table and
// performs an indirect call. ReXGlue already consumes the corresponding state
// through the native command path, while the Xbox device table is not a host
// callable vtable. Calling an unpopulated/stale entry caused the v4r1 hardware
// crash after "The Cousins Bellic" (guest LR 828C8F7C). Theft4-NX and
// LibertyRecompAndroid independently use this same safety hook. Keep it in
// this directly-linked TU8 bridge so it strongly overrides the generated weak
// fallback in every Switch link.
extern "C" void sub_828E02E8(PPCContext&, uint8_t*) {}

