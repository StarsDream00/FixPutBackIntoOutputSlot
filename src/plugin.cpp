/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */

/**
 * @brief The entrypoint of the plugin. DO NOT remove or rename this function.
 *
 */
#include <llapi/HookAPI.h>
#include <llapi/mc/ItemStackRequestActionHandler.hpp>
#include <llapi/mc/ItemStackRequestActionTransferBase.hpp>
#include <llapi/mc/ContainerScreenContext.hpp>
#include <llapi/mc/ItemStackRequestSlotInfo.hpp>

TInstanceHook(enum ItemStackNetResult, "?_handleTransfer@ItemStackRequestActionHandler@@AEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionTransferBase@@_N11@Z", ItemStackRequestActionHandler, class ItemStackRequestActionTransferBase const& a2, bool a3, bool a4, bool a5) {
    auto& screenContext = this->getScreenContext();
    switch (screenContext.getScreenContainerType())
    {
    case ContainerType::FURNACE:
    case ContainerType::BLAST_FURNACE:
    case ContainerType::SMOKER:
        a5 = false;
        break;
    default:
        break;
    }
    return original(this, a2, a3, a4, a5);
}
