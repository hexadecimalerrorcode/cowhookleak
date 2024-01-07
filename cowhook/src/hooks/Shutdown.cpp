#include <hacks/hacklist.hpp>
#include <settings/Bool.hpp>
#include "HookedMethods.hpp"
#include "MiscTemporary.hpp"
#include "votelogger.hpp"


namespace hooked_methods
{
DEFINE_HOOKED_METHOD(Shutdown, void, INetChannel *this_, const char *reason)
{
    g_Settings.bInvalid = true;
    logging::Info("Disconnect: %s", reason);
#if ENABLE_IPC
    ipc::UpdateServerAddress(true);
#endif
    original::Shutdown(this_, reason);
    ignoredc = false;
    hacks::autojoin::OnShutdown();
    std::string message = reason;
    votelogger::onShutdown(message);
}

} // namespace hooked_methods
